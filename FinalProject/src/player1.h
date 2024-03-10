#ifndef __PLAYER1_AGENT__H
#define __PLAYER1_AGENT__H 

#include "enviro.h"

using namespace enviro;

class player1Controller : public Process, public AgentInterface {
    /*
    This class is used to create player 1 object and how to control player one
    Player 1 can be controled by using W,S,A, and D keys for its direction in play area
    */
    public:
    player1Controller() : Process(), AgentInterface() {}

    void init() {
        watch("keyup", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == "w" ) {
                  fx = 0;
                  fy = -force;
            } else if ( k == "s" ) {
                  fx = 0;
                  fy = force;
            } else if ( k == "a" ) {
                  fx = -force;
                  fy = 0;
            } else if ( k == "d" ) {
                  fx = force;
                  fy = 0;
            } else {
                fx = 0;
                fy = 0;
            }
            //after determine the inpu from user, apply force to object to move it
            omni_apply_force(fx,fy);
            
        });
    }
    void start() {
        //initial foce apply to object
        fx = 0;
        fy = 0;
    }
    void update() {
        //slow the agents down using linear and angular friction coefficients defined in JSON file
        omni_damp_movement();
    }
    void stop() {}

    double fx, fy;

    const double force = 150;

};

class player1 : public Agent {
    public:
    player1(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    player1Controller c;
};

DECLARE_INTERFACE(player1)

#endif