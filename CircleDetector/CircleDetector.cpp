/*
 * CircleDetector.cpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */


#include "CircleDetector.hpp"


CircleDetector::CircleDetector() {
	cdInterface = NULL;

	detectedCircle = NULL;
}

CircleDetector::CircleDetector( CDInterface * cdInterface ) {
	this->cdInterface = cdInterface;
}

CircleDetector::~CircleDetector() {
	delete cdInterface;
}

void CircleDetector::detectCircle( const Eigen::MatrixXd & x ) {
	try {
		cdInterface->detectCircle( x );

		detectedCircle = cdInterface->getDetectedCircle();
	} catch( std::runtime_error & e ) {
		throw;
	}
}

CircleParameters * CircleDetector::getDetectedCircle() {
	return detectedCircle;
}
