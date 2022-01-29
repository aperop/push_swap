/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:11:20 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/29 20:02:59 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		++size;
		lst = lst->next;
	}
	return (size);
}

t_stack	*lstnew(int n)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (lst)
	{
		lst->n = n;
		lst->next = 0;
		lst->score = 0;
	}
	return (lst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		last = lstlast(*lst);
		last->next = new;
	}
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
