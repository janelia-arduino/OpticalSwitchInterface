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

## API

```json
{
  "id":"getApi",
  "result":{
    "firmware":["OpticalSwitchInterface"],
    "functions":[
      "enableAllOutputs",
      "disableAllOutputs",
      "outputsEnabled"
    ],
    "parameters":[],
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

## API Verbose

```json
{
  "id":"getApiVerbose",
  "result":{
    "firmware":["OpticalSwitchInterface"],
    "functions":[
      {
        "name":"enableAllOutputs",
        "parameters":[],
        "result_type":null
      },
      {
        "name":"disableAllOutputs",
        "parameters":[],
        "result_type":null
      },
      {
        "name":"outputsEnabled",
        "parameters":[],
        "result_type":"bool"
      }
    ],
    "parameters":[],
    "properties":[
      {
        "name":"inverted",
        "type":"array"
      }
    ],
    "callbacks":[
      {
        "name":"output0",
        "properties":[]
      },
      {
        "name":"output1",
        "properties":[]
      },
      {
        "name":"output2",
        "properties":[]
      },
      {
        "name":"output3",
        "properties":[]
      }
    ]
  }
}
```

## More Detailed Modular Device Information

[modular-devices](https://github.com/janelia-modular-devices/modular-devices)

## Install Library Dependencies

[arduino-libraries](https://github.com/janelia-arduino/arduino-libraries)
