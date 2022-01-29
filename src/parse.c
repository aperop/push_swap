/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:12:54 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/29 22:06:32 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char *s)
{
	size_t	i;

	i = -1;
	if (!ft_strlen(s))
		return (0);
	if (s[0] == '-' && ft_strlen(s) > 1)
		i = 0;
	while (++i < ft_strlen(s))
	{
		if (!ft_isdigit(s[i]))
			return (0);
	}
	if (ft_strlen(s) > 11)
		return (0);
	if (s[0] != '-' && ft_strlen(s) == 10 && ft_atoi(s) <= 0)
		return (0);
	if (s[0] == '-' && ft_strlen(s) == 11 && ft_atoi(s) >= 0)
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

void	parse(t_stack **a, int argc, char **argv)
{
	int	i;

	i = 0;
	*a = NULL;
	while (++i < argc)
	{
		if (is_int(argv[i]) && !check_double(*a, ft_atoi(argv[i])))
			lstadd_back(a, lstnew(ft_atoi(argv[i])));
		else
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(a);
			exit(-1);
		}
	}
}
