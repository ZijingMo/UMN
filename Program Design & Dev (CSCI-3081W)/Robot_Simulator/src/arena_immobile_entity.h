/**
 * @file arena_immobile_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

#ifndef SRC_ARENA_IMMOBILE_ENTITY_H_
#define SRC_ARENA_IMMOBILE_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_entity.h"
#include "src/color.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief The class describes the feactures of immobile entities. The main judging
  * criteria is the return value of boolean verdict.
  */

class ArenaImmobileEntity : public ArenaEntity {
 public:
  ArenaImmobileEntity(double radius, const Position& pos,
                    const Color& color) :
      ArenaEntity(radius, pos, color) {}

  bool is_mobile(void) { return false; }
};

NAMESPACE_END(csci3081);

#endif /* SRC_ARENA_IMMOBILE_ENTITY_H_ */
