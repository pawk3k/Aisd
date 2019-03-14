#include<iostream>
using namespace std;
int getMax(int *arr,int lentgh){
        int maximum = arr[0];
        for(int i = 0;i<lentgh;i++){
            if(arr[i] > maximum){
            maximum = arr[i];
            }
        }
        return maximum;
}
void bubbleSort(int *arr, int length){
    for(int i = 0; i<length-1;i++){
        for(int j = 0;j<length-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void insertionSort(int *arr,int length){
    for(int i = 1;i<length;i++){
    int current = arr[i];
    int  j = i-1;
    while(j>=0 && arr[j]>current){
        arr[j+1] = arr[j];
        j = j - 1;
    }
    arr[j+1] = current;
    }

}
void println(int *arr,int len){
    for(int i = 0; i<len;i++){
        cout << arr[i] << ",";
    }
    cout << endl <<endl;

}
void mergeArr(int *arr,int left,int middle,int right){
    int leftPart[middle-left+1];
    int  rightPart[right-middle];
    int lLength = sizeof(leftPart)/sizeof(*leftPart);
    int rLength = sizeof(rightPart)/sizeof(*rightPart);
    for(int i = 0;i < lLength;i++){
        leftPart[i] = arr[left+i];
    }
    for(int i = 0; i<rLength; i++){
        rightPart[i] = arr[middle + i + 1];
    }
    int i = 0;
    int j = 0;
    for(int o = left;o<=right;o++){
        if(leftPart[i]<=rightPart[j] && i!=lLength && j != rLength){
            arr[o] = leftPart[i];
            i++;
        }else if(leftPart[i]>=rightPart[j] && i!=lLength && j != rLength){
            arr[o] = rightPart[j];
            j++;
        }
        else if(i == lLength){
            arr[o] = rightPart[j];
            j++;
        }else if(j==rLength){
            arr[o] = leftPart[i];
            i++;
        }
    }
}
void mergeSort(int *arr,int  left,int right){
    if(right>left){
        int middle = (right+left)/2;
        mergeSort(arr,left,middle);
        mergeSort(arr,middle+1,right);
        mergeArr(arr,left,middle,right);
    }

}
int slice(int *arr,int left,int right){
    int key = arr[(right+left)/2];
    int i = left;
    int j = right;
    while(true){
        while(arr[i]<key){i++;}
        while(arr[j]>key){j--;}
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }else{
            return j;
        }
    }



}
void quickSort(int *arr, int left,int right){
    if (right > left){
        int midle = slice(arr,left,right);
        quickSort(arr,left,midle);
        quickSort(arr,midle+1,right);
    }

}
void selectionSort(int *arr,int length){
    for(int i = 0; i< length-1;i++){
        int minimum = i;
        for(int j=i+1;j<length;j++){
            if(arr[j] < arr[minimum]){
                minimum = j;
            }
        }
        int temp  = arr[i];
        arr[i] = arr[minimum];
        arr[minimum] = temp;
    }
}

void countingSort(int *arr,int length){
    int maxElem = getMax(arr,length);
    //cout << maxElem;
    int temporary[maxElem+1];
    int result[length];
    for(int i=0;i<=maxElem;i++){
        temporary[i] = 0;
        result[i] = 0;
    }
    for(int i=0;i<length;i++){
        temporary[arr[i]]++;

    }
    //println(temporary,maxElem+1);
    for(int l=1;l<=maxElem;l++){
        temporary[l] += temporary[l-1];
    }
    //println(temporary,maxElem+1);

    for(int i=0;i<length;i++){
        result[temporary[arr[i]]--] = arr[i];
    }
    println(result,length+1);
}

int main(){
//My data
int k[] = {6,5,4,3,6};
int masuv[100];
int dovjuna = sizeof(masuv)/sizeof(*masuv);
for(int o = 0; o <dovjuna;o++){
    masuv[o] = rand()%100;
}
println(masuv,dovjuna);
countingSort(masuv,dovjuna);
//println(masuv,dovjuna);
//int k = 5>5;
cout << endl;


return  0;}
