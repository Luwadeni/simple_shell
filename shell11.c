#include "ourshell.h"
/**
 * func_rev_string - for reversal of string
 * @s: pointer for string input
 * Return: NULL
 */
void func_rev_string(char *s)
{
int ct = 0, y, z;
char *str, tmp;

/* for fuction elp */
for (ct = 0; s[ct] != '\0'; ct++)
{
str = s;
}

/* while loop for function */
y = 0;
while (y < ct - 1)
{
z = y + 1;
while (z > 0)/*second while loop fid function */
{
tmp = *(str + z);
*(str + z) = *(str + (z - 1));
*(str + (z - 1)) = tmp;
z--;
}
y++;
}
}
