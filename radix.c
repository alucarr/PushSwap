/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:39:32 by alucar            #+#    #+#             */
/*   Updated: 2023/10/12 14:39:34 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_struct *stack)
{
	int	max_value;
	int	max_bit;
	int	i;

	i = 0;
	max_value = stack->stack_a[0];
	while (i < stack->size_stacks)
	{
		if (stack->stack_a[i] > max_value)
			max_value = stack->stack_a[i];
		i++;
	}
	if (max_value < 0)
		max_value = -max_value;
	max_bit = 0;
	while (max_value > 0)
	{
		max_value >>= 1;
		max_bit++;
	}
	return (max_bit);
}

void	radix_sort(t_struct *stack)
{
	int	i;
	int	size;
	int	j;

	size = get_max_bits(stack);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < stack->size_stacks)
		{
			if ((stack->stack_a[0] >> i) & 1)
				ra(stack);
			else
				pb(stack);
			j++;
		}
		i++;
		while (!is_empty(stack))
		{
			pa(stack);
		}
	}
}

int	is_empty(t_struct *stack)
{
	int	i;

	i = stack->size_stack_b + 1;
	if (i)
	{
		i--;
	}
	if (i != 0)
		return (0);
	return (1);
}
