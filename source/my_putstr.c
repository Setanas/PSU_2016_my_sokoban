/*
** my_putstr.c for my_putstr.c in /home/TAN_S/CPool_workshoplib/lib/my
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Fri Oct 21 16:06:35 2016 Sébastien TAN
** Last update Fri Nov 11 12:12:41 2016 Sébastien TAN
*/

#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
