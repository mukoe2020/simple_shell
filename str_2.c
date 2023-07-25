#include "shell.h"

char *strdup_func(const char *s);
char *strncat_alt(char *dest, char *src, int n);
size_t strspn_alt(char *s, char *accept);
int strncmp_alt(const char *s1, const char *s2, int n);
char *strncpy_alt(char *destination, char *source, int n);
int atoi_alt(char *s);

/**
* strdup_func - Entry point
* Description - 'a function that duplicates a string including allocating
* memory dynamically'
* @s: string to be duplicated
*
* Return: a pointer to the duplicated string
*/

char *strdup_func(const char *s)
{
int m = 0;
char *copy;
int len = 0;


if (s == NULL)
{
return (NULL);
}


while (s[len] != '\0')
{
len++;
}


copy = malloc((len + 1) * sizeof(char));
if (copy == NULL)
{
/* if memory allocation fails */
return (NULL);
}

for (m = 0; m < len; m++)
{
copy[m] = s[m];
}
copy[m] = '\0';
return (copy);
}
/**
* strncat_alt - Entry point
* Description - 'a function used to concantenate a specified number of chars'
* @src: a pointer to the source string
* @dest: a pointer to the destination string
* @n: the maximum number of chars to be concantenated
*
* Return: pointer to dest
*/


char *strncat_alt(char *dest, char *src, int n)
{
int dest_len = strlen_alt(dest);


int m;


for (m = 0; m < n && src[m] != '\0'; m++)
{
dest[dest_len + m] = src[m];
}
dest[dest_len + m] = '\0';


return (dest);


}
/**
* strspn_alt - Entry point
* Description - ' a function that gets the length of a prefix substring'
* @s: string to be checked
* @accept: the substring to be checked
*
* Return: the number of bytes within s that only belongs to accept
*/


size_t strspn_alt(char *s, char *accept)
{
size_t h, m;


for (h = 0; s[h] != '\0'; h++)
{
for (m = 0; accept[m] != '\0'; m++)
{
if (s[h] == accept[m])
{
break;
}
}
if (accept[m] == '\0')
{
break;
}
}
return (h);
}
/**
* strncmp_alt - Entry point
* Description - ' a function that compares two strings according to a specif-
* ' ied number of bytes or characters'
* @s1: pointer to a string
* @s2: pointer to another string
* @n: specified or maximum number of bytes to be used for comparing
*
* Return: if value is less than 0, then s1 is shorter or less than s2
* if value is 0 then s1 and s2 are the same or have a match
* if value is greater than 0, then s2 is longer than s1
*/


int strncmp_alt(const char *s1, const char *s2, int n)
{
int m = 0;


/* an iterator that keeps count of bytes or characters*/


while (s1[m] && s2[m] && m < n)
{
if (s1[m] != s2[m])
{
return (s1[m] - s2[m]);
}
m++;
}


if (m == n)
{
return (0);
}


if (s1[m] && !s2[m])
{
return (1);
}
else if (!s1[m] && s2[m])
{
return (-1);
}


return (0);
}
/**
* strncpy_alt - Entry point
* Description -'a function that copies a string'
* @destination: destination char string type
* @source: initial char string type
* @n: maximum number of bytes to be used
* Return: pointer to destination
*/

char *strncpy_alt(char *destination, char *source, int n)
{
	int cob;

	for (cob = 0; cob < n && source[cob] != '\0'; cob++)
	{
		destination[cob] = source[cob];
	}
	for (; cob < n; cob++)
	{
		destination[cob] = '\0';
	}
	return (destination);

}
/**
 * atoi_alt - Entry point
 * Description -'funtion that converts a chracter string to an integer'
 * @s: the string to be converted
 * Return: converted interger value
 */
int atoi_alt(char *s)
{
	int res_value = 0;
	int sn = 1;
	int h = 0;

	while (s[h] == ' ' || s[h] == '\t' || s[h] == '\n')
	{
		h++;
	}

	if (s[h] == '+' || s[h] == '-')
	{
		sn = (s[h++] == '-') ? -1 : 1;
	}

	while (s[h] >= '0' && s[h] <= '9')
	{
		res_value = res_value * 10 + (s[h] - '0');
		h++;
	}

return (res_value * sn);
}
