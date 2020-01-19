#pragma once
#include "rechner_reg.h"
#include "rechner_register_map.h"

namespace rechner
{
  namespace SYS
  {
    class rcc
    {
      public:
      rcc();
      static void enable_clock_gpio_a()
      {
        reg rcc_ahb1enr(rcc_base + UINT32_C(0x30));
        rcc_ahb1enr.set_bit(BIT_0);
      }
    };
  }
}