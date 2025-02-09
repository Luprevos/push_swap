/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:30:38 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/06 16:23:37 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pswap.h"

int	main(int ac,char **av)
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
		// printf("here boucle ");
		if (stack_len(stack_a) == 2)
			sa(&stack_a, 0);
		else if (stack_len(stack_a) == 3)
			sort_stack_3E(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
    free_stack(&stack_a);
    return (0);
}

/*	int i = 0;
	while (stack_a)
	{
		printf("node [%i] contain value %i\n", i, stack_a->value);
		++i;
		stack_a = stack_a->next;
	}*/

















// int main(void)
// {
//     t_list  *stack_z = malloc(sizeof(t_list));
//     t_list  *prout = malloc(sizeof(t_list));
//     t_list  *zeub = malloc(sizeof(t_list));
//     t_list  *stack_a = malloc(sizeof(t_list));
//     t_list  *stack_b; //malloc(sizeof(t_list));
//     t_list  *tmp = malloc(sizeof(t_list));
//     t_list  *caca = malloc(sizeof(t_list));
//     t_list  *tmpo = malloc(sizeof(t_list));
//     t_list	*popo = malloc(sizeof(t_list));
//     t_list  *lulu = malloc(sizeof(t_list));
//     t_list  *lolo = malloc(sizeof(t_list));
	
//     // stack_z->value = 8;
//     // stack_z->next = prout;
//     // prout->value = 2;
//     // prout->next = zeub;
//     // zeub->value = 9;
//     // zeub->next = NULL;
//     stack_a->value = 1;
//     stack_a->next = tmp;
//     tmp->value = 2;
//     tmp->next = tmpo;
//     tmpo->value = 3;
//     tmpo->next = caca;
//     caca->value = 4;
//     caca->next = NULL;
//     // popo->value = 5;
//     // popo->next = lulu;
//     lulu->value = 6;
//     lulu->next = lolo;
//     lolo->value = 7;
//     lolo->next = NULL;
//     // stack_b = NULL;
//     stack_b = NULL;
//     //stack_a->next = NULL;
//    //is_empty(stack_a);
//     //printf("%d\n",stack_len(stack_a));
//     printf("stack_a\n");
//     print_list(stack_a);
//     // printf("stack_b\n");
//     // print_list(stack_b);
//     //stack_a = pop_front_list(stack_a);
//     //print_list(stack_b);
//     //print_list(stack_b);
//     // stack_a = pop_front_list(stack_a);
//     // stack_a = push_back_list(stack_a, 8);
//     //sort_stack_3E(&stack_z); printf("a");
//     printf("------------------------------\n");
//     min_node(stack_a);
//     //found_min(&stack_a, &stack_b);
//     //printf("%d HERE\n", get_max(&stack_a));
//     // printf("je suis le max: %d\n", get_max(&stack_a));
//     //printf("je suis le min: %d\n", get_min(&stack_a));
//     printf("------------------------------\n");
//     printf("stack_a\n");
//      print_list(stack_a);
//     //  printf("stack_b\n");
//     //  print_list(stack_b);
//     //print_list(stack_b);
//    //print_list(stack_a);
//     //free(stack_a);
//     free(tmp);
//     free(caca);
// }