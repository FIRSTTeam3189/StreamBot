#include "Components/Piston.h"

Components::Piston::Piston(int extendId, int retractId, int pneumaticControllerId, bool extendedByDefault) {
    // Initialize solenoids using unique_ptr's make_unique function. Essentially new operator for unique_ptrs
    extendSolenoid = std::make_unique<frc::Solenoid>(pneumaticControllerId, extendId);
    retractSolenoid = std::make_unique<frc::Solenoid>(pneumaticControllerId, retractId);

    // Take account of extendedByDefault
    extendSolenoid->Set(extendedByDefault);
    retractSolenoid->Set(!extendedByDefault);
}

void Components::Piston::SetExtended(bool extendPiston) {
    extendSolenoid->Set(extendPiston);
    retractSolenoid->Set(!extendPiston);
}

void Components::Piston::Toggle() {
    extendSolenoid->Set(!extendSolenoid->Get());
    retractSolenoid->Set(!retractSolenoid->Get());
}

bool Components::Piston::IsExtended() {
    return extendSolenoid->Get();
}