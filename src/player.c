#include <rogue.h>

Player * createPlayer(){
    Player * newPlayer;
    newPlayer = malloc(sizeof(Player));

    /*
    char nameTemp[10];
    newPlayer->name[0] = wgetstr(WINDOW *win, &name);
    */
    newPlayer->playerPosition.xAxis = 5;
    newPlayer->playerPosition.yAxis = 7;
    newPlayer->hp = 100;
    newPlayer->mana = 100;

    movePlayer(7, 5, newPlayer);

    return newPlayer;
}

int userInput(int input, Player *player){

    int newY;
    int newX;

    switch (input)
    {
    case 'w':
    case 'W':
        newY = player->playerPosition.yAxis -1;
        newX = player->playerPosition.xAxis;
        break;
    
    case 'a':
    case 'A':
        newY = player->playerPosition.yAxis;
        newX = player->playerPosition.xAxis -1;
        break;

    case 's':
    case 'S':
        newY = player->playerPosition.yAxis +1;
        newX = player->playerPosition.xAxis;
        break;

    case 'd':
    case 'D':
        newY = player->playerPosition.yAxis;
        newX = player->playerPosition.xAxis +1;
        break;

    default:
        break;
    }

    checkPosition(newY, newX, player);


}

int checkPosition(int newY, int newX, Player *player){

    switch (mvinch(newY, newX))
    {
    case '.':
    case '+':
    case '#':
        movePlayer(newY, newX, player);
        break;
    
    default:
        move(player->playerPosition.yAxis, player->playerPosition.xAxis);
        break;
    }

}

int movePlayer(int y, int x, Player *player){

    mvprintw(player->playerPosition.yAxis, player->playerPosition.xAxis, ".");
    player->playerPosition.yAxis = y;
    player->playerPosition.xAxis = x;
    mvprintw(player->playerPosition.yAxis, player->playerPosition.xAxis, "@");
    move(player->playerPosition.yAxis, player->playerPosition.xAxis);

}