#include <stdio.h>

#define N 4

int check_and_put(char m[][N],int i, int j, int pos)
{
	if (i == 0 && m[N - 1 - pos][j] == ' ')
		m[N - 1 - pos][j] = '4';
	else if (i == 1 && m[pos][j] == ' ')
		m[pos][j] = '4';
	else if (i == 2 && m[j][N - 1 - pos] == ' ')
		m[j][N - 1 - pos] = '4';
	else if (i == 4 && m[j][pos] == ' ')
		m[j][pos] = '4';
	else
		return (-1);
	return (1);
}

int	the_4_rule(char m[][N],char c[][N])
{
	int i;
	int	j;
	int res;

	i = 0;
	j = 0;
	while (i < N)
	{
		while (j < N)
		{
			if (c[i][j] == '4'){
				res = check_and_put(m,i,j,0);
				if (res == -1)
					return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	the_3_rule(char m[][N],char c[][N])
{
	int i;
	int	j;
	int res;

	i = 0;
	j = 0;
	while (i < N)
	{
		while (j < N)
		{
			if (c[i][j] == '3')
			{
				res = check_and_put(m,i,j,1);
				if (res == -1)
					return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return 0;
}

int	rush01(char m[][N],char c[][N]){

	if (the_4_rule(m,c) == -1)
		return (-1);
	if (the_3_rule(m,c) == -1)
		return (-1);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%c ", m[i][j]);
		}
		printf("\n");
	}
	return (1);
}
