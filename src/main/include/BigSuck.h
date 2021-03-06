#ifndef BIGSUCK_H //heh heh
#define BIGSUCK_H

#include <ctre/Phoenix.h>
#include "frc/AnalogInput.h"

class BigSuck{
    public:
        BigSuck();
        void initBig();
        void manualBigSuck(bool on, bool off);

    private:
    //this is a comment so you never forget
        WPI_TalonSRX bigsucker1{10}; 
        WPI_TalonSRX bigsucker2{11};
        WPI_TalonSRX bigsucker3{12};

        frc::AnalogInput pressure1 {0};
        frc::AnalogInput pressure2 {2};
        double ultraMegaSuperSuccSpeed = 0.25;
        bool sucking = false;
};

#endif
