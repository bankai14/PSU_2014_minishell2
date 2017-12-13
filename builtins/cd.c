/*
** cd.c for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sun May 10 18:32:25 2015 Yassine Zitouni
** Last update Tue May 19 14:51:06 2015 Yassine Zitouni
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"../struct.h"
#include	"../parsing/write.h"
#include	"cd.h"

char		*found_home(t_liste *liste)
{
  t_element	*tmp;

  tmp = liste->first;
  while (my_strncmp(tmp->str, "HOME=", 5) != 0)
    {
      tmp = tmp->next;
      if (tmp == NULL)
	return (NULL);
    }
  liste->home = tmp;
  return (tmp->str + 5);
}

char		*found_old_pwd(t_liste *liste)
{
  t_element	*tmp;

  tmp = liste->first;
  while (my_strncmp(tmp->str, "OLDPWD=", 7) != 0)
    {
      tmp = tmp->next;
      if (tmp == NULL)
	return (NULL);
    }
  return (tmp->str + 7);
}

void		use_cd(t_liste *liste, char **tab)
{
  t_element	element;
  
  element.str = found_home(liste);
  if (chdir(element.str) == -1)
    my_putstr("cd can't be lunch(chdir HOME not found)\n");
}

void            cd_point(t_liste *liste)
{
  t_element     element;

  if (chdir("..") == -1)
    my_putstr("Error with chdir..\n");
}

void		cd_tire(t_liste *liste)
{
  t_element	element;

  element.str = found_old_pwd(liste);
  if (chdir(element.str) == -1)
    my_putstr("bash: cd: OLDPWD not set\n");
}

void		cd_word(char **str)
{
  t_element	element;

  my_putstr(str[2]);
  my_putchar('\n');
  if (chdir(str[1]) == -1)
    my_putstr("Error with chdir\n");
}
