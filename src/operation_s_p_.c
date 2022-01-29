/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s_p_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:03:41 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/29 16:27:58 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack **x, int p)
{
	t_stack	*temp;

	if (lstsize(*x) >= 2)
	{
		temp = (*x)->next;
		(*x)->next = temp->next;
		temp->next = *x;
		*x = temp;
	}
	if (p == PRINT_A)
		ft_putstr_fd("sa\n", 1);
	else if (p == PRINT_B)
		ft_putstr_fd("sb\n", 1);
}

void	px(t_stack **x, t_stack **y, int p)
{
	t_stack	*temp;

	if (lstsize(*y) > 0)
	{
		lstadd_front(x, lstnew((*y)->n));
		temp = (*y)->next;
		free(*y);
		*y = temp;
	}
	if (p == PRINT_A)
		ft_putstr_fd("pa\n", 1);
	else if (p == PRINT_B)
		ft_putstr_fd("pb\n", 1);
}

void	ss(t_stack **a, t_stack **b, int p)
{
	sx(a, p);
	sx(b, p);
	if (p == PRINT)
		ft_putstr_fd("ss\n", 1);
}
