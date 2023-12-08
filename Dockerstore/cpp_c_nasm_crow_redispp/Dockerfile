FROM ubuntu:latest

# Set environment variables to non-interactive (this prevents some prompts)
ENV DEBIAN_FRONTEND=non-interactive

# Update package list and install essential packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    llvm-11 llvm-11-dev \
    clang \
    cmake \
    git \
    wget \
    unzip \
    pkg-config \
    nasm \
    libhiredis-dev \
    libasio-dev
#    apt-get autoremove -y && \
#    apt-get clean && \
#    rm -rf /var/lib/apt/lists/*

# Clean up to reduce image size
RUN   apt-get autoremove -y && \
      apt-get clean

# Install Crow
RUN wget -O CrowCpp.zip https://github.com/CrowCpp/Crow/archive/refs/heads/master.zip && \
    unzip CrowCpp.zip && \
    cd Crow-master && \
    mkdir build && \
    cd build && \
    cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF && \
    make && \
    make install && \
    cd ../../ && \
    rm -rf CrowCpp.zip Crow-master

# Install redis-plus-plus
RUN wget -O redis-plus-plus.zip https://github.com/sewenew/redis-plus-plus/archive/refs/heads/master.zip && \
    unzip redis-plus-plus.zip && \
    cd redis-plus-plus-master && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install && \
    cd ../../ && \
    rm -rf redis-plus-plus.zip redis-plus-plus-master

# Reset environment variable
ENV DEBIAN_FRONTEND=

# Set the working directory
WORKDIR /workspace

# Set the default command
CMD ["bash"]

# Instructions to build and run the container
# docker build -t llvm_redispp_crow .
# docker run -it -v /root/Dockerfolder/host/share/host:/workspace --name cont_llvm_redispp_crow llvm_redispp_crow
