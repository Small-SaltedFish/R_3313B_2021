/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * Copyright (c) 2017-2021, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convienent for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "api.h"
#include <bits/stdc++.h> //Added by Sukanu

/**
 * You should add more #includes here
 */
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
using namespace pros;
using namespace std; // Added by Sukanu
// using namespace pros::literals;
//using namespace okapi;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif

void autonomous(void);

void initialize(void);

void disabled(void);

void competition_initialize(void);

void opcontrol(void);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */

//---Declare Devices---
// Ctrl
Controller Ctrl1(CONTROLLER_MASTER);
//Controller Ctrl2(CONTROLLER_PARTNER);
// Motor fwd
pros::Motor LF(12, E_MOTOR_GEARSET_18, false);
pros::Motor LB(13, E_MOTOR_GEARSET_18, false);
pros::Motor FL(15, E_MOTOR_GEARSET_18, false);
pros::Motor BL(16, E_MOTOR_GEARSET_18, false);
pros::Motor ML(14, E_MOTOR_GEARSET_18, false);
pros::Motor Ring(19, E_MOTOR_GEARSET_18, false);
// Motor rev
pros::Motor RF(17, E_MOTOR_GEARSET_18, true);
pros::Motor RB(18, E_MOTOR_GEARSET_18, true);

// Imu
Imu IS(20);

// 3-Wire LED
ADIDigitalOut LED('A');
//---Declare Devices--- Added By Sukanu

#include <iostream>
#endif

#endif // _PROS_MAIN_H_
