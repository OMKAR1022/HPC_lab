#!/bin/bash

# Check if any arguments are provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 username1 [username2 ...]"
    exit 1
fi

# Loop through each provided username
for username in "$@"; do
    # Get the home directory for the user
    home_dir=$(eval echo ~$username)
    
    # Check if the user exists
    if id "$username" &>/dev/null; then
        echo "$username: $home_dir"
    else
        echo "Error: User $username does not exist."
    fi
done
