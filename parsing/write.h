/*
** write.h for  in /home/zitouni/rendu/shell2
** 
** Made by Yassine Zitouni
** Login   <zitoun_y@epitech.net>
** 
** Started on  Sat May  9 18:42:36 2015 Yassine Zitouni
** Last update Sun May 10 20:06:04 2015 Yassine Zitouni
*/

#ifndef		WRITE_H_
# define	WRITE_H_

int             my_putchar(char c);
void            my_putstr(char *str);
int             my_strlen(char *str);
char            *my_strcpy(char *dest, char *src);
int             my_strcmp(char *str1, char *str2);
int             my_strncmp(char *str1, char *str2, int nb);
//int             tab_len(char **str);
char            *my_strcat(char *dest, char *src);
int             my_tab_len(char **str);
void            my_put_tab(char **tab);
char            *epur_str(char *str);
char            *concat(char* dst, const char* srcs[]);
char            *my_strcat2(char* dst, const char* src);
char            *my_strcpy2(char* dst, const char* src);
int             my_strncmp2(const char *str1, const char *str2, int nb);
int             my_strlen2(const char *str);
#endif		/*WRITE_H_*/
