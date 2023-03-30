#include <iostream>
#include <string.h>

using namespace std;
 
class Email{
	
	private:
	
		char m_str[64];
		
	public:
		
		void getEmail()
		{
//			char str[64];
			scanf("%s",m_str);
			
//			int len=strlen(str);
//			for(int i=0;i<len;i++)
//			{
//				m_str[i]==str[i];
//			}
		}
		
		int judgeEmail()
		{
			int len=strlen(m_str);
			
			int cnt1=0,cnt2=0;
			
			if(m_str[0]=='@' || m_str[len-1]=='@' || m_str[len-1]=='.')
			{
				return -1;
			}
			
			for(int i = 0; i < len; i++)
			{
				if(m_str[i] == '@')
				{
					cnt1++;
				}
				if(m_str[i] == '.')
				{
					cnt2++;
				}
				if(m_str[i] == '@' && m_str[i+1]=='.')
				{
					return -1;
				}
				
				if(m_str[i] != '@'&& m_str[i] != '.')
				{
					if(m_str[i]==96)
					{
						return -1;
					}
					if(m_str[i] > 90 && m_str[i] < 95)
					{
						return -1;
					}
					if(m_str[i] > 122)
					{
						return -1;
					}
					if(m_str[i] > 57 && m_str[i] < 65)
					{
						return -1;
					}
					if(m_str[i] > 45 && m_str[i] < 48)
					{
						return -1;
					}
					if(m_str[i] < 45)
					{
						return -1;
					}
				}
				
			}
			
			if(cnt1 != 1 || cnt2 != 1)
				{
					cnt1=0;cnt2=0;
					return -1;
				}
							
			return 1;
		}
		
		void showRes(int n)
		{
			if(n==1)
			{
				cout << "yes" << endl;
			}
			if(n==-1)
			{
				cout << "no" << endl;
			}
			
		}
};

int main()
{
	Email e;
	
	e.getEmail();
	e.showRes(e.judgeEmail());
	
}
