/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:39:02 by alucar            #+#    #+#             */
/*   Updated: 2023/10/12 14:39:03 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char *arg)
{
	int	i;

	i = 0;
	while (arg[i++])
	{
		if (arg[i] == ' ')
			return (1);
	}
	return (0);
}

int	argv_counter(char **argv)
{
	int		i;
	int		j;
	int		counter;
	char	**temp_arg;

	i = 1;
	counter = 0;
	while (argv[i])
	{
		if (is_space(argv[i]))
		{
			temp_arg = ft_split(argv[i], 32);
			j = 0;
			while (temp_arg[j])
			{
				counter++;
				j++;
			}
			free_data(temp_arg);
		}
		else
			counter++;
		i++;
	}
	return (counter);
}

void	convert_arg(t_struct *lc, char **argv)
{
	int		i;
	int		j;
	int		ai;
	char	**temp;

	i = 1;
	ai = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0 || argv[i] == NULL)
			error_message();
		if (is_space(argv[i]))
		{
			temp = ft_split(argv[i], 32);
			j = 0;
			while (temp[j])
				lc->stack_a[ai++] = ft_atoi(temp[j++]);
			free_data(temp);
		}
		else
			lc->stack_a[ai++] = ft_atoi(argv[i]);
		i++;
	}
}

void	args_control(t_struct *lc, char **argv)
{
	lc->size_stacks = argv_counter(argv);
	lc->stack_a = ft_calloc(sizeof(int), lc->size_stacks + 1);
	lc->stack_b = ft_calloc(sizeof(int), lc->size_stacks + 1);
	lc->size_stack_a = lc->size_stacks;
	lc->size_stack_b = 0;
	is_number(argv);
	convert_arg(lc, argv);
	is_zero(lc);
	is_one(lc);
	is_double(lc);
	add_index(lc);
	is_sorted(lc);
	ft_bzero(lc, lc->size_stacks);
}

void	add_index(t_struct *lc)
{
	int	i;
	int	j;

	i = 0;
	while (i < lc->size_stacks)
	{
		lc->stack_b[i] = lc->stack_a[i];
		i++;
	}
	bubble_sort(lc);
	i = 0;
	while (i < lc->size_stacks)
	{
		j = 0;
		while (i < lc->size_stacks)
		{
			if (lc->stack_a[i] == lc->stack_b[j])
			{
				lc->stack_a[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
}
