/*
 * CircleParameters.hpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */

#ifndef CIRCLEPARAMETERS_HPP_
#define CIRCLEPARAMETERS_HPP_


#include <iostream>
#include <stdexcept>

#include <eigen3/Eigen/Eigen>


class CircleParameters
{
public:
	CircleParameters();

	CircleParameters( const Eigen::Vector2d & x_C, \
					  double r );

	~CircleParameters() {}

	Eigen::Vector2d get_xC();

	double get_r();

	void set_xC( const Eigen::Vector2d & xC );

	void set_r( double r );

private:
	Eigen::Vector2d xC;

	double r;
};


#endif /* CIRCLEPARAMETERS_HPP_ */
