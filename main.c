#include <stdio.h>
#include "croutine.h"

void counter(int N, char label[]){
    for(int i=0;i<N;i++){
        printf("%s: %d\n", label,i);
        cro_yield();
    }
}
int main(){
    cro_init();
    cro(counter, 5, "Croutine A");
    cro(counter, 10, "Croutine B");
    cro_join();
}
