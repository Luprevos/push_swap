/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:12:36 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/09 17:45:46 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void is_above_mediane(t_list **stack)
{
    int mediane;
    int len;
    int i = 0;

    if (*stack)
    {
        len = stack_len(*stack);
        if (len % 2 == 0)
            mediane = len / 2;
        else
            mediane = (len / 2) + 1;
        
        while (i < len)
        {
            if ((*stack)->value > mediane)
                (*stack)->above_median = true;
            else
                (*stack)->above_median = false;
            i++;
            (*stack) = (*stack)->next;
        }
    }
}
