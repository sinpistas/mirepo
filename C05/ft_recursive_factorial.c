int ft_recursive_factorial(int nb)
{

	int res;
	if (nb < 0)
		res = 0;
	else if (nb == 0)
		res = 1;
	else
		res = nb * ft_recursive_factorial(nb-1);
	return (res);
}
