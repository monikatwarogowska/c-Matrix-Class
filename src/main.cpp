#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include "Matrix.hpp"

using namespace std;

int main()
{
  vector<vector<double> > a{ {1.0, 2.0, 1.0}, {3.0, 1.0, 1.0}, {1.0, 5.0, 2.0}};
  vector<vector<double> > b{ {-1.0, 4.0, 2.0}, {3.0, 2.0, 2.0}, {0.0, 2.0, 4.0} };
  Matrix A(a);              // TODO: how to pass {{...},{...}} directly?
  Matrix B(b);
  cout << " Matrix A = \n";
  A.disp();
  cout << " Matrix B = \n";
  B.disp();
  cout << " Matrix A+B = \n";
  (A+B).disp();
  cout << " Matrix A*B = \n";
  (A*B).disp();
  cout<<"det(A) = " << A.matrixDeterminant() << "\n";
  cout << " Matrix inv(A) = \n";
  A.matrixInverse().disp();
  return 0;
}
