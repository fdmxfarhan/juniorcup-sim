// robot.h - #version 1.1
//
// Copyright (c) 2021-2020 JuniorCup
//
// Distributed under the Iran Robotic Academy Software License
// See accompanying file at
// http://www.iranroboticacademy.com/
//
// The documentation can be found at the library's page:
// http://juniorcup.ir/
//
// =================================================================================================
// =================================================================================================
// =================================================================================================
//
// - C++ Code Write by Mohammad Hossein Zolfaghari
// - Simulation Write by Farhan daemi
//
// =================================================================================================
// =================================================================================================
// =================================================================================================
#ifndef ROBOT_H
#define ROBOT_H


#define number_of_teamat_robot 2
#define max_buffer_size 63
#define teamat 'a'//'a' OR 'b'
#define bluetooth TRUE
#define print_send_data_on_console FALSE
#define print_recive_data_on_console FALSE
///////
/*the signicher 1 is ball placement*/
/*the signicher 2 is yellow goal placement*/
/*the signicher 3 is blue goal placement*/
#define signicher_number 3
class Junior_Soccer_Simulation
{
public:
     ////settings
	 int port = 3000;
	 int sendToPort = 8000;
	 bool sending = true;
	 char send[30];
	 char ID[2] = { '0','1' };
	 char receive_hsb = teamat;
	 char receive[max_buffer_size];
	 ///////////

	 ////sensor

	 int x[signicher_number][number_of_teamat_robot];
	 int y[signicher_number][number_of_teamat_robot];
	 int cmp[number_of_teamat_robot];
	 int ldr_left[number_of_teamat_robot];
	 int ldr_right[number_of_teamat_robot];
	 int ldr_front[number_of_teamat_robot];
	 int ldr_back[number_of_teamat_robot];
	 int srf_left[number_of_teamat_robot];
	 int srf_right[number_of_teamat_robot];
	 int srf_front[number_of_teamat_robot];
	 int srf_back[number_of_teamat_robot];
	 ////////////

	 /////////////Robot
     void sensor(int Robot_ID);
     void sensor(void);
     void motor(int ml1, int ml2, int mr2, int mr1,int robot_number);
     void shoot(int ID);
     void spin_back(int ID,bool on);
     //////////////////

     /////simulation
     void Robot_Init(void);
     bool InitializeSockets();
     void ShutdownSockets(void);
     void CreateSocket(void);
     void SendPacket(const char data[], const int len);
     void ReceivePackets(void);
     bool ParseCmdLine(int argc, char** argv);
     void send_udp(void);
     void receive_udp(int Robot_ID);
     ////////////////

private:

};
extern Junior_Soccer_Simulation Robot;


///////////////function
void shoot(int ID);
void spin_back(int ID,bool on);
int read_ball_x(int ID);
int read_ball_y(int ID);
int read_yellow_goal_x(int ID);
int read_yellow_goal_y(int ID);
int read_blue_goal_x(int ID);
int read_blue_goal_y(int ID);
int read_cmp(int ID);
int read_ldr_l(int ID);
int read_ldr_r(int ID);
int read_ldr_b(int ID);
int read_ldr_f(int ID);
int read_distance_b(int ID);
int read_distance_f(int ID);
int read_distance_r(int ID);
int read_distance_l(int ID);
void motor0(int ml1, int ml2, int mr2, int mr1);
void motor1(int ml1, int ml2, int mr2, int mr1);
void delay_ms(int ms);


#endif
