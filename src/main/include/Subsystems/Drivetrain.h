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
  void InitDefaultCommand() override;
  void InitHardware();

  void TankDrive(double left, double right);

 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  std::unique_ptr<Common::TalonSRX> m_left;
  std::unique_ptr<Common::TalonSRX> m_right;
};
