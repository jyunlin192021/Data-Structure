//�L���� B093050069
//Sept.07,2022 
//���h�s�@ 
#include<iostream>
using namespace std;

int main()
{
	//��J 
	int input[10]={0};		 //��l�ƿ�J�}�C 
	int a=0;			      
	while(1)                 
	{
		cin>>input[a];
		a++;
		if(input[a-1]==0)
			break;
	}
	
	int arr[100]={0};       //��l��n!���s��}�C 
	int b,high;				 
	for(int k=0;k<a-1;k++)
	{
		int num=input[k];   
		cout<<endl;
		
		for(int i=0;i<100;i++)  //���s�k�s
		{
			arr[i]=0;
		}
		
		arr[0]=1;
		int z=1;
		while(1)
		{
			for(int i=0;i<100;i++)   //���k�B�� 
				arr[i]=arr[i]*z;
				
			for(int i=0;i<100;i++){        //�B�z�i�� 
				if(arr[i]>=10){
					b=arr[i]/10;
					arr[i]=arr[i]%10;
					arr[i+1]=arr[i+1]+b;
				}
			}
		
			for(int w=99;w>=0;w--){     //���̰��� 
				if(arr[w]!=0){
					high=w;
					break;
				}
			} 
			
			
			cout<<z<<"!=";             //�L�X 
			for(int i=high;i>=0;i--)
				cout<<arr[i];	
			cout<<endl;
			
			if(z==num)	
				break;		
			z++;
			
		}
	}
	
}
