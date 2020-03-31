/**
 * @file sensor_entity_type.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <limits>
#include "src/sensor_entity_type.h"
#include "src/arena_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorEntityType::SensorEntityType() :
  activated_(false),
  point_of_sensor_entity_type_(0, 0),
  angle_of_sensor_entity_type_(0) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorEntityType::Accept(EventCollision * e){

}

void SensorEntityType::Reset(void) {

} /* reset() */

NAMESPACE_END(csci3081);
