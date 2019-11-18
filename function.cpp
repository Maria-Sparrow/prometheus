
void InputArray(Matrix  Arr[]) 
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
    {            cin >> Arr[i].M[j];        }

} 
void OutputArray(Matrix  Arr[])
{    for (int i = 0; i < n; ++i)
{        for (int j = 0; j < m; ++j)
{            cout << Arr[i].M[j] << "\t";
}        cout << endl;
}
}
void CalcArray(Matrix Arr[])
        {    
double DobytokNadDopDia[n] = {1, 1, 1, 1, 1};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n-i-1; j++) {
               
 DobytokNadDopDia[i]*=(Arr[i].M[j]);       
 }
    }    double haunt;
        for (int i = 0; i < n; i++) {
            haunt += DobytokNadDopDia[i];
            std::cout << "f(" << i << "): " << DobytokNadDopDia[i] << std::endl;  
  }
    cout << "F(f(ij)): " << haunt << endl;