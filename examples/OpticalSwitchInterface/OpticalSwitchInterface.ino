#include <OpticalSwitchInterface.h>


OpticalSwitchInterface dev;

void setup()
{
  dev.setup();
  dev.startServer();
}

void loop()
{
  dev.update();
}
