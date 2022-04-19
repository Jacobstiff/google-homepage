//C Program using the Monte Carlo simulation to give an idea
//on the chances of winning a Football game, with the clock at 0, and
//the option to kick a field goal or go for the 2 Point Conversion
#include <stdio.h>
#include <stdlib.h>

//Function to simulate the how many times you'd win going for the 2 Points
int GoForIt(){
    int TwoPoint = 52;  //Leaguewide stats of successful 2 point conversion
    int overtime = 50;  //Chance of winning overtime
    int t = 1;
    int f = 0;
    int temp = (rand() % 100) + 1;
        if(temp <= TwoPoint){
            int ranint = (rand() % 100) + 1;
            if(ranint <= overtime){
                return 1;
            }
        }
        else return 0;
}

//Used to calculate the odds of winning via Extra Point
int PlayItSafe(){
    int XPP = 95;           //Percentage of getting the Extra Point
    int otRecieve = 54;     //Odds of winning in OT recieving the ball
    int otKick = 46;        //Odds of winning in OT kicking the ball
    int coinFlip= 50;       //Odds of winning cointoss
    int t = 1;
    int f = 0;

    int temp1 = (rand() % 100) + 1;
    int temp2 = (rand() % 100) + 1;
    int temp3 = (rand() % 100) + 1;
    int temp4 = (rand() % 100) + 1;
    //If random number is less than Chance of getting Extra Point (XPP)
    if(temp1 <= XPP){
        //Winning coin flip
        if(temp2 <= coinFlip){
            //Less than chance of winning Kicking Ball 
            if(temp3 <= otKick){
                //Win
                return t;
        }
            else{
                //Lose
                return f;
            }
        }
            //Losing coin flip
        else{
            //Recieving the ball
            if(temp4 <= otRecieve){
                //win
                return t;
            }
            else{
                //lose
                return f;
            }
        }
    }
        else return 0;
}
int outcome(int trials){
    int winsGoingTwo = 0;
    int lossesGoingTwo = 0;
    int winsXP = 0;
    int losesXP = 0;
    int curTrial = 0;
    do
    {
        //Going for two Points
        if(curTrial % 2 == 0){
            if(GoForIt() == 1){
                curTrial += 1;
                winsGoingTwo++;
            }
            else{
                curTrial += 1;
                lossesGoingTwo += 1;
        }
    }
        else{
            //Not going for 2 Points
            if(PlayItSafe() == 1){
                curTrial += 1;
                winsXP += 1;
            }
            else{
                curTrial +=1;
                losesXP +=1;
            }
        }   
    } while (curTrial < trials);

printf("\nWins by playing it safe, making the Extra Point: %d", winsXP);
printf("\nLosses by playing it safe, missing the extra: %d", losesXP);
printf("\nWins by making and going for 2 Point Conversion: %d", winsGoingTwo);
printf("\nLosses going for 2 Points and not converting: %d\n", lossesGoingTwo);
}


int main() {
    //Amount of simulations 
  int trials = 10000;
  outcome(trials);
}