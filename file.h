#include <iostream>
 #include <math.h>
 #include <conio.h> 
#define _USE_MATH_DEFINES
#define n 5 #define m 5
using namespace std;
class Matrix {
 private:   
 double M[m]; 
public:   
 friend void InputArray(Matrix Arr[]);    
 friend void OutputArray(Matrix Arr[]);  
  friend void SortArray(Matrix  Arr[]);   
 friend void CalcArray(Matrix Arr[]);
 };
