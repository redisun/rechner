#pragma once

#include <cstdint>
#include <memory>

namespace rechner
{
  namespace SYS
  {
    class reg
    {
      public:
      reg(std::uint32_t addr);
      std::uint32_t get();
      bool get_bit(uint8_t bit_number);
      void set(uint32_t val);
      void set_bit(uint8_t bit_number);

      private:
      volatile std::uint32_t* const address;
    };
  }
}
