/*
 * CircleDetector.hpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */

#ifndef CIRCLEDETECTOR_HPP_
#define CIRCLEDETECTOR_HPP_


#include "CDInterface.hpp"
#include "CircleParameters.hpp"


class CircleDetector {
public:
	CircleDetector();

	CircleDetector( CDInterface * cdInterface );

	~CircleDetector();

	CircleParameters * detectCircle( const Eigen::MatrixXd & x );

private:
	CDInterface * cdInterface;
};


#endif /* CIRCLEDETECTOR_HPP_ */
