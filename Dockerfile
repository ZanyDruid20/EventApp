# Use a base image with gcc build tools (e.g., gcc and cmake)
FROM gcc:latest

# Install necessary dependencies like g++, make, wget, and dependencies for CMake
RUN apt-get update && \
    apt-get install -y \
    g++ make wget \
    ca-certificates \
    curl \
    gnupg2 lsb-release

# Install the latest CMake (version 3.26 or higher)
RUN wget -qO - https://cmake.org/files/v3.26/cmake-3.26.2-linux-x86_64.tar.gz | tar -xz -C /opt && \
    ln -s /opt/cmake-3.26.2-linux-x86_64/bin/cmake /usr/local/bin/cmake

# Set the working directory in the container
WORKDIR /usr/src/app

# Copy the contents of the local project directory to the working directory in the container
COPY . .

# Create a build directory and navigate into it
RUN mkdir -p build
WORKDIR /usr/src/app/build

# Run cmake to configure the project
RUN cmake ..

# Build the project using make
RUN make

# Specify the command to run your program (in this case, EventApp)
CMD ["./EventApp"]
