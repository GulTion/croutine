#include <stdio.h>
/*
 * TODO:
 * - give supoort for more than 5 arguments
 *
 */


void cro(int(*fn)(), ...);
// void cro_init(void);


int counter(int N, char label[]){
    // int N=10; char label[] = "Counter A";
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
    // cro(counter, 20, "Croutine B");
    //
    // cro_join();
}
