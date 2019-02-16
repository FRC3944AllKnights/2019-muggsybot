#ifndef LIFTER_H
#define LIFTER_H

#include <ctre/Phoenix.h>

class Lifter{
    public:
        Lifter();
        void init();
        void manualLift(bool foward, bool reverse);

    private:
        WPI_TalonSRX longlifty{13};
        double growthspeed = .6;
};

#endif