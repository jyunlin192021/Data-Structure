//製作1,3,5,7,9階魔方陣 
#include<iostream>
#include<iomanip>
using namespace std;

void output(int n)             //函數參數:n階魔方陣 
{
	int arr[100][100];         //設定一個100*100的陣列 
	
	for(int i=0;i<n;i++)       //先初始化陣列 
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=0;
		}
	}
	
	if(n==1)                   //印出一階魔方陣 
		cout<<setw(2)<<n<<endl;
	else                       //魔方陣製作方法 
	{
		arr[0][n/2]=1;     
		int k=2;              //設定k=2 
		while(1){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(arr[i][j]==k-1){
						if(i==0&&j==0&&arr[n-1][n-1]==0)          //最左且最上時放入最右最下 
							arr[n-1][n-1]=k;
						else if(i==0&&j!=0&&arr[n-1][j-1]==0)     //最左但非最上時放入最右、往上移1 
							arr[n-1][j-1]=k;
						else if(i!=0&&j==0&&arr[i-1][n-1]==0)     //非最左但為最上時放入最下、往左移1 
							arr[i-1][n-1]=k;
						else if(i!=0&&j!=0&&arr[i-1][j-1]==0)     //非最左且非最上時往左移1、往上移1 
							arr[i-1][j-1]=k;
						else                                      //原本擺放處已有資料、往下放 
							arr[i+1][j]=k;                         
					}
				}
			}
			k=k+1;
			if(k>n*n)    //全部放入完畢後跳出迴圈 
				break;
			
		}
		
		//列印1階以外的魔方陣 
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
	int num=1;                 //初始魔方陣階數 
	
	while(num<10){ 
		cout<<num<<"階:"<<endl;
		output(num);
		num=num+2;              
	}
	

} 
