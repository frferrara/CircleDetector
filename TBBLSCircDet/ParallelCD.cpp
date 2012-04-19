/*
 * ParallelCD.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: frferrara
 */


#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>

#include "ParallelCD.hpp"


ParallelCD::ParallelCD() {
	hist_xC = NULL;
	hist_r = NULL;

	rng = NULL;

	lsCircDet = NULL;
}

ParallelCD::ParallelCD( unsigned int numPoints, \
						const Eigen::MatrixXd & x, \
						gsl_histogram2d * hist_xC, \
						gsl_histogram * hist_r, \
						RandomNumberGenerator * rng ) {
	this->numPoints = numPoints;

	this->x = x;

	this->hist_xC = hist_xC;
	this->hist_r = hist_r;

	this->rng = rng;

	lsCircDet = new LSCircDet();
}

void ParallelCD::operator()( const tbb::blocked_range<size_t> & r )  const {
	for ( size_t i = r.begin(); i != r.end(); i++ ) {
		Eigen::MatrixXd x;
		x.resize( numPoints, 2 );

		unsigned int idx;

		for ( unsigned int i = 0; i < numPoints; i++ ) {
			idx = ( unsigned int )round( rng->uniGen( 0.0, ( double )numPoints ) );

			x( i, 0 ) = this->x( idx, 0 );
			x( i, 1 ) = this->x( idx, 1 );
		}

		CircleParameters * cP = NULL;

		try {
			cP = lsCircDet->detectCircle( x );
		} catch ( std::runtime_error & e ) {
			throw;
		}

		gsl_histogram2d_increment( hist_xC, round( ( cP->get_xC() )( 0 ) ), \
								   round( ( cP->get_xC() )( 1 ) ));
		gsl_histogram_increment( hist_r, round( cP->get_r() ) );
	}
}
