/*
** my_str_to_wordtab.c for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sun May  3 17:01:35 2015 Yassine Zitouni
** Last update Tue May 19 14:58:35 2015 Yassine Zitouni
*/

#include		<stdlib.h>
#include		"../struct.h"
#include		"write.h"
#include		"my_str_to_wordtab.h"

char                    *my_strdup(char *str)
{
  char                  *dest;

  if ((dest = (char *)malloc(sizeof(char) * (size_t)my_strlen(str) + 1)) == NULL)
    my_putstr("Error malloc\n");
  dest = my_strcpy(dest, str);
  dest[my_strlen(str)] = 0;
  return (dest);
}

int                     my_count_word(char *str)
{
  int                   i;
  int                   compteur;

  compteur = 1;
  i = 0;
  while (str[i])
    {
      if (str[i] == ';')
        {
          while (str[i] == ';')
            i = i + 1;
          compteur = compteur + 1;
        }
      i = i + 1;
    }
  return (compteur);
}

int                     my_count_char(char *s, int *i)
{
  int                   cpt;

  cpt = 0;
  while (s[*i] != '\0' && s[*i] != ';')
    {
      cpt = cpt + 1;
      *i = *i + 1;
    }
  return (cpt);
}

char                    **my_str_to_wordtab(char *str)
{
  int                   i;
  int                   word;
  char                  **tab;
  int                   n;
  int                   cpt;

  n = 0;
  i = 0;
  word = my_count_word(str);
  cpt = word;
  if ((tab = malloc(sizeof(char *) * (size_t)(1 + word))) == NULL)
    my_putstr("Error malloc\n");
  if (str[0] == ';')
    exit(1);
  while (str[i] != '\0' && word > 0)
    {
      if (str[i] != ';')
        {
          tab[n] = my_strdup(str + i);
          tab[n][my_count_char(str, &i)] = '\0';
          n = n + 1;
          word = word - 1;
        }
      if (str[i] != '\0')
	i = i + 1;
    }
  tab[cpt] = NULL;
  return (tab);
}
