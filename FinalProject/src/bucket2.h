#ifndef __BUCKET2_AGENT__H
#define __BUCKET2_AGENT__H 

#include "enviro.h"

using namespace enviro;

class bucket2Controller : public Process, public AgentInterface {
    /*
        This class is used to create a goal bucket for second player
    */
    public:
    bucket2Controller() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class bucket2 : public Agent {
    public:
    bucket2(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    bucket2Controller c;
};

DECLARE_INTERFACE(bucket2)

#endif