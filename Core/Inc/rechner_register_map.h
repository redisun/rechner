#pragma once
#include <cstdint>

namespace rechner
{
	namespace SYS
	{

		/* Base Addresses */

		constexpr std::uint32_t flash_base= UINT32_C(0x08000000);
		constexpr std::uint32_t flash_end= UINT32_C(0x0807FFFF);
		constexpr std::uint32_t flash_otp_base= UINT32_C(0x1FFF7800);
		constexpr std::uint32_t flash_otp_end= UINT32_C(0x1FFF7A0F);

		constexpr std::uint32_t sram1_base= UINT32_C(0x20000000);
		constexpr std::uint32_t sram2_base= UINT32_C(0x2001C000);
		constexpr std::uint32_t sram1_bitband_base= UINT32_C(0x22000000);
		constexpr std::uint32_t sram2_bitband_base= UINT32_C(0x22380000);
		constexpr std::uint32_t backup_sram_base= UINT32_C(0x40024000);

		constexpr std::uint32_t fmc_r_base= UINT32_C(0xA0000000);
		constexpr std::uint32_t quad_spi_base= UINT32_C(0xA0001000);

		constexpr std::uint32_t peripheral_base= UINT32_C(0x40000000);

		/* Peripheral Memory Map */

		constexpr std::uint32_t apb1_peripheral_base= peripheral_base;
		constexpr std::uint32_t apb2_peripheral_base= (peripheral_base + UINT32_C(0x00010000));
		constexpr std::uint32_t ahb1_peripheral_base= (peripheral_base + UINT32_C(0x00020000));
		constexpr std::uint32_t ahb2_peripheral_base= (peripheral_base + UINT32_C(0x10000000));

		/* APB1 Peripheral Register */

		constexpr std::uint32_t tim2_base= (apb1_peripheral_base + UINT32_C(0x0000));
		constexpr std::uint32_t tim3_base= (apb1_peripheral_base + UINT32_C(0x0400));
		constexpr std::uint32_t tim4_base= (apb1_peripheral_base + UINT32_C(0x0800));
		constexpr std::uint32_t tim5_base= (apb1_peripheral_base + UINT32_C(0x0C00));
		constexpr std::uint32_t tim6_base= (apb1_peripheral_base + UINT32_C(0x1000));
		constexpr std::uint32_t tim7_base= (apb1_peripheral_base + UINT32_C(0x1400));
		constexpr std::uint32_t tim12_base= (apb1_peripheral_base + UINT32_C(0x1800));
		constexpr std::uint32_t tim13_base= (apb1_peripheral_base + UINT32_C(0x1C00));
		constexpr std::uint32_t tim14_base= (apb1_peripheral_base + UINT32_C(0x2000));
		constexpr std::uint32_t rtc_base= (apb1_peripheral_base + UINT32_C(0x2800));
		constexpr std::uint32_t wwdg_base= (apb1_peripheral_base + UINT32_C(0x2C00));
		constexpr std::uint32_t iwdg_base= (apb1_peripheral_base + UINT32_C(0x3000));
		constexpr std::uint32_t spi2_base= (apb1_peripheral_base + UINT32_C(0x3800));
		constexpr std::uint32_t spi3_base= (apb1_peripheral_base + UINT32_C(0x3C00));
		constexpr std::uint32_t spdirfrx_base= (apb1_peripheral_base + UINT32_C(0x4000));
		constexpr std::uint32_t usart2_base= (apb1_peripheral_base + UINT32_C(0x4400));
		constexpr std::uint32_t usart3_base= (apb1_peripheral_base + UINT32_C(0x4800));
		constexpr std::uint32_t uart4_base= (apb1_peripheral_base + UINT32_C(0x4C00));
		constexpr std::uint32_t uart5_base= (apb1_peripheral_base + UINT32_C(0x5000));
		constexpr std::uint32_t i2c1_base= (apb1_peripheral_base + UINT32_C(0x5400));
		constexpr std::uint32_t i2c2_base= (apb1_peripheral_base + UINT32_C(0x5800));
		constexpr std::uint32_t i2c3_base= (apb1_peripheral_base + UINT32_C(0x5C00));
		constexpr std::uint32_t fmpi2c1_base= (apb1_peripheral_base + UINT32_C(0x6000));
		constexpr std::uint32_t can1_base= (apb1_peripheral_base + UINT32_C(0x6400));
		constexpr std::uint32_t can2_base= (apb1_peripheral_base + UINT32_C(0x6800));
		constexpr std::uint32_t cec_base= (apb1_peripheral_base + UINT32_C(0x6C00));
		constexpr std::uint32_t pwr_base= (apb1_peripheral_base + UINT32_C(0x7000));
		constexpr std::uint32_t dac_base= (apb1_peripheral_base + UINT32_C(0x7400));

		/* APB2 Peripheral Register */

		constexpr std::uint32_t tim1_base= (apb2_peripheral_base + UINT32_C(0x0000));
		constexpr std::uint32_t tim8_base= (apb2_peripheral_base + UINT32_C(0x0400));
		constexpr std::uint32_t usart1_base= (apb2_peripheral_base + UINT32_C(0x1000));
		constexpr std::uint32_t usart6_base= (apb2_peripheral_base + UINT32_C(0x1400));
		constexpr std::uint32_t adc1_base= (apb2_peripheral_base + UINT32_C(0x2000));
		constexpr std::uint32_t adc2_base= (apb2_peripheral_base + UINT32_C(0x2100));
		constexpr std::uint32_t adc3_base= (apb2_peripheral_base + UINT32_C(0x2200));
		constexpr std::uint32_t adc123_common_base= (apb2_peripheral_base + UINT32_C(0x2300));
		constexpr std::uint32_t sdio_base= (apb2_peripheral_base + UINT32_C(0x2C00));
		constexpr std::uint32_t spi1_base= (apb2_peripheral_base + UINT32_C(0x3000));
		constexpr std::uint32_t spi4_base= (apb2_peripheral_base + UINT32_C(0x3400));
		constexpr std::uint32_t syscfg_base= (apb2_peripheral_base + UINT32_C(0x3800));
		constexpr std::uint32_t exti_base= (apb2_peripheral_base + UINT32_C(0x3C00));
		constexpr std::uint32_t tim9_base= (apb2_peripheral_base + UINT32_C(0x4000));
		constexpr std::uint32_t tim10_base= (apb2_peripheral_base + UINT32_C(0x4400));
		constexpr std::uint32_t tim11_base= (apb2_peripheral_base + UINT32_C(0x4800));

		constexpr std::uint32_t sai1_base= (apb2_peripheral_base + UINT32_C(0x5800));
		constexpr std::uint32_t sai1_block_a_base= (sai1_base + UINT32_C(0x004));
		constexpr std::uint32_t sai1_block_b_base= (sai1_base + UINT32_C(0x024));

		constexpr std::uint32_t sai2_base= (apb2_peripheral_base + UINT32_C(0x5C00));
		constexpr std::uint32_t sai2_block_a_base= (sai2_base + UINT32_C(0x004));
		constexpr std::uint32_t sai2_block_b_base= (sai2_base + UINT32_C(0x024));

		/* GPIO Register */

		constexpr std::uint32_t gpio_a_base= (ahb1_peripheral_base + UINT32_C(0x0000));
		constexpr std::uint32_t gpio_b_base= (ahb1_peripheral_base + UINT32_C(0x0400));
		constexpr std::uint32_t gpio_c_base= (ahb1_peripheral_base + UINT32_C(0x0800));
		constexpr std::uint32_t gpio_d_base= (ahb1_peripheral_base + UINT32_C(0x0C00));
		constexpr std::uint32_t gpio_e_base= (ahb1_peripheral_base + UINT32_C(0x1000));
		constexpr std::uint32_t gpio_f_base= (ahb1_peripheral_base + UINT32_C(0x1400));
		constexpr std::uint32_t gpio_g_base= (ahb1_peripheral_base + UINT32_C(0x1800));
		constexpr std::uint32_t gpio_h_base= (ahb1_peripheral_base + UINT32_C(0x1C00));

		/* AHB1 Peripheral Register */

		constexpr std::uint32_t crc_base= (ahb1_peripheral_base + UINT32_C(0x3000));
		constexpr std::uint32_t rcc_base= (ahb1_peripheral_base + UINT32_C(0x3800));
		constexpr std::uint32_t flash_r_base= (ahb1_peripheral_base + UINT32_C(0x3C00));

		constexpr std::uint32_t dma1_base= (ahb1_peripheral_base + UINT32_C(0x6000));
		constexpr std::uint32_t dma1_stream1_base= (dma1_base + UINT32_C(0x010));
		constexpr std::uint32_t dma1_stream2_base= (dma1_base + UINT32_C(0x028));
		constexpr std::uint32_t dma1_stream0_base= (dma1_base + UINT32_C(0x040));
		constexpr std::uint32_t dma1_stream3_base= (dma1_base + UINT32_C(0x058));
		constexpr std::uint32_t dma1_stream4_base= (dma1_base + UINT32_C(0x070));
		constexpr std::uint32_t dma1_stream5_base= (dma1_base + UINT32_C(0x088));
		constexpr std::uint32_t dma1_stream6_base= (dma1_base + UINT32_C(0x0A0));
		constexpr std::uint32_t dma1_stream7_base= (dma1_base + UINT32_C(0x0B8));

		constexpr std::uint32_t dma2_base= (ahb1_peripheral_base + UINT32_C(0x6400));
		constexpr std::uint32_t dma2_stream0_base= (dma2_base + UINT32_C(0x010));
		constexpr std::uint32_t dma2_stream1_base= (dma2_base + UINT32_C(0x028));
		constexpr std::uint32_t dma2_stream2_base= (dma2_base + UINT32_C(0x040));
		constexpr std::uint32_t dma2_stream3_base= (dma2_base + UINT32_C(0x058));
		constexpr std::uint32_t dma2_stream4_base= (dma2_base + UINT32_C(0x070));
		constexpr std::uint32_t dma2_stream5_base= (dma2_base + UINT32_C(0x088));
		constexpr std::uint32_t dma2_stream6_base= (dma2_base + UINT32_C(0x0A0));
		constexpr std::uint32_t dma2_stream7_base= (dma2_base + UINT32_C(0x0B8));

		/* AHB2 Peripheral Register */

		constexpr std::uint32_t dcmi_base= (ahb2_peripheral_base + UINT32_C(0x50000));

		/* FMC Bank Base Register Addresses */

		constexpr std::uint32_t fmc_bank1_r_base= (fmc_r_base + UINT32_C(0x0000));
		constexpr std::uint32_t fmc_bank1e_r_base= (fmc_r_base + UINT32_C(0x0104));
		constexpr std::uint32_t fmc_bank_3_r_base= (fmc_r_base + UINT32_C(0x0080));
		constexpr std::uint32_t fmc_bank_5_r_base= (fmc_r_base + UINT32_C(0x0140));

		/* Debug MCU Base Register */

		constexpr std::uint32_t dbgmcu_base= UINT32_C(0xE0042000);

		/* USB Base Register */

		constexpr std::uint32_t usb_otg_hs_periph_base= UINT32_C(0x40040000);
		constexpr std::uint32_t usb_otg_fs_periph_base= UINT32_C(0x50000000);

		constexpr std::uint32_t usb_otg_global_base= UINT32_C(0x000);
		constexpr std::uint32_t usb_otg_device_base= UINT32_C(0x800);
		constexpr std::uint32_t usb_otg_in_endpoint_base= UINT32_C(0x900);
		constexpr std::uint32_t usb_otg_out_endpoint_base= UINT32_C(0xB00);
		constexpr std::uint32_t usb_otg_ep_reg_size= UINT32_C(0x20);
		constexpr std::uint32_t usb_otg_host_base= UINT32_C(0x400);
		constexpr std::uint32_t usb_otg_host_port_base= UINT32_C(0x440);
		constexpr std::uint32_t usb_otg_host_channel_base= UINT32_C(0x500);
		constexpr std::uint32_t usb_otg_host_channel_size= UINT32_C(0x20);
		constexpr std::uint32_t usb_otg_pcgcctl_base= UINT32_C(0xE00);
		constexpr std::uint32_t usb_otg_fifo_base= UINT32_C(0x1000);
		constexpr std::uint32_t usb_otg_fifo_size= UINT32_C(0x1000);

		constexpr std::uint32_t uid_base= UINT32_C(0x1FFF7A10);
		constexpr std::uint32_t flashsize_base= UINT32_C(0x1FFF7A22);
		constexpr std::uint32_t package_base= UINT32_C(0x1FFF7BF0);
	}
}
