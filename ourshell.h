#ifndef OURSHELL	
#define OURSHELL

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data - struct function that contains all data.
 * @av: the argument vector for functio
 * @input: the command line written by user
 * @args: the argument token of the command line
 * @status: shell last status
 * @counter: function to count lines
 * @_environ: the environment variable passed
 * @pid: the shell process identification
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} project_shell;

/**
 * struct sep_list_s - function for asingle linked list
 * @separator: ; | &
 * @link: link node
 * Description: the single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *link;
} sep_list;

/**
 * struct line_list_s - struct function for single linked list
 * @line: the command line
 * @link: the link node for function
 * Description: a single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *link;
} line_list;

/**
 * struct r_var_list - function single linked list
 * @len_var: length of variable
 * @val: variable value
 * @len_val: value length
 * @link: link node
 * Description: a single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *link;
} r_var;

/**
 * struct builtin_s - struct builtin struct for command arguments.
 * @name: Command builtin names such as  i.e cd, exit, env
 * @f: data pointer function type
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(project_shell *);
} builtin_t;

char *func_strcat_cd(project_shell *, char *, char *, char *);
char *e_get_cd(project_shell *);
char *e_not_f(project_shell *);
char *e_exit_s(project_shell *);
char *func_strdup(const char *s);
/* myhelper functions */
int func_strlen(const char *s);
int compare_chars(char string[], const char *);
char *func_strtok(char string[], const char *);
int func_isdigit(const char *);
void func_rev_string(char *);
/*function to navigate directory */
void func_cd_dot(project_shell *);
void func_cd_to(project_shell *);
void func_cd_previous(project_shell *);
void func_cd_to_home(project_shell *);
int func_cd_shell(project_shell *);
int repeat_chars(char *, int);
int func_e_s_p(char *, int, char);
int func_first_char(char *, int *);
/*functions */
void p_x_e(project_shell *, char *, int, int);
int c_x_e(project_shell *, char *);
int func_exec_line(project_shell *);
int func_exit_shell(project_shell *);
int (*func_get_builtin(char *))(project_shell *);
int func_get_error(project_shell *, int);
int func_get_help(project_shell *);
void func_bring_line(char **, size_t *, char *, size_t);
ssize_t func_get_line(char **, size_t *, FILE *);

void func_get_sigint(int);
char *func_read_line(int *);
char *func_without_comment(char *);
void looper(project_shell *);
char *func_swap_char(char *, int);
void func_add_nodes(sep_list **, line_list **, char *);
void func_go_link(sep_list **, line_list **, project_shell *);
int func_split_commands(project_shell *, char *);
char **func_split_line(char *);
void aux_help_env(void);
/* more helper functions */
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);
sep_list *func_add_sep_node_end(sep_list **, char);
void func_free_sep_list(sep_list **);
line_list *func_add_line_node_end(line_list **, char *);
void func_free_line_list(line_list **);

char *func_strchr(char *s, char c);
int func_strspn(char *, char *);
void func_check_env(r_var **, char *, project_shell *);
int func_check_vars(r_var **, char *, char *, project_shell *);
char *replace_inputs(r_var **, char *, char *, int);
char *var_replace(char *, project_shell *);
char *func_copy_info(char *, char *);
void func_set_env(char *, char *, project_shell *);
int func_setenv(project_shell *);
int func_unsetenv(project_shell *);
int func_cmp_env_name(const char *, const char *);
char *func_getenv(const char *, char **);
int func_env(project_shell *);
int func_is_cdir(char *, int *);
char *func_which(char *, char **);
int func_is_executable(project_shell *);
int func_check_error_cmd(char *d, project_shell *);
/* other helper functions */
int func_cmd_exec(project_shell *);
char *e_env(project_shell *);
char *e_path_126(project_shell *);

r_var *func_add_rvar_node(r_var **, int, char *, int);
void func_free_rvar_list(r_var **);
void func_memcpy(void *, const void *, unsigned int);
void *func_realloc(void *, unsigned int, unsigned int);
char **func_reallocdp(char **, unsigned int, unsigned int);
int func_get_len(int);
char *func_itoa(int);
int func_atoi(char *);
char *func_strcat(char *, const char *);
char *func_strcpy(char *, char *);
int func_strcmp(char *, char *);

#endif
