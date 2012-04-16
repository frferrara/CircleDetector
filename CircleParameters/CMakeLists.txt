add_library( CircleParameters SHARED CircleParameters.cpp CircleParameters.hpp )

install( TARGETS CircleParameters DESTINATION lib )
install( FILES CircleParameters.hpp DESTINATION include )