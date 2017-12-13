/*
** my_builtins.h for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sat May  9 18:55:35 2015 Yassine Zitouni
** Last update Sun May 17 20:24:58 2015 Yassine Zitouni
*/

#ifndef		MY_BUILTINS_H_
# define	MY_BUILTINS_H_

int             tablen_redir(char **str);
int             my_builtins(char *input, t_liste *envi, char **tab);
char            *redir_parsing(t_element *tmp, char *file, char **tab_path, char **env);
int             my_access_redire(char **commande, char **path, char **env, int fd);
int             my_execve_redire(char *str, char **commande, char **env, int fd);
char            *redir_do_parsing(t_element *tmp, char *file, char **tab_path, char **env);

#endif		/*MY_BUILTINS*/
