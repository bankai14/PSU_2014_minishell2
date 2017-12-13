/*
** get_next_line.h for  in /home/zitouni/rendu/PSU_2014_minishell1
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Mon Jan 26 16:13:41 2015 Yassine Zitouni
** Last update Sat May  9 18:16:31 2015 Yassine Zitouni
*/


#ifndef			GET_NEXT_LINE_H
#define			GET_NEXT_LINE_H

#define			BUFF_SIZE	10

typedef	struct		s_list	t_list;

struct			s_list
{
  char			c;
  t_list		*next;
};

char			*get_next_line(const int);

#endif			/*GET_NEXT_LINE_H*/
