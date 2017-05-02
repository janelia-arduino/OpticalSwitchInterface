// ----------------------------------------------------------------------------
// 5x3.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "5x3.h"


#if defined(__MK64FX512__)

namespace optical_switch_interface
{
namespace constants
{
const modular_server::HardwareInfo hardware_info =
  {
    .name_ptr=&hardware_name,
    .part_number=1230,
    .version_major=1,
    .version_minor=0,
  };

const size_t enable_pin = 2;

const size_t encoder_a_pins[ENCODER_COUNT] =
  {
    3,
  };

const size_t encoder_b_pins[ENCODER_COUNT] =
  {
    4,
  };

const size_t output_pins[OUTPUT_COUNT] =
  {
    20,
    21,
    22,
    23,
  };

// Interrupts

// Units

// Properties

// Parameters

// Functions

// Callbacks

// Errors
}
}
#endif
