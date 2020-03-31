/**
 * @file robot.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/robot_motion_handler.h"
#include "src/robot_motion_behavior.h"
#include "src/sensor_touch.h"
#include "src/sensor_base_class.h"
#include "src/robot_battery.h"
#include "src/arena_mobile_entity.h"
#include "src/event_recharge.h"
#include "src/event_collision.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

 /**
  * @brief The class constructs the contents of the Robot. In this class, we
  * would implement the parameters of heading angle, delta angle, handler of motion,
  * behavior of motion, sensor touch and different ids. On the other hand, we need
  * to call the functions of time step update, events acceptance, environment reset
  * and the battery resets.
  * In the next, we also can call the getters and setters. The names of setters
  * and getters are name(), heading_angle(), speed(). The getters in this class
  * are id() and battery level(). In the end, we also need to put into the
  * functions to increase and decrease the heading angle. The function of EventCmd
  * contols the motion of Robot.
  */

class Robot : public ArenaMobileEntity {
 public:
  explicit Robot(const struct robot_params* const params);

  void ResetBattery(void);
  void Reset(void);
  void HeadingAngleInc(void) { heading_angle_ += angle_delta_; }
  void HeadingAngleDec(void) { heading_angle_ -= angle_delta_; }
  void TimestepUpdate(unsigned int dt);
  void Accept(EventRecharge * e);
  void Accept(EventCollision * e);
  void EventCmd(enum event_commands cmd);

  double get_battery_level(void) { return battery_.level(); }
  double get_heading_angle(void)
  const { return motion_handler_.get_heading_angle(); }
  void set_heading_angle(double ha) { motion_handler_.set_heading_angle(ha); }
  double get_speed(void) { return motion_handler_.get_speed(); }
  void set_speed(double sp) { motion_handler_.set_speed(sp); }
  int id(void) const { return id_; }

  void name(std::string rn) {robot_name = rn; }
  std::string name(void) const {return robot_name;}


 private:
  static unsigned int next_id_;

  int id_;
  double heading_angle_;
  double angle_delta_;
  RobotBattery battery_;
  RobotMotionHandler motion_handler_;
  RobotMotionBehavior motion_behavior_;
  SensorTouch sensor_touch_;
  std::string robot_name = "Robot" + std::to_string(id());
};

NAMESPACE_END(csci3081);

#endif /* SRC_ROBOT_H_ */
