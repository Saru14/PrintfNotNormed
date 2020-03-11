/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:05:55 by jbodson           #+#    #+#             */
/*   Updated: 2020/03/10 18:52:31 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//# define INPUT "%.p|\n", NULL

int main()
{
    char *str = NULL;
    /*char c;
    int r00 = 0;
    c = 'x';*/
    ft_printf("|%d|\n", ft_printf("%-1s", NULL));
    printf("|%d|\n", printf("%.4s   %s", "louuuuul", "eh"));
    return (0);
}