#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<conio.h> 

using namespace std;

ofstream out;
ifstream in;

int Appid=0;
int Lid=0;

class Application{
public:
    string fname,lname;
    string address,city,state;
    string phone;

    void form(){
        cout<<"-----------Loan Application Form-----------"<<endl;
        cout<<"Enter Your First Name : "<<endl;
        cin>>fname;
        cout<<"Enter Your Last Name : "<<endl;
        cin>>lname;
        cout<<"Enter Your City : "<<endl;
        cin>>city;
        cout<<"Enter Your State : "<<endl;
        cin>>state;
        cout<<"Enter Your Residential Address : "<<endl;
        cin.ignore();
        getline(cin, address);
        cout<<"Enter Your Contact : "<<endl;
        cin>>phone;
        if(phone.length()==10){
            
            Appid++;
            cout<<"Your Loan Application Id is "<<Appid<<endl;
        }
        else{
            cout<<"Invalid Number !"<<endl;
            cout<<"Enter correct Number : "<<endl;
            cin>>phone ;
        }

    }

   void writeToFile() {
        ofstream out("application.txt", ios::app);
        if (out.is_open()) {
            out << "###############Application Form###############" << endl;
            out << "First NAME: " << fname << endl;
            out << "Last NAME: " << lname << endl;
            out << "ADDRESS: " << address << endl;
            out << "CITY: " << city << endl;
            out << "STATE: " << state << endl;
            out << "Phone: " << phone << endl;
            out << "-------------------------------------------" << endl;

            cout << "Application form added successfully." << endl;
            out.close();
        }
    }

};

class Loan{
public:
    float monthly_int;
    int ch3;
    int l;
    long long int loan_amt=0;
    long long int month_sal=0;
    string type;
    long long int emi;
    void calc();
    void personal();
    void home();
    void student();
    void business();
    
    void display1(){
        cout<<"----------------TYPE OF LOAN----------------"<<endl;
        cout<<"1.Personal Loan "<<endl;
        cout<<"2.Home Loan "<<endl;
        cout<<"3.Student Loan "<<endl;
        cout<<"4.Business Loan "<<endl;
        cout<<"Choose Loan : ";
        cin>>ch3;
        switch(ch3){
            case 1:
                personal();
                break;

            case 2:
                home();
                break;

            case 3:
                student();
                break;

            case 4:
                business();
                break;

            default:
                cout<<"Invalid Choice !"<<endl;
        }
       


    }

};
void Loan::calc() {
    cout << "Enter Your Loan Type : " << endl;
    cin.ignore();
    getline(cin,type);
    
    if (type == "Personal loan" || type == "personal loan") {
        monthly_int = 8.45/(12*100);
        emi = loan_amt * monthly_int * pow(1+monthly_int,10)/(pow(1+monthly_int,10)-1);
        cout << "Loan Amount: " << loan_amt << endl;
        cout << "Monthly EMI : " << emi << endl;  
    } else if (type == "Home loan" || type == "home loan") {
        int m_int = 8.35/(12*100);
        emi = loan_amt * m_int * pow(1+m_int,15)/(pow(1+m_int,15)-1);
        cout << "Loan Amount: " << loan_amt << endl;
        cout << "Monthly EMI : " << emi << endl;
    } else if (type == "Student loan" || type == "student loan") {
        int m_int1 = 10.75/(12*100);
        emi = loan_amt * m_int1 * pow(1+m_int1,15)/(pow(1+m_int1,15)-1);
        cout << "Loan Amount: " << loan_amt << endl;
        cout << "Monthly EMI : " << emi << endl;
    } else if (type == "Business loan" || type == "business loan") {
        int m_int2 = 22.50/(12*100);
        emi = loan_amt * m_int2 * pow(m_int2,4)/(pow(1+m_int2,4)-1);
        cout << "Loan Amount: " << loan_amt << endl;
        cout << "Monthly EMI : " << emi << endl;
    }
}

void Loan::personal(){
    cout<<"********Personal Loan*********"<<endl;
    cout<<"Interest Rate on Personal Loan is 8.45% per month"<<endl;
    cout<<"You can Take Loan upto 50 Lac"<<endl;
    cout<<"Tenure For Loan is 10 years"<<endl;
    do{
        cout<<"Enter Your Loan Amount : ";
        cin>>loan_amt;
    }while(loan_amt<0);
    cout<<"Loan is Successfully Granted."<<endl;
    Lid++;
    cout<<"Your loan id is "<<Lid<<endl;
}

void Loan::home(){
    cout<<"********Home Loan*********"<<endl;
    cout<<"Interest Rate on Home Loan is 8.35% per month"<<endl;
    cout<<"Enter your salary per month : "<<endl;
    cin>>month_sal;
    cout<<"You can Take Loan upto "<<month_sal*60<<endl;
    cout<<"Tenure For Loan is 15 years"<<endl;
    loan_amt=month_sal*60;
    cout<<"Loan is Successfully Granted."<<endl;
    Lid++;
    cout<<"Your loan id is "<<Lid<<endl;
}

void Loan::student(){
    cout<<"********Student Loan*********"<<endl;
    cout<<"Interest Rate on Student Loan is 10.75% per month"<<endl;
    cout<<"You can Take Loan upto 40 Lac"<<endl;
    cout<<"Tenure For Loan is 15 years"<<endl;
    do{
        cout<<"Enter Your Loan Amount : ";
        cin>>loan_amt;
    }while(loan_amt<0);
    cout<<"Loan is Successfully Granted."<<endl;
    Lid++;
    cout<<"Your loan id is "<<Lid<<endl;
}

void Loan::business(){
    cout<<"********Business Loan*********"<<endl;
    cout<<"Interest Rate on Business Loan is 22.50 per month"<<endl;
    cout<<"You can Take Loan upto 1 crore"<<endl;
    cout<<"Tenure For Loan is 4 years"<<endl;
    do{
        cout<<"Enter Your Loan Amount : ";
        cin>>loan_amt;
    }while(loan_amt<0); 
    cout<<"Loan is Successfully Granted."<<endl;
    Lid++;
    cout<<"Your loan id is "<<Lid<<endl;
}


class Customer:public Application,public Loan{
public:
    int ch1,ch2;
    int Cid=0;
    int searchCustomerId;
    string cname,city,contact;
    int age;
    bool isLogged();
    void search();
    void write();

    void menu1(){
        do{
            cout<<"\t\t\t\t\t--------------------------------"<<endl;
            cout<<"\t\t\t\t\t|             USER             |"<<endl;
            cout<<"\t\t\t\t\t--------------------------------"<<endl;
            cout<<"1.Create Account (If New User)"<<endl;
            cout<<"2.If Created Press 2"<<endl;
            cout<<"Press 4 for exit"<<endl;
            cout<<"Enter Your Choice : "<<endl;
            cin>>ch1;
            switch(ch1){
                case 1:
                    menu2();
                    write();
                    break;

                case 2:
                    menu3();
                    break;

                default:
                    cout<<"Choose Correct Options"<<endl;
            }
        }while(ch1!=4);
    }
    
    void menu2(){
        cout<<"-----------Create New Account-----------"<<endl;
        cout<<"Enter Your Name : "<<endl;
        cin>>cname;
        do{
            cout<<"Enter Your Age : "<<endl;
            cin>>age;
            if(age<20){
                cout<<"You are Not capable Of Taking LOAN :"<<endl;
            }

        }while(age<20);
        cout<<"Enter Your City : "<<endl;
        
        cin>>city;
        cout<<"Enter Your Contact : "<<endl;
        cin>>contact;
        if (contact.length() == 10) {
            Cid++;
            cout<<"Your Customer ID is "<<Cid<<endl;
        } else {
            cout << "Invalid Number!" << endl;
            cout<<"Enter correct Number : "<<endl;
            cin>>contact;

            Cid++;
            cout<<"Your Customer ID is "<<Cid<<endl; 
        }

        Loan l;
        Application app;
        app.form();
        app.writeToFile();
        l.display1();
        l.calc();

        ofstream out1;
        out1.open("customer1.txt",ios::app);
        out1<<"________________CUSTOMER DATA________________"<<endl;
        out1<<"Name : "<<cname<<endl;
        out1<<"Age : "<<age<<endl;
        out1<<"City : "<<city<<endl;
        out1<<"Contact : "<<contact<<endl;
        out1<<"EMI Amount : "<<l.emi<<endl;
        out1<<"Loan Type : "<<l.type<<endl;
        out1<<"C'ID : "<<Cid<<endl;
        out1<<"----------------------------------------------"<<endl;
        
        out1.close();
    }

    void read(){
        Loan l;
        cout<<"Customer Name : "<<cname<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"City : "<<city<<endl;
        cout<<"Contact : "<<contact<<endl;
        cout<<"C'ID : "<<Cid<<endl;
        
    }


    void menu3(){
        Application app;
        Loan l;
        
        do{
            cout<<"\t\t\t\t\t----------------------------------"<<endl;
            cout<<"\t\t\t\t\t:        Loan Management         :"<<endl;
            cout<<"\t\t\t\t\t----------------------------------"<<endl;
            cout<<"1.View your Account Details : "<<endl;
            cout<<"Press 0 for exit"<<endl;
            cout<<"Choose Option : ";
            cin>>ch2;
            switch(ch2){

                
                case 1:
                    search();
                    break;
                
                default:
                    cout<<"Invalid Choice !"<<endl;    
            }
        }while(ch2!=0);


    }

    
}c;

void Customer::search() {
    int cid1;
    bool found = false;
    cout << "Enter customer ID: ";
    cin >> cid1;
    in.open("customer2.txt",ios::binary | ios::in);
    while (in.read((char*)&c, sizeof(c))) {
        if (c.Cid == cid1) {
            cout << "Customer Details of Cid " << cid1 << endl;
            cout << "--------------------------------" << endl;
            c.read();
            found = true;
        }
    }
    in.close();
    if (!found) {
        cout << "No Details Found" << endl;
    }
    getchar();  
}
void Customer:: write() {
    out.open("customer2.txt", ios::app);
    if (out.is_open()) {
        out.write((char*)&c, sizeof(c));
        out.close();
        cout << "Customer data added successfully." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }
}

bool Customer::isLogged()
{
    string username;
    char password[25];
    string un,pw;
    char ch;
    int i=0;

    cout<<"Enter Username : "<<endl;
    cin>>username;
    cout<<"Enter Password : "<<endl;
    
    while (i < 25) {
        ch = getch();   

        if (ch == 13) {   
            password[i] = '\0';
            break;
        }

        cout << '*'; 
        
        password[i++] = ch;
        
    }

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == username && pw == password)
    {
        return true;
    }
    else{
        return false;
    }
}




int main() {
    int ch8;

    do {
        
        cout << endl;
        cout << "Main Menu: " << endl;
        cout << "----------------------------------------" << endl;
        cout << "1.Register" << endl;
        cout << "2.Login" << endl;
        cout << "Enter Your Choice :" << endl;
        cin >> ch8;

        if (ch8 == 1) {
            string username, password;
            cout << "Registration : " << endl;
            cout << "Create Username : " << endl;
            cin >> username;
            cout << "Create Password : " << endl;
            cin>>password;
            ofstream file;
            file.open(username + ".txt");
            file << username << endl << password;
            file.close();
        } else if (ch8 == 2) {
            bool status = c.isLogged();
            if (!status) {
                system("cls");
                cout << endl;
                cout << "Invalid Login !" << endl;
            } else {
                cout<<endl;
                cout << "Successfully Logged in!" << endl;
                int ch9;

                do {
                    cout << endl;
                    cout << "Welcome Back ! " << endl;
                    cout << "----------------DASHBOARD----------------" << endl;
                    cout << "1.Home : " << endl;
                    cout << "2.Sign Out" << endl;
                    cout << "Enter Choice : ";
                    cin >> ch9;

                    switch (ch9) {
                        case 1:
                            c.menu1();
                            break;
                        case 2:
                            break;
                        default:
                            cout << "Invalid Choice !" << endl;
                    }
                } while (ch9 != 2);
            }
        }
    } while (ch8 != 3); 
    cout << "\nThank you for using the Loan Management System!" << endl;
    return 0;
}  
