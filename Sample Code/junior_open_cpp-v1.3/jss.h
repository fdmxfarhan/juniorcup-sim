// ======================================================================
// == DO NOT MODIFY THIS FILE BY HAND
// ======================================================================
//
// sokcet_udp.h - #version 1.1
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
#ifndef jss_H
#define jss_H
#include "robot.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "socket_udp.h"
#include <sstream>
void sensor(int Robot_ID);
void sensor(void);
void motor(int ml1, int ml2, int mr2, int mr1,int robot_number);
#endif
