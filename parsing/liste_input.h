/*
** liste_input.h for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sat May  9 18:53:43 2015 Yassine Zitouni
** Last update Sat May  9 19:02:21 2015 Yassine Zitouni
*/

#ifndef		LISTE_INPUT_H_
# define	LISTE_INPUT_H_

int             liste_in_commande(t_liste *liste, char **tab);
int             empty_liste_input(t_liste *liste, char **tab);
int             add_in_liste_input(t_liste *liste, char **tab);
int             my_show_liste_input(t_liste *liste);

#endif		/*LISTE_INPUT_H_**/

