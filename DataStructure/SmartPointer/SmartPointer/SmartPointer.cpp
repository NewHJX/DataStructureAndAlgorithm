#include<iostream>
class Point
{
public:
	Point(int xVal = 0, int yVal = 0) :x(xVal), y(yVal) { }
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int xVal) { x = xVal; }
	void setY(int yVal) { y = yVal; }

private:
	int x, y;

};

template<typename T>
class SmartPt;

template<class Type>
class U_Ptr {
private:
	friend class SmartPt<Type>;
	U_Ptr(Type *ptr) :p(ptr), count(1) {}
	~U_Ptr() { delete p; }
	int count;
	Type *p;
};

template<typename T>
class SmartPt {
public:
	SmartPt(T *ptr):rp(new U_Ptr<T>(ptr)){}
	SmartPt(const SmartPt &sp) :rp(sp.rp) { ++rp->count; }
	SmartPt& operator=(const SmartPt& rhs) {
		++rhs.rp->count;
			if (--rp->count == 0)
				delete rp;
		rp = rhs.rp;
		return *this;
	}
	~SmartPt() {
		if (--rp->count == 0)
			delete rp;
		else
			std::cout << "����" << rp->count << "��ָ��ָ���������" << std::endl;
	}
private:
	U_Ptr<T> *rp;
};

int main()
{
	//����һ������������ָ��
	Point *pa = new Point(10, 20);

	//������������ָ������󣬶���ָ����������pa
	//ʹ�û����ſ�������ָ��ָ��������ڣ��۲�����ı仯

	{
		SmartPt<Point> sptr1(pa);//��ʱ����count=1
		{
			SmartPt<Point> sptr2(sptr1); //���ø��ƹ��캯������ʱ����Ϊcount=2
			{
				SmartPt<Point> sptr3 = sptr1; //���ø�ֵ����������ʱ����Ϊconut=3
			}
			//��ʱcount=2
		}
		//��ʱcount=1��
	}
	//��ʱcount=0��pa����delete��

	std::cout << pa->getX() << std::endl;
	getchar();
	return 0;
}