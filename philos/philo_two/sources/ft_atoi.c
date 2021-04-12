/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:33:11 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/10 16:00:15 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	parse_limits_sign(long int a, int sign)
{
	if (a < 0 && sign > 0)
		return (-1);
	if (a > 0 && sign < 0)
		return (0);
	return (a);
}

long int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	a;

	a = 0L;
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			break ;
		a = (a * 10) + (str[i] - '0');
		i++;
	}
	a *= sign;
	return (parse_limits_sign(a, sign));
}
