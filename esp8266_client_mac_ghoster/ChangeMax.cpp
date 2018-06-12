#include "ChangeMac.hpp"
#include <Arduino.h>
extern "C" {
#include <user_interface.h>
}

void
makeRandomMac(uint8_t mac[6])
{
 // mac[0]=69;
  for (size_t i = 0; i < 6; ++i) {
    mac[i] = random(256);
  }
  mac[0] = mac[0] & ~0x01;
//  mac[1] = 0x69;
//  mac[2] = 0x96;
}

bool
changeMac(const uint8_t mac[6])
{
  return wifi_set_macaddr(STATION_IF, const_cast<uint8*>(mac));
}
