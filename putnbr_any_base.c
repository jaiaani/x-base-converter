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

void	my_putstr(char *str)
{
	int	x;

	x = my_strlen(str);
	write(1, str, x);
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
		my_putstr("-");
		x *= -1;
	}
	if(x < 9)
	{
		my_putchar(base[x % b]);
		return ;
	}
	putnbr_base(x / b, base);
	my_putchar(base[x % b]);
}

int	main(void)
{
	putnbr_base(-2147483647, "0123456789abcdef");
	return (0);
}
