/*
 * TBBLSCircDet.hpp
 *
 *  Created on: Apr 17, 2012
 *      Author: frferrara
 */

#ifndef TBBLSCIRCDET_HPP_
#define TBBLSCIRCDET_HPP_


#include <vector>
#include <stdexcept>

#include <gsl/gsl_histogram.h>
#include <gsl/gsl_histogram2d.h>

#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>

#include <eigen3/Eigen/Eigen>

#include <RandomNumberGenerator.hpp>

#include "CDInterface.hpp"


class TBBLSCircDet: public CDInterface {
public:
	TBBLSCircDet();

	TBBLSCircDet( unsigned int n, \
				  gsl_histogram2d * hist_xC, \
				  gsl_histogram * hist_r, \
				  unsigned long long j );

	~TBBLSCircDet();

	void operator()( const tbb::blocked_range< size_t > & r );

	virtual CircleParameters * detectCircle( const Eigen::MatrixXd & x );

private:
	CircleParameters * detCirc( const Eigen::MatrixXd & x );

	void checkMatrixSize( const Eigen::MatrixXd & x );

	void fillMat( const Eigen::MatrixXd & x );

	Eigen::Vector3d solveLS( const double eps = \
			std::numeric_limits< double >::epsilon() );

	CircleParameters * getCircle();

	Eigen::Matrix3d A;

	Eigen::Vector3d D, X;

	CircleParameters * detectedCircle;

	unsigned int n;

	Eigen::MatrixXd blobContour;

	gsl_histogram2d * hist_xC;
	gsl_histogram * hist_r;

	RandomNumberGenerator * rng;
};


#endif /* TBBLSCIRCDET_HPP_ */
