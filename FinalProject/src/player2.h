#ifndef __PLAYER2_AGENT__H
#define __PLAYER2_AGENT__H 

#include "enviro.h"

using namespace enviro;

class player2Controller : public Process, public AgentInterface {
    /*
    This class help generate Player 2 and its control using I,J,K,an L keys
    */
    public:
    player2Controller() : Process(), AgentInterface() {}
    void init() {
        watch("keyup", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == "i" ) {
                  fx = 0;
                  fy = -force;
            } else if ( k == "k" ) {
                  fx = 0;
                  fy = force;
            } else if ( k == "j" ) {
                  fx = -force;
                  fy = 0;
            } else if ( k == "l" ) {
                  fx = force;
                  fy = 0;
            } else {
                fx = 0;
                fy = 0;
            }
            //after determine the direction, apply force to the direction chosen
            omni_apply_force(fx,fy);
            
        });
    }
    void start() {
        //Initial force applied to object
        fx = 0;
        fy = 0;
    }
    void update() {
        //slow the agents down using linear and angular 
        //friction coefficients defined in JSON file
        omni_damp_movement();
    }
    void stop() {}

    double fx, fy;

    const double force = 100;
};

class player2 : public Agent {
    public:
    player2(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    player2Controller c;
};

DECLARE_INTERFACE(player2)

#endif