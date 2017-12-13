/*
** main.c for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Fri May  1 15:43:43 2015 Yassine Zitouni
** Last update Tue May 19 15:42:23 2015 Yassine Zitouni
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	"parsing/write.h"
#include	"struct.h"
#include        "parsing/get_next_line.h"
#include	"parsing/my_str_to_wordtab.h"
#include	"parsing/liste_env.h"
#include	"parsing/liste_input.h"
#include	"main.h"
#include	"builtins/my_builtins.h"
#include	"process/exec.h"

int		main(int ac, char **av, char **env)
{
  t_liste	*envi;

   (void)av;
   if (env[0] == NULL)
     exit(1);
   if (ac == 1)
     {
       if ((envi = malloc(sizeof(t_liste))) == NULL)
	 my_putstr("Error: envi\n");
       signal(SIGINT, SIG_IGN);
       prompt(envi, env);
     }
  else
    my_putstr("Error arguments\n");
}

int		prompt(t_liste *envi, char **env)
{
  char		**tab;
  char		*input;
  t_liste	*commande;
  t_element	element;

  if ((commande = malloc(sizeof(t_liste))) == NULL)
    my_putstr("Error: commande\n");
  my_putstr("$> ");
  liste_in_env(envi, env);
  while ((input = get_next_line(0)) != NULL && my_strcmp(input, "exit\0") != 0)
    {
      input = clean_space(input);
      if (my_strlen(input) != 0)
	{
	  tab = my_str_to_wordtab(input);
	  tab = my_str_to_wordtab2(input);
	  liste_in_commande(commande, my_str_to_wordtab(input));
	  if (my_builtins(input, envi, tab) == -1)
	    full_path(envi, commande,tab, env);
	  // my_show_liste_input(commande);
	  my_putstr("$> ");
	}
    }
  my_putchar('\n');
  return (0);
}
