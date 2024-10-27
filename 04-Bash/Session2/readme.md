# session 2

## Check this link for more details

- [Bash scripting](https://devhints.io/bash)

## Switch statement

```bash

echo "Enter a number"
read num

case $num in
    1)
        echo "One"
        ;;
    2)
        echo "Two"
        ;;
    3)
        echo "Three"
        ;;
    *)
        echo "Invalid number"
        ;;
esac

```

## Select statement

```bash

select word in write read delete quit; do
    case $word in
        write)
            echo "You have selected write"
            ;;
        read)
            echo "You have selected read"
            ;;
        delete)
            echo "You have selected delete"
            ;;
        quit)
            break
            ;;
        *)
            echo "Invalid selection"
            ;;
    esac
done

```

## xclip

- xclip is a command line interface to the X11 clipboard.

```bash
# get the content of the clipboard 
word=$(xclip -o)
echo $word

```

## String

### String comparison

```bash

str1="Hello"
str2="World"

if [ $str1 = $str2 ]; then
    echo "Strings are equal"
else
    echo "Strings are not equal"
fi

# comparison based on length
if [ $str1 \> $str2 ]; then
    echo "$str1 is greater than $str2"
else
    echo "$str1 is less than $str2"
fi

if [ -z $str1 ]; then
    echo "String is empty"
else
    echo "String is not empty"
fi

if [ -n $str1 ]; then
    echo "String is not empty"
else
    echo "String is empty"
fi
``

### Count the number of characters in a string

```bash

str="Hello World"
echo ${#str}
# or
echo "Hello World" | wc -c

```
### Split a string

```bash

str="Hello World"

echo ${str:0:5}

# or

echo "Hello World" | cut -f 2 -d " "

# or

echo "Hello World" | awk '{print $2}'
```


