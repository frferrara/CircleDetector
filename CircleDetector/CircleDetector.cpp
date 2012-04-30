/*
 * CircleDetector.cpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */


#include "CircleDetector.hpp"


CircleDetector::CircleDetector() {
	cdInterface = NULL;

	circleParameters = NULL;
}

CircleDetector::CircleDetector( CDInterface * cdInterface ) {
	this->cdInterface = cdInterface;
}

CircleDetector::~CircleDetector() {
	delete cdInterface;
}

CircleParameters * CircleDetector::detectCircle( const Eigen::MatrixXd & x ) {
	try {
		circleParameters = cdInterface->detectCircle( x );
	} catch( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	}

	return circleParameters;
}
