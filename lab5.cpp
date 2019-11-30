#include <iostream>
#include <math.h>
#include <conio.h>
#define _USE_MATH_DEFINES
#define N_size 5
#define M_size 5

using namespace std;

class Matrix {
private:
    double M[M_size];
public:
    friend void InputArray(Matrix Arr[]);
    friend void OutputArray(Matrix Arr[]);
    friend void SortArray(Matrix  Arr[]);
    friend void CalcArray(Matrix Arr[]);
};
void InputArray(Matrix  Arr[]) {
    for (int column = 0; column < N_size; ++column)
        for (int row = 0; row < M_size; ++row)
        {            cin >> Arr[column].M[row];
        }
}
void OutputArray(Matrix  Arr[]) {
    for (int column = 0; column < N_size; ++column)    {
        for (int row = 0; row < M_size; ++row)        {
            cout << Arr[column].M[row] << "\t";
        }        cout << endl;
    }
}
void SortArray(Matrix  arr[]) {
    for (int column = 0; column < N_size; column++) {
        for (int BlockSizeIterator = 1; BlockSizeIterator < N_size; BlockSizeIterator *= 2) {
            for (int BlockIterator = 0; BlockIterator < N_size - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator) {
                int LeftBlockIterator = 0; int RightBlockIterator = 0; int LeftBorder = BlockIterator;
                int MidBorder = BlockIterator + BlockSizeIterator;
                int RightBorder = BlockIterator + 2 * BlockSizeIterator; RightBorder = (RightBorder < N_size) ? RightBorder : N_size;
                int* SortedBlock = new int[RightBorder - LeftBorder];
                while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder) {
                    if (arr[LeftBorder + LeftBlockIterator].M[column] < arr[MidBorder + RightBlockIterator].M[column]) { SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].M[column]; LeftBlockIterator++;
                    }
                    else { SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].M[column]; RightBlockIterator++;
                    }
                }
                while (LeftBorder + LeftBlockIterator < MidBorder) { SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].M[column]; LeftBlockIterator++; }
                while (MidBorder + RightBlockIterator < RightBorder) { SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].M[column]; RightBlockIterator++; }
                for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++) { arr[LeftBorder + MergeIterator].M[column] = SortedBlock[MergeIterator]; }
                delete SortedBlock;
            }
        }
    }
}

void CalcArray(Matrix Arr[]) {
    double DobytokNadDopDia[N_size] = {1, 1, 1, 1, 1};
    for(int column = 0; column < N_size; column++) {
        for(int row = 0; row < N_size-column-1; row++) {
            DobytokNadDopDia[column]*=(Arr[column].M[row]);        }
    }
    double Function;
    for (int column = 0; column < N_size; column++) {
        Function += DobytokNadDopDia[column];
        std::cout << "f(" << column << "): " << DobytokNadDopDia[column] << std::endl;    }
    cout << "F(f(ij)): " << Function << endl;
}

int main()
{    Matrix  Array[N_size];
    cout << "Enter elements of matrix:\n" << endl;
    InputArray(Array);
    cout << "\nYour matrix:\n" << endl;
    OutputArray(Array);
    SortArray(Array);
    cout << "\nSorted matrix:\n" << endl;
    OutputArray(Array);
    cout << "\nCalculations:\n" << endl;
    CalcArray(Array);
}