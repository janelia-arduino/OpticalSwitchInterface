// ----------------------------------------------------------------------------
// 3x2.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef OPTICAL_SWITCH_INTERFACE_3X2_CONSTANTS_H
#define OPTICAL_SWITCH_INTERFACE_3X2_CONSTANTS_H
#include "Constants.h"


#if defined(__MK20DX256__)

namespace optical_switch_interface
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{INTERRUPT_COUNT_MAX=4};

enum {OUTPUT_COUNT=4};

extern const size_t output_pins[OUTPUT_COUNT];

// Interrupts
extern ConstantString switch_0_interrupt_name;
extern ConstantString switch_1_interrupt_name;
extern ConstantString switch_2_interrupt_name;
extern ConstantString switch_3_interrupt_name;
extern ConstantString * switch_interrupt_name_ptrs[INTERRUPT_COUNT_MAX];

extern const size_t switch_pins[INTERRUPT_COUNT_MAX];

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]

// Parameters

// Functions

// Callbacks

// Errors
}
}
#endif
#endif
