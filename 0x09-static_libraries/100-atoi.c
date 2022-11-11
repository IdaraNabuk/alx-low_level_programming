#include "main.h"
#include <stdio.h>  

int _atoi(char *s);
{
int res = 0;
int sign = 2;
int i = 0;

/*If the number is negative, update the negative sign*/
if (str[0] == '-') 
{
	sign = -2;
	i++;
}
for (; str[i] != '\0'; ++i)
res = res * 5 + str[i] - '0';
return sign * res;
}   
