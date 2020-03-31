/**
 * @file sensor_proximity.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <limits>
#include "src/sensor_proximity.h"
#include "src/arena_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorProximity::SensorProximity() :
  activated_(false),
  point_of_sensor_proximity_(0, 0),
  angle_of_sensor_proximity_(0) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/


void SensorProximity::InRange(void){
  }

void SensorProximity::SensorView(void){

}

void SensorProximity::Accept(EventCollision * e){

}

void SensorProximity::Reset(void) {

} /* reset() */

NAMESPACE_END(csci3081);
