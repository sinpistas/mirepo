int ft_check(char c,int *sign)
{
	int state;

	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' ||
		c == '\t' || c == '\v')
	{
		state = 1;
	}
	else if (c == '-' || c == '+' )
	{
		state = 2;
		if (c == '-')
			*sign = (*sign) * (-1);
	}
	else if (c >= '0' && c <= '9')
		state = 3;
	else
		state = 4;
	return (state);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	state;
	int	sign;
	int start;

	sign = 1;
	i = 0;
	res = 0;
	start = 0;
	while(str[i] != '\0')
	{
		state = ft_check(str[i],&sign);
		if (start <= state && state != 4)
			start = state;
		else
			break;
		if (start == 3){
			if (sign == -1)
				res = res * 10 - (str[i] - '0');
			else
				res = res * 10 + str[i] - '0';
		}
		i++;
	}
	return (res);
}
