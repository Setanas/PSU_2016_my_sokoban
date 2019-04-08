/*
** flag_h.c for flag_h.c in /home/TAN_S/PSU_2016_my_sokoban/source
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Tue Dec 20 13:35:02 2016 Sébastien TAN
** Last update Tue Dec 20 13:48:15 2016 Sébastien TAN
*/

#include "my.h"

int	flag_h()
{
  my_putstr("USAGE\n\t   ./my_sokoban map\n\n");
  my_putstr("DESCRIPTION\n\t   map\tfile representing the warehouse map,");
  my_putstr(" containing '#' for walls,\n");
  my_putstr("\t\t'P' for the player, 'X' for boxes and 'O' for storage");
  my_putstr(" locations.\n");
  return (0);
}
