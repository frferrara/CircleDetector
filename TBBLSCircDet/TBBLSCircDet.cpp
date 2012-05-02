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
	if ( numPoints < 3 )
		throw std::runtime_error( "Exception: numPoints < 3" );

	if ( hist_xC == NULL || hist_xC->nx == 0 || hist_xC->ny == 0 )
		throw std::runtime_error( "Exception: hist_xC == NULL || hist_xC->nx == 0 || hist_xC->ny == 0" );

	if ( hist_r == NULL || hist_r->n == 0 )
		throw std::runtime_error( "Exception: hist_r == NULL || hist_r->n == 0" );

	if ( n == 0 )
		throw std::runtime_error( "Exception: n == 0" );

	this->numPoints = numPoints;

	this->hist_xC = hist_xC;

	this->hist_r = hist_r;

	this->n = n;

	rng = new RandomNumberGenerator( new Ran64( j ) );
}

TBBLSCircDet::~TBBLSCircDet() {
	delete detectedCircle;

	gsl_histogram2d_free( hist_xC );
	gsl_histogram_free( hist_r );

	delete rng;
}

void TBBLSCircDet::detectCircle( const Eigen::MatrixXd & x ) {
	if ( hist_xC == NULL )
		throw std::runtime_error( "hist_xC == NULL" );

	if ( hist_r == NULL )
		throw std::runtime_error( "hist_r == NULL" );

	if ( rng == NULL )
		throw std::runtime_error( "rng == NULL" );

	Eigen::MatrixXd z = checkMatrixSize( x );

	tbb::parallel_for( tbb::blocked_range< size_t >( 0, n ), \
			ParallelCD( numPoints, z, hist_xC, hist_r, rng ) );

	size_t x_, y_, r_;

	gsl_histogram2d_max_bin( hist_xC, &x_, &y_ );
	r_ = gsl_histogram_max_bin( hist_r );

	gsl_histogram2d_reset( hist_xC );
	gsl_histogram_reset( hist_r );

	detectedCircle = new CircleParameters( Eigen::Vector2d( x_, y_ ), r_ );
}

CircleParameters * TBBLSCircDet::getDetectedCircle() {
	return detectedCircle;
}

Eigen::MatrixXd TBBLSCircDet::checkMatrixSize( const Eigen::MatrixXd & x ) {
	if ( x.rows() != 2 && x.cols() != 2 )
		throw std::runtime_error( "Exception: x.rows() != 2 && x.cols() != 2" );

	if ( x.rows() < 3 && x.cols() < 3 )
		throw std::runtime_error( "Exception: x.rows() < 3 && x.cols() < 3" );

	if ( x.rows() == 2 ) {
		Eigen::MatrixXd y = x.transpose();

		return y;
	}

	return x;
}
