/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zcaca44.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:48:33 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/18 17:43:56 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	is_empty(t_list *stack_a)
{
	if (stack_a == NULL)
		return (0);
	else
		return (1);
}

void	print_list(t_list *stack_a)
{
	if (is_empty(stack_a) == 0)
	{
		printf("%s\n", "la liste est vide.");
		return ;
	}
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
}

t_list	*push_back_list(t_list *stack_a, int x)
{
	t_list	*new;
	t_list	*temp;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = x;
	new->next = NULL;
	if (is_empty(stack_a) == 0)
		return (new);
	temp = stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return (stack_a);
}

t_list	*push_front_list(t_list *stack_a, int x)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = x;
	if (is_empty(stack_a) == 0)
		new->next = NULL;
	else
		new->next = stack_a;
	return (new);
}

t_list	*pop_back_list(t_list *stack_a)
{
	t_list	*temp;
	t_list	*before;

	temp = stack_a;
	before = stack_a;
	if (is_empty(stack_a) == 0)
		return (stack_a);
	if (stack_a->next == NULL)
	{
		free(stack_a);
		return (stack_a);
	}
	while (temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	free(temp);
	return (stack_a);
}

t_list	*pop_front_list(t_list *stack_a)
{
	t_list	*new;

	if (is_empty(stack_a) == 0)
		return (stack_a);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new = stack_a->next;
	free(stack_a);
	return (new);
}

t_list	*clear_list(t_list *stack_a)
{
	if (is_empty(stack_a) == 0)
		return (NULL);
	while (stack_a != NULL)
		stack_a = pop_front_list(stack_a);
	return (NULL);
}
