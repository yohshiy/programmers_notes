
cmake_minimum_required(VERSION 2.6)
project (sample)



# 全体構成

get_filename_component(DEV_TOP ../../.. ABSOLUTE)
message("-- == Develop top directory : ${DEV_TOP}")



if (UNIX)
  include_directories(/usr/local/include)
  link_directories(/usr/local/lib)
endif(UNIX)



# Boost
################################################################
if (DEFINED ENV{BOOST_DIR})
  message("-- == Env. BOOST_DIR : $ENV{BOOST_DIR}")
  set(BOOST_DIR $ENV{BOOST_DIR})
elseif(WIN32)
  set(BOOST_DIR C:/local/boost_1_56_0)
else()
  set(BOOST_DIR /usr/local)
endif()

if(WIN32)
  string(SUBSTRING ${CMAKE_GENERATOR} 14 2 VSVER)
  set(BOOST_INCLUDE_PATH_DEFAULT ${BOOST_DIR})
  set(BOOST_LIBRARY_PATH_DEFAULT ${BOOST_DIR}/lib32-msvc-${VSVER}.0)
else()
  set(BOOST_INCLUDE_PATH_DEFAULT ${BOOST_DIR}/include)
  set(BOOST_LIBRARY_PATH_DEFAULT ${BOOST_DIR}/lib)  
endif()


set(BOOST_INCLUDE_PATH ${BOOST_INCLUDE_PATH_DEFAULT}
  CACHE PATH "Set the directory of boost header files")
set(BOOST_LIBRARY_PATH ${BOOST_LIBRARY_PATH_DEFAULT}
  CACHE PATH "Set the directory of boost library files")
set(BOOST_LIBRARY_WINDOWS_SUFFIX_RELEASE -vc${VSVER}0-mt-s-1_56
  CACHE STRING "Set boost library on windows for relese build")
set(BOOST_LIBRARY_WINDOWS_SUFFIX_DEBUG -vc${VSVER}0-mt-sgd-1_56
  CACHE STRING "Set boost library on windows for debug build")

message("-- == Boost include path : ${BOOST_INCLUDE_PATH}")
message("-- == Boost library path : ${BOOST_LIBRARY_PATH}")
message("-- == Boost library windows suffix (Release) : ${BOOST_LIBRARY_WINDOWS_SUFFIX_RELEASE}")
message("-- == Boost library windows suffix (Debug)   : ${BOOST_LIBRARY_WINDOWS_SUFFIX_DEBUG}")

include_directories(${BOOST_INCLUDE_PATH})
link_directories(${BOOST_LIBRARY_PATH})


# 共通コンパイルオプション
################################################################

include_directories(.)

if(WIN32)
  # add_definitions(/W4 /wd"4127")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${EB_LIBRARY_PATH})
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${EB_LIBRARY_PATH})
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${EB_LIBRARY_PATH})
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${EB_LIBRARY_PATH})
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${EB_LIBRARY_PATH})
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${EB_LIBRARY_PATH})
  add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS -D_UNICODE)
  link_libraries(Shlwapi.lib)

  # Windows で M_PI を使うための定義
  add_definitions(-D_USE_MATH_DEFINES)

  # Windows で std::min, max を使うための定義
  add_definitions(-DNOMINMAX)

  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MTd")
  set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /MT")

  # set(CMAKE_SHARED_LINKER_FLAGS_DEBUG
  #   "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrt.lib  /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib")
  # set(CMAKE_SHARED_LINKER_FLAGS_RELEASE
  #   "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrtd.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib")

else(WIN32)
  add_definitions(-Wall)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${EB_LIBRARY_PATH})
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EB_LIBRARY_PATH})
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${EB_LIBRARY_PATH})
endif(WIN32)




# マクロ、関数定義
################################################################

# ライブラリーのプロジェクトの追加
macro (my_add_library libname)
  add_library(${libname} SHARED ${ARGN})
  set_target_properties(${libname} PROPERTIES
    RUNTIME_OUTPUT_NAME_DEBUG "${libname}d"
    ARCHIVE_OUTPUT_NAME_DEBUG "${libname}d"
    LIBRARY_OUTPUT_NAME_DEBUG "${libname}d")
endmacro()

# VERSION.h を取り除いて、ヘッダーファイルをインストール
function(install_heaers_except_VERSION dest)
  file(GLOB version_file VERSION.h)
  list(REMOVE_ITEM ARGN ${version_file})
  install(FILES ${ARGN} DESTINATION ${dest})
endfunction()

# boost ライブラリー用 link_libraries
macro (link_boost_libraries)
  set(argv_for_loop "${ARGV}")
  foreach (blib IN LISTS argv_for_loop)
    if (WIN32)
      link_libraries(
	debug libboost_${blib}${BOOST_LIBRARY_WINDOWS_SUFFIX_DEBUG}
	optimized libboost_${blib}${BOOST_LIBRARY_WINDOWS_SUFFIX_RELEASE})
    else(WIN32)
      link_libraries(boost_${blib})
    endif(WIN32)
  endforeach()
endmacro()


################################################################
################################################################




# Google Test 用
################################################################

if (DEFINED ENV{GTEST_DIR})
  message("-- == == Env. GTEST_DIR : $ENV{GTEST_DIR}")
  set(GTEST_DIR $ENV{GTEST_DIR})
elseif(WIN32)
  set(GTEST_DIR $ENV{ProgramFiles}/gtest)
else()
  set(GTEST_DIR /usr/local)
endif()


if (WIN32)
  set(GTEST_INCLUDE_PATH_DEFAULT "${GTEST_DIR}/include")
  set(GTEST_LIBRARY_PATH_DEFAULT "${GTEST_DIR}")
else()
  set(GTEST_INCLUDE_PATH_DEFAULT "${GTEST_DIR}/include")
  set(GTEST_LIBRARY_PATH_DEFAULT "${GTEST_DIR}/lib")
endif()

set(GTEST_INCLUDE_PATH ${GTEST_INCLUDE_PATH_DEFAULT}
  CACHE PATH "Set the directory of Google Test header files")
set(GTEST_LIBRARY_PATH ${GTEST_LIBRARY_PATH_DEFAULT}
  CACHE PATH "Set the directory of Google Test library files")



message("-- == == Google Test include path : ${GTEST_INCLUDE_PATH}")
message("-- == == Google Test library path : ${GTEST_LIBRARY_PATH}")


include_directories(. ${GTEST_INCLUDE_PATH})
link_directories(${GTEST_LIBRARY_PATH})



# データ
################################################################
get_filename_component(DATA_DIR ../../../../../../doc/Data ABSOLUTE)
message("-- == == Data directory : ${DATA_DIR}")
configure_file(UTestsConfig.h.in UTestsConfig.h)


# 単体テスト
################################################################

file(GLOB FILES ../*.h ../*.cpp *.h *.cpp)

add_executable(utests ${FILES})
target_link_libraries(utests gtest gtest_main)
target_link_libraries(utests libjbx libj01 jbxrdy)
set_target_properties(utests PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${EB_BIN_PATH})
