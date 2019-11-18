#include <iostream>

 void SortArray(Matrix  arr[])
{ 
for (int i = 0; i < n; i++)
{ 
for (int Size = 1;
       Size < n; Size *= 2)
{ 
for (int BlItr = 0; BlItr < n - Size;BlItr += 2 * Size)
{ 
int LftBlItr = 0;
int RBlItr = 0;
int LftBdr = BlItr;
int MidBdr = BlItr + Size;
int RBdr = BlItr + 2 * Size; RBdr = (RBdr < n) ? RBdr : n;
int* SortedBlock = new int[RBdr - LftBdr];
                while (LftBdr + LftBlItr < MidBdr && MidBdr + RBlItr < RBdr)
                { if (arr[LftBdr + LftBlItr].M[i] < arr[MidBdr + RBlItr].M[i]) { SortedBlock[LftBlItr + RBlItr] = arr[LftBdr + LftBlItr].M[i]; LftBlItr++; }
                else { SortedBlock[LftBlItr + RBlItr] = arr[MidBdr + RBlItr].M[i]; RBlItr++; } 
                } while (LftBdr + LftBlItr < MidBdr) { SortedBlock[LftBlItr + RBlItr] = arr[LftBdr + LftBlItr].M[i]; LftBlItr++; }
                while (MidBdr + RBlItr < RBdr) { SortedBlock[LftBlItr + RBlItr] = arr[MidBdr + RBlItr].M[i]; RBlItr++; }
                for (int MergeIterator = 0; MergeIterator < LftBlItr + RBlItr; MergeIterator++) { arr[LftBdr + MergeIterator].M[i] = SortedBlock[MergeIterator];
                } delete SortedBlock;
            }
        } } }