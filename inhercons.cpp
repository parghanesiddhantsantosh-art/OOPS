#include<iostream>
using namespace std;


class student
{
protected:
    int rollno;
public:
    student()
    {
        rollno=0;
        cout<<"the default constructor called"<<endl;

    }
    student(int r)
    {
        rollno=r;
        cout<<"the paramitized constructor called"<<endl;

    }


    student(const student& s)
    {

        rollno=s.rollno;
        cout<<"the copy constructor is called"<<endl;
    }
    ~student()
    {
        cout<<"the detsructructor is called"<<endl;

    }

};

class sports
{
protected:
    int sportsmarks;
public:
    sports()
    {
        sportsmarks=0;
        cout<<"the spots default constructor is called"<<endl;

    }
    sports(int m)
    {
        sportsmarks=m;
        cout<<"the sports paramaitized constructor called"<<endl;
    }
    sports(const sports& s)
    {
        sportsmarks=s.sportsmarks;
        cout<<"the sports copy constructor is called"<<endl;

    }
};

class result: public student,public sports
{
private:
    int totalmarks;
public:
    result():student(),sports(){
        totalmarks=0;
        cout<<"the result constructor called"<<endl;



    }
    result(int r,int s,int t) : student(r),sports(s)
    {
        totalmarks=t;
        cout<<"the result paramatized constructor is called"<<endl;


    }

    result(const result& obj):student(obj),sports(obj)
    {
        totalmarks=obj.totalmarks;
        cout<<"the result copy constructor is called"<<endl;

    }
    void display()
    {
        cout<<"\nroll no"<<rollno;
        cout<<"\nsports marks"<<sportsmarks;
        cout<<"\nresult marks"<<totalmarks;


    }
    ~result()
    {
        cout<<"the result destructor is called"<<endl;

    }
};

int main()
{
    cout<<"the default constructor is called"<<endl;
    result r1;
    r1.display();

    cout<<"the paramitized constructor is called"<<endl;
    result r2(102,34,560);
    r2.display();

    cout<<"the copy constructor is called"<<endl;
    result r3(r1);
    r3.display();
    return 0;
}
