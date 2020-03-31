/**
 * @file arena_entity_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

#ifndef SRC_ARENA_ENTITY_PARAMS_H_
#define SRC_ARENA_ENTITY_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/nanogui.h>
#include "src/position.h"
#include "src/color.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/**
 * @brief A data structure contains the parameters: radius, positions and color.
 */

struct arena_entity_params {
  arena_entity_params(void) : radius(), pos(), color() {}
  double radius;
  Position pos;
  Color color;
};

NAMESPACE_END(csci3081);

#endif /* SRC_ARENA_ENTITY_PARAMS_H_ */
