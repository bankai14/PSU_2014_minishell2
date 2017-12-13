/*
** my_str_to_wordtab_2.c for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sun May  3 17:01:22 2015 Yassine Zitouni
** Last update Tue May 19 14:50:17 2015 Yassine Zitouni
*/

#include		<stdlib.h>
#include		"../struct.h"
#include		"write.h"
#include		"my_str_to_wordtab.h"

int                     my_count_word2(char *str)
{
  int                   i;
  int                   compteur;

  compteur = 1;
  i = 0;
  if (str[0] == ' ' || str[0] == '\t')
    {
      while (str[i] == ' ' || str[i] == '\t')
	i = i + 1;
    }
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
        {
          while (str[i] == ' ' || str[i] == '\t')
            i = i + 1;
          compteur = compteur + 1;
        }
      i = i + 1;
    }
  return (compteur);
}

int                     my_count_char2(char *s, int *i)
{
  int                   cpt;

  cpt = 0;
  while (s[*i] != '\0' && s[*i] != ' ' && s[*i] != '\t')
    {
      cpt = cpt + 1;
      *i = *i + 1;
    }
  return (cpt);
}

char                    **my_str_to_wordtab2(char *str)
{
  int                   i;
  int                   word;
  char                  **tab;
  int                   n;
  int                   cpt;

  n = 0;
  i = 0;
  word = my_count_word2(str);
  cpt = word;
  if ((tab = malloc(sizeof(char *) * (size_t)(1 + word))) == NULL)
    my_putstr("Error malloc\n");
  while (str[i] != '\0' && word > 0)
    {
      if (str[i] != ' ' && str[i] != '\t')
        {
          tab[n] = my_strdup(str + i);
          tab[n][my_count_char2(str, &i)] = '\0';
          n = n + 1;
          word = word - 1;
        }
      if (str[i] != '\0')
	i = i + 1;
    }
  tab[cpt] = NULL;
  return (tab);
}
