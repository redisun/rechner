#include "rechner_port.h"
#include "rechner_register_map.h"
#include "rechner_rcc.h"
#include "stm32f4xx_hal.h"
#include <memory>

#ifdef __cplusplus
extern "C" {
#endif

int rechner_main();

#ifdef __cplusplus
}
#endif



int rechner_main()
{
  rechner::IO::GPIO::port gpioa(rechner::SYS::gpio_a_base);
  volatile size_t gpio_size = sizeof(rechner::IO::GPIO::port);
  volatile size_t reg_size = sizeof(rechner::SYS::reg);
  volatile size_t gpio_a_size = sizeof(gpioa);
  //rechner::SYS::rcc::enable_clock_gpio_a();
  HAL_Delay(10);
  for(;;)
  {
    gpioa.toggle_pin(rechner::IO::GPIO::PIN_5);
    HAL_Delay(100);
    gpioa.toggle_pin(rechner::IO::GPIO::PIN_5);
    HAL_Delay(50);
    gpioa.toggle_pin(rechner::IO::GPIO::PIN_5);
    HAL_Delay(500);
    gpioa.toggle_pin(rechner::IO::GPIO::PIN_5);
    HAL_Delay(100);
    gpioa.toggle_pin(rechner::IO::GPIO::PIN_5);
    HAL_Delay(100);
    gpioa.toggle_pin(rechner::IO::GPIO::PIN_5);
    HAL_Delay(100);
    gpioa.configure_pin();
    HAL_Delay(100);
  }
}
