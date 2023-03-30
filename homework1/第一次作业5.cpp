#include <iostream> 

using namespace std;

int n;

void sort(int a[])
{
	int temp;
	
	for(int i=0;i<25;i++)
	{
		for(int j=i+1;j<26;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
class A{
	public:
		
		void getStr(char inchar[],int num)
		{
			for(int i=0;i<n;i++)
			{
				str[i]=inchar[i];
			}
			
			for(int i=0;i<n;i++)
			{
				judge[i]=1;
				cnt[i]=0;
			}
		}
		
		void cal()
		{
			int x=0;
			
			for(int i=0;i<n;i++)
			{
				count=1;
				
				if(judge[i]==1)
				{
					for(int j=i+1;j<n;j++)
					{
						if(judge[i]==1)
						{						
							if(str[i]==str[j] && judge[j]==1)
							{
								count++;
								judge[j]=0;
							}						
						}					
					}
					cnt[str[i]-'a']=count;
				}
				
			}
			
			sort(cnt);
		}
		
		int res()
		{
						
			for(int i=0;i<26;i++)
			{
				r+=cnt[i]*(i+1);
				//printf("%d\n",cnt[i]);
			}
			
			return r;
		}
	private:
		char str[10000];
		int cnt[26],count,r;
		int judge[10000];
}; 

int main()
{
	cin >> n;
	
	char str0[10000];
	
	scanf("%s",str0);
	
	A str1;

	str1.getStr(str0,n);
	str1.cal();
	//str1.res();
	cout << str1.res() << endl;
}
