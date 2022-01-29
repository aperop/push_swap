/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:43:24 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/29 23:43:00 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **lst)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = *lst;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
}

static void	sort_rotate(t_stack **a)
{
	int		min_pos;
	t_stack	*temp;

	min_pos = 0;
	temp = *a;
	while (temp)
	{
		if (temp->n == lst_min(*a))
			break ;
		temp = temp->next;
		++min_pos;
	}
	if (min_pos > lstsize(*a) / 2)
		min_pos = min_pos - lstsize(*a);
	if (min_pos > 0)
		while (min_pos--)
			rx(a, PRINT_A);
	else
		while (min_pos++)
			rrx(a, PRINT_A);
}

static void	push_b(t_stack **a, t_stack **b)
{
	int	m;

	m = lst_median(*a);
	while (lstsize(*a) > 2)
	{
		if ((*a)->n == lst_min(*a) || (*a)->n == lst_max(*a))
		{
			rx(a, PRINT_A);
			continue ;
		}
		if ((*a)->n < m)
			px(b, a, PRINT_B);
		else
		{
			px(b, a, PRINT_B);
			rx(b, PRINT_B);
		}
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	push_b(a, b);
	if (!lst_is_sorted(*a))
		rx(a, PRINT_A);
	while (lstsize(*b) > 0)
	{
		score_elems(*a, *b);
		rotate_push(a, b);
	}
	sort_rotate(a);
}
