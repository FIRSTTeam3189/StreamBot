#include "ctre/Phoenix.h"
#include <AnalogPotentiometer.h>

namespace Common {
    using TalonSRX = ctre::phoenix::motorcontrol::can::TalonSRX;
    using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
    using Potentiometer = AnalogPotentiometer;
};