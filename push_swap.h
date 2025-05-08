/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:40:10 by alucar            #+#    #+#             */
/*   Updated: 2023/10/12 14:40:11 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	int		*stack_a;
	int		*stack_b;
	int		size_stacks;
	int		count;
	int		size_stack_a;
	int		size_stack_b;
}t_struct;

void	error_message(void);
char	**ft_split(char const *s, char c);
void	free_data(char **temp);
void	args_control(t_struct *lc, char **argv);
int		argv_counter(char **argv);
size_t	ft_strlen(const char *s);
size_t	ft_atoi(char *str);
void	is_double(t_struct *lc);
void	bubble_sort(t_struct *lc);
void	add_index(t_struct *lc);
void	is_number(char **numbers);
void	is_sorted(t_struct *lc);
void	mini_sort(t_struct *lc);
void	sa(t_struct *lc);
void	ra(t_struct *lc);
void	rra(t_struct *lc);
void	ft_bzero(t_struct *lc, size_t n);
void	pb(t_struct *lc);
void	pa(t_struct *lc);
int		get_max_bits(t_struct *stack);
void	radix_sort(t_struct *stack);
int		is_empty(t_struct *stack);
void	is_one(t_struct *lc);
void	*ft_calloc(size_t count, size_t size);
void	pb_zero(int lena, t_struct *lc);
void	pb_multi(int lena, int lenb, t_struct *lc);
void	pas(int lena, int lenb, t_struct *lc);
void	is_zero(t_struct *lc);
#endif