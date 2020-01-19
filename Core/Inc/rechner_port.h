#pragma once

#include <rechner_reg.h>
#include <rechner_register_map.h>
#include <memory>

namespace rechner
{
  namespace IO
  {
    constexpr static const std::uint32_t GPIO_A = rechner::SYS::gpio_a_base;
    constexpr static const std::uint32_t GPIO_B = rechner::SYS::gpio_b_base;
    constexpr static const std::uint32_t GPIO_C = rechner::SYS::gpio_c_base;
    constexpr static const std::uint32_t GPIO_D = rechner::SYS::gpio_d_base;
    constexpr static const std::uint32_t GPIO_E = rechner::SYS::gpio_e_base;
    constexpr static const std::uint32_t GPIO_F = rechner::SYS::gpio_f_base;
    constexpr static const std::uint32_t GPIO_G = rechner::SYS::gpio_g_base;
    constexpr static const std::uint32_t GPIO_H = rechner::SYS::gpio_h_base;

    namespace GPIO
    {
      typedef std::uint8_t gpio_pin_number_t;
      typedef std::uint32_t gpio_pin_mode_t;
      typedef std::uint32_t gpio_pin_type_t;
      typedef std::uint32_t gpio_pin_pull_up_down_t;
      typedef std::uint32_t gpio_pin_speed_t;
      typedef std::uint32_t gpio_pin_afunction_t;

      constexpr static gpio_pin_number_t PIN_0 = UINT8_C(0);
      constexpr static gpio_pin_number_t PIN_1 = UINT8_C(1);
      constexpr static gpio_pin_number_t PIN_2 = UINT8_C(2);
      constexpr static gpio_pin_number_t PIN_3 = UINT8_C(3);
      constexpr static gpio_pin_number_t PIN_4 = UINT8_C(4);
      constexpr static gpio_pin_number_t PIN_5 = UINT8_C(5);
      constexpr static gpio_pin_number_t PIN_6 = UINT8_C(6);
      constexpr static gpio_pin_number_t PIN_7 = UINT8_C(7);
      constexpr static gpio_pin_number_t PIN_8 = UINT8_C(8);
      constexpr static gpio_pin_number_t PIN_9 = UINT8_C(9);
      constexpr static gpio_pin_number_t PIN_10 = UINT8_C(10);
      constexpr static gpio_pin_number_t PIN_11 = UINT8_C(11);
      constexpr static gpio_pin_number_t PIN_12 = UINT8_C(12);
      constexpr static gpio_pin_number_t PIN_13 = UINT8_C(13);
      constexpr static gpio_pin_number_t PIN_14 = UINT8_C(14);
      constexpr static gpio_pin_number_t PIN_15 = UINT8_C(15);

      constexpr static gpio_pin_mode_t PIN_MODE_INPUT = UINT32_C(0x00);
      constexpr static gpio_pin_mode_t PIN_MODE_OUTPUT = UINT32_C(0x01);
      constexpr static gpio_pin_mode_t PIN_MODE_AF = UINT32_C(0x02);
      constexpr static gpio_pin_mode_t PIN_MODE_ANALOG = UINT32_C(0x03);

      constexpr static gpio_pin_type_t PIN_TYPE_PUSH_PULL = UINT32_C(0x00);
      constexpr static gpio_pin_type_t PIN_TYPE_OPEN_DRAIN = UINT32_C(0x01);

      constexpr static gpio_pin_speed_t PIN_TYPE_SPEED_LOW = UINT32_C(0x00);
      constexpr static gpio_pin_speed_t PIN_TYPE_SPEED_MEDIUM = UINT32_C(0x01);
      constexpr static gpio_pin_speed_t PIN_TYPE_SPEED_HIGH = UINT32_C(0x02);
      constexpr static gpio_pin_speed_t PIN_TYPE_SPEED_VERY_HIGH = UINT32_C(0x03);

      constexpr static gpio_pin_pull_up_down_t PIN_NO_PULL_UP_DOWN = UINT32_C(0x00);
      constexpr static gpio_pin_pull_up_down_t PIN_PULL_UP = UINT32_C(0x01);
      constexpr static gpio_pin_pull_up_down_t PIN_PULL_DOWN = UINT32_C(0x02);

      typedef struct pin_configuration {
        gpio_pin_number_t pin;
        gpio_pin_mode_t mode;
        gpio_pin_type_t type;
        gpio_pin_pull_up_down_t pull_up_down;
        gpio_pin_speed_t speed;
        gpio_pin_afunction_t alternate_function;
      } pin_configuration_t;

      class port
      {
        public:
        port(std::uint32_t base_address);
        void set_pin(gpio_pin_number_t pin_number);
        void reset_pin(gpio_pin_number_t pin_number);
        bool read_pin(gpio_pin_number_t pin_number);
        void toggle_pin(gpio_pin_number_t pin_number);
        void configure_pin();

        private:
        //volatile std::uint32_t* const addr;
        //std::uint32_t addr;
        bool pin_state = false;

        std::unique_ptr<rechner::SYS::reg> moder = nullptr;
        std::unique_ptr<rechner::SYS::reg> otyper = nullptr;
        std::unique_ptr<rechner::SYS::reg> ospeedr = nullptr;
        std::unique_ptr<rechner::SYS::reg> pupdr = nullptr;
        std::unique_ptr<rechner::SYS::reg> idr = nullptr;
        std::unique_ptr<rechner::SYS::reg> odr = nullptr;
        std::unique_ptr<rechner::SYS::reg> bsrr = nullptr;
        std::unique_ptr<rechner::SYS::reg> lckr = nullptr;
        std::unique_ptr<rechner::SYS::reg> afrl = nullptr;
        std::unique_ptr<rechner::SYS::reg> afrh = nullptr;
      };
    }
    
  }
}
