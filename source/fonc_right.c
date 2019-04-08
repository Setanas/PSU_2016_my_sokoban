/*
** fonc_right.c for fonc_right.c in /home/TAN_S/PSU_2016_my_sokoban/test/test3
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Sun Dec 11 02:07:35 2016 Sébastien TAN
** Last update Sat Dec 17 17:56:16 2016 Sébastien TAN
*/

#include <ncurses/curses.h>
#include "my.h"

int            fonc_right(char **stock, int size,
			  char *av1, t_position *position)
{
  int           x;
  int		y;
  int		i;
  int           incre;
  t_arrow       right[4];

  incre = 0;
  i = 0;
  y = position_y(stock, size);
  x = position_x(stock, y);
  array_right(right);
  av1 = av1;
  while (right[incre].position_1 != stock[y][x+1] && incre < 4)
    incre = incre + 1;
  if (incre <= 3)
    i = right[incre].fptr_arrow(stock, size, y, position);
  return (i);
}

void         array_right(t_arrow *right_key)
{
  right_key[0].position_1 = ' ';
  right_key[0].fptr_arrow = &right;
  right_key[1].position_1 = '#';
  right_key[1].fptr_arrow = &no_change;
  right_key[2].position_1 = 'X';
  right_key[2].fptr_arrow = &right_x;
  right_key[3].position_1 = 'O';
  right_key[3].fptr_arrow = &right;
}

int            right(char **stock, int size, int y, t_position *position)
{
  int		x;
  int		incre;

  incre = 0;
  x = position_x(stock, y);
  stock[y][x + 1] = 'P';
  stock[y][x] = ' ';
  while (incre < size)
    {
      if (position[incre].y == y && position[incre].x == x)
	stock[y][x] = 'O';
      incre = incre + 1;
    }
  return (0);
}

int		right_x(char **stock, int size, int y, t_position *position)
{
  int		i;
  int		x;
  int		incre;

  i = 0;
  incre = 0;
  x = position_x(stock, y);
  if (stock[y][x + 2] != '#' && stock[y][x + 2] != 'X')
    {
      stock[y][x + 1] = 'P';
      stock[y][x + 2] = 'X';
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
