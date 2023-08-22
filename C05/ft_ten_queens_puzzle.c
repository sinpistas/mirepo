#include <unistd.h>

#define N 10
/*Lectura de izquierda a derecha*/
void	write_sol(int matrix[][N])
{
	int		i;
	int		j;
	char	c;
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (matrix[j][i] != 0)
			{
				c = j + '0';
				write(1,&c,1);
			}
			j++;
		}
		i++;
	}
}

int	check(int matrix[][N], int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while(i < col)
	{
		if (matrix[row][i++] != 0)
			return (0);
	}
	i = row;
	j = col;
	while(i >= 0 & j >= 0)
	{
		if (matrix[i--][j--] != 0)
			return (0);
	}
	i = row;
	j = col;
	while(i < N & j >= 0)
	{
		if (matrix[i++][j--] != 0)
			return (0);
	}
	return (1);
}

/*Recursive part*/
int	ft_recursive_queens(int matrix[][N], int *cont, int col)
{
	int	i;

	if(col >= N)
		return (1);
	i = 0;
	while (i < N)
	{
		if (check(matrix,i,col) == 1)
		{
			matrix[i][col] = 1;
			if (ft_recursive_queens(matrix, cont, col + 1))
			{
				if(*cont > 0)
						write(1,"\n",1);
				*cont = *cont + 1;
				write_sol(matrix);
			}
			matrix[i][col] = 0;
		}
		i++;
	}
	return (0);
}

void	initialice(int matrix[][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}

}

int ft_ten_queens_puzzle(void){
	int matrix[N][N];
	int cont;

	cont = 0;
	initialice(matrix);
	ft_recursive_queens(matrix,&cont,0);
	return (cont);
}
/*
#include <stdio.h>
int main()
{
	printf("\n%i",ft_ten_queens_puzzle());
	return (0);
}
*/
