//狶А B093050069
//Sept.07,2022 
//籹1,3,5,7,9顶臸よ皚 
#include<iostream>
#include<iomanip>
using namespace std;

void output(int n)             //ㄧ计把计:n顶臸よ皚 
{
	int arr[100][100];         //砞﹚100*100皚 
	
	for(int i=0;i<n;i++)       //﹍て皚 
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=0;
		}
	}
	
	if(n==1)                   //顶臸よ皚 
		cout<<setw(2)<<n<<endl;
	else                       //臸よ皚籹よ猭 
	{
		arr[0][n/2]=1;     
		int k=2;              //砞﹚k=2 
		while(1){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(arr[i][j]==k-1){
						if(i==0&&j==0&&arr[n-1][n-1]==0)          //程オ程程程 
							arr[n-1][n-1]=k;
						else if(i==0&&j!=0&&arr[n-1][j-1]==0)     //程オ獶程程┕簿1 
							arr[n-1][j-1]=k;
						else if(i!=0&&j==0&&arr[i-1][n-1]==0)     //獶程オ程程┕オ簿1 
							arr[i-1][n-1]=k;
						else if(i!=0&&j!=0&&arr[i-1][j-1]==0)     //獶程オ獶程┕オ簿1┕簿1 
							arr[i-1][j-1]=k;
						else                                      //セ耚矪Τ戈┕ 
							arr[i+1][j]=k;                         
					}
				}
			}
			k=k+1;
			if(k>n*n)    //场Ч拨铬癹伴 
				break;
			
		}
		
		//1顶臸よ皚 
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
	int num=1;                 //﹍臸よ皚顶计 
	
	while(num<10){ 
		cout<<num<<"顶:"<<endl;
		output(num);
		num=num+2;              
	}
	

} 
