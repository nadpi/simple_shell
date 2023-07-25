#ifndef __shell__
#define __shell__
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
extern char **environ;
int cmp(char *s1, char *s2);
int findandexec(char *, char *, char **, int);
int find(char *, char *, char **);
int _strlen(char *);
void tokenize(char *, char **, char *);
void env(void);
char *comments(char *);
#endif
