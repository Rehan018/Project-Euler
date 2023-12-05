#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

int countDivisors(uint32_t n){
    int divisors = 0;
    for(uint32_t i=1;i*i<=n;i++)
        if(n%i==0)
            if(i*i < n) divisors+=2;
            else if(i*i == n) if(n!=1) divisors+=1;
    if(n!=1) divisors-=1;
    return divisors;
}

int main(){
    int T,N,local=1;
    scanf("%d",&T);
    uint16_t arrayN[T],max=1;
    for(int a0=0;a0<T;++a0){
        scanf("%d",&N);
        arrayN[a0] = N;
        max = arrayN[a0]>max?arrayN[a0]:max;
    }

    uint32_t numTriangular,*arrayResult = (uint32_t*)malloc(max*sizeof(uint32_t));
    
    for(int a0=1;a0<=max;++a0){
        while(true){
            numTriangular= (uint32_t)(local*(local+1)/2);
            if(countDivisors(numTriangular) >= a0) break;
            local++;
        }
        arrayResult[a0-1]=numTriangular;
    }

    for(int a0=0;a0<T;++a0)
        printf("%lu\n",arrayResult[arrayN[a0]-1]);
    free(arrayResult);
    return 0;
}
