/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ndpart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:45:45 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/13 16:59:19 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"


void	ra(t_list **stack_a, int n)
{
	t_list	*temp;
	t_list	*first;

	if(is_empty(*stack_a) == 0)
		return;
	first = *stack_a;
	temp = *stack_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	*stack_a = first->next;
	temp->next = first;
	first->next = NULL;
	if (n == 0)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int n)
{
	t_list	*temp;
	t_list	*first;
	
	if(is_empty(*stack_b) == 0)
		return;
	first = *stack_b;
	temp = *stack_b;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	*stack_b = first->next;
	temp->next = first;
	first->next = NULL;
	if (n == 0)
		write(1, "rb\n", 3);
}

void    rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	write(1, "rr\n", 3);
}

void	rra(t_list **stack_a, int n)
{
	t_list *temp;
	t_list	*last;

	if(is_empty(*stack_a) == 0 || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	last = *stack_a;
	while(last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if(n == 0)
	{
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b, int n)
{
	t_list *temp;
	t_list	*last;

	if(is_empty(*stack_b) == 0 || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	last = *stack_b;
	while(last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if(n == 0)
	{
		write(1, "rrb\n", 4);
	}
}