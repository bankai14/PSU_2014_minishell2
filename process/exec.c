/*
** exec.c for  in /home/zitouni/rendu/PSU_2014_minishell1
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sun Mar 29 22:21:30 2015 Yassine Zitouni
** Last update Tue May 19 14:58:49 2015 Yassine Zitouni
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include        <stdlib.h>
#include        <stdio.h>
#include        <unistd.h>
#include	"../parsing/write.h"
#include        "../struct.h"
#include	"../parsing/liste_env.h"
#include	"exec.h"
#include	"../parsing/my_str_to_wordtab.h"
#include        "../builtins/my_builtins.h"

char		**add_slash(char **str, char **tab)
{
  char		**new_str;
  int		i;

  i = 0;
  if ((new_str = malloc(sizeof(char *) * (size_t)(my_tab_len(str)))) == NULL)
    exit(1);
  while (str[i] != NULL)
    {
      new_str[i] = my_strcat(my_strcat(str[i], "/"), tab[0]);
      i = i + 1;
    }
  return (new_str);
}

void		display_tab(char **tab)
{
  int		i;
  
  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}

int		my_execve(char *str, char **commande, char **env)
{
  pid_t		pid;

  if ((pid = fork()) == -1)
    {
      my_putstr("Error FORK()\n");
      return (-1);
    }
  else if (pid == 0 && execve(str, commande, env) == -1)
    exit(EXIT_FAILURE);
  if (wait(&pid) == -1)
    my_putstr("Error wait\n");
    return (pid);
}

int		my_access(char **commande, char **path, char **env)
{
  int		i;
  int		n;
  int		cpt;

  i = 0;
  cpt = 0;
  while (path[i] != NULL)
    {
      if (access(path[i], X_OK ) == 0 && access(path[i], F_OK) == 0)
	my_execve(path[i], commande, env);
      else
	cpt++;
      i++;
    }
  if (cpt == i)
    {
      n = 0;
      while (commande[n] != NULL)
	{
	  my_putstr(commande[n]);
	  my_putstr(": commande not found\n");
	  n++;
	}
    }
  return (0);
}

int		full_path(t_liste *liste, t_liste *commande, char **input, char **env)
{
  char		*file;
  char		*path;
  char		**tab_path;
  t_element	*tmp;
  int		i;
  
  i =  0;
  tmp = commande->first;
  if ((found_path(liste)) == NULL)
    return (-1);
  path = found_path(liste);
  while (tmp != NULL)
    {
      if (check_right(tmp, path, tab_path, env) == 0)
	return (0);
      tab_path = my_str_to_wordtab3(path);
      my_access(tmp->tab, add_slash(tab_path, tmp->tab), env);
      tmp = tmp->next;
    }
  return (0);
}

int		check_right(t_element *tmp, char *path, char **tab_path, char **env)
{
  int		i;
  char		*file;
  
  i = 0;
  while (tmp->tab[i] != NULL)
    {
      if (my_strcmp(tmp->tab[i], ">") == 0)
	{
	  file = my_strdup(tmp->tab[i + 1]);
	  tab_path = my_str_to_wordtab3(path);
	  redir_parsing(tmp, file, tab_path, env);
	  return (0);
	}
      else if (my_strncmp(tmp->tab[i], ">>", 2) == 0)
	{
	  file = my_strdup(tmp->tab[i + 1]);
	  tab_path = my_str_to_wordtab3(path);
	  redir_do_parsing(tmp, file, tab_path, env);
	  return (0);
	}
      i++;
    }
  return (-1);
}
