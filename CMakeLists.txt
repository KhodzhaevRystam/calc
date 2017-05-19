cmake_minimum_required(VERSION 2.8)

project (Calc)

SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY
	${CMAKE_HOME_DIRECTORY}/Binary
	CACHE PATH
	"Directory for all objects"
)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_HOME_DIRECTORY}/Binary
	CACHE PATH
	"Directory for all objects"
)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
	${CMAKE_HOME_DIRECTORY}/Binary
	CACHE PATH
	"Directory for all objects"
)

if (UNIX)
	set(CMAKE_CXX_FLAGS "-02 -B -fPIC -std=c++11")
	set(CMAKE_CXX_COMPILER "/opt/gcc/4.9.2/bin/c++" CACHE PATH "path to c++ compiler" FORCE)
	set(CMAKE_C_COMPILER "/opt/gcc/4.9.2/bin/gcc" CACHE PATH "path to c++ compiler" FORCE)
endif()

add_definitions(
	-DUNICODE
	-D_CRT_SECURE_NO_WARNINGS
)

#add_subdirectory (main)
add_subdirectory (calculator)



