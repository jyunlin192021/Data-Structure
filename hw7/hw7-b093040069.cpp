//B093040069 �L����
//2022/11/17
// sorting�t��k����Ĳv 
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

void displayInsertion(int *arr, int size){   //Insertionsort���G�g�J�ɮ� 
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

    // �Q�� std::vector ��constructor, 
    // ��array[front]~array[mid]��i LeftSub[]
    // ��array[mid+1]~array[end]��i RightSub[]
    std::vector<int> LeftSub(Array.begin()+front, Array.begin()+mid+1),
                     RightSub(Array.begin()+mid+1, Array.begin()+end+1);

    LeftSub.insert(LeftSub.end(), 50000);      // �bLeftSub[]���ݥ[�J�Ȭ� Max ������
    RightSub.insert(RightSub.end(), 50000);    // �bRightSub[]���ݥ[�J�Ȭ� Max ������

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
                                         // front�Pend���x�}�d��
    if (front < end) {                   // ��ܥثe���x�}�d��O���Ī�
        int mid = (front+end)/2;         // mid�Y�O�N�x�}��b����index
        MergeSort(array, front, mid);    // �~��divide�x�}���e�b�qsubarray
        MergeSort(array, mid+1, end);    // �~��divide�x�}����b�qsubarray
        Merge(array, front, mid, end);   // �N���subarray�����, �æX�֥X�Ƨǫ᪺�x�}
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
	while( file>>size )             //Ū�ɪ��Ĥ@�� size 
	{
		data= new int [size];
		for(int i=0 ; i<size ; i++ )
		{
			file>>data[i];              //����Ū�� 
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
		
	//C�禡�w stdlib.h�@�� cstdlib�Aqsort( )�禡
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

	//C++�禡�w (STL) sort( )�禡
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
//	cout << (double)clock() / CLOCKS_PER_SEC << "S"; //�p��ɶ� 
	
	
	
	
} 
