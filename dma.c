#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<sys/types.h>
const int INITSIZE = 10;
typedef struct dynamicArray
{
    unsigned int size;
    unsigned int capacity;
    int *arr;
}dynamicArray;
void arrayInit(dynamicArray *a)
{
    a->size = 0;
    a->capacity = INITSIZE;
    a->arr = (int*)malloc(sizeof(int)*INITSIZE);
}
void arrayInsert(dynamicArray *a, int element)
{
    if(a->size == a->capacity)
    {
        a->capacity *= 2;
        a->arr = (int*)realloc(a->arr, sizeof(int)*a->capacity);
    }
    a->arr[a->size++] = element;
}
void arrayFree(dynamicArray *a)
{
    free(a->arr);
    a->size = 0;
    a->capacity = 0;
}
void arrayPrint(dynamicArray *a)
{
    for(int i = 0; i < a->size; i++)
    {
        printf("%d ", a->arr[i]);
    }
    printf("\n");
}
void arrayDelete(dynamicArray *a, int index)
{
    if(index < 0 || index >= a->size)
    {
        printf("Invalid index\n");
        return;
    }
    for(int i = index; i < a->size - 1; i++)
    {
        a->arr[i] = a->arr[i + 1];
    }
    a->size--;
}
void arrayInsertAt(dynamicArray *a, int index, int element)
{
    if(index < 0 || index >= a->size)
    {
        printf("Invalid index\n");
        return;
    }
    if(a->size == a->capacity)
    {
        a->capacity *= 2;
        a->arr = (int*)realloc(a->arr, sizeof(int)*a->capacity);
    }
    for(int i = a->size; i > index; i--)
    {
        a->arr[i] = a->arr[i - 1];
    }
    a->arr[index] = element;
    a->size++;
}
int main()
{

}

