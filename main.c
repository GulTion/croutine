#include <stdio.h>
#include "croutine.h"
/*
 * TODO:
 * - give supoort for more than 5 arguments
 *
 */


int counter(int N, char label[]){

    for(int i=0;i<N;i++){
        printf("%s: %d\n", label,i);
        // cro_yield();
    }
    return 10;
}
int main(){
    // cro_init();

    // cro(counter, );
    int k = cro(counter, 10, "Croutine A");
    printf("%d", k);
    // cro(counter, 20, "Croutine B");
    //
    // cro_join();
}
