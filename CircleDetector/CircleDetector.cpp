/*
 * CircleDetector.cpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */


#include "CircleDetector.hpp"


CircleDetector::CircleDetector() {
	cdInterface = NULL;
}

CircleDetector::CircleDetector( CDInterface * cdInterface ) {
	this->cdInterface = cdInterface;
}

CircleDetector::~CircleDetector() {
	delete cdInterface;
}

CircleParameters CircleDetector::detectCircle( const Eigen::MatrixXd & x ) {
	return cdInterface->detectCircle( x );
}
