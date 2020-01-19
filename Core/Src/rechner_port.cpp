#include "rechner_port.h"

namespace rechner
{
  namespace IO
  {
    namespace GPIO
    {
      port::port(std::uint32_t base_address)
        //: addr(reinterpret_cast<volatile uint32_t* const>(base_address))
      {
        moder = std::make_unique<rechner::SYS::reg>(base_address);
        otyper = std::make_unique<rechner::SYS::reg>(base_address + UINT32_C(0x04));
        ospeedr = std::make_unique<rechner::SYS::reg>(base_address + UINT32_C(0x08));
        pupdr = std::make_unique<rechner::SYS::reg>(base_address + UINT32_C(0x0C));
        idr = std::make_unique<rechner::SYS::reg>(base_address + UINT32_C(0x10));
        odr = std::make_unique<rechner::SYS::reg>(base_address + UINT32_C(0x14));
        lckr = std::make_unique<rechner::SYS::reg>(base_address + UINT32_C(0x1C));
        bsrr = std::make_unique<rechner::SYS::reg>(base_address + UINT32_C(0x18));
        afrl = std::make_unique<rechner::SYS::reg>(base_address + UINT32_C(0x20));
        afrh = std::make_unique<rechner::SYS::reg>(base_address + UINT32_C(0x24));
      }

      void
      port::set_pin(gpio_pin_number_t pin_number)
      {
        bsrr->set_bit(pin_number);
        pin_state = true;
      }

      void
      port::reset_pin(gpio_pin_number_t pin_number)
      {
        bsrr->set_bit(UINT8_C(pin_number + 16));
        pin_state = false;
      }

      void
      port::toggle_pin(gpio_pin_number_t pin_number)
      {
        if (pin_state)
          reset_pin(pin_number);
        else
          set_pin(pin_number);
        
        return; 
      }

      bool
      port::read_pin(gpio_pin_number_t pin_number)
      {
        return (idr->get() & static_cast<std::uint32_t>(1 << pin_number));
      }

      void
      port::configure_pin()
      {
        pin_configuration_t pin_config;
        pin_config.pin = rechner::IO::GPIO::PIN_5;
        pin_config.mode = rechner::IO::GPIO::PIN_MODE_OUTPUT;
        pin_config.pull_up_down = rechner::IO::GPIO::PIN_NO_PULL_UP_DOWN;
        pin_config.speed = rechner::IO::GPIO::PIN_TYPE_SPEED_LOW;
        pin_config.type = rechner::IO::GPIO::PIN_TYPE_PUSH_PULL;
        
        std::uint32_t temp_mode_r = moder->get();
        std::uint32_t bit_pos = (pin_config.mode << (pin_config.pin * 2));
        temp_mode_r |= (pin_config.mode << (pin_config.pin * 2));
        //moder->set(temp_reg || (pin_config.mode << (pin_config.pin * 2)));
        std::uint32_t temp_mode_test = pin_config.mode;

        std::uint32_t temp_type_r = otyper->get();
        temp_type_r |= (pin_config.type << pin_config.pin);
        std::uint32_t temp_type_test = temp_type_r;

        std::uint32_t temp_speed_r = ospeedr->get();
        temp_speed_r |= (pin_config.speed << (pin_config.pin * 2));
        std::uint32_t temp_speed_test = temp_speed_r;

        std::uint32_t temp_pullupdown_r = pupdr->get();
        temp_pullupdown_r = (pin_config.pull_up_down << (pin_config.pin * 2));
        std::uint32_t temp_pullupdown_test = temp_pullupdown_r;

        moder->set(temp_mode_r);
        otyper->set(temp_type_r);
        ospeedr->set(temp_speed_r);
        pupdr->set(temp_pullupdown_r);
      }
    }
  }
}
