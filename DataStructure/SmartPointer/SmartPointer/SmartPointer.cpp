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
			std::cout << "还有" << rp->count << "个指针指向基础对象" << std::endl;
	}
private:
	U_Ptr<T> *rp;
};

int main()
{
	//定义一个基础对象类指针
	Point *pa = new Point(10, 20);

	//定义三个智能指针类对象，对象都指向基础类对象pa
	//使用花括号控制三个指针指针的生命期，观察计数的变化

	{
		SmartPt<Point> sptr1(pa);//此时计数count=1
		{
			SmartPt<Point> sptr2(sptr1); //调用复制构造函数，此时计数为count=2
			{
				SmartPt<Point> sptr3 = sptr1; //调用赋值操作符，此时计数为conut=3
			}
			//此时count=2
		}
		//此时count=1；
	}
	//此时count=0；pa对象被delete掉

	std::cout << pa->getX() << std::endl;
	getchar();
	return 0;
}