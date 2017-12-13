/*
** write2.c for  in /home/zitouni/rendu/PSU_2014_minishell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sun May 10 23:58:56 2015 Yassine Zitouni
** Last update Mon May 18 17:09:32 2015 Yassine Zitouni
*/
#include        <stdio.h>
#include        <stdlib.h>
#include	<unistd.h>
#include	"write.h"

int             my_strncmp(char *str1, char *str2, int nb)
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
      my_putchar('\n');
      i++;
    }
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

int             my_tab_len(char **str)
{
  int           i;

  i = 0;
  while (str[i] != NULL)
    i++;
  return (i);
}

char            *my_strcat(char *dest, char *src)
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

char		*clean_space(char *str)
{
  char		*dest;
  int		i;
  int		j;

  i = 0;
  j = 0;
  dest = malloc(sizeof(char) * (my_strlen(str) + 1));
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[i] == ' ' || str[i] == '\t')
	    i = i + 1;
	  if (j != 0)
	    {
	      dest[j] = ' ';
	      j = j + 1;
	    }
	}
      dest[j] = str[i];
      j = j + 1;
      i = i + 1;
    }
  dest[j] = '\0';
  return (dest);
}
