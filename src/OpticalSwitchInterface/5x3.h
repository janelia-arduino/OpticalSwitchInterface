// ----------------------------------------------------------------------------
// 5x3.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef OPTICAL_SWITCH_INTERFACE_5X3_CONSTANTS_H
#define OPTICAL_SWITCH_INTERFACE_5X3_CONSTANTS_H
#include "Constants.h"


#if defined(__MK64FX512__)

namespace optical_switch_interface
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PIN_COUNT_MAX=4};

enum {OUTPUT_COUNT=4};

extern const size_t output_pins[OUTPUT_COUNT];

// Pins
extern ConstantString switch_0_pin_name;
extern ConstantString switch_1_pin_name;
extern ConstantString switch_2_pin_name;
extern ConstantString switch_3_pin_name;
extern ConstantString * switch_pin_name_ptrs[PIN_COUNT_MAX];

extern const size_t switch_pin_numbers[PIN_COUNT_MAX];

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern const bool inverted_default[OUTPUT_COUNT];

// Parameters

// Functions

// Callbacks

// Errors
}
}
#endif
#endif
