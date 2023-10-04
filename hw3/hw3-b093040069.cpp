//B093040069�L����
//2022.10.02
//��v���M�h(knight)�����ѽL������
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

class Node{
	private:
		int a[3];      //i�b���ȡBj�b���ȡB��m�w���L���s�� 
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
		int floor;   //stack���X�h 
	public:
		stack();
		int IsEmpty();   //�P�_stack�O�_���� 
		int geta0();     //�o��i 
		int geta1();     //�o��j 
		int geta2();     //�o��num 
		int getfloor();  //�o��X�h 
		void push( int i , int j , int num );  //push stack 
		void pop();      //pop stack 
		
};



stack::stack()     //constructor
{
	Top=NULL;
	floor=0;
}

int stack::geta0()    //�^��i 
{
	return Top->a[0]; 
}

int stack::geta1()    //�^��j 
{
	return Top->a[1];
}

int stack::geta2()    //�^��num 
{
	return Top->a[2];
}

int stack::getfloor()   //�^��floor 
{ 
	return floor;
}

int stack::IsEmpty()    //�P�_�O�_���� 
{
	if( Top==NULL )
		return 1;       //�Ŧ^��1 �Ϥ��^��0 
	else return 0;
}

void stack::push( int i , int j , int num )   //push�禡 
{
	Node *newa;      //�إߤ@�ӷs��node  
	newa = new Node;  //malloc(sizeof(Node));
	newa->next=Top;   
	newa->a[0]=i;
	newa->a[1]=j;
	newa->a[2]=num;
	Top=newa;        //�snode��Top 
	floor++;         //�[�@�h 
}

void stack::pop()   //pop�禡 
{
	Top=Top->next;   
	floor--;        //��@�h 
}



int main()
{
	stack A;
	int array[100][100];
	int n;          
	cin >> n ;       //n*n�}�C 
	
	for( int i=0 ; i<100 ; i++ )        //�}�C�Ҧ��������]�w��0 
	{
		for( int j=0 ; j<100 ; j++ )
		{
			array[i][j] = 0 ;
		}
	}
	
	int i=0 , j=0 , k=0 , num=0;
	while(1)
	{
		if( i-2>=0 && j+1<n && num<1 && array[i-2][j+1]==0  ){       //�]�wK1 
			
			num=1;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i-2;
			j=j+1;
			num=0;
			
		}else if( i-1>=0 && j+2<n && num<2 && array[i-1][j+2]==0 ){   //�]�wK2 
			
			num=2;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i-1;
			j=j+2;
			num=0;
			
		} else if( i+1<n && j+2<n && num<3 && array[i+1][j+2]==0 ){   //�]�wK3 
			
			num=3;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i+1;
			j=j+2;
			num=0;
			
		}else if( i+2<n && j+1<n && num<4 && array[i+2][j+1]==0 ){   //�]�wK4 
			
			num=4;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i+2;
			j=j+1;
			num=0;
			
		}else if( i+2<n && j-1>=0 && num<5 && array[i+2][j-1]==0 ){  //�]�wK5 
			
			num=5;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i+2;
			j=j-1;
			num=0;
			
		}else if( i+1<n && j-2>=0 && num<6 && array[i+1][j-2]==0 ){   //�]�wK6 
			
			num=6;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i+1;
			j=j-2;
			num=0;
			
		}else if( i-1>=0 && j-2>=0 && num<7 && array[i-1][j-2]==0 ){   //�]�wK7 
			
			num=7;
			A.push(i,j,num);
			array[i][j]=A.getfloor();
			i=i-1;
			j=j-2;
			num=0;
			
		}else if( i-2>=0 && j-1>=0 && num<8 && array[i-2][j-1]==0 ){   //�]�wK8 
			
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
			array[0][0]=1;        //n=1 ,�u��1 
			cout<<array[0][0];
			break;
		}else{                   //���]8�ظ��u������,�^�W�@�B  
			array[i][j]=0;      //��m���]0 
			i = A.geta0();
			j = A.geta1();
			num = A.geta2();
			A.pop();	       //stack���X 
			
		}
		
		
		if( A.IsEmpty() == 1 ){    //�Y���� no solution 
			cout<<"no solution";
			break;
		}
		
		if( A.getfloor() == n*n-1 ){      //�����]���L�X���G  
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
