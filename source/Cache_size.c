#include <stdio.h>
#include <time.h>
#define N 2*1024*1024	//数组占用内存最大 2*1024*1024*4B=8MB
int arr[N];
int loop = (1 << 24);


int main()
{
    clock_t start, cost_time;
    int count = 1;
    FILE *fp = NULL;
    fp = fopen("cache_size.txt", "w");
    for (int length = 256; length <= N; length += 256) {
        start = clock();
        int lengthmod = length - 1;
        for (int i = 0; i < loop; ++i) {
            ++arr[(i * 16) & lengthmod];
        }
        cost_time = clock() - start;
        printf("memory size: %4dk: array length: %7d, cost_time: %dms\n", count, length, cost_time);
        fprintf(fp, "memory size: %4dk: array length: %7d, cost_time: %dms\n", count, length, cost_time);
        ++count;
    }
    fclose(fp);
    fp = NULL;
    return 0;
}