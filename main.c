#include <stdio.h>
/*
 * TODO:
 * - give supoort for more than 5 arguments
 *
 */


void cro(void(*fn)(), ...);
// void cro_init(void);


void counter(int N, char label[]){
    // int N=10; char label[] = "Counter A";
    for(int i=0;i<N;i++){
        printf("%s: %d\n", label,i);
        // cro_yield();
    }
}
int main(){
    // cro_init();

    // cro(counter, );
    cro(counter, 10, "Croutine A");
    // cro(counter, 20, "Croutine B");
    //
    // cro_join();
}
