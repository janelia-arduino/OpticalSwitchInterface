// ----------------------------------------------------------------------------
// 3x2.cpp
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#include "3x2.h"


#if defined(__MK20DX256__)

namespace optical_switch_interface
{
namespace constants
{
const modular_server::HardwareInfo hardware_info =
{
  .name_ptr=&hardware_name,
  .part_number=1221,
  .version_major=1,
  .version_minor=0,
};

const size_t enable_pin = 2;

const size_t output_pins[OUTPUT_COUNT] =
{
  20,
  21,
  22,
  23,
};

// Pins
CONSTANT_STRING(switch_0_pin_name,"switch_0");
CONSTANT_STRING(switch_1_pin_name,"switch_1");
CONSTANT_STRING(switch_2_pin_name,"switch_2");
CONSTANT_STRING(switch_3_pin_name,"switch_3");
ConstantString * switch_pin_name_ptrs[PIN_COUNT_MAX] =
{
  &switch_0_pin_name,
  &switch_1_pin_name,
  &switch_2_pin_name,
  &switch_3_pin_name,
};

const size_t switch_pin_numbers[PIN_COUNT_MAX] =
{
  3,
  4,
  5,
  6,
};

// Units

// Properties
const bool inverted_default[OUTPUT_COUNT] =
{
  false,
  false,
  false,
  false,
};

// Parameters

// Functions

// Callbacks

// Errors
}
}
#endif
