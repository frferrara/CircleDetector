/*
 * LSCircDet.hpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */

#ifndef LSCIRCDET_HPP_
#define LSCIRCDET_HPP_


#include <iostream>
#include <stdexcept>
#include <eigen3/Eigen/Eigen>
#include "CDInterface.hpp"
#include "CircleParameters.hpp"


class LSCircDet : public CDInterface {
public:
	LSCircDet();

	virtual ~LSCircDet();

	virtual void detectCircle( const Eigen::MatrixXd & x );

	virtual CircleParameters * getDetectedCircle();

private:
	void checkMatrixSize( const Eigen::MatrixXd & x );

	void fillMat( const Eigen::MatrixXd & x );

	Eigen::Vector3d solveLS( const double eps = \
			std::numeric_limits< double >::epsilon() );

	Eigen::Matrix3d A;

	Eigen::Vector3d D, X;

	CircleParameters * detectedCircle;
};


#endif /* LSCIRCDET_HPP_ */
