#!/bin/bash

# Check if the correct number of arguments are provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 file1 file2"
    exit 1
fi

file1=$1
file2=$2

# Check if both files exist
if [ ! -e "$file1" ]; then
    echo "Error: $file1 does not exist."
    exit 1
fi

if [ ! -e "$file2" ]; then
    echo "Error: $file2 does not exist."
    exit 1
fi

# Get the permissions of both files
perm1=$(stat -f "%A" "$file1")
perm2=$(stat -f "%A" "$file2")

# Check if the permissions are identical
if [ "$perm1" = "$perm2" ]; then
    echo "Permissions are identical: $(ls -l "$file1" | awk '{print $1}')"
else
    echo "$file1 permissions: $(ls -l "$file1" | awk '{print $1}')"
    echo "$file2 permissions: $(ls -l "$file2" | awk '{print $1}')"
fi
