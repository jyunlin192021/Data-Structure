#include<iostream>
#include<fstream>
#include <cstdlib> //rand()
#include <ctime> //time()
using namespace std;
int main()
{
	int num=500;
	ofstream file ("input.txt");

	file<<num<<endl;
	for(int i=0;i<num;i++)
	{
		int a=rand()%500+1;
		cout << a <<endl;
		file<< a <<endl;
	}

	file.close();
	
	

}

