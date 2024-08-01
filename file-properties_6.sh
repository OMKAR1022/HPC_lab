#!/bin/bash

# Prompt the user to enter a file name
echo "Enter the file name:"
read file_name

# Check if the file exists
if [ ! -e "$file_name" ]; then
    echo "File does not exist."
    exit 1
fi

# Output the file properties using stat
echo "File properties for $file_name:"
stat "$file_name"
