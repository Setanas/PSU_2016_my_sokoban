# PSU_2016_my_sokoban

Sokoban is one of the first year project in Epitech. <br/>
What is Sokoban ? It is a type of puzzle video game, in which the player pushes crates or boxes around in a warehouse, trying to get them to storage locations. <br/>
Here we have a player represented by a 'P', the box by 'X'and the storage locations by 'O'. <br/>
In this game, we have the wall represented by '#'. <br/>
Here is a map example : 

```
############
#        O #
#   P   ####
#          #
#######    #
#  O ##    #
#    ##    #
#          #
#       XX #
#       #  #
############
```

## Getting Started

This game is programmed in C on a Linux environment. <br/>
The programm use the ncruses library.

### Prerequisites

To compile we are using gcc.<br/>
The programm use the ncruses library.

### Installing

To install the game please use the Makefile to compile.
 
```
$> make
```

At the end you should have a "my_sokoban" binary in your current folder.

## Creating your own map

You can create your own map by adding a file in the folder "maps".<br/>
You can name it as you want<br/>
The file must contain one player 'P' and at least one 'O' and one 'X'. <br/>
The map must be surrounded by closed wall. <br/>
The map below is correct.
```
    #
   #O#
  #   #
 #   X #
#P      #
#########
```

The map below isn't because there is a hole.

```
    #
   #O#
  #   #
 #   X 
#P      #
#########
```

## Running the programm

To run :<br/>

```
$> ./my_sokoban {map_path}
```

Replace {map_path} by the path of the map

If you want to usage:
```
$> ./my_sokoban -h
USAGE
	   ./my_sokoban map

DESCRIPTION
	   map	file representing the warehouse map, containing '#' for walls,
		'P' for the player, 'X' for boxes and 'O' for storage locations.
```

## Authors

* **Sébastien Tan** - *Developer* - [Setanas](https://github.com/Setanas)