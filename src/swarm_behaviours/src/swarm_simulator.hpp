#ifndef SWARMSIM_H
#define SWARMSIM_H

#pragma once
#include <memory>
#include <string>

#include "../core/Log.h"
#include "../sim/Simulator.h"
#include "../ui/SimulatorView.h"

class SwarmSimulator
{
public:
    SwarmSimulator(bool, std::list<SwarmSim::Robot *> robots, std::list<SwarmSim::Widget *> widgetList);
    ~SwarmSimulator();

    void addRobot(SwarmSim::Robot *robot);
    bool shouldClose();
    void loop();
    void loopOnce();

private:
    bool mHeadless;
    std::unique_ptr<SwarmSim::SimulatorView> mSimulatorView;
    std::shared_ptr<SwarmSim::Simulator> mSimulator;

    void customLog(int msgType, const char *text, va_list args);
};

#endif // SWARMSIM_H
