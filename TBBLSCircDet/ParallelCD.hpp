/*
 * ParallelCD.hpp
 *
 *  Created on: Apr 18, 2012
 *      Author: frferrara
 */

#ifndef PARALLELCD_HPP_
#define PARALLELCD_HPP_


#include <eigen3/Eigen/Eigen>

#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>

#include <gsl/gsl_histogram2d.h>
#include <gsl/gsl_histogram.h>

#include <boost/shared_ptr.hpp>

#include <RandomNumberGenerator.hpp>

#include "LSCircDet.hpp"


class ParallelCD {
public:
	ParallelCD();

	ParallelCD( unsigned int numPoints, \
				const Eigen::MatrixXd & x, \
				gsl_histogram2d * hist_xC, \
				gsl_histogram * hist_r, \
				RandomNumberGenerator * rng );

	~ParallelCD() {}

	void operator()( const tbb::blocked_range< size_t > & r ) const;

private:
	unsigned int numPoints;

	Eigen::MatrixXd x;

	gsl_histogram2d * hist_xC;
	gsl_histogram * hist_r;

	RandomNumberGenerator * rng;

	//LSCircDet * lsCircDet;
	boost::shared_ptr< LSCircDet > lsCircDet;
};


#endif /* PARALLELCD_HPP_ */
