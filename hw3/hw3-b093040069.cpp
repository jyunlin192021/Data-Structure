//B093040069林奕均
//2022.10.02
//西洋棋騎士(knight)走完棋盤的順序
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

class Node{
	private:
		int a[3];      //i軸之值、j軸之值、位置已走過的編號 
		Node *next;
	public:
		Node();
		friend class stack;
};

Node::Node()
{
	next=NULL;
}

class stack{
	private:
		Node *Top;
		int floor;   //stack有幾層 
	public:
		stack();
		int IsEmpty();   //判斷stack是否為空 
		int geta0();     //得到i 
		int geta1();     //得到j 
		int geta2();     //得到num 
		int getfloor();  //得到幾層 
		void push( int i , int j , int num );  //push stack 
		void pop();      //pop stack 
		
};



stack::stack()     //constructor
{
	Top=NULL;
	floor=0;
}

int stack::geta0()    //回傳i 
{
	return Top->a[0]; 
}

int stack::geta1()    //回傳j 
{
	return Top->a[1];
}

int stack::geta2()    //回傳num 
{
	return Top->a[2];
}

int stack::getfloor()   //回傳floor 
{ 
	return floor;
}

int stack::IsEmpty()    //判斷是否為空 
{
	if( Top==NULL )
		return 1;       //空回傳1 反之回傳0 
	else return 0;
}

void stack::push( int i , int j , int num )   //push函式 
{
	Node *newa;      //建立一個新的node  
	newa = new Node;  //malloc(sizeof(Node));
	newa->next=Top;   
	newa->a[0]=i;
	newa->a[1]=j;
	newa->a[2]=num;
	Top=newa;        //新node變Top 
	floor++;         //加一層 
}

void stack::pop()   //pop函式 
{
	Top=Top->next;   
	floor--;        //減一層 
}



int main()
{
	stack A;
	int array[100][100];
	int n;          
	cin >> n ;       //n*n陣列 
	
	for( int i=0 ; i<100 ; i++ )        //陣列所有元素均設定為0 
	{
		for( int j=0 ; j<100 ; j++ )
		{
			array[i][j] = 0 ;
		}
	}
	
	int i=0 , j=0 , k=0 , num=0;
	while(1)
	{
		if( i-2>=0 && j+1<n && num<1 && array[i-2][j+1]==0  ){       //設定K1 
			
			num=1;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i-2;
			j=j+1;
			num=0;
			
		}else if( i-1>=0 && j+2<n && num<2 && array[i-1][j+2]==0 ){   //設定K2 
			
			num=2;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i-1;
			j=j+2;
			num=0;
			
		} else if( i+1<n && j+2<n && num<3 && array[i+1][j+2]==0 ){   //設定K3 
			
			num=3;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i+1;
			j=j+2;
			num=0;
			
		}else if( i+2<n && j+1<n && num<4 && array[i+2][j+1]==0 ){   //設定K4 
			
			num=4;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i+2;
			j=j+1;
			num=0;
			
		}else if( i+2<n && j-1>=0 && num<5 && array[i+2][j-1]==0 ){  //設定K5 
			
			num=5;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i+2;
			j=j-1;
			num=0;
			
		}else if( i+1<n && j-2>=0 && num<6 && array[i+1][j-2]==0 ){   //設定K6 
			
			num=6;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i+1;
			j=j-2;
			num=0;
			
		}else if( i-1>=0 && j-2>=0 && num<7 && array[i-1][j-2]==0 ){   //設定K7 
			
			num=7;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i-1;
			j=j-2;
			num=0;
			
		}else if( i-2>=0 && j-1>=0 && num<8 && array[i-2][j-1]==0 ){   //設定K8 
			
			num=8;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i-2;
			j=j-1;
			num=0;
			
		}else if( n == 2 ){
			cout<<"no solution";   //n=2 ,no solution
			break;
		}else if( n == 1){
			array[0][0]=1;        //n=1 ,只有1 
			cout<<array[0][0];
			break;
		}else{                   //假設8種路線都不行,回上一步  
			array[i][j]=0;      //位置重設0 
			i = A.geta0();
			j = A.geta1();
			num = A.geta2();
			A.pop();	       //stack取出 
			
		}
		
		
		if( A.IsEmpty() == 1 ){    //若為空 no solution 
			cout<<"no solution";
			break;
		}
		
		if( A.getfloor() == n*n-1 ){      //全部跑完印出結果  
			array[i][j]=n*n;
			for(int i=0 ; i<n ;i++){
				for(int j=0 ; j<n ; j++ ){
					cout<<setw(2)<<array[i][j]<<" ";
				}
				cout<<endl;
			}
			
			break;
		} 
		
	}
} 
