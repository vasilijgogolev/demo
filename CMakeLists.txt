cmake_minimum_required(VERSION 3.18.0 FATAL_ERROR)
project(demo)
set(CMAKE_CXX_STANDARD 17)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_compile_options("/std:c++17")
	add_compile_options("/bigobj")
endif()

if (WIN32)
	set(WIN32 True)
	add_definitions(-DWIN32)
endif(WIN32)

if (MACOS)
	set(MACOSX True)
	add_definitions(-DMACOS)
endif(MACOS)

if (LINUX)
	set(LINUX True)
	add_definitions(-DLINUX)

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
	set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -stdlib=libc++")
endif(LINUX)

file(GLOB_RECURSE SOURCES "src/*.*")

add_subdirectory(engine)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} engine)
set_target_properties(${PROJECT_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
	RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}
	RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

source_group(TREE "${CMAKE_SOURCE_DIR}/src" FILES ${SOURCES})

if (MACOS)
	set(CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE PRE_TEST)
endif(MACOS)

set(INSTALL_GTEST OFF CACHE BOOL "do not install gtest" FORCE)
set(BUILD_GMOCK ON CACHE BOOL "do not build gmock" FORCE)

include(FetchContent)
FetchContent_Declare(googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG        release-1.12.1
		)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE TEST_SOURCES "tests/*.*")

add_executable(
		tests_executable
		${TEST_SOURCES}
)

target_link_libraries(tests_executable gtest gmock)
set_target_properties(tests_executable PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
		RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}
		RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

include(GoogleTest)
gtest_discover_tests(tests_executable)