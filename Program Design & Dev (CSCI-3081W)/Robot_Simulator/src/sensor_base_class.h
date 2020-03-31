/**
 * @file sensor_base_class.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

#ifndef SRC_SENSOR_BASE_CLASS_H_
#define SRC_SENSOR_BASE_CLASS_H_

 /*******************************************************************************
  * Includes
  ******************************************************************************/
#include "src/position.h"

 /*******************************************************************************
  * Namespaces
  ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

 /*******************************************************************************
  * Class Definitions
  ******************************************************************************/

  /**
   * @brief The sensor base class from which all sensor touch should derive from.
   */

class SensorBaseClass{
 public:
      SensorBaseClass(void) {}
      virtual ~SensorBaseClass(void) {}

      virtual void EmitMessage(void) = 0;

      //virtual void TimestepUpdate(__unused uint dt) {}


 /*******************************************************************************
    * Member Functions
  ******************************************************************************/
  // void set_pos(const Position& pos) { pos_ = pos;}
  // const Position& get_pos(void) const { return pos_; }
  // const Color& get_color(void) const { return color_; }
  // void set_color(const Color& color) { color_ = color; }
  // virtual bool is_actived(void) = 0;
  //double radius(void) const { return radius_; }

 private:
  double radius_;
  Position pos_;
  //Color color_;
};

NAMESPACE_END(csci3081);

#endif /* SRC_SENSOR_BASE_CLASS_H_ */
