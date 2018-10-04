/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <memory>
#include "Common.h"

class Drivetrain : public frc::Subsystem {
 public:
  Drivetrain();
  ~Drivetrain() = default;
  void InitDefaultCommand() override;

  /**
   * Initializes the TalonSRX CAN controllers because we can't initialize them
   * in the constructor without crashing the robot.
   */
  void InitHardware();

  /**
   * Powers left and right sides of the robot with the power values ranging from
   * -1.0 to 1.0.
   */
  void TankDrive(double left, double right);

 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  std::unique_ptr<Common::TalonSRX> front_left;
  std::unique_ptr<Common::TalonSRX> front_right;
  std::unique_ptr<Common::TalonSRX> back_left;
  std::unique_ptr<Common::TalonSRX> back_right;
};
