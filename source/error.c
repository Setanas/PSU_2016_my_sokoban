/*
** error.c for error.c in /home/TAN_S/PSU_2016_my_sokoban/test/test6
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Mon Dec 12 11:59:18 2016 Sébastien TAN
** Last update Tue Dec 20 14:06:46 2016 Sébastien TAN
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int	error_condition(char **stock,int nbr_o, int size)
{
  int error;

  error = 0;
  error = nbr_X(stock, nbr_o, size);
  if (error != 84)
    error = player(stock, size);
  return (error);
}

int	nbr_X(char **stock, int nbr_o, int size)
{
  int	incre_x;
  int	incre_y;
  int	nbr_of_X;

  incre_x = 0;
  incre_y = 0;
  nbr_of_X = 0;
  while (incre_y < size)
    {
      while (stock[incre_y][incre_x] != '\0')
	{
	  if (stock[incre_y][incre_x] == 'X')
	    nbr_of_X = nbr_of_X + 1;
	  incre_x = incre_x + 1;
	}
      incre_x = 0;
      incre_y = incre_y + 1;
    }
  if (nbr_of_X != nbr_o)
    return (84);
  return (0);
}

int	player(char **stock, int size)
{
  int	nbr_of_P;
  int	x;
  int	y;

  x = 0;
  y = 0;
  nbr_of_P = 0;
  while (y < size)
    {
      while (stock[y][x] != '\0')
	{
	  if (stock[y][x] == 'P')
	    nbr_of_P = nbr_of_P + 1;
	  x = x + 1;
	}
      x = 0;
      y = y + 1;
    }
  if (nbr_of_P != 1)
    return (84);
  return (0);
}

int	bad_open(char *av)
{
  int	fd;

  fd = open(av, O_RDONLY);
  if (fd == -1)
    return (84);
  return (0);
}
