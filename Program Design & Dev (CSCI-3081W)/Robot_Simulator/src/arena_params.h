/**
 * @file arena_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

#ifndef SRC_ARENA_PARAMS_H_
#define SRC_ARENA_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_params.h"
#include "src/home_base_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/
#define MAX_OBSTACLES 8

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

 /**
  * @brief A data structure contains the parameters: x-axis dimension, y-axis
  * dimension, and the amount of obstacles. In this data structure, it also
  * contains four different parameters we construct: robot (the robot_params
  * structure), recharged station (the arena_entity_params structure), home base
  * (the home_base_params structure), and obstacles array (the arena_entity_params
  * structure). 
  */

struct arena_params {
  struct robot_params robot;
  struct arena_entity_params recharge_station;
  struct home_base_params home_base;
  struct arena_entity_params obstacles[MAX_OBSTACLES];
  size_t n_obstacles;
  uint x_dim;
  uint y_dim;
};

NAMESPACE_END(csci3081);

#endif /* SRC_ARENA_PARAMS_H_ */
