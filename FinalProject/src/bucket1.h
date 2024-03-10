#ifndef __BUCKET1_AGENT__H
#define __BUCKET1_AGENT__H 

#include "enviro.h"

using namespace enviro;

class bucket1Controller : public Process, public AgentInterface {
    /*
     This class is used to generate the goal bucket in play area for 
    player 1   
    */

    public:
    bucket1Controller() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class bucket1 : public Agent {
    public:
    bucket1(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    bucket1Controller c;
};

DECLARE_INTERFACE(bucket1)

#endif