
file(GLOB SOURCES CONFIGURE_DEPENDS *.h *.cpp)

add_library(src ${SOURCES} "myMain.h" "Engine/Graphics.h"  "Engine/Graphics.cpp" "Engine/GameObject.h" "Engine/GameObject.cpp" "Engine/Physics.cpp" "Engine/Engine.h" "Engine/Engine.cpp" "Player.h" "Engine/ContactListener.h" "Engine/ContactListener.cpp")
target_include_directories(src PUBLIC ./)

target_link_libraries(src PUBLIC sfml-graphics box2d)
