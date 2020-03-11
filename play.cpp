#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <time.h>
#include <thread>

#include "reactionspeedgame.h"


int main(int argc, char** argv) {
    Game game;
    short ready;
    short react;
    
    game.setMIN_WAIT(1);
    game.setRANGE_WAIT(5);

    while(1) {
        // get waiting time before anything else
        game.setWaitingTime(game.createWaitingTime());

        // print instructions
        cout << endl << "Press ENTER when ready" << endl;

        // wait for play to be ready
        ready = game.playerReaction();
        cout << "get set..." << endl;

        // elapse waiting time
        game.wait();
        // start timer
        game.startTimer();
        // print GO after waiting time is finished
        cout << "########## GO ##########" << endl;

        // get time of player reaction
        ready = game.playerReaction();
        // end timer
        game.endTimer();
        // compute reaction time
        game.setReactionTime();
    
        // print resulting time
        cout << "Reaction time: " << game.getReactionTime().count() << endl;

        // show avg
        game.setAvg(game.getReactionTime());
        cout << "Avg: (" << game.getIterations() << ") " << game.getAvg().count() << endl;
    }
    
}
