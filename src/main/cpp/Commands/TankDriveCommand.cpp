/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/TankDriveCommand.h"

#include "Robot.h"

TankDriveCommand::TankDriveCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void TankDriveCommand::Initialize() {
  // Place any code to clear out state, to setup command, set timeouts...
}

// Called repeatedly when this Command is scheduled to run
void TankDriveCommand::Execute() {
  Robot::m_drivetrain.TankDrive(Robot::m_oi.GetLeftY(), Robot::m_oi.GetRightY());
}

// Make this return true when this Command no longer needs to run execute()
bool TankDriveCommand::IsFinished() { 
  return false; 
}

// Called once after isFinished returns true
void TankDriveCommand::End() {
  // Clean up anything that the command did to the subsystem so the next command
  // can execute successfully.
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDriveCommand::Interrupted() {

}
