cmake_minimum_required( VERSION 2.8 )

project( CircleDetector )

set( CMAKE_CXX_FLAGS "-Wall -Wextra -g" )

include_directories( /opt/local/include
                     ${PROJECT_SOURCE_DIR}/CircleParameters
                     ${PROJECT_SOURCE_DIR}/CDInterface
                     ${PROJECT_SOURCE_DIR}/CircleDetector
                     ${PROJECT_SOURCE_DIR}/LSCircDet
                     ${PROJECT_SOURCE_DIR}/TBBLSCircDet )
add_subdirectory( CircleParameters )
add_subdirectory( CDInterface )
add_subdirectory( CircleDetector )
add_subdirectory( LSCircDet )
add_subdirectory( TBBLSCircDet )

add_executable( main main.cpp )
target_link_libraries( main
                       CircleParameters
                       CircleDetector
                       LSCircDet )