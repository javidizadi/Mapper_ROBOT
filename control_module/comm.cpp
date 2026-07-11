#include <Wire.h>

#include "comm.h"
#include "addresses.h"

void comm_init()
{
    Wire.begin();
    Wire.setClock(100000);
}

void comm_update()
{
    // Reserved for future communication logic.
}