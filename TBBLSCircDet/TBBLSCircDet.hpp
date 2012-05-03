/*
 * TBBLSCircDet.hpp
 *
 *  Created on: Apr 17, 2012
 *      Author: frferrara
 */

#ifndef TBBLSCIRCDET_HPP_
#define TBBLSCIRCDET_HPP_


#include <stdexcept>

#include <gsl/gsl_histogram2d.h>
#include <gsl/gsl_histogram.h>

#include <eigen3/Eigen/Eigen>

#include <RandomNumberGenerator.hpp>
#include <ConstructionException.hpp>

#include "CDInterface.hpp"
#include "ParallelCD.hpp"


class TBBLSCircDet: public CDInterface {
public:
	TBBLSCircDet();

	TBBLSCircDet( unsigned int numPoints, \
				  gsl_histogram2d * hist_xC, \
				  gsl_histogram * hist_r, \
				  unsigned long j, \
				  unsigned int n ) throw( ConstructionException );

	~TBBLSCircDet();

	virtual void detectCircle( const Eigen::MatrixXd & x );

	virtual CircleParameters * getDetectedCircle();

private:
	Eigen::MatrixXd checkMatrixSize( const Eigen::MatrixXd & x );

	CircleParameters * detectedCircle;

	unsigned int numPoints, n;

	gsl_histogram2d * hist_xC;
	gsl_histogram * hist_r;

	RandomNumberGenerator * rng;
};


#endif /* TBBLSCIRCDET_HPP_ */
