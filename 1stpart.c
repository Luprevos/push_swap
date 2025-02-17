/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1stpart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:53:24 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/17 16:56:28 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	sa(t_list **stack_a, int n)
{
	t_list	*temp;
	int		x;

	temp = *stack_a;
	if (!temp->next)
		return ;
	*stack_a = (*stack_a)->next;
	x = (*stack_a)->value;
	(*stack_a)->value = temp->value;
	*stack_a = temp;
	(*stack_a)->value = x;
	if (n == 0)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_a, int n)
{
	t_list	*temp;
	int		x;

	temp = *stack_a;
	if (!temp->next)
		return ;
	*stack_a = (*stack_a)->next;
	x = (*stack_a)->value;
	(*stack_a)->value = temp->value;
	*stack_a = temp;
	(*stack_a)->value = x;
	if (n == 0)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	write(1, "ss\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (is_empty(*stack_b) == 0)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (is_empty(*stack_a) == 0)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}
