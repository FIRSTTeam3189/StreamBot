/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/AutoDriveTime.h"

#include "Robot.h"

AutoDriveTime::AutoDriveTime(DriveDirection direction, double time, double power) {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_drivetrain);
  SetTimeout(time);
  move_direction = direction;
  drive_power = power;
}

// Called just before this Command runs the first time
void AutoDriveTime::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoDriveTime::Execute() {
  switch (move_direction) {
    case DriveDirection::Forward:
      Robot::m_drivetrain.TankDrive(drive_power, drive_power);
      break;
    case DriveDirection::Backward:
      Robot::m_drivetrain.TankDrive(-drive_power, -drive_power);
      break;
    case DriveDirection::RotateLeft:
      // Negative power on left, positive power on right causes rotation
      // in the left direction.
      Robot::m_drivetrain.TankDrive(-drive_power, drive_power);
      break;
    case DriveDirection::RotateRight:
      // Positive power on left, negative power on right causes rotation
      // in the right direction.
      Robot::m_drivetrain.TankDrive(drive_power, -drive_power);
      break;
  }
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveTime::IsFinished() { return IsTimedOut(); }

// Called once after isFinished returns true
void AutoDriveTime::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveTime::Interrupted() {}
