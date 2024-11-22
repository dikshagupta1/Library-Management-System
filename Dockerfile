# Stage 1: Build Stage
FROM ubuntu:22.04 AS build

# Set environment variables for non-interactive installations
ENV DEBIAN_FRONTEND=noninteractive

# Install essential tools and dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    curl \
    libssl-dev \
    nlohmann-json3-dev \
    && apt-get clean

# Set working directory in the container
WORKDIR /app

# Copy project files into the container
COPY . .

# Create a build directory and build the project
RUN mkdir -p build && cd build && \
    cmake .. && \
    cmake --build . --target LibraryManagementSystem

# Stage 2: Runtime Stage
FROM ubuntu:22.04

# Install only the required runtime libraries
RUN apt-get update && apt-get install -y \
    libstdc++6 \
    && apt-get clean

# Set working directory in the container
WORKDIR /app

# Copy the built executable from the build stage
COPY --from=build /app/build/LibraryManagementSystem .

# Copy any required resources (e.g., library_data.json for persistence)
COPY library_data.json .

# Set the default command
CMD ["./LibraryManagementSystem"]
