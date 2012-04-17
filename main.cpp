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


int main( int argc, char * argv[] ) {
	std::cout << "Test of circle detection!" << std::endl;

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

	return 0.0;
}

