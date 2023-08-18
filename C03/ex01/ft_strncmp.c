#include <string.h>
#include <stdio.h>

int ft_strncmp(char *s1, char *s2, unsigned int n){
	unsigned int	i;
	int				res;

	i = 0;
	res = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (i < n)
		res = s1[i] - s2[i];
	return (res);
}

int main(){
	char str1[] = "rasa";
	char str2[] = "rasa";
	int res;

	res = strncmp(str1,str2,4);
	printf("%i \n",res);

	res = ft_strncmp(str1,str2,4);
	printf("%i \n",res);
}