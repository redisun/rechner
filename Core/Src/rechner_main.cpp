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

extern UART_HandleTypeDef huart2;

int rechner_main()
{
  char str[80];
  std::uint8_t recv_size;
  rechner::IO::GPIO::port gpioa(rechner::IO::GPIO_A);
  volatile size_t gpio_size = sizeof(rechner::IO::GPIO::port);
  volatile size_t reg_size = sizeof(rechner::SYS::reg);
  volatile size_t gpio_a_size = sizeof(gpioa);
  rechner::SYS::rcc::enable_clock_gpio_a();
  gpioa.configure_pin();
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
    HAL_UART_Receive(&huart2, reinterpret_cast<std::uint8_t*>(&recv_size), 1, HAL_MAX_DELAY);
    //HAL_UART_Receive(&huart2, reinterpret_cast<std::uint8_t*>(str), recv_size, HAL_MAX_DELAY);
    HAL_Delay(100);
  }
}
