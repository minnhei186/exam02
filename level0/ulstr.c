#include "unistd.h"

int	ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	return (-nb);
}

void	write_u(char c)
{
	char	u_move;

	u_move = 'a' - 'A';
	c -= u_move;
	write(1, &c, 1);
}

void	write_l(char c)
{
	char	u_move;

	u_move = 'a' - 'A';
	c += u_move;
	write(1, &c, 1);
}

void	write_ulstr(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			write_u(*str);
		else if (*str >= 'A' && *str <= 'Z')
			write_l(*str);
		else
			write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	write_ulstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
