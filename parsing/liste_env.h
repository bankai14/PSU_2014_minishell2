/*
** liste_env.h for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sat May  9 18:51:30 2015 Yassine Zitouni
** Last update Sat May  9 18:53:03 2015 Yassine Zitouni
*/

#ifndef		LISTE_ENV_H_
# define	LISTE_ENV_H_

int             liste_in_env(t_liste *liste, char **tab);
int             empty_liste_env(t_liste *liste, char *str);
int             add_in_liste_env(t_liste *liste, char *str);
int             my_show_liste_env(t_liste *liste);
char            *found_path(t_liste *liste);

#endif		/*LISTE_ENV_H_*/
