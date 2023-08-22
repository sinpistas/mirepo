int ft_fibonacci(int index){
	int	res;

	if (index < 0)
		res = -1;
	else if (index == 0)
		res = 0;
	else if (index == 1)
		res = 1;
	else
		res = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (res);
}
