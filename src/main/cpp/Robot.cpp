/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <thread> 

#include <cameraserver/CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <wpi/raw_ostream.h>
#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include <frc/SmartDashboard/SmartDashboard.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

#include "Drive.h"
#include "LittleSuck.h"
#include "Lifter.h"
#include "BigSuck.h"
#include "Arm.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override {
    // Invert the left side motors. You may need to change or remove this to
    // match your robot.
    std::thread visionThread(VisionThread);
    visionThread.detach();
    MuggsyDrive.init();
    smolsuck.init();
    bigboisuck.initBig();
    liftyboi.init();
    frc::SmartDashboard::init();
  }

  void AutonomousPeriodic() {
    /* Use the joystick X axis for lateral movement, Y axis for forward
     * movement, and Z axis for rotation.
     */
    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    double Xoffset = table->GetNumber("tx",0.0);
    double Yoffset = table->GetNumber("ty",0.0);
    double targetArea = table->GetNumber("ta",0.0);
    double targetSkew = table->GetNumber("ts",0.0);

    MuggsyDrive.mechanum(m_stick.GetX(), m_stick.GetY(), m_stick.GetZ(), m_stick.GetRawButton(2), m_stick.GetRawButton(1), m_stick.GetRawButton(4), Xoffset);

    smolsuck.manualSuck(m_stick.GetRawButton(1), m_stick.GetRawButton(2));
    liftyboi.manualLift(m_stick.GetRawButton(12), m_stick.GetRawButton(11));
    bigboisuck.manualBigSuck(m_stick.GetRawButton(8), m_stick.GetRawButton(7));
  }

  void TeleopPeriodic() override {
    /* Use the joystick X axis for lateral movement, Y axis for forward
     * movement, and Z axis for rotation.
     */
    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    double Xoffset = table->GetNumber("tx",0.0);
    double Yoffset = table->GetNumber("ty",0.0);
    double targetArea = table->GetNumber("ta",0.0);
    double targetSkew = table->GetNumber("ts",0.0);

    MuggsyDrive.mechanum(m_stick.GetX(), m_stick.GetY(), m_stick.GetZ(), m_stick.GetRawButton(2), m_stick.GetRawButton(1), m_stick.GetRawButton(4), Xoffset);

    smolsuck.manualSuck(m_stick.GetRawButton(1), m_stick.GetRawButton(2));
    liftyboi.manualLift(m_stick.GetRawButton(12), m_stick.GetRawButton(11));
    bigboisuck.manualBigSuck(m_stick.GetRawButton(8), m_stick.GetRawButton(7));
    frc::SmartDashboard::PutBoolean("1 pressed", m_stick.GetRawButton(1));

    frc::SmartDashboard::PutNumber("X offset", Xoffset);
    frc::SmartDashboard::PutNumber("Y offset", Yoffset);
    frc::SmartDashboard::PutNumber("Area", targetArea);
    frc::SmartDashboard::PutNumber("Skew", targetSkew);
  }

 private:
 
  static void VisionThread() {
    // Get the USB camera from CameraServer
    cs::UsbCamera camera =
        frc::CameraServer::GetInstance()->StartAutomaticCapture("0", 0);
    // Set the resolution
    camera.SetFPS(10);
    camera.SetResolution(128, 72);
    //frc::CameraServer::GetInstance()->StartAutomaticCapture(camera);
    // Get a CvSink. This will capture Mats from the Camera
    cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo();
    cs::CvSource outputStream =
        frc::CameraServer::GetInstance()->PutVideo("gray", 128, 72);
    //Mats are very memory expensive. Lets reuse this Mat.
    cv::Mat mat;

    while(true) {
            cvSink.GrabFrame(mat);
            cvtColor(mat, mat, cv::COLOR_BGR2GRAY);
            outputStream.PutFrame(mat);
       }
  }

 //this is where to change variables
  static constexpr int kJoystickChannel = 0;
  Drive MuggsyDrive;
  BigSuck bigboisuck;
  LittleSuck smolsuck;
  Arm arm;
  int loops = 0;
  frc::Joystick m_stick{kJoystickChannel};
  Lifter liftyboi;
};

#ifndef RUNNING_FRC_TESTS
int main() { 
  return frc::StartRobot<Robot>(); 
}
#endif
