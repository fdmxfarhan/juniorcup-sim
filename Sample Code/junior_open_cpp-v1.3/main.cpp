#include "robot.h"
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int speed = 255;

/// Robot 1 Variables
int cmp1,ldr_l_1,ldr_r_1,ldr_f_1,ldr_b_1,distance_r_1,distance_l_1,distance_b_1,distance_f_1;
int x_ball_1,y_ball_1,x_yellow_goal_1,y_yellow_goal_1,x_blue_goal_1,y_blue_goal_1;
int yellow_goal_direction_1,blue_goal_direction_1,ball_direction_1;
int ball_distance_1, yellow_goal_distance_1;
int var1;

/// Robot 0 Variables
int cmp0,ldr_l_0,ldr_r_0,ldr_f_0,ldr_b_0,distance_r_0,distance_l_0,distance_b_0,distance_f_0;
int x_ball_0,y_ball_0,x_yellow_goal_0,y_yellow_goal_0,x_blue_goal_0,y_blue_goal_0;
int yellow_goal_direction_0,blue_goal_direction_0,ball_direction_0;
int ball_distance_0, yellow_goal_distance_0;
int var0;

/// Functions Declarations
int angle(int x,int y)
{
    return atan2(x, y) * 180 / M_PI;
}

int direction(int angle)
{
    int direction,i;
    angle*=-1;
    if (angle < 0) angle += 360;
    angle = 360 - angle;
    for(i = 0; i < 16; i++)
    {
        if(angle <= 11.25) direction = 0;
        else if(angle >= 348.5) direction = 0;
        else if((angle - 11.25 >= i * 22.5) && (angle-11.25 < (i+1) * 22.5))
            direction = i + 1;
    }
    return direction;
}

void readSensors()
{
    /// Read all sensor
    Robot.sensor();
    /// Get x,y of Ball and Goals
    x_ball_0 = read_ball_x(0);
    y_ball_0 = read_ball_y(0);
    x_yellow_goal_0 = read_yellow_goal_x(0);
    y_yellow_goal_0 = read_yellow_goal_y(0);
    x_blue_goal_0 = read_blue_goal_x(0);
    y_blue_goal_0 = read_blue_goal_y(0);

    x_ball_1 = read_ball_x(1);
    y_ball_1 = read_ball_y(1);
    x_yellow_goal_1 = read_yellow_goal_x(1);
    y_yellow_goal_1 = read_yellow_goal_y(1);
    x_blue_goal_1 = read_blue_goal_x(1);
    y_blue_goal_1 = read_blue_goal_y(1);

    /// Get CMP
    cmp0=read_cmp(0);
    if(cmp0 > 128)              cmp0 -= 255;
    if(cmp0 > -30 && cmp0 < 30) cmp0 *= -3;
    else                        cmp0 *= -2;

    cmp1=read_cmp(1);
    if(cmp1 > 128) cmp1 -= 255;
    if(cmp1 > -30 && cmp1 < 30) cmp1 *= -3;
    else                        cmp1 *= -2;

    /// Get LDR Sensors
    ldr_b_0=read_ldr_b(0);
    ldr_f_0=read_ldr_f(0);
    ldr_l_0=read_ldr_l(0);
    ldr_r_0=read_ldr_r(0);

    ldr_b_1=read_ldr_b(1);
    ldr_f_1=read_ldr_f(1);
    ldr_l_1=read_ldr_l(1);
    ldr_r_1=read_ldr_r(1);

    /// Get Distance Sensors
    distance_b_0=read_distance_b(0);
    distance_r_0=read_distance_r(0);
    distance_l_0=read_distance_l(0);
    distance_f_0=read_distance_f(0);

    distance_b_1=read_distance_b(1);
    distance_r_1=read_distance_r(1);
    distance_l_1=read_distance_l(1);
    distance_f_1=read_distance_f(1);

    /// Calculate Directions
    ball_direction_0 = direction(angle(x_ball_0, y_ball_0));
    blue_goal_direction_0 = direction(angle(x_blue_goal_0, y_blue_goal_0));
    yellow_goal_direction_0 = direction(angle(x_yellow_goal_0, y_yellow_goal_0));

    ball_direction_1 = direction(angle(x_ball_1, y_ball_1));
    blue_goal_direction_1 = direction(angle(x_blue_goal_1, y_blue_goal_1));
    yellow_goal_direction_1 = direction(angle(x_yellow_goal_1, y_yellow_goal_1));

    /// Calculate Distances
    ball_distance_0 = sqrt(x_ball_0*x_ball_0 + y_ball_0*y_ball_0);
    yellow_goal_distance_0 = sqrt(x_yellow_goal_0*x_yellow_goal_0 + y_yellow_goal_0*y_yellow_goal_0);

    ball_distance_1 = sqrt(x_ball_1*x_ball_1 + y_ball_1*y_ball_1);
    yellow_goal_distance_1 = sqrt(x_yellow_goal_1*x_yellow_goal_1 + y_yellow_goal_1*y_yellow_goal_1);

}

void move0(int dir)
{
    if(dir == 0)      motor0(speed   + cmp0, speed   + cmp0, -speed  + cmp0, -speed   + cmp0);
    if(dir == 1)      motor0(speed   + cmp0, speed/2 + cmp0, -speed  + cmp0, -speed/2 + cmp0);
    if(dir == 2)      motor0(speed   + cmp0, 0       + cmp0, -speed  + cmp0, 0        + cmp0);
    if(dir == 3)      motor0(speed   + cmp0, -speed/2+ cmp0, -speed  + cmp0, speed/2  + cmp0);
    if(dir == 4)      motor0(speed   + cmp0, -speed  + cmp0, -speed  + cmp0, speed    + cmp0);
    if(dir == 5)      motor0(speed/2 + cmp0, -speed  + cmp0, -speed/2+ cmp0, speed    + cmp0);
    if(dir == 6)      motor0(0       + cmp0, -speed  + cmp0, 0       + cmp0, speed    + cmp0);
    if(dir == 7)      motor0(-speed/2+ cmp0, -speed  + cmp0, speed/2 + cmp0, speed    + cmp0);

    if(dir == 8)      motor0(-speed  + cmp0, -speed  + cmp0, speed   + cmp0, speed    + cmp0);

    if(dir == 9)      motor0(-speed   + cmp0, -speed/2+ cmp0, speed   + cmp0, speed/2 + cmp0);
    if(dir == 10)     motor0(-speed   + cmp0, 0       + cmp0, speed   + cmp0, 0       + cmp0);
    if(dir == 11)     motor0(-speed   + cmp0, speed/2 + cmp0, speed   + cmp0, -speed/2+ cmp0);
    if(dir == 12)     motor0(-speed   + cmp0, speed   + cmp0, speed   + cmp0, -speed  + cmp0);
    if(dir == 13)     motor0(-speed/2 + cmp0, speed   + cmp0, speed/2 + cmp0, -speed  + cmp0);
    if(dir == 14)     motor0(0        + cmp0, speed   + cmp0, 0       + cmp0, -speed  + cmp0);
    if(dir == 15)     motor0(speed/2  + cmp0, speed   + cmp0, -speed/2+ cmp0, -speed  + cmp0);
}

void move1(int dir)
{
    if(dir == 0)      motor1(speed   + cmp1, speed   + cmp1, -speed  + cmp1, -speed   + cmp1);
    if(dir == 1)      motor1(speed   + cmp1, speed/2 + cmp1, -speed  + cmp1, -speed/2 + cmp1);
    if(dir == 2)      motor1(speed   + cmp1, 0       + cmp1, -speed  + cmp1, 0        + cmp1);
    if(dir == 3)      motor1(speed   + cmp1, -speed/2+ cmp1, -speed  + cmp1, speed/2  + cmp1);
    if(dir == 4)      motor1(speed   + cmp1, -speed  + cmp1, -speed  + cmp1, speed    + cmp1);
    if(dir == 5)      motor1(speed/2 + cmp1, -speed  + cmp1, -speed/2+ cmp1, speed    + cmp1);
    if(dir == 6)      motor1(0       + cmp1, -speed  + cmp1, 0       + cmp1, speed    + cmp1);
    if(dir == 7)      motor1(-speed/2+ cmp1, -speed  + cmp1, speed/2 + cmp1, speed    + cmp1);

    if(dir == 8)      motor1(-speed  + cmp1, -speed  + cmp1, speed   + cmp1, speed    + cmp1);

    if(dir == 9)      motor1(-speed   + cmp1, -speed/2+ cmp1, speed   + cmp1, speed/2 + cmp1);
    if(dir == 10)     motor1(-speed   + cmp1, 0       + cmp1, speed   + cmp1, 0       + cmp1);
    if(dir == 11)     motor1(-speed   + cmp1, speed/2 + cmp1, speed   + cmp1, -speed/2+ cmp1);
    if(dir == 12)     motor1(-speed   + cmp1, speed   + cmp1, speed   + cmp1, -speed  + cmp1);
    if(dir == 13)     motor1(-speed/2 + cmp1, speed   + cmp1, speed/2 + cmp1, -speed  + cmp1);
    if(dir == 14)     motor1(0        + cmp1, speed   + cmp1, 0       + cmp1, -speed  + cmp1);
    if(dir == 15)     motor1(speed/2  + cmp1, speed   + cmp1, -speed/2+ cmp1, -speed  + cmp1);
}

void defend0()
{
    var0 = (distance_r_0 - distance_l_0) / 8;
    motor0(-150 + cmp0 + var0, -150 + cmp0 - var0, 150 + cmp0 - var0, 150 + cmp0 + var0);
}

void defend1()
{
    var1 = (distance_r_1 - distance_l_1) / 8;
    motor1(-150 + cmp1 + var1, -150 + cmp1 - var1, 150 + cmp1 - var1, 150 + cmp1 + var1);
}

/// Main Function
int main()
{
    /// Start Communication With Robots
    Robot.Robot_Init();
    while (true) {
        readSensors();

        /// Robot 0
        spin_back(0, true);
        if(y_ball_0 < 25 && y_ball_0 > 20 && x_ball_0 > -5 && x_ball_0 < 5)
        {
            /// Kick the ball
            if(yellow_goal_distance_0 > 300) move0(yellow_goal_direction_0);
            else
            {
                cmp0 = 0;
                if(yellow_goal_direction_0 == 0)      shoot(0);
                else if(yellow_goal_direction_0 < 8)  motor0(50, 150, 150, 50);
                else                                motor0(-50, -150, -150, -50);
            }
        }
        else if(ball_distance_0 <= ball_distance_1)
        {
            /// Forward Robot
            if(ball_direction_0 == 0)       move0(0);
            else if(ball_direction_0 < 3)   move0(ball_direction_0 + 1);
            else if(ball_direction_0 > 13)  move0(ball_direction_0 - 1);
            else if(ball_direction_0 < 8)   move0(ball_direction_0 + 3);
            else if(ball_direction_0 >= 8)  move0(ball_direction_0 - 3);
        }
        else
        {
            /// Goal Keeper Robot
            if(distance_b_0 > 500)          defend0();
            else if(ball_direction_0 == 0)  motor0(cmp0, cmp0, cmp0, cmp0);
            else if(ball_direction_0 < 3)   move0(4);
            else if(ball_direction_0 > 13)  move0(12);
            else if(ball_direction_0 < 8)   move0(ball_direction_0 + 3);
            else if(ball_direction_0 >= 8)  move0(ball_direction_0 - 3);
        }

        /// Robot 1
        spin_back(1, true);
        if(y_ball_1 < 25 && y_ball_1 > 20 && x_ball_1 > -5 && x_ball_1 < 5)
        {
            /// Kick the ball
            if(yellow_goal_distance_1 > 300) move1(yellow_goal_direction_1);
            else
            {
                cmp1 = 0;
                if(yellow_goal_direction_1 == 0)      shoot(1);
                else if(yellow_goal_direction_1 < 8)  motor1(50, 150, 150, 50);
                else                                  motor1(-50, -150, -150, -50);
            }
        }
        else if(ball_distance_0 > ball_distance_1)
        {
            /// Forward Robot
            if(ball_direction_1 == 0)       move1(0);
            else if(ball_direction_1 < 3)   move1(ball_direction_1 + 1);
            else if(ball_direction_1 > 13)  move1(ball_direction_1 - 1);
            else if(ball_direction_1 < 8)   move1(ball_direction_1 + 3);
            else if(ball_direction_1 >= 8)  move1(ball_direction_1 - 3);
        }
        else
        {
            /// Goal Keeper Robot
            if(distance_b_1 > 500)          defend1();
            else if(ball_direction_1 == 0)  motor1(cmp1, cmp1, cmp1, cmp1);
            else if(ball_direction_1 < 3)   move1(4);
            else if(ball_direction_1 > 13)  move1(12);
            else if(ball_direction_1 < 8)   move1(ball_direction_1 + 3);
            else if(ball_direction_1 >= 8)  move1(ball_direction_1 - 3);
        }
    }
}
