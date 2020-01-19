#pragma once

#include <cstdint>
#include <memory>

namespace rechner
{
  namespace SYS
  {
    typedef std::uint8_t bit_number_t;

    constexpr static bit_number_t BIT_0 = UINT8_C(0);
    constexpr static bit_number_t BIT_1 = UINT8_C(1);
    constexpr static bit_number_t BIT_2 = UINT8_C(2);
    constexpr static bit_number_t BIT_3 = UINT8_C(3);
    constexpr static bit_number_t BIT_4 = UINT8_C(4);
    constexpr static bit_number_t BIT_5 = UINT8_C(5);
    constexpr static bit_number_t BIT_6 = UINT8_C(6);
    constexpr static bit_number_t BIT_7 = UINT8_C(7);
    constexpr static bit_number_t BIT_8 = UINT8_C(8);
    constexpr static bit_number_t BIT_9 = UINT8_C(9);
    constexpr static bit_number_t BIT_10 = UINT8_C(10);
    constexpr static bit_number_t BIT_11 = UINT8_C(11);
    constexpr static bit_number_t BIT_12 = UINT8_C(12);
    constexpr static bit_number_t BIT_13 = UINT8_C(13);
    constexpr static bit_number_t BIT_14 = UINT8_C(14);
    constexpr static bit_number_t BIT_15 = UINT8_C(15);

    class reg
    {
      public:
      reg(std::uint32_t addr);
      std::uint32_t get();
      bool get_bit(bit_number_t bit_number);
      void set(std::uint32_t val);
      void set_bit(bit_number_t bit_number);
      void clear_bit(bit_number_t bit_number);

      private:
      volatile std::uint32_t* const address;
    };
  }
}
