/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:39:11 by alucar            #+#    #+#             */
/*   Updated: 2023/10/12 14:39:13 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	*lc;

	lc = malloc(sizeof(t_struct));
	if (argc <= 1)
		exit(0);
	args_control(lc, argv);
	mini_sort(lc);
}
