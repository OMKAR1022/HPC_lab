#!/bin/bash

# Check if at least one argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 filename1 [filename2 ...]"
    exit 1
fi

# Loop through each provided filename
for filename in "$@"; do
    # Check if the file exists in the current directory
    if [ -e "$filename" ]; then
        # Convert the file content to uppercase and save it back to the file
        awk '{ print toupper($0) }' "$filename" > tmpfile && mv tmpfile "$filename"
        echo "Converted $filename to uppercase."
    else
        echo "Error: File $filename does not exist in the current directory."
    fi
done
