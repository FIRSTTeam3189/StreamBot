/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/DriveForwardTime.h"

#include "Robot.h"

DriveForwardTime::DriveForwardTime(double time) {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_drivetrain);
  SetTimeout(time);
}

// Called just before this Command runs the first time
void DriveForwardTime::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveForwardTime::Execute() {
  Robot::m_drivetrain.TankDrive(.5, .5);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForwardTime::IsFinished() { return IsTimedOut(); }

// Called once after isFinished returns true
void DriveForwardTime::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForwardTime::Interrupted() {}
