/*
** get_next_line.c for  in /home/zitouni/rendu/PSU_2014_minishell1
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Mon Jan 26 16:13:49 2015 Yassine Zitouni
** Last update Sat May  9 18:46:46 2015 Yassine Zitouni
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"write.h"
#include	"get_next_line.h"
#include	<sys/stat.h> 
#include	<fcntl.h>

static t_list	*add_in_list(t_list *list, char c)
{
  t_list	*new_element;
  t_list	*tmp;

  new_element = malloc(sizeof(t_list));
  new_element->c = c;
  new_element->next = NULL;
  if (list == NULL)
    return (new_element);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_element;
  return (list);
}

static int	check_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->c == '\n' || tmp->c == '\0')
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

static int	str_size(t_list *list)
{
  t_list	*tmp;
  int		i;

  tmp = list;
  i = 0;
  while (tmp != NULL)
    {
      if (tmp->c == '\n' || tmp->c == '\0')
	return (i);
      tmp = tmp->next;
      i++;
    }
  return (i);
}

static char	*list_to_str(t_list **list)
{
  t_list	*ptr;
  char		*str;
  int		i;

  i = 0;
  if ((*list) == NULL)
    return (NULL);
  str = malloc(sizeof(char) * (size_t)(str_size(*list) + 1));
  while ((*list) != NULL && (*list)->c != '\n' && (*list)->c != '\0')
    {
      ptr = (*list);
      str[i++] = (*list)->c;
      (*list) = (*list)->next;
      free(ptr);
    }
  str[i] = '\0';
  if ((*list) != NULL)
    {
      ptr = (*list);
      (*list) = (*list)->next;
      free(ptr);
    }
  return (str);
}

extern char	*get_next_line(const int fd)
{
  static t_list	*list;
  char		buffer[BUFF_SIZE];
  int		val;
  int		i;

  i = 0;
  while (i < BUFF_SIZE)
    buffer[i++] = 0;
  if ((val = read(fd, buffer, BUFF_SIZE)) < 0)
    return (NULL);
  if (val == 0)
    return (list_to_str(&list));
  i = 0;
  while (i < val)
    list = add_in_list(list, buffer[i++]);
  if (check_list(list))
    return (list_to_str(&list));
  return (get_next_line(fd));
}
