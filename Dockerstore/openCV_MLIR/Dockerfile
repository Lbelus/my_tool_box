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
    llvm-11 llvm-11-dev \
    g++ libstdc++6 \
    libjpeg-dev \
    libpng-dev \
    libtiff-dev \
    libavcodec-dev \
    libavformat-dev \
    libswscale-dev \
    libv4l-dev \
    libxvidcore-dev \
    libx264-dev \
    libgtk-3-dev \
    libatlas-base-dev \
    libblas-dev \
    liblapack-dev \
    x11-apps

# Install OpenCV from source
RUN wget -O opencv.zip https://github.com/opencv/opencv/archive/refs/tags/4.8.0.zip && \
    unzip opencv.zip && \
    cd opencv-4.8.0 && \
    mkdir build && \
    cd build && \
    cmake -D CMAKE_BUILD_TYPE=RELEASE \
          -D CMAKE_INSTALL_PREFIX=/usr/local \
          .. && \
    make -j4 && \
    make install

# Clean up to reduce image size
RUN apt-get autoremove -y && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /opencv-4.8.0 /opencv.zip

# Reset environment variable
ENV DEBIAN_FRONTEND=

# Set the working directory
WORKDIR /workspace

# Set the default command
CMD ["bash"]


# run this in terminal. 
# xhost +local:docker
# docker run -it \
#     -e DISPLAY=unix$DISPLAY \
#     -v /tmp/.X11-unix:/tmp/.X11-unix \
#     -v /path/to/local/directory:/workspace \
#     --name my_container \
#     your_docker_image