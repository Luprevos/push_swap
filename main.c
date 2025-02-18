/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:30:38 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/18 17:11:46 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack_a(&stack_a, av + 1);
	if (!(stack_already_sorted(stack_a)))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a, 0);
		else if (stack_len(stack_a) == 3)
			sort_stack_3E(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	// printf("-- Stack A --\n");
	// print_list(stack_a);
	// printf("-- Stack B --\n");
	// print_list(stack_b);
	free_stack(&stack_a);
	return (0);
}
