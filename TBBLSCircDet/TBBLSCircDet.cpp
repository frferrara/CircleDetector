/*
 * TBBLSCircDet.cpp
 *
 *  Created on: Apr 17, 2012
 *      Author: frferrara
 */


#include "TBBLSCircDet.hpp"


TBBLSCircDet::TBBLSCircDet() {
	rng = NULL;

	detectedCircle = NULL;

	hist_xC = NULL;
	hist_r = NULL;
}

TBBLSCircDet::TBBLSCircDet( unsigned int numPoints, \
							gsl_histogram2d * hist_xC , \
							gsl_histogram * hist_r, \
							unsigned long j, \
							unsigned int n ) {
	try {
		if ( numPoints == 0 )
			throw std::runtime_error( "Exception: numPoints == 0" );

		if ( hist_xC->nx == 0 || hist_xC->ny == 0 )
			throw std::runtime_error( "Exception: hist_xC->nx == 0 || hist_xC->ny == 0" );

		if ( hist_r->n == 0 )
			throw std::runtime_error( "Exception: hist_r->n == 0" );

		if ( n == 0 )
			throw std::runtime_error( "Exception: n == 0" );
	} catch ( std::runtime_error & e ) {
		throw;
	}

	this->numPoints = numPoints;

	this->hist_xC = hist_xC;

	this->hist_r = hist_r;

	rng = new RandomNumberGenerator( new Ran64( j ) );

	this->n = n;
}

TBBLSCircDet::~TBBLSCircDet() {
	delete detectedCircle;

	delete hist_xC;
	delete hist_r;

	delete rng;
}

CircleParameters * TBBLSCircDet::detectCircle( const Eigen::MatrixXd & x ) {
	try {
		tbb::parallel_for( tbb::blocked_range< size_t >( 0, n ), \
				ParallelCD( numPoints, x, hist_xC, hist_r, rng ) );

		size_t x, y, r;

		gsl_histogram2d_max_bin( hist_xC, &x, &y );
		r = gsl_histogram_max_bin( hist_r );

		detectedCircle = new CircleParameters( Eigen::Vector2d( x, y ), r );

	} catch ( std::runtime_error & e ) {
		throw;
	}

	return detectedCircle;
}
