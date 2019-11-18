int main()
{    
Matrix  Array[n];   
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