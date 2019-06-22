#ifndef LIFTER_H
#define LIFTER_H

#include <ctre/Phoenix.h>
#include <Servo.h>

class Lifter{
    public:
        Lifter();
        void init();
        void manualLift(bool foward, bool reverse);

    private:
        WPI_TalonSRX longlifty{14};
        frc::Servo safetyServo{0};
        double growthspeed = .6;
        double holdAngle = 0;
        double releaseAngle = 0.5;
};

#endif