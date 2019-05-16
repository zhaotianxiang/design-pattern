#include<iostream>

// 多态性的完美展示， 在运行的时候才知道调用的具体信息
// fillResume() 定义了操作的骨架, 具体会因为执行的子类不同而不同

using namespace std;

class Resume
{
	protected:
		virtual void setPersonalInfo(){}
		virtual void setEduaction(){}
		virtual void setWorkExp(){}
	public:
		void fillResume()
		{
			setPersonalInfo();
			setEduaction();
			setWorkExp();
		}
};

class ResumeA: public Resume
{
	protected:
		void setPersonalInfo() { cout<<"A's PersonalInfo"<<endl; }
		void setEducation() { cout<<"A's Education"<<endl; }
		void setWorkExp() { cout<<"A's Work Experience"<<endl; }
};

class ResumeB: public Resume
{
	protected:
		void setPersonalInfo() { cout<<"B's PersonalInfo"<<endl; }
		void setEducation() { cout<<"B's Education"<<endl; }
		void setWorkExp() { cout<<"B's Work Experience"<<endl; }
};


int main()
{
	Resume *r1;
	r1 = new ResumeA();
	r1->fillResume();
	delete r1;
	r1 = new ResumeB();
	r1->fillResume();
	delete r1;
	r1 = NULL;
	return 0;
}

