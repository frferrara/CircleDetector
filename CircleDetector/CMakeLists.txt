add_library( CircleDetector SHARED CircleDetector.cpp CircleDetector.hpp )
target_link_libraries( CircleDetector CircleParameters )

install( TARGETS CircleDetector DESTINATION lib )
install( FILES CircleDetector.hpp DESTINATION include )