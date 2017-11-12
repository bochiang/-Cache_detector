#include <stdio.h>  
#include <stdlib.h>  
#include <windows.h>  
__int64 __declspec(naked) read_time_stamp_counter()
{
    __asm cpuid;//ʹ�û��ָ�����ʱ�侫�ȸ���
    __asm rdtsc;
    __asm ret;
}
#define SIZE_1KB (1024)
#define SIZE_1MB (1024*1024)
#define NUMBER 128*SIZE_1MB 
int main()
{
    long long ticks_1, ticks_2;
    long perus;
    int i, step, s;;
    int * a;
    ticks_1 = (double)read_time_stamp_counter();
    Sleep(1000);
    ticks_2 = (double)read_time_stamp_counter();
    perus = (ticks_2 - ticks_1) / (1000 * 1000);//����cpu��ǰʱ��Ƶ��

    //����ȱʧ����
    a = (int *)malloc(NUMBER*sizeof(int));
    step = SIZE_1KB * 4;
    s = 1;
    ticks_1 = (double)read_time_stamp_counter();
    for (i = 1; i < SIZE_1KB; i++) {
        a[s] = 1;
        s = s + step;
    }
    ticks_2 = (double)read_time_stamp_counter();
    printf("ȱʧ����: %.8f us\n", (double)(ticks_2 - ticks_1) / perus / SIZE_1KB);

    return 0;
}