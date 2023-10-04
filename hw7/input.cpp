#include<iostream>
#include<fstream>
#include <cstdlib> //rand()
#include <ctime> //time()
using namespace std;
int main()
{
	int num=100;     //看要輸入多少值 
	ofstream file ("input.txt");

	file<<num<<endl;           
	for(int i=0;i<num;i++)
	{
		int a=rand()%500+1; //設定範圍 
		cout << a <<endl;
		file<< a <<endl;    //寫入檔案 
	}

	file.close();
	
	

}

