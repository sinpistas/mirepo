int ft_is_prime(int nb){
	int	res;
	int	i;

	res = 1;
	i = 2;
	if (nb < 2)
		return (0);
	while((i <= (nb / 2)) && res == 1)
	{
		if (nb % i == 0)
			res = 0;
		i++;
	}
	return (res);
}
