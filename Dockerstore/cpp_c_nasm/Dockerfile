# Use the latest version of Ubuntu as the base image
FROM ubuntu:latest

# Set environment variables to non-interactive (this prevents some prompts)
ENV DEBIAN_FRONTEND=non-interactive

# Update package list and install essential packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    llvm \
    clang \
    cmake \
    git \
    wget \
    unzip \
    pkg-config \
    nasm \
    llvm-11 llvm-11-dev

# Clean up to reduce image size
RUN   apt-get autoremove -y && \
      apt-get clean

# Reset environment variable
ENV DEBIAN_FRONTEND=

# Set the working directory
WORKDIR /workspace

# Set the default command
CMD ["bash"]


# Run in terminal 
# docker build -t llvm_cpp_c_asm .
# then
# docker run -it \
#     -v /root/Dockerfolder/host/share/host:/workspace \
#     --name cont_llvm_cpp_c_asm \
#     llvm_cpp_c_asm