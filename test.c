#include <unistd.h>

int checker(char *str)
{
	int i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-' && str[i + 1] != '\0')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	return (1);
}

int checker2(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}


int ft_atoi(char *str)
{
	if (checker(str) == 1)
	{
		int i = 0;
		int sign = 1;
		int result = 0;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '+')
			i++;
		else if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		{
			result *= 10;
			result += str[i] - '0';
			i++;
		}
		if (checker2(str, i) == 1)
			return (result * sign);
	}

	return (-1);
}


void	print_hex(int num)
{
	int i = 0;
	char *hex = "0123456789abcdef";
	if (num > 15)
	{
		print_hex(num / 16);
		print_hex(num % 16);
	}
	else {
		write (1, &hex[num % 16], 1);
	}
}


int main(int ac, char **av)
{
	int num;
	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		if (num >= 0)
			print_hex(num);
	}
	write (1, "\n", 1);
	return (0);
}
