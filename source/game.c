/*
** game.c for game.c in /home/TAN_S/PSU_2016_my_sokoban/test/test3
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Fri Dec  9 00:39:09 2016 Sébastien TAN
** Last update Tue Dec 20 19:22:13 2016 Sébastien TAN
*/

#include <ncurses/curses.h>
#include "my.h"

int            play_the_game(WINDOW *vin, char **stock,
			     t_position *position, char *av1)
{
  int		i;
  int		size;
  int		ch;
  int		incre;
  t_keypad	key[5];

  incre = 0;
  size = size_for_incre(av1);
  init_funct(key);
  ch = wgetch(vin);
  while (key[incre].key != ch && incre < 5)
    incre = incre + 1;
  if (incre <= 4)
    i = key[incre].fptr_key(stock, size, av1, position);
  i = play_the_game_if(stock, size, i, vin);
  return (i);
}

int		play_the_game_if(char **stock, int size, int i, WINDOW *vin)
{
  if (i == 0)
    {
      wclear(vin);
      put_map(stock, size, vin);
      wrefresh(vin);
      cbreak();
    }
  else if (i == 1)
    endwin();
  return (i);
}
int		position_y(char **stock, int size)
{
  int		x;
  int		y;
  
  x = 0;
  y = 0;
  while (y < size)
    {
      while (stock[y][x] != '\0')
	{
	  if (stock[y][x] == 'P')
	    return (y);
	  x = x + 1;
	}
      x = 0;
      y = y + 1;
    }
  return (-1);
}

int		position_x(char **stock, int y)
{
  int		x;

  x = 0;
  while (stock[y][x] != '\0')
    {
      if (stock[y][x] == 'P')
	return (x);
      x = x + 1;
    }
  return (-1);
}

void		init_funct(t_keypad *key_arrow)
{
  key_arrow[0].key = KEY_UP;
  key_arrow[0].fptr_key = &fonc_up;
  key_arrow[1].key = KEY_DOWN;
  key_arrow[1].fptr_key = &fonc_down;
  key_arrow[2].key = KEY_RIGHT;
  key_arrow[2].fptr_key = &fonc_right;
  key_arrow[3].key = KEY_LEFT;
  key_arrow[3].fptr_key = &fonc_left;
  key_arrow[4].key = ' ';
  key_arrow[4].fptr_key = &fonc_reset;
}
