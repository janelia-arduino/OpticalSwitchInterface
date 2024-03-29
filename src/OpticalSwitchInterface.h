// ----------------------------------------------------------------------------
// OpticalSwitchInterface.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef OPTICAL_SWITCH_INTERFACE_H
#define OPTICAL_SWITCH_INTERFACE_H
#include <ArduinoJson.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <ConstantVariable.h>
#include <Functor.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>

#include "OpticalSwitchInterface/Constants.h"


class OpticalSwitchInterface : public ModularDeviceBase
{
public:
  virtual void setup();

  void enableAllOutputs();
  void disableAllOutputs();
  bool outputsEnabled();

  int switchRead(size_t switch_index);
  int outputRead(size_t output_index);

private:
  modular_server::Pin pins_[optical_switch_interface::constants::PIN_COUNT_MAX];

  modular_server::Property properties_[optical_switch_interface::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[optical_switch_interface::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[optical_switch_interface::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[optical_switch_interface::constants::CALLBACK_COUNT_MAX];

  bool enabled_;

  // Handlers
  void enableAllOutputsHandler();
  void disableAllOutputsHandler();
  void outputsEnabledHandler();
  void getSwitchInfoHandler();
  void getOutputInfoHandler();
  void invertedElementHandler(size_t element_index);
  void output0Handler(modular_server::Pin * pin_ptr);
  void output1Handler(modular_server::Pin * pin_ptr);
  void output2Handler(modular_server::Pin * pin_ptr);
  void output3Handler(modular_server::Pin * pin_ptr);

};

#endif
