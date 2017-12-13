/*
** liste_env.c for  in /home/zitouni/rendu
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Mon May  4 21:50:30 2015 Yassine Zitouni
** Last update Fri Jun 19 15:42:20 2015 Yassine Zitouni
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"../struct.h"
#include	"write.h"
#include	"liste_env.h"

int		empty_liste_env(t_liste *liste, char *str)
{
  t_element     *element;

  if ((element = malloc(sizeof(t_element))) == NULL)
    return (-1);
  element->str = str;
  element->next = NULL;
  element->prev = NULL;
  liste->last = element;
  liste->first = element;
  return (0);
}

int		add_in_liste_env(t_liste *liste, char *str)
{
  t_element     *new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (-1);
  new->str = str;
  new->next = NULL;
  new->prev = liste->last;
  liste->last->next = new;
  liste->last = new;
  return (0);
}

int             liste_in_env(t_liste *liste, char **tab)
{
  int           i;

  i = 1;
  empty_liste_env(liste, tab[0]);
  while (tab[i] != NULL)
    {
      add_in_liste_env(liste, tab[i]);
      i++;
    }
  return (0);
}

int		my_show_liste_env(t_liste *liste)
{
  t_element     *tmp;

  tmp = liste->first;
  while (tmp != NULL)
    {
      my_putstr(tmp->str);
      my_putchar('\n');
      tmp = tmp->next;
      if (tmp  == NULL)
	return (-1);
    }
  return (0);
}

char            *found_path(t_liste *liste)
{
  t_element     *tmp;

  tmp = liste->first;
  while (tmp != NULL && my_strncmp(tmp->str, "PATH=", 5) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    return (NULL);
  liste->path = tmp;
  return (tmp->str + 5);
}
