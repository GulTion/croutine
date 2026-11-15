#include <stdio.h>
#include "croutine.h"
/*
 * TODO:
 * -[ ] give supoort for more than 5 arguments
 *
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
    cro(counter, 10, "Croutine A");
    cro(counter, 10, "Croutine B");
    cro(counter, 10, "Croutine C");
    cro(counter, 10, "Croutine D");
    cro(counter, 10, "Croutine E");
    cro(counter, 10, "Croutine F");
    cro(counter, 10, "Croutine G");
    cro(counter, 10, "Croutine H");
    cro(counter, 10, "Croutine I");



    cro_join();
}
