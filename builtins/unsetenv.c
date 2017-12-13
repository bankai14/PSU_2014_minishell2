/*
** unsetenv.c for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sun May 10 18:47:07 2015 Yassine Zitouni
** Last update Tue May 19 14:52:34 2015 Yassine Zitouni
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"../struct.h"
#include	"unsetenv.h"
#include	"../parsing/liste_env.h"
#include	"../parsing/write.h"

int		my_setenv2(t_liste *liste, char **tab, char *env_word)
{
  t_element	*tmp;
  int		i;

  i = 0;
  tmp = liste->first;
  while (my_strncmp(tmp->str, env_word, my_strlen(env_word)) != 0)
    {
      tmp = tmp->next;
      if (tmp->next == NULL && tmp->str != env_word)
        {
          add_in_liste_env(liste, my_strcat(env_word, "="));
     	}
    }
  return (0);
}

int		my_setenv(t_liste *liste, char **tab)
{
  t_element	*tmp;
  int		i;
  char		*env_word;
  char		*new_word;

  i = 0;
  env_word =  tab[1];
  new_word = tab[2];
  if (new_word == NULL)
    {
      my_setenv2(liste, tab, env_word);
      return (0);
    }
  tmp = liste->first;
  while (my_strncmp(tmp->str, env_word, my_strlen(env_word)) != 0)
    {
      tmp = tmp->next;
      if (tmp->next == NULL && tmp->str != env_word)
	{
	  add_in_liste_env(liste, my_strcat(my_strcat(env_word, "="), new_word));
	}
    } 
  while (tmp->str[i] != '=')
    i++;
   i = i + 1;
  my_strcpy(tmp->str + i, new_word);
  return (0);
}

int		first_element(t_liste *liste)
{
  t_element	*tmp;

  tmp = liste->first->next;
  free(tmp->prev);
  liste->first = tmp;
  return (0);
}

int		last_element(t_liste *liste)
{
  t_element	*tmp;

  tmp = liste->last->prev;
  free(tmp->next);
  liste->last = tmp;
  tmp->next = NULL;
  return (0);
}

int             my_unsetenv(t_liste *liste, char *delete)
{
  t_element     *tmp;

  tmp = liste->first;
  while (tmp != NULL && (my_strncmp(tmp->str, delete, my_strlen(delete)) != 0))
    {
      if (tmp->next == NULL)
	{
	  my_putstr("existe pas\n");
	  return (-1);
	}
      tmp = tmp->next;
    }
  if (tmp->next != NULL && tmp->prev != NULL)
    {
      liste->my_delete = tmp;
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;
      free(tmp);
    }
  else if (tmp->prev == NULL && tmp->next != NULL)
    first_element(liste);
  else if (tmp == liste->last)
    {
      my_putstr("le dernier element !\n");
      last_element(liste);
    }
  return (0);
}
