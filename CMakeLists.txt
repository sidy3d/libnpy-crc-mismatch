cmake_minimum_required (VERSION 3.30)

if (MSVC)
  if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT EditAndContinue) # TODO: Ignore ClangCL
  elseif (CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
	set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT ProgramDatabase)
    add_compile_options(/O2;/Ob3;/Zc:inline)
	if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	   add_compile_options(/Qvec-report:2)
	endif()
  endif()
  add_compile_definitions(UNICODE _UNICODE)
  add_compile_options(/EHsc;/GS-;/utf-8;/Gd;/permissive-)
  add_compile_options(/W4)
endif()

project("libnpy-crc-mismatch")

find_package(npy CONFIG REQUIRED)

add_executable ("libnpy-crc-mismatch" "source.cpp")
set_property(TARGET "libnpy-crc-mismatch" PROPERTY CXX_STANDARD 20)

target_link_libraries("libnpy-crc-mismatch" PRIVATE npy::npy)