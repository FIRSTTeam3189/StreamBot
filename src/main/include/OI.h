/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Joystick.h>

class OI {
public:
  OI();

  double GetLeftY();
  double GetRightY();
private:
  frc::Joystick m_left { 0 };
  frc::Joystick m_right { 1 };
};
