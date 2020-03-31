/**
 * @file robot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot.h"
#include "src/robot_motion_behavior.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Static Variables
 ******************************************************************************/
uint Robot::next_id_ = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Robot::Robot(const struct robot_params* const params) :
  ArenaMobileEntity(params->radius, params->collision_delta,
  params->pos, params->color),
  battery_(params->battery_max_charge),
  heading_angle_(0),
  angle_delta_(params->angle_delta),
  motion_handler_(),
  motion_behavior_(),
  sensor_touch_(),
  id_(-1) {
  motion_handler_.set_heading_angle(270);
  motion_handler_.set_speed(5);
  id_ = next_id_++;
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
* @brief In this TimestepUpdate() funtction, we can implement the function of the
* update the heading angle, postions, velocity. The updating of heading and speed
* is indicated by touchsensor. We can use the velocity and position to update the
* postions. On the other hand, given distance and speed of movenment, we can deplete
* the battery as appropriate.
*/
void Robot::TimestepUpdate(uint dt) {
  Position old_pos = get_pos();
  motion_handler_.UpdateVelocity(sensor_touch_);
  motion_behavior_.UpdatePosition(this, dt);
  battery_.Deplete(old_pos, get_pos(), dt);
}

/**
* @brief This function passes along a recharge event.
*/

void Robot::Accept(__unused EventRecharge * e) {
  battery_.EventRecharge();
}

/**
* @brief This function passes along a collision event (from arena) to the touch sensor.
*/
void Robot::Accept(EventCollision * e) {
  sensor_touch_.Accept(e);
}

/**
* @brief The motion of robot will be controlled by the input of the keyboards.
*/

// User input commands to change heading or speed
void Robot::EventCmd(enum event_commands cmd) {
  motion_handler_.AcceptCommand(cmd);
} /* event_cmd() */

/**
* @brief The robot will be reseted at the initial postion and speed. If the user
* is the loser, this function would reset the name of the robot to the initial name.
*/
void Robot::Reset(void) {
  battery_.Reset();
  motion_handler_.Reset();
  sensor_touch_.Reset();
  set_pos(Position(500, 500));
  name("Robot" + std::to_string(id()));
}

/**
* @brief Reset the robot's battery.
*/

void Robot::ResetBattery(void) {
  battery_.Reset();
}

NAMESPACE_END(csci3081);
