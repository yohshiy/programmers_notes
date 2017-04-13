
cmake_minimum_required(VERSION 3.0)
project (coroutine_samples)

include_directories(.)

if(MSVC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
else()
  add_definitions(-std=c++14)
endif()


# Boost
################################################################

if(MSVC)
  set(BOOST_INCLUDE_PATH_DEFAULT C:/local/boost_1_63_0)
  set(BOOST_LIBRARY_PATH_DEFAULT C:/local/boost_1_63_0/lib32-msvc-14.0)
  set(BOOST_COROUTINE_LIB_DEFAULT_RELEASE libboost_coroutine-vc140-mt-s-1_63)
  set(BOOST_COROUTINE_LIB_DEFAULT_DEBUG   libboost_coroutine-vc140-mt-sgd-1_63)
else()
  set(BOOST_INCLUDE_PATH_DEFAULT /usr/local/include)
  set(BOOST_LIBRARY_PATH_DEFAULT /usr/local/lib)  
  set(BOOST_COROUTINE_LIB_DEFAULT_RELEASE libboost_coroutine)
  set(BOOST_COROUTINE_LIB_DEFAULT_DEBUG libboost_coroutine)
endif()


set(BOOST_INCLUDE_PATH "${BOOST_INCLUDE_PATH_DEFAULT}"
  CACHE PATH "Set a directory of boost header files")
set(BOOST_LIBRARY_PATH "${BOOST_LIBRARY_PATH_DEFAULT}"
  CACHE PATH "Set a directory of boost library files")
set(BOOST_COROUTINE_LIB_RELEASE "${BOOST_COROUTINE_LIB_DEFAULT_RELEASE}"
  CACHE STRING "Set a name of a boost coroutine library (Release")
set(BOOST_COROUTINE_LIB_DEBUG   "${BOOST_COROUTINE_LIB_DEFAULT_DEBUG}"
  CACHE STRING "Set a name of a boost coroutine library (Debug)")

message("-- == Boost include path : ${BOOST_INCLUDE_PATH}")
message("-- == Boost library path : ${BOOST_LIBRARY_PATH}")
message("-- == Boost coroutine library (Release) : ${BOOST_COROUTINE_LIB_RELEASE}")
message("-- == Boost coroutine library (Debug)   : ${BOOST_COROUTINE_LIB_DEBUG}")

include_directories(${BOOST_INCLUDE_PATH})
link_directories(${BOOST_LIBRARY_PATH})

link_libraries(
  optimized "${BOOST_COROUTINE_LIB_RELEASE}"
  debug "${BOOST_COROUTINE_LIB_DEBUG}")



# プロジェクト
################################################################

file(GLOB fibfiles fib.cpp)
add_executable(fib ${fibfiles})

file(GLOB readlinesfiles readlines.cpp)
add_executable(readlines ${readlinesfiles})

file(GLOB readerfiles reader.cpp)
add_executable(reader ${readerfiles})


file(GLOB enumerablefiles use_mixin.cpp EnumerableMixin.h)
add_executable(enumerable ${enumerablefiles})

add_subdirectory(streams)

