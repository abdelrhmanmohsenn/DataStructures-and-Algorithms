#include <stdio.h>
#include <stdlib.h>

unsigned int arr[10]={9,5,1,3,7,4,2,6,8,0};

void printarray(unsigned int data[], unsigned int length);
void swap(unsigned int *element1, unsigned int *element2);
void BubbleSort(unsigned int data[], unsigned int length);
void insertionSort(unsigned int data[], unsigned int length);
void selectionSort(unsigned int data[], unsigned int length);

int main()
{
    insertionSort(arr,10);
    printarray(arr,10);

    return 0;
}

void printarray(unsigned int data[], unsigned int length){
    for(unsigned int i=0; i<length ; i++){
        printf("%i\t",data[i]);
    }
}

void swap(unsigned int *element1, unsigned int *element2){
    unsigned int temp=*element1;
    *element1=*element2;
    *element2=temp;
}

void BubbleSort(unsigned int data[], unsigned int length){
    unsigned int iteration=0;
    unsigned int compared_index=0;
    unsigned int sort_flag=0;

    for(iteration=0 ; iteration<length-1 ; iteration++){
        for(compared_index=0 ; compared_index<length-1-iteration ; compared_index++){
            if(data[compared_index]>data[compared_index+1]){
                swap(&data[compared_index],&data[compared_index+1]);
                sort_flag=1;
            }
        }
        if(sort_flag == 0){
            break;
        }
    }
}

void insertionSort(unsigned int data[], unsigned int length){
    unsigned int iterator=0;
    signed int compared_index=0;
    unsigned int temp=0;

    for(iterator=1 ; iterator<length ; iterator++){
        temp=data[iterator];
        compared_index=iterator-1;
        while(compared_index >=0 && data[compared_index]>temp){
            data[compared_index+1]=data[compared_index];
            compared_index--;
        }
        data[compared_index+1]=temp;
    }
}

void selectionSort(unsigned int data[], unsigned int length){
    unsigned int iterator=0;
    unsigned int minimum_index=0;
    unsigned int compared_index=0;

    for(iterator=0 ; iterator<length-1 ; iterator++){
        minimum_index=iterator;
        for(compared_index=iterator+1 ; compared_index<length ; compared_index++){
            if(data[compared_index]<data[minimum_index]){
                minimum_index=compared_index;
            }
        }
        swap(&data[iterator],&data[minimum_index]);
    }
}
