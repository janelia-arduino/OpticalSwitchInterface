// ----------------------------------------------------------------------------
// OpticalSwitchInterface.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef OPTICAL_SWITCH_INTERFACE_H
#define OPTICAL_SWITCH_INTERFACE_H
#include <Flash.h>
#include <EEPROM.h>
#include <Streaming.h>
#include <ArduinoJson.h>
#include <JsonSanitizer.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <MemoryFree.h>
#include <ConstantVariable.h>
#include <SavedVariable.h>
#include <Functor.h>
#include <IndexedContainer.h>
#include <FunctorCallbacks.h>
#include <Watchdog.h>

#include <EncoderFunctors.h>

#include <ModularClient.h>

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

  int switchRead(const size_t switch_index);
  int outputRead(const size_t output_index);

private:
  modular_server::Interrupt interrupts_[optical_switch_interface::constants::INTERRUPT_COUNT_MAX];

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
  void invertedElementHandler(const size_t element_index);
  void output0Handler(modular_server::Interrupt * interrupt_ptr);
  void output1Handler(modular_server::Interrupt * interrupt_ptr);
  void output2Handler(modular_server::Interrupt * interrupt_ptr);
  void output3Handler(modular_server::Interrupt * interrupt_ptr);

};

#endif
