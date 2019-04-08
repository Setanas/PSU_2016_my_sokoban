/*
** main.c for main.c in /home/TAN_S/PSU_2016_my_sokoban/test
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Thu Dec  8 13:36:44 2016 Sébastien TAN
** Last update Tue Dec 20 19:29:20 2016 Sébastien TAN
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include <unistd.h>
#include "my.h"


int		main(int ac, char **av)
{
  WINDOW	*vin;
  int		i;

  if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
    return (flag_h());
  if (ac != 2)
    return (84);
  if (bad_open(av[1]) == 84)
    {
      write(2, "Bad map\n", 8);
      return (84);
    }
  i = 0;
  initscr();
  noecho();
  curs_set(0);
  vin = newwin(LINES, COLS, 0, 0);
  keypad(vin, TRUE);
  i = while_main(av[1], vin);
  endwin();
  if (i == 84)
    write(2, "Bad map\n", 8);
  return (i);
}

char		**put_in_stock(char *av)

{
  char		**stock;
  FILE		*stream;
  char		*line;
  size_t	len;
  ssize_t	read;
  int		size;

  size = 0;
  line = NULL;
  len = 0;
  stream = fopen(av, "r");
  if (stream == NULL)
    exit(EXIT_FAILURE);
  while ((read = getline(&line, &len, stream)) != -1)
    size = size + 1;
  fclose(stream);
  stock = malloc(sizeof(char *) * size);
  stock = real_stock(av, stock);
  return (stock);
}

char		**real_stock(char *av, char **stock)
{
  FILE		*stream;
  char		*line;
  size_t	len;
  ssize_t	value;
  int		incre;
  
  line = NULL;
  len = 0;
  incre = 0;
  stream = fopen(av, "r");
  while ((value = getline(&line, &len, stream)) != -1)
    {
      stock[incre] = line;
      incre = incre + 1;
      line = NULL;
    }
  incre = incre -1;
  fclose(stream);
  return (stock);
}

int		size_for_incre(char *av)
{
  int		size;
  FILE		*stream;
  char		*line;
  size_t	len;
  ssize_t	read;

  line = NULL;
  len = 0;
  stream = fopen(av, "r");
  size = 0;
  while ((read = getline(&line, &len, stream)) != -1)
    size = size + 1;
  return (size);
}

void		put_map(char **stock, int size, WINDOW *vin)
{
  int		i;

  i = 0;
  while (i < size)
    {
      wprintw(vin, stock[i]);
      i = i + 1;
    }
  wrefresh(vin);
}
