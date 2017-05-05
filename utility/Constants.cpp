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
CONSTANT_STRING(inverted_property_name,"inverted");

// Parameters

// Functions
CONSTANT_STRING(enable_all_outputs_function_name,"enableAllOutputs");
CONSTANT_STRING(disable_all_outputs_function_name,"disableAllOutputs");
CONSTANT_STRING(outputs_enabled_function_name,"outputsEnabled");

// Callbacks
CONSTANT_STRING(output_0_callback_name,"output0");
CONSTANT_STRING(output_1_callback_name,"output1");
CONSTANT_STRING(output_2_callback_name,"output2");
CONSTANT_STRING(output_3_callback_name,"output3");

// Errors
}
}
