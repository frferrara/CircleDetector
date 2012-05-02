/*
 * CircleDetector.hpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */

#ifndef CIRCLEDETECTOR_HPP_
#define CIRCLEDETECTOR_HPP_


#include <stdexcept>

#include "CDInterface.hpp"
#include "CircleParameters.hpp"

#include "LSCircDet.hpp"
#include "TBBLSCircDet.hpp"


class CircleDetector {
public:
	CircleDetector();

	CircleDetector( CDInterface * cdInterface );

	~CircleDetector();

	void detectCircle( const Eigen::MatrixXd & x );

	CircleParameters * getDetectedCircle();

private:
	CDInterface * cdInterface;

	CircleParameters * detectedCircle;
};


#endif /* CIRCLEDETECTOR_HPP_ */
