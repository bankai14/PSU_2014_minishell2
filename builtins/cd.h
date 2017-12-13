/*
** cd.h for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sun May 10 18:36:32 2015 Yassine Zitouni
** Last update Fri May 15 16:37:11 2015 Yassine Zitouni
*/

#ifndef		CD_H_
# define	CD_H_

void            use_cd(t_liste *liste, char **tab);
char            *found_home(t_liste *liste);
void            cd_point(t_liste *liste);
void            cd_tire(t_liste *liste);

#endif		/*CD_H_*/
