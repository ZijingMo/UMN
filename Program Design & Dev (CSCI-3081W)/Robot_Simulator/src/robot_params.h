/**
 * @file robot_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

#ifndef SRC_ROBOT_PARAMS_H_
#define SRC_ROBOT_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_mobile_entity_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/**
* @brief A data structure contains the parameters: the delta angles and the
* maximum of the battery charge. This structure also inherits the parameters of
* arena mobile entity structure.
*/

struct robot_params : public arena_mobile_entity_params {
  robot_params(void) :
      arena_mobile_entity_params(),
      battery_max_charge(),
      angle_delta() {}

  double battery_max_charge;
  uint angle_delta;
};

NAMESPACE_END(csci3081);

#endif /* SRC_ROBOT_PARAMS_H_ */
