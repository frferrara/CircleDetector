/*
 * CircleParameters.cpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */


#include "CircleParameters.hpp"


CircleParameters::CircleParameters() {
	xC = Eigen::Vector2d::Zero();

	r = 0.0;
}

CircleParameters::CircleParameters( const Eigen::Vector2d & xC, \
									double r ) {
	try {
		if ( r <= 0.0 )
			throw std::runtime_error( "Exception: r <= 0.0" );

		this->xC = xC;
		this->r = r;
	} catch ( std::runtime_error & e ) {
		this->xC = Eigen::Vector2d::Zero();
		this->r = 0.0;

		std::cout << std::endl << e.what() << std::endl;
	}
}

Eigen::Vector2d CircleParameters::get_xC() {
	return xC;
}

double CircleParameters::get_r() {
	return r;
}

void CircleParameters::set_xC( const Eigen::Vector2d & xC ) {
	this->xC = xC;
}

void CircleParameters::set_r( double r ) {
	try {
		if ( r <= 0.0 )
			throw std::runtime_error( "Exception: r <= 0.0" );

		this->r = r;
	} catch ( std::runtime_error & e ) {
		this->r = 0.0;

		std::cout << std::endl << e.what() << std::endl;
	}
}
