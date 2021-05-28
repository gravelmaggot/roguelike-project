#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define esc 27

typedef struct Position
{
    int yAxis;
    int xAxis;

} Position;


typedef struct Player
{
    //char name[10];
    Position playerPosition;
    int hp;
    int mana;
    //Room * room;
} Player;

typedef struct Room
{

    Position roomPosition;
    int height;
    int width;

    Position door[4];

    //Monster ** monsters;
    //Item ** items;

} Room;


//ncurses and Map/Rooms
int screenSetup(); //sets up the screen on termial through ncurses
Room ** printMap(); //setting up the map
Room * createRoom(int x, int y, int height, int width);
int printRoom(Room * room);

//Player creation and movement
Player * createPlayer(); //funct to create player
int userInput(int input, Player *player);
int checkPosition(int newY, int newX, Player *player);
int movePlayer(int y, int x, Player *player);
int roomHallways(Position  doorExit, Position  doorEntrance);

#endif