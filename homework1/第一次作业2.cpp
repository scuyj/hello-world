#include <iostream>
#include <stdio.h>
using namespace std;

int x;

class Int{
	private:
		int N;
		int Num[256],res[256];
		int count;
		int judge[256];
		
	public:
		void setN(int n)
		{
			N=n;
			
			for(int i=0;i<N;i++)
			{
				judge[i]=1;
			}			
		}
		
		void setNum(int num[])
		{
			for(int i=0;i<N;i++)
			{
				Num[i]=num[i];
			}
		}
		
		void Count()
		{
		    x=0;
			
			for(int i=0;i<N-1;i++)
			{
				count=0;
				
				for(int j=i+1;j<N;j++)
				{
					if(Num[i]==Num[j] && judge[j]==1)
					{
						count++;
						judge[j]=0;
					}
				}
				
				if(count==1)
				{
					res[x]=Num[i];
					x++;
				}
			}
		}
		
		void showRes()
		{
			if(x==0)
			{
				printf("none\n");
				return;
			}
			for(int i=0;i<x;i++)
			{
				printf("%d ",res[i]);
			}
			printf("\n");
		}
}; 

int main()
{
	Int A;
	
	int n;
	int num[256];
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	
	A.setN(n);
	A.setNum(num);
	A.Count();
	A.showRes();
}
