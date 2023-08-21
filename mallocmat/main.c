#include <unistd.h>
#include <stdlib.h>

void padding(char **matrix, int col, int row)
{
	int i, j;
	char car;

	car = 'a';
	i = 0;
	while ( i< row)
	{
		j = 0;
		while ( j < col)
		{
			matrix[i][j] = car;
			car++;
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int r,c,i;
	char **matrix;

	i = 0;
	if (argc == 3)
		{
			r = argv[1][0] - '0';
			c = argv[2][0] - '0';
			matrix = (char**)malloc(r * sizeof(char*));
			while( i < r)
			{
				matrix[i] = (char*)malloc(c * sizeof(char*));
				i++;
			}
			padding(matrix,c,r);
			//PINTAR (OBVIAR)
			int j;
			for (i = 0; i < r; i++){
				for (j = 0; j < c; j++){
					write(1, &matrix[i][j],1);
					write(1," ",1);
				}
				write(1,"\n",1);
			}
			//OBIVAR HASTA AQUI
			i = 0;
			while (i < r)
			{
				free(matrix[i]);
				i++;
			}
			free(matrix);
		}
	return 0;
}
