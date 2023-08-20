#include <unistd.h>
#include <stdio.h>

#define N 6

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

void initializer(char m[][N], char *str)
{
	int i;
	int k;

	i = 1;
	k = 0;
	while (i < N -1){
		m[0][i++] = str[k];
		k = k + 2;
	}
	i = 1;
	while (i < N -1){
		m[N - 1][i++] = str[k];
		k = k + 2;
	}
	i = 1;
	while (i < N -1){
		m[i++][0] = str[k];
		k = k + 2;
	}
		i = 1;
	while (i < N -1){
		m[i++][N - 1] = str[k];
		k = k + 2;
	}
}

int	main(int argc, char **argv)
{
	char m[N][N]; // Vi mas intuitivo poner las condiciones en la misma matriz que en una nueva. Cuestion de gustos

	if (argc!=2)
	{
		write(1,"Error\n",6);
	}
	else if (check_string(argv[1]) == -1)
	{
		write(1,"Error\n",6);
	}
	else
	{
		padding(m);
		initializer(m, argv[1]);
		//rush <- llamar aqui y hacer en un .c distinto
		for (int i = 0; i < N; i++){ // <- Quitar esto, solo sirve para comprobar
			for (int j = 0; j < N; j++){
				printf("%c ", m[i][j]);
			}
			printf("\n");
		}

	}

	return (0);
}
