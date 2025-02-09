/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:51:58 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/05 14:17:21 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

long     ft_atoi(const char *str)
{
		long     i;
		long     nb;
		long     s;

		s = 1;
		i = 0;
		nb = 0;
		while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
				i++;
		if ((str[i] == '-') || (str[i] == '+'))
		{
				if (str[i] == '-')
						s = -s;
				i++;
		}
		while (str[i] && ft_isdigit(*str))
		{
				nb = nb * 10 + (str[i] - '0');
				i++;
		}
		return (nb * s);
}


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
void	add_last(t_list	**stack, int n)
{
	t_list	*temp;
	t_list	*last;

	if (!stack)
		return ;
	temp = malloc(sizeof(t_list));
	if (!temp)
		return ;
	temp->next = NULL;
	temp->value = n;
	temp->cheapest = 0;

	// int				index;
	// int				push_cost;
	 //temp->above_median = 0;
	// temp->target_node = NULL;

	if (!(*stack))
	{
		*stack = temp;
		temp->prev = NULL;
	}
	else
	{
		last = go_last(stack);
		last->next = temp;
		temp->prev = last;
	}
}

void	init_stack_a(t_list **stack_a , char **av)
{
	long	n;
	int			i;

	i = 0;
	while(av[i])
	{
		if(syntax_error(av[i]))
			free_errors(stack_a);
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(stack_a);
		if (check_double(*stack_a, (int)n))
			free_errors(stack_a);
		add_last(stack_a, (int)n);
		i++;
	}
}