/*! Class:  Matrix 
*   c++ code
*   Author: Monika Twarogowska, March 2019
*
*   Matrix : class for (n x m) dimensional matrices
*   
*   Functionality: 
*                 - create a (nxm) matrix of type double using dimensions (n,m) or vectors
*                 - get/set elements of a matrix
*                 - use operators: add, substract, multiply
*                 - compute determinant, first minor and inverse matrix of a squere matrix
*                 - print the content of a matrix 
*
*   USAGE: 
*      Create a matrix: 
*                 Matrix A;
*                 Matrix A(number of rows, number of columns, initial value);
*                 Matrix A(vec); where vec is of type: vector<vector<double> >
*
*     Get and set matrix element:
*                 A.getElement(row index,column index);
*                 A.setElement(row index,column index,value);
*
*     Get matrix dimensions:
*                 A.getRows();
*                 A.getCols();
*
*     Operations:
*                A+B
*                A-B
*                A*B  if A.getCols() = B.getRows()
*
*     Functions for squere matrices:
*                determinant:     A.matrixDeterminant();
*                i,j first minor: A.matrixFirstMinor(i,j);
*                inverse:         A.matrixInverse();
*
*     Print:
*                A.disp();
*/



#include <iostream>
#include <stdlib.h>
#include <math.h> 

#include "Matrix.hpp"

using namespace std;

// Constructors
Matrix::Matrix()
{
  mNumberRows = 1;
  mNumberCols = 1;
  mMatrix.resize(1);
  mMatrix[0].resize(1,0.0);
}

Matrix::Matrix(unsigned _mNumberRows, unsigned _mNumberCols, const double& _init)
{
  if (mNumberRows < 0 || mNumberCols < 0)
    {
      cout << "Error: Matrix dimensions cannot be zero or negative.";
      exit (EXIT_FAILURE);
    }
  else
    {
      mNumberRows = _mNumberRows;
      mNumberCols = _mNumberCols;
      mMatrix.resize(_mNumberRows);
      for (unsigned ii=0; ii<mMatrix.size(); ii++)
	{
	  mMatrix[ii].resize(_mNumberCols,_init);
	}
    }
}

Matrix::Matrix(vector<vector<double> > v)
{
  mNumberRows = v.size();
  mNumberCols = v[0].size();
  for (unsigned ii = 1; ii < mNumberRows; ii++)
    {
      if (v[ii].size() != v[0].size())
	{
	  cout << "Error: non equal number of columns \n";
	  exit (EXIT_FAILURE);
	}
    }
  mMatrix.resize(v.size());
  for (unsigned ii = 0; ii < mNumberRows; ii++)
    {
      mMatrix[ii].resize(v[0].size(),0.0);
    }
  
  for (unsigned ii = 0; ii < mNumberRows; ii++) 
    {
      for (unsigned jj = 0; jj < mNumberCols; jj++) 
	{
	  mMatrix[ii][jj] = v[ii][jj];
	}
    }
}
// Descturctor
Matrix::~Matrix() {}

// Getters
double Matrix::getElement(unsigned indexRowElement, unsigned indexColElement)
{
  return mMatrix[indexRowElement][indexColElement];
}

unsigned Matrix::getRows() const
{
  return this->mNumberRows;
}

unsigned Matrix::getCols() const
{
  return this->mNumberCols;
}
// Setters
void Matrix::setElement(unsigned indexRowElement, unsigned indexColElement, double val)
{
  mMatrix[indexRowElement][indexColElement] = val;
}

// Display
void Matrix::disp()
{
  for (unsigned ii = 0; ii < mNumberRows; ii++)
    {
      cout << "| ";
      for (unsigned jj = 0; jj < mNumberCols-1; jj++)
	{
	  cout << mMatrix[ii][jj] << " ";
	}
      cout << mMatrix[ii][mNumberCols-1] << " |\n";
    }
}

//Overload operators
Matrix Matrix::operator=(Matrix &M)
{
  Matrix result(mNumberRows, mNumberCols, 0.0);

  for (unsigned ii = 0; ii < mNumberRows; ii++)
    {
      for (unsigned jj = 0; jj < mNumberCols; jj++)
	{
	  result.setElement(ii,jj,M.getElement(ii,jj));
	}
    }
  return result;
}

Matrix Matrix::operator+(Matrix &M)
{
  Matrix result(mNumberRows, mNumberCols, 0.0);

  for (unsigned ii = 0; ii < mNumberRows; ii++)
    {
      for (unsigned jj = 0; jj < mNumberCols; jj++)
	{
	  result.setElement(ii,jj,this->mMatrix[ii][jj] + M.getElement(ii,jj));
	}
    }
  return result;
}

Matrix Matrix::operator-(Matrix &M)
{
  Matrix result(mNumberRows, mNumberCols, 0.0);

  for (unsigned ii = 0; ii < mNumberRows; ii++)
    {
      for (unsigned jj = 0; jj < mNumberCols; jj++)
	{
	  result.setElement(ii,jj,this->mMatrix[ii][jj] - M.getElement(ii,jj));
	}
    }
  return result;
}

Matrix Matrix::operator*(Matrix &M)
{
  unsigned numberCols = M.getCols();
  Matrix result(mNumberRows, numberCols,0.0);
  if(mNumberCols == numberCols)
    {
      double temp = 0.0;
      for (unsigned ii = 0; ii < mNumberRows; ii++)
        {
	  for (unsigned jj = 0; jj < numberCols; jj++)
            {
	      temp = 0.0;
	      for (unsigned kk = 0; kk < mNumberCols; kk++)
                {
		  temp += mMatrix[ii][kk] * M.getElement(kk,jj);
                }
	      result.setElement(ii,jj,temp);
            }
        }
      return result;
    }
  else
    {
      cout << "Error: wrong matrix dimensions";
      exit (EXIT_FAILURE);
    }
}

// Methods
double Matrix::matrixDeterminant() {

  double det;
  if (mNumberRows != mNumberCols )
    {
      cout << "Error: Cannot compute determinant because matrix squared. \n";
      exit (EXIT_FAILURE);
    }
  else
    {
      unsigned nSize = mNumberRows;  
      if (nSize == 1)
	{
	  return mMatrix[0][0];
	}
      else if (nSize == 2)
	{
	  return mMatrix[0][0]*mMatrix[1][1]-mMatrix[0][1]*mMatrix[1][0];
	}
      else
	{
	  Matrix tempM(nSize-1,nSize-1,0.0);
	  vector<unsigned> tempV;
	  int one_fact = 1;
	  det = 0;
	  for(unsigned ii = 0; ii < nSize; ii++)
	    {
	      for (unsigned jj = 0; jj < nSize; jj++)
		{
		  if (jj != ii )
		    {
		      tempV.push_back(jj);
		    }
		}
	      for(unsigned kk = 0; kk < nSize-1; kk++)
		{
		  for(unsigned ll = 0; ll < nSize; ll++)
		    {
		      unsigned tempIdx = tempV[ll];
		      tempM.setElement(kk,ll,mMatrix[kk+1][tempIdx]);
		    }
		}
	      det = det + one_fact*mMatrix[0][ii]*tempM.matrixDeterminant();
	      one_fact = -1*one_fact;
	      tempV.clear();
	    }
	  return det;
	}
    }
}

double Matrix::matrixFirstMinor(unsigned indexRow, unsigned indexCol)
{
  if (mNumberRows != mNumberCols )
    {
      cout << "Error: Matrix is not squared. \n";
      exit (EXIT_FAILURE);
    }
  else
    {
      unsigned nSize = mNumberRows;
      Matrix tempM(nSize-1,nSize-1,0.0);
      vector<unsigned> rowsIdx;
      vector<unsigned> colsIdx;

      for (unsigned kk = 0; kk < nSize; kk++)
	{
	  if (kk != indexRow )
	    {
	      rowsIdx.push_back(kk);
	    }
	  if (kk != indexCol )
	    {
	      colsIdx.push_back(kk);
	    }	  
	}

      for(unsigned ii = 0; ii < nSize-1; ii++)
	{
	  for(unsigned jj = 0; jj < nSize-1; jj++)
	    {
	      unsigned tempIdx_row = rowsIdx[ii];
	      unsigned tempIdx_col = colsIdx[jj];
	      tempM.setElement(ii,jj,mMatrix[tempIdx_row][tempIdx_col]);
	    }
	}
      return tempM.matrixDeterminant();
    }
}

Matrix Matrix::matrixInverse()
{ 
  if (mNumberRows != mNumberCols )
    {
      cout << "Error: Matrix is not squared. \n";
      exit (EXIT_FAILURE);
    }
  else
    {
      Matrix tempM(mNumberRows,mNumberRows,0.0);
      
      for (unsigned ii = 0; ii < mNumberRows; ii++)
	{
	  for (unsigned jj = 0; jj < mNumberRows; jj++)
	    {
	      tempM.setElement(ii,jj,this->mMatrix[ii][jj]);
	    }
	}
      if ( tempM.matrixDeterminant() == 0.0 )
	{
	  cout<< "Error: Determinant equals zero. Inverse matrix does not exist.\n";
	  exit (EXIT_FAILURE);
	}
      else
	{
	  Matrix matrix_inverse(mNumberRows,mNumberRows,0.0);
	  for (unsigned ii = 0; ii < mNumberRows; ii++)
	    {
	      for (unsigned jj = 0; jj < mNumberRows; jj++)
		{
		  matrix_inverse.setElement(ii,jj,(pow(-1,ii+jj))*tempM.matrixFirstMinor(ii,jj)/tempM.matrixDeterminant());
		}
	    }
	  return matrix_inverse;
	}
    }
}

