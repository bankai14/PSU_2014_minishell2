/*
** exec.h for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sat May  9 19:00:44 2015 Yassine Zitouni
** Last update Mon May 18 14:06:59 2015 Yassine Zitouni
*/

#ifndef		EXEC_H_
# define	EXEC_H_

char            **add_slash(char **str, char **tab);
int             my_execve(char *str, char **commande, char **env);
int		 my_access(char **commande, char **path, char **env);
int		full_path(t_liste *liste, t_liste *commande, char **input, char **env);
int             check(t_element *tmp, char *path, char **tab_path, char **env);
int             check_right(t_element *tmp, char *path, char **tab_path, char **env);

#endif		/*EXEC_H_*/
