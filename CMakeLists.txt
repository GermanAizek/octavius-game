cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
project(octavius-game)

if(UNIX AND NOT APPLE)
	set(LINUX TRUE)
endif()

set(OCTAVIUS_SRC "copy_resources_debug_x64.bat" "copy_resources_debug_x86.bat" "copy_resources_release_x64.bat" "copy_resources_release_x86.bat" "octavius.cpp" "octavius.h" "Wheel.cpp" "Classes/Wheel.h" "SlotMachine.cpp" "Classes/SlotMachine.h" "Render.cpp" "Classes/Render.h" "Sound.cpp" "Classes/Sound.h" "Timer.cpp" "Classes/Timer.h")
add_executable(octavius ${OCTAVIUS_SRC})

if(LINUX)
	find_package(OpenGL REQUIRED COMPONENTS OpenGL)
	find_package(GLUT REQUIRED)
	find_package(SDL2 REQUIRED)
	
	add_dependencies(octavius OpenGL::OpenGL)
	include_directories(octavius ${SDL2_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
	target_link_libraries(octavius OpenGL::OpenGL GLU SDL2main SDL2_ttf SDL2_image ${GLUT_LIBRARY} ${SDL2_LIBRARIES})
else()
	set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2/include;${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2_image/include;${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2_ttf/include")

	# Support both 32 and 64 bit builds
	if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
	  set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2/lib/x64/SDL2main.lib;${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2_image/lib/x64/SDL2_image.lib;${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2_ttf/lib/x64/SDL2_ttf.lib;")
	else ()
	  set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2/lib/x86/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2/lib/x86/SDL2main.lib;${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2_image/lib/x86/SDL2_image.lib;${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2_ttf/lib/x86/SDL2_ttf.lib;")
	endif ()
	
	set(GL_LIBRARIES "opengl32.lib;glu32.lib;")

	string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

	include_directories(octavius ${SDL2_INCLUDE_DIRS})
	target_link_libraries(octavius ${SDL2_LIBRARIES} ${GL_LIBRARIES})
endif()
