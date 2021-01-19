#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/dynamicArray.h"
#include "./include/Array_fun.h"

void initArray(Dynamic_Array *Array) //��ʼ��
{
    Array->pHead = (int *)malloc(sizeof(int) * Array->Array_size);
    Array->Array_size = ARR_SIZE;
    Array->Array_num = 0;
}
void Inflation(Dynamic_Array *Array, int number)
{
    //�ж������Ƿ��Ѿ���Ա
    if (Array->Array_num == Array->Array_size)
    {
        //��������
        Array->Array_size += ARR_SIZE;
        //�����¿ռ�
        int *newArray = (int *)malloc(sizeof(int) * Array->Array_size);
        //ԭ���ݸ�ֵ�����¿ռ�
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
        printf("����Ϊ�գ�\n");
        return;
    }
    int *pTemp = Array->pHead;
    int num = 0;
    printf("�Ѵ����� %u ����Ϊ %u\n����������ʾ��", Array->Array_num, Array->Array_size);
    while (num++ != Array->Array_num)
        printf("%d ", *pTemp++);
    printf("\n");
}
void InsertElement(Dynamic_Array *Array, int number, int index)
{ //�����Ϸ��Լ�⣬�±��������Array->Array_num������������
    if (Array == NULL || index < 0)
    {
        printf("��������\n");
        return;
    }
    SpaceInflate(Array);
    if (index > Array->Array_num)
    {
        index = Array->Array_num;
    }
    //���Ų
    for (unsigned int i = Array->Array_num; i > index; i--)
    {
        Array->pHead[i] = Array->pHead[i - 1];
    }
    //���ݸ�ֵ��ָ��λ�ã�Ԫ�ص���������
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
        //��������
        Array->Array_size += ARR_SIZE;
        //�����¿ռ�
        int *newArray = (int *)malloc(sizeof(int) * Array->Array_size);
        memset(newArray, 0, sizeof(int) * Array->Array_size); /* �ռ��ʼ��������Ҫ */
        //ԭ���ݸ�ֵ�����¿ռ�
        for (unsigned int i = 0; i < Array->Array_num; i++)
        {
            newArray[i] = Array->pHead[i];
        }
        free(Array->pHead);
        Array->pHead = newArray;
    }
}
