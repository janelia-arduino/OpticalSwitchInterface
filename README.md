# OpticalSwitchInterface

Authors:

    Peter Polidoro <polidorop@janelia.hhmi.org>

License:

    BSD

## Ancestors

[ModularServer](https://github.com/janelia-arduino/ModularServer)

[ModularDeviceBase](https://github.com/janelia-arduino/ModularDeviceBase)

## Clients

## Devices

[modular_device_base](https://github.com/janelia-modular-devices/modular_device_base.git)

[optical_switch_interface](https://github.com/janelia-modular-devices/optical_switch_interface.git)

## API NAMES

```json
{
  "id":"getApi",
  "result":{
    "firmware":["OpticalSwitchInterface"],
    "verbosity":"NAMES",
    "functions":[
      "enableAllOutputs",
      "disableAllOutputs",
      "outputsEnabled",
      "getSwitchInfo",
      "getOutputInfo"
    ],
    "properties":[
      "inverted"
    ],
    "callbacks":[
      "output0",
      "output1",
      "output2",
      "output3"
    ]
  }
}
```

## API GENERAL

[API GENERAL](./api/)

## More Detailed Modular Device Information

[modular-devices](https://github.com/janelia-modular-devices/modular-devices)

## Install Library Dependencies

[arduino-libraries](https://github.com/janelia-arduino/arduino-libraries)
