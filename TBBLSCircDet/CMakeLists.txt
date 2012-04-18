add_library( TBBLSCircDet SHARED TBBLSCircDet.cpp TBBLSCircDet.hpp 
                                 ParallelCD.cpp ParallelCD.hpp )
target_link_libraries( TBBLSCircDet LSCircDet CircleParameters 
                       /opt/local/lib/libtbb.dylib /opt/local/lib/libgsl.dylib
                       -lRandomNumberGenerator
                       -lRan64 )

install( TARGETS TBBLSCircDet DESTINATION lib )
install( FILES TBBLSCircDet.hpp DESTINATION include )