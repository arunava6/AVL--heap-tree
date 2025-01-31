#include<stdio.h>
int size=0;
void swap(int *a,int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
void heapify(int arr[],int size,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<size && arr[l]>arr[largest])
    largest=l;
    if(r<size && arr[r]>arr[largest])
    largest=r;
    if(largest != i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,size,largest);
    }
}
void heapsort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--)
    heapify(arr,n,i);
    for(int i=n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
}
int main(){
    int arr[]={1,12,55,20,4,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    printf("Sorted array: ");
    printarray(arr,n);
}




