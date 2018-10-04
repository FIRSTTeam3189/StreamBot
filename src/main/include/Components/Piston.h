#pragma once

#include <WPILib.h>
#include <Solenoid.h>
#include <memory>

namespace Components {
    class Piston {
    public:
        Piston(int extendId, int retractId, int pneumaticsControllerId = 0, bool extendedByDefault = false);
        ~Piston() = default;

        /**
         * Extends the piston if extendPiston is true,
         * otherwise retracts the piston if it is false.
         */
        void SetExtended(bool extendPiston);

        /**
         * Toggles the state of the piston, retracting it if it is extended,
         * otherwise extending it if it is retracted.
         */
        void Toggle();

        /**
         * Returns if the piston is currently extended.
         */
        bool IsExtended();

    private:
        std::unique_ptr<frc::Solenoid> extendSolenoid;
        std::unique_ptr<frc::Solenoid> retractSolenoid;
    };
};