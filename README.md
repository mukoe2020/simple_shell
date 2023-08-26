##  💻 THE SIMPLE_SHELL PROJECT 💻

![Alt text](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)

<code>In This Project We Were Assigned To Create a simple UNIX command interpreter</code>

## Project's Programming Language
* C 

## Styles
* Betty linter

## Authors

- [@habibaadam](https://www.github.com/habibaadam)
- [@mukoe2020](https://www.github.com/mukoe2020)

## Compilation

Your shell will be compiled this way:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Requirements Abided By

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the      options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)
* Write a README with the description of your project
* You should have an AUTHORS file at the root of your repository, listing all * * individuals having contributed content to the repository. Format, see Docker

## Our Shell's Interactivity

<code>This shell could work in interactive mode</code>

```bash 
$ ./hsh
(~$) /bin/ls
hsh shell_main.c shell.h
(~$)
(~$) exit
$ 
```
<code>And Also in Non-Interactive Mode</code>
  
```bash
$ echo "/bin/ls" | ./hsh
hsh shell_main.c shell.h test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh shell_main.c shell.h test_ls_2
hsh shell_main.c shell.h test_ls_2
$
```
## Basic Functionality Overview

```bash
Displays a prompt such as ~$ to indicate it's ready to accept input.
Waits for the user to type a command followed by pressing the Enter key (ending with a new line).

Executing Commands
Executes the entered command when the user presses Enter.
Displays the prompt again after executing a command.
Handles commands that are a single word (no arguments).

Error Handling
If an executable program cannot be found, prints an error message.
Displays the prompt again after printing the error message.
Handles errors gracefully without crashing.

End of File (EOF)
Handles the "end of file" condition (Ctrl+D) appropriately.
Exits the shell gracefully when the user presses Ctrl+D.
```
## Development

<b>Simple Shell 0.1</b>
* Basic shell functionality.
* Able to read and execute commands.
* Handles simple execution of commands without arguments.
* Limited built-in commands.

<b>Simple Shell 0.2</b>
* All features of 0.1 plus:
* Supports command lines with arguments.
* Basic handling of command execution using fork() and exec().

<b>Simple Shell 0.3</b>
* All features of 0.2 plus:
* Handles the PATH variable to search for executable commands.
* Won't call fork() if the command doesn't exist.
* Can execute commands like /bin/ls and display their output.
* Basic handling of signals (such as Ctrl+C).

<b>Simple Shell 0.4</b>
* All features of 0.3 plus:
* Implements the exit built-in command to exit the shell.
* Supports the exit command without any arguments.
* Handles exit status correctly.

<b>Simple Shell 1.0</b>
* All features of 0.4 plus:
* Implements the env built-in command to print the current environment variables.
* Capable of showing environment variables like USER, PATH, etc.

<b>Simple Shell 0.1.1 (Advanced)</b>
* All features of 0.1 plus:
* Implements a custom getline function to read input.
* Uses a buffer to minimize the number of read system calls.
* Utilizes static variables.

<b>Simple Shell 0.2.1 (Advanced)</b>
* All features of 0.2 plus:
* Achieves command and argument separation without using strtok.

<b>Simple Shell 0.4.1 (Advanced)</b>
* All features of 0.4 plus:
* Handles arguments for the exit built-in command.
* Allows using the exit command with an integer status.

<b>Setenv, Unsetenv (Advanced), 50% done</b>
* All features of 1.0 plus:
* Implements the setenv built-in command to initialize or modify environment variables.
* Implements the unsetenv built-in command to remove environment variables.

## Usage

```bash
./hsh  Or <./nameofexecutable
```