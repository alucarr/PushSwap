/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:39:37 by alucar            #+#    #+#             */
/*   Updated: 2023/10/12 14:39:39 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

size_t	ft_strlen(const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == ' ')
	{
		i++;
		continue ;
	}
	while (s[i])
	{
		j++;
		i++;
	}
	return ((size_t) j);
}

size_t	ft_atoi(char *str)
{
	size_t		sign;
	long long	result;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
		if (str[i] == '-' || str[i] == '+')
			error_message();
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
	}
	result *= sign;
	if (!(result > -2147483648 && result < 2147483647))
		error_message();
	return (result);
}

void	is_double(t_struct *lc)
{
	int	i;
	int	j;

	i = 0;
	while (i < lc->size_stack_a)
	{
		j = i + 1;
		while (j < lc->size_stack_a)
		{
			if (lc->stack_a[i] == lc->stack_a[j])
				error_message();
			j++;
		}
		i++;
	}
}

void	bubble_sort(t_struct *lc)
{
	int				i;
	int				j;
	int				tmp;
	unsigned int	a;

	a = lc->size_stacks;
	i = 0;
	j = 0;
	while (a)
	{
		j = 0;
		while (j < lc->size_stacks - 1)
		{
			if (lc->stack_b[j] > lc->stack_b[j + 1])
			{
				tmp = lc->stack_b[j];
				lc->stack_b[j] = lc->stack_b[j + 1];
				lc->stack_b[j + 1] = tmp;
			}
			j++;
		}
		a--;
	}
}
