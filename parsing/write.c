/*
** write.c for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Fri May  1 17:03:16 2015 Yassine Zitouni
** Last update Sat May 16 16:47:15 2015 Yassine Zitouni
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"write.h"

int		my_putchar(char c)
{
  return (write(1, &c, 1) != -1 ? 0 : -1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void            my_putnbr(int nb)
{
  if (nb / 10 > 0)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + 48);
}

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int             my_strcmp(char *str1, char *str2)
{
  int           i;

  i =  0;
  if (my_strlen(str1) != my_strlen(str2))
    return (1);
  while (str1[i])
    {
      if (str1[i] != str2[i])
        return (1);
      i++;
    }
  return(0);
}

/*int             my_strncmp(char *str1, char *str2, int nb)
{
  int           i;

  i = 0;
  if (my_strlen(str1) < nb || my_strlen(str2) < nb)
    return (1);
  while (i < nb)
    {
      if (str1[i] != str2[i])
        return (1);
      i = i + 1;
    }
  return (0);
}

void            my_put_tab(char **tab)
{
  int           i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      i++;
    }
  my_putchar('\n');
}

char            *epur_str(char *str)
{
  char  *dest;
  int   i;
  int   j;

  dest = malloc(sizeof(char) * (size_t)(my_strlen(str) + 1));
  i = 0;
  j = 0;
  while (str[i] == ' ' || (str[i] == '\t' && str[i] != '\0'))
    i++;
  while (str[i] != '\0')
    {
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
        {
          dest[j++] = str[i];
          i++;
        }
      while (str[i] == ' ' && str[i] != '\t' && str[i] != '\0')
        i++;
      if (str[i] != '\0')
        dest[j++] = ' ';
    }
  dest[j] = '\0';
  return (dest);
}

int		my_tab_len(char **str)
{
  int		i;

  i = 0;
  while (str[i] != NULL)
    i++;
  return (i);
}

char		*my_strcat(char *dest, char *src)
{
  int   i;
  int   j;

  j = 0;
  i = my_strlen(dest);
  while (src[j])
    dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}
*/
