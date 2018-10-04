/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/GearboxShiftGears.h"
#include "Robot.h"

GearboxShiftGears::GearboxShiftGears() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_gearbox);
}

// Called just before this Command runs the first time
void GearboxShiftGears::Initialize() {
  Robot::m_gearbox.ToggleGear();
}

// Called repeatedly when this Command is scheduled to run
void GearboxShiftGears::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool GearboxShiftGears::IsFinished() { return true; }

// Called once after isFinished returns true
void GearboxShiftGears::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearboxShiftGears::Interrupted() {}
