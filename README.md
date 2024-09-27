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

## Usage

The compiled program can be used as follows:

```bash
./cd [directory]
```

Options:

- `[directory]`: The directory to change to. If omitted, the program changes to the home directory.

- `-`: Switches to the previous directory, stored in the OLDPWD environment variable.

## Examples

Change to `$HOME` directory:

If no directory is specified, the program changes to the user's home directory:

```bash
./cd
```

If a directory is provided, the program changes current folder to the given directory:

```bash
./cd /path/to/directory
```

If the `-` option is provided, the program switches to the last working directory stored in `$OLDPWD`:

```bash
./cd -
```

If too many arguments are passed, the program prints a usage message:

```bash
./cd dir1 dir2
```

## Important Note

To achieve the actual `cd` behavior, you need to use the built-in `cd` command in your shell, not a separate program.

> Only the `shell` process itself can change its working directory.

When you run a `C` program, it executes in a _child process_.

Changing the directory in this _child process_ won't affect the parent `shell` process.

> `shell` process itself needs to change the current directory.

You can use this _C_ program to understand how `chdir()` works, but it can't replace the `shell`'s `cd` command directly.

The correct way to achieve this in a `shell` (like `bash`, `zsh`, etc.) is to create a _shell built-in_.

Source code for `cd` command (_shell built-in_) in `bash` can be found in <https://github.com/bminor/bash/blob/master/builtins/cd.def>

### Explanation

_C Program as a standalone_: If you create the `cd` command as a standalone _C_ program, it will only change the directory in its own process, and once it exits, the `shell` will remain in its original directory. The `shell` needs to change its directory, and only the `shell` process can do that.

_Shell Built-in_: The `cd` command is implemented as a _shell built-in_. It directly affects the `shell` process, so when the `shell` executes it, the _current working directory_ of the `shell` itself is changed.
