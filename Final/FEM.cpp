
void FEM()
{
  double x[24];
  double y[24];
    
  ifstream infile;
  infile.open("fem.txt");
  if(!infile.good())
  {
      cout << "Cannot open this file" <<endl;
      return -1;
  }

  if(!infile.eof())
  {
      cout << "The file has been opened!" <<endl;
      for(int i=0;i<24;i++)
    {
        infile >> x[i];
        //cout << elementx[i] << endl;
        infile >> y[i];
        //cout << elementy[i] << endl;
    }
  }

  float A = 0.5;
 
  for(int i=0;i<7;i++);
  {
    //char str[1];
    //str[1] = "m";
    //int name = sprintf(str,"%1d",i);
    //cout << str <<endl;
    const TMatrixD K(3,3);
    TArrayD data(9);
    const int a=3*i;
    const int b=3*i+1;
    const int c=3*i+2;
    data[0] = ((x[c]-x[b])*(x[c]-x[b]))+((y[c]-y[b])*(y[c]-y[b]));
    data[1] = ((x[b]-x[c])*(x[c]-x[a]))+((y[a]-y[c])*(y[c]-y[b]));
    data[2] = ((x[a]-x[b])*(x[b]-x[c]))+((y[b]-y[a])*(y[c]-y[b]));
    data[3] = ((x[c]-x[b])*(x[a]-x[c]))+((y[c]-y[b])*(y[a]-y[c]));
    data[4] = ((x[a]-x[c])*(x[a]-x[c]))+((y[c]-y[a])*(y[c]-y[a]));
    data[5] = ((x[a]-x[c])*(x[b]-x[a]))+((y[b]-y[a])*(y[a]-y[c]));
    data[6] = ((x[c]-x[b])*(x[b]-x[a]))+((y[b]-y[a])*(y[c]-y[b]));
    data[7] = ((x[a]-x[c])*(x[a]-x[b]))+((y[b]-y[a])*(y[a]-y[c]));
    data[8] = ((x[a]-x[b])*(x[a]-x[b]))+((y[b]-y[a])*(y[b]-y[a]));
    K.SetMatrixArray(data.GetArray()); 
    const TMatrixDEigen eigen(K);
    const TMatrixD eigenvectors = eigen.GetEigenVectors();
    for(int j=0;j<3;j++)
        for(int k=0;k<3;k++)
        {
            cout << TMatrixDRow(eigenvectors,j)(k) <<endl;
        }
  
  
  
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return;

}
