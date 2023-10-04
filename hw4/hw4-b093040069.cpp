//B093040069�L����
//2022.10.04
//��v���M�h(knight)�����ѽL������(�N�W�@�Ӳ��D�אּrecursive program)
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

Recursive( int value, int a[][100]  , int i , int j , int n )
{

	int k=0;
	while(1)
	{
		if( value == n*n )     //�̫�@�ӼƦ^��1 
			return 1;
		if( i-2>=0 && j+1<n && k<1 && a[i-2][j+1]==0  ){       //�]�wK1 	
			k=1;
			i=i-2;
			j=j+1;
			value++;
			a[i][j]=value;
	
			
		}else if( i-1>=0 && j+2<n && k<2 && a[i-1][j+2]==0 ){   //�]�wK2 
		
			k=2;
			i=i-1;
			j=j+2;
			value++;
			a[i][j]=value;
			
			
		} else if( i+1<n && j+2<n && k<3 && a[i+1][j+2]==0 ){   //�]�wK3 
			
			k=3;	
			i=i+1;
			j=j+2;
			value++;
			a[i][j]=value;
		
			
		}else if( i+2<n && j+1<n && k<4 && a[i+2][j+1]==0 ){   //�]�wK4 
			
			k=4;
			i=i+2;
			j=j+1;
			value++;
			a[i][j]=value;
			
			
		}else if( i+2<n && j-1>=0 && k<5 && a[i+2][j-1]==0 ){  //�]�wK5 
			
			k=5;
			i=i+2;
			j=j-1;
			value++;
			a[i][j]=value;
			
			
		}else if( i+1<n && j-2>=0 && k<6 && a[i+1][j-2]==0 ){   //�]�wK6 
			
			k=6;
			i=i+1;
			j=j-2;
			value++;
			a[i][j]=value;
			
			
		}else if( i-1>=0 && j-2>=0 && k<7 && a[i-1][j-2]==0 ){   //�]�wK7 
			
			k=7;
			i=i-1;
			j=j-2;
			value++;
			a[i][j]=value;
			
			
		}else if( i-2>=0 && j-1>=0 && k<8 && a[i-2][j-1]==0 ){   //�]�wK8 
			
			k=8;
			i=i-2;
			j=j-1;
			value++;
			a[i][j]=value;
			
			
		}else{
			return 0;
		}
//		cout<<i<<" "<<j<<" "<<value<<endl; 
		
		if(  Recursive( value , a ,  i , j , n ) == 1  ){    //���j 
			return 1;
		}else {                                              //���]8�ظ��u������,�^�W�@�B  
			a[i][j]=0;										//�]��0					
			value--;										//��-1  
			
			if( k == 1){									//8�ظ��u���p�U,i,j�h�^�W�@�B 
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
	
	for( int i=0 ; i<n ; i++ )      //�}�C��ȳ]��0 
	{
		for( int j=0 ; j<n ; j++ )
		{
			a[i][j]=0;
		}
	}
	
	int i=0 , j=0   ;
	a[0][0]=1;
	int value = 1;
	
	if( Recursive( 1, a,  0, 0, n ) == 1 ){      //�Y���j�禡�^��1,�L�X�����}�C 
		for( int i=0 ; i<n ; i++ ){
			for( int j=0 ;j<n ;j++ ){
				cout<<setw(2)<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}else                                       //�Ϥ��^��0�hno solution 
		cout<<"no solution";
	
	
	
	
}
