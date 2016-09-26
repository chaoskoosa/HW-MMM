/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 26, 2016, 12:42 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;


int *arrayFill (int);
int *mode (int, int);
int *sort(int *,int);
void prntAry(int *, int, int = 10);
int *copy(int *a,int n);
/*
 * 
 */
int main(int argc, char** argv) {
    int size;
    cout << "Enter random number generated array size: ";
    cin >> size;
    int *array=arrayFill(size);
    
    //Print unsorted
    prntAry(array, size, 10);
    int *array2=sort(array,size);
    int *array3=mode(array2, size);
    
    prntAry(array2,size);
    
    //To prevent memory leaks
    delete []array;
    delete []array2;
    return 0;
}

int *arrayFill(int s){
    //Allocate the memory
    int *array=new int[s];
    //Set the random number seed by the clock
    srand(static_cast<unsigned int>(time(0)));
    //Fill the array with random 2 digit numbers
    for(int i=0;i<s;i++){
        *(array+i)=rand()%90+10;
    }
    return array;
}

int *sort(int *a,int n){
    //Copy the array
    int *array2=copy(a,n);
    //Sort the array
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(*(array2+i)>*(array2+j)){
                *(array2+i)=*(array2+i)^*(array2+j);
                *(array2+j)=*(array2+i)^*(array2+j);
                *(array2+i)=*(array2+i)^*(array2+j);
            }
        }
    }
    return array2;
}

int *copy(int *a,int n){
    //Allocate a new array and fill
    int *b=new int[n];
    for(int i=0;i<n;i++){
        *(b+i)=*(a+i);
    }
    return b;
}

int *mode (*int m, int s);
{
    
}

void prntAry(int *a,int n,int perLine){
    cout << endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}