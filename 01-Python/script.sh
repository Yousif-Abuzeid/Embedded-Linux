#!/usr/bin/bash

screenshot_directory="/home/youssef-abuzeid/Pictures/Screenshots"

latest_screenshot=$(ls -t "$screenshot_directory"/*.png | head -n 1)

if [ -z "$latest_screenshot" ]; then
    echo "No screenshots found in the specified directory."
    exit 1
fi

extract_text=$(tesseract "$latest_screenshot" stdout)

echo "$extract_text" | xclip -selection clipboard
