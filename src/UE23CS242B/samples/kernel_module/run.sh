#!/bin/bash

set -e  # Exit on any error

MODULE_NAME="kernel_sim"       # Set your module name here
MODULE_FILE="${MODULE_NAME}.ko"

# Check if the system is Arch-based
if ! grep -qi "arch" /etc/os-release; then
    echo "This script is only for Arch Linux. Update package manager for other distros."
    exit 1
fi

# Ensure required packages are installed
echo "Installing required packages (if not already installed)..."
sudo pacman -S --needed --noconfirm base-devel linux-headers

# Compile the kernel module
echo "Compiling the kernel module..."
make clean && make

# Load the module
echo "Loading the kernel module: $MODULE_NAME"
sudo insmod $MODULE_FILE

# Verify module is loaded
if lsmod | grep -q "$MODULE_NAME"; then
    echo "✅ Module $MODULE_NAME loaded successfully."
else
    echo "❌ Failed to load $MODULE_NAME."
    exit 1
fi

# Show kernel logs after loading
echo "Kernel logs (after loading the module):"
sudo dmesg | tail -n 20

# Allow some time for the module to run
sleep 5

# Unload the module
echo "Unloading the module: $MODULE_NAME"
sudo rmmod $MODULE_NAME

# Verify module is unloaded
if lsmod | grep -q "$MODULE_NAME"; then
    echo "❌ Module $MODULE_NAME failed to unload."
    exit 1
else
    echo "✅ Module $MODULE_NAME unloaded successfully."
fi

# Show kernel logs after unloading
echo "Kernel logs (after unloading the module):"
sudo dmesg | tail -n 20
