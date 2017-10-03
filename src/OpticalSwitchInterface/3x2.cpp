// ----------------------------------------------------------------------------
// 3x2.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
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

// Interrupts
CONSTANT_STRING(switch_0_interrupt_name,"switch_0");
CONSTANT_STRING(switch_1_interrupt_name,"switch_1");
CONSTANT_STRING(switch_2_interrupt_name,"switch_2");
CONSTANT_STRING(switch_3_interrupt_name,"switch_3");
ConstantString * switch_interrupt_name_ptrs[INTERRUPT_COUNT_MAX] =
  {
    &switch_0_interrupt_name,
    &switch_1_interrupt_name,
    &switch_2_interrupt_name,
    &switch_3_interrupt_name,
  };

const size_t switch_pins[INTERRUPT_COUNT_MAX] =
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
