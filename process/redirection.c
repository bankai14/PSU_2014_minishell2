/*
** redirection.c for  in /home/zitouni/rendu/PSU_2014_minishell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sun May 17 13:01:13 2015 Yassine Zitouni
** Last update Tue May 19 14:56:07 2015 Yassine Zitouni
*/

#include        <sys/wait.h>
#include        <sys/types.h>
#include        <sys/stat.h>
#include        <fcntl.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include        "../struct.h"
#include        "../parsing/write.h"
#include        "../builtins/my_builtins.h"
#include        "../parsing/liste_env.h"
#include        "../builtins/unsetenv.h"
#include        "../builtins/cd.h"
#include        "exec.h"
#include        "../parsing/my_str_to_wordtab.h"

int             tablen_redir(char **str)
{
  int           i;

  i = 0;
  while (str[i] != NULL)
    i++;
  return (i);
}

char            *redir_do_parsing(t_element *tmp, char *file, char **tab_path, char **env)
{
  int           fd;
  int           i;
  char          **exec;

  exec = malloc(sizeof(char *) * tablen_redir(tmp->tab));
  i = 0;
  while (tmp->tab[i] != NULL && my_strcmp(tmp->tab[i], ">>") != 0)
    {
      exec[i] = my_strdup(tmp->tab[i]);
      i++;
    }
  if ((fd = open(file, O_CREAT | O_WRONLY | O_APPEND, \
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    my_putstr("Error with open\n");
  my_access_redire(exec, add_slash(tab_path, exec), env, fd);
  return (0);
}

char            *redir_parsing(t_element *tmp, char *file, char **tab_path, char **env)
{
  int           fd;
  int           i;
  char          **exec;

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
}
