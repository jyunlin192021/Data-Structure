#include<iostream>
#include<fstream>
#include <cstdlib> //rand()
#include <ctime> //time()
using namespace std;
int main()
{
	int num=100;     //�ݭn��J�h�֭� 
	ofstream file ("input.txt");

	file<<num<<endl;           
	for(int i=0;i<num;i++)
	{
		int a=rand()%500+1; //�]�w�d�� 
		cout << a <<endl;
		file<< a <<endl;    //�g�J�ɮ� 
	}

	file.close();
	
	

}

