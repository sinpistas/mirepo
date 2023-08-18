#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while(src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int main()
{
    char dest[30];
    strcpy(dest, "Techie ");
 
    char src[] = "Delight – Implement strncat";
 
    my_strncat(dest, src, 7);
 
    puts(dest);
 
    return 0;
}