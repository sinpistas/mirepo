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

int ft_find_next_prime(int nb){
	int	res;
	int	i;

	res = 0;
	i = nb;
	while (res == 0)
	{
		if (ft_is_prime(i) == 1)
			res = i;
		i++;
	}
	return (res);
}
