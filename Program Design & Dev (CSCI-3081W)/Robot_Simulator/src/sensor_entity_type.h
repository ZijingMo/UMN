/**
 * @file sensor_entity_type.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */
#ifndef SRC_SENSOR_ENTITY_TYPE_H_
#define SRC_SENSOR_ENTITY_TYPE_H_

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
 * @brief A representation of a sensor entity type.
 */
class SensorEntityType : public SensorBaseClass{
 public:
  SensorEntityType();
  void EmitMessage(void) { printf("This is a Sensor Entity Type!\n");}
  /**
  * @brief
  */
  bool activated(void) { return activated_; }
  void activated(bool value) { activated_ = value; }

  Position point_of_contact() { return point_of_sensor_entity_type_; }
  void point_of_contact(Position p) {
    point_of_sensor_entity_type_.x = p.x;
    point_of_sensor_entity_type_.y = p.y;
  }

  void Accept(EventCollision * e);

  void Reset(void);



private:
 bool activated_;
 Position point_of_sensor_entity_type_;
 double angle_of_sensor_entity_type_;
 };

NAMESPACE_END(csci3081);
#endif   /* SRC_SENSOR_DISTRESS_H_ */
