
file(GLOB SOURCES CONFIGURE_DEPENDS *.h *.cpp)

add_library(src ${SOURCES} "myMain.h" "Engine/Graphics.h"  "Engine/Graphics.cpp" "Engine/GameObject.h" "Engine/GameObject.cpp")
target_include_directories(src PUBLIC ./)

target_link_libraries(src PUBLIC sfml-graphics)