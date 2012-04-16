add_library( LSCircDet SHARED LSCircDet.cpp LSCircDet.hpp )
target_link_libraries( LSCircDet CircleParameters )

install( TARGETS LSCircDet DESTINATION lib )
install( FILES LSCircDet.hpp DESTINATION include )