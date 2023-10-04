//B093040069林奕均
//2022.10.04
//西洋棋騎士(knight)走完棋盤的順序(將上一個習題改為recursive program)
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

Recursive( int value, int a[][100]  , int i , int j , int n )
{

	int k=0;
	while(1)
	{
		if( value == n*n )     //最後一個數回傳1 
			return 1;
		if( i-2>=0 && j+1<n && k<1 && a[i-2][j+1]==0  ){       //設定K1 	
			k=1;
			i=i-2;
			j=j+1;
			value++;
			a[i][j]=value;
	
			
		}else if( i-1>=0 && j+2<n && k<2 && a[i-1][j+2]==0 ){   //設定K2 
		
			k=2;
			i=i-1;
			j=j+2;
			value++;
			a[i][j]=value;
			
			
		} else if( i+1<n && j+2<n && k<3 && a[i+1][j+2]==0 ){   //設定K3 
			
			k=3;	
			i=i+1;
			j=j+2;
			value++;
			a[i][j]=value;
		
			
		}else if( i+2<n && j+1<n && k<4 && a[i+2][j+1]==0 ){   //設定K4 
			
			k=4;
			i=i+2;
			j=j+1;
			value++;
			a[i][j]=value;
			
			
		}else if( i+2<n && j-1>=0 && k<5 && a[i+2][j-1]==0 ){  //設定K5 
			
			k=5;
			i=i+2;
			j=j-1;
			value++;
			a[i][j]=value;
			
			
		}else if( i+1<n && j-2>=0 && k<6 && a[i+1][j-2]==0 ){   //設定K6 
			
			k=6;
			i=i+1;
			j=j-2;
			value++;
			a[i][j]=value;
			
			
		}else if( i-1>=0 && j-2>=0 && k<7 && a[i-1][j-2]==0 ){   //設定K7 
			
			k=7;
			i=i-1;
			j=j-2;
			value++;
			a[i][j]=value;
			
			
		}else if( i-2>=0 && j-1>=0 && k<8 && a[i-2][j-1]==0 ){   //設定K8 
			
			k=8;
			i=i-2;
			j=j-1;
			value++;
			a[i][j]=value;
			
			
		}else{
			return 0;
		}
//		cout<<i<<" "<<j<<" "<<value<<endl; 
		
		if(  Recursive( value , a ,  i , j , n ) == 1  ){    //遞迴 
			return 1;
		}else {                                              //假設8種路線都不行,回上一步  
			a[i][j]=0;										//設為0					
			value--;										//值-1  
			
			if( k == 1){									//8種路線狀況下,i,j退回上一步 
				i=i+2;
				j=j-1;
			}if( k ==2 ){
				i=i+1;
				j=j-2;
			}if( k ==3 ){
				i=i-1;
				j=j-2;
			}if( k ==4 ){
				i=i-2;
				j=j-1;
			}if( k ==5 ){
			 	i=i-2;
			 	j=j+1;
			}if( k==6 ){
				i=i-1;
				j=j+2;
			}if( k ==7 ){
				i=i+1;
				j=j+2;
			}if( k ==8 ){
				i=i+2;
				j=j+1;
			}
			
			
			
		}
	
	}
	
} 





int main()
{
	int a[100][100];
	int n;
	cin >> n;
	
	for( int i=0 ; i<n ; i++ )      //陣列初值設為0 
	{
		for( int j=0 ; j<n ; j++ )
		{
			a[i][j]=0;
		}
	}
	
	int i=0 , j=0   ;
	a[0][0]=1;
	int value = 1;
	
	if( Recursive( 1, a,  0, 0, n ) == 1 ){      //若遞迴函式回傳1,印出全部陣列 
		for( int i=0 ; i<n ; i++ ){
			for( int j=0 ;j<n ;j++ ){
				cout<<setw(2)<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}else                                       //反之回傳0則no solution 
		cout<<"no solution";
	
	
	
	
}
