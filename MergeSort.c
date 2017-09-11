#include <stdlib.h>
#include <stdio.h>

void MergeSort(int* arr, int len);
void MergeArr(int* leftArr, int* rightArr ,int* sortedArr, int len);

int main()
{
 int i;
    int a[16] = {73,234,124,626,134124,643,123,523,6662,1244,99999,2135,65,23,1,6};
    MergeSort(a, 16);

    for(i=0;i<16;i++) printf("%d, ", a[i]);
    return 0;
}

void MergeSort(int* arr, int len)
{
    if(len < 2) return;

    int* leftArr = (int*)malloc(sizeof(int)*(len/2));
    int* rightArr = (int*)malloc(sizeof(int)*(len/2));

    int i;
    for(i=0; i<len/2; i++)
        leftArr[i]=arr[i];

    for(i=len/2; i<len; i++)
        rightArr[i-len/2]=arr[i];

    MergeSort(leftArr, len/2);
    MergeSort(rightArr, len/2);

    MergeArr(leftArr, rightArr, arr, len);

    free(leftArr);
    free(rightArr);
}

void MergeArr(int* leftArr, int* rightArr ,int* sortedArr, int len)
{
    int i=0, j=0, k=0;
    for(; i<len; i++)
    {
        if(j<len/2 && k<len/2)
        {
            if(leftArr[j]<rightArr[k])
            {
                sortedArr[i]=leftArr[j];
                j++;
            }

            else
            {
                sortedArr[i]=rightArr[k];
                k++;
            }
        }

        else
        {
            if(k<len/2)
            {
                sortedArr[i]= rightArr[k];
                k++;
            }

            if(j<len/2)
            {
                sortedArr[i] = leftArr[j];
                j++;
            }
        }
    }
}
