/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:39:17 by alucar            #+#    #+#             */
/*   Updated: 2023/10/12 14:39:18 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_three(t_struct *lc)
{
	int	i;

	i = 0;
	while (i < lc->size_stacks)
	{
		if (lc->stack_a[1] > lc->stack_a[2]
			&& lc->stack_a[1] > lc->stack_a[0])
			rra(lc);
		else if (lc->stack_a[0] > lc->stack_a[1]
			&& lc->stack_a[0] < lc->stack_a[2])
			sa(lc);
		else if (lc->stack_a[0] > lc->stack_a[2]
			&& lc->stack_a[0] > lc->stack_a[1])
			ra(lc);
		else
			break ;
		i++;
	}
}

void	for_four(t_struct *lc)
{
	int	i;

	i = -1;
	while (++i < lc->size_stacks)
	{
		if (lc->stack_a[0] < lc->stack_a[1]
			&& lc->stack_a[0] < lc->stack_a[2]
			&& lc->stack_a[0] < lc->stack_a[3])
		{
			pb(lc);
			break ;
		}
		else if (lc->stack_a[3] < lc->stack_a[1]
			&& lc->stack_a[3] < lc->stack_a[2]
			&& lc->stack_a[3] < lc->stack_a[0])
		{
			rra(lc);
			pb(lc);
			break ;
		}
		else
			ra(lc);
	}
	for_three(lc);
	pa(lc);
}

void	for_five(t_struct *l)
{
	int	i;

	i = -1;
	while (++i < l->size_stacks)
	{
		if (l->stack_a[0] < l->stack_a[1] && l->stack_a[0] < l->stack_a[2]
			&& l->stack_a[0] < l->stack_a[3]
			&& l->stack_a[0] < l->stack_a[4])
		{
			pb(l);
			break ;
		}
		else if (l->stack_a[4] < l->stack_a[1] && l->stack_a[4] < l->stack_a[2]
			&& l->stack_a[4] < l->stack_a[3]
			&& l->stack_a[4] < l->stack_a[0])
		{
			rra(l);
			pb(l);
			break ;
		}
		else
			ra(l);
	}
	for_four(l);
	pa(l);
}

void	mini_sort(t_struct *lc)
{
	if (lc->size_stacks == 2)
		sa(lc);
	else if (lc->size_stacks == 3)
		for_three(lc);
	else if (lc->size_stacks == 4)
		for_four(lc);
	else if (lc->size_stacks == 5)
		for_five(lc);
	else
	{
		radix_sort(lc);
	}
}
