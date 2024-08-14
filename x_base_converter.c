#include <unistd.h>

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	base_is_valid(char *base)
{
	int	l;
	int	i;
	int	j;

	i = 0;
	l = my_strlen(base);
	if(l < 2)
		return (0);
	while(base[i])
	{
		j = i + 1;
		while(base[j])
		{	
			if(base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_a_space(char c)
{
	if(c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	my_atoi(char *str)
{
	int	i;
	int	s;
	int	x;

	i = 0;
	s = 1;
	x = 0;
	while(is_a_space(str[i]))
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] = '-')
			s = -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		x = x * 10 + (str[i] - 48);
		i++;
	}
	x *= s;
	return (x);
}

void	putnbr_base(int x, char *base)
{
	int	b;

	b = my_strlen(base);
	if (!base_is_valid(base))
		return ;
	if(x == -2147483648)
	{
		my_putchar('-');
		putnbr_base(x / b * -1, base);
		my_putchar(base[x % b * -1]);
		return ;
	}
	if(x < 0)
	{
		my_putchar('-');
		x *= -1;
	}
	if(x < b)
	{
		my_putchar(base[x % b]);
		return ;
	}
	putnbr_base(x / b, base);
	my_putchar(base[x % b]);
}

int	main(int argc, char *argv[])
{
	int	num;

	if(argc == 3)
	{
		num = my_atoi(argv[1]);
		putnbr_base(num, argv[2]);
		my_putchar('\n');
	}
	return (0);
}
