#include<stdio.h>
int size=0;
void swap(int *a,int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
void heapify(int arr[],int size,int i){
    if(size==1){
        printf("Single element in the heap ");
    }
    else{
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<size && arr[left]>arr[largest])
        largest=left;
        if(right<size && arr[right]>arr[largest])
        largest=right;
        if(largest != i){
            swap(&arr[i],&arr[largest]);
            heapify(arr,size,largest);
        }
    }
}

void insert(int arr[],int newNum){
    if(size==0){
        arr[0]=newNum;
        size+=1;
    }
    else{
        arr[size]=newNum;
        size+=1;
        for(int i=size/2-1;i>=0;i--){
            heapify(arr,size,i);
        }
    }
}

void deleteroot(int arr[],int num){
    int i;
    for(i=0;i<size;i++){
        if(num==arr[i])
        break;
    }
    swap(&arr[i],&arr[size-1]);
    size-=1;
    for(int i=size/2-1;i>=0;i--){
        heapify(arr,size,i);
    }
}
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[10];
    insert(arr,3);
    insert(arr,4);
    insert(arr,9);
    insert(arr,5);
    insert(arr,2);
    printf("Max array: ");
    printarray(arr,size);
    deleteroot(arr,4);
    printf("After deleteing an element: ");
    printarray(arr,size);
}


