#include "robot.h"
#include "iostream"
using namespace std;

int v = 255;

/// Robot 0 Variables
int cmp0, min0, imin0, ball_distance_0;
int ldr_l_0, ldr_r_0, ldr_f_0, ldr_b_0;
int distance_r_0, distance_l_0, distance_b_0, distance_f_0;

/// Robot 1 Variables
int cmp1, min1, imin1, ball_distance_1;
int ldr_l_1, ldr_r_1, ldr_f_1, ldr_b_1;
int distance_r_1, distance_l_1, distance_b_1, distance_f_1;

void readSensors()
{
    /// Read all sensor
    Robot.sensor();

    /// TSOP Sensors
    imin0 = read_tsop_number(0);
    min0 = read_tsop_min(0);

    imin1 = read_tsop_number(1);
    min1 = read_tsop_min(1);

    /// Compass Sensor
    cmp0=read_cmp(0);
    if(cmp0 > 128) cmp0 -= 255;

    cmp1=read_cmp(1);
    if(cmp1 > 128) cmp1 -= 255;

    /// LDR Sensors
    ldr_b_0 = read_ldr_b(0);
    ldr_f_0 = read_ldr_f(0);
    ldr_l_0 = read_ldr_l(0);
    ldr_r_0 = read_ldr_r(0);

    ldr_b_1 = read_ldr_b(1);
    ldr_f_1 = read_ldr_f(1);
    ldr_l_1 = read_ldr_l(1);
    ldr_r_1 = read_ldr_r(1);

    /// Distance Sensors
    distance_b_0 = read_distance_b(0);
    distance_r_0 = read_distance_r(0);
    distance_l_0 = read_distance_l(0);
    distance_f_0 = read_distance_f(0);

    distance_b_1 = read_distance_b(1);
    distance_r_1 = read_distance_r(1);
    distance_l_1 = read_distance_l(1);
    distance_f_1 = read_distance_f(1);

    /// Ball Distance
    ball_distance_0 = read_ball_distance(0);

    ball_distance_1 = read_ball_distance(1);

}

void move0(int dir)
{

}

int main()
{
    Robot.Robot_Init();
    while (true) {
        readSensors();
        cout<<imin1<<endl;
        /*
        /// Robot 1
        if (min1 < 700)
        {
            if (imin1 == 0)       motor1(v, v, -v, -v);
            else if (imin1 == 1)  motor1(v, v / 2, -v, -v / 2);
            else if (imin1 == 2)  motor1(v, 0, -v, 0);
            else if (imin1 == 3)  motor1(v, -v / 2, -v, v / 2);
            else if (imin1 == 4)  motor1(v, -v, -v, v);
            else if (imin1 == 5)  motor1(v / 2, -v, -v / 2, v);
            else if (imin1 == 6)  motor1(0, -v, 0, v);
            else if (imin1 == 7)  motor1(-v / 2, -v, v / 2, v);
            else if (imin1 == 8)  motor1(-v, -v, v, v);
            else if (imin1 == 9)  motor1(-v, -v / 2, v, v / 2);
            else if (imin1 == 10) motor1(-v, 0, v, 0);
            else if (imin1 == 11) motor1(-v, v / 2, v, -v / 2);
            else if (imin1 == 12) motor1(-v, v, v, -v);
            else if (imin1 == 13) motor1(-v / 2, v, v / 2, -v);
            else if (imin1 == 14) motor1(0, v, 0, -v);
            else if (imin1 == 15) motor1(v / 2, v, -v / 2, -v);
        }
        else  motor1(0, 0, 0, 0);

        /// Robot 0
        if (min0 < 700)
        {
            if (imin0 == 0)       motor0(v, v, -v, -v);
            else if (imin0 == 1)  motor0(v, v / 2, -v, -v / 2);
            else if (imin0 == 2)  motor0(v, 0, -v, 0);
            else if (imin0 == 3)  motor0(v, -v / 2, -v, v / 2);
            else if (imin0 == 4)  motor0(v, -v, -v, v);
            else if (imin0 == 5)  motor0(v / 2, -v, -v / 2, v);
            else if (imin0 == 6)  motor0(0, -v, 0, v);
            else if (imin0 == 7)  motor0(-v / 2, -v, v / 2, v);
            else if (imin0 == 8)  motor0(-v, -v, v, v);
            else if (imin0 == 9)  motor0(-v, -v / 2, v, v / 2);
            else if (imin0 == 10) motor0(-v, 0, v, 0);
            else if (imin0 == 11) motor0(-v, v / 2, v, -v / 2);
            else if (imin0 == 12) motor0(-v, v, v, -v);
            else if (imin0 == 13) motor0(-v / 2, v, v / 2, -v);
            else if (imin0 == 14) motor0(0, v, 0, -v);
            else if (imin0 == 15) motor0(v / 2, v, -v / 2, -v);
        }
        else  motor0(0, 0, 0, 0);
        */
    }
}
