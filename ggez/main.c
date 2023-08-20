#include <unistd.h>

#define N 4

int	rush01(char m[][N],char c[][N]);

int	check_string(char str[])
{
	int	i;
	int alternate;

	i = 0;
	alternate = 0;
	while (str[i] != '\0')
	{
		if (alternate == 0 && str[i]>= '1' && str[i] <= '4')
			alternate = 1;
		else if (alternate == 1 && str[i]==' ')
			alternate = 0;
		else
			return (-1);
		i++;
	}
	if (i != 31)
		return (-1);
	return (1);
}

void padding(char m[][N])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < N )
	{
		while (j < N )
		{
			m[i][j] = ' ';
			j++;
		}
		j = 0;
		i++;
	}
}

void initializer(char c[][N], char *str)
{
	int	i;
	int	j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < N )
	{
		while (j < N )
		{
			c[i][j] = str[k];
			j++;
			k = k + 2;
		}
		j = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	char m[N][N];
	char c[N][N];
	int	res;

	if (argc!=2)
		write(1,"Error\n",6);
	else if (check_string(argv[1]) == -1)
		write(1,"Error\n",6);
	else
	{
		padding(m);
		initializer(c, argv[1]);
		res = rush01(m,c);
		if (res == -1)
			write(1,"Error\n",6);
	}

	return (0);
}
