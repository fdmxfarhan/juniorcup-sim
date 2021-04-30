// ======================================================================
// == DO NOT MODIFY THIS FILE BY HAND
// ======================================================================
#include "robot.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "socket_udp.h"
#include <sstream>
#include <windows.h>
Junior_Soccer_Simulation Robot;
void Junior_Soccer_Simulation::sensor()
{
//#if bluetooth

		for (int i = 0; i < number_of_teamat_robot; i++)
	{
		receive_udp(i);
		std::string data(Robot.receive);
			if (Robot.ID[i] == Robot.receive[1])// && teamat == Robot.receive[0])
		if (sizeof(Robot.receive) >= 10)
			{

				 std::istringstream cmp(data.substr(2, 3));
                 cmp >> Robot.cmp[i];
				 std::istringstream imin(data.substr(5, 2));
                 imin >> Robot.imin[i];
                 std::istringstream ldr_back(data.substr(7, 4));
                 ldr_back >> Robot.ldr_back[i];
                 std::istringstream ldr_front(data.substr(11, 4));
                 ldr_front >> Robot.ldr_front[i];
			     std::istringstream ldr_left(data.substr(15, 4));
                 ldr_left >> Robot.ldr_left[i];
                 std::istringstream ldr_right(data.substr(19, 4));
                 ldr_right >> Robot.ldr_right[i];
                 std::istringstream srf_back(data.substr(23, 4));
                 srf_back >> Robot.srf_back[i];
                 std::istringstream srf_front(data.substr(27, 4));
                 srf_front >> Robot.srf_front[i];
                 std::istringstream srf_left(data.substr(31, 4));
                 srf_left >> Robot.srf_left[i];
                 std::istringstream srf_right(data.substr(35, 4));
                 srf_right >> Robot.srf_right[i];
                 std::istringstream min(data.substr(39, 4));
                 min >> Robot.min[i];
                 std::istringstream ball_distance(data.substr(43, 4));
                 ball_distance >> Robot.ball_distance[i];

			}

	}
//#endif // bluetooth
}
void Junior_Soccer_Simulation::sensor(int Robot_ID)
{
#if !bluetooth
	//receive(Robot_ID);
	std::string data(Robot.receive);
	if (sizeof(data) >= 38)
		if (Robot.ID[Robot_ID] == Robot.receive[1] && teamat == Robot.receive[0])
		{
            std::istringstream cmp(data.substr(2, 3));
            cmp >> Robot.cmp[Robot_ID];
            std::istringstream imin(data.substr(5, 2));
            imin >> Robot.imin[Robot_ID];
            std::istringstream ldr_back(data.substr(7, 4));
            ldr_back >> Robot.ldr_back[Robot_ID];
            std::istringstream ldr_front(data.substr(11, 4));
            ldr_front >> Robot.ldr_front[Robot_ID];
            std::istringstream ldr_left(data.substr(15, 4));
            ldr_left >> Robot.ldr_left[Robot_ID];
            std::istringstream ldr_right(data.substr(19, 4));
            ldr_right >> Robot.ldr_right[Robot_ID];
            std::istringstream srf_back(data.substr(23, 4));
            srf_back >> Robot.srf_back[Robot_ID];
            std::istringstream srf_front(data.substr(27, 4));
            srf_front >> Robot.srf_front[Robot_ID];
            std::istringstream srf_left(data.substr(31, 4));
            srf_left >> Robot.srf_left[Robot_ID];
            std::istringstream srf_right(data.substr(35, 4));
            srf_right >> Robot.srf_right[Robot_ID];
            std::istringstream min(data.substr(39, 4));
            min >> Robot.min[Robot_ID];
            std::istringstream ball_distance(data.substr(43, 4));
            ball_distance >> Robot.ball_distance[Robot_ID];
		}
#endif // !bluetooth
}
void Junior_Soccer_Simulation::motor(int ml1, int ml2, int mr2, int mr1, int robot_number)
{
	Robot.send[0] = 'm';
	Robot.send[1] = teamat;
	Robot.send[2] = '0' + robot_number;
	if (ml1 >= 0)Robot.send[3] = '+';
	else { Robot.send[3] = '-'; ml1 *= -1; }
	Robot.send[4] = '0' + ((ml1 / 100) % 10);
	Robot.send[5] = '0' + (((ml1 / 10)) % 10);
	Robot.send[6] = '0' + (ml1 % 10);
	if (ml2 >= 0)Robot.send[7] = '+';
	else { Robot.send[7] = '-'; ml2 *= -1; }
	Robot.send[8] = '0' + ((ml2 / 100) % 10);
	Robot.send[9] = '0' + ((ml2 / 10) % 10);
	Robot.send[10] = '0' + (ml2 % 10);
	if (mr2 >= 0)Robot.send[11] = '+';
	else { Robot.send[11] = '-'; mr2 *= -1; }
	Robot.send[12] = '0' + ((mr2 / 100) % 10);
	Robot.send[13] = '0' + ((mr2 / 10) % 10);
	Robot.send[14] = '0' + (mr2 % 10);
	if (mr1 >= 0)Robot.send[15] = '+';
	else { Robot.send[15] = '-'; mr1 *= -1; }
	Robot.send[16] = '0' + ((mr1 / 100) % 10);
	Robot.send[17] = '0' + ((mr1 / 10) % 10);
	Robot.send[18] = '0' + (mr1 % 10);
	send_udp();
}
////////////////////////////


///////////////////function
int read_cmp(int ID)
{
    return Robot.cmp[ID];
}
int read_tsop_number(int ID)
{
    return Robot.imin[ID];
}
int read_tsop_min(int ID)
{
    return Robot.min[ID];
}
int read_ldr_l(int ID)
{
    return Robot.ldr_left[ID];
}
int read_ldr_r(int ID)
{
    return Robot.ldr_right[ID];
}
int read_ldr_b(int ID)
{
    return Robot.ldr_back[ID];
}
int read_ldr_f(int ID)
{
    return Robot.ldr_front[ID];
}
int read_distance_b(int ID)
{
    return Robot.srf_back[ID];
}
int read_distance_f(int ID)
{
    return Robot.srf_front[ID];
}
int read_distance_r(int ID)
{
    return Robot.srf_right[ID];
}
int read_distance_l(int ID)
{
    return Robot.srf_left[ID];
}
int read_ball_distance(int ID)
{
    return Robot.ball_distance[ID];
}
void motor0(int ml1, int ml2, int mr2, int mr1)
{
    Robot.motor(ml1,ml2,mr2,mr1,0);
}
void motor1(int ml1, int ml2, int mr2, int mr1)
{
    Robot.motor(ml1,ml2,mr2,mr1,1);
}

void delay_ms(int ms)
{
    Sleep(ms);
}
