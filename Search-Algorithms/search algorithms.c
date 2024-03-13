#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 10

int BinarySearch(unsigned int Data[], unsigned int start, unsigned int end, unsigned int req_data);
int linearsearch(unsigned int Data[], unsigned int length, unsigned int req_data);

unsigned int Data[ARRAY_LENGTH]={11,22,33,44,55,66,77,88,99,100};

int main()
{
    int ret=0;
    //ret = linearsearch(Data, ARRAY_LENGTH, 77);
    ret = BinarySearch(Data, 0, ARRAY_LENGTH-1, 22);
    printf("%i\n",ret);

    return 0;
}

int BinarySearch(unsigned int Data[], unsigned int start, unsigned int end, unsigned int req_data){
    unsigned int middle=0;
    int ret=-1;

    while(start <= end){
        middle = start + ((end-start)/2);
        if(Data[middle] == req_data){
            ret=middle;
            break;
        }
        else if(Data[middle] > req_data){
            end=middle-1;
        }
        else if(Data[middle] < req_data){
            start=middle+1;
        }
    }

    return ret;
}

int linearsearch(unsigned int Data[], unsigned int length, unsigned int req_data){
    int ret=-1;
    unsigned int leftindex=0;
    unsigned int rightindex=length-1;

    for(leftindex=0 ; leftindex<=rightindex-leftindex ; leftindex++){
        if(req_data == Data[leftindex]){
            ret=leftindex;
            break;
        }
        else if(req_data == Data[rightindex-leftindex]){
            ret=rightindex-leftindex;
            break;
        }
    }

    return ret;
}
