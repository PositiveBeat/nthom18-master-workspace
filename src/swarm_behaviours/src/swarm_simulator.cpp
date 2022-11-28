#include "swarm_simulator.hpp"

#define GRAPHICS_API_OPENGL_33
#include <iostream>
#include <string>

// namespace SwarmSim
// {

SwarmSimulator::SwarmSimulator(bool hl, std::list<SwarmSim::Robot *> robots, std::list<SwarmSim::Widget *> widgetList) : mHeadless(hl)
{
    // init logger
    SwarmSim::Log log;
    log.Init();

    // init simulation
    mSimulator = std::make_shared<SwarmSim::Simulator>(robots);

    if (!mHeadless)
    {
        // init the view
        mSimulatorView = std::make_unique<SwarmSim::SimulatorView>(mSimulator, widgetList, 1920, 1080);
    }
}

SwarmSimulator::~SwarmSimulator()
{
}

void SwarmSimulator::addRobot(SwarmSim::Robot *robot)
{
}

bool SwarmSimulator::shouldClose()
{
    return mHeadless ? false : WindowShouldClose();
}

void SwarmSimulator::loop()
{
    while (!shouldClose())
    {
        // step SwarmSimulator
        mSimulator->step();
        if (!mHeadless)
        {
            // handle input
            mSimulatorView->update();
            // render state
            mSimulatorView->render();
        }
    }
}

void SwarmSimulator::loopOnce()
{
    // step SwarmSimulator
    mSimulator->step();
    if (!mHeadless)
    {
        // handle input
        mSimulatorView->update();
        // render state
        mSimulatorView->render();
    }
}

// } // namespace SwarmSim
