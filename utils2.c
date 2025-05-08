/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:39:42 by alucar            #+#    #+#             */
/*   Updated: 2023/10/12 14:39:43 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_number(char **numbers)
{
	int	i;
	int	k;

	i = 1;
	while (numbers[i])
	{
		k = 0;
		while (numbers[i][k])
		{
			if ((numbers[i][k] == 45 || numbers[i][k] == 43) &&
				!(numbers[i][k + 1] >= '0' && numbers[i][k + 1] <= '9'))
				error_message();
			if (!(numbers[i][k] >= 48 && numbers[i][k] <= 57) &&
				numbers[i][k] != 32 && numbers[i][k] != 45 &&
				numbers[i][k] != 43)
				error_message();
			if (numbers[i][k] >= '0' && numbers[i][k] <= '9'
				&& (numbers[i][k + 1] == 45 || numbers[i][k + 1] == 43))
				error_message();
			k++;
		}
		i++;
	}
}

void	is_sorted(t_struct *lc)
{
	int	i;

	i = 0;
	while (i < lc->size_stacks -1)
	{
		if (lc->stack_a[i] < lc->stack_a[i + 1])
		{
			if (i +1 == lc->size_stack_a -1)
			{
				exit(0);
			}
			i++;
		}
		else
			break ;
	}
}

void	ft_bzero(t_struct *lc, size_t n)
{
	int	*p;

	p = lc->stack_b;
	while (n)
	{
		*p++ = 0;
		--n;
	}
}

void	is_one(t_struct *lc)
{
	if (lc->size_stacks == 1)
		exit(0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*dst;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
	dst = malloc(total);
	if (!dst)
		return (NULL);
	i = 0;
	while (total--)
	{
		dst[i] = 0;
		i++;
	}
	return ((void *)dst);
}
