/*
** fonc_reset.c for fonc_reset.c in /home/TAN_S/PSU_2016_my_sokoban/test/test7
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Mon Dec 12 15:28:11 2016 Sébastien TAN
** Last update Tue Dec 20 19:35:09 2016 Sébastien TAN
*/

#include <ncurses/curses.h>
#include <stdlib.h>
#include "my.h"

int	fonc_reset(char **stock, int size, char *av1, t_position *position)
{
  char	**restart;

  position = position;
  restart = put_in_stock(av1);
  stock = my_arraycpy_sokoban(stock, restart);
  free_fonction(restart, size);
  size = 0;
  return (size);
}

char	**my_arraycpy_sokoban(char **dest, char **src)
{
  int	incre;
  
  incre = 0;
  while (src[incre] != NULL)
    {
      dest[incre] = src[incre];
      incre = incre + 1;
    }
  return (dest);
}
