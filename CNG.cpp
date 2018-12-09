/**Like Uber, CNG owners want to develop a software which can communicate with customer and driver.
A customer needs to say his/her destination and nearer CNG driver will get message from the Uber company with name and mobile number of the customer.
The driver can make a direct call and if the customer confirms the ride then driver will come to spot and carry the passenger.
As a student of CSE, write OOP code for the project.
You need to pass message from one end to another end to make communications.**/
#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
class Person
{
protected:
    string name;
    int national_id;
public:
    Person(){}
    Person(string name,int national_id)
    {
        this->name=name;
        this->national_id=national_id;
    }
};
class Driver: public Person
{
    int mobile_number;
    string current_location;

public:
    double lattitude;
    double longitude;
   Driver (){};
    Driver(string name,int national_id,int mobile_number,string current_location,double lattitude,double longitude):Person(name,national_id)
    {
        this->mobile_number=mobile_number;
       this-> current_location=current_location;
       this-> lattitude=lattitude;
       this-> longitude=longitude;
    }
     void driverfile ()
    {
        ofstream myfile2;
         myfile2.open ("Driver Information.txt");
        myfile2<<"\nDriver Details "<<endl;
        myfile2<<"-------------------------------"<<endl;
        myfile2<<"Mobile number :"<<mobile_number<<endl;
        myfile2<<"current location   : "<<current_location<<endl;
        myfile2<<"Lattitude :"<<lattitude<<"  degree "<<endl;
        myfile2<<"Longitude :  "<<longitude<<" degree "<<endl;
         myfile2<<"Name          :"<<name<<endl;
        myfile2<<"National id   :"<<national_id<<endl;
        myfile2<<"--------------------------------";
        myfile2.close();
    }
    void booking ()
    {
        cout<<"a seat has been confirmed"<<endl;
    }
};
class Cng
{
    Driver driver1,driver2;
public:
    void driver_list(Driver &driver1,Driver &driver2)
    {
       this-> driver1=driver1;
       this-> driver2=driver2;
    }
    double calculate_distance( double customer_lattitude, double customer_longitude, double driver_lattitude, double driver_longitude )
{
    int nRadius = 6371;

    double nDLat = (driver_lattitude - customer_lattitude) * (M_PI/180);
    double nDLon = (driver_longitude-customer_longitude) * (M_PI/180);

        double nA = pow ( sin(nDLat/2), 2 ) + cos(customer_lattitude) * cos(driver_lattitude) * pow ( sin(nDLon/2), 2 );

    double nC = 2 * atan2( sqrt(nA), sqrt( 1 - nA ));
    double distance = nRadius * nC;

    return distance;
}

    void contact_with_driver(double customer_lattitude,double customer_longitude)
    {
        double distancefromdriver1,distancefromdriver2;

     distancefromdriver1=calculate_distance(customer_lattitude,customer_longitude,driver1.lattitude,driver1.longitude);
     distancefromdriver2=calculate_distance(customer_lattitude,customer_longitude,driver2.lattitude,driver2.longitude);

     if(distancefromdriver1<distancefromdriver2)
         driver1.booking();
     else
         driver2.booking();
    }
};
class Customer:public Person
{
    int mobile_number;
    string destination;
    double lattitude;
    double longitude;
public:
    Customer(){}
    Customer(string name,int national_id,int mobile_number,string destination,double lattitude,double longitude):Person(name,national_id)
    {
       this-> mobile_number=mobile_number;
        this->destination=destination;
       this-> lattitude=lattitude;
       this-> longitude=longitude;
    }
        friend class Cng;
    void customerfile ()
    {
        ofstream myfile1;
    myfile1.open ("Customer Information.txt");
    myfile1<<"\nCustomer Details "<<endl;
    myfile1<<"----------------------------"<<endl;
    myfile1<<"Mobile number :"<<mobile_number<<endl;
    myfile1<<"Lattitude :"<<lattitude<<"  degree "<<endl;
    myfile1<<"Longitude :  "<<longitude<<" degree "<<endl;
    myfile1<<"Destination   :  "<<destination<<endl;
    myfile1<<"Name          :"<<name<<endl;
    myfile1<<"National id   :"<<national_id<<endl;
    myfile1<<"----------------------------"<<endl;
    }
    void contact_with_cng(Cng &cng)
    {
        double lattitude,longitude;
       this-> lattitude=lattitude;
       this-> longitude=longitude;
        cout<<"\n\nFor customer "<<this->name<<", whose Destination is  "<<this->destination<<", ";

       cng .contact_with_driver(lattitude,longitude);
    }

};
int main()
{
    Customer customer("Mehedi",1,2345,"Sylhet",23,91);

    Driver driver1("Kadir",2,72567,"Comilla",21,93);
    Driver driver2("Rahim",3,8652,"Chittagong",22,91);

    driver1.driverfile();
    customer.customerfile();

    Cng cng;
    cng.driver_list(driver1,driver2);

    customer.contact_with_cng(cng);
}

