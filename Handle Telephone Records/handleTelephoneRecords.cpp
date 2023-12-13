#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
    ifstream fin;
    ofstream fout;

    char name[30],str[30],ph[15];
    int choice, x, f;

    do
    {
        system("cls");
        cout<<"\n$$$$$MENU$$$$$";
        cout<<"\n1.Add record";
        cout<<"\n2.searcch record";
        cout<<"\n3.delete record";
        cout<<"\n4.display all records";
        cout<<"\n5.Exit";
        cout<<"\nEnter choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1: fout.open("Tele.dat",ios::app);
                    cout<<"\nEnter name and phone no.";
                    cin>>name>>ph;
                    fout<<name<<"\t"<<ph<<"\n";
                    cout<<"\nrecord added";
                    fout.close();
                    break;

            case 2: fin.open("Tele.dat");
                    if (fin!=0)
                    {
                        cout<<"\nAdd records first.";
                        break;
                    }
                    cout<<"\nEnter name to search ";
                    cin>>str;
                    f=0;
                    while(1)
                    {
                        fin>>name>>ph;
                        if(fin.eof())
                        {
                            break;
                        }
                        x=stricmp(name,str);
                        if(x==0)
                        {
                            cout<<"\nname : "<<name;
                            cout<<"\nphone : "<<ph;
                            f=1;
                        }
                    }
                    if(f==0)
                        cout<<"\n"<<str<<" is not found.";

                    fin.close();
                    break;

            case 3: fin.open("Tele.dat");
                    if(fin!=0)
                    {
                        cout<<"\nAdd recrods first.";
                        break;
                    }
                    fout.open("Temp.dat");
                    cout<<"\nEnter name to delete : ";
                    cin>>str;
                    f=0;
                    while(1)
                    {
                        fin>>name>>str;
                        if(fin.eof())
                            break;
                        x=stricmp(name, str);
                        if(x==0)
                            f=1;
                        else
                            fout<<name<<"\t"<<ph<<"\n";
                    }
                    if(f==0)
                        cout<<"\n"<<str<<" is not found.";
                    else
                        cout<<"\n"<<str<<" is deleted.";
                    fout.close();
                    fin.close();
                    remove("Tele.dat");
                    rename("Temp.dat","Tele.dat");
                    break;

            case 4: fin.open("Tele.dat");
                    if(fin!=0)
                    {
                        cout<<"\nAdd records first";
                        break;
                    }
                    cout<<"\nname\tphone";
                    while(1)
                    {
                        fin>>name>>ph;
                        if(fin.eof())
                            break;
                        cout<<"\n"<<name<<"\t"<<ph;
                    }
                    fin.close();
                    break;

            case 5: cout<<"\nGood Bye!";
                    break;

            default : cout<<"\nInvalid choice.";

        }
        getch();

    }while(choice!=5);
    return 0;
}
