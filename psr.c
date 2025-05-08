/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:39:27 by alucar            #+#    #+#             */
/*   Updated: 2023/10/12 14:39:29 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_struct *lc)
{
	int	tmp;

	if (lc->stack_a[0] > lc->stack_a[1])
	{
		tmp = lc->stack_a[0];
		lc->stack_a[0] = lc->stack_a[1];
		lc->stack_a[1] = tmp;
		write(1, "sa\n", 3);
	}
}

void	ra(t_struct *lc)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = lc->stack_a[0];
	while (i < lc->size_stack_a)
	{
		lc->stack_a[i -1] = lc->stack_a[i];
		i++;
	}
	lc->stack_a[lc->size_stack_a -1] = tmp;
	lc->stack_a[lc->size_stack_a] = 0;
	write(1, "ra\n", 3);
}

void	rra(t_struct *lc)
{
	int	tmp;
	int	i;

	i = lc->size_stack_a;
	tmp = lc->stack_a[lc->size_stack_a -1];
	while (0 < i)
	{
		lc->stack_a[i] = lc->stack_a[i -1];
		i--;
	}
	lc->stack_a[0] = tmp;
	lc->stack_a[lc->size_stack_a] = 0;
	write(1, "rra\n", 4);
}

void	pb(t_struct *lc)
{
	int	i;
	int	lenb;
	int	lena;

	i = 0;
	lenb = 0;
	lena = 0;
	lc->size_stack_a -= 1;
	lc->size_stack_b += 1;
	while (lc->stack_b[i++])
		lenb++;
	i = 0;
	while (lc->stack_a[i++])
		lena++;
	if (lenb == 0)
		pb_zero(lena, lc);
	else
		pb_multi(lena, lenb, lc);
	write(1, "pb\n", 3);
}

void	pa(t_struct *lc)
{
	int	i;
	int	lenb;
	int	lena;

	i = 0;
	lenb = 0;
	lena = 0;
	lc->size_stack_a += 1;
	lc->size_stack_b -= 1;
	while (lc->stack_b[i++])
		lenb++;
	i = 0;
	while (lc->stack_a[i++])
		lena++;
	pas(lena, lenb, lc);
	write(1, "pa\n", 3);
}
