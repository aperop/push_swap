/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:41:03 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/30 00:13:28 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_score(t_stack *a, int elem)
{
	int	min;
	int	count;
	int	size;

	count = 0;
	size = lstsize(a);
	min = lst_min(a);
	if (a->n == min && elem < a->n)
		return (0);
	if (a->n > elem && lstlast(a)->n < elem)
		return (0);
	while (a->next)
	{
		++count;
		if (a->next->n == min && elem < a->next->n)
			break ;
		if (a->n < elem && (a->next->n > elem || a->next->n == min))
			break ;
		a = a->next;
	}
	if (count > size / 2)
		count = -1 * (size - count);
	return (count);
}

int	b_score(t_stack *b, int elem)
{
	int	count;
	int	size;

	count = 0;
	size = lstsize(b);
	while (b)
	{
		if (b->n == elem)
			break ;
		b = b->next;
		++count;
	}
	if (count > size / 2)
		count = (-1) * (size - count);
	return (count);
}

void	score_elems(t_stack *a, t_stack *b)
{
	int	i;
	int	score_a;
	int	b_size;

	i = 0;
	b_size = lstsize(b);
	while (b)
	{
		score_a = a_score(a, b->n);
		if (score_a < 0)
			score_a *= -1;
		if (i < b_size / 2)
			b->score = i + score_a;
		else
			b->score = (b_size - i) + score_a;
		++i;
		b = b->next;
	}
}

void	rotate(t_stack **a, t_stack **b, t_stack *node)
{
	int	r_a;
	int	r_b;

	r_a = a_score(*a, node->n);
	r_b = b_score(*b, node->n);
	if (r_a < 0 && r_b < 0)
		while (r_a < 0 && r_b < 0 && r_a++ < __INT_MAX__ && r_b++ < __INT_MAX__)
			rrr(a, b, PRINT);
	else if (r_a > 0 && r_b > 0)
		while (r_a > 0 && r_b > 0 && r_a-- < __INT_MAX__ && r_b-- < __INT_MAX__)
			rr(a, b, PRINT);
	if (r_a < 0)
		while (r_a++)
			rrx(a, PRINT_A);
	else
		while (r_a--)
			rx(a, PRINT_A);
	if (r_b < 0)
		while (r_b++)
			rrx(b, PRINT_B);
	else
		while (r_b--)
			rx(b, PRINT_B);
}

void	rotate_push(t_stack **a, t_stack **b)
{
	t_stack	*to_push;
	t_stack	*temp;

	(void)a;
	to_push = *b;
	temp = *b;
	while (temp)
	{
		if (temp->score < to_push->score)
			to_push = temp;
		temp = temp->next;
	}
	rotate(a, b, to_push);
	px(a, b, PRINT_A);
}
