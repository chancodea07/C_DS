#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/dynamicArray.h"
#include "./include/Array_fun.h"

void initArray(Dynamic_Array *Array) //初始化
{
    Array->pHead = (int *)malloc(sizeof(int) * Array->Array_size);
    Array->Array_size = ARR_SIZE;
    Array->Array_num = 0;
}
void Inflation(Dynamic_Array *Array, int number)
{
    //判断数组是否已经满员
    if (Array->Array_num == Array->Array_size)
    {
        //数组扩容
        Array->Array_size += ARR_SIZE;
        //申请新空间
        int *newArray = (int *)malloc(sizeof(int) * Array->Array_size);
        //原数据赋值进入新空间
        for (unsigned int i = 0; i < Array->Array_num; i++)
        {
            newArray[i] = Array->pHead[i];
        }
        free(Array->pHead);
        Array->pHead = newArray;
    }
    Array->pHead[Array->Array_num] = number;
    Array->Array_num++;
}
void PrintArray(Dynamic_Array *Array)
{
    if (Array == NULL)
    {
        printf("数组为空！\n");
        return;
    }
    int *pTemp = Array->pHead;
    int num = 0;
    printf("已存数量 %u 容量为 %u\n数据如下所示：", Array->Array_num, Array->Array_size);
    while (num++ != Array->Array_num)
        printf("%d ", *pTemp++);
    printf("\n");
}
void InsertElement(Dynamic_Array *Array, int number, int index)
{ //参数合法性监测，下标如果大于Array->Array_num，则插入在最后
    if (Array == NULL || index < 0)
    {
        printf("参数错误！\n");
        return;
    }
    SpaceInflate(Array);
    if (index > Array->Array_num)
    {
        index = Array->Array_num;
    }
    //向后挪
    for (unsigned int i = Array->Array_num; i > index; i--)
    {
        Array->pHead[i] = Array->pHead[i - 1];
    }
    //数据赋值到指定位置，元素的数量增加
    Array->pHead[index] = number;
    Array->Array_num++;
}
void SpaceInflate(Dynamic_Array *Array)
{
    if (Array == NULL)
    {
        return;
    }

    if (Array->Array_num == Array->Array_size)
    {
        //数组扩容
        Array->Array_size += ARR_SIZE;
        //申请新空间
        int *newArray = (int *)malloc(sizeof(int) * Array->Array_size);
        memset(newArray, 0, sizeof(int) * Array->Array_size); /* 空间初始化，不必要 */
        //原数据赋值进入新空间
        for (unsigned int i = 0; i < Array->Array_num; i++)
        {
            newArray[i] = Array->pHead[i];
        }
        free(Array->pHead);
        Array->pHead = newArray;
    }
}
