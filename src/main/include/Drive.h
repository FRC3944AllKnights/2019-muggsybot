#ifndef DRIVE_H
#define DRIVE_H

#include <Drive/MecanumDrive.h>
#include <ctre/Phoenix.h>

class Drive{
    public:
        Drive();
        void init();
        void mechanum(double x, double y, double z, double throttle);

    private:
        WPI_TalonSRX m_frontLeft{1};
        WPI_TalonSRX m_rearLeft{2};
        WPI_TalonSRX m_frontRight{3};
        WPI_TalonSRX m_rearRight{4};
        frc::MecanumDrive m_robotDrive{m_frontLeft, m_rearLeft, m_frontRight,
                                 m_rearRight};
};

#endif