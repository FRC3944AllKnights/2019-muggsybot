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
        frc::Servo lifterServo{8};
        double growthspeed = .8;
        double liftHoldAngle = 0.43;
        double liftReleaseAngle = 0.8;
};

#endif