#include "rechner_reg.h"

namespace rechner
{
  namespace SYS
  {
    reg::reg(std::uint32_t addr) :
      address(reinterpret_cast<volatile std::uint32_t* const>(addr)){};

    std::uint32_t reg::get()
    {
      return *address;
    };

    void reg::set(uint32_t val)
    {
      *address = val;
      //*regi = val;
    };

    bool reg::get_bit(uint8_t bit_number)
    {
      return ((*address & (1 << bit_number)) == (1 << bit_number) ? true : false);
    };

    void reg::set_bit(uint8_t bit_number)
    {
      *address |= (1 << bit_number);
    };
  }
}
