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
char flag_ball_x,flag_ball_y,flag_yellow_goal_x,flag_yellow_goal_y,flag_blue_goal_x,flag_blue_goal_y;
		for (int i = 0; i < number_of_teamat_robot; i++)
	{
		receive_udp(i);
		std::string data(Robot.receive);
			if (Robot.ID[i] == Robot.receive[1])// && teamat == Robot.receive[0])
		if (sizeof(Robot.receive) >= 10)
			{

				 std::istringstream cmp(data.substr(2, 3));
                 cmp >> Robot.cmp[i];
                 std::istringstream ldr_back(data.substr(5, 4));
                 ldr_back >> Robot.ldr_back[i];
                 std::istringstream ldr_front(data.substr(9, 4));
                 ldr_front >> Robot.ldr_front[i];
			     std::istringstream ldr_left(data.substr(13, 4));
                 ldr_left >> Robot.ldr_left[i];
                 std::istringstream ldr_right(data.substr(17, 4));
                 ldr_right >> Robot.ldr_right[i];
                 std::istringstream srf_back(data.substr(21, 4));
                 srf_back >> Robot.srf_back[i];
                 std::istringstream srf_front(data.substr(25, 4));
                 srf_front >> Robot.srf_front[i];
                 std::istringstream srf_left(data.substr(29, 4));
                 srf_left >> Robot.srf_left[i];
                 std::istringstream srf_right(data.substr(33, 4));
                 srf_right >> Robot.srf_right[i];

                 std::istringstream flagball_x(data.substr(37, 1));
                 flagball_x >> flag_ball_x;
                 std::istringstream ball_x(data.substr(38, 3));
                 ball_x >> Robot.x[0][i];

                 std::istringstream flagball_y(data.substr(41, 1));
                 flagball_y >> flag_ball_y;
                 std::istringstream ball_y(data.substr(42, 3));
                 ball_y >> Robot.y[0][i];

                 std::istringstream flagyellow_goal_x(data.substr(45, 1));
                 flagyellow_goal_x >> flag_yellow_goal_x;
                 std::istringstream yellow_goal_x(data.substr(46, 3));
                 yellow_goal_x >> Robot.x[1][i];

                 std::istringstream flagyellow_goal_y(data.substr(49, 1));
                 flagyellow_goal_y >> flag_yellow_goal_y;
                 std::istringstream yellow_goal_y(data.substr(50, 3));
                 yellow_goal_y >> Robot.y[1][i];

                 std::istringstream flagblue_goal_x(data.substr(53, 1));
                 flagblue_goal_x >> flag_blue_goal_x;
                 std::istringstream blue_goal_x(data.substr(54, 3));
                 blue_goal_x >> Robot.x[2][i];

                 std::istringstream flagblue_goal_y(data.substr(57, 1));
                 flagblue_goal_y >> flag_blue_goal_y;
                 std::istringstream blue_goal_y(data.substr(58, 3));
                 blue_goal_y >> Robot.y[2][i];

                 if(flag_ball_x=='-')Robot.x[0][i]*=-1;
                 if(flag_ball_y=='-')Robot.y[0][i]*=-1;
                 if(flag_yellow_goal_x=='-')Robot.x[1][i]*=-1;
                 if(flag_yellow_goal_y=='-')Robot.y[1][i]*=-1;
                 if(flag_blue_goal_x=='-')Robot.x[2][i]*=-1;
                 if(flag_blue_goal_y=='-')Robot.y[2][i]*=-1;
			}

	}
//#endif // bluetooth
}

void Junior_Soccer_Simulation::sensor(int Robot_ID)
{
#if !bluetooth
	//receive(Robot_ID);
	char flag_ball_x,flag_ball_y,flag_yellow_goal_x,flag_yellow_goal_y,flag_blue_goal_x,flag_blue_goal_y;

	std::string data(Robot.receive);
	if (sizeof(data) >= 38)
		if (Robot.ID[Robot_ID] == Robot.receive[1] && teamat == Robot.receive[0])
		{

             std::istringstream cmp(data.substr(2, 3));
                 cmp >> Robot.cmp[Robot_ID];
                 std::istringstream ldr_back(data.substr(5, 4));
                 ldr_back >> Robot.ldr_back[Robot_ID];
                 std::istringstream ldr_front(data.substr(9, 4));
                 ldr_front >> Robot.ldr_front[Robot_ID];
			     std::istringstream ldr_left(data.substr(13, 4));
                 ldr_left >> Robot.ldr_left[Robot_ID];
                 std::istringstream ldr_right(data.substr(17, 4));
                 ldr_right >> Robot.ldr_right[Robot_ID];
                 std::istringstream srf_back(data.substr(21, 4));
                 srf_back >> Robot.srf_back[Robot_ID];
                 std::istringstream srf_front(data.substr(25, 4));
                 srf_front >> Robot.srf_front[Robot_ID];
                 std::istringstream srf_left(data.substr(29, 4));
                 srf_left >> Robot.srf_left[Robot_ID];
                 std::istringstream srf_right(data.substr(33, 4));
                 srf_right >> Robot.srf_right[Robot_ID];

                 std::istringstream flagball_x(data.substr(37, 1));
                 flagball_x >> flag_ball_x;
                 std::istringstream ball_x(data.substr(38, 3));
                 ball_x >> Robot.x[0][Robot_ID];

                 std::istringstream flagball_y(data.substr(41, 1));
                 flagball_y >> flag_ball_y;
                 std::istringstream ball_y(data.substr(42, 3));
                 ball_y >> Robot.y[0][Robot_ID];

                 std::istringstream flagyellow_goal_x(data.substr(45, 1));
                 flagyellow_goal_x >> flag_yellow_goal_x;
                 std::istringstream yellow_goal_x(data.substr(46, 3));
                 yellow_goal_x >> Robot.x[1][Robot_ID];

                 std::istringstream flagyellow_goal_y(data.substr(49, 1));
                 flagyellow_goal_y >> flag_yellow_goal_y;
                 std::istringstream yellow_goal_y(data.substr(50, 3));
                 yellow_goal_y >> Robot.y[1][Robot_ID];

                 std::istringstream flagblue_goal_x(data.substr(53, 1));
                 flagblue_goal_x >> flag_blue_goal_x;
                 std::istringstream blue_goal_x(data.substr(54, 3));
                 blue_goal_x >> Robot.x[2][Robot_ID];

                 std::istringstream flagblue_goal_y(data.substr(57, 1));
                 flagblue_goal_y >> flag_blue_goal_y;
                 std::istringstream blue_goal_y(data.substr(58, 3));
                 blue_goal_y >> Robot.y[2][Robot_ID];

                 if(flag_ball_x=='-')Robot.x[0][Robot_ID]*=-1;
                 if(flag_ball_y=='-')Robot.y[0][Robot_ID]*=-1;
                 if(flag_yellow_goal_x=='-')Robot.x[1][Robot_ID]*=-1;
                 if(flag_yellow_goal_y=='-')Robot.y[1][Robot_ID]*=-1;
                 if(flag_blue_goal_x=='-')Robot.x[2][Robot_ID]*=-1;
                 if(flag_blue_goal_y=='-')Robot.y[2][Robot_ID]*=-1;
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
void Junior_Soccer_Simulation::shoot(int ID)
{
	Robot.send[0] = 'k';
	Robot.send[1] = teamat;
	Robot.send[2] = '0' + ID;
	Robot.send[3] = '1';
	send_udp();
	Robot.send[3] = '0';
}
void Junior_Soccer_Simulation::spin_back(int ID,bool on)
{
	Robot.send[0] = 's';
	Robot.send[1] = teamat;
	Robot.send[2] = '0' + ID;
    Robot.send[3] = (on)? '1' : '0';
	send_udp();
}
////////////////////////////


///////////////////function
int read_cmp(int ID)
{
    return Robot.cmp[ID];
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
void motor0(int ml1, int ml2, int mr2, int mr1)
{
    Robot.motor(ml1,ml2,mr2,mr1,0);
}
void motor1(int ml1, int ml2, int mr2, int mr1)
{
    Robot.motor(ml1,ml2,mr2,mr1,1);
}



void shoot(int ID)
{
    Robot.shoot(ID);
}
void spin_back(int ID,bool on)
{
    Robot.spin_back(ID,on);
}
int read_ball_x(int ID)
{
    return Robot.x[0][ID];
}
int read_ball_y(int ID)
{
    return Robot.y[0][ID];
}
int read_yellow_goal_x(int ID)
{
    return Robot.x[1][ID];
}
int read_yellow_goal_y(int ID)
{
    return Robot.y[1][ID];
}
int read_blue_goal_x(int ID)
{
    return Robot.x[2][ID];
}
int read_blue_goal_y(int ID)
{
    return Robot.y[2][ID];
}
void delay_ms(int ms)
{
    Sleep(ms);
}
