/*
** annexe1.c for annexe1.c in /home/TAN_S/PSU_2016_my_sokoban/test/test8
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Tue Dec 13 14:00:07 2016 Sébastien TAN
** Last update Tue Dec 20 19:45:56 2016 Sébastien TAN
*/

#include <ncurses/curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int             while_main(char *av1, WINDOW *vin)
{
  char          **stock;
  t_position	*position;
  int           size;
  int           i;
  int           nbr_o;
  int		win;

  stock = put_in_stock(av1);
  size = size_for_incre(av1);
  nbr_o = nbr_O_fonc(stock, size);
  position = position_o(stock, size);
  win = win_condition(stock, position, nbr_o);
  i = 0;
  i = error_condition(stock, nbr_o, size);
  if (i == 84)
    return (i);
  put_map(stock, size, vin);
  play_the_game(vin, stock, position, av1);
  while (win != nbr_o && i != 1)
    {
      i = play_the_game(vin, stock, position, av1);
      win = win_condition(stock, position, nbr_o);
    }
  free_fonction(stock, size);
  return (i);
}

int             nbr_O_fonc(char **stock, int size)
{
  int           y;
  int           x;
  int           nbr_o;

  y = 0;
  x = 0;
  nbr_o = 0;
  while (y < size)
    {
      while (stock[y][x] != '\0')
	{
	  if (stock[y][x] == 'O')
	    nbr_o = nbr_o + 1;
	  x = x + 1;
	}
      x = 0;
      y = y + 1;
    }
  return (nbr_o);
}

t_position	*position_o(char **stock, int size)
{
  int	       	o;
  int		y;
  int		x;
  t_position	*position;

  y = 0;
  x = 0;
  o = 0;
  position = malloc(sizeof(*position) * size + 1);
  while (y < size)
    {
      while (stock[y][x] != '\0')
	{
	  if (stock[y][x] == 'O')
	    {
	      position[o].y = y;
	      position[o].x = x;
	      o = o + 1;
	    }
	  x = x + 1;	    
	}
      x = 0;
      y = y + 1;
    }
  return (position);
}

int		win_condition(char **stock, t_position *position, int nbr_o)
{
  int		incre;
  int		nbr_final;
  int		x;
  int		y;
  
  incre = 0;
  x = 0;
  y = 0;
  nbr_final = 0;
  while (incre < nbr_o)
    {
      x = position[incre].x;
      y = position[incre].y;
      if (stock[y][x] == 'X')
	nbr_final = nbr_final + 1;
      incre = incre + 1;
    }
  return (nbr_final);
}
