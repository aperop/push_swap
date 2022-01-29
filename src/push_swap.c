/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:55:58 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/29 21:09:32 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack **a, t_stack **b)
{
	(void)b;
	if (lst_is_sorted(*a))
		return ;
	if (lstsize(*a) == 2)
		sx(a, PRINT_A);
	else if (lstsize(*a) == 3)
		sort_3(a);
	else if (lstsize(*a) <= 5)
		sort_5(a, b);
	else
		big_sort(a, b);
}
/*
#include <stdio.h>
static void print(t_stack	*a)
{
	t_stack *p = a;
	if(a!=NULL)
	{
		while(p!=NULL)
		{
			printf("%d\t", p->n);
			p = p->next;
		}
		printf("\n");
	}
}
*/

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc == 1)
		exit(0);
	parse(&a, argc, argv);
	sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
}
