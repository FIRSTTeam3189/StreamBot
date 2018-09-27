/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Drivetrain.h"
#include "Commands/TankDriveCommand.h"

#include "RobotMap.h"

Drivetrain::Drivetrain() : frc::Subsystem("Drivetrain") {}

void Drivetrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new TankDriveCommand());
}

void Drivetrain::InitHardware() {
  m_left = std::make_unique<Common::TalonSRX>(0);
  m_right = std::make_unique<Common::TalonSRX>(1);
}

void Drivetrain::TankDrive(double left, double right) {
  m_left->Set(Common::ControlMode::PercentOutput, left);
  m_right->Set(Common::ControlMode::PercentOutput, right);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
