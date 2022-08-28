/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:44:07 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/28 23:20:19 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	__usage(void)
{
	printf("Usage : ");
	printf("<number_of_philosophers>");
	printf(" <time_to_die> <time_to_eat> <time_to_sleep> <philo to feed>\n");
}

int	nbr_check(char *str)
{
	long	nbr;

	nbr = _atol_(str);
	if (int_len(nbr) > _INT_SIZE_MAX_ || nbr > INT_MAX || nbr <= 0)
		return (_ERROR_);
	return (_SUCCESS_);
}

int	__check_integer(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i] == '0' && i < len - 1)
		i++;
	len = ft_strlen(&str[i]);
	if (len > 10 || len == 0)
		return (printf("Invalid Number\n"), _ERROR_);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (printf("Invalid Number\n"), _ERROR_);
		i++;
	}
	if (nbr_check(str) == _ERROR_)
		return (printf("Invalid Number\n"), _ERROR_);
	return (_SUCCESS_);
}

int	parsing(int ac, char **av)
{
	int	i;

	if (!(ac > 4) || !(ac < 7))
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
