/*
** free_fonction.c for free_fonction.c in /home/TAN_S/PSU_2016_my_sokoban/source
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Tue Dec 20 14:54:43 2016 Sébastien TAN
** Last update Tue Dec 20 15:01:51 2016 Sébastien TAN
*/

#include <stdlib.h>

void	free_fonction(char **stock, int size)
{
  int	incre;

  while (incre < size)
    {
      free(stock[incre]);
      incre = incre + 1;
    }
  free(stock);
}
