#include <rogue.h>

// Room Functions

Room * createRoom(int y, int x, int height, int width){

    Room * newRoom;
    newRoom = malloc(sizeof(Room));
    newRoom->roomPosition.xAxis =x;
    newRoom->roomPosition.yAxis = y;
    newRoom->height = height;
    newRoom->width = width;

    //newRoom->door = malloc(sizeof(Position) * 4);


    //top door
    //newRoom->door[0] = malloc(sizeof(Position));
    newRoom->door[0].xAxis = rand() % (width -2) + newRoom->roomPosition.xAxis +1;
    newRoom->door[0].yAxis = newRoom->roomPosition.yAxis;

    //bottom door
    //newRoom->door[1] = malloc(sizeof(Position));
    newRoom->door[1].xAxis = rand() % (width - 2) + newRoom->roomPosition.xAxis +1;
    newRoom->door[1].yAxis = newRoom->roomPosition.yAxis + newRoom->height -1;

    //left side door
    //newRoom->door[2] = malloc(sizeof(Position));
    newRoom->door[2].xAxis = newRoom->roomPosition.xAxis;
    newRoom->door[2].yAxis = rand() % (height -2) + newRoom->roomPosition.yAxis +1;

    //right side door
    //newRoom->door[3] = malloc(sizeof(Position));
    newRoom->door[3].xAxis = newRoom->roomPosition.xAxis + newRoom->width -1;
    newRoom->door[3].yAxis = rand() % (height -2) + newRoom->roomPosition.yAxis +1;

    return newRoom;

}

int printRoom(Room * room){

    int x, y;

    //top and bottom walls
    for(x = room->roomPosition.xAxis; x < room->roomPosition.xAxis + room->width; x++){
        mvprintw(room->roomPosition.yAxis, x, "-"); //top wall
        mvprintw(room->roomPosition.yAxis + room->height -1, x, "-"); //bottom wall
    }

    //walls and floor
    for (y = room->roomPosition.yAxis +1; y < room->roomPosition.yAxis + room->height -1; y++)
    {
        //side walls
        mvprintw(y, room->roomPosition.xAxis, "|");
        mvprintw(y, room->roomPosition.xAxis + room->width -1, "|");

        for (x = room->roomPosition.xAxis +1; x < room->roomPosition.xAxis + room->width -1; x++)
        {
            //floor
            mvprintw(y, x, ".");
        }
        
    }

    //Doors
    mvprintw(room->door[0].yAxis, room->door[0].xAxis, "+");
    mvprintw(room->door[1].yAxis, room->door[1].xAxis, "+");
    mvprintw(room->door[2].yAxis, room->door[2].xAxis, "+");
    mvprintw(room->door[3].yAxis, room->door[3].xAxis, "+");
    

}

int roomHallways(Position  doorExit, Position  doorEntrance){

    Position temp;
    Position previous;

    int count = 0;

    temp.xAxis = doorExit.xAxis;
    temp.yAxis = doorExit.yAxis;

    previous = temp;

    while(1){

        //step left
        if ((abs((temp.xAxis -1) - doorEntrance.xAxis) < abs(temp.xAxis - doorEntrance.xAxis)) && (mvinch(temp.yAxis, temp.xAxis -1) == ' '))
        {
            previous.xAxis = temp.xAxis;
            temp.xAxis = temp.xAxis -1;

        //step right
        } else if ((abs((temp.xAxis +1) - doorEntrance.xAxis) < abs(temp.xAxis - doorEntrance.xAxis)) && (mvinch(temp.yAxis, temp.xAxis +1) == ' '))
        {
            previous.xAxis = temp.xAxis;
            temp.xAxis = temp.xAxis +1;

        //step down
        } else if ((abs((temp.yAxis +1) - doorEntrance.yAxis) < abs(temp.yAxis - doorEntrance.yAxis)) && (mvinch(temp.yAxis +1 , temp.xAxis) == ' '))
        {
            previous.yAxis = temp.yAxis;
            temp.yAxis = temp.yAxis +1;


        //step up
        } else if ((abs((temp.yAxis -1) - doorEntrance.yAxis) < abs(temp.yAxis - doorEntrance.yAxis)) && (mvinch(temp.yAxis -1, temp.xAxis) == ' '))
        {
            previous.yAxis = temp.yAxis;
            temp.yAxis = temp.yAxis -1;
        } else {
            if (count == 0)
            {
                temp = previous;
                count++;
                continue;
            } else{   

            return 0;

            }

        }
        
        mvprintw(temp.yAxis, temp.xAxis, "#");

    }

    return 1;

}