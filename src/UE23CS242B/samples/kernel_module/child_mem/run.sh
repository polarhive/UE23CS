#!/bin/bash
set -e

MODULE_NAME="kernel_observer"
MODULE_FILE="${MODULE_NAME}.ko"

# Function to echo and run commands
run_cmd() {
    echo -e "\n# $1"
    shift
    echo -e "+ $@"
    eval "$@"
}

# Compile both user-space and kernel-space
run_cmd "Compiling the kernel module..." "make clean && make"

run_cmd "Compiling user-space program..." "gcc userspace.c"

# Run the user-space program in the background
run_cmd "Running the user-space program..." "./a.out &"
USERSPACE_PID=$!
sleep 2 # Allow user-space to spawn child processes
echo -e "User-space process running with PID: $USERSPACE_PID"

# Load the module with parent PID
run_cmd "Loading the kernel module..." "sudo insmod $MODULE_FILE parent_pid=$USERSPACE_PID"

# Verify module is loaded
run_cmd "Verifying module load status..." "lsmod | grep -q \"$MODULE_NAME\""
if [ $? -eq 0 ]; then
    echo -e "Module $MODULE_NAME loaded successfully."
else
    echo -e "Failed to load $MODULE_NAME."
    exit 1
fi

# Show kernel logs after loading
run_cmd "Kernel logs after loading module..." "sudo dmesg | tail -n 20"

# Wait for user-space program to complete
run_cmd "Waiting for user-space program to complete..." "wait $USERSPACE_PID"
echo -e "User-space program completed."

# Unload the module
run_cmd "Unloading the kernel module..." "sudo rmmod $MODULE_NAME"

# Verify module is unloaded
run_cmd "Verifying module unload status..." "lsmod | grep -q \"$MODULE_NAME\""
if [ $? -eq 0 ]; then
    echo -e "Module $MODULE_NAME failed to unload."
    exit 1
else
    echo -e "Module $MODULE_NAME unloaded successfully."
fi

# Show kernel logs after unloading
run_cmd "Kernel logs after unloading module..." "sudo dmesg | tail -n 20"
