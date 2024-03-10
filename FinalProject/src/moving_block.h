#ifndef __MOVING_BLOCK_AGENT__H
#define __MOVING_BLOCK_AGENT__H 

#include "enviro.h"

using namespace enviro;

class movingBlockController : public Process, public AgentInterface {
    /*
        Instead of having static block, this class will be used to generated block that 
        can be moved if in contact with something in the play area
    */
    public:
    movingBlockController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class movingBlock : public Agent {
    public:
    movingBlock(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    movingBlockController c;
};

DECLARE_INTERFACE(movingBlock)

#endif