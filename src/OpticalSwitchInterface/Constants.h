// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef OPTICAL_SWITCH_INTERFACE_CONSTANTS_H
#define OPTICAL_SWITCH_INTERFACE_CONSTANTS_H
#include <ConstantVariable.h>
#include <ModularServer.h>

#include <EventController.h>


namespace optical_switch_interface
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PROPERTY_COUNT_MAX=1};
enum{PARAMETER_COUNT_MAX=1};
enum{FUNCTION_COUNT_MAX=5};
enum{CALLBACK_COUNT_MAX=4};

extern ConstantString device_name;

extern ConstantString firmware_name;
extern const modular_server::FirmwareInfo firmware_info;

extern ConstantString hardware_name;
extern const modular_server::HardwareInfo hardware_info;

extern const size_t enable_pin;

extern ConstantString pin_string;
extern ConstantString state_string;
extern ConstantString high_string;
extern ConstantString low_string;

// Interrupts

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern ConstantString inverted_property_name;

// Parameters

// Functions
extern ConstantString enable_all_outputs_function_name;
extern ConstantString disable_all_outputs_function_name;
extern ConstantString outputs_enabled_function_name;
extern ConstantString get_switch_info_function_name;
extern ConstantString get_output_info_function_name;

// Callbacks
extern ConstantString output_0_callback_name;
extern ConstantString output_1_callback_name;
extern ConstantString output_2_callback_name;
extern ConstantString output_3_callback_name;

// Errors
}
}
#include "5x3.h"
#include "3x2.h"
#endif
