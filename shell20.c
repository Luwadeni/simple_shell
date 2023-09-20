#include "ourshell.h"
/**
 * func_get_builtin - function of builtin
 * @cmd: command argss
 * Return: function pointer of the builtin command
 */
int (*func_get_builtin(char *cmd))(project_shell *)
{
builtin_t builtin[] =
{
{ "env", func_env },
{ "exit", func_exit_shell },
{ "setenv", func_setenv },
{ "unsetenv", func_unsetenv },
{ "cd", func_cd_shell },
{ "help", func_get_help },
{ NULL, NULL }
};
int z;

for (z = 0; builtin[z].name; z++)
{
if (func_strcmp(builtin[z].name, cmd) == 0)
break;
}

return (builtin[z].f);
}
