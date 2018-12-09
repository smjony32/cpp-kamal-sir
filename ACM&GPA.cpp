/**A C++ code in object oriented approach for the students.
Student can be rewarded from the department if he gets good GPA in a semester and solved atleast 100 ACM problems in the last year.
Department will publish the top 5 students name in their honor board.
As a student of CSE, write OOP code for the project.**/
#include<bits/stdc++.h>
using namespace std;

float arr[10];

class Person
{
public:
    string Name;
    int Age;

    Person(string name, int age);
};

Person::Person(string name, int age)
{
    Name=name;
    Age=age;
}

class Student:public Person
{
private:
    float GPA;
    int ACM_Solve;

public:
	Student(string n, int a, float g, int s) : Person(n,a), GPA(g), ACM_Solve(s) {}
	void showStudent();

	int checkGPA(float gpa)
    {
        if(GPA==gpa && ACM_Solve>=100)
            return 1;

        else return 0;
    }

    float accessGPA()
    {
        return GPA;
    }
};

void Student::showStudent()
{
    cout << setw(10) << Name << setw(13) <<  GPA << setw(13) << ACM_Solve << endl << endl;
}

int main()
{
    int i,j;
    Student *performance[10]=
    {
        new Student("Mehedi",20,3.22,120),
        new Student("Nazmul",22,3.91,110),
        new Student("Rakib",21,3.56,130),
        new Student("Sahariar",21,3.26,210),
        new Student("Tanvir",23,3.38,310),
        new Student("Farhan",21,3.48,200),
        new Student("Abir",23,3.73,90),
        new Student("Tipu",22,3.57,95)
    };

    float temp;
    int counter=0;
    float maximum;

    for(i=7;i>=0;i--)
    {
        arr[i]=performance[i]->accessGPA();
        for(j=0;j<7-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j] = temp ;
            }
        }
    }

    cout << "TOP 5 students on the Honor Board are:" << endl << endl;
    cout << setw(10) << "Student Name"  << setw(10) << "GPA" << setw(17) << "ACM Solve" << endl  ;
    cout << setw(10) << "____________"  << setw(10) << "___" << setw(17) << "_________" << endl << endl ;

    for(i=7;i>=0;i--)
    {
        maximum=arr[i];

        for(j=0;j<7;j++)
        {
            if(performance[j]->checkGPA(maximum)==1)
            {
                counter++;
                performance[j]->showStudent();
            }

            if(counter==5) break;
        }
    }
    return 0;
}

