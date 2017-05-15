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
        "parameters":[]
      },
      {
        "name":"disableAllOutputs",
        "parameters":[]
      },
      {
        "name":"outputsEnabled",
        "parameters":[],
        "result_info":{
          "type":"bool"
        }
      }
    ],
    "parameters":[],
    "properties":[
      {
        "name":"inverted",
        "type":"array",
        "array_element_type":"bool",
        "functions":[
          "getValue",
          "setValue",
          "getDefaultValue",
          "setValueToDefault",
          "getElementValue",
          "setElementValue",
          "getDefaultElementValue",
          "setElementValueToDefault",
          "setAllElementValues",
          "getArrayLength",
          "setArrayLength"
        ],
        "parameters":[
          "value",
          "element_index",
          "element_value",
          "array_length"
        ]
      }
    ],
    "callbacks":[
      {
        "name":"output0",
        "properties":[],
        "functions":[
          "trigger",
          "attachTo",
          "detachFrom",
          "detachFromAll"
        ],
        "parameters":[
          "interrupt",
          "mode"
        ]
      },
      {
        "name":"output1",
        "properties":[],
        "functions":[
          "trigger",
          "attachTo",
          "detachFrom",
          "detachFromAll"
        ],
        "parameters":[
          "interrupt",
          "mode"
        ]
      },
      {
        "name":"output2",
        "properties":[],
        "functions":[
          "trigger",
          "attachTo",
          "detachFrom",
          "detachFromAll"
        ],
        "parameters":[
          "interrupt",
          "mode"
        ]
      },
      {
        "name":"output3",
        "properties":[],
        "functions":[
          "trigger",
          "attachTo",
          "detachFrom",
          "detachFromAll"
        ],
        "parameters":[
          "interrupt",
          "mode"
        ]
      }
    ]
  }
}
```

## More Detailed Modular Device Information

[modular-devices](https://github.com/janelia-modular-devices/modular-devices)

## Install Library Dependencies

[arduino-libraries](https://github.com/janelia-arduino/arduino-libraries)
