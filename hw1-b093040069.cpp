//�L���� B093050069
//Sept.07,2022 
//�s�@1,3,5,7,9���]��} 
#include<iostream>
#include<iomanip>
using namespace std;

void output(int n)             //��ưѼ�:n���]��} 
{
	int arr[100][100];         //�]�w�@��100*100���}�C 
	
	for(int i=0;i<n;i++)       //����l�ư}�C 
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=0;
		}
	}
	
	if(n==1)                   //�L�X�@���]��} 
		cout<<setw(2)<<n<<endl;
	else                       //�]��}�s�@��k 
	{
		arr[0][n/2]=1;     
		int k=2;              //�]�wk=2 
		while(1){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(arr[i][j]==k-1){
						if(i==0&&j==0&&arr[n-1][n-1]==0)          //�̥��B�̤W�ɩ�J�̥k�̤U 
							arr[n-1][n-1]=k;
						else if(i==0&&j!=0&&arr[n-1][j-1]==0)     //�̥����D�̤W�ɩ�J�̥k�B���W��1 
							arr[n-1][j-1]=k;
						else if(i!=0&&j==0&&arr[i-1][n-1]==0)     //�D�̥������̤W�ɩ�J�̤U�B������1 
							arr[i-1][n-1]=k;
						else if(i!=0&&j!=0&&arr[i-1][j-1]==0)     //�D�̥��B�D�̤W�ɩ�����1�B���W��1 
							arr[i-1][j-1]=k;
						else                                      //�쥻�\��B�w����ơB���U�� 
							arr[i+1][j]=k;                         
					}
				}
			}
			k=k+1;
			if(k>n*n)    //������J��������X�j�� 
				break;
			
		}
		
		//�C�L1���H�~���]��} 
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<setw(2)<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
}




int main()
{
	int num=1;                 //��l�]��}���� 
	
	while(num<10){ 
		cout<<num<<"��:"<<endl;
		output(num);
		num=num+2;              
	}
	

} 
