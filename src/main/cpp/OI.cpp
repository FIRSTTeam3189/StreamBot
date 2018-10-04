/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>
#include "Commands/GearboxSetGear.h"
#include "Commands/GearboxShiftGears.h"

OI::OI() {
  // Process operator interface input here.
  // Create Joystick buttons to send commands to the gearbox
  right_1 = std::make_unique<frc::JoystickButton>(&m_right, 1);
  right_2 = std::make_unique<frc::JoystickButton>(&m_right, 2);
  right_3 = std::make_unique<frc::JoystickButton>(&m_right, 3);

  right_1->WhenPressed(new GearboxShiftGears());
  right_2->WhenPressed(new GearboxSetGear(true));
  right_3->WhenPressed(new GearboxSetGear(false));
}

double OI::GetLeftY() {
  return m_left.GetY(frc::GenericHID::JoystickHand::kLeftHand);
}

double OI::GetRightY() {
  return m_left.GetY(frc::GenericHID::JoystickHand::kRightHand);
}
