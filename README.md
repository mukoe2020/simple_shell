##  💻 THE SIMPLE_SHELL PROJECT 💻

![Alt text](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)

<code>In This Project We Were Assigned To Create a simple UNIX command interpreter</code>

## Project Programming Language
* C Programming language

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

