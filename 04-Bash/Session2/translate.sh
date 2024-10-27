#!/usr/bin/bash

url="https://translate.google.com/?sl=en&tl=ar&text=$(xclip -o sel)&op=translate"

firefox "$url"

