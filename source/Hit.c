#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 1024*1024
int loop = (1 << 25);
int arr[N];

int main()
{
    clock_t start, finish;
    double sumtime = 0;
    for (int k = 0; k < 16; k++) {
        start = clock();
        for (int i = 0; i < loop; ++i) {
            int index = (i * 16) & (N - 1);	//gurantee that it does miss
            arr[index] *= 3;	//meaningless
        }
        finish = clock();
        int duration = finish - start;
        start = clock();			//minus the time taked by lopps
        for (int i = 0; i < loop; ++i) {
            int index = (i * 16) & (N - 1);
        }
        finish = clock();
        double tmp = (double)(duration - (finish - start)) / loop;
        sumtime += tmp;
        printf("the miss time is %fus\n", tmp);
    }
    printf("\nThe average miss time is %fus\n", sumtime / 16);

    sumtime = 0;
    for (int k = 0; k < 16; k++) {
        arr[0] = 1;
        start = clock();
        for (int i = 0; i < loop; ++i) {
            arr[0] *= 3;		//always visit the arr[0] ;)
        }
        finish = clock();
        int duration = finish - start;
        start = clock();
        for (int i = 0; i < loop; ++i) {

        }
        finish = clock();
        double tmp = (double)(duration - (finish - start)) / loop;
        sumtime += tmp;
        printf("the hit  time is %fus\n", tmp);
    }
    printf("\nThe average hit  time is %fus\n", sumtime / 16);

    return 0;
}