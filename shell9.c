#include "ourshell.h"
/**
 * func_strcat - function that concatenates two strings
 * @dest: char pointer to the destination of the copied string
 * @src: const char pointer to the source string
 * Return: @dest
 */
char *func_strcat(char *dest, const char *src)
{
    int r;
    int m;

    for (r = 0; dest[r] != '\0'; r++)
        ;

    for (m = 0; src[m] != '\0'; m++)
    {
        dest[r] = src[m];
        r++;
    }

    dest[r] = '\0';
    return (dest);
}
/**
 * func_strcpy - function;that duplicates the string pointed to by src.
 * @dest: char pointer to the destination of the duplicated string
 * @src: char pointer to the source string
 * Return: dest
 */
char *func_strcpy(char *dest, char *src)
{

    size_t z;

    for (z = 0; src[z] != '\0'; z++)
    {
        dest[z] = src[z];
    }
    dest[z] = '\0';

    return (dest);
}
/**
 * func_strcmp - Function that compares two strings.
 * @s1: string
 * @s2: string
 * Return: 0 for equal string, positive value if s1 > s2, negative value if s1 < s2
 */
int func_strcmp(char *s1, char *s2)
{
    int y;

    for (y = 0; s1[y] == s2[y] && s1[y]; y++)
        ;

    if (s1[y] > s2[y])
        return (1);
    if (s1[y] < s2[y])
        return (-1);
    return (0);
}

/**
 * func_strchr - locates a character in a string
 * @s: string
 * @c: character
 * Return: pointer to the first occurrence of the character c
 */
char *func_strchr(char *s, char c)
{
    unsigned int p = 0;

    for (; *(s + p) != '\0'; p++)
        if (*(s + p) == c)
            return (s + p);
    if (*(s + p) == c)
        return (s + p);
    return ('\0');
}
/**
 * func_strspn - function;that acquires the length of a prefix substring
 * @s: initial segment
 * @accept: accepted bytes
 * Return: accepted bytes number
 */
int func_strspn(char *s, char *accept)
{
    int r, d, bool;

    for (r = 0; *(s + r) != '\0'; r++)
    {
        bool = 1;
        for (d = 0; *(accept + d) != '\0'; d++)
        {
            if (*(s + r) == *(accept + d))
            {
                bool = 0;
                break;
            }
        }
        if (bool == 1)
            break;
    }
    return (r);
}
