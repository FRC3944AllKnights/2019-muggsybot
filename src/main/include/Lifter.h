#ifndef LIFTER_H
#define LIFTER_H

#include <ctre/Phoenix.h>
#include <frc/Servo.h>
#include <frc/DigitalInput.h>

class Lifter{
    public:
        Lifter();
        void init();
        void manualLift(bool foward, bool reverse);

    private:
        WPI_TalonSRX longlifty{14};
        frc::Servo lifterServo{1};
        frc::Servo armServo{0};
        frc::DigitalInput limitSwitch{0};
        double growthspeed = .8;
        double liftHoldAngle = 0.43;
        double liftReleaseAngle = 0.8;
        double armHoldAngle = 0.8;
        double armReleaseAngle = 0.4;
};

#endif