#include "BigSuck.h"

BigSuck::BigSuck(){
};

void BigSuck::initBig(){
    bigsucker1.Set(ControlMode::PercentOutput, 0);
    bigsucker2.Set(ControlMode::PercentOutput, 0);
    bigsucker3.Set(ControlMode::PercentOutput, 0);
    armServo.Set(armHoldAngle);
};

void BigSuck::manualBigSuck(bool on, bool off){
    if (on) {
        sucking = true;
    }
    if (off) {
        sucking = false;
    }
    if (sucking) {
        bigsucker1.Set(ControlMode::PercentOutput, ultraMegaSuperSuccSpeed);
        bigsucker2.Set(ControlMode::PercentOutput, ultraMegaSuperSuccSpeed);
        bigsucker3.Set(ControlMode::PercentOutput, ultraMegaSuperSuccSpeed);
        armServo.Set(armReleaseAngle);
    }
    else {
        bigsucker1.Set(ControlMode::PercentOutput, 0);
        bigsucker2.Set(ControlMode::PercentOutput, 0);
        bigsucker3.Set(ControlMode::PercentOutput, 0);
    }
};
