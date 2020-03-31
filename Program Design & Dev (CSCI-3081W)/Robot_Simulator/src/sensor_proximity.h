/**
 * @file sensor_proximity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

#ifndef SRC_SENSOR_PROXIMITY_H_
#define SRC_SENSOR_PROXIMITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <vector>
#include <utility>
#include "src/position.h"
#include "src/sensor_base_class.h"
#include "src/event_collision.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
class ArenaEntity;

/**
 * @brief A representation of a sensor proximity.
 *
 */
class SensorProximity : public SensorBaseClass{
 public:
  SensorProximity();

  void EmitMessage(void) { printf("This is a Sensor Proximity!\n");}
  /**
  * @brief
  */

  bool activated(void) { return activated_; }
  void activated(bool value) { activated_ = value; }

  Position point_of_contact() { return point_of_sensor_proximity_; }
  void point_of_contact(Position p) {
    point_of_sensor_proximity_.x = p.x;
    point_of_sensor_proximity_.y = p.y;
  }

  double angle_of_contact(void) { return angle_of_sensor_proximity_; }
  void angle_of_contact(double aosp) { angle_of_sensor_proximity_; }

  void InRange(void);

  void SensorView(void);

  void Accept(EventCollision * e);

  void Reset(void);

 private:
  bool activated_;
  Position point_of_sensor_proximity_;
  double angle_of_sensor_proximity_;
};

  NAMESPACE_END(csci3081);

  #endif   /* SRC_SENSOR_PROXIMITY_H_ */
