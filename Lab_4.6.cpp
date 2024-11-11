#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   double P, S;
   int n, k; 

   P = 1;
   n = 1;
   while (n <= 10)
   {
      S = 0;
      k = 1;
      while (k <= n)
      {
         S += sin(1. *k)*sin(1. *k);
         k++;
      }
      P *= (cos(n) + S);
      n++;
   }
   cout << P << endl;

   P = 1;
   n = 1;
   do {
      S = 0;
      k = 1;
      do {
         S += sin(1. *k)*sin(1. *k);
         k++;
      } while (k <= n);
      P *= (cos(n) + S);
      n++;
   } while (n <= 10);
   cout << P << endl;

   P = 1;
   for (n=1; n<=10; n++)
   {
      S = 0;
      for (k=1; k<=n; k++)
      {
         S += sin(1. *k)*sin(1. *k);
      }
      P *= (cos(n) + S);
   }
   cout << P << endl;

   P = 1;
   for (n=10; n>=1; n--)
   {
      S = 0;
      for (k=n; k>=1; k--)
      {
         S += sin(1. *k)*sin(1. *k);
      }
      P *= (cos(n) + S);
   }
   cout << P << endl;

   return 0;
}