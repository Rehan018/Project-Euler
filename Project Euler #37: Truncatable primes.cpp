#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int is_prime(int num){

  if (num == 1) return 0;
  for (int i= 2; i<=sqrt(num); i++) {
     if(num%i == 0) return 0;
  }
  return 1;
}

int main() {

int n;
scanf("%d",&n);
unsigned long long int sum = 0;
for (int i = 11 ; i<n; i++) {
     if(is_prime(i)){
         int digit = 1+log10(i),flag = 0;
         for (int j = 1; j<digit; j++) {
              if(is_prime(i/pow(10,j)) && is_prime(i%(int) pow(10,digit-j))) continue;
               else {
                   flag = 1;
                   break;
               }
         }
         if(flag == 0)  
             sum += i;
     }
}
printf("%lld\n",sum);
return 0;
}
