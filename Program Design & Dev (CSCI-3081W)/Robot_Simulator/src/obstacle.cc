/**
 * @file obstacle.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/obstacle.h"
#include "src/color.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Static Variables
 ******************************************************************************/
uint Obstacle::next_id_ = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Obstacle::Obstacle(double radius, const Position& pos,
                                   const Color& color) :
    ArenaImmobileEntity(radius, pos, color),
    id_(-1) {
  id_ = next_id_++;
}

NAMESPACE_END(csci3081);
