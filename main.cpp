/*
 * main.cpp
 *
 *  Created on: Apr 17, 2012
 *      Author: frferrara
 */


#include <iostream>
#include <eigen3/Eigen/Eigen>
#include <cmath>
#include "CircleDetector.hpp"
#include "LSCircDet.hpp"
#include "CircleParameters.hpp"


int main() {
	std::cout << "Test of circle detection!\n";

	// Create a set of circle points
	// Circle properties
	double x0 = 2.0;
	double y0 = 4.0;
	double r = 2.0;

	std::cout << "Original circle:\n" \
			  << "xC = " << x0 << ", yC = " << y0 \
			  << ", r  = " << r << std::endl;

	// Generation of circle points
	// Point distance
	double dphi = 0.1;

	// Preallocation
	double n = round( 2 * M_PI / dphi ) + 1;
	Eigen::MatrixXd x;
	x.resize( n, 2 );
	double phi = 0.0;

	// Generation
	for ( int i = 0; i < n; i++ )
	{
		// Calculate the points
		x( i, 0 ) = x0 + r * cos( phi );
		x( i, 1 ) = y0 + r * sin( phi );

		// Augment the angle
		phi = phi + dphi;
	}

	CircleDetector * circleDetector = new CircleDetector( new LSCircDet );

	CircleParameters * circleParameters = circleDetector->detectCircle( x );

	std::cout << "Detected circle:\n" \
			  << "xC = " << ( circleParameters->get_xC() )( 0 ) << ", yC = " \
			  << ( circleParameters->get_xC() )( 1 ) \
			  << ", r  = " << circleParameters->get_r() << std::endl;

	free( circleParameters );
	circleParameters = new CircleParameters;

	x.resize( 2, n );
	phi = 0.0;

	// Generation
	for ( int i = 0; i < n; i++ )
	{
		// Calculate the points
		x( 0, i ) = x0 + r * cos( phi );
		x( 1, i ) = y0 + r * sin( phi );

		// Augment the angle
		phi = phi + dphi;
	}

	circleParameters = circleDetector->detectCircle( x );

	std::cout << "Detected circle:\n" \
			  << "xC = " << ( circleParameters->get_xC() )( 0 ) << ", yC = " \
			  << ( circleParameters->get_xC() )( 1 ) \
			  << ", r  = " << circleParameters->get_r() << std::endl;

	free( circleParameters );
	circleParameters = new CircleParameters;

	n = 1;
	x.resize( 2, n );
	phi = 0.0;

	// Generation
	for ( int i = 0; i < n; i++ )
	{
		// Calculate the points
		x( 0, i ) = x0 + r * cos( phi );
		x( 1, i ) = y0 + r * sin( phi );

		// Augment the angle
		phi = phi + dphi;
	}

	circleParameters = circleDetector->detectCircle( x );

	std::cout << "Detected circle:\n" \
			  << "xC = " << ( circleParameters->get_xC() )( 0 ) << ", yC = " \
			  << ( circleParameters->get_xC() )( 1 ) \
			  << ", r  = " << circleParameters->get_r() << std::endl;

	free( circleParameters );
	circleParameters = new CircleParameters;

	n = 1;
	x.resize( n, 2 );
	phi = 0.0;

	// Generation
	for ( int i = 0; i < n; i++ )
	{
		// Calculate the points
		x( i, 0 ) = x0 + r * cos( phi );
		x( i, 1 ) = y0 + r * sin( phi );

		// Augment the angle
		phi = phi + dphi;
	}

	circleParameters = circleDetector->detectCircle( x );

	std::cout << "Detected circle:\n" \
			  << "xC = " << ( circleParameters->get_xC() )( 0 ) << ", yC = " \
			  << ( circleParameters->get_xC() )( 1 ) \
			  << ", r  = " << circleParameters->get_r() << std::endl;

	free( circleParameters );
	circleParameters = new CircleParameters;

	n = 4;
	x.resize( n, 3 );
	phi = 0.0;

	// Generation
	for ( int i = 0; i < n; i++ )
	{
		// Calculate the points
		x( i, 0 ) = x0 + r * cos( phi );
		x( i, 1 ) = y0 + r * sin( phi );

		// Augment the angle
		phi = phi + dphi;
	}

	circleParameters = circleDetector->detectCircle( x );

	std::cout << "Detected circle:\n" \
			  << "xC = " << ( circleParameters->get_xC() )( 0 ) << ", yC = " \
			  << ( circleParameters->get_xC() )( 1 ) \
			  << ", r  = " << circleParameters->get_r() << std::endl;

	free( circleParameters );
	circleParameters = new CircleParameters;

	n = 4;
	x.resize( 3, n );
	phi = 0.0;

	// Generation
	for ( int i = 0; i < n; i++ )
	{
		// Calculate the points
		x( 0, i ) = x0 + r * cos( phi );
		x( 1, i ) = y0 + r * sin( phi );

		// Augment the angle
		phi = phi + dphi;
	}

	circleParameters = circleDetector->detectCircle( x );

	std::cout << "Detected circle:\n" \
			  << "xC = " << ( circleParameters->get_xC() )( 0 ) << ", yC = " \
			  << ( circleParameters->get_xC() )( 1 ) \
			  << ", r  = " << circleParameters->get_r() << std::endl;

	free( circleParameters );
	circleParameters = new CircleParameters;

	gsl_histogram2d * hist_xC = gsl_histogram2d_calloc_uniform( 10, 10, \
																0.0, 10.0, \
																0.0, 10.0 );
	gsl_histogram * hist_r = gsl_histogram_calloc_uniform( 10, 0.0, 10.0 );

	unsigned int j = 27, n_ = 100000, numPoints = 5;

	n = round( 2 * M_PI / dphi ) + 1;
	x.resize( n, 2 );
	phi = 0.0;

	// Generation
	for ( int i = 0; i < n; i++ )
	{
		// Calculate the points
		x( i, 0 ) = x0 + r * cos( phi );
		x( i, 1 ) = y0 + r * sin( phi );

		// Augment the angle
		phi = phi + dphi;
	}

	try {
		circleDetector = new CircleDetector( \
				new TBBLSCircDet( 5, hist_xC, hist_r, j, n_ ) );

		circleParameters = circleDetector->detectCircle( x );
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	}

	std::cout << "Detected circle:\n" \
			  << "xC = " << ( circleParameters->get_xC() )( 0 ) << ", yC = " \
			  << ( circleParameters->get_xC() )( 1 ) \
			  << ", r  = " << circleParameters->get_r() << std::endl;

	free( circleParameters );
	circleParameters = new CircleParameters;

	x.resize( 2, n );
	phi = 0.0;

	// Generation
	for ( int i = 0; i < n; i++ )
	{
		// Calculate the points
		x( 0, i ) = x0 + r * cos( phi );
		x( 1, i ) = y0 + r * sin( phi );

		// Augment the angle
		phi = phi + dphi;
	}

	try {
		circleDetector = new CircleDetector( \
				new TBBLSCircDet( 5, hist_xC, hist_r, j, n_ ) );

		circleParameters = circleDetector->detectCircle( x );
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	}

	std::cout << "Detected circle:\n" \
			  << "xC = " << ( circleParameters->get_xC() )( 0 ) << ", yC = " \
			  << ( circleParameters->get_xC() )( 1 ) \
			  << ", r  = " << circleParameters->get_r() << std::endl;

	free( circleParameters );
	circleParameters = new CircleParameters;

	return 0.0;
}

