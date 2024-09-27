# `cd` command from scratch in C

This is a simple _C_ implementation that mimics the behavior of the `cd` (_change directory_) command found in _Unix-like systems_.

The program changes the _current working directory_ to a specified directory or to the _home_ directory if no argument is provided. It also supports switching to the _previous directory_ using the `-` option.

## How It Works

There are a few header files;

- `stdio.h`: For standard input/output functions like `printf`, `fprintf`.
- `unistd.h`: For the `chdir` function that changes the working directory.
- `stdlib.h`: For environment variable handling (`getenv`).
- `string.h`: For string comparison (`strcmp`).

The program takes command-line arguments:

- `argc`: The number of arguments.
- `argv[]`: An array of arguments, _where `argv[0]` is the program name_.

### No arguments (`argc == 1`)

It retrieves the value of the `$HOME` environment variable.

If `$HOME` is found, it switches to that directory using `chdir()`. Otherwise, it prints an error.

### Single argument (`argc == 2`)

If the argument is `-`, it switches to the directory stored in `$OLDPWD` (previous working directory).

If a regular directory is provided, it changes to that directory using `chdir()`.

### More than two arguments (`argc > 2`)

It prints a usage error message.

## Compilation

To compile this program, use:

```bash
# This command generates an executable named cd.
gcc -o cd main.c
```
