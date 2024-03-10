#ifndef __BALL_AGENT__H
#define __BALL_AGENT__H 

#include "enviro.h"

using namespace enviro;

class ballController : public Process, public AgentInterface {
    /*
    This class represents the ball that users have to push it to the Bucket
    */
    public:
    ballController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class ball : public Agent {
    public:
    ball(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    ballController c;
};

DECLARE_INTERFACE(ball)

#endif