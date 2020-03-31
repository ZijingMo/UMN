/* This is the unit tests for sensor_touch.h, sensor_distress.h, sensor_proximity.h,
 * and sensor_entity_type.h file. For each class test, it would contains 5 aspects of
 * tests: the state of sensor is sleepy, the state of sensor is sanity, the function
 * resets, the situation of collision, and the setter function of position.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/sensor_touch.h"
#include "../src/sensor_distress.h"
#include "../src/sensor_proximity.h"
#include "../src/sensor_entity_type.h"


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

//For Sensor Touch

TEST(SensorTouch, Sleepy) {
  csci3081::SensorTouch st;

  bool val = std::is_base_of<csci3081::SensorBaseClass, csci3081::SensorTouch>::value;
  EXPECT_TRUE(val);

  EXPECT_EQ(st.activated(), false);
  EXPECT_EQ(st.point_of_contact().x, 0);
  EXPECT_EQ(st.point_of_contact().y, 0);
  EXPECT_EQ(st.angle_of_contact(), 0.0);
}

TEST(SensorTouch, Sanity){
  csci3081::SensorTouch st;
  bool val = std::is_base_of<csci3081::SensorBaseClass, csci3081::SensorTouch>::value;
  EXPECT_TRUE(val);

  st.activated(true);
  st.point_of_contact(csci3081::Position(1.0, 1.0));
  EXPECT_EQ(st.activated(), true);
  EXPECT_EQ(st.point_of_contact().x, 1.0);
  EXPECT_EQ(st.point_of_contact().y, 1.0);
}

TEST(SensorTouch, Reset) {
  csci3081::SensorTouch st;

  st.activated(true);
  st.point_of_contact(csci3081::Position(1.0, 1.0));
  EXPECT_EQ(st.activated(), true);
  EXPECT_EQ(st.point_of_contact().x, 1.0);
  EXPECT_EQ(st.point_of_contact().y, 1.0);
  EXPECT_DOUBLE_EQ(st.angle_of_contact(), 45.0);

  st.Reset();
  EXPECT_EQ(st.angle_of_contact(), 0.0);
  EXPECT_EQ(st.point_of_contact().x, 0);
  EXPECT_EQ(st.point_of_contact().y, 0);
  EXPECT_EQ(st.activated(), false);
}

TEST(SensorTouch, Accept){
  csci3081::SensorTouch st;
  st.activated(false);

  csci3081::EventCollision e_st;
  st.activated(true);
  e_st.collided(true);
  e_st.point_of_contact(csci3081::Position(100.0, 100.0));
  e_st.angle_of_contact(45);
  st.Accept(&e_st);
  EXPECT_EQ(st.angle_of_contact(), 45.0);
  EXPECT_EQ(st.point_of_contact().x, 100);
  EXPECT_EQ(st.point_of_contact().y, 100);
  EXPECT_TRUE(st.activated()) << "FAIL: Senor not activated with collision";
}

TEST(SensorTouch, PositionSetters){
  csci3081::SensorTouch st;
  st.point_of_contact(csci3081::Position(30.0, 40.0));
  st.angle_of_contact(30);
  EXPECT_EQ(st.angle_of_contact(), 30.0);
  EXPECT_EQ(st.point_of_contact().x, 30);
  EXPECT_EQ(st.point_of_contact().y, 40);
}

//For Sensor Proximity

TEST(SensorProximity, Sleepy) {
  csci3081::SensorProximity sp;

  bool val = std::is_base_of<csci3081::SensorBaseClass, csci3081::SensorProximity>::value;
  EXPECT_TRUE(val);

  EXPECT_EQ(sp.activated(), false);
  EXPECT_EQ(sp.point_of_contact().x, 0);
  EXPECT_EQ(sp.point_of_contact().y, 0);
  EXPECT_EQ(sp.angle_of_contact(), 0.0);
}

TEST(SensorProximity, Sanity){
  csci3081::SensorProximity sp;
  bool val = std::is_base_of<csci3081::SensorBaseClass, csci3081::SensorProximity>::value;
  EXPECT_TRUE(val);

  sp.activated(true);
  sp.point_of_contact(csci3081::Position(1.0, 1.0));
  EXPECT_EQ(sp.activated(), true);
  EXPECT_EQ(sp.point_of_contact().x, 1.0);
  EXPECT_EQ(sp.point_of_contact().y, 1.0);
}

TEST(SensorProximity, Reset) {
  csci3081::SensorProximity sp;

  sp.activated(true);
  sp.point_of_contact(csci3081::Position(1.0, 1.0));
  EXPECT_EQ(sp.activated(), true);
  EXPECT_EQ(sp.point_of_contact().x, 1.0);
  EXPECT_EQ(sp.point_of_contact().y, 1.0);
  EXPECT_DOUBLE_EQ(sp.angle_of_contact(), 45.0);

  sp.Reset();
  EXPECT_EQ(sp.angle_of_contact(), 0.0);
  EXPECT_EQ(sp.point_of_contact().x, 0);
  EXPECT_EQ(sp.point_of_contact().y, 0);
  EXPECT_EQ(sp.activated(), false);
}

TEST(SensorProximity, Accept){
  csci3081::SensorProximity sp;
  sp.activated(false);

  csci3081::EventCollision e_sp;
  sp.activated(true);
  e_sp.collided(true);
  e_sp.point_of_contact(csci3081::Position(100.0, 100.0));
  e_sp.angle_of_contact(45);
  sp.Accept(&e_sp);
  EXPECT_EQ(sp.angle_of_contact(), 45.0);
  EXPECT_EQ(sp.point_of_contact().x, 100);
  EXPECT_EQ(sp.point_of_contact().y, 100);
  EXPECT_TRUE(sp.activated()) << "FAIL: Senor not activated with collision";
}

TEST(SensorProximity, PositionSetters){
  csci3081::SensorProximity sp;
  sp.point_of_contact(csci3081::Position(30.0, 40.0));
  sp.angle_of_contact(30);
  EXPECT_EQ(sp.angle_of_contact(), 30.0);
  EXPECT_EQ(sp.point_of_contact().x, 30);
  EXPECT_EQ(sp.point_of_contact().y, 40);
}

// For Sensor Distress

TEST(SensorDistress, Sleepy) {
  csci3081::SensorDistress sd;

  bool val = std::is_base_of<csci3081::SensorBaseClass, csci3081::SensorDistress>::value;
  EXPECT_TRUE(val);

  EXPECT_EQ(sd.activated(), false);
  EXPECT_EQ(sd.point_of_contact().x, 0);
  EXPECT_EQ(sd.point_of_contact().y, 0);

}

TEST(SensorDistress, Sanity){
  csci3081::SensorDistress sd;
  bool val = std::is_base_of<csci3081::SensorBaseClass, csci3081::SensorDistress>::value;
  EXPECT_TRUE(val);

  sd.activated(true);
  sd.point_of_contact(csci3081::Position(1.0, 1.0));
  EXPECT_EQ(sd.activated(), true);
  EXPECT_EQ(sd.point_of_contact().x, 1.0);
  EXPECT_EQ(sd.point_of_contact().y, 1.0);
}

TEST(SensorDistress, Reset) {
  csci3081::SensorDistress sd;

  sd.activated(true);
  sd.point_of_contact(csci3081::Position(1.0, 1.0));
  EXPECT_EQ(sd.activated(), true);
  EXPECT_EQ(sd.point_of_contact().x, 1.0);
  EXPECT_EQ(sd.point_of_contact().y, 1.0);

  sd.Reset();
  EXPECT_EQ(sd.point_of_contact().x, 0);
  EXPECT_EQ(sd.point_of_contact().y, 0);
  EXPECT_EQ(sd.activated(), false);
}

TEST(SensorDistress, Accept){
  csci3081::SensorDistress sd;
  sd.activated(false);

  csci3081::EventCollision e_sd;
  sd.activated(true);
  e_sd.collided(true);
  e_sd.point_of_contact(csci3081::Position(120.0, 130.0));
  //e_sd.angle_of_contact(45);
  sd.Accept(&e_sd);
  EXPECT_EQ(sd.point_of_contact().x, 120);
  EXPECT_EQ(sd.point_of_contact().y, 130);
  EXPECT_TRUE(sd.activated()) << "FAIL: Senor not activated with collision";
}

TEST(SensorDistress, PositionSetters){
  csci3081::SensorDistress sd;
  sd.point_of_contact(csci3081::Position(50.0, 90.0));
  EXPECT_EQ(sd.point_of_contact().x, 50);
  EXPECT_EQ(sd.point_of_contact().y, 90);
}

//For Senor Entity Type

TEST(SensorEntityType, Sleepy) {
  csci3081::SensorEntityType setype;

  bool val = std::is_base_of<csci3081::SensorBaseClass, csci3081::SensorEntityType>::value;
  EXPECT_TRUE(val);

  EXPECT_EQ(setype.activated(), false);
  EXPECT_EQ(setype.point_of_contact().x, 0);
  EXPECT_EQ(setype.point_of_contact().y, 0);

}

TEST(SensorEntityType, Sanity){
  csci3081::SensorEntityType setype;
  bool val = std::is_base_of<csci3081::SensorBaseClass, csci3081::SensorEntityType>::value;
  EXPECT_TRUE(val);

  setype.activated(true);
  setype.point_of_contact(csci3081::Position(1.0, 1.0));
  EXPECT_EQ(setype.activated(), true);
  EXPECT_EQ(setype.point_of_contact().x, 1.0);
  EXPECT_EQ(setype.point_of_contact().y, 1.0);
}

TEST(SensorEntityType, Reset) {
  csci3081::SensorEntityType setype;

  setype.activated(true);
  setype.point_of_contact(csci3081::Position(3.0, 3.0));
  EXPECT_EQ(setype.activated(), true);
  EXPECT_EQ(setype.point_of_contact().x, 3.0);
  EXPECT_EQ(setype.point_of_contact().y, 3.0);

  setype.Reset();
  EXPECT_EQ(setype.point_of_contact().x, 0);
  EXPECT_EQ(setype.point_of_contact().y, 0);
  EXPECT_EQ(setype.activated(), false);
}

TEST(SensorEntityType, Accept){
  csci3081::SensorEntityType setype;
  setype.activated(false);

  csci3081::EventCollision e_setype;
  setype.activated(true);
  e_setype.collided(true);
  e_setype.point_of_contact(csci3081::Position(800.0, 700.0));
  //e_setype.angle_of_contact(45);
  setype.Accept(&e_setype);
  EXPECT_EQ(setype.point_of_contact().x, 800);
  EXPECT_EQ(setype.point_of_contact().y, 700);
  EXPECT_TRUE(setype.activated()) << "FAIL: Senor not activated with collision";
}

TEST(SensorEntityType, PositionSetters){
  csci3081::SensorEntityType setype;
  setype.point_of_contact(csci3081::Position(23.0, 56.0));
  EXPECT_EQ(setype.point_of_contact().x, 23);
  EXPECT_EQ(setype.point_of_contact().y, 56);
}
