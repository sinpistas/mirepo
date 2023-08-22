int ft_iterative_factorial(int nb)
{
	int res;

	res = 0;
	if (nb >= 0){
		res = 1;
		while (nb > 1)
		{
			res = res * nb;
			nb--;
		}
	}
	return (res);
}
