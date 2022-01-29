/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:28:47 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/29 16:27:36 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_stack **x, int p)
{
	t_stack	*temp;

	if (lstsize(*x) > 1)
	{
		lstadd_back(x, lstnew((*x)->n));
		temp = (*x)->next;
		free(*x);
		*x = temp;
	}
	if (p == PRINT_A)
		ft_putstr_fd("ra\n", 1);
	else if (p == PRINT_B)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b, int p)
{
	rx(a, p);
	rx(b, p);
	if (p == PRINT)
		ft_putstr_fd("rr\n", 1);
}

void	rrx(t_stack **x, int p)
{
	t_stack	*prev;
	t_stack	*curr;

	if (lstsize(*x) > 1)
	{
		curr = *x;
		prev = NULL;
		while (curr->next)
		{
			prev = curr;
			curr = curr->next;
		}
		lstadd_front(x, lstnew(curr->n));
		free(prev->next);
		prev->next = NULL;
	}
	if (p == PRINT_A)
		ft_putstr_fd("rra\n", 1);
	else if (p == PRINT_B)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b, int p)
{
	rrx(a, p);
	rrx(b, p);
	if (p == PRINT)
		ft_putstr_fd("rrr\n", 1);
}
