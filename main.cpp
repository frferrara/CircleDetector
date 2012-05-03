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
	std::cout << "Test of LSCircDet\n";

	// Create a set of circle points
	// Circle properties
	double x0 = 2.0;
	double y0 = 4.0;
	double r = 2.0;

	std::cout << "Original circle:\n" \
			  << "x = " << x0 << ", y = " << y0 \
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

	LSCircDet * lscd = new LSCircDet;

	CircleParameters * cp = NULL;

	try {
		lscd->detectCircle( x );

		cp = lscd->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

	// Preallocation
	n = round( 2 * M_PI / dphi ) + 1;
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
		lscd->detectCircle( x );

		cp = lscd->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

	// Preallocation
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

	try {
		lscd->detectCircle( x );

		cp = lscd->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

	// Preallocation
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

	try {
		lscd->detectCircle( x );

		cp = lscd->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

	// Preallocation
	n = 1;
	x.resize( 5, n );
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
		lscd->detectCircle( x );

		cp = lscd->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

	// Preallocation
	n = 1;
	x.resize( n, 5 );
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
		lscd->detectCircle( x );

		cp = lscd->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

	// Preallocation
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

	CircleParameters * cp2 = NULL;

	try {
		cp2 = lscd->detectCircle2( x );

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp2->get_xC() )( 0 ) << ", yC = " \
				  << ( cp2->get_xC() )( 1 ) \
				  << ", r  = " << cp2->get_r() << std::endl;

		delete cp2;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

	// Preallocation
	n = round( 2 * M_PI / dphi ) + 1;
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
		cp2 = lscd->detectCircle2( x );

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp2->get_xC() )( 0 ) << ", yC = " \
				  << ( cp2->get_xC() )( 1 ) \
				  << ", r  = " << cp2->get_r() << std::endl;

		delete cp2;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

	// Preallocation
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

	try {
		cp2 = lscd->detectCircle2( x );

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp2->get_xC() )( 0 ) << ", yC = " \
				  << ( cp2->get_xC() )( 1 ) \
				  << ", r  = " << cp2->get_r() << std::endl;

		delete cp2;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

	// Preallocation
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

	try {
		cp2 = lscd->detectCircle2( x );

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp2->get_xC() )( 0 ) << ", yC = " \
				  << ( cp2->get_xC() )( 1 ) \
				  << ", r  = " << cp2->get_r() << std::endl;

		delete cp2;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

	// Preallocation
	n = 1;
	x.resize( 5, n );
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
		cp2 = lscd->detectCircle2( x );

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp2->get_xC() )( 0 ) << ", yC = " \
				  << ( cp2->get_xC() )( 1 ) \
				  << ", r  = " << cp2->get_r() << std::endl;

		delete cp2;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

	// Preallocation
	n = 1;
	x.resize( n, 5 );
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
		cp2 = lscd->detectCircle2( x );

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp2->get_xC() )( 0 ) << ", yC = " \
				  << ( cp2->get_xC() )( 1 ) \
				  << ", r  = " << cp2->get_r() << std::endl;

		delete cp2;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

	delete lscd;

	std::cout << "Test of CircleDetector!\n";

	// Preallocation
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

	CircleDetector * circleDetector = new CircleDetector( new LSCircDet );

	try {
		circleDetector->detectCircle( x );

		cp = circleDetector->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

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
		circleDetector->detectCircle( x );

		cp = circleDetector->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

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

	try {
		circleDetector->detectCircle( x );

		cp = circleDetector->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

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

	try {
		circleDetector->detectCircle( x );

		cp = circleDetector->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

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

	try {
		circleDetector->detectCircle( x );

		cp = circleDetector->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

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

	try {
		circleDetector->detectCircle( x );

		cp = circleDetector->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

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

	circleDetector = new CircleDetector();

	try {
		circleDetector->detectCircle( x );
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	}

	/////////////////////////////////////

	gsl_histogram2d * hist_xC = gsl_histogram2d_calloc_uniform( 10, 10, \
			0.0, 10.0, 0.0, 10.0 );
	gsl_histogram * hist_r = gsl_histogram_calloc_uniform( 10, 0.0, 10.0 );

	unsigned int j = 27, n_ = 100, numPoints = 5;

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
		delete circleDetector;
		circleDetector = new CircleDetector( \
				new TBBLSCircDet( numPoints, hist_xC, hist_r, j, n_ ) );

		circleDetector->detectCircle( x );

		cp = circleDetector->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;

		delete circleDetector;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	} catch ( ... ) {
		std::cout << "Unknown Exception!\n";
	}

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
				new TBBLSCircDet( numPoints, hist_xC, hist_r, j, n_ ) );

		circleDetector->detectCircle( x );

		cp = circleDetector->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;

		delete circleDetector;
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	}

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

	try {
		circleDetector = new CircleDetector( \
				new TBBLSCircDet( numPoints, hist_xC, hist_r, j, n_ ) );

		circleDetector->detectCircle( x );

		cp = circleDetector->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;

		delete circleDetector;
	} catch ( std::runtime_error & e ) {
		cp = NULL;

		std::cout << std::endl << e.what() << std::endl;
	}

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

	try {
		delete circleDetector;
		circleDetector = new CircleDetector( \
				new TBBLSCircDet( numPoints, hist_xC, hist_r, j, n_ ) );

		circleDetector->detectCircle( x );

		cp = circleDetector->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;

		delete circleDetector;
	} catch ( std::runtime_error & e ) {
		cp = NULL;

		std::cout << std::endl << e.what() << std::endl;
	}

	n = 1;
	x.resize( 5, n );
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
		delete circleDetector;
		circleDetector = new CircleDetector( \
				new TBBLSCircDet( numPoints, hist_xC, hist_r, j, n_ ) );

		circleDetector->detectCircle( x );

		cp = circleDetector->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;

		delete circleDetector;
	} catch ( std::runtime_error & e ) {
		cp = NULL;

		std::cout << std::endl << e.what() << std::endl;
	}

	n = 1;
	x.resize( n, 5 );
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
		delete circleDetector;
		circleDetector = new CircleDetector( \
				new TBBLSCircDet( numPoints, hist_xC, hist_r, j, n_ ) );

		circleDetector->detectCircle( x );

		cp = circleDetector->getDetectedCircle();

		std::cout << "Detected circle:\n" \
				  << "xC = " << ( cp->get_xC() )( 0 ) << ", yC = " \
				  << ( cp->get_xC() )( 1 ) \
				  << ", r  = " << cp->get_r() << std::endl;

		delete circleDetector;
	} catch ( std::runtime_error & e ) {
		cp = NULL;

		std::cout << std::endl << e.what() << std::endl;
	}

	delete circleDetector;

	return 0;
}

