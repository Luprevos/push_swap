/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:58:30 by luprevos          #+#    #+#             */
/*   Updated: 2024/11/08 17:05:23 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pswap.h"

int	syntax_error(char *str)
{
    if (!(*str == '+'
    || *str == '-'
    || (*str >= '0' && *str <= '9')))
        return (1);
    if ((*str == '+'
                || *str == '-')
                && !(str[1] >= '0' && str[1] <= '9'))
                return (1);
    while (*++str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return(1);
    }
    return (0);
}

int check_double(t_list *a, int n)
{
    if (!a)
        return (0);
    while(a)
    {
        if (a->value == n)
            return (1);
        a = a->next;
    }
    return (0);
}

void    free_stack(t_list **stack)
{
    t_list  *temp;
    t_list  *current;

    if (!stack)
        return ;
    current = *stack;
    while (current)
    {
        temp = current->next;
        current->value = 0;
        free(current);
        current = temp;
    }
    *stack = NULL;
}

void    free_errors(t_list **stack)
{
    free_stack(stack);
    write(1, "Error\n", 6);
    exit(1);
}