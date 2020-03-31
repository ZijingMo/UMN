/**
 * @file position.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

#ifndef SRC_POSITION_H_
#define SRC_POSITION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A simplified representation of the location. Each component should be x or y.
 */
struct Position {
Position(void) : x(0), y(0) { }
Position(double in_x, double in_y) : x(in_x), y(in_y) { }
double x;
double y;
};

NAMESPACE_END(csci3081);

#endif /* SRC_POSITION_H_ */
