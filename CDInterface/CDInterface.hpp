/*
 * CDInterface.hpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */

#ifndef CDINTERFACE_HPP_
#define CDINTERFACE_HPP_


#include <eigen3/Eigen/Eigen>
#include "CircleParameters.hpp"


class CDInterface {
public:
	virtual ~CDInterface() {}

	virtual void detectCircle( const Eigen::MatrixXd & x ) = 0;

	virtual CircleParameters * getDetectedCircle() = 0;

protected:
	CDInterface() {}
};


#endif /* CDINTERFACE_HPP_ */
