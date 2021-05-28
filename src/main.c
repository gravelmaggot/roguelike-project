#include <rogue.h>

int main () {
    int ch;

    Player * player; //creates player 1 pointer

    screenSetup();

    printMap();

    player = createPlayer(); //assigns data to player pointer

    //main loop to keep game running
    while((ch = getch()) != esc){
        userInput(ch, player);
    }

    getch(); //wait for input to exit
    
    endwin(); //clear terminal

    return 0;
}

int screenSetup(){
    initscr(); // clears screen, sets up terminal
    printw("Press ESC twice to quit.");
    noecho(); //prevents input from being echoed to screen
    refresh(); //refresh screen to output data structs manipulated by other funct calls
    srand(time(NULL)); //seed for random numbers
    
    return 1;
}

Room ** printMap() {

    Room ** room;
    room = malloc(sizeof(Room) * 4);

    room [0] = createRoom(6, 4, 10, 18);

    printRoom(room[0]);

    room [1] = createRoom(4, 80, 12, 22);

    printRoom(room[1]);

    room [2] = createRoom(12, 24, 14, 40);

    printRoom(room[2]);

    //set hallways
    roomHallways(room[0]->door[3], room[2]->door[2]);

    roomHallways(room[0]->door[0], room[1]->door[0]);

    return room;
}