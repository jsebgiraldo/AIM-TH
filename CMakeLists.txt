# The following four lines of boilerplate have to be in your project's CMakeLists
# in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

set(EXTRA_COMPONENT_DIRS ../components/libsmb2)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

list(APPEND EXTRA_COMPONENT_DIRS components/lvgl_esp32_drivers 
								 components/lvgl_esp32_drivers/lvgl_touch 
								 components/lvgl_esp32_drivers/lvgl_tft 
								 $ENV{IDF_PATH}/examples/common_components/protocol_examples_common)

                                 
project(AIM-TH)
