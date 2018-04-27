
cmake_minimum_required(VERSION 2.6)
project (boostpy)



# Boost Python 用のコンパイルオプション
################################################################


if(WIN32)
  set(SEARCH_BOOST_ROOT c:/local/boost_1_63_0
    CACHE PATH "The boost root path")
  set(SEARCH_BOOST_LIBRARYDIR c:/local/boost_1_63_0/lib32-msvc-14.0
    CACHE PATH "The boost library path")
  message("== Boost root : " ${SEARCH_BOOST_ROOT})
  message("== Boost library directory: " ${SEARCH_BOOST_LIBRARYDIR})

  set(BOOST_ROOT ${SEARCH_BOOST_ROOT})
  set(BOOST_LIBRARYDIR ${SEARCH_BOOST_LIBRARYDIR})
endif()


set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     ON)
find_package(Boost REQUIRED
             COMPONENTS python)

include_directories(${Boost_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES})



# Python 用のコンパイルオプション
################################################################

find_package(PythonLibs REQUIRED)

if(WIN32)
  include_directories(${PYTHON_INCLUDE_PATH})
  link_libraries(${PYTHON_LIBRARIES})
else()
  include_directories(/usr/ebsys/anaconda2/include/python2.7)
  link_directories(/usr/ebsys/anaconda2/lib)
endif()




# その他のコンパイルオプション
################################################################

include_directories(.)


if (MSVC)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MTd")
  set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /MT")
else()
  add_definitions(-Wall)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()



if(WIN32)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS -D_UNICODE)
endif()





# プロジェクト
################################################################

add_library(pyfoo SHARED foo.cpp)

if (WIN32)
  # 拡張子を pyd に変更
  set_target_properties(pyfoo PROPERTIES
    SUFFIX ".pyd")
endif()


