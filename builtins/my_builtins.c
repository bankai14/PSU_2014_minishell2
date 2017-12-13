/*
** my_builtins.c for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Mon May  4 16:36:19 2015 Yassine Zitouni
** Last update Tue May 19 14:51:57 2015 Yassine Zitouni
*/

#include	<sys/wait.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"../struct.h"
#include	"../parsing/write.h"
#include	"my_builtins.h"
#include	"../parsing/liste_env.h"
#include	"unsetenv.h"
#include	"cd.h"
#include	"../process/exec.h"
#include	"../parsing/my_str_to_wordtab.h"

/*int		tablen_redir(char **str)
{
  int		i;

  i = 0;
  while (str[i] != NULL)
    i++;
  return (i);
}

char		*redir_parsing(t_element *tmp, char *file, char **tab_path, char **env)
{
  int		fd;
  int		i;
  char		**exec;

  exec = malloc(sizeof(char *) * tablen_redir(tmp->tab));
  i = 0;
  while (tmp->tab[i] != NULL && my_strcmp(tmp->tab[i], ">") != 0)
    {
      exec[i] = my_strdup(tmp->tab[i]);
      i++;
    }
  if ((fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, \
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    my_putstr("Error open\n");
    my_access_redire(exec, add_slash(tab_path, exec), env, fd);
    return (0);
}

int             my_access_redire(char **commande, char **path, char **env, int fd)
{
  int           i;
  int           n;
  int           cpt;

  i = 0;
  cpt = 0;
  while (path[i] != NULL)
    {
      if (access(path[i], X_OK ) == 0 && access(path[i], F_OK) == 0)
	my_execve_redire(path[i], commande, env, fd);
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

int             my_execve_redire(char *str, char **commande, char **env, int fd)
{
  pid_t         pid;

  if ((pid = fork()) == -1)
    {
      my_putstr("Error FORK()\n");
      return (-1);
    }
  else if (pid == 0)
    {
      dup2(fd, 1);
      if (execve(str, commande, env) == -1)
	my_putstr("Error\n");
    }
  if (wait(&pid) == -1)
    my_putstr("Error wait\n");
  return (pid);
}*/


int             my_builtins(char *input, t_liste *envi, char **tab)
{
  char          *env_name;
  char          *new_word;
  char		*delete;

  if (my_strcmp("env\0", input) == 0)
    {
      my_show_liste_env(envi);
      return (0);
    }
  else if (tab[1] == '\0' && my_strcmp("cd", tab[0]) == 0)
    {
      use_cd(envi, tab);
      return (0);
    }
  else if (tab[1] != '\0' && my_strcmp("cd", tab[0]) == 0)
    {
      if (my_strcmp("..", tab[1]) == 0)
	cd_point(envi);
      else if (my_strcmp("-", tab[1]) == 0)
	{
	  cd_tire(envi);
	}
      else
	chdir(tab[1]);
      return (0);
    }
  else if (my_strncmp("unsetenv", input, my_strlen("unsetenv")) == 0)
    {
      delete = input + 9;
      my_putstr(delete);
      my_putchar('\n');
      my_unsetenv(envi, delete);
      return (0);
    }
  else if (my_strncmp("setenv", tab[0], my_tab_len(tab)) == 0)
    {
      my_setenv(envi, tab);
      return (1);
    }
  return (-1);
}
