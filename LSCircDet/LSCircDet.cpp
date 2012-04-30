/*
 * LSCircDet.cpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */


#include "LSCircDet.hpp"


LSCircDet::LSCircDet() {
	detectedCircle = NULL;
}

LSCircDet::~LSCircDet() {
	delete detectedCircle;
}

CircleParameters * LSCircDet::detectCircle( const Eigen::MatrixXd & x ) {
	try {
		fillMat( x );

		X = solveLS();

		detectedCircle = new CircleParameters( \
						Eigen::Vector2d( X( 0 ), X( 1 ) ),
						std::sqrt( X( 0 ) * X( 0 ) + X( 1 ) * X( 1 ) - X( 2 ) ) \
						);
	} catch ( std::runtime_error & e ) {
		detectedCircle = new CircleParameters;

		throw;
	}

	return detectedCircle;
}

void LSCircDet::checkMatrixSize( const Eigen::MatrixXd & x ) {
	if ( x.rows() != 2 && x.cols() != 2 )
		throw std::runtime_error( "Exception: x.rows() != 2 && x.cols() != 2" );

	if ( x.rows() < 3 && x.cols() < 3 )
		throw std::runtime_error( "Exception: x.rows() < 3 && x.cols() < 3" );
}

void LSCircDet::fillMat( const Eigen::MatrixXd & x ) {
	checkMatrixSize( x );

	double n;

	double A11 = 0.0;
	double A12 = 0.0;
	double A13 = 0.0;
	double A22 = 0.0;
	double A23 = 0.0;

	double D1 = 0.0;
	double D2 = 0.0;
	double D3 = 0.0;

	double temp1, temp2;

	if ( x.rows() == 2 ) {
		n = x.cols();

		for ( int i = 0; i < n; i++ ) {
			temp1 = x( 0, i ) * x( 0, i );
			temp2 = x( 1, i ) * x( 1, i );

			A11 = A11 + temp1;
			A12 = A12 + x( 0, i ) * x( 1, i );
			A13 = A13 - x( 0, i );
			A22 = A22 + temp2;
			A23 = A23 - x( 1, i );

			D1 = D1 + temp1 * x( 0, i ) + x( 0, i ) * temp2;
			D2 = D2 + temp1 * x( 1, i ) + x( 1, i ) * temp2;
			D3 = D3 + temp1 + temp2;
		}
	} else {
		n = x.rows();

		for ( int i = 0; i < n; i++ ) {
			temp1 = x( i, 0 ) * x( i, 0 );
			temp2 = x( i, 1 ) * x( i, 1 );

			A11 = A11 + temp1;
			A12 = A12 + x( i, 0 ) * x( i, 1 );
			A13 = A13 - x( i, 0 );
			A22 = A22 + temp2;
			A23 = A23 - x( i, 1 );

			D1 = D1 + temp1 * x( i, 0 ) + x( i, 0 ) * temp2;
			D2 = D2 + temp1 * x( i, 1 ) + x( i, 1 ) * temp2;
			D3 = D3 + temp1 + temp2;
		}
	}

	A11 = 2 * A11;
	A12 = 2 * A12;
	double A21 = A12;
	A22 = 2 * A22;
	double A31 = -2 * A13;
	double A32 = -2 * A23;
	double A33 = -n;

	A << A11, A12, A13, \
		 A21, A22, A23, \
		 A31, A32, A33;

	D << D1, D2, D3;
}

Eigen::Vector3d LSCircDet::solveLS( const double eps ) {
	// Do a singular value decomposition of the matrix
	Eigen::JacobiSVD< Eigen::Matrix3d, \
		Eigen::FullPivHouseholderQRPreconditioner > svd( A, \
		Eigen::ComputeFullU | Eigen::ComputeFullV );

	// Set the tolerance
	double tol = eps * std::max( ( int )A.rows (), ( int )A.cols () ) * \
			svd.singularValues().maxCoeff();

	// Put the singular values into a matrix
	Eigen::Matrix3d sv = svd.singularValues().asDiagonal();

	// Calculate the singular values according to the tolerance
	for ( int i = 0; i < ( int )sv.cols(); i++ )
	{
		// If the singular values greater than the tolerance
		if ( sv( i, i ) > tol )
		{
			// Take the inverse of the singular values and put it back into the diagonal
			sv(i, i) = 1.0 / sv(i, i);
		}
		else // else
		{
			// Set them to 0
			sv(i, i) = 0.0;
		}
	}

	// Calculate the pseudo inverse
	Eigen::Matrix3d A_inv = svd.matrixV() * sv.transpose() * \
			svd.matrixU().adjoint();

	// Calculate X
	Eigen::Vector3d X = A_inv * D;

	return X;
}
