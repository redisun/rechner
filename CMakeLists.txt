include (CMakeForceCompiler)

cmake_minimum_required(VERSION 3.1.0)

CMAKE_FORCE_C_COMPILER(arm-none-eabi-gcc GCC)
CMAKE_FORCE_CXX_COMPILER(arm-none-eabi-g++ GCC)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(rechner-hal C CXX ASM)
set(TARGET stm32)
set(APP rechner_hal)

set(BASE_DIR ${CMAKE_CURRENT_LIST_DIR})

set(CPU "cortex-m4")

include("arm-gcc-toolchain")

set(PARSE_SYMBOL_OPTIONS --print-size)

set(APP_INCLUDE Core/Inc)
set(CMSIS_INCLUDE Drivers/CMSIS/Include)
set(CMSIS_DEVICE_INCLUDE Drivers/CMSIS/Device/ST/STM32F4xx/Include)
set(STM_HAL_INCLUDE Drivers/STM32F4xx_HAL_Driver/Inc)
set(STM_LEGACY_INCLUDE Drivers/STM32F4xx_HAL_Driver/Inc/Legacy)

file(GLOB_RECURSE APP_INCLUDE_F ${APP_INCLUDE}/*.h)
file(GLOB_RECURSE CMSIS_INCLUDE_F ${CMSIS_INCLUDE}/*.h)
file(GLOB_RECURSE CMSIS_DEVICE_INCLUDE_F ${CMSIS_DEVICE_INCLUDE}/*.h)
file(GLOB_RECURSE STM_HAL_INCLUDE_F ${STM_HAL_INCLUDE}/*.h)
file(GLOB_RECURSE STM_LEGACY_INCLUDE_F ${STM_LEGACY_INCLUDE}/*.h)

file(GLOB_RECURSE APP_C_SOURCES Core/Src/*.c)
file(GLOB_RECURSE APP_CXX_SOURCES Core/Src/*.cpp)
file(GLOB_RECURSE STM_HAL_C_SOURCES Drivers/STM32F4xx_HAL_Driver/Src/*.c)
file(GLOB_RECURSE ARM_ST_STARTUP Core/Startup/*.s)

set(SOURCES ${APP_C_SOURCES} ${APP_CXX_SOURCES} ${STM_HAL_C_SOURCES} ${ARM_ST_STARTUP})

include_directories(${APP_INCLUDE} ${CMSIS_INCLUDE} ${CMSIS_DEVICE_INCLUDE} ${STM_HAL_INCLUDE} ${STM_LEGACY_INCLUDE})

add_executable(${TARGET} ${SOURCES})

set_target_properties(${TARGET} PROPERTIES OUTPUT_NAME ${TARGET})

add_custom_command(TARGET ${TARGET} POST_BUILD

    COMMENT "Generating post build artifacts"

    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}

    # generate assembly listing
    COMMAND ${OBJDUMP} -h -S ${TARGET}.elf > ${TARGET}.lss

    # parsing symbols with nm to generate: ${APP}_nm.txt
    COMMAND ${NM} --numeric-sort ${PARSE_SYMBOL_OPTIONS} ${TARGET}.elf > ${TARGET}_nm.txt

    # demangling symbols with c++filt to generate: ${APP}_cppfilt.txt
    COMMAND ${NM} --numeric-sort ${PARSE_SYMBOL_OPTIONS} ${TARGET}.elf | ${CPPFILT} > ${TARGET}_cppfilt.txt

    # creating size summary table with size to generate: ${APP}_size.txt
    COMMAND ${SIZE} -A -t ${TARGET}.elf > ${TARGET}_size.txt

    # parsing symbols with readelf to generate: ${APP}_readelf.txt
    COMMAND ${POSTBUILD_GEN_SYMBOL_LISTING}
    
    # creating hex module: ${APP}.hex
    COMMAND ${POSTBUILD_GEN_HEX}

    # creating hex module: ${APP}.bin
    COMMAND ${POSTBUILD_GEN_BIN}
)

install(FILES
    ${CMAKE_BINARY_DIR}/${TARGET}${CMAKE_EXECUTABLE_SUFFIX}
    ${CMAKE_BINARY_DIR}/${TARGET}.lss
    ${CMAKE_BINARY_DIR}/${TARGET}_cppfilt.txt
    ${CMAKE_BINARY_DIR}/${TARGET}_size.txt
    ${CMAKE_BINARY_DIR}/${MAP_FILE}
    ${CMAKE_BINARY_DIR}/${SYMBOL_LISTING_FILE}
    ${CMAKE_BINARY_DIR}/${HEX_FILE}
    ${CMAKE_BINARY_DIR}/${BIN_FILE}

    DESTINATION

    ${CMAKE_CURRENT_SOURCE_DIR}/bin/${APP}
)

add_custom_target(flash_shutdown
    WORKING_DIRECTORY ${BASE_DIR}
    COMMAND openocd -f .vscode/openocd_flash_verify_shutdown.cfg
    DEPENDS ${CMAKE_BINARY_DIR}/${TARGET}.elf
)