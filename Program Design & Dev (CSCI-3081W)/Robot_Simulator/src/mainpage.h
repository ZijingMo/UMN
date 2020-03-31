/**
 * @file mainpage.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */


#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

/*! \mainpage CSCI3081 Robot Simulator Project
 *
 * \section intro_sec Introduction
 *
 * We could understand the mutual relations for the first project with UML graph.
 * There exist three main parts in the graph: ArenaEntity part, EvenBaseClass part, and anrena_entity_params part. Comparing with other two parts, anrean_entity_params is the form of a struct. Different classes or structs inherit these three basic units.
 * Besides those base classes or struct. There are two other important classes we need to focus on. The first one is Arena class. In this data unit, we could create the environment of our little robot. With the graph, we can find that the function of aggregation is implemented by EventColllision class and EventKeypress class. On the other hand, the class of Robot, HomeBase, and RechargeStation are critical constitutive of the Arena class. These three parts construct the environment of robot world together.
 * The other important class is Robert. The objective of our project is changing or operating the behaviors of the robot in some environment. Thus, the understanding of mutual relations of Robot class could help us for creating multifunctional entities. In the class, we could know our entity inherits the function of ArenaMobileEntity, and apply the function of RobotBattery class and SensorTouch class to implement partial functions of Robot. Moreover, the Robot class has four different  behaviors, which are handled by four class: EventRecharge, EventCollision, robot_motion_handler, and robot_motion_behavior. The reasonable and efficient coding in these four classes could bring improvement of robot's performance.
 * That's the explanation of graph. If you want to add more classes to implement a better robot, just a more classes in this graph!
 *
 * \section install_sec Installation
 *
 * \subsection libsimplegraphics Installing and Using libsimplegraphics
 *
 * etc...
 */


NAMESPACE_END(csci3081);

#endif /* SRC_MAINPAGE_H_ */
