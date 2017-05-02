// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Constants.h"


namespace optical_switch_interface
{
namespace constants
{
CONSTANT_STRING(device_name,"optical_switch_interface");

CONSTANT_STRING(firmware_name,"OpticalSwitchInterface");
// Use semantic versioning http://semver.org/
const modular_server::FirmwareInfo firmware_info =
  {
    .name_ptr=&firmware_name,
    .version_major=1,
    .version_minor=0,
    .version_patch=0,
  };

CONSTANT_STRING(hardware_name,"optical_switch_interface");

// Interrupts

// Units

// Properties

// Parameters
CONSTANT_STRING(encoder_index_parameter_name,"encoder_index");

CONSTANT_STRING(position_parameter_name,"position");

// Functions
CONSTANT_STRING(enable_all_outputs_function_name,"enableAllOutputs");
CONSTANT_STRING(disable_all_outputs_function_name,"disableAllOutputs");
CONSTANT_STRING(outputs_enabled_function_name,"outputsEnabled");
CONSTANT_STRING(get_positions_function_name,"getPositions");
CONSTANT_STRING(set_position_function_name,"setPosition");

// Callbacks

// Errors
}
}
