#!/bin/bash

# Function to display all links to the specified file
find_links() {
    local target_file=$1
    local search_dir=$2

    # Find all files in the specified directory and subdirectories
    find "$search_dir" -type f -samefile "$target_file"
}

# Check if at least one argument is provided
if [ $# -lt 1 ]; then
    echo "Usage: $0 target_file [search_directory]"
    exit 1
fi

# Set the target file
target_file=$1

# Set the search directory to the second argument or the current directory if not provided
search_dir=${2:-.}

# Display the links to the specified file
echo "Searching for links to '$target_file' in directory '$search_dir' and its subdirectories..."
find_links "$target_file" "$search_dir"
