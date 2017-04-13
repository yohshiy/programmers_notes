
include_directories(. ..)


# C++14 Streams
################################################################


if(WIN32)
  set(STREAMS_INCLUDE_PATH_DEFAULT C:/usr/include/Streams)
else()
  set(STREAMS_INCLUDE_PATH_DEFAULT /usr/local/include)
endif()

set(STREAMS_INCLUDE_PATH "${STREAMS_INCLUDE_PATH_DEFAULT}"
  CACHE PATH "Set a directory of C++14 Streams header files")

message("-- == Streams include path : ${STREAMS_INCLUDE_PATH}")

include_directories(${STREAMS_INCLUDE_PATH})


# プロジェクト
################################################################


file(GLOB streamsfiles use_streams.cpp ../EnumerableMixin.h)
add_executable(streams ${streamsfiles})

