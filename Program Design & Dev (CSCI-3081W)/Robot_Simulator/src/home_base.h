/**
 * @file home_base.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

#ifndef SRC_HOME_BASE_H_
#define SRC_HOME_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdlib.h>
#include <string>
#include "src/robot_motion_handler.h"
#include "src/robot_motion_behavior.h"
#include "src/sensor_touch.h"
#include "src/robot_battery.h"
#include "src/arena_mobile_entity.h"
#include "src/event_recharge.h"
#include "src/event_collision.h"
#include "src/home_base_params.h"
#include "src/sensor_base_class.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 * Constructors/Destructor
 ******************************************************************************/
 /**
  * @brief The class constructs the contents of the home base. In this class, we
  * would implement the parameters of heading angle, delta angle, handler of motion,
  * behavior of motion, sensor touch and different ids. On the other hand, we need
  * to call the functions of time step update, events acceptance, environment reset
  * and the battery resets.
  * In the next, we also can call the getters and setters. The names of setters
  * and getters are name(), heading_angle(), speed(). The getters in this class
  * are id() and battery level(). In the end, we also need to put into the
  * functions to increase and decrease the heading angle.
  */
class HomeBase : public ArenaMobileEntity{
 public:
  explicit HomeBase(const struct home_base_params* const params) :
    ArenaMobileEntity(params->radius, params->collision_delta,
        params->pos, params->color),
    battery_(params->battery_max_charge),
    heading_angle_(0),
    angle_delta_(params->angle_delta),
    motion_handler_(),
    motion_behavior_(),
    sensor_touch_(),
    id_(1) {
    motion_handler_.set_heading_angle(-45);
    motion_handler_.set_speed(5);
    id_ = next_id_++;
    }
  void name(std::string hn) {home_name = hn; }
  std::string name(void) const {return home_name;}
  void HeadingAngleInc(void) { heading_angle_ += angle_delta_; }
  void HeadingAngleDec(void) { heading_angle_ -= angle_delta_; }
  double battery_level(void) { return battery_.level(); }
  double get_heading_angle(void)
  const { return motion_handler_.get_heading_angle(); }
  void set_heading_angle(double ha) { motion_handler_.set_heading_angle(ha); }
  double get_speed(void) { return motion_handler_.get_speed(); }
  void set_speed(double sp) { motion_handler_.set_speed(sp); }
  int id(void) const { return id_; }

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
 /**
 * @brief In this TimestepUpdate() funtction, we can implement the function of the
 * update the heading angle, postions, velocity. The updating of heading and speed
 * is indicated by touchsensor. We can use the velocity and position to update the
 * postions. On the other hand, given distance and speed of movenment, we can deplete
 * the battery as appropriate. I think the home base is the mobile entity in the arena
 * it has the battery as well.
 */
  void TimestepUpdate(uint dt) {
    if (randomfactors == factors) {
      randomfactors = 0;
      factors = rand() % 50;
      double direction = rand() % 360;
      motion_handler_.set_heading_angle(direction);
      motion_handler_.UpdateVelocity(sensor_touch_);
      motion_behavior_.UpdatePosition(this, dt);
    } else {
      randomfactors = randomfactors + 1;
      Position old_pos = get_pos();
      motion_handler_.UpdateVelocity(sensor_touch_);
      motion_behavior_.UpdatePosition(this, dt);
      battery_.Deplete(old_pos, get_pos(), dt);
    }
  }
 /**
 * @brief This function would trigger the action of recharge.
 */
  void Accept(__unused EventRecharge * e) {
       battery_.EventRecharge();
     }
 /**
 * @brief This function would trigger the event of collision.
 */
  void Accept(EventCollision * e) {
      sensor_touch_.Accept(e);
    }
 /**
 * @brief The home base will be reseted at the initial postion and
 * speed. If the user is the winner, this function would reset the
 * name of the home base to the initial name.
 */
  void Reset(void) {
      battery_.Reset();
      motion_handler_.Reset();
      sensor_touch_.Reset();
      set_pos(Position(400, 400));
      name("Home Base");
    }
 /**
 * @brief Reset the home base's battery.
 */
  void ResetBattery(void) {
       battery_.Reset();
     }

 private:
  double heading_angle_;
  double angle_delta_;
  SensorTouch sensor_touch_;
  int id_;
  uint next_id_ = 0;
  RobotBattery battery_;
  RobotMotionHandler motion_handler_;
  RobotMotionBehavior motion_behavior_;
  std::string home_name = "Home Base";
  double randomfactors = 0;
  double factors = rand() % 50;
};



NAMESPACE_END(csci3081);

#endif    /* SRC_HOME_BASE_H_ */
