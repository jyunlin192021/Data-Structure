//林奕均 B093050069
//Sept.07,2022 
//階層製作 
#include<iostream>
using namespace std;

int main()
{
	//輸入 
	int input[10]={0};		 //初始化輸入陣列 
	int a=0;			      
	while(1)                 
	{
		cin>>input[a];
		a++;
		if(input[a-1]==0)
			break;
	}
	
	int arr[100]={0};       //初始化n!的存放陣列 
	int b,high;				 
	for(int k=0;k<a-1;k++)
	{
		int num=input[k];   
		cout<<endl;
		
		for(int i=0;i<100;i++)  //重新歸零
		{
			arr[i]=0;
		}
		
		arr[0]=1;
		int z=1;
		while(1)
		{
			for(int i=0;i<100;i++)   //乘法運算 
				arr[i]=arr[i]*z;
				
			for(int i=0;i<100;i++){        //處理進位 
				if(arr[i]>=10){
					b=arr[i]/10;
					arr[i]=arr[i]%10;
					arr[i+1]=arr[i+1]+b;
				}
			}
		
			for(int w=99;w>=0;w--){     //取最高位 
				if(arr[w]!=0){
					high=w;
					break;
				}
			} 
			
			
			cout<<z<<"!=";             //印出 
			for(int i=high;i>=0;i--)
				cout<<arr[i];	
			cout<<endl;
			
			if(z==num)	
				break;		
			z++;
			
		}
	}
	
}
