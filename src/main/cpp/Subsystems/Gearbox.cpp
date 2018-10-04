/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Gearbox.h"
#include "Commands/GearboxDoNothing.h"
#include "RobotMap.h"

Gearbox::Gearbox() : Subsystem("Gearbox") {}

void Gearbox::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new GearboxDoNothing());
}

void Gearbox::InitHardware() {
  gearbox_piston = std::make_unique<Components::Piston>(RobotMap::Gearbox::extend_solenoid_id,
                                                        RobotMap::Gearbox::retract_solenoid_id,
                                                        RobotMap::Gearbox::pneumatics_controller_id,
                                                        RobotMap::Gearbox::is_first_gear_by_default);
}

void Gearbox::SetGear(bool is_first) {
  gearbox_piston->SetExtended(is_first);
}

void Gearbox::ToggleGear() {
  gearbox_piston->Toggle();
}
