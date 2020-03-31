/**
 * @file robot_motion_handler.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
RobotMotionHandler::RobotMotionHandler() :
  heading_angle_(0),
  speed_(0),
  max_speed_(15) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
 /**
  * @brief In this class, we can control the entity motion by the keypress up arrow, down arrow,
  * left arrow and right arrow. When the user apply the left arrow key, the robot in
  * arena will change its heading angle by 45 degrees in the direction of
  * counter-clockwise. When the user apply the right arrow key, the robot in
  * arena will change its heading angle by 45 degrees in the direction of
  * clockwise. When the user apply the up arrow key, the robot in
  * arena will increase its velocity by 1. When the user apply the down arrow key, the
  * robot in arena will decrease its velocity by 0.1.
  */
void RobotMotionHandler::AcceptCommand(enum event_commands cmd) {
  switch (cmd) {
  case COM_TURN_LEFT:
  heading_angle_ = heading_angle_ - 45;
  break;

  case COM_TURN_RIGHT:
  heading_angle_ = heading_angle_ + 45;
  break;

  case COM_SPEED_UP:
    if (speed_ == max_speed()) {
      std::cout << "We have reached the maximum value of speed.";
      speed_ = 15;
    }
    if (speed_ == 0) {
      std::cout << "The Robot is out of the power.";
      speed_ = 0;
    } else {
    speed_ = speed_ + 1;}
  break;

  case COM_SLOW_DOWN:
    if (speed_ == 0) {
     std::cout << "We have reached the minimum value of speed.";
     speed_ = 0;
    } else {
     speed_ = speed_ - 0.1;}
  break;

   default:
    std::cerr << "FATAL: bad actuator command" << std::endl;
    assert(0);
  } /* switch() */
} /* accept_command() */


/**
 * @brief In this class, we can implement the function of reducing the speed when
 * the entity bump into the obstacles and boundaries of the arena. Once the entities
 * collide, the speed of itself would decrease by 0.01. When the speed of entities
 * reach zero, the entities will stop their motion.
 */
void RobotMotionHandler::UpdateVelocity(SensorTouch st) {
  if (st.activated()) {
    heading_angle_ = - st.angle_of_contact();
    speed_ = speed_ - 0.01;
    if (speed_ <= 0) {
      speed_ = 0;
    }
  }
}

NAMESPACE_END(csci3081);
