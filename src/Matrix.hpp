/*! Header for class:  Matrix 
* 
*
* A more detailed description of the class
* Created by Monika Twarogowska on 24/03/2019
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using std::vector;

// In more general implementation we would use a template , which works for different data types

class Matrix
{
private:
  vector<vector<double> > mMatrix;
  unsigned mNumberRows;
  unsigned mNumberCols;

public:
  // Constructors
  Matrix();
  Matrix(unsigned _mNumberRows, unsigned _mNumberCols, const double& _init);
  Matrix(vector<vector<double> > v);
  ~Matrix();

  // Methods
  double matrixDeterminant();
  double matrixFirstMinor(unsigned indexRow, unsigned indexCol);
  Matrix matrixInverse();
  void disp();

  // Overload operators
  Matrix operator=(Matrix &M);
  Matrix operator+(Matrix &M);
  Matrix operator-(Matrix &M);
  Matrix operator*(Matrix &M);

  // Getters and setters
  double getElement(unsigned indexRowElement, unsigned indexColElement);
  void setElement(unsigned indexRowElement, unsigned indexColElementl, double val);
  unsigned getRows() const;
  unsigned getCols() const;

};

#endif
