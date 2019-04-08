/*
** fonc_left.c for fonc_left.c in /home/TAN_S/PSU_2016_my_sokoban/test/test3
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Sun Dec 11 02:16:11 2016 Sébastien TAN
** Last update Sat Dec 17 17:54:04 2016 Sébastien TAN
*/
#include <ncurses/curses.h>
#include "my.h"

int            fonc_left(char **stock, int size,
			 char *av1, t_position *position)
{
  int		x;
  int		y;
  int		i;
  int           incre;
  t_arrow       left[4];

  incre = 0;
  i = 0;
  y = position_y(stock, size);
  x = position_x(stock, y);
  array_left(left);
  av1 = av1;
  while (left[incre].position_1 != stock[y][x - 1] && incre < 4)
    incre = incre + 1;
  if (incre <= 3)
    i = left[incre].fptr_arrow(stock, size, y, position);
  return (i);
}

void        array_left(t_arrow *left_key)
{
  left_key[0].position_1 = ' ';
  left_key[0].fptr_arrow = &left;
  left_key[1].position_1 = '#';
  left_key[1].fptr_arrow = &no_change;
  left_key[2].position_1 = 'X';
  left_key[2].fptr_arrow = &left_x;
  left_key[3].position_1 = 'O';
  left_key[3].fptr_arrow = &left;
}

int            left(char **stock, int size, int y, t_position *position)
{
  int		x;
  int		incre;

  incre = 0;
  x = position_x(stock, y);
  stock[y][x - 1] = 'P';
  stock[y][x] = ' ';
  while (incre < size)
    {
      if (position[incre].y == y && position[incre].x == x)
	stock[y][x] = 'O';
      incre = incre + 1;
    }
  return (0);
}

int            left_x(char **stock, int size, int y, t_position *position)
{
  int		i;
  int		x;
  int		incre;

  i = 0;
  incre = 0;
  x = position_x(stock, y);
  if (stock[y][x - 2] != '#' && stock[y][x - 2] != 'X')
    {
      stock[y][x - 1] = 'P';
      stock[y][x - 2] = 'X';
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
