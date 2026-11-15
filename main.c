#include <stdio.h>
#include "croutine.h"
/*
 * TODO:
 * -[ ] give supoort for more than 5 arguments
 *
 * BUGS:
 * - [x] fails on uneven counters
 *
 */


int counter(int N, char label[]){

    for(int i=0;i<N;i++){
        printf("%s: %d\n", label,i);
        cro_yield();
    }
    return 10;
}
int main(){
    cro_init();
    cro(counter, 5, "Croutine A");
    cro(counter, 10, "Croutine B");


    cro_join();
}
