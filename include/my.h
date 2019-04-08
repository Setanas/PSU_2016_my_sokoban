/*
** my.h for main.c in /home/TAN_S/PSU_2016_my_sokoban/test/test3
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Fri Dec  9 00:19:07 2016 Sébastien TAN
** Last update Tue Dec 20 16:09:34 2016 Sébastien TAN
*/

#include <ncurses/curses.h>

#ifndef MY_H_
# define MY_H_

typedef struct		s_position
{
  int			y;
  int			x;
}			t_position;

typedef struct		s_keypad
{
  int			(*fptr_key)(char **stock, int size, char *av1, t_position *position);
  int			key;
}			t_keypad;

typedef struct		s_arrow
{
  int			(*fptr_arrow)(char **stock, int size, int y, t_position *position);
  char			position_1;
}			t_arrow;

void		free_fonction(char **stock, int size);
int		bad_open(char *av);
int		flag_h();
void		my_putstr(char *str);
t_position	*position_o(char **stock, int size);
char		**my_arraycpy_sokoban(char **dest, char **src);
int		fonc_up(char **stock, int size, char *av1, t_position *position);
int		fonc_down(char **stock, int size, char *av1, t_position *position);
int		fonc_right(char **stock, int size, char *av1, t_position *position);
int		fonc_left(char **stock, int size, char *av1, t_position *position);
int		fonc_reset(char **stock, int size, char *av1, t_position *position);
void        init_funct(t_keypad *key_arrow);
char            **put_in_stock(char *av);
char            **real_stock(char *av, char **stock);
void            put_map(char **stock, int size, WINDOW *vin);
int		play_the_game(WINDOW *vin, char **stock, t_position *position, char *av1);
int		size_for_incre(char *av);
int             position_x(char **stock, int y);
int             position_y(char **stock, int size);
void		my_putchar(char c);
int            no_change(char **stock, int size, int y, t_position *position);

int		no_more_move(int y, int x, char **stock);

int            up_x(char **stock, int size, int y, t_position *position);
int            up(char **stock, int size, int y, t_position *position);
void         array_up(t_arrow *up_key);
int            down_x(char **stock, int size, int y, t_position *position);
int            down(char **stock, int size, int y, t_position *position);
void         array_down(t_arrow *down_key);
int            right_x(char **stock, int size, int y, t_position *position);
int            right(char **stock, int size, int y, t_position *position);
void         array_right(t_arrow *right_key);
int            left_x(char **stock, int size, int y, t_position *position);
int            left(char **stock, int size, int y, t_position *position);
void         array_left(t_arrow *left_key);
int             while_main(char *av1, WINDOW *vin);
int             nbr_O_fonc(char **stock, int size);
int             play_the_game_if(char **stock, int size, int i, WINDOW *vin);
int		win_condition(char **stock, t_position *position, int nbr_o);
int	     error_condition(char **stock,int nbr_o, int size);
int     nbr_X(char **stock, int nbr_o, int size);
int     player(char **stock, int size);
#endif /* !MY_H_ */
