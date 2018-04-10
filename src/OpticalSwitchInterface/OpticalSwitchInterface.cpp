// ----------------------------------------------------------------------------
// OpticalSwitchInterface.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "../OpticalSwitchInterface.h"


using namespace optical_switch_interface;

void OpticalSwitchInterface::setup()
{
  // Parent Setup
  ModularDeviceBase::setup();

  // Reset Watchdog
  resetWatchdog();

  // Pin Setup
  pinMode(constants::enable_pin,OUTPUT);
  enableAllOutputs();

  for (size_t output_index=0; output_index<constants::OUTPUT_COUNT; ++output_index)
  {
    pinMode(constants::output_pins[output_index],OUTPUT);
    digitalWrite(constants::output_pins[output_index],LOW);
  }

  // Set Device ID
  modular_server_.setDeviceName(constants::device_name);

  // Add Hardware
  modular_server_.addHardware(constants::hardware_info,
                              pins_);

  // Pins
  for (size_t pin_index=0; pin_index<constants::PIN_COUNT_MAX; ++pin_index)
  {
    modular_server_.createPin(*constants::switch_pin_name_ptrs[pin_index],
                              constants::switch_pin_numbers[pin_index]);
  }

  // Add Firmware
  modular_server_.addFirmware(constants::firmware_info,
                              properties_,
                              parameters_,
                              functions_,
                              callbacks_);
  // Properties
  modular_server::Property & inverted_property = modular_server_.createProperty(constants::inverted_property_name,constants::inverted_default);
  inverted_property.attachPostSetElementValueFunctor(makeFunctor((Functor1<const size_t> *)0,*this,&OpticalSwitchInterface::invertedElementHandler));

  // Parameters

  // Functions
  modular_server::Function & enable_all_outputs_function = modular_server_.createFunction(constants::enable_all_outputs_function_name);
  enable_all_outputs_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OpticalSwitchInterface::enableAllOutputsHandler));

  modular_server::Function & disable_all_outputs_function = modular_server_.createFunction(constants::disable_all_outputs_function_name);
  disable_all_outputs_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OpticalSwitchInterface::disableAllOutputsHandler));

  modular_server::Function & outputs_enabled_function = modular_server_.createFunction(constants::outputs_enabled_function_name);
  outputs_enabled_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OpticalSwitchInterface::outputsEnabledHandler));
  outputs_enabled_function.setResultTypeBool();

  modular_server::Function & get_switch_info_function = modular_server_.createFunction(constants::get_switch_info_function_name);
  get_switch_info_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OpticalSwitchInterface::getSwitchInfoHandler));
  get_switch_info_function.setResultTypeArray();
  get_switch_info_function.setResultTypeObject();

  modular_server::Function & get_output_info_function = modular_server_.createFunction(constants::get_output_info_function_name);
  get_output_info_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OpticalSwitchInterface::getOutputInfoHandler));
  get_output_info_function.setResultTypeArray();
  get_output_info_function.setResultTypeObject();

  // Callbacks
  modular_server::Callback & output_0_callback = modular_server_.createCallback(constants::output_0_callback_name);
  output_0_callback.attachFunctor(makeFunctor((Functor1<modular_server::Pin *> *)0,*this,&OpticalSwitchInterface::output0Handler));
  output_0_callback.attachTo(*(constants::switch_pin_name_ptrs[0]),modular_server::constants::pin_mode_interrupt_change);

  modular_server::Callback & output_1_callback = modular_server_.createCallback(constants::output_1_callback_name);
  output_1_callback.attachFunctor(makeFunctor((Functor1<modular_server::Pin *> *)0,*this,&OpticalSwitchInterface::output1Handler));
  output_1_callback.attachTo(*(constants::switch_pin_name_ptrs[1]),modular_server::constants::pin_mode_interrupt_change);

  modular_server::Callback & output_2_callback = modular_server_.createCallback(constants::output_2_callback_name);
  output_2_callback.attachFunctor(makeFunctor((Functor1<modular_server::Pin *> *)0,*this,&OpticalSwitchInterface::output2Handler));
  output_2_callback.attachTo(*(constants::switch_pin_name_ptrs[2]),modular_server::constants::pin_mode_interrupt_change);

  modular_server::Callback & output_3_callback = modular_server_.createCallback(constants::output_3_callback_name);
  output_3_callback.attachFunctor(makeFunctor((Functor1<modular_server::Pin *> *)0,*this,&OpticalSwitchInterface::output3Handler));
  output_3_callback.attachTo(*(constants::switch_pin_name_ptrs[3]),modular_server::constants::pin_mode_interrupt_change);

  for (size_t output_index=0; output_index<constants::OUTPUT_COUNT; ++output_index)
  {
    invertedElementHandler(output_index);
  }

}

void OpticalSwitchInterface::enableAllOutputs()
{
  digitalWrite(constants::enable_pin,LOW);
  enabled_ = true;
}

void OpticalSwitchInterface::disableAllOutputs()
{
  digitalWrite(constants::enable_pin,HIGH);
  enabled_ = false;
}

bool OpticalSwitchInterface::outputsEnabled()
{
  return enabled_;
}

int OpticalSwitchInterface::switchRead(const size_t switch_index)
{
  if (switch_index < constants::PIN_COUNT_MAX)
  {
    return digitalRead(constants::switch_pin_numbers[switch_index]);
  }
  return LOW;
}

int OpticalSwitchInterface::outputRead(const size_t output_index)
{
  if (output_index < constants::OUTPUT_COUNT)
  {
    return digitalRead(constants::output_pins[output_index]);
  }
  return LOW;
}

// Handlers must be non-blocking (avoid 'delay')
//
// modular_server_.parameter(parameter_name).getValue(value) value type must be either:
// fixed-point number (int, long, etc.)
// floating-point number (float, double)
// bool
// const char *
// ArduinoJson::JsonArray *
// ArduinoJson::JsonObject *
// const ConstantString *
//
// For more info read about ArduinoJson parsing https://github.com/janelia-arduino/ArduinoJson
//
// modular_server_.property(property_name).getValue(value) value type must match the property default type
// modular_server_.property(property_name).setValue(value) value type must match the property default type
// modular_server_.property(property_name).getElementValue(element_index,value) value type must match the property array element default type
// modular_server_.property(property_name).setElementValue(element_index,value) value type must match the property array element default type

void OpticalSwitchInterface::enableAllOutputsHandler()
{
  enableAllOutputs();
}

void OpticalSwitchInterface::disableAllOutputsHandler()
{
  disableAllOutputs();
}

void OpticalSwitchInterface::outputsEnabledHandler()
{
  bool all_enabled = outputsEnabled();
  modular_server_.response().returnResult(all_enabled);
}

void OpticalSwitchInterface::getSwitchInfoHandler()
{
  modular_server_.response().writeResultKey();

  modular_server_.response().beginArray();

  for (size_t switch_index=0; switch_index<constants::PIN_COUNT_MAX; ++switch_index)
  {
    int state = switchRead(switch_index);
    modular_server_.response().beginObject();

    // modular_server_.response().write(constants::pin_string,constants::switch_pin_numbers[switch_index]);

    if (state == HIGH)
    {
      modular_server_.response().write(constants::state_string,constants::high_string);
    }
    else
    {
      modular_server_.response().write(constants::state_string,constants::low_string);
    }

    modular_server_.response().endObject();
  }

  modular_server_.response().endArray();
}

void OpticalSwitchInterface::getOutputInfoHandler()
{
  modular_server_.response().writeResultKey();

  modular_server_.response().beginArray();

  for (size_t output_index=0; output_index<constants::OUTPUT_COUNT; ++output_index)
  {
    int state = outputRead(output_index);
    modular_server_.response().beginObject();

    // modular_server_.response().write(constants::pin_string,constants::output_pins[output_index]);

    if (state == HIGH)
    {
      modular_server_.response().write(constants::state_string,constants::high_string);
    }
    else
    {
      modular_server_.response().write(constants::state_string,constants::low_string);
    }

    modular_server_.response().endObject();
  }

  modular_server_.response().endArray();
}

void OpticalSwitchInterface::invertedElementHandler(const size_t element_index)
{
  if (element_index < constants::PIN_COUNT_MAX)
  {
    modular_server::Pin & pin = modular_server_.pin(*constants::switch_pin_name_ptrs[element_index]);
    if (element_index == 0)
    {
      output0Handler(&pin);
    }
    else if (element_index == 1)
    {
      output1Handler(&pin);
    }
    else if (element_index == 2)
    {
      output2Handler(&pin);
    }
    else if (element_index == 3)
    {
      output3Handler(&pin);
    }
  }
}

void OpticalSwitchInterface::output0Handler(modular_server::Pin * pin_ptr)
{
  if (pin_ptr)
  {
    size_t output_index = 0;

    bool inverted;
    modular_server_.property(constants::inverted_property_name).getElementValue(output_index,inverted);

    int pin_value = pin_ptr->getValue();

    if (!inverted)
    {
      pin_value = ((pin_value == HIGH) ? HIGH : LOW);
    }
    else
    {
      pin_value = ((pin_value == HIGH) ? LOW : HIGH);
    }

    digitalWrite(constants::output_pins[output_index],pin_value);
  }
}

void OpticalSwitchInterface::output1Handler(modular_server::Pin * pin_ptr)
{
  if (pin_ptr)
  {
    size_t output_index = 1;

    bool inverted;
    modular_server_.property(constants::inverted_property_name).getElementValue(output_index,inverted);

    int pin_value = pin_ptr->getValue();

    if (!inverted)
    {
      pin_value = ((pin_value == HIGH) ? HIGH : LOW);
    }
    else
    {
      pin_value = ((pin_value == HIGH) ? LOW : HIGH);
    }

    digitalWrite(constants::output_pins[output_index],pin_value);
  }
}

void OpticalSwitchInterface::output2Handler(modular_server::Pin * pin_ptr)
{
  if (pin_ptr)
  {
    size_t output_index = 2;

    bool inverted;
    modular_server_.property(constants::inverted_property_name).getElementValue(output_index,inverted);

    int pin_value = pin_ptr->getValue();

    if (!inverted)
    {
      pin_value = ((pin_value == HIGH) ? HIGH : LOW);
    }
    else
    {
      pin_value = ((pin_value == HIGH) ? LOW : HIGH);
    }

    digitalWrite(constants::output_pins[output_index],pin_value);
  }
}

void OpticalSwitchInterface::output3Handler(modular_server::Pin * pin_ptr)
{
  if (pin_ptr)
  {
    size_t output_index = 3;

    bool inverted;
    modular_server_.property(constants::inverted_property_name).getElementValue(output_index,inverted);

    int pin_value = pin_ptr->getValue();

    if (!inverted)
    {
      pin_value = ((pin_value == HIGH) ? HIGH : LOW);
    }
    else
    {
      pin_value = ((pin_value == HIGH) ? LOW : HIGH);
    }

    digitalWrite(constants::output_pins[output_index],pin_value);
  }
}
