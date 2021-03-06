/**
 * @file arena.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "src/arena.h"
#include <math.h>
#include <algorithm>
#include "src/robot.h"
#include "src/home_base.h"
#include "src/obstacle.h"
#include "src/event_collision.h"
#include "src/arena_params.h"
#include "src/recharge_station.h"
#include "src/event_recharge.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Arena::Arena(const struct arena_params* const params) :
  x_dim_(params->x_dim), y_dim_(params->y_dim),
  robot_(new Robot(&params->robot)),
  n_robots_(1),
  n_obstacles_(params->n_obstacles),
  recharge_station_(new RechargeStation(params->recharge_station.radius,
  params->recharge_station.pos,
  params->recharge_station.color)),
  home_base_(new HomeBase(&params->home_base)),
  entities_(),
  mobile_entities_() {
  robot_->set_heading_angle(37);
  entities_.push_back(robot_);
  mobile_entities_.push_back(robot_);

  entities_.push_back(recharge_station_);

  entities_.push_back(home_base_);
  mobile_entities_.push_back(home_base_);

  for (size_t i = 0; i < n_obstacles_; ++i) {
    entities_.push_back(new Obstacle(
        params->obstacles[i].radius,
        params->obstacles[i].pos,
        params->obstacles[i].color));
  } /* for(i..) */
}

Arena::~Arena(void) {
  for (auto ent : entities_) {
    delete ent;
  }
}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
* @brief This function is the virtual function. All the functions of reset would
* overwrite this function.
*/
void Arena::Reset(void) {
  for (auto ent : entities_) {
    ent->Reset();
  } /* for(ent..) */
} /* reset() */

std::vector<Obstacle*> Arena::obstacles(void) {
  std::vector<Obstacle*> res;
  for (auto ent : entities_) {
    Obstacle* o = dynamic_cast<Obstacle*>(ent);
    if (o) {
      res.push_back(o);
    }
  } /* for(ent..) */
  return res;
} /* robots() */

void Arena::AdvanceTime(void) {
  std::cout << "Advancing simulation time by 1 timestep\n";
  UpdateEntitiesTimestep();
} /* AdvanceTime() */

void Arena::UpdateEntitiesTimestep(void) {
  /*
   * First, update the position of all entities, according to their current
   * velocities.
   */
  for (auto ent : entities_) {
    ent->TimestepUpdate(1);
  } /* for(ent..) */

  /*
   * The battery of robot will gradually change by its battery level.
   */

  if (robot_->get_battery_level() <= 100) {
       robot_-> set_color(csci3081::Color(0, 0, 255, 255));
  }

  if (robot_->get_battery_level() <= 80) {
       robot_-> set_color(csci3081::Color(0, 40, 255, 255));
  }

  if (robot_->get_battery_level() <= 60) {
       robot_-> set_color(csci3081::Color(0, 80, 255, 255));
  }

  if (robot_->get_battery_level() <= 40) {
       robot_-> set_color(csci3081::Color(0, 120, 255, 255));
  }

  if (robot_->get_battery_level() <= 20) {
       robot_-> set_color(csci3081::Color(0, 160, 255, 255));
  }

  if (robot_->get_battery_level() <= 0) {
      robot_-> set_color(csci3081::Color(255, 255, 255, 255));
      robot_-> set_speed(0);
      robot_->name("Loser :(");
  }


  /*
   * Next, check if the robot has collided with the recharge station or the home
   * base. These need to be before the general collisions, which can move the
   * robot away from these "obstacles" before the "collisions" have been
   * properly processed.
   */

  EventCollision ec;

  CheckForEntityCollision(robot_, home_base_, &ec, robot_->collision_delta());
  if (ec.collided()) {
      home_base_->set_speed(0);
      home_base_->name("Winner :P");
  }

  CheckForEntityCollision(robot_, recharge_station_,
    &ec, robot_->collision_delta());
  if (ec.collided()) {
    robot_->get_battery_level() - 0.03;
    EventRecharge er;
    robot_->Accept(&er);
  }

  /*
   * Finally, some pairs of entities may now be close enough to be considered
   * colliding, send collision events as necessary.
   *
   * When something collides with an immobile entity, the immobile entity does
   * not move (duh), so no need to send it a collision event.
   */
  for (auto ent : mobile_entities_) {
    // Check if it is out of bounds. If so, use that as point of contact.
    assert(ent->is_mobile());
    CheckForEntityOutOfBounds(ent, &ec);

    // If not at wall, check if colliding with any other entities (not itself)
    if (!ec.collided()) {
      for (size_t i = 0; i < entities_.size(); ++i) {
        if (entities_[i] == ent) {
          continue;
        }
        CheckForEntityCollision(ent, entities_[i], &ec, ent->collision_delta());
        if (ec.collided()) {
          break;
        }
      } /* for(i..) */
    } /* else */
    ent->Accept(&ec);
  } /* for(ent..) */
} /* UpdateEntities() */

void Arena::CheckForEntityOutOfBounds(const ArenaMobileEntity * const ent,
  EventCollision * event) {
  if (ent->get_pos().x+ ent->radius() >= x_dim_) {
    // Right Wall
    event->collided(true);
    event->point_of_contact(Position(x_dim_, ent->get_pos().y));
    event->angle_of_contact(ent->get_heading_angle()-180);
  } else if (ent->get_pos().x- ent->radius() <= 0) {
    // Left Wall
    event->collided(true);
    event->point_of_contact(Position(0, ent->get_pos().y));
    event->angle_of_contact(ent->get_heading_angle()+180);
  } else if (ent->get_pos().y+ ent->radius() >= y_dim_) {
    // Bottom Wall
    event->collided(true);
    event->point_of_contact(Position(ent->get_pos().x, y_dim_));
    event->angle_of_contact(ent->get_heading_angle());
  } else if (ent->get_pos().y - ent->radius() <= 0) {
    // Top Wall
    event->collided(true);
    event->point_of_contact(Position(ent->get_pos().x, 0));
    event->angle_of_contact(ent->get_heading_angle());
  } else {
    event->collided(false);
  }
} /* entity_out_of_bounds() */

void Arena::CheckForEntityCollision(const ArenaMobileEntity* const ent1,
  const ArenaEntity* const ent2,
  EventCollision * event,
  double collision_delta) {
  /* Note: this assumes circular entities */
  double ent1_x = ent1->get_pos().x;
  double ent1_y = ent1->get_pos().y;
  double ent2_x = ent2->get_pos().x;
  double ent2_y = ent2->get_pos().y;
  double dist = std::sqrt(
    std::pow(ent2_x - ent1_x, 2) + std::pow(ent2_y - ent1_y, 2));
  if (dist > ent1->radius() + ent2->radius() + collision_delta) {
    event->collided(false);
  } else {
    // Populate the collision event.
    // Collided is true
    // Point of contact is point along perimeter of ent1
    // Angle of contact is angle to that point of contact
    event->collided(true);
    double theta = ((ent1_y - ent2_y) / (ent1_x - ent2_x));
    double arctangent = (atan(theta/M_PI)) * 180;
    event-> angle_of_contact(180-(2*arctangent)+(ent1->get_heading_angle()));
    /// >>>>>>> FILL THIS IN
  }
} /* entities_have_collided() */

void Arena::Accept(__unused EventKeypress * e) {
    robot_ -> EventCmd(e->get_key_cmd());
}

NAMESPACE_END(csci3081);
