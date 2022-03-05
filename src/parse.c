/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:12:54 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/05 15:43:58 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

long	ft_atol(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*str++ - '0');
		if (sign < 0 && ret > 0)
			return (LONG_MIN);
		else if (sign > 0 && ret < 0)
			return (LONG_MAX);
	}
	return (ret);
}

static int	is_int(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		++i;
	while (s[i])
		if (!ft_isdigit(s[i++]))
			return (0);
	if (ft_atol(s) < INT_MIN || ft_atol(s) > INT_MAX)
		return (0);
	return (1);
}

static int	check_double(t_stack *lst, int n)
{
	while (lst)
	{
		if (lst->n == n)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	parse_arg(t_stack **a, char *argv)
{
	char	**args;
	int		i;

	i = 0;
	args = ft_split(argv, ' ');
	while (args[i])
	{
		if (is_int(args[i]) && !check_double(*a, ft_atoi(args[i])))
			lstadd_back(a, lstnew(ft_atoi(args[i])));
		else
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(a);
			exit(-1);
		}
		++i;
	}
}

void	parse(t_stack **a, int argc, char **argv)
{
	int	i;

	i = 0;
	*a = NULL;
	while (++i < argc)
	{
		if (argc == 2)
			parse_arg(a, argv[1]);
		else if (is_int(argv[i]) && !check_double(*a, ft_atoi(argv[i])))
			lstadd_back(a, lstnew(ft_atoi(argv[i])));
		else
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(a);
			exit(-1);
		}
	}
}
