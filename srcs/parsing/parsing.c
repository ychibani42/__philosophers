/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:44:07 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/20 20:27:07 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	int_len(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		i = 1;
		nb = -nb;
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	__usage(void)
{
	printf("Usage : ");
	printf("<number_of_philosophers>");
	printf(" <time_to_die> <time_to_eat> <time_to_sleep>\n");
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

long	_atol_(char *str)
{
	long nbr;
	int i;
	int sign;

	nbr = 0;
	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

int nbr_check(char *str)
{
	long nbr;

	nbr = _atol_(str);
	if (int_len(nbr) > _INT_SIZE_MAX_ || nbr > INT_MAX || nbr < INT_MIN)
		return (_ERROR_);
	return (_SUCCESS_);
}

int __check_integer(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (str[i] == '0' && i < len - 1)
		i++;
	len = ft_strlen(&str[i]);
	if (len > 10 || len == 0)
		return (printf("Invalid Arg"), _ERROR_);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (printf("Pas Un Chiffre"), _ERROR_);
		i++;
	}
	if (nbr_check(str) == _ERROR_)
		return (printf("Chiffre Trop Gros\n"), _ERROR_);
	return (_SUCCESS_);
}

int parsing(int ac, char **av)
{
	int i;

	if (!(ac == 5))
		return (__usage(), _ERROR_);
	i = 1;
	while (i < ac)
	{
		if (__check_integer(av[i]) == _ERROR_)
			return (ft_putstr_fd("Wrong Values\n", 2), _ERROR_);
		i++;
	}
	return (_SUCCESS_);
}