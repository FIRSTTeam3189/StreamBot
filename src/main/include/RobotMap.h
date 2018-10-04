/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

namespace RobotMap {
    namespace Drivetrain {
        // Constants for Drivetrain subsystem
        // This includes:
        //      CAN ID's for the drive motors.
        constexpr int front_left_id = 2;
        constexpr int front_right_id = 5;
        constexpr int back_left_id = 1;
        constexpr int back_right_id = 6;
    }

    namespace Gearbox {
        // Constants for Gearbox subsystem
        // This includes:
        //      Pneumatics controller CAN ID
        //      Pneumatics ID for extend and retract solenoids for gearbox piston
        //      Wether the piston should be extended by default (in first gear).
        constexpr int pneumatics_controller_id = 0;
        constexpr int extend_solenoid_id = 0;
        constexpr int retract_solenoid_id = 1;
        constexpr bool is_first_gear_by_default = true;
    }
};
