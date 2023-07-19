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
#define BUF 1024


extern char **environ;

/*Shell's Loop*/
void loop_ourshell();

/*Command/Input Readers */
char *read_command();

/*Token Handlers */
char **token_maker(char *linebuf);
void _release(char **tokens_made);

/* Execution Handlers */
int exec_args(char **tokens_made);

/* command path*/
char *commandExists(const char *command);

/*customized getenv */
void printEnvironmentVariable(const char *variable);

/* Memory Allocation */
void *custom_realloc(void *ptr, unsigned int old_s, size_t new_s);


/* All String Function Implementations */

size_t strlen_alt(const char *s);
char *strcat_alt(char *dest, char *src);
int strcmp_alt(char *s1, char *s2);
char *strchr_alt(char *s, char c);
char *strdup_func(const char *s);
char *strncat_alt(char *dest, char *src, int n);
size_t strspn_alt(char *s, char *accept);
int strncmp_alt(const char *s1, const char *s2, int n);
char *strcpy_alt(char *destination, char *source);
char *strncpy_alt(char *destination, char *source, int n);


#endif /* _SHELL_H */

