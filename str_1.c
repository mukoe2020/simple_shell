#include "shell.h"

int strlen_alt(const char *s);
char *strcat_alt(char *dest, char *src);
int strcmp_alt(char *s1, char *s2);
char *strchr_alt(char *s, char c);
char *strcpy_alt(char *destination, char *source);
/**
*strlen_alt - Entry point
* Description - 'function returning length of a string'
* @s: string to be measured
*
* Return: the length of given string 's'
*/
int strlen_alt(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
* strcat_alt - Entry point
* Description - 'a function concantenating two strings'
* @dest: char string type
* @src: char string type
*
* Return: pointer to the concantenated string
*/
char *strcat_alt(char *dest, char *src)
{
int dest_len = 0;
int h;


/*Find the length of the destination string*/


while (dest[dest_len] != '\0')
{
dest_len++;
}


/*append the first string to the destination string */


for (h = 0; src[h] != '\0'; h++)
{
dest[dest_len + h] = src[h];
}
/* add null terminating character to concantenated string */


dest[dest_len + h] = '\0';


return (dest);
}




/**
* strcmp_alt - Entry point
* Description - 'a function comparing two strings'
* @s1: first string to be checked
* @s2: second string to be checked
*
* Return: value less than 0 means s1 is less than s2
* value equal to 0 meants s1 = s2
* value greater than 0 means s1 is greater than s2
*/


int strcmp_alt(char *s1, char *s2)
{
int len;


for (len = 0; s1[len] == s2[len] && s1[len]; len++)
;


if (s1[len] > s2[len])
return (1);
if (s1[len] < s2[len])
return (-1);
return (0);
}




/**
* strchr_alt - Entry point
* Description - ' a function searching for the first occurence of a character
* in a string'
* @s: a pointer to the string to be searched
* @c: the character to be searched for
*
* Return: a pointer to the first occurrence of the char c in s
* 0R 0 if char c is not found in s
*/


char *strchr_alt(char *s, char c)
{
int h;


for (h = 0; s[h] >= 0; h++)
{
if (s[h] == c)
{
return (&s[h]);
}
}
return (0);
}


/**
* memcpy_alt - Entry point
* Description: 'function copying memory area'
* @src: source char string type
* @dest: destination string type
* @n: maximum number of byte area to be copied
* Return: pointer to destination string
*/


char *memcpy_alt(char *dest, char *src, unsigned int n)
{
unsigned int h = 0;


for (h = 0; h < n; h++)
{
dest[h] = src[h];


}
return (dest);
}
/**
  * strcpy_alt - Entry point
  * Description - 'a function copying one pointer to another pointer'
  * @source: char type string
  * @destination: char string type
  * Return: Pointer to dest
  */

char *strcpy_alt(char *destination, char *source)
{
	int h = 0;

	while (source[h] != '\0')
	{
		destination[h] = source[h];
		h++;
	}
	destination[h] = '\0';
	return (destination);
}
