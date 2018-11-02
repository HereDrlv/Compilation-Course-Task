int a,b,c;
// float m,n;
int fibo(int a) 
{
  if (a==1|| a==2) return 1;
  return fibo(a-1) + fibo(a-2);
}
int main() 
{
  int m,n,i;
  i = 1;
  m = read();  
  write(m);
  // i++;
  // (i+i)++;
  // 1++;
  // i+=12;
  // m+=2;
  while(i<=m)
  {
    n = fibo(i);
    write(n);
    // i = i+1;
    // i+=1;
    i++;
  }
  return 1;
}