/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include "Components/Piston.h"
#include <memory>

class Gearbox : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  Gearbox();
  ~Gearbox() = default;
  void InitDefaultCommand() override;

  /**
   * Initializes the Piston needed for the Gearbox to shift gears.
   */
  void InitHardware();
  
  /**
   * Sets the gear to first gear if is_first is true, otherwise if 
   * is_first is false, the gearbox shifts into second.
   */
  void SetGear(bool is_first);

  /**
   * Toggles between first and second gear.
   */
  void ToggleGear();

private:
  std::unique_ptr<Components::Piston> gearbox_piston;
};
