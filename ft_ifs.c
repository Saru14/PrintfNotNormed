/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:02:15 by jbodson           #+#    #+#             */
/*   Updated: 2020/03/10 18:53:13 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_ifs(char *str, t_list *lst)
{
    int i;
    int numb1;
    int numb2;
    int u;

    numb1 = 0;
    u = 0;
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
    if (numb2 < 0)
        lst->prec = 0;
    if (!str)
    {
        str = "(null)";
    }
    i = 0;
    if (numb1 < 0)
        numb1 = numb1 * -1;
    if (lst->neg == 1)
    {
        while (str[i] && (lst->prec == 0 || numb2 > 0))
        {
            write (1, &str[i], 1);
            lst->retour++;
            numb2--;
            i++;
        }
        if (numb1 < 0)
        {
            i = -i;
            u++;
        }
        while(numb1 < i && u == 1)
        {
            write(1, " ", 1);
            lst->retour++;
            numb1++;
        }
        while (i < numb1)
        {
            write (1, " ", 1);
            lst->retour++;
            numb1--;
            
        }
        return ;
    }
    while (ft_strlen(str) < numb1 || (numb1 > numb2 && lst->prec == 1))
    {
        write(1, " ", 1);
        lst->retour++;
        numb1--;
    }
    while (str[i] && (lst->prec == 0 || numb2 > 0))
    {
        write(1, &str[i], 1);
        lst->retour++;
        numb2--;
        i++;
    }
    return ;
}