/**
 * @file robot_battery.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "src/robot_battery.h"
#include <cmath>
#include <iostream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/** @brief deplete battery by some value based on movement and speed. The value
* of loss depends on the linear change. From the pos() function, we can know the
* x-value and y-value of the mobile entity in the arena. The values of
* kBASE_DEPLETION and kLINEAR_SCALE_FACTOR are known, we get the the change vaule
* of the charge.
*/
double RobotBattery::Deplete(__unused Position old_pos,
  __unused Position new_pos, __unused double dt) {
  charge_ -= kBASE_DEPLETION*dt;
  sqnum = pow((new_pos.x - old_pos.x), 2) + pow((new_pos.y - old_pos.y), 2);
  charge_ = charge_ - (sqrt(sqnum)/dt * kLINEAR_SCALE_FACTOR);
  if (charge_ <= 0) {
     charge_ = 0;
  }
  return charge_;
}

void Accept(__unused EventCollision * e) {
  /* @brief deplete battery by some value -- arbitrary selected for bumping */
}

NAMESPACE_END(csci3081);
