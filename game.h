#include <chrono>

using namespace std;

typedef chrono::duration<int> seconds_type;
typedef chrono::duration<double> millis_type;
typedef chrono::time_point<chrono::system_clock> tp_clock;

class Game {
    private:
        const int MIN_WAIT = 1;
        const int RANGE_WAIT = 5;
        tp_clock start, end;
        millis_type waiting, reaction;

    public:
        short playerReaction() {
            // wait for an input
            cin.get();   // busy wait
            // once input is received, return
            return 1;
        }
        
        void startTimer() {
            start = chrono::system_clock::now();
        }

        tp_clock getStart() {
            return start;
        }
        
        void endTimer() {
            end = chrono::system_clock::now();
        }

        tp_clock getEnd() {
            return end;
        }

        millis_type createWaitingTime() {
            srand(time(NULL));
            seconds_type seconds(rand() % RANGE_WAIT + MIN_WAIT);
            millis_type milliseconds(rand() % 999);
            millis_type waiting = seconds + milliseconds / 1000;
    
            return waiting;
        }

        void setWaitingTime(millis_type pause) {
            waiting = pause;
        }

        millis_type getWaitingTime() {
            return waiting;
        }

        void wait() {
            this_thread::sleep_for(waiting);
        }

        void setReactionTime() {
            reaction = end - start;
        }

        millis_type getReactionTime() {
            return reaction;
        }


};