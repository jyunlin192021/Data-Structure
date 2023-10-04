// sorting演算法執行效率 
#include <iostream>
#include <vector>
#include<fstream>
#include <stdlib.h>
#include<time.h>
#include <algorithm>
using namespace std;


void Insertion(int *arr,int size) //Insertion sort
{
	for(int i=0;i<size;i++)
	{
		int key = arr[i] ;
		int j = i-1;
		while( key < arr[j] && j>=0 )
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
 } 

void displayInsertion(int *arr, int size){   //Insertionsort結果寫入檔案 
	fstream file;
	file.open("outputA.txt",ios::out | ios::trunc) ;
	file<<"Insertion sort: "<<endl;
    for (int i = 0; i < size; i++) {
        file << arr[i] <<endl;
    }
    file.close();
    //std::cout << std::endl;
}


void Merge(std::vector<int> &Array, int front, int mid, int end){

    // 利用 std::vector 的constructor, 
    // 把array[front]~array[mid]放進 LeftSub[]
    // 把array[mid+1]~array[end]放進 RightSub[]
    std::vector<int> LeftSub(Array.begin()+front, Array.begin()+mid+1),
                     RightSub(Array.begin()+mid+1, Array.begin()+end+1);

    LeftSub.insert(LeftSub.end(), 50000);      // 在LeftSub[]尾端加入值為 Max 的元素
    RightSub.insert(RightSub.end(), 50000);    // 在RightSub[]尾端加入值為 Max 的元素

    int idxLeft = 0, idxRight = 0;

    for (int i = front; i <= end; i++) {

        if (LeftSub[idxLeft] <= RightSub[idxRight] ) {
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else{
            Array[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}








void MergeSort(std::vector<int> &array, int front, int end){
                                         // front與end為矩陣範圍
    if (front < end) {                   // 表示目前的矩陣範圍是有效的
        int mid = (front+end)/2;         // mid即是將矩陣對半分的index
        MergeSort(array, front, mid);    // 繼續divide矩陣的前半段subarray
        MergeSort(array, mid+1, end);    // 繼續divide矩陣的後半段subarray
        Merge(array, front, mid, end);   // 將兩個subarray做比較, 並合併出排序後的矩陣
    }
}

void PrintMergeSort(std::vector<int> &array){

    fstream file;
	file.open("outputB.txt",ios::out | ios::trunc) ;
	file<<"Merge sort: "<<endl;
    for (int i = 0; i < array.size(); i++) {
        file << array[i] << " ";
    }
    file.close();
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(int *arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}
void PrintQuickSort(int *arr, int size){
   	fstream file;
	file.open("outputC.txt",ios::out | ios::trunc) ;
    file<<"Quick sort:"<<endl;
	for (int i = 0; i < size; i++) {
        file << arr[i] << " ";
    }
    file.close();
}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}





int main()
{
	double START,END;
	START = clock();
	int size=0;
	int *data=NULL;
	fstream file;
	
	//Insertion sort 
	file.open( "input.txt");
	while( file>>size )             //讀檔的第一行 size 
	{
		data= new int [size];
		for(int i=0 ; i<size ; i++ )
		{
			file>>data[i];              //接續讀值 
		}
		
		Insertion( data , size );
		displayInsertion( data , size );
		delete [] data;
		data = NULL ;
		
	}
	
	
	file.close();
	
//	cout<<"finish"<<endl;
		// MergeSort
	vector <int> array; 
	file.open("input.txt");
	
	while(file >> size)
    {
        data = new int[size]; 
        for(int i=0;i<size;i++)
        {	
            file >> data[i];
            array.push_back(data[i]);
        }
        MergeSort(array,0,size-1);
		PrintMergeSort(array);
        delete[] data;
        data = 0;
    }
	file.close();
	//QuickSort
	file.open("input.txt");
	
	while(file >> size)
    {
        data = new int[size]; 
        for(int i=0;i<size;i++)
        {
            file >> data[i];
        }
        QuickSort(data,0,size-1);
		PrintQuickSort(data,size);
        delete[] data;
        data = 0;
    }
	file.close();
		
	//C函式庫 stdlib.h　或 cstdlib，qsort( )函式
	file.open("input.txt");
	
	while(file >> size)
    {
        data = new int[size]; 
        for(int i=0;i<size;i++)
        {
            file >> data[i];
        }   
    }
    qsort(data,size,sizeof(int),cmpfunc);
    file.close();  
	file.open("outputD.txt",ios::out | ios::trunc) ;
	file<<"Cqsort() : "<<endl;
    for (int i = 0; i < size; i++) {
        file << data[i] << " ";
    }
    delete[] data;
        data = 0;
	file.close();

	//C++函式庫 (STL) sort( )函式
	file.open("input.txt");
	
	while(file >> size)
    {
        data = new int[size]; 
        for(int i=0;i<size;i++)
        {
            file >> data[i];
        }   
    }
    sort(data,data+size);
    file.close();  
	file.open("outputE.txt",ios::out | ios::trunc) ;
    file<<"C++sort() : "<<endl;
	for (int i = 0; i < size; i++) {
        file << data[i] << " ";
    }
    delete[] data;
        data = 0;
	file.close();
	
 
	cout<<"finish"<<endl;
//	cout << (double)clock() / CLOCKS_PER_SEC << "S"; //計算時間 
	
	
	
	
} 
