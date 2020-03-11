/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:49:46 by jbodson           #+#    #+#             */
/*   Updated: 2020/03/10 18:55:39 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_ifc(int c, t_list *lst)
{
    int numb1;
    int numb2;

    numb1 = 0;
    numb2 = 0;
    if (lst->star1 > 0 || lst->star1 < 0)
        numb1 = lst->star1;
    else if (lst->nb1 > 0 || lst->nb1 < 0)
    {
        numb1 = lst->nb1;
    }
    if (lst->star2 > 0 || lst->star2 < 0)
        numb2 = lst->star2;
    else if (lst->nb2 > 0 || lst->nb2 < 0)
    {
        numb2 = lst->nb2;
    }
    if(c == '%' && lst->zero == 1)
    {
        while(numb1 > 1)
        {
            write(1, "0", 1);
            lst->retour++;
            numb1--;
        }
    }
    if (lst->neg == 1)
    {
        write(1, &c, 1);
        lst->retour++;
        while (numb1 > 1 || numb1 < -1)
        {
            write (1, " ", 1);
            lst->retour++;
            if(numb1 > 0)
                numb1--;
            else if(numb1 < 0)
                numb1++;
        }
        return 0;
    }
    while (numb1 > 1)
    {
        write(1, " ", 1);
        lst->retour++;
        numb1--;
    }
    write(1, &c, 1);
    lst->retour++;
    return (0);
}