#include "main.h"

using namespace GirlPowered;

void drivetrain_controller() {
    double rightXjoystick = (controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)); // Axis 1
    double rightYjoystick = (controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)); // Axis 2
    double leftYjoystick  = (controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)); // Axis 3
    double leftXjoystick  = (controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X)); // Axis 4
    if(fabs(leftYjoystick) < 10) leftYjoystick = 0;
    if(fabs(rightYjoystick) < 10) rightYjoystick = 0;

    int32_t left = (rightXjoystick + leftYjoystick) * (12000.0 / 127);
    int32_t right = (leftYjoystick - rightXjoystick) * (12000.0 / 127);
    util.move_left_motors(left);
    util.move_right_motors(right);
}

void arm_controller(int speed) {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        util.move_arm_motors(speed * (12000.0 / 127));
    } else if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1))){
        util.move_arm_motors(-speed * (12000.0 / 127));
    } 
    else { util.move_arm_motors(0); }
}

void claw_controller(int speed) {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        util.move_claw_motors(speed * (12000.0 / 127));
    } else if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))){
        util.move_claw_motors(-speed * (12000.0 / 127));
    } 
    else { util.move_claw_motors(0); }
}