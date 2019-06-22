#ifndef BIGSUCK_H //heh heh
#define BIGSUCK_H

#include <ctre/Phoenix.h>

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

        double ultraMegaSuperSuccSpeed = 0.15;
        bool sucking = false;
};

#endif
