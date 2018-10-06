/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>

enum class DriveDirection {
  Forward,
  Backward,
  RotateLeft,
  RotateRight
};

class AutoDriveTime : public frc::Command {
 public:
  AutoDriveTime(DriveDirection direction, double time, double power);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

private:
  DriveDirection move_direction;
  double drive_power;
};
