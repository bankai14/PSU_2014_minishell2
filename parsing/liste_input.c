/*
** liste_input.c for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Mon May  4 21:27:41 2015 Yassine Zitouni
** Last update Tue May 19 14:50:08 2015 Yassine Zitouni
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"../struct.h"
#include	"write.h"
#include	"liste_input.h"
#include	"my_str_to_wordtab.h"

int		empty_liste_input(t_liste *liste, char **tab)
{
  t_element     *element;

  if ((element = malloc(sizeof(t_element))) == NULL)
    return (-1);
  element->tab = tab;
  element->next = NULL;
  element->prev = NULL;
  liste->last = element;
  liste->first = element;
  return (0);
}

int		add_in_liste_input(t_liste *liste, char **tab)
{
  t_element     *new;

  if ((new = malloc(sizeof(t_element))) == NULL)
    return (-1);
  new->tab = tab;
  new->next = NULL;
  new->prev = liste->last;
  liste->last->next = new;
  liste->last = new;
  return (0);
}

int             liste_in_commande(t_liste *liste, char **tab)
{
  int           i;

  i = 1;
  empty_liste_input(liste, my_str_to_wordtab2(tab[0]));
  while (tab[i] != NULL)
    {
      add_in_liste_input(liste, my_str_to_wordtab2(tab[i]));
      i++;
    }
  return (0);
}

int		my_show_liste_input(t_liste *liste)
{
  int		i;
  t_element     *tmp;

  tmp = liste->first;
  while (tmp != NULL)
    {
      i = 0;
      while (tmp->tab[i] != NULL)
	{
	  my_putstr("tab = ");
	  my_putstr(tmp->tab[i]);
	  i = i + 1;
	  if (tmp->tab[i] == NULL)
	    my_putstr(" == NULL !\n");
	}
      my_putchar('\n');
      tmp = tmp->next;
    }
  my_putstr("$> ");
  return (0);
}

