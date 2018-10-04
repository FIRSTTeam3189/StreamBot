/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/GearboxSetGear.h"
#include "Robot.h"

GearboxSetGear::GearboxSetGear(bool is_first) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_gearbox);
  set_is_first = is_first;
}

// Called just before this Command runs the first time
void GearboxSetGear::Initialize() {
  Robot::m_gearbox.SetGear(set_is_first);
}

// Called repeatedly when this Command is scheduled to run
void GearboxSetGear::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool GearboxSetGear::IsFinished() { return true; }

// Called once after isFinished returns true
void GearboxSetGear::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearboxSetGear::Interrupted() {}
