/**CSE department wants to select Programming Coach for its students.
Any student of the department can be a coach.
He need to have high profile at least three ACM regional contest participation and number of problem solutions of ACM need to more 300.
Students need to apply in the department, if anyone’s performance is below the requirement he will discard automatically.
As a student of CSE, write OOP code for the project.
All the communications will be held by message.**/

#include<bits/stdc++.h>

using namespace std;

class Date
{
public:
    int day,month,year;
    Date() {};
    Date(int d,int m,int y)
    {
        day=d;
        month=m;
        year=y;
    }

};

class Person
{
public:
    string name;
    Date d1;
    Person() {};
    Person(string n)
    {
        name=n;
    }
    Person(string n,Date *d)
    {
        name=n;
        d1=*d;
    }
};

    class Department
    {
    public:
        string dept_name;
        Department() {};
        Department(string n)
        {
            dept_name=n;
        }
    };

    class Student : public Person
    {
    public:
        int id,ACM,problem_solve;
        Department d;
        Student() {};
        Student(string n,Date *d2,Department *dp,int dd,int acm,int solve) : Person(n,d2)
        {
            id=dd;
            d=*dp;
            ACM=acm;
            problem_solve=solve;
        }
        View_Student_Info()
        {
            cout<<"Student name: "<<name<<endl;
            cout<<"Department: "<<d.dept_name<<endl;
            cout<<"Students Birthday: "<<d1.day<<"-"<<d1.month<<"-"<<d1.year<<endl;
            cout<<"NUMBER OF ACM PARTICIPATION: "<<ACM<<endl;
            cout<<"NUMBER OF SOLVED PROBLEMS: "<<problem_solve<<endl;
        }
    };

    class Faculty : public Person
    {
    public:
        Student *s;
        string designation;
        Department dp;
        Faculty() {};
        Faculty(string d,string n,Department *dp1):Person(d)
        {
            designation=n;
            dp=*dp1;
        }
        View_Faculty()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Department: "<<dp.dept_name<<endl;
            cout<<"Designation: "<<designation<<endl;
        }
        int select_coach(Student *s1)
        {
            s=s1;
            if(s->ACM>=3&&s->problem_solve>300)
                return 1;
            else
                return 0;
        }
    };

    int main()
    {
        Department *dp[5]=
        {
            new Department("CSE"),
            new Department("CSE"),
            new Department("CSE"),
            new Department("CSE"),
            new Department("CSE"),
        };

        Date *dt[4]=
        {
            new Date(25,9,1997),
            new Date(16,04,1996),
            new Date(15,11,1993),
            new Date(14,06,1983)
        };
        Student *s[3]=
        {
            new Student("Asraful",dt[0],dp[0],1001,4,350),
            new Student("Mehedi",dt[1],dp[1],1002,1,400),
            new Student("Saiful",dt[2],dp[2],1003,2,290)
        };
        Faculty *f[2]=
        {
            new Faculty("Hassan","Professor",dp[3]),
            new Faculty("Razib","Lecturer",dp[4])
        };
        cout<<"THE DETAILS OF FACULTY MEMBER: "<<endl<<endl;
        for(int i=0; i<2; i++){
            f[i]->View_Faculty();
            cout<<endl;
        }
        cout<<endl<<endl;
        cout<<"THE DETAILS OF STUDENTS: "<<endl<<endl;
        for(int i=0; i<3; i++){
            s[i]->View_Student_Info();
            cout<<endl;
        }
        int x;
        cout<<endl<<endl;
        for(int i=0;i<3;i++)
        {
           x=f[i]->select_coach(s[i]);
           if(x==1)
           {
               cout<<"THE STUDENT CAN BE SELECTED AS COACH.."<<endl;
               cout<<"THE DETAILS OF THE STUDENT IS: "<<endl;
               s[i]->View_Student_Info();
               cout<<endl<<endl;
           }
           else
           {
               cout<<"THE STUDENT IS NOT SELECTED AS COACH.."<<endl;
               cout<<"THE DETAILS OF THE STUDENT IS: "<<endl;
               s[i]->View_Student_Info();
               cout<<endl<<endl;
           }
        }
        return 0;
    }

