int ft_sqrt(int nb)
{
	int	res;
	int	i;
	int	pot;

	res = 0;
	i = 1;
	pot = 0;
	while (pot <= nb)
	{
		pot = i * i;
		if (nb == pot)
		{
			res = i;
			break;
		}
		i++;
	}
	return (res);
}
