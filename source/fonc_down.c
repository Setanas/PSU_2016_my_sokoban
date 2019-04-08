/*
** fonc_down.c for fonc_down.c in /home/TAN_S/PSU_2016_my_sokoban/test/test3
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Sun Dec 11 01:41:21 2016 Sébastien TAN
** Last update Sat Dec 17 17:47:50 2016 Sébastien TAN
*/

#include <ncurses/curses.h>
#include "my.h"

int            fonc_down(char **stock, int size, char *av1,
			 t_position *position)
{
  int		x;
  int		y;
  int		i;
  int           incre;
  t_arrow       down[4];

  incre = 0;
  i = 0;
  y = position_y(stock, size);
  x = position_x(stock, y);
  array_down(down);
  av1 = av1;
  while (down[incre].position_1 != stock[y + 1][x] && incre < 4)
    incre = incre + 1;
  if (incre <= 3)
    i = down[incre].fptr_arrow(stock, size, y, position);
  return (i);
}

void         array_down(t_arrow *down_key)
{
  down_key[0].position_1 = ' ';
  down_key[0].fptr_arrow = &down;
  down_key[1].position_1 = '#';
  down_key[1].fptr_arrow = &no_change;
  down_key[2].position_1 = 'X';
  down_key[2].fptr_arrow = &down_x;
  down_key[3].position_1 = 'O';
  down_key[3].fptr_arrow = &down;
}

int            down(char **stock, int size, int y, t_position *position)
{
  int		x;
  int		incre;

  incre = 0;
  x = position_x(stock, y);
  stock[y + 1][x] = 'P';
  stock[y][x] = ' ';
  while (incre < size)
    {
      if (position[incre].y == y && position[incre].x == x)
	stock[y][x] = 'O';
      incre = incre + 1;
    }
  return (0);
}

int            down_x(char **stock, int size, int y, t_position *position)
{
  int		i;
  int		x;
  int		incre;
  
  i = 0;
  x = position_x(stock, y);
  incre = 0;
  if (stock[y + 2][x] != '#' && stock[y + 2][x] != 'X')
    {
      stock[y + 1][x] = 'P';
      stock[y + 2][x] = 'X';
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
