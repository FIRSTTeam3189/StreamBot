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
  // Initialize the motors for the drivetrain.
  front_left = std::make_unique<Common::TalonSRX>(RobotMap::Drivetrain::front_left_id);
  front_right = std::make_unique<Common::TalonSRX>(RobotMap::Drivetrain::front_right_id);
  back_left = std::make_unique<Common::TalonSRX>(RobotMap::Drivetrain::back_left_id);
  back_right = std::make_unique<Common::TalonSRX>(RobotMap::Drivetrain::back_right_id);

  back_left->Follow(*front_left);
  back_right->Follow(*front_right);
}

void Drivetrain::TankDrive(double left, double right) {
  // Use PercentOutput for controlling TalonSRX motor controllers.
  front_left->Set(Common::ControlMode::PercentOutput, left);
  front_right->Set(Common::ControlMode::PercentOutput, right);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
