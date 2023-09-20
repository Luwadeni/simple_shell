#include "ourshell.h"
/**
 * func_cd_dot - changes pathway to the parent directory
 * @dtsh: data relevant for (environ) variable
 * Return: NULL
 */
void func_cd_dot(project_shell *dtsh)
{
char pwd[PATH_MAX];
char *d, *cp_pwd, *cp_strtok_pwd;

/* getting the size of the pwd */
getcwd(pwd, sizeof(pwd));
cp_pwd = func_strdup(pwd);/* environ arhuments*/
func_set_env("OLDPWD", cp_pwd, dtsh);
	d = dtsh->args[1];
	if (func_strcmp(".", d) == 0)
	{
		func_set_env("PWD", cp_pwd, dtsh);
		free(cp_pwd);
		return;
	}
	if (func_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	/* ths copies string */
	cp_strtok_pwd = cp_pwd;
	func_rev_string(cp_strtok_pwd);
	cp_strtok_pwd = func_strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = func_strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			func_rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		func_set_env("PWD", cp_strtok_pwd, dtsh);
	}
	else
	{
		chdir("/");
		func_set_env("PWD", "/", dtsh);
	}
	dtsh->status = 0;
	free(cp_pwd);
}
/**
 * func_cd_to - functon that changes pathway to a directory given by user
 * @dtsh: data
 * Return: no return
 */
void func_cd_to(project_shell *dtsh)
{
	char pwd[PATH_MAX];
	char *d, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	d = dtsh->args[1];
	if (chdir(d) == -1)
	{
		func_get_error(dtsh, 2);
		return;
	}

	cp_pwd = func_strdup(pwd);
	func_set_env("OLDPWD", cp_pwd, dtsh);

	cp_dir = func_strdup(d);
	func_set_env("PWD", cp_dir, dtsh);

	free(cp_pwd);
	free(cp_dir);

	dtsh->status = 0;

	chdir(d);
}

/**
 * func_cd_previous - changes to the previous directory
 * @dtsh: data relevant (environ)
 * Return: no return
 */
void func_cd_previous(project_shell *dtsh)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = func_strdup(pwd);

	p_oldpwd = func_getenv("OLDPWD", dtsh->_environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = func_strdup(p_oldpwd);

	func_set_env("OLDPWD", cp_pwd, dtsh);

	if (chdir(cp_oldpwd) == -1)
		func_set_env("PWD", cp_pwd, dtsh);
	else
		func_set_env("PWD", cp_oldpwd, dtsh);

	p_pwd = func_getenv("PWD", dtsh->_environ);

	write(STDOUT_FILENO, p_pwd, func_strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	dtsh->status = 0;

	chdir(p_pwd);
}
/**
 * func_cd_to_home - changes pathway to home directory
 * @dtsh: data
 * Return: no return
 */
void func_cd_to_home(project_shell *dtsh)
{
char *p_pwd, *home;
char pwd[PATH_MAX];

getcwd(pwd, sizeof(pwd));
p_pwd = func_strdup(pwd);

home = func_getenv("HOME", dtsh->_environ);

if (home == NULL)
{
func_set_env("OLDPWD", p_pwd, dtsh);
free(p_pwd);
return;
}

/* if loop argument */
if (chdir(home) == -1)
{
func_get_error(dtsh, 2);
free(p_pwd);
return;
}

/* pathway arguments */
func_set_env("OLDPWD", p_pwd, dtsh);
func_set_env("PWD", home, dtsh);
free(p_pwd);
dtsh->status = 0;
}
