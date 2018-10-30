int a,b,c;
float m,n;
int fibo(int a) 
{
  if (a==1|| a==2) return 1;
  return fibo(a-1) + fibo(a-2);
}
// int fibo()
// {
//   return 0;
// }
int main() 
{
  // int m[];
  int m,n,i;//m redefined
  int j =1;
  // i = 0.001;// type error?
  // m = 'a';
  // l = 1;//l undefined
  m = read();
  i = 1;
  // i =1.1;//assign type unmatch 
  while(i<=m)
  {
    n = fibo(i);
    write(n);
    // write(n,m,1,1,1);  
    i = i+1;
    break;
  }
  return 1;
}