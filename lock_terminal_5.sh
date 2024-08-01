#!/bin/bash

# Function to lock the terminal
lock_terminal() {
    # Prompt for the password
    echo "Enter password for locking the terminal:"
    read -s password1

    # Prompt for password confirmation
    echo "Confirm password:"
    read -s password2

    # Check if passwords match
    if [ "$password1" != "$password2" ]; then
        echo "Passwords do not match. Terminal will not be locked."
        exit 1
    fi

    # Clear the screen and lock the terminal
    clear
    echo "Terminal locked. Press Ctrl+D to unlock."

    # Disable Ctrl+D (end-of-file) and Break (Ctrl+C) handling
    stty -icanon -echo
    
    # Loop until the correct password is entered
    while true; do
        echo "Enter password to unlock the terminal:"
        read -s unlock_password
        
        # Check if the entered password matches
        if [ "$unlock_password" == "$password1" ]; then
            echo "Terminal unlocked."
            # Re-enable terminal input and echo
            stty icanon echo
            clear
            break
        else
            echo "Incorrect password. Try again."
        fi
    done
}

# Main script execution
lock_terminal
