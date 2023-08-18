#include <string.h>
#include <stdio.h>

int ft_strcmp(char *s1, char *s2){

	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	res = s1[i] - s2[i];
	return (res);
}

int main(){
	char str1[] = "rasa";
	char str2[] = "rasa";
	int res;

	res = strcmp(str1,str2);
	printf("%i \n",res);

	res = ft_strcmp(str1,str2);
	printf("%i \n",res);
}