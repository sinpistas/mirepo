int ft_iterative_power(int nb, int power){
	int	res;
	int	i;

	i = 1;
	res = 1;
	if (power < 0)
		return (0);
	while(i <= power)
		{
			res = res * nb;
			i++;
		}
	return (res);
}
