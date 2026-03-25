*This project has been created as part of the 42 curriculum by mmittelb.*

# Get_next_line

## Description

In the Get_next_line project, `get_next_line()` was created to read from a file descriptor line by line. Each line is returned as a string, with efficient buffering and memory management to allow consecutive calls to continue reading seamlessly.

This project teaches the following:

- Handling file descriptors in C
- Dynamic memory allocation
- String manipulation
- Static variables and buffers
- Variadic management of multiple file descriptors (bonus)

## Instructions

### Compile

**Mandatory version**

```bash
cc -D BUFFER_SIZE=32 main.c get_next_line.c get_next_line_utils.c -o gnl
```
- `BUFFER_SIZE` determines how many bytes are read from the file descriptor at once using `read()`. It can be changed during compilation with `-D BUFFER_SIZE=<value>`.

**Bonus Version**

```bash
cc -D BUFFER_SIZE=32 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```
- Each file descriptor maintains its own buffer.

### Run

```bash
./gnl <file>       					# Normal version
./gnl_bonus <file1> <file2> <file3> # Bonus version, supports multiple files at once
```
Example:

```bash
./gnl lorelei.txt
```

- The program will read a file line by line and print each line to standard output. 
- Make sure your `main.c` includes the appropriate header (`get_next_line.h` or `get_next_line_bonus.h`) depending on which version you are testing.

### Notes

- Always `free()` the memory returned by `get_next_line()` to avoid leaks. 
- Works with any file descriptor, including standard input (`0`), regular files, and sockets. 
- Each returned line includes the newline character (`\n`) if it is present in the file. 
- The bonus version allows reading from multiple file descriptors at the same time without overwriting buffers.
