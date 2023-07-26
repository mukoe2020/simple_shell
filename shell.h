#ifndef _SHELL_H
#define _SHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define TOK_DEL " \n"
#define CMD_LEN 64
#define SIZE_B 1024

/* Accessing environmental variables */
extern char **environ;

/*Shell's Loop*/
void loop_ourshell(int argc, char **argv);

/*Command/Input Readers */
char *read_command();

/*Token Handlers */
char **token_maker(char *linebuf);
char *alt_strtok(char *string, const char *del);
void _release(char **tokens_made);

/* Execution Handlers */
int exec_args(char **tokens_made);

/* Command Path Handler*/
char *commandExists(const char *cmd);

/* Customized getenv */
char *getenv_alt(const char *variable_name);

/* Memory Allocation */
void *custom_realloc(void *ptr, unsigned int old_s, size_t);

/* Built-in Command Handlers */
void blt_matcher(char **tokens_made);
void shell_exit(int status);
void shell_env(void);

/* Error handlers */
void print_error(const char *name, int cmd_count, const char *command,
const char *error_msg);
void print_string(int descriptor, const char *string);
void convert_string(int num, char *string);

/* All String Function Implementations */

size_t strlen_alt(const char *s);
char *strcat_alt(char *dest, const char *src);
int strcmp_alt(char *s1, char *s2);
char *strchr_alt(const char *s, char c);
char *strdup_func(const char *s);
char *strncat_alt(char *dest, char *src, int n);
size_t strspn_alt(char *s, char *accept);
int strncmp_alt(const char *s1, const char *s2, int n);
char *strcpy_alt(char *destination, char *source);
char *strncpy_alt(char *destination, char *source, int n);
int atoi_alt(char *s);

#endif /* _SHELL_H */

