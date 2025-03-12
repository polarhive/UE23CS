# Use Ubuntu as the base image
FROM ubuntu:latest
LABEL maintainer="Your Name"
RUN apt-get update && \
    apt-get install -y build-essential linux-headers-$(uname -r) kmod && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /module

# Copy your kernel module code (hello_world.c and Makefile)
COPY . /module

# Compile the kernel module
RUN make

CMD ["sh", "-c", "\
    echo 'Compiling Module...' && make && \
    echo 'Loading Module...' && insmod hello_world.ko && \
    echo 'Verifying Module:' && lsmod | grep hello_world && \
    echo 'Kernel Logs (After Load):' && dmesg | tail && \
    sleep 3 && \
    echo 'Unloading Module...' && rmmod hello_world && \
    echo 'Kernel Logs (After Unload):' && dmesg | tail && \
    bash"]

