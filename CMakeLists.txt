cmake_minimum_required (VERSION 2.6.4)
project(Plib)


file(READ version versionFile)
string(STRIP ${versionFile} PLIB_VERSION)


if(NOT DEFINED CMAKE_INSTALL_LIBDIR)
    set(CMAKE_INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/lib)
endif(NOT DEFINED CMAKE_INSTALL_LIBDIR)


if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-write-strings -Wno-int-to-pointer-cast")
endif(CMAKE_COMPILER_IS_GNUCC)


# Warning when build is not an out-of-source build.
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" InSourceBuild)
if(InSourceBuild)
    message(WARNING  "Avoid building inside the source tree!")
    message(WARNING  "Create a separate build directory instead (i.e. 'build') and call CMake from there: ")
    message(WARNING  "  mkdir ../build && cd ../build && cmake ${CMAKE_SOURCE_DIR}")
endif(InSourceBuild)


find_package(OpenGL  REQUIRED)


option(ENABLE_FNT    "Set to ON to build the Font lib (default)" ON)
option(ENABLE_JS     "Set to ON to build the Joystick lib (default)" ON)
option(ENABLE_NET    "Set to ON to build the Net lib (default)" ON)
option(ENABLE_PSL    "Set to ON to build the Psl lib (default)" ON)
option(ENABLE_PUAUX  "Set to ON to build the PuAux lib (default)" ON)
option(ENABLE_PUI    "Set to ON to build the Pui lib (default)" ON)
option(ENABLE_PW     "Set to ON to build the Pw lib (default)" ON)
option(ENABLE_SG     "Set to ON to build the Sg lib (default)" ON)
option(ENABLE_SL     "Set to ON to build the Sl lib (default)" ON)
option(ENABLE_SSG    "Set to ON to build the Ssg lib (default)" ON)
option(ENABLE_SSGAUX "Set to ON to build the SsgAux lib (default)" ON)
option(ENABLE_UTIL   "Set to ON to build the Util lib (default)" ON)


message(STATUS "Library installation directory: ${CMAKE_INSTALL_LIBDIR}")
add_subdirectory(src)

