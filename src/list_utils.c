/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:47:11 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/29 17:17:44 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_is_sorted(t_stack *lst)
{
	while (lst->next)
	{
		if (lst->next->n < lst->n)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	lst_min(t_stack *lst)
{
	int	min;

	min = lst->n;
	while (lst)
	{
		if (lst->n < min)
			min = lst->n;
		lst = lst->next;
	}
	return (min);
}

int	lst_max(t_stack *lst)
{
	int	max;

	max = lst->n;
	while (lst)
	{
		if (lst->n > max)
			max = lst->n;
		lst = lst->next;
	}
	return (max);
}

static int	lst_next_min(t_stack *lst, int min)
{
	int	next_min;

	next_min = lst_max(lst);
	while (lst)
	{
		if (lst->n > min && lst->n < next_min)
			next_min = lst->n;
		lst = lst->next;
	}
	return (next_min);
}

int	lst_median(t_stack *lst)
{
	int	m;
	int	i;

	m = lst_min(lst);
	i = 0;
	while (i++ < lstsize(lst) / 2)
		m = lst_next_min(lst, m);
	return (m);
}
