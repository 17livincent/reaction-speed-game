// terminal-based reaction speed game

#include <chrono>

typedef std::chrono::duration<int> seconds_type;
typedef std::chrono::duration<double> millis_type;
typedef std::chrono::time_point<std::chrono::system_clock> tp_clock;

using namespace std;

class Game {
    private:
        int MIN_WAIT = 1;   // minimum waiting time, default 1s
        int RANGE_WAIT = 5; // max time between MIN_WAIT and the longest possible waiting time
        int iterations = 0; // number of values used to compute avg
        tp_clock start;     // the time value when waiting time is finished, AKA the time when the player can respond
        tp_clock end;       // the time value when the player responds
        millis_type waiting, reaction, avg; // waiting time, reaction time, and the avg reaction time

    public:
        void setMIN_WAIT(int num) {
            /*
                set parameter MIN_WAIT
            */
            MIN_WAIT = num;
        }
        int getMIN_WAIT() {
            /*
                Return parameter MIN_WAIT
            */
            return MIN_WAIT;
        }
        void setRANGE_WAIT(int num) {
            /*
                Set parameter RANGE_WAIT
            */
            RANGE_WAIT = num;
        }
        int getRANGE_WAIT() {
            /*
                Returns RANGE_WAIT
            */
            return RANGE_WAIT;
        }

        void iterate() {
            /*
                Increment parameter iterations
            */
            iterations++;
        }
        int getIterations() {
            /*
                Return parameter iterations
            */
            return iterations;
        }
        int resetIterations() {
            /*
                Set parameter iterations to 0
            */
            iterations = 0;
        }
         
        void startTimer() {
            /*
                Defines the parameter start time
            */
            start = chrono::system_clock::now();
        }
        tp_clock getStart() {
            /*
                Returns the parameter start time
            */
            return start;
        }
        void endTimer() {
            /*
                Defines the parameter end time
            */
            end = chrono::system_clock::now();
        }
        tp_clock getEnd() {
            /*
                Returns the parameter end time
            */
            return end;
        }
       
        millis_type createWaitingTime() {
            /*
                Randomly generates the seconds and milliseconds 
                of the waiting time.
                Does not give this value to parameter waiting
            */
            srand(time(NULL));
            seconds_type seconds(rand() % RANGE_WAIT + MIN_WAIT);
            millis_type milliseconds(rand() % 999);
            millis_type waiting = seconds + milliseconds / 1000;
    
            return waiting;
        }  
        void setWaitingTime(millis_type pause) {
            /*
                Sets parameter waiting
            */
            waiting = pause;
        }
        millis_type getWaitingTime() {
            /*
                Returns the parameter waiting
            */
            return waiting;
        }
        void wait() {
            /*
                Makes the program wait for the duration in waiting time
            */
            this_thread::sleep_for(waiting);
        }

        short playerReaction() {
            /*
            Waits until the user inputs anything, 
            including a blank, in the terminal, 
            and then returns an integer
            */
            // wait for an input
            cin.get();   // busy wait
            // once input is received, return
            return 1;
        }
        void setReactionTime() {
            /*
                Computes the reaction time from parameters end and start
                and  gives that value to parameter reaction
            */
            reaction = end - start;
        }
        millis_type getReactionTime() {
            /*
                Returns parameter reaction
            */
            return reaction;
        }

        void setAvg(millis_type time) {
            /*
                Computes the new avg and gives that value to parameter avg
            */
            iterations++;
            avg = ((iterations - 1) * avg + time) / iterations;
        }
        void resetAvg() {
            avg = chrono::milliseconds::zero();
            iterations = 0;
        }      
        millis_type getAvg() {
            /*
                Returns parameter avg
            */
            return avg;
        }

};
