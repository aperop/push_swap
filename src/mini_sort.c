/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:39:52 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/29 20:03:09 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = (*a)->n;
	a2 = (*a)->next->n;
	a3 = (*a)->next->next->n;
	if (a2 < a1 && a1 < a3)
		sx(a, PRINT_A);
	else if (a3 < a1 && a1 < a2)
		rrx(a, PRINT_A);
	else if (a1 < a3 && a3 < a2)
	{
		rrx(a, PRINT_A);
		sx(a, PRINT_A);
	}
	else if (a3 < a2 && a2 < a1)
	{
		rx(a, PRINT_A);
		sx(a, PRINT_A);
	}
	else if (a2 < a3 && a3 < a1)
		rx(a, PRINT_A);
}

static void	push_b_min(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *a;
	while (temp)
	{
		if (temp->n == lst_min(*a))
			break ;
		++i;
		temp = temp->next;
	}
	while (i > 2 && i++ < 5)
		rrx(a, PRINT_A);
	while (i <= 2 && i--)
		rx(a, PRINT_A);
	px(b, a, PRINT_B);
}

static void	push_b_max(t_stack **a, t_stack **b)
{
	if ((*a)->next->n == lst_max(*a))
		rx(a, PRINT_A);
	else if ((*a)->next->next->n == lst_max(*a))
	{
		rx(a, PRINT_A);
		rx(a, PRINT_A);
	}
	else if (lstlast(*a)->n == lst_max(*a))
		rrx(a, PRINT_A);
	px(b, a, PRINT_B);
}

void	sort_5(t_stack **a, t_stack **b)
{
	if (lstsize(*a) == 5)
		push_b_min(a, b);
	push_b_max(a, b);
	sort_3(a);
	px(a, b, PRINT_A);
	rx(a, PRINT_A);
	if (lstsize(*b) != 1)
		return ;
	px(a, b, PRINT_A);
}
