#include <iostream>
using namespace std;

class Int{
	private:
		int m_num;
		int m_ge;
		int m_shi;
		int m_bai;
	
	public:
		void setNum(int num)
		{
			m_num=num;
		}
		
		int Sum()
		{
			m_ge=m_num%10;
			m_shi=m_num/10%10;
			m_bai=m_num/100;
			
			return m_ge+m_shi+m_bai;
		}
}; 

int main()
{
	Int num;
	int n1;
	
	cin >> n1;
	
	num.setNum(n1);

	cout << num.Sum() << endl;
}
