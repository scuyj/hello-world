#include <iostream>
#include <string.h>
 
using namespace std;
 
class fraction{
	public:
		
		void getFra(char mf[10])
		{
			len=strlen(mf);
			for(int j=0;j<len;j++)
			{
				f[j]=mf[j];
			}
			
		}
		
		int Judge()//�ж������Լ��Ƿ��ܼ���
		{
			if(f[0]=='-')
			{
				judge=-1;
			}
			if(f[0]>='0' && f[0]<='9')
			{
				judge=1;
			}
			for(int i=0;i<len;i++)
			{
				if(f[i]<'0' || f[i]>'9')
				{
					if(f[i]!='-' && f[i]!='/')
					{
						judge=0;
					}
				}
			}
			return judge;
		}	
			
		int showUp()   //���� 
		{
			int up=0;
			 
			for(int i=0;f[i]!='/';i++)
			{
				if(f[i]>='0' && f[i]<='9')
				{
					up=up*10+f[i]-'0';
				}
			}
			
			if(Judge()==-1)
			return -up;
			if(Judge()==1)
			return up;
		}
		
		int showDown() //��ĸ 
		{
			int down=0;
			int i;
			for(i=0;f[i]!='/';i++);
			
			for(i;i<len;i++)
			{
				if(f[i]>='0' && f[i]<='9')
				{
					down=down*10+f[i]-'0';
				}
			}
			return down;
		} 
					
	private:
		char f[10];
		int len;
		int judge;
		int up,down;
};

int gcd(int a ,int b)//�����Լ�� 
{
	return (b == 0 ? a : gcd(b, a % b));
}

void showRes(int a,int b) //����ӷ�ĸ�����Լ�������л��� 
{
	int max=gcd(a,b);
	
	a /= max;
	b /= max;
	
	if(b==1)
	{
		cout << a<< endl;
	}
	else 
	cout << a<< "/" <<  b << endl;
}

int main()
{
	fraction fra[256];
	char num[10];
	int n;
	
	scanf("%d",&n);
	
	//sumMΪ��ĸ�˻� 
	int sumM=1;
	
	for(int i=0; i<n; i++)
	{
		scanf("%s",num);
		fra[i].getFra(num);
		
//		cout << fra[i].showUp() << endl << fra[i].showDown() << endl;
		if(fra[i].Judge()==0)
		{
			cout << "error" << endl;
			return 0;
		}
		
		sumM*=fra[i].showDown();
		
	}
	
	//max���Լ�� 
	int max=1;
	//���ĸ�����Լ�� 
	for(int i = 0; i < n; i++)
	{
		max=gcd(max,fra[i].showDown());
	}
	
	//min��С������ =�˻�/���Լ�� 
	int min,fz;
	min=sumM/max;
	
	//��δ����ķ��� 
	for(int i=0;i<n;i++)
	{
		fz += (fra[i].showUp()*(min/fra[i].showDown()));
	} 
	//��ĸ��Ϊ��С������ 
	int fm=min;
	
	showRes(fz,fm);
}
