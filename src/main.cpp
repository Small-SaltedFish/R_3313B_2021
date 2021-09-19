/**
 * File:main.cpp
 * Author:Sukanu Xian
 * Unit:Taizhou Youth&Children's Center
 * Description: This File is the main function for the VEX Robot which is owned
 * by Team 3313B from Taizhou Youth&Children's Center. This Project is for the
 * VEX Robotics Competition Season 2021-2022 Tipping Point.
 * CopyRight (c) 2021 Team 3313B
 * 2021.7 Zhejiang,China
 */

#include "main.h" //PROS官方API&OKAPI
#include "func.h" //自有函数头文件 如果有新函数常量需要到这里声明 文件路径:include/func.h

//--Competition Function Start--
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  LOCK();                             //程序初始化函数
  LF.set_encoder_units(E_MOTOR_ENCODER_DEGREES); //设置电机计量度数
  LB.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  RF.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  RB.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  FL.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  BL.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  ML.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  LF.set_zero_position(0); //初始化电机数为0
  LB.set_zero_position(0);
  RF.set_zero_position(0);
  RB.set_zero_position(0);
  FL.set_zero_position(0);
  BL.set_zero_position(0);
  ML.set_zero_position(0);
  Ring.set_zero_position(0);
  IS.set_heading(0);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() { //禁用时函数
  // setBrakeModeToHold();
  LOCK();
  while (1) {
    Ctrl_Shin(1); //禁用时闪烁LED灯
  }
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {} //竞赛时初始化函数 可用于程序选择器

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	NBL_LB_to(127,1200);
  BL_Move(-127,105);
  NBL_LB_to(127,500);
  BL_Move(127, 80);
  NBL_Turn_to(200, -115);
  NBL_LF_to(127,-1200);
  delay(1000);
  NBL_Move(100, 65);
  delay(1800);
  //
  NBL_LF_to(127,-600);
  delay(1000);
  /**
  BL_Move(127, 10);
  delay(200);
  BL_Move(-127, 30);
  delay(100);
  NBL_LM_to(200, -320);
  NBL_LB_to(127,1200);
  delay(300);
  NBL_LF_to(127, 0);
  delay(500);
  NBL_LM_to(200, -400);
  NBL_LF_to(127, -200);
  delay(500);
  NBL_LF_to(127, 0);
  delay(500);
  Ring.move_absolute(1000, 100);
  delay(700);
  Ring.move(-80);
  delay(300);
  Ring.move_absolute(1000, 100);
  delay(400);
  Ring.move(-80);
  delay(300);
  Ring.move_absolute(1100, 100);
  delay(600);
  Ring.move_absolute(0, 100);
  NBL_LB_to(127,500);
  delay(500);
  BL_Move(127,30);
  delay(1000);
  BL_Move(-127,40);
  LOCK();
  **/
  BL_Move(-127, 40);
  delay(1800);
  LOCK();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() { //手动时函数
  Ctrl_Shin(0);    // LED停止闪烁
  STOP_LIFT();     //设置抬升电机停止状态
  while (1) {
    move_brake(Ctrl1.get_digital(E_CONTROLLER_DIGITAL_X)); //设置切换抱死按钮
    revctl_flag(Ctrl1.get_digital(E_CONTROLLER_DIGITAL_Y)); //设置切换方向按钮
    Ctrl_Move(Ctrl1.get_analog(E_CONTROLLER_ANALOG_LEFT_Y), //设置前后移动摇杆
              Ctrl1.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
    Ctrl_Lift(Ctrl1.get_digital(E_CONTROLLER_DIGITAL_L1), //设置抬升按钮
              Ctrl1.get_digital(E_CONTROLLER_DIGITAL_L2),
              Ctrl1.get_digital(E_CONTROLLER_DIGITAL_B),
              Ctrl1.get_digital(E_CONTROLLER_DIGITAL_A),
              Ctrl1.get_digital(E_CONTROLLER_DIGITAL_R1),
              Ctrl1.get_digital(E_CONTROLLER_DIGITAL_R2));
    if (Ctrl1.get_digital(E_CONTROLLER_DIGITAL_UP)) { //设置方向键
      Ctrl_Move(100, 100);
    }
    if (Ctrl1.get_digital(E_CONTROLLER_DIGITAL_DOWN)) {
      Ctrl_Move(-100, -100);
    }
    if (Ctrl1.get_digital(E_CONTROLLER_DIGITAL_LEFT)) {
      Ctrl_Move(-100, 100);
    }
    if (Ctrl1.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) {
      Ctrl_Move(100, -100);
    }
    delay(10); //十毫秒闪烁一次LED&采集数据
  }
}

//--Competition Function End--

// Ctrl Functions

// Status:bool,true or false.
void Ctrl_Shin(bool status) { //控制闪烁函数 true打开 false关闭
  shin_count++;
  if (status) {
    if (shin_count % 10 == 0) {
      LED.set_value(0);
    }
    if (shin_count % 10 == 5) {
      LED.set_value(1);
    }
  } else {
    LED.set_value(1);
  }
}

void STOP_MOVE() { //刹车函数
  LF.move(0);
  LB.move(0);
  RF.move(0);
  RB.move(0);
  LF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  LB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  RF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  RB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
}

void LOCK_MOVE() { //移动抱死
  LF.move(0);
  LB.move(0);
  RF.move(0);
  RB.move(0);
  LF.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  LB.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  RF.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  RB.set_brake_mode(E_MOTOR_BRAKE_HOLD);
}

void STOP_LIFT() { //抬升抱死
  FL.move(0);
  ML.move(0);
  BL.move(0);
  FL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  ML.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  BL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
}

void LOCK() { //全部抱死
  LOCK_MOVE();
  STOP_LIFT();
}

// btn:bool,true or false.
void move_brake(bool btn) { //切换抱死状态
  if (btn) {
    if (brake_flag_1 == 1) {
      brake_flag_2 = 1;
      brake_status = false;
    } else {
      brake_flag_2 = 0;
      brake_status = true;
    }
  } else {
    if (brake_flag_2 == 1) {
      brake_flag_1 = 0;
      brake_status = false;
    } else {
      brake_flag_1 = 1;
      brake_status = true;
    }
  }
  if (brake_status == 1) {
    RF.set_brake_mode(E_MOTOR_BRAKE_HOLD); //抱死
    RB.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    LF.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    LB.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  } else {
    RF.set_brake_mode(E_MOTOR_BRAKE_COAST); //放开
    RB.set_brake_mode(E_MOTOR_BRAKE_COAST);
    LF.set_brake_mode(E_MOTOR_BRAKE_COAST);
    LB.set_brake_mode(E_MOTOR_BRAKE_COAST);
  }
}

// ctrl_power:int,-127~127.
void Ctrl_L(int ctrl_power) { //左边电压设置
  LF.move(ctrl_power);
  LB.move(ctrl_power);
}

// ctrl_power:int,-127~127.
void Ctrl_R(int ctrl_power) { //右边电压设置
  RF.move(ctrl_power);
  RB.move(ctrl_power);
}

// btn_1:bool,true or false.
// btn_2:bool,true or false.
// ctrl_power:int,-127~127.
void Ctrl_BL(bool btn_1, bool btn_2, int ctrl_power) { //后抬函数
  ctrl_power = abs(ctrl_power); //防止错误 进行绝对值
  /**
  if (BL.get_position() <= 100) { //若后抬低于100度 只允许下降 不允许上升
    if (status_bl_1 == 0)
      cout << "Warning:BL has been Locked.Because it is too high." << endl;
    status_bl_1 = 1;
    if (btn_2) {
      BL.move(ctrl_power);
    } else {
      BL.move(0);
    }
  } else if (BL.get_position() >=
             1300) { //若后抬高于1300度 只允许上升 不允许下降
    if (status_bl_2 == 0)
      cout << "Warning:BL has been Locked.Because it is too low." << endl;
    status_bl_2 = 1;
    if (btn_1) {
      BL.move(-ctrl_power);
    } else {
      BL.move(0);
    }
  } else {
    status_bl_1 = 0;
    status_bl_2 = 0;
    if (btn_1) {
      BL.move(-ctrl_power);
    } else {
      if (btn_2) {
        BL.move(ctrl_power);
      } else {
        BL.move(0);
      }
    }
  }
  */
  if(btn_1){
    BL.move(-ctrl_power);
  }else{
    if(btn_2){
      BL.move(ctrl_power);
    }else{
      BL.move(0);
    }
  }
}

// btn_1:bool,true or false.
// btn_2:bool,true or false.
// ctrl_power:int,-127~127.
void Ctrl_ML(bool btn_1, bool btn_2, int ctrl_power) { //中抬函数 同上理
  ctrl_power = abs(ctrl_power);
  /**
  if (ML.get_position() >= 300) {
    if (status_ml_1 == 0)
      cout << "Warning:ML_M has been Locked.Because it is too high." << endl;
    status_ml_1 = 1;
    if (btn_2) {
      ML.move(-ctrl_power);
    } else {
      ML.move(0);
    }
  } else if (ML.get_position() <= -300) {
    if (status_ml_2 == 0)
      cout << "Warning:ML_M has been Locked.Because it is too low." << endl;
    status_ml_2 = 1;
    if (btn_1) {
      ML.move(ctrl_power);
    } else {
      ML.move(0);
    }
  } else {
    status_ml_1 = 0;
    status_ml_2 = 0;
    if (btn_1) {
      ML.move(ctrl_power);
    } else {
      if (btn_2) {
        ML.move(-ctrl_power);
      } else {
        ML.move(0);
      }
    }
  }
  */
  if(btn_1){
    ML.move(ctrl_power);
  }else{
    if(btn_2){
      ML.move(-ctrl_power);
    }else{
      ML.move(0);
    }
  }
}

// btn_1:bool,true or false.
// btn_2:bool,true or false.
// ctrl_power:int,-127~127.
void Ctrl_FL(bool btn_1, bool btn_2, int ctrl_power) { //前抬函数 同上理
  ctrl_power = abs(ctrl_power);
  /**
  if (FL.get_position() >= -100) {
    if (status_fl_1 == 0)
      cout << "Warning:FL_M has been Locked.Because it is too high." << endl;
    status_fl_1 = 1;
    if (btn_2) {
      FL.move(-ctrl_power);
    } else {
      FL.move(0);
    }
  } else if (FL.get_position() <= -1300) {
    if (status_fl_2 == 0)
      cout << "Warning:FL_M has been Locked.Because it is too low." << endl;
    status_fl_2 = 1;
    if (btn_1) {
      FL.move(ctrl_power);
    } else {
      FL.move(0);
    }
  } else {
    status_fl_1 = 0;
    status_fl_2 = 0;
    if (btn_1) {
      FL.move(ctrl_power);
    } else {
      if (btn_2) {
        FL.move(-ctrl_power);
      } else {
        FL.move(0);
      }
    }
  }
  */
  if(btn_1){
    FL.move(ctrl_power);
  }else{
    if(btn_2){
      FL.move(-ctrl_power);
    }else{
      FL.move(0);
    }
  }
}

// btn:bool,true or false.
void revctl_flag(bool btn) { //换向函数
  if (btn) {
    if (revctl_flag_1 == 1) {
      revctl_flag_2 = 1;
      revctl_status = false;
    } else {
      revctl_flag_2 = 0;
      revctl_status = true;
    }
  } else {
    if (revctl_flag_2 == 1) {
      revctl_flag_1 = 0;
      revctl_status = false;
    } else {
      revctl_flag_1 = 1;
      revctl_status = true;
    }
  }
}

// Axis1:int,-127~127.
// Axis2:int,-127~127.
void Ctrl_Move(int Axis1, int Axis2) { //摇杆整体移动函数
  if (revctl_status == false) {
    Ctrl_L(Axis1);
    Ctrl_R(Axis2);
    Ctrl_Shin(false);
    if (info_status)
      cout << "Info:Direction is forward now." << endl;
    info_status = 0;
  }
  if (revctl_status == true) {
    Ctrl_L(-Axis2);
    Ctrl_R(-Axis1);
    Ctrl_Shin(true);
    if (info_status == 0)
      cout << "Info:Direction is reverse now." << endl;
    info_status = 1;
  }
}

// btn*:bool,true or false.
void Ctrl_Lift(bool Fbtn_1, bool Fbtn_2, bool Mbtn_1, bool Mbtn_2, bool Bbtn_1,
               bool Bbtn_2) { //按钮整体抬升函数
  Ctrl_ML(Mbtn_1, Mbtn_2, 127);
  if (revctl_status == false) {
    Ctrl_FL(Fbtn_1, Fbtn_2, 127);
    Ctrl_BL(Bbtn_1, Bbtn_2, 127);
  }
  if (revctl_status == true) {
    Ctrl_FL(Bbtn_1, Bbtn_2, 127);
    Ctrl_BL(Fbtn_1, Fbtn_2, 127);
  }
}

// Autonomous Functions

// auto_power:int,-127~127.
// dis_cm:int,*.
// maxtime:float,>=0.
void BL_Move(int auto_power, int dis_cm,
             float maxtime) { // Block Move 只能运行单一动作的移动函数
                              // 在未结束动作时 程序不会继续运行
  dis_cm = abs(dis_cm);
  if (auto_power == 0) {
    STOP_MOVE();
  } else {
    if (auto_power > 0) {
      float counter = 0, goal_counter = maxtime / 0.02;
      float spindeg = dis_cm / wc_cm * 360;
      float nowdeg = LF.get_position();
      float goaldeg = nowdeg + spindeg;
      if (maxtime == 0) {
        while (1) {
          nowdeg = LF.get_position();
          if (nowdeg >= goaldeg) {
            Ctrl_Move(0, 0);
            break;
          } else {
            Ctrl_Move(auto_power, auto_power);
          }
          delay(2);
        }
      } else {
        while (counter <= goal_counter) {
          nowdeg = LF.get_position();
          counter++;
          if (nowdeg >= goaldeg) {
            Ctrl_Move(0, 0);
            break;
          } else {
            Ctrl_Move(auto_power, auto_power);
          }
          delay(2);
        }
      }
    } else {
      float counter = 0, goal_counter = maxtime / 0.02;
      float spindeg = dis_cm / wc_cm * 360;
      float nowdeg = LF.get_position();
      float goaldeg = nowdeg - spindeg;
      if (maxtime == 0) {
        while (1) {
          nowdeg = LF.get_position();
          if (nowdeg <= goaldeg) {
            Ctrl_Move(0, 0);
            break;
          } else {
            Ctrl_Move(auto_power, auto_power);
          }
          delay(2);
        }
      } else {
        while (counter <= goal_counter) {
          nowdeg = LF.get_position();
          counter++;
          if (nowdeg <= goaldeg) {
            Ctrl_Move(0, 0);
            break;
          } else {
            Ctrl_Move(auto_power, auto_power);
          }
          delay(2);
        }
      }
    }
  }
}

// auto_power:int,-127~127.
// deg:int,>=0&&<=360.
// maxtime:float,>=0.
void BL_Turn(int auto_power, int deg,
             float maxtime) { // Block Turn 只能运行单一动作的相对旋转函数
                              // 动作未结束 程序不会继续运行
  deg = abs(deg);
  if (auto_power == 0) {
    STOP_MOVE();
  } else {
    if (auto_power > 0) {
      int is360 = 0;
      float counter = 0, goal_counter = maxtime / 0.02;
      float recdeg = IS.get_heading() - 0.5;
      float nowdeg = IS.get_heading();
      float goaldeg = nowdeg + deg;
      if (goaldeg > 360) {
        goaldeg = goaldeg - 360;
        is360 = 1;
      }
      if (maxtime == 0) {
        while (1) {
          cout << IS.get_heading();
          nowdeg = IS.get_heading();
          cout << " " << goaldeg << endl;
          if (is360) {
            if (nowdeg >= goaldeg && nowdeg < recdeg) {
              STOP_MOVE();
              break;
            } else {
              Ctrl_L(auto_power);
              Ctrl_R(-auto_power);
            }
          } else {
            if (nowdeg >= goaldeg) {
              STOP_MOVE();
              break;
            } else {
              Ctrl_L(auto_power);
              Ctrl_R(-auto_power);
            }
          }
          delay(2);
        }
      } else {
        while (counter <= goal_counter) {
          cout << IS.get_heading();
          nowdeg = IS.get_heading();
          cout << " " << goaldeg << endl;
          counter++;
          if (is360) {
            if (nowdeg >= goaldeg && nowdeg < recdeg) {
              STOP_MOVE();
              break;
            } else {
              Ctrl_L(auto_power);
              Ctrl_R(-auto_power);
            }
          } else {
            if (nowdeg >= goaldeg) {
              STOP_MOVE();
              break;
            } else {
              Ctrl_L(auto_power);
              Ctrl_R(-auto_power);
            }
          }
          delay(2);
        }
      }
    } else {
      int is360 = 0;
      float counter = 0, goal_counter = maxtime / 0.02;
      float nowdeg = IS.get_heading();
      float recdeg = IS.get_heading() + 0.5;
      float goaldeg = nowdeg - deg;
      if (goaldeg < 0) {
        goaldeg = goaldeg + 360;
        is360 = 1;
      }
      if (maxtime == 0) {
        while (1) {
          cout << IS.get_heading();
          nowdeg = IS.get_heading();
          cout << " " << goaldeg << endl;
          if (is360) {
            if (nowdeg > recdeg && nowdeg <= goaldeg) {
              STOP_MOVE();
              break;
            } else {
              Ctrl_L(auto_power);
              Ctrl_R(-auto_power);
            }
          } else {
            if (nowdeg <= goaldeg) {
              STOP_MOVE();
              break;
            } else {
              Ctrl_L(auto_power);
              Ctrl_R(-auto_power);
            }
          }
          delay(2);
        }
      } else {
        while (counter <= goal_counter) {
          cout << IS.get_heading();
          nowdeg = IS.get_heading();
          cout << " " << goaldeg << endl;
          counter++;
          if (is360) {
            if (nowdeg > recdeg && nowdeg <= goaldeg) {
              STOP_MOVE();
              break;
            } else {
              Ctrl_L(auto_power);
              Ctrl_R(-auto_power);
            }
          } else {
            if (nowdeg <= goaldeg) {
              STOP_MOVE();
              break;
            } else {
              Ctrl_L(auto_power);
              Ctrl_R(-auto_power);
            }
          }
          delay(2);
        }
      }
    }
  }
}

// auto_power:int,-127~127.
// deg:int,-1300~-100.
void NBL_LF_to(
    int auto_power,
    int deg) { // No Block 不会阻止程序运行的前抬函数 绝对运动 有取值范围
  auto_power = auto_power / 127 * 200;
  FL.move_absolute(deg, auto_power);
}

// auto_power:int,-127~127.
// deg:int,1300~100.
void NBL_LB_to(
    int auto_power,
    int deg) { // No Block 不会阻止程序运行的后抬函数 绝对运动 有取值范围
  auto_power = auto_power / 127 * 200;
  BL.move_absolute(deg, auto_power);
}

// auto_power:int,-127~127.
// deg:int,300~-300.
void NBL_LM_to(
    int auto_power,
    int deg) { // No Block 不会阻止程序运行的中抬函数 绝对运动 有取值范围
  auto_power = abs(auto_power / 127 * 200);
  ML.move_absolute(deg, auto_power);
}

// speed:int,-200~200
// dis_cm:int,*
void NBL_Move(int speed, int dis_cm) { // No Block 不会阻止程序运行的移动函数
  speed = abs(speed);
  int deg = dis_cm / wc_cm * 360;
  LF.move_relative(deg, speed);
  RB.move_relative(deg, speed);
  LB.move_relative(deg, speed);
  RF.move_relative(deg, speed);
}

// speed:int,-200~200
// goaldeg:int,0-360
void NBL_Turn_to(int speed,
                 int target) { // No Block 不会阻止程序运行的绝对旋转函数
  speed = abs(speed);
  int now = IS.get_heading();
  int deg = 0;
  if (target > now) {
    deg = target - now;
  } else if (target <= now) {
    deg = -(now - target);
  }
  if (abs(deg) > (360 - abs(deg))) {
    if (deg > 0) {
      deg = -(360 - abs(deg));
    } else {
      deg = 360 - abs(deg);
    }
  }
  float mfdeg = deg / 360.0 * rc_cm / wc_cm * 360.0;
  int mdeg = (int)mfdeg;
  LF.move_relative(mdeg, speed);
  RB.move_relative(-mdeg, speed);
  LB.move_relative(mdeg, speed);
  RF.move_relative(-mdeg, speed);
}
