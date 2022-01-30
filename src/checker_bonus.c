/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:31:04 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/29 23:36:06 by dhawkgir         ###   ########.fr       */
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

static void	free_exit(t_stack **a, t_stack **b, char *cmd, int flag)
{
	if (flag == ERROR)
		ft_putstr_fd("Error\n", 2);
	else if (flag == OK)
		ft_putstr_fd("OK\n", 1);
	else if (flag == KO)
		ft_putstr_fd("KO\n", 1);
	free_stack(a);
	free_stack(b);
	free(cmd);
	exit(0);
}

static void	do_command(t_stack **a, t_stack **b, char *cmd)
{
	if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "sa", 2))
		sx(a, NOT_PRINT);
	else if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "sb", 2))
		sx(b, NOT_PRINT);
	else if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "ss", 2))
		ss(a, b, NOT_PRINT);
	else if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "pa", 2))
		px(a, b, NOT_PRINT);
	else if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "pb", 2))
		px(b, a, NOT_PRINT);
	else if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "ra", 2))
		rx(a, NOT_PRINT);
	else if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "rb", 2))
		rx(b, NOT_PRINT);
	else if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "rr", 2))
		rr(a, b, NOT_PRINT);
	else if (ft_strlen(cmd) == 3 && !ft_strncmp(cmd, "rra", 3))
		rrx(a, NOT_PRINT);
	else if (ft_strlen(cmd) == 3 && !ft_strncmp(cmd, "rrb", 3))
		rrx(b, NOT_PRINT);
	else if (ft_strlen(cmd) == 3 && !ft_strncmp(cmd, "rrr", 3))
		rrr(a, b, NOT_PRINT);
	else
		free_exit(a, b, cmd, ERROR);
}

static int	read_cmd(char **cmd)
{
	int		rd;
	int		i;

	rd = 0;
	i = 0;
	rd = read(0, &(*cmd)[i], 1);
	while (rd > 0 && (*cmd)[i] != '\n')
	{
		++i;
		rd = read(0, &(*cmd)[i], 1);
		if (i > 4)
		{
			while (rd > 0 && (*cmd)[0] != '\n')
				rd = read(0, &(*cmd)[0], 1);
			return (0);
		}
	}
	(*cmd)[i] = '\0';
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*cmd;

	b = NULL;
	cmd = ft_calloc(4, sizeof(char));
	if (argc == 1)
		exit(0);
	parse(&a, argc, argv);
	while (1)
	{
		if (!read_cmd(&cmd))
			free_exit(&a, &b, cmd, ERROR);
		if (!ft_strlen(cmd))
			break ;
		do_command(&a, &b, cmd);
	}
	if (lst_is_sorted(a) && !lstsize(b))
		free_exit(&a, &b, cmd, OK);
	else
		free_exit(&a, &b, cmd, KO);
}
