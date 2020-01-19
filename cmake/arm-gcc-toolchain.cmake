set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR armv7-m)
set(GCC_TOOLCHAIN_PREFIX "arm-none-eabi-")
set(CMAKE_CROSSCOMPILING 1)
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "" )
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "" )
set(CMAKE_EXECUTABLE_SUFFIX .elf)

message(STATUS "TOOLCHAIN PREFIX ------- ${GCC_TOOLCHAIN_PREFIX}")

set(UTIL_SEARCH_CMD which)

execute_process(
  COMMAND ${UTIL_SEARCH_CMD} ${GCC_TOOLCHAIN_PREFIX}g++
  OUTPUT_VARIABLE BINUTILS_PATH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
get_filename_component(TOOLCHAIN_PATH ${BINUTILS_PATH} DIRECTORY)

message(STATUS "TOOLCHAIN PATH ------- ${TOOLCHAIN_PATH}")

set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_C_COMPILER "${GCC_TOOLCHAIN_PREFIX}gcc")
set(CMAKE_CXX_COMPILER "${GCC_TOOLCHAIN_PREFIX}g++")
set(CMAKE_ASM_COMPILER "${GCC_TOOLCHAIN_PREFIX}as")

set(NM ${GCC_TOOLCHAIN_PREFIX}nm)
set(OBJDUMP ${GCC_TOOLCHAIN_PREFIX}objdump)
set(OBJCOPY ${GCC_TOOLCHAIN_PREFIX}objcopy)
set(READELF ${GCC_TOOLCHAIN_PREFIX}readelf)
set(SIZE ${GCC_TOOLCHAIN_PREFIX}size)
set(CPPFILT ${GCC_TOOLCHAIN_PREFIX}c++filt)

#set(LINKER_SCRIPT "${BASE_DIR}/src/startup/stm.ld")
set(LINKER_SCRIPT "${BASE_DIR}/STM32F446RETX_FLASH.ld")

set(MAP_FILE ${TARGET}.map)
set(SYMBOL_LISTING_FILE ${TARGET}_readelf.txt)
set(HEX_FILE ${TARGET}.map)
set(BIN_FILE ${TARGET}.map)

set(DEFINITIONS "${DEFINITIONS} -DSTM32F446xx")
set(DEFINITIONS "${DEFINITIONS} -DUSE_HAL_DRIVER")

set(POSTBUILD_GEN_SYMBOL_LISTING ${READELF} --syms ${TARGET}.elf > ${TARGET}_readelf.txt)
set(POSTBUILD_GEN_HEX ${OBJCOPY} -O ihex ${TARGET}.elf ${TARGET}.hex)
set(POSTBUILD_GEN_BIN ${OBJCOPY} -S -O binary ${TARGET}.elf ${TARGET}.bin)

set(WARNING_FLAGS "-Wall -Wextra -pedantic -Wmain -Wundef -Wsign-conversion -Wunused-parameter -Wuninitialized -Wmissing-declarations -Wshadow -Wunreachable-code -Wswitch-default -Wcast-align -Wmissing-include-dirs -Winit-self -Wfloat-equal -Wdouble-promotion")

set(GCCFLAGS "-g ${WARNING_FLAGS} -fno-exceptions -ffunction-sections -fdata-sections")

set(_CFLAGS "${GCCFLAGS} -Wunsuffixed-float-constants -std=c11")

set(_CXXFLAGS "${GCCFLAGS} -std=c++17 -fno-rtti -fstrict-enums -fno-use-cxa-atexit -fno-use-cxa-get-exception-ptr -fno-nonansi-builtins -fno-threadsafe-statics -fno-enforce-eh-specs -ftemplate-depth=32 -Wzero-as-null-pointer-constant")

set(_AFLAGS "${GCCFLAGS}")

set(_LDFLAGS "${GCCFLAGS} -Wl,--gc-sections -Wl,-Map,${MAP_FILE}")

set(COMMON_COMPILE_FLAGS "-finline-functions -finline-limit=32 -mcpu=${CPU} -mtune=${CPU} -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -mno-unaligned-access -mno-long-calls")

set(COMMON_ASM_FLAGS "-mcpu=${CPU} -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCCFLAGS} ${COMMON_COMPILE_FLAGS} ${DEFINITIONS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCCFLAGS} ${COMMON_COMPILE_FLAGS} ${DEFINITIONS}")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${COMMON_ASM_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${_LDFLAGS} -T ${LINKER_SCRIPT} -Wl,-Map,${MAP_FILE}")