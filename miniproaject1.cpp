#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;
int check_user(char user[20],char pass[20],char faname[20])
{
    char u[20],p[20];
    fstream obj;
    obj.open(faname,ios::in);
    obj>>u;
    obj>>p;
    obj.close();
    if(strcmp(u,user)==0 && strcmp(p,pass)==0)
    {
        return 1;
    }
    return 0;
}
class Inventary
{
    private:
        int pid;
        char pname[20];
        float pcost;
        int pqty;
        float ptotal;

    public:
        void get();
        void getupdate();
        void put();
        void add();
        void display();
        void serach(int id);
        void Delete(int id);
        void update(int id);
};
void Inventary::get()
{
    cout<<"\n\t Enter the Product Id:";
    cin>>pid;
    cout<<"\n\t Enter the Product Name:";
    cin>>pname;
    cout<<"\n\t Enter the Product Cost in Rs:";
    cin>>pcost;
    cout<<"\n\t Enter the Product Quantity:";
    cin>>pqty;
    ptotal=pcost*pqty;
}
void Inventary::getupdate()
{
    cout<<"\n\t Enter the Product Name:";
    cin>>pname;
    cout<<"\n\t Enter the Product Cost in Rs:";
    cin>>pcost;
    cout<<"\n\t Enter the Product Quantity:";
    cin>>ptotal;
    ptotal=pcost*pqty;
}
void Inventary::put()
{
    cout<<"\n\t "<<setiosflags(ios::left)<<setw(5)<<pid<<setw(20)<<pname<<setw(10)<<pcost<<setw(5)<<pqty<<setw(10)<<ptotal;
}
void Inventary::add()
{
    Inventary obji;
    fstream objf;
    objf.open("data.txt",ios::app|ios::binary);
    if(objf.good())
    {
        obji.get();
        objf.write((char*)&obji,sizeof(obji));
        if(objf.good())
        {
            cout<<"\n\t Record Added Successfully";
        }
        else
        {
            cout<<"\n\t Record Fail";
        }
        objf.close();
    }
    else
    {
        cout<<"\n\t data.txt File Open Error in Add Module";
    }
}
void Inventary::display()
{
    Inventary obji;
    fstream objf;
    objf.open("data.txt",ios::in|ios::binary);
    if(objf.good())
    {
        while(objf.read((char*)&obji,sizeof(obji)))
        {
            obji.put();
        }
        objf.close();
    }
    else
    {
        cout<<"\n\t data.txt File Open Error in Display Module";
    }
}
void Inventary::serach(int id)
{
    int x=0;
    Inventary obji;
    fstream objf;
    objf.open("data.txt",ios::in|ios::binary);
    if(objf.good())
    {
        while(objf.read((char*)&obji,sizeof(obji)))
        {
            if(obji.pid==id)
            {
                obji.put();
                x++;
            }
        }
        objf.close();
        if(x==0)
        {
            cout<<"\n\t Record Not Found";
        }
        else
        {
            cout<<"\n\t Record Found "<<x<<" Times";
        }
    }
    else
    {
        cout<<"\n\t data.txt File Open Error in Search Module";
    }
}
void Inventary::Delete(int id)
{
    int x=0;
    Inventary obji;
    fstream objf,objt;
    objf.open("data.txt",ios::in|ios::binary);
    if(objf.good())
    {
        objt.open("temp.txt",ios::out|ios::binary);
        while(objf.read((char*)&obji,sizeof(obji)))
        {
            if(obji.pid==id)
            {
                x++;
            }
            else
            {
                objt.write((char*)&obji,sizeof(obji));
            }
        }
        objf.close();
        objt.close();
        remove("data.txt");
        rename("temp.txt","data.txt");
        if(x==0)
        {
            cout<<"\n\t Record Not Found";
        }
        else
        {
            cout<<"\n\t Record Deleted "<<x<<" Times";
        }
    }
    else
    {
        cout<<"\n\t data.txt File Open Error in Delete Module";
    }
}
void Inventary::update(int id)
{
    int x=0;
    Inventary obji;
    fstream objf,objt;
    objf.open("data.txt",ios::in|ios::binary);
    if(objf.good())
    {
        objt.open("temp.txt",ios::out|ios::binary);
        while(objf.read((char*)&obji,sizeof(obji)))
        {
            if(obji.pid==id)
            {
                obji.getupdate();
                objt.write((char*)&obji,sizeof(obji));
                x++;
            }
            else
            {
                objt.write((char*)&obji,sizeof(obji));
            }
        }
        objf.close();
        objt.close();
        remove("data.txt");
        rename("temp.txt","data.txt");
        if(x==0)
        {
            cout<<"\n\t Record Not Found";
        }
        else
        {
            cout<<"\n\t Record Updated "<<x<<" Times";
        }
    }
    else
    {
        cout<<"\n\t data.txt File Open Error in Update Module";
    }
}
int main()
{
    int choice,x,id;
    char ch,user[20],pass[20];
    Inventary obj;
    do
    {
        system("cls");
        cout<<"\n\t .........................................";
        cout<<"\n\t\t Welcomt To Inventary Management System";
        cout<<"\n\t .........................................";
        cout<<"\n\t .........................................";
        cout<<"\n\t Login Section";
        cout<<"\n\t.........................................";
        cout<<"\n\t 1.Admin Login";
        cout<<"\n\t 2.Customer Login";
        cout<<"\n\t 3.Exit";
        cout<<"\n\t.........................................";
        cout<<"\n\t Enter Your Choice(1-3):";
        cin>>choice;
        cout<<"\n\t.........................................";
        switch(choice)
        {
            case 1:
                cout<<"\n\t Enter the User Name:";
                cin>>user;
                cout<<"\n\t Enter the Password:";
                cin>>pass;
                x=check_user(user,pass,"admin.txt");
                if(x==1)
                {
                    do
                    {
                        system("cls");
                        cout<<"\n\t .........................................";
                        cout<<"\n\t Admin Menu";
                        cout<<"\n\t..........................................";
                        cout<<"\n\t 1.Add Record";
                        cout<<"\n\t 2.Display Record";
                        cout<<"\n\t 3.Search Record";
                        cout<<"\n\t 4.Update Record";
                        cout<<"\n\t 5.Delete Record";
                        cout<<"\n\t 6.Logout";
                        cout<<"\n\t..........................................";
                        cout<<"\n\t Enter Your Choice(1-6):";
                        cin>>choice;
                        cout<<"\n\t..........................................";
                        switch(choice)
                        {
                            case 1:
                                obj.add();
                                break;

                            case 2:
                                cout<<"\n\t .........................................";
                                cout<<"\n\t\t Inventary Management System";
                                cout<<"\n\t .........................................";
                                cout<<"\n\t "<<setiosflags(ios::left)<<setw(5)<<"pid"<<setw(20)<<"pname"<<setw(10)<<"pcost"<<setw(5)<<"pqty"<<setw(10)<<"ptotal";
                                cout<<"\n\t .........................................";
                                obj.display();
                                cout<<"\n\t .........................................";
                                break;
                                  
                            case 3:
                                cout<<"\n\t Enter the Id to Serach Record:";
                                cin>>id;
                                obj.serach(id);
                                break;
                            
                            case 4:
                                cout<<"\n\t Enter the Id to Update Record:";
                                cin>>id;
                                obj.update(id);
                                break;

                            case 5:
                                cout<<"\n\t Enter the Id to Delete Record:";
                                cin>>id;
                                obj.Delete(id);
                                break;
                            case 6:
                                exit(0);
                                break;

                            default :
                                cout<<"\n\t Invalid Admin User";
                        }
                        cout<<"\n\t Do You Want To Continue in Admin Menu(Y/N):";
                        cin>>ch;
                    }while(ch=='y'||ch=='Y');
                }
                else
                {
                    cout<<"\n\t Invalid Admin User Pradencials";
                }
                break;

            case 2:
                cout<<"\n\t Enter the User Name:";
                cin>>user;
                cout<<"\n\t Enter the Password:";
                cin>>pass;
                x=check_user(user,pass,"user.txt");
                if(x==1)
                {
                    do
                    {
                        system("cls");
                        cout<<"\n\t .........................................";
                        cout<<"\n\t Customer Menu";
                        cout<<"\n\t..........................................";
                        cout<<"\n\t 1.Display Record";
                        cout<<"\n\t 2.Search Record";
                        cout<<"\n\t 3.Logout";
                        cout<<"\n\t..........................................";
                        cout<<"\n\t Enter Your Choice(1-3):";
                        cin>>choice;
                        cout<<"\n\t..........................................";
                        switch(choice)
                        {
                            case 1:
                                cout<<"\n\t .........................................";
                                cout<<"\n\t\t Inventary Management System";
                                cout<<"\n\t .........................................";
                                cout<<"\n\t "<<setiosflags(ios::left)<<setw(5)<<"pid"<<setw(20)<<"pname"<<setw(10)<<"pcost"<<setw(5)<<"pqty"<<setw(10)<<"ptotal";
                                cout<<"\n\t .........................................";
                                obj.display();
                                cout<<"\n\t .........................................";
                                break;

                            case 2:
                                cout<<"\n\t Enter the Id to Serach Record:";
                                cin>>id;
                                obj.serach(id);
                                break;
                                  
                            case 3:
                                exit(0);
                                break;

                            default :
                                cout<<"\n\t Invalid Customer User";
                        }
                        cout<<"\n\t Do You Want To Continue in Customer Menu(Y/N):";
                        cin>>ch;
                    }while(ch=='y'||ch=='Y');
                }
                else
                {
                    cout<<"\n\t Invalid Customer Pradencials";
                }
                break;
                
            case 3:
                exit(0);
                break;

            default :
                cout<<"\n\t Invalid User";
        }
        cout<<"\n\t Do You Want To Continue in Login Section(Y/N):";
        cin>>ch;
    }while(ch=='y'||ch=='Y');


    return 0;
}