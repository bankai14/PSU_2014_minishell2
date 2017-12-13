/*
** struct.h for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Fri May  1 16:35:40 2015 Yassine Zitouni
** Last update Tue May 19 14:33:21 2015 Yassine Zitouni
*/

#ifndef			STRUCT_H_
# define		STRUCT_H_

typedef struct		s_element
{
  char			*str;
  char			**pathline;
  char			**tab;
  char			*env;
  struct s_element	*next;
  struct s_element	*prev;
}			t_element;

typedef struct		s_liste
{
  int		count;
  struct s_element	*first;
  struct s_element	*last;
  struct s_element	*path;
  struct s_element	*home;
  struct s_element	*my_delete;
  
}			t_liste;


#endif			/*STRUCT_H_*/
