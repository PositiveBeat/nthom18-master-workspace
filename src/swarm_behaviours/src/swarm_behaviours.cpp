#include <cstdio>

#include "boids.hpp"
#include "property_panel.hpp"
#include "swarm_simulator.hpp"

#include "EnvironmentState.h"

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  printf("Hello world swarm-sim package\n");
  // Create robot instances
  std::list<SwarmSim::Robot *> robots;
  for (size_t i = 0; i < 250; i++)
  {
    robots.emplace_back(new Boids());
  }

  // Custom property menu
  std::list<SwarmSim::Widget *> widgetList;
  SwarmSim::Widget *menu = new PropertyPanel();
  widgetList.push_back(menu);

  SwarmSimulator sim(false, robots, widgetList);

  sim.loop();
  return 0;
}