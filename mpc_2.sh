#!/bin/bash

# Check if the argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 path_name"
    exit 1
fi

# Create the directories
mkdir -p "$1"

# Check if the directories were created successfully
if [ $? -eq 0 ]; then
    echo "Directories created successfully."
else
    echo "Failed to create directories."
fi
