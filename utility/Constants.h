// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef OPTICAL_SWITCH_INTERFACE_CONSTANTS_H
#define OPTICAL_SWITCH_INTERFACE_CONSTANTS_H
#include "ConstantVariable.h"
#include "ModularServer.h"

#include "EventController.h"


namespace optical_switch_interface
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PROPERTY_COUNT_MAX=1};
enum{PARAMETER_COUNT_MAX=2};
enum{FUNCTION_COUNT_MAX=5};
enum{CALLBACK_COUNT_MAX=1};

extern ConstantString device_name;

extern ConstantString firmware_name;
extern const modular_server::FirmwareInfo firmware_info;

extern ConstantString hardware_name;
extern const modular_server::HardwareInfo hardware_info;

extern const size_t enable_pin;

// Interrupts

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]

// Parameters
extern ConstantString encoder_index_parameter_name;

extern ConstantString position_parameter_name;

// Functions
extern ConstantString enable_all_outputs_function_name;
extern ConstantString disable_all_outputs_function_name;
extern ConstantString outputs_enabled_function_name;
extern ConstantString get_positions_function_name;
extern ConstantString set_position_function_name;

// Callbacks

// Errors
}
}
#include "5x3.h"
#include "3x2.h"
#endif
