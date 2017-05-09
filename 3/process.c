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
    while(1){
        starttime = clock();
        while((clock()-starttime) <= (double)busytime * CLOCKS_PER_SEC / 50 * cpu )
            //cout << clock() << endl;
            ;
        sleep(idletime);
    }
    return 0;
}
