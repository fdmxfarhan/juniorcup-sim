#include "./smart car/robot.h"
#include <iostream>

using namespace std;
int main(int argc, char** argv)
{
    Robot.Robot_Init();
    while(true)
    {
        Robot.sensor();
        if(Robot.crossWalk < 20 && Robot.trafficLight == 2){
            Robot.brake(true);
        }
        else if(Robot.crossWalk < 10 && Robot.trafficLight == 3){
            Robot.turnRight();
        }
        else {
            Robot.setSpeed(10);
            Robot.brake(false);
        }
    }
}
