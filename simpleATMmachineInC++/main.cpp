#include <iostream>
#include<exception>
#include<fstream>
#include<windows.h>
#define j 10
using namespace std;
class Atm
{
protected:
    int record[j],balance[j],pin[j],temp=j;
    string name[j];
public:
    Atm()//initializing from file
    {
        ifstream file1("accountRec.txt");
        for(int i=0;i<j;i++)
        {
            file1>>record[i];
            //cout<<record[i]<<endl;
        }
        ifstream file2("accbalance.txt");
        for(int i=0;i<j;i++)
        {
            file2>>balance[i];
            //cout<<balance[i]<<endl;
        }
        ifstream file3("accpins.txt");
        for(int i=0;i<j;i++)
        {
            file3>>pin[i];
            //cout<<pin[i]<<endl;
        }
        ifstream file4("accnames.txt");
        for(int i=0;i<j;i++)
        {
            getline(file4,name[i]);
            //cout<<name[i]<<endl;
        }
        file1.close();
        file2.close();
        file3.close();
        file4.close();
//        for(int i=0;i<j;i++)
//        {
//            cout<<name[i]<<endl;
//        }

    }
    void checkUser()//checking the user validity
    {
        int temp,tempass,id;
        cout<<"ENTER YOUR ACCOUNT NUMBER: ";
        cin>>id;
        for(int i=0;i<j;i++)
        {
            if(id==record[i])
            {
                temp=i;
                break;
            }
            else
                temp=j;
        }
        try
        {
            if(temp==j)
            {
                throw "Invalid ID\a";
            }
            cout<<"WELCOME "<<name[temp]<< "!\nPLEASE GIVE YOUR PIN NUMBER..."<<endl;
        cin>>tempass;
        try{
        if(tempass!=pin[temp])
        {
            throw "Incorrect Password. SORRY\a";
        }
        this->temp=temp;
        system("cls");
        }catch(const char *a)
        {
            cout<<a<<endl;

        }

        }catch(const char *a){
        cout<<a<<endl;
        }

    }
    virtual void withdraw(int money)
    {
        cout<<"this is our base class"<<endl;
    }
    virtual void transfer(int money)
    {
        cout<<"this is our base class"<<endl;
    }
    virtual void chackBal()
    {
        cout<<"your account balance is : "<<balance[temp]<<"BDT"<<endl;
    }

};
class choiceWork: public Atm//inharited from ATM Class
{
public:
    void checkUser()
    {
        Atm::checkUser();
    }
    void withdraw()//money withdraw
    {
        system("cls");
        int money;
        cout<<"Enter the amount to be withdrawn: ";
        cin>>money;
        if(money<500)
            {
                cout<<"Invalid Amount Sir!!!\a"<<endl;

            }
            else if (money>balance[temp])
            {
                cout<<"Amount exceeds your balance!!!\a"<<endl;

            }
        else
        {balance[temp]=balance[temp]-money;
        ofstream with("accbalance.txt");
        for(int i=0;i<j;i++)
        {
            with<<balance[i]<<endl;
        }
        with.close();
        Atm::chackBal();}
    }
    void transfer()//account transfer
    {
        system("cls");
        int a,t,money;
        cout<<"Enter the account number: "<<endl;
        cin>>a;
        for(int i=0;i<j;i++)
        {
            if(a==record[i])
            {
                t=i;
                break;
            }
            else
                t=j;
        }
        try
        {
            if(t==j)
            {
                throw "Invalid ID\a";
            }
            cout<<"Enter the amout to transfer to "<<name[t]<<"'s account : ";
            cin>>money;
            if(money<500)
            {
                cout<<"Invalid Amount Sir!!!\a"<<endl;

            }
            else if (money>balance[temp])
            {
                cout<<"Amount exceeds your balance!!!\a"<<endl;

            }
            else
            {balance[temp]=balance[temp]-money;
            balance[t]=balance[t]+money;
            Atm::chackBal();}
        }catch(const char *a){
        cout<<a<<endl;
        }
        ofstream tran("accbalance.txt");
        for(int i=0;i<j;i++)
        {
            tran<<balance[i]<<endl;
        }
        tran.close();

    }
    int returnTemp()
    {
        return Atm::temp;
        //cout<<Atm::temp<<endl;
    }
};
void welcome()
{
    system("color 70");
    cout <<"\n\n\n\n\n\n:::::::::::::::::::::::::::::::::::::: THE CITY BANK LTD. ::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"                                   WELCOME TO OUR ATM SYSTEM\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
    cout<<"software by: Shihab-Rifan Software Company LTD."<<endl;
    system("pause");
}
int main()
{
    system("cls");
    welcome();
    int k,choose;
    string ans="y";
    while(ans=="y"||ans=="Y")
    {
        system("cls");
        system("color 17");

        choiceWork acc;
        acc.checkUser();
        k=acc.returnTemp();
        if (k==j)
        {
            system("cls");
            system("color C0");

        }
        else
        {
            cout<<"Sir please make your choice: "<<endl;
            cout<<"1. WITHDRAW\n2. TRANSFER\n3. CHECK BALANCE\n4. EXIT"<<endl;
            cin>>choose;
            switch(choose)
            {
            case 1:
                acc.withdraw();
                break;
            case 2:
                acc.transfer();
                break;
            case 3:
                acc.chackBal();
                break;
            case 4:
                exit(1);
                break;
            default:
                cout<<"WRONG CHOICE INPUT\a"<<endl;

            }
            system("pause");
            system("cls");
            system("color 70");
        }
        cout<<"\n\n\nWanna Continue??? (y/n)\a"<<endl;
        cin>>ans;
    }
    if(ans=="123456789")
    {
        system("cls");
        system("color F0");
        int x,y,z;
        string n;
        cin>>n;//name
        cin>>x;//id
        cin>>y;//pin
        cin>>z;//balance
        ofstream dom("accnames.txt",ios::app|ios::out);
        dom<<endl<<n<<endl;
        dom.close();
        ofstream dom1("accountRec.txt",ios::app|ios::out);
        dom1<<endl<<x<<endl;
        dom1.close();
        ofstream dom2("accpins.txt",ios::app|ios::out);
        dom2<<endl<<y<<endl;;
        dom2.close();
        ofstream dom3("accbalance.txt",ios::app|ios::out);
        dom3<<endl<<z<<endl;
        dom3.close();
        cout<<"Thank you sir...database updated...\a"<<endl;
        system("cls");
        main();
    }

    else if (ans=="n"||ans=="N")
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n                                                          Thank You...\n                                                          For Using Our System..."<<endl;
        system("pause");
    }
    system("cls");
    system("pause");
    main();
}
