#include <unistd.h>

int search(char *base)
{
	int	cont;
	int	i;
	int	j;

	cont = 0;
	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				cont++;
			if (cont > 1)
				return (-1);
			j++;
		}
		cont = 0;
		i++;
	}
	return (1);
}

int check_base(char *base)
{
	int	i;

	i = 0;
	while ( base[i] != '\0'){
		i++;
	}
	if(i <= 1)
		return (-1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		i++;
	}
	if (search(base) != 1)
		return (-1);
	return (1);
}

int conversion(int conversor[], int nbr, char *base){
	int	len;

	len = 0;
	if (nbr == 0){
		conversor[len] = 0;
		len++;
	}
	else{
		if (nbr < 0)
		{
			write(1,"-",1);
			nbr = -nbr;
		}
		while (nbr != 0)
		{
			conversor[len] = nbr % ft_strlen(base);
			nbr = nbr / ft_strlen(base);
			len++;
		}
	}
	len--;
	return (len);
}

void ft_putnbr_base(int nbr, char *base)
{
	int	conversor[32];
	int i;

	if (check_base(base) != -1)
	{
		i = conversion(conversor,nbr,base);
		while (i >= 0)
		{
			write(1,&base[conversor[i]],1);
			i--;
		}
	}
}

int main()
{
	//QUITAR strlen!!!
	ft_putnbr_base(012345671,"poniguay");
}
