/*
** unsetenv.h for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sun May 10 18:52:10 2015 Yassine Zitouni
** Last update Mon May 18 14:05:09 2015 Yassine Zitouni
*/

#ifndef		UNSETENV_H_
# define	UNSETENV_H_

int             my_setenv2(t_liste *liste, char **tab, char *env_word);
int             my_setenv(t_liste *liste, char **tab);
int             first_element(t_liste *liste);
int             my_unsetenv(t_liste *liste, char *delete);

#endif		/*UNSETENV_H_*/
