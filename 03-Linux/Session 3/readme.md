# Session 3

## Topics

- File Viewing and Editing
          
            - cat
            - more
            - less
            - head
            - tail
            - nano 
            - vi or vim or nvim
            - gedit (GUI)
- Controls

            - Redirectors
                    - > (Output Redirection)
                    - >> (Append)
                    - < (Input Redirection)
                    - 2> (Error Redirection)
                    - 2>> (Error Append)
            - Piping
            - Wildcards
                    - * (Zero or more characters)
                    - ? (Single character)
                    - [ ] (Range of characters)

## File Viewing and Editing

### cat

- Concatenate and display the content of files
- Can be used to write the content of a file to another file
- Also can be used to write into a file
- Syntax: `cat [OPTION]... [FILE]...`
- **Options**: 
    
        - -n, --number: Number all output lines
        - -b, --number-nonblank: Number nonempty output lines
        - -E, --show-ends: Display $ at end of each line
        - -T, --show-tabs: Display TAB characters as ^I
        - -v, --show-nonprinting: Use ^ and M- notation, except for LFD and TAB
        - -s, --squeeze-blank: Suppress repeated empty output lines
        - -A, --show-all: Equivalent to -vET
        - -e: Equivalent to -vE

```bash
cat file1.txt file2.txt > file3.txt
cat > file4.txt
write the content of file4.txt 
then press ctrl+d
```

### more

- Display the content of a file page by page
- Syntax: `more [OPTION]... [FILE]...`

**Options**:

        - +n: Start displaying from line number n
        - -n: Display n lines per screen
        - +/pattern: Start displaying from the line containing the pattern

```bash

more file1.txt
more +5 file1.txt
more -5 file1.txt
more +/pattern file1.txt

```

### less

- Display the content of a file page by page
- Syntax: `less [OPTION]... [FILE]...`

**Options**:

        - +n: Start displaying from line number n
        - -n: Display n lines per screen
        - +/pattern: Start displaying from the line containing the pattern

```bash

less file1.txt
less +5 file1.txt
less -5 file1.txt
less +/pattern file1.txt

```

### head

- Display the first few lines of a file
- Syntax: `head [OPTION]... [FILE]...`

**Options**:

        - -n, --lines: Display the first n lines
        - -c, --bytes: Display the first n bytes
        - -q, --quiet: Never print headers giving file names
        - -v, --verbose: Always print headers giving file names

```bash

head file1.txt
head -n 5 file1.txt
head -c 5 file1.txt

```


### tail

- Display the last few lines of a file
- Syntax: `tail [OPTION]... [FILE]...`

**Options**:

        - -n, --lines: Display the last n lines
        - -c, --bytes: Display the last n bytes
        - -q, --quiet: Never print headers giving file names
        - -v, --verbose: Always print headers giving file names
        - -f, --follow: Output appended data as the file grows
        - -F: Same as --follow=name --retry
        - --retry: Keep trying to open a file if it is inaccessible

```bash

tail file1.txt
tail -n 5 file1.txt
tail -c 5 file1.txt

```

### nano

- A simple text editor
- Syntax: `nano [OPTION]... [FILE]...`


### vi or vim or nvim

#### Vim Modes

Vim, a highly configurable text editor, operates through different modes, each serving a specific purpose for editing and interacting with files. Here's a breakdown of the primary modes in Vim:

##### 1. Normal Mode (Command Mode)
- **Purpose**: This is the default mode when you open Vim, and it’s used for navigating and issuing commands.
- **Common actions**:
  - Move the cursor: `h` (left), `j` (down), `k` (up), `l` (right).
  - Delete text: `dd` (delete line), `x` (delete character).
  - Copy and paste: `yy` (yank/copy), `p` (paste).
- **Enter this mode**: Press `Esc` from any other mode.

##### 2. Insert Mode
- **Purpose**: Used for entering or editing text.
- **Common actions**:
  - Type normally to insert text.
  - Press `Esc` to return to Normal mode.
- **Enter this mode**: Press `i` (insert before cursor), `I` (insert at the beginning of the line), `a` (insert after cursor), or `A` (insert at the end of the line).

##### 3. Visual Mode
- **Purpose**: Used for selecting text to perform operations like copying, deleting, or replacing.
- **Common actions**:
  - Select text by moving the cursor.
  - Perform operations: `d` (delete), `y` (copy), or `r` (replace).
- **Enter this mode**: Press `v` (character-wise selection), `V` (line-wise selection), or `Ctrl+v` (block selection).

##### 4. Command-Line Mode
- **Purpose**: Used for running Vim commands, like saving or quitting.
- **Common actions**:
  - `:w` (write/save file), `:q` (quit), `:wq` (save and quit), `:q!` (quit without saving).
  - You can also search using `/` (forward search) or `?` (backward search).
- **Enter this mode**: Press `:` (colon) for commands or `/` for search.

##### 5. Replace Mode
- **Purpose**: Used to replace existing text with new text.
- **Common actions**:
  - Replaces characters one at a time as you type.
  - Press `Esc` to return to Normal mode.
- **Enter this mode**: Press `R` from Normal mode.

##### 6. Select Mode (Less common)
- **Purpose**: Similar to Visual Mode, but selections act like a typical text editor.
- **Common actions**:
  - Select text and immediately replace it by typing.
- **Enter this mode**: Press `g` followed by `v`.

##### Switching between modes:
- Use `Esc` to switch back to Normal mode from other modes.
- Commands like `i`, `v`, `R`, and `:` help transition between modes.

Each mode has its own distinct role, making Vim powerful for both text editing and efficient navigation.


#### Check the [Vim Cheat Sheet](https://devhints.io/vim) for more commands and shortcuts.


### gedit (GUI)

- A simple text editor for GNOME desktop environment
- Syntax: `gedit [OPTION]... [FILE]...`

## Controls

### Redirectors

#### > (Output Redirection)

- Redirects the output of a command to a file
- Syntax: `command > file`

```bash

ls > file1.txt

cat file1.txt> file2.txt

```

#### >> (Append)

- Appends the output of a command to a file
- Syntax: `command >> file`

```bash

ls >> file1.txt

cat file1.txt >> file2.txt

```

#### < (Input Redirection)

- Redirects the input of a command from a file
- Syntax: `command < file`

```bash


cat < file1.txt

```

#### 2> (Error Redirection)

- Redirects the error output of a command to a file
- Can be used to redirect the standard error output to a file

- Syntax: `command 2> file`

```bash

g++ file.cpp && ./a.out 2> error.txt> log.txt
// Redirects the error output to error.txt and the standard output to log.txt

```

#### 2>> (Error Append)

- Appends the error output of a command to a file
- Syntax: `command 2>> file`

```bash

g++ file.cpp && ./a.out 2>> error.txt>> log.txt
// Appends the error output to error.txt and the standard output to log.txt

```

### Piping

- Connects the output of one command to the input of another command

- Syntax: `command1 | command2`

```bash

ls | grep file

```

### Wildcards


- Wildcards are characters used to match filenames.
- Wildcards are used with commands like `ls`, `cp`, `mv`, etc.

#### Types of Wildcards

- `*` -> Matches zero or more characters.
- `?` -> Matches a single character.
- `[]` -> Matches a range of characters.
- `[!]` -> Matches characters not in the range.
- `[^]` -> Matches characters not in the range.

#### Special patterns

- `.` -> Matches a single character.
- `..` -> Matches two characters.
- `~` -> Matches the home directory.
- `*` -> Matches zero or more characters.
- `?` -> Matches a single character.
- `[]` -> Matches a range of characters.
- `[!]` -> Matches characters not in the range.
- `[^]` -> Matches characters not in the range.

- `[:alnum:]` -> Matches alphanumeric characters.
- `[:alpha:]` -> Matches alphabetic characters.
- `[:digit:]` -> Matches numeric characters.
- `[:lower:]` -> Matches lowercase characters.
- `[:upper:]` -> Matches uppercase characters.
- `[:space:]` -> Matches whitespace characters.




#### Examples

- `*.txt` -> Matches all files with the `.txt` extension.
- `file?` -> Matches files like `file1`, `file2`, etc.
- `[az]*` -> Matches files starting with `a` or `z`.
- `[!az]*` -> Matches files not starting with `a` or `z`.
- `[a-z]*` -> Matches files starting with any character from `a` to `z`
- `[^a-z]*` -> Matches files not starting with any character from `a` to `z`

## grep command

### Definition

- `grep` is a command-line utility for searching text patterns in files.

#### Syntax

```bash

grep [OPTIONS] PATTERN [FILE...]
```

#### Options

- `-i` -> Case-insensitive search.
- `-v` -> Invert match.
- `-n` -> Display line numbers.
- `-e` -> Extended regular expression.
- `-c` -> Display count of matching lines.
- `-l` -> Display filenames with matching lines.
- `-r` -> Recursive search (in whole dir).
- `-w` -> Match whole words.
- `-E` -> Extended regular expression.
- `-o` -> Display only matching text.
- `-A` -> Display lines after the match.
- `-B` -> Display lines before the match.
- `-C` -> Display lines before and after the match.


#### Examples

- `grep pattern file` -> Search for a pattern in a file.
- `grep -i pattern file` -> Case-insensitive search.
- `grep -v pattern file` -> Invert match.
- `grep -n pattern file` -> Display line numbers.
- `grep -c pattern file` -> Display count of matching lines.
- `grep -l pattern file` -> Display filenames with matching lines.
- `grep -r pattern directory` -> Recursive search (in whole dir).
- `grep -w pattern file` -> Match whole words.
- `grep -E pattern file` -> Extended regular expression.
- `grep -o pattern file` -> Display only matching text.
- `grep -A 2 pattern file` -> Display lines after the match.
- `grep -B 2 pattern file` -> Display lines before the match.
- `grep -C 2 pattern file` -> Display lines before and after the match.
- `grep -e pattern1 -e pattern2 file` -> Search for multiple patterns in a file.

## Basic Regular Expressions

### Definition

- A regular expression is a sequence of characters that define a search pattern.

### Metacharacters


- `.` -> Matches any single character(used with grep).
- `^` -> Matches the beginning of a line.
- `$` -> Matches the end of a line.
- `*` -> Matches zero or more occurrences of the previous character.
- `\` ->  Represents special characters.
- `()` -> Groups characters.
- `?` -> Matches any single character(used with ls).

### Examples

- `^pattern` -> Matches lines starting with `pattern`.
- `pattern$` -> Matches lines ending with `pattern`.
- `^pattern$` -> Matches lines containing only `pattern`.
- `pattern*` -> Matches `pattern`, `patternn`, `patternnn`, etc.
- `pattern\*` -> Matches `pattern*`.
- `pattern\.` -> Matches `pattern.`.
- `pattern()` -> Matches `pattern()`.
- `pattern?` -> Matches `pattern`, `patern`, etc.

### Extended Regular Expressions

- `+` -> Matches one or more occurrences of the previous character
- `?` -> Matches zero or one occurrence of the previous character
- `{n}` -> Matches exactly n occurrences of the previous character
- `{n,}` -> Matches n or more occurrences of the previous character
- `{n,m}` -> Matches between n and m occurrences of the previous character
- `|` -> Alternation (OR operator)
- `[]` -> Character class
- `[^]` -> Negated character class
- `()` -> Grouping
- `\` -> Escape character

### Examples

- `pattern+` -> Matches `pattern`, `patternn`, `patternnn`, etc.
- `pattern?` -> Matches `pattern` or `patern`.
- `pattern{n}` -> Matches `pattern` repeated n times.
- `pattern{n,}` -> Matches `pattern` repeated n or more times.
- `pattern{n,m}` -> Matches `pattern` repeated between n and m times.
- `pattern1|pattern2` -> Matches `pattern1` or `pattern2`.
- `[a-z]` -> Matches any lowercase letter.
- `[^a-z]` -> Matches any character except lowercase letters.
- `(pattern)` -> Matches `pattern`.
- `pattern\|pattern` -> Matches `pattern` or `pattern`.


## Access Files

- Layers

                Smack labels
                SELinux labels
                namespaces
                cgroups
                permissions ACL
                seccomp
- File Permissions

                -rwxrwxrwx
                -rwxr-xr-x
                -rw-rw-rw-
                -rw-r--r--
                -rwx------
                -rw-------
                -r--------
                -r--r--r--
- File Ownership
        
                        - User
                        - Group
                        - Others

- File Permissions

                - Read
                - Write
                - Execute


- 0: (000) No permission
- 1: (001) Execute permission
- 2: (010) Write permission
- 3: (011) Write and execute permissions
- 4: (100) Read permission
- 5: (101) Read and execute permissions
- 6: (110) Read and write permissions
- 7: (111) Read, write, and execute permissions

- chmod

                - chmod [OPTION]... MODE[,MODE]... FILE...
                - chmod [OPTION]... OCTAL-MODE FILE...
                - chmod [OPTION]... --reference=RFILE FILE...

### Examples

- `chmod 777 file` -> Give full permissions to user, group, and others.

- `chmod 755 file` -> Give read, write, and execute permissions to the user, and read and execute permissions to the group and others.

- `chmod 644 file` -> Give read and write permissions to the user, and read permissions to the group and others.

- `chmod 600 file` -> Give read and write permissions to the user, and no permissions to the group and others.

- `chmod 700 file` -> Give read, write, and execute permissions to the user, and no permissions to the group and others.

- `chmod 666 file` -> Give read and write permissions to the user, group, and others.

- `chmod 644 file` -> Give read and write permissions to the user, and read permissions to the group and others.


### chown

- Change file owner and group

                - chown [OPTION]... OWNER[:[GROUP]] FILE...
                - chown [OPTION]... :GROUP FILE...
                - chown [OPTION]... --reference=RFILE FILE...

### Examples

- `chown user:group file` -> Change the owner and group of the file.

- `chown :group file` -> Change the group of the file.

- `chown user file` -> Change the owner of the file.

