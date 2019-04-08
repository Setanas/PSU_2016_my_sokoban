/*
** arrow.c for arrow.c in /home/TAN_S/PSU_2016_my_sokoban/test/test3
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Sat Dec 10 23:05:53 2016 Sébastien TAN
** Last update Sat Dec 17 14:20:15 2016 Sébastien TAN
*/

#include <ncurses/curses.h>
#include "my.h"

int            fonc_up(char **stock, int size, char *av1, t_position *position)
{
  int		x;
  int		y;
  int		i;
  int		incre;
  t_arrow	up[4];
  
  incre = 0;
  i = 0;
  y = position_y(stock, size);
  x = position_x(stock, y);
  array_up(up);
  av1 = av1;
  while (up[incre].position_1 != stock[y - 1][x] && incre < 4)
    incre = incre + 1;
  if (incre <= 3)
    i = up[incre].fptr_arrow(stock, size, y, position);
  return (i);
}

void		array_up(t_arrow *up_key)
{
  up_key[0].position_1 = ' ';
  up_key[0].fptr_arrow = &up;
  up_key[1].position_1 = '#';
  up_key[1].fptr_arrow = &no_change;
  up_key[2].position_1 = 'X';
  up_key[2].fptr_arrow = &up_x;
  up_key[3].position_1 = 'O';
  up_key[3].fptr_arrow = &up;
}

int		up(char **stock, int size, int y, t_position *position)
{
  int		x;
  int		incre;

  incre = 0;
  x = position_x(stock, y);
  stock[y - 1][x] = 'P';
  stock[y][x] = ' ';
  while (incre < size)
    {
      if (position[incre].y == y && position[incre].x == x)
	stock[y][x] = 'O';
      incre = incre + 1;
    }
  return (0);
}

int		no_change(char **stock, int size, int y, t_position *position)
{
  int		x;

  size = 0;
  x = position_x(stock, y);
  stock[y][x] = 'P';
  position = position;
  return (size);
}

int		up_x(char **stock, int size, int y, t_position *position)
{
  int		i;
  int		x;
  int		incre;

  i = 0;
  incre = 0;
  x = position_x(stock, y);
  if (stock[y - 2][x] != '#' && stock[y - 2][x] != 'X')
    {
      stock[y - 1][x] = 'P';
      stock[y - 2][x] = 'X';
      stock[y][x] = ' ';
    }
  while (incre < size)
    {
      if (position[incre].y == y && position[incre].x == x)
	stock[y][x] = 'O';
      incre = incre + 1;
    }
  return (i);
}
