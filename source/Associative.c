#include <stdio.h>
#include <time.h>

#define N (1<<8<<10<<10)
int arr[N];
int loop = (1 << 16);	//for producing a accurate result

int main()
{
    clock_t start, finish;
    int sumtime = 0;

    for (int asso = 2; asso <= 16; asso += 2) {
        //suppose that associative is in (2-16)
        start = clock();
        for (int k = 0; k < loop; ++k)
            for (int i = 0; i < asso; ++i)
                arr[i << 9 << 4] = 0;	//512blocks in cache L1, 16 int/block
        finish = clock();
        int duration = finish - start;
        start = clock();		//again for accuraty
        for (int k = 0; k < loop; ++k)
            for (int i = 0; i < asso; ++i)
                i << 9 << 4 << 4;
        finish = clock();
        printf("%2dways associative's average time is %fus\n",
            asso, (double)(duration - (finish - start)) / (loop*asso));
    }
    return 0;
}