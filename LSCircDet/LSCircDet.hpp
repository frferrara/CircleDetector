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
	LSCircDet() {}

	~LSCircDet() {}

	CircleParameters detectCircle( const Eigen::MatrixXd & x );

private:
	void checkMatrixSize( const Eigen::MatrixXd & x );

	void fillMat( const Eigen::MatrixXd & x );

	Eigen::Matrix3d A;

	Eigen::Vector3d D;
};


#endif /* LSCIRCDET_HPP_ */
