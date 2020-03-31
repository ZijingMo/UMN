/**
 * @file mobile_arena_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

#ifndef SRC_ARENA_MOBILE_ENTITY_H_
#define SRC_ARENA_MOBILE_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include "src/arena_entity.h"
#include "src/event_base_class.h"
#include "src/event_recharge.h"
#include "src/event_collision.h"
#include "src/color.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

 /**
  * @brief The class describes the feactures of mobile entities. The main judging
  * criteria is the return value of boolean verdict. It also contains different
  * motion conditions like, heading angle, speed, collision delta, the step of time
  * update, and the two accept functions. The objectives for functions are judging
  * the occurence of collision and recharging.
  */

class ArenaMobileEntity : public ArenaEntity {
 public:
  ArenaMobileEntity(double radius, double collision_delta,
                    const Position& pos, const Color& color) :
      ArenaEntity(radius, pos, color),
      collision_delta_(collision_delta) {}
  bool is_mobile(void) { return true; }
  virtual double get_heading_angle(void) const = 0;
  virtual void set_heading_angle(double heading_angle) = 0;
  virtual double get_speed(void) = 0;
  virtual void set_speed(double sp) = 0;
  double collision_delta(void) const { return collision_delta_; }
  void TimestepUpdate(uint dt);
  virtual void Accept(EventCollision * e) = 0;
  virtual void Accept(EventRecharge * e) = 0;

 private:
  double collision_delta_;
};

NAMESPACE_END(csci3081);

#endif /* SRC_ARENA_MOBILE_ENTITY_H_ */
