cmake_minimum_required(VERSION 3.16)

# initialize the SDK based on PICO_SDK_PATH
include(pico_sdk_import.cmake)
project(simo-extras)
#set(CMAKE_C_STANDARD 11)
#set(CMAKE_CXX_STANDARD 17)
# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
# initialize the Pico SDK
pico_sdk_init()




add_executable(simo
	Core/src/main.c
	
	#Core/src/test.c
	)


target_include_directories(simo PUBLIC 
	Core/include/
)



target_link_libraries(simo pico_stdlib)


target_link_libraries( simo

	hardware_irq
	hardware_gpio

	)

	
pico_add_extra_outputs(simo)