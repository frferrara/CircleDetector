cmake_minimum_required( VERSION 2.8 )

project( CircleDetector )

include_directories( ${PROJECT_SOURCE_DIR}/CircleParameters
                     ${PROJECT_SOURCE_DIR}/CDInterface
                     ${PROJECT_SOURCE_DIR}/CircleDetector
                     ${PROJECT_SOURCE_DIR}/LSCircDet )
add_subdirectory( CircleParameters )
add_subdirectory( CDInterface )
add_subdirectory( CircleDetector )
add_subdirectory( LSCircDet )