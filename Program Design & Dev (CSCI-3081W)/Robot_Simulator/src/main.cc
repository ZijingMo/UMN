/**
 * @file main.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * @author Zijing Mo <zijingmo888@gmail.com>
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/graphics_arena_viewer.h"
#include "src/arena_params.h"
#include "src/color.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/

/**
* @brief Essential call to initiate the graphics window. In this areana, we have
* one robot, one home base mobile entity, one recharge station, and five obstacles.
*/
int main(int argc, char const *argv[]) {
  csci3081::InitGraphics();

  // Initialize default start values for various arena entities

 csci3081::robot_params rparams;

 csci3081::arena_params aparams;

   aparams.n_obstacles = 5;
   aparams.x_dim = 1024;
   aparams.y_dim = 768;

   printf("pass x_dim and y_dim\n");

  // Start up the graphics (which creates the arena).
  // Run will enter the nanogui::mainloop()

    argc = 2;
    //argv[0] = "Robot_Simulator";
    argv[1] = "config.txt";
    printf("read file.\n");
    ifstream config;
    config.open(argv[1]);
    assert(config.is_open());
    string line;
    int i = 0;

    char command[100];

    while (getline(config, line)){
      if (line[0] == '#'){
        printf("read #.\n");
        continue;
      }
      sscanf(line.c_str(), "%s ", command);
      string cmd = command;

      if (cmd == "robot"){

        float bmaxcharge; float angledelta; float collisiondelta;
        float x; float y; float rad;
        int r; int g; int b; int a;
        sscanf(line.c_str(), "robot %f %f %f %f %f %f %d %d %d %d",
        &bmaxcharge, &angledelta, &collisiondelta, &x, &y, &rad, &r, &g, &b, &a);
        printf("Robot?.\n");
        rparams.battery_max_charge = bmaxcharge;
        rparams.angle_delta = angledelta;
        rparams.collision_delta = collisiondelta;
        rparams.pos = {x, y};
        rparams.radius = rad;
        rparams.color = csci3081::Color(r, g, b, a);
        //csci3081::arena_params aparams;
        aparams.robot = rparams;
      }

      else if (cmd == "recharge_station") {
        float x; float y; float rad;
        int r; int g; int b; int a;
        sscanf(line.c_str(), "recharge_station %f %f %f %d %d %d %d",
        &x, &y, &rad, &r, &g, &b, &a);
        aparams.recharge_station.pos = {x, y};
        aparams.recharge_station.radius = rad;
        aparams.recharge_station.color = csci3081::Color(r, g, b, a);
      }

      else if (cmd == "home_base") {
        float x; float y; float rad;
        int r; int g; int b; int a;
        sscanf(line.c_str(), "home_base %f %f %f %d %d %d %d",
        &x, &y, &rad, &r, &g, &b, &a);
        aparams.home_base.pos = {x, y};
        aparams.home_base.radius = rad;
        aparams.home_base.color = csci3081::Color(r, g, b, a);
      }

      else if (cmd == "obstacle") {
        //printf("hello\n")
        float x; float y; float rad;
        int r; int g; int b; int a;
        sscanf(line.c_str(), "obstacle %f %f %f %d %d %d %d",
        &x, &y, &rad, &r, &g, &b, &a);
        aparams.obstacles[i].pos = {x, y};
        aparams.obstacles[i].radius = rad;
        aparams.obstacles[i].color = csci3081::Color(r, g, b, a);
        i++;
      }
    }

    config.close();

  csci3081::GraphicsArenaViewer *app =
    new csci3081::GraphicsArenaViewer(&aparams);
  app->Run();
  csci3081::ShutdownGraphics();
  return 0;


}
