# assignment4
Assignment - 4 oop
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

class A{
    int a;
    static int b;
    protected:
    int c;
    public:
    A(){
		cout<<"constructor called"<<endl;
	};
    A(int x,int y){
      a=x;
      c=y;
    }
	~A(){
		cout<<"destructor called"<<endl;
	}
    inline int square(int a){
        return a*a;;
    }
    inline int cube(int a){
        return a*a*a;
    }
    int sum(int a,int c){
        cout<<"sum of a and c is "<<a+c<<endl;
    }
    int sum(int a,int b,int c){
        cout<<"sum of a,b,c is "<<a+b+c<<endl;
    }
    
    void display(){
        cout<<"displaying class A"<<endl;
        cout<<"square of 4 is"<<square(4)<<endl;
        cout<<"cube of 4 is"<<cube(4)<<endl;
    }
    static void display1(){
        cout<<"displaying class B. value of b is "<<b<<endl;
    }
    friend void frnd_display(A);
    friend class frnd_B;
    
    
};
int A :: b=5;
void frnd_display(A obj){
    obj.display();
        cout<<"friend function called"<<endl;
}
class frnd_B{
    public:
    void display(A&obj){
        obj.display();
        cout<<"friend class called"<<endl;
    }
};

class B : public A
{
protected:
    int b;

public:
    void dispb()
    {
        b = 20;
        cout << "B Entered = " << b << endl;
    }
};
class C : public A
{
protected:
    int c;

public:
    void dispc()
    {
        c = 30;
        cout << "C Entered = " << c << endl;
    }
};
class D : public B
{
protected:
    int d;

public:
    void dispd()
    {
        d = 40;
        cout << "D Entered = " << d << endl;
    }
};


class Count {
   private:
    int value;

   public:
    Count() : value(5) {}
    Count operator ++ () {
        Count temp;
        temp.value = ++value;
        return temp;
    }

    Count operator ++ (int) {
        Count temp;
        temp.value = value++;
		return temp;
    }

    void display() {
        cout << "Count: " << value << endl;
    }
};
template <typename T> T myMax(T x, T y)
{
    return (x > y) ? x : y;
}


int main(){
    class A obj1(5,4),obj2;
    obj1.display();
    obj1.display1();
    frnd_display(obj2);
    frnd_B obj3;
    obj3.display(obj2);
    obj1.sum(4,6);
    obj1.sum(4,6,8);

    D d;
    d.dispd();
    C c;
    c.dispc();

	try {
        A t1;
        throw 10;
    }
    catch (int i) {
        cout << "Caught " << i << endl;
    }

	cout << myMax<int>(3, 7) << endl;
    cout << myMax<double>(3.0, 7.0)<< endl;
    cout << myMax<char>('g', 'e')<< endl;
    
    
	 Count count1, result;
    result = ++count1;
    result.display();
    result = count1++;
    result.display();

}
