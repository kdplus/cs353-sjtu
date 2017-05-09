#include <cstring>
#include <stdlib.h>
#include<stdio.h>
#include <iostream>
#include<unistd.h>
#include<time.h>
using namespace std;

int main(int argc, char *argv[]){
    int busytime=1;
    int idletime=busytime;
    clock_t starttime;
    int cpu = atoi(argv[1]);
    int mem = atoi(argv[2]);
    long long* large_mem = new long long[mem * 100000];
    for (int i = 0; i < mem*100000; ++i) large_mem[i] = i;
    while(1){
        starttime = clock();
        while((clock()-starttime) <= (double)busytime * CLOCKS_PER_SEC / 50 * cpu )
            //cout << clock() << endl;
            ;
        sleep(idletime);
    }
    return 0;
}
