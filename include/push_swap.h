/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:53:38 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/30 13:47:05 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>

# include <stdio.h>

enum e_print
{
	NOT_PRINT,
	PRINT_A,
	PRINT_B,
	PRINT
};

enum e_check
{
	ERROR,
	KO,
	OK
};

typedef struct s_stack
{
	int				n;
	int				score;
	struct s_stack	*next;
}				t_stack;

	/*Parse functions*/

void	parse(t_stack **a, int argc, char **argv);

	/*Mini sort functions*/

void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b);

	/*Big sort functions*/

void	big_sort(t_stack **a, t_stack **b);
void	roll_push_roll(t_stack **a, t_stack **b);
void	score_elems(t_stack *a, t_stack *b);
void	rotate_push(t_stack **a, t_stack **b);

	/*list functions*/

int		lstsize(t_stack *lst);
t_stack	*lstnew(int n);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstadd_front(t_stack **lst, t_stack *new);
t_stack	*lstlast(t_stack *lst);
int		lst_is_sorted(t_stack *lst);
int		lst_min(t_stack *lst);
int		lst_max(t_stack *lst);
int		lst_median(t_stack *lst);

void	free_stack(t_stack **lst);

/*swap 'x':
Swap the first 2 elements at the top of stack `x`.
Do nothing if there is only one or no elements.*/
void	sx(t_stack **x, int p);

/*swap 'a' and swap 'b' at the same time.*/
void	ss(t_stack **a, t_stack **b, int p);

/*push 'x':
Take the first element at the top of `y` and put it at the top of `x`.
Do nothing if `y` is empty.*/
void	px(t_stack **x, t_stack **y, int p);

/*rotate 'x':
Shift up all elements of stack `x` by 1.
The first element becomes the last one.*/
void	rx(t_stack **x, int p);

/*rotate 'a' and rotate 'b' at the same time.*/
void	rr(t_stack **a, t_stack **b, int p);

/*reverse rotate 'x':
Shift down all elements of stack `x` by 1.
The last element becomes the first one.*/
void	rrx(t_stack **x, int p);

/*reverse rotate 'a' and reverse rotate 'b' at the same time.*/
void	rrr(t_stack **a, t_stack **b, int p);

#endif
