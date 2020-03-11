/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:08:44 by jbodson           #+#    #+#             */
/*   Updated: 2020/03/10 19:03:02 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putcharbasep(char c, t_list *lst)
{
	write (1, &c, 1);
	lst->retour++;
}

int    ft_ifp(unsigned long nb, t_list *lst)
{
    int i;
	int x;
	int y;
	int numb1;
    int numb2;
	unsigned long nb2;
	int k;
	int u;
	int o;

	nb2 = nb;
    numb1 = 0;
    numb2 = 0;
	x = 0;
	y = 0;
	i = -1;
	u = 0;
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
	if(numb1 == 0 && numb2 == 0 && lst->prec == 1)
	{	
		write(1, "0x", 2);
		lst->retour += 2;
		return 1;
	}
	k = numb2;
	if (numb1 < 0)
		numb1 = -numb1;
	if (!numb2 && !nb && lst->prec)
	{
		while (++i < numb1)
		{	
			write(1, lst->zero ? "0" : " ", 1);
			lst->retour++;
		}	
		return (numb1);
	}
	i =	ft_putnumberbasep(nb, lst);
	if (nb == 0 && lst->prec == 0)
		i++;
	o = numb2;
	while (lst->prec == 1 && numb1 > numb2 && i < numb1 && lst->neg == 0)
	{
		ft_putcharbasep(' ', lst);
		numb1--;
	}

	while (lst->prec == 1 && i < numb2)
	{
		ft_putcharbasep('0', lst);
		numb2--;
	}
	while (i <= numb1 && lst->neg == 0 && lst->prec == 0)
	{
		if (lst->zero == 1)
		{
			if ((lst->zero == 1 && x == 0) || (lst->zero == 1 && i < numb1 - 1 && x == 1))
				ft_putcharbasep('0', lst);
		}
		if (lst->zero == 0)
			ft_putcharbasep(' ', lst);
		i++;
	}
	ft_putnumberbase2p(nb2, lst);
	if (lst->neg == 1 && o > i)
		u = -1;	
	if (lst->neg == 1 && lst->prec == 1)
	{
		i = k + 1 + u;
	}
	while (i <= numb1 && lst->neg == 1)
	{
		ft_putcharbasep(' ', lst);
		i++;
	}
    return (1);
}

int    ft_putnumberbasep(unsigned long nb, t_list *lst)
{
      int i;
      char str[5000];
 
      if (!nb)
      {
          lst->i = 3;
          return (lst->i);
      }
      i = 0;
       lst->i = lst->i + 3;
      while (nb)
      {
          str[i] = nb % 16;
          nb = nb / 16;
          i++;
      }
      while (--i >= 0)
          lst->i++;
	  return (lst->i);
}
 
void    ft_putnumberbase2p(unsigned long nb, t_list *lst)
{
      int i;
	  int j;
      char str[1234];
	  char *base;
	  
	  j = 0;
	  base = "0123456789abcdef";
      i = 0;
	  if(nb)
       { 
		write(1, "0x", 2);
		lst->retour += 2;
	   }
	  if(!nb)
       {
	    write(1, "0x0", 3);
		lst->retour += 3;
	   }
      if (nb == 0 && lst->prec == 0 && j == 0)
	  {	
          if(nb)  
            ft_putcharbasep('0', lst);
		  return ;
	  }
      while (nb)
      {
          str[i] = nb % 16;
          nb = nb / 16;
          i++;
		  j++;
      }
      while (--i >= 0)
          ft_putcharbasep(base[(int)str[i]], lst);
}