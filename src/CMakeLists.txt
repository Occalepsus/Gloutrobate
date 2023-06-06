
file(GLOB SOURCES CONFIGURE_DEPENDS *.h *.cpp)

add_library(src ${SOURCES} "myMain.h" "Graphics/Graphics.h"  "Graphics/Graphics.cpp")
target_include_directories(src PUBLIC ./)

target_link_libraries(src PUBLIC sfml-graphics)