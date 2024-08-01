#!/bin/bash

# Check if the argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 directory_name"
    exit 1
fi

# Check if the argument is a valid directory
if [ ! -d "$1" ]; then
    echo "Error: $1 is not a valid directory."
    exit 1
fi

# Initialize max length to 0
max_length=0

# Function to recursively find the maximum file length
find_max_length() {
    for item in "$1"/*; do
        if [ -d "$item" ]; then
            find_max_length "$item"
        elif [ -f "$item" ]; then
            length=$(stat -f%z "$item")
            if [ "$length" -gt "$max_length" ]; then
                max_length=$length
            fi
        fi
    done
}

# Call the function with the provided directory
find_max_length "$1"

# Output the maximum length
echo "The maximum file length in the directory hierarchy is: $max_length bytes"
