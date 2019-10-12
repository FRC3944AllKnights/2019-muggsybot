#include "Drive.h"

Drive::Drive(){
};

void Drive::init(){
    m_frontLeft.SetInverted(true);
    m_rearLeft.SetInverted(true);
    m_frontRight.SetInverted(true);
    m_rearRight.SetInverted(true);
};

void Drive::mechanum(double x, double y, double z, bool backslow, bool frontslow, bool aimbot, double Xray){
    if(backslow){
        m_robotDrive.DriveCartesian(0, 0.12, 0);
    }
    else if(frontslow){
        z = z/(-2.0)*throttle*.25;
        x = x*(-1.0)*throttle*.25;
        y = y*throttle*.25;
        m_robotDrive.DriveCartesian(x, y, z);
    }
    else if(aimbot){
        sum = sum - Xray*0.0015;
        m_robotDrive.DriveCartesian(0, 0, (-Xray*0.02 + sum));
    }
    else{
        z = z/(-2.0)*throttle;
        x = x*(-1.0)*throttle;
        y = y*throttle;
        m_robotDrive.DriveCartesian(x, y, z);
    }
};