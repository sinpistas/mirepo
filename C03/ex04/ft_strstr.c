#include <stddef.h>
#include <stdio.h>
#include <string.h>
int	ft_check(char *str, char *to_find)
{
	int	res;


	res = 1;
	while (*str != '\0' && *to_find != '\0')
	{
		if (*str != *to_find)
		{
			res = 0;
			return 0;
		}
		str++;
		to_find++;
	}
	if (!(res == 1 && *to_find == '\0'))
	    res = 0;
	return (res);
}

char *ft_strstr(char *str, char *to_find)
{

	char *p;
	int	exit;

	p = NULL;
	exit = 0;
	while (*str != '\0' && exit == 0)
	{
		if(*str == *to_find)
		{
			if (ft_check(str,to_find) == 1)
				p = str;
				return str;
		}
		if (exit != 1)
			str++;			
	}
	return p;
}

int main()
{
    char *str1 = "Mi barro me ca lo robaron, mi cacarro lala";
    char *str1 = "carro";
 
    printf("%s\n", ft_strstr(str1, str1));

    
    char *str2 = "Mi barro me ca lo robaron, mi cacarro lala";
    char *str2 = "carro";
 

    printf("%s\n", strstr(str2, str2));
    return 0;
}
