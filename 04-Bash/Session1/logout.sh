#!/usr/bin/bash

# This script will log out the user from the system or shutdown the system or reboot the system


choice=$(echo -e "Logout\nShutdown\nReboot" | rofi -dmenu -p "Choose an option")

if [ "$choice" == "Logout" ]; then
    pkill -KILL -u "$USER"
elif [ "$choice" == "Shutdown" ]; then
    shutdown now
elif [ "$choice" == "Reboot" ]; then
    reboot
fi