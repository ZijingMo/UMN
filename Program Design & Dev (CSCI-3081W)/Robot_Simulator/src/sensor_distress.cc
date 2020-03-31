/**
 * @file sensor_distress.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <limits>
#include "src/sensor_distress.h"
#include "src/arena_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorDistress::SensorDistress() :
  activated_(false),
  point_of_sensor_distress_(0, 0),
  angle_of_sensor_distress_(0) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorDistress::Accept(EventCollision * e){

}

void SensorDistress::Reset(void) {

} /* reset() */

NAMESPACE_END(csci3081);
