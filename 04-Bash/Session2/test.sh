#!/usr/bin/bash

read -p "enter value: " value

case $value in
    1)
        echo "Value is 1"
        ;;
    2|2.0|2.1|"2.2"|"two")
        echo "Value is 2"
        ;;
    3)
        echo "Value is 3"
        ;;
    *)
        echo "Value is not 1, 2 or 3"
        ;;
esac

str="Hello World"

echo "${str:0:5}"

# or

echo "$str" | cut -f 2 -d " "

word=$(xclip -o)
echo "word: $word"

select word in write read delete; do

    case $word in
        write)
            echo "You selected write"
            ;;
        read)
            echo "You selected read"
            ;;
        delete)
            echo "You selected delete"
            ;;
        *)
            echo "Invalid selection"
            ;;
    esac

done

