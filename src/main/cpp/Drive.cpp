#include "Drive.h"

Drive::Drive(){
};

void Drive::init(){
    m_frontLeft.SetInverted(true);
    m_rearLeft.SetInverted(true);
    m_frontRight.SetInverted(true);
    m_rearRight.SetInverted(true);
};

void Drive::mechanum(double x, double y, double z, bool backslow, bool frontslow){
    if(backslow){
        m_robotDrive.DriveCartesian(0, 0.12, 0);
    }
    else if(frontslow){
        z = z/(-2.0)*throttle*.7;
        x = x*(-1.0)*throttle*.7;
        y = y*throttle*.25;
        m_robotDrive.DriveCartesian(-x, y, z);
    }
    else{
        z = z/(-2.0)*throttle;
        x = x*(-1.0)*throttle;
        y = y*throttle;
        m_robotDrive.DriveCartesian(-x, y, z);
    }
};