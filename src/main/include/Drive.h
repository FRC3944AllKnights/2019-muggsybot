#ifndef DRIVE_H
#define DRIVE_H

#include <Drive/MecanumDrive.h>
#include <ctre/Phoenix.h>

class Drive{
    public:
        Drive();
        void init();
        void mechanum(double x, double y, double z, bool backslow, bool frontslow);

    private:
        WPI_TalonSRX m_frontLeft{1};
        WPI_TalonSRX m_rearLeft{2};
        WPI_TalonSRX m_frontRight{4};
        WPI_TalonSRX m_rearRight{3};
        frc::MecanumDrive m_robotDrive{m_frontLeft, m_rearLeft, m_frontRight,
                                 m_rearRight};
        double throttle = 0.75;
};

#endif