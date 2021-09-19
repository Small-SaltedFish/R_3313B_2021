/**
 * File:func.h
 * Author:Sukanu Xian
 * Unit:Taizhou Youth&Children's Center
 * Description: This File is the Header File of the Functions that was written
 * by Sukanu for the VEX Robot which is owned by Team 3313B from Taizhou
 * Youth&Children's Center. This Project is for the VEX Robotics Competition
 * Season 2021-2022 Tipping Point.
 * CopyRight (c) 2021 Team 3313B
 * 2021.7 Zhejiang,China
 */
#ifndef _CTRL_FUNC_H_
#define _CTRL_FUNC_H_

void Ctrl_Shin(bool status);

void STOP_MOVE();

void STOP_LIFT();

void LOCK();

void move_brake(bool btn);

void Ctrl_L(int ctrl_power);

void Ctrl_R(int ctrl_power);

void Ctrl_BL(bool btn_1, bool btn_2, int ctrl_power);

void Ctrl_ML(bool btn_1, bool btn_2, int ctrl_power);

void Ctrl_FL(bool btn_1, bool btn_2, int ctrl_power);

void revctl_flag(bool btn);

void Ctrl_Move(int Axis1, int Axis2);

void Ctrl_Lift(bool Fbtn_1, bool Fbtn_2, bool Mbtn_1, bool Mbtn_2, bool Bbtn_1,
               bool Bbtn_2);

long long shin_count = 0;
bool status_bl_1 = 0, status_bl_2 = 0;
bool status_ml_1 = 0, status_ml_2 = 0;
bool status_fl_1 = 0, status_fl_2 = 0;
bool revctl_flag_1 = 0, revctl_flag_2 = 1;
bool revctl_status = 0;
bool info_status = 1;
bool brake_flag_1 = 0, brake_flag_2 = 1;
bool brake_status = 0;

const float Pi = 3.14159;
const float wd_cm = 10.6;
const float wc_cm = 33.3;
const float rd_cm = 40;
const float rc_cm = 125.6637;


void BL_Move(int auto_power, int dis_cm, float maxtime = 0);

void BL_Turn(int auto_power, int deg, float maxtime = 0);

void NBL_LF_to(int auto_power, int deg);

void NBL_LB_to(int auto_power, int deg);

void NBL_LM_to(int auto_power, int deg);

void NBL_Move(int speed, int dis_cm);

void NBL_Turn_to(int speed,int target);

#endif
