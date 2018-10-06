/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/SimpleAuto.h"
#include "Commands/AutoDriveTime.h"
#include "Commands/GearboxSetGear.h"
#include <Commands/TimedCommand.h>

constexpr int NUMBER_OF_LEGS = 4;
SimpleAuto::SimpleAuto() {
  for (int i = 0; i < NUMBER_OF_LEGS; ++i) {
    // Add one leg of the box
    AddSequential(new GearboxSetGear(true));
    AddSequential(new AutoDriveTime(DriveDirection::Forward, 3.0, 0.5));
    AddSequential(new AutoDriveTime(DriveDirection::RotateRight, .75, 0.5));
  }
}
