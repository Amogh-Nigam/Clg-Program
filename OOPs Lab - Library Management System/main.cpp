
//***************************************************************
//                   HEADER FILE USED IN PROJECT
// MADE BY : AMOGH NIGAM 2K20/CO/064 & ADITYA YADAV 2K20/CO/042
//****************************************************************

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <iomanip>
using namespace std;

void clrscr(void)
{
       system("clear");
}

void gotoxy(int x, int y)
{
    cout << setw(x);
    for (; y > 0; y--)
        cout << endl;
}

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class book
{
    char bno[16];
    char bname[150];
    char aname[120];

public:
    void create_book()
    {
        cout << "\nNEW BOOK ENTRY...\n";
        cout << "\nEnter The book no. : ";
        cin >> bno;
        cout << "\n\nEnter The Name of The Book : ";
        cin.ignore();
        cin.getline(bname, 150);
        cout << "\n\nEnter The Author's Name : ";
        cin.getline(aname, 120);
        cout << "\n\n\nBook Created!!!";
    }

    void show_book()
    {
        cout << "\nBook no. : " << bno;
        cout << "\nBook Name : ";
        puts(bname);
        cout << "Author Name : ";
        puts(aname);
    }

    void modify_book()
    {
        cout << "\nBook no. : " << bno;
        cout << "\nModify Book Name : ";
        cin.ignore();
        cin.getline(bname, 150);
        cout << "\nModify Author's Name of Book : ";
        cin.getline(aname, 120);
    }

    char *retbno()
    {
        return bno;
    }

    void report()
    {
        cout << bno << setw(35) << bname << setw(35) << aname << endl;
    }

}; //class ends here

class student
{
    char admno[60];
    char name[25];
    char stbno[16];
    int token;

public:
    void create_student()
    {
        clrscr();
        cout << "\nNEW STUDENT ENTRY...\n";
        cout << "\nEnter The admission no. : ";
        cin >> admno;
        cout << "\n\nEnter The Name of The Student : ";
        cin.ignore();
        cin.getline(name, 25);
        token = 0;
        stbno[0] = '/0';
        cout << "\n\nStudent Record Created!!!";
    }

    void show_student()
    {
        cout << "\nAdmission no. : " << admno;
        cout << "\nStudent Name : ";
        puts(name);
        cout << "\nNo of Book issued : " << token;
        if (token == 1)
            cout << "\nBook No : " << stbno;
    }

    void modify_student()
    {
        cout << "\nAdmission no. : " << admno;
        cout << "\nModify Student Name : ";
        cin.ignore();
        cin.getline(name, 25);
    }

    char *retadmno()
    {
        return admno;
    }

    char *retstbno()
    {
        return stbno;
    }

    int rettoken()
    {
        return token;
    }

    void addtoken()
    {
        token = 1;
    }

    void resettoken()
    {
        token = 0;
    }

    void getstbno(char t[])
    {
        strcpy(stbno, t);
    }

    void report()
    {
        cout << "\t" << admno << setw(25) << name << setw(25) << token << endl;
    }

}; //class ends here

//***************************************************************
//        global declaration for stream object, object
//****************************************************************

fstream fp, fp1;
book bk;
student st;

//***************************************************************
//        function to write in file
//****************************************************************

void write_book()
{
    char ch;
    fp.open("book.dat", ios::out | ios::app);
    do
    {
        clrscr();
        bk.create_book();
        fp.write((char *)&bk, sizeof(book));
        cout << "\n\nDo you want to add more record..(y/n?)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fp.close();
}

void write_student()
{
    char ch;
    fp.open("student.dat", ios::out | ios::app);
    do
    {
        st.create_student();
        fp.write((char *)&st, sizeof(student));
        cout << "\n\nDo you want to add more record..(y/n?)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fp.close();
}

//***************************************************************
//        function to read specific record from file
//***************************************************************

void display_spb(char n[])
{
    cout << "\nBOOK DETAILS\n";
    int flag = 0;
    fp.open("book.dat", ios::in);
    while (fp.read((char *)&bk, sizeof(book)))
    {
        if (strcmp(bk.retbno(), n) == 0)
        {
            bk.show_book();
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "\n\nBook does not exist";
    cout<<endl;
    cout<<"\nPress Enter to Continue ...";
    string a;
    cin.ignore();
    getline(cin,  a);
    fp.close();
}

void display_sps(char n[])
{
    cout << "\nSTUDENT DETAILS\n";
    int flag = 0;
    fp.open("student.dat", ios::in);
    while (fp.read((char *)&st, sizeof(student)))
    {
        if ((strcmp(st.retadmno(), n) == 0))
        {
            st.show_student();
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "\n\nStudent does not exist";
    cout<<endl;
    cout<<"\nPress Enter to Continue ...";
    string a;
    cin.ignore();
    getline(cin,  a);
    fp.close();
}

//***************************************************************
//        function to modify record of file
//****************************************************************

void modify_book()
{
    char n[16];
    int found = 0;
    clrscr();
    cout << "\n\n\tMODIFY BOOK RECORD... ";
    cout << "\n\n\tEnter The book no. of The book : ";
    cin >> n;
    fp.open("book.dat", ios::in | ios::out);
    while (fp.read((char *)&bk, sizeof(book)) && found == 0)
    {
        if (strcmp(bk.retbno(), n) == 0)
        {
            bk.show_book();
            cout << "\nEnter The New Details of book : " << endl;
            bk.modify_book();
            unsigned long pos = -1 * sizeof(bk);
            fp.seekp(pos, ios::cur);
            fp.write((char *)&bk, sizeof(book));
            cout << "\n\n\t Record Updated!!!";
            found = 1;
        }
    }
    if (found == 0)
        cout << "\n\n Record Not Found!!! ";
    cout<<endl;
    cout<<"\nPress Enter to Continue ...";
    string a;
    cin.ignore();
    getline(cin,  a);
    fp.close();
}

void modify_student()
{
    char n[60];
    int found = 0;
    clrscr();
    cout << "\n\n\tMODIFY STUDENT RECORD... ";
    cout << "\n\n\tEnter The admission no. of The student : ";
    cin >> n;
    fp.open("student.dat", ios::in | ios::out);
    while (fp.read((char *)&st, sizeof(student)) && found == 0)
    {
        if (strcmp(st.retadmno(), n) == 0)
        {
            st.show_student();
            cout << "\nEnter The New Details of student" << endl;
            st.modify_student();
            unsigned long pos = -1 * sizeof(st);
            fp.seekp(pos, ios::cur);
            fp.write((char *)&st, sizeof(student));
            cout << "\n\n\t Record Updated!!!";
            found = 1;
        }
    }
    if (found == 0)
        cout << "\n\n Record Not Found!!!";
    cout<<endl;
    cout<<"\nPress Enter to Continue ...";
    string a;
    cin.ignore();
    getline(cin,  a);
    fp.close();
}

//***************************************************************
//        function to delete record of file
//****************************************************************

void delete_student()
{
    char n[60];
    int flag = 0;
    clrscr();
    cout << "\n\n\n\tDELETE STUDENT...";
    cout << "\n\nEnter The admission no. of the Student You Want To Delete : ";
    cin >> n;
    fp.open("student.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char *)&st, sizeof(student)))
    {
        if (strcmp(st.retadmno(), n) != 0)
            fp2.write((char *)&st, sizeof(student));
        else
            flag = 1;
    }
    if (flag == 1)
        cout << "\n\n\tRecord Deleted!!!";
        
    else
        cout << "\n\nRecord not found!!!";
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("Temp.dat", "student.dat");
    cout<<endl;
    cout<<"\nPress Enter to Continue ...";
    string a;
    cin.ignore();
    getline(cin,  a);
}

void delete_book()
{
    char n[16];
    clrscr();
    cout << "\n\n\n\tDELETE BOOK ...";
    cout << "\n\nEnter The Book no. of the Book You Want To Delete : ";
    cin >> n;
    fp.open("book.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char *)&bk, sizeof(book)))
    {
        if (strcmp(bk.retbno(), n) != 0)
        {
            fp2.write((char *)&bk, sizeof(book));
        }
    }

    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat", "book.dat");
    cout << "\n\n\tRecord Deleted !!!";
    cout<<endl;
    cout<<"\nPress Enter to Continue ...";
    string a;
    cin.ignore();
    getline(cin,  a);
}

//***************************************************************
//        function to display all students list
//****************************************************************

void display_alls()
{
    clrscr();
    fp.open("student.dat", ios::in);
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";

        return;
    }

    cout << "\n\n\t\t\t\tSTUDENT LIST\n\n";
    cout << "========================================================================\n";
    cout << "\tAdmission No." << setw(20) << "Name" << setw(30) << "Book Issued\n";
    cout << "========================================================================\n";

    while (fp.read((char *)&st, sizeof(student)))
    {
        st.report();
    }
    fp.close();
    cout<<endl;
    cout<<"\nPress Enter to Continue ...";
    string a;
    cin.ignore();
    getline(cin,  a);
}

//***************************************************************
//        function to display Books list
//****************************************************************

void display_allb()
{
    clrscr();
    fp.open("book.dat", ios::in);
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";

        return;
    }

    cout << "\n\n\t\t\t\tBOOK LIST\n\n";
    cout << "==================================================================================\n";
    cout << "Book Number" << setw(35) << "Book Name" << setw(35) << "Author\n";
    cout << "==================================================================================\n";

    while (fp.read((char *)&bk, sizeof(book)))
    {
        bk.report();
    }
    fp.close();
    cout<<endl;
    cout<<"\nPress Enter to Continue ...";
    string a;
    cin.ignore();
    getline(cin,  a);
}

//***************************************************************
//        function to issue book
//****************************************************************

void book_issue()
{
    char sn[60], bn[16];
    int found = 0, flag = 0;
    clrscr();
    cout << "\n\nBOOK ISSUE ...";
    cout << "\n\n\tEnter The student's admission no. : ";
    cin >> sn;
    fp.open("student.dat", ios::in | ios::out);
    fp1.open("book.dat", ios::in | ios::out);
    while (fp.read((char *)&st, sizeof(student)) && found == 0)
    {
        if (strcmp(st.retadmno(), sn) == 0)
        {
            found = 1;
            if (st.rettoken() == 0)
            {
                cout << "\n\n\tEnter the book no. : ";
                cin >> bn;
                while (fp1.read((char *)&bk, sizeof(book)) && flag == 0)
                {
                    if (strcmp(bk.retbno(), bn) == 0)
                    {
                        bk.show_book();
                        flag = 1;
                        st.addtoken();
                        st.getstbno(bk.retbno());
                        unsigned long pos = (-1) * sizeof(st);
                        fp.seekp(pos, ios::cur);
                        fp.write((char *)&st, sizeof(student));
                        cout << "\n\n\t Book issued successfully\n\nPlease Note: Write the current date in backside of your book and submit within 15 days fine Rs. 1 for each day after 15 days period";
                    }
                }
                if (flag == 0)
                    cout << "Book no does not exist";
            }
            else
                cout << "You have not returned the last book ";
        }
    }
    if (found == 0)
        cout << "Student record not exist...";
    fp.close();
    fp1.close();
    cout<<endl;
    cout<<"\nPress Enter to Continue ...";
    string a;
    cin.ignore();
    getline(cin,  a);
}

//***************************************************************
//        function to deposit book
//****************************************************************

void book_deposit()
{
    char sn[60];
    int found = 0, flag = 0, day;
    long fine;
    clrscr();
    cout << "\n\nBOOK DEPOSIT ...";
    cout << "\n\n\tEnter The student's admission no. : ";
    cin >> sn;
    fp.open("student.dat", ios::in | ios::out);
    fp1.open("book.dat", ios::in | ios::out);
    while (fp.read((char *)&st, sizeof(student)) && found == 0)
    {
        if (strcmp(st.retadmno(), sn) == 0)
        {
            found = 1;
            if (st.rettoken() == 1)
            {
                while (fp1.read((char *)&bk, sizeof(book)) && flag == 0)
                {
                    if (strcmp(bk.retbno(), st.retstbno()) == 0)
                    {
                        bk.show_book();
                        flag = 1;
                        cout << "\n\nBook deposited in no. of days : ";
                        cin >> day;
                        if (day > 15)
                        {
                            fine = (day - 15) * 1;
                            cout << "\n\nFine has to deposited Rs. : " << fine;
                        }
                        st.resettoken();
                        unsigned long pos = -1 * sizeof(st);
                        fp.seekp(pos, ios::cur);
                        fp.write((char *)&st, sizeof(student));
                        cout << "\n\n\t Book deposited successfully";
                    }
                }
                if (flag == 0)
                    cout << "Book no. does not exist!!!";
            }
            else
                cout << "No book is issued...please check!!!";
        }
    }
    if (found == 0)
        cout << "Student record not exist!!!";
    fp.close();
    fp1.close();
    cout<<endl;
    cout<<"\nPress Enter to Continue ...";
    string a;
    cin.ignore();
    getline(cin,  a);
}

//***************************************************************
//        INTRODUCTION FUNCTION
//****************************************************************

void intro()

{
    clrscr();
    gotoxy(35, 1);
    cout << "LIBRARY";
    gotoxy(37, 1);
    cout << "MANAGEMENT";
    gotoxy(35, 1);
    cout << "SYSTEM";
    gotoxy(52, 2);
    cout << "DELHI TECHNOLOGICAL UNIVERSITY (DTU)";
    gotoxy(53, 1);
    cout << "(formerly Delhi College of Engineering)";
}

//***************************************************************
//        ADMINISTRATOR MENU FUNCTION
//****************************************************************

void admin_menu()
{
    clrscr();
    int ch2;
    cout << "\n\n\n\tADMINISTRATOR MENU";
    cout << "\n\n\t1.CREATE STUDENT RECORD";
    cout << "\n\n\t2.DISPLAY ALL STUDENTS RECORD";
    cout << "\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
    cout << "\n\n\t4.MODIFY STUDENT RECORD";
    cout << "\n\n\t5.DELETE STUDENT RECORD";
    cout << "\n\n\t6.CREATE BOOK ";
    cout << "\n\n\t7.DISPLAY ALL BOOKS ";
    cout << "\n\n\t8.DISPLAY SPECIFIC BOOK ";
    cout << "\n\n\t9.MODIFY BOOK ";
    cout << "\n\n\t10.DELETE BOOK ";
    cout << "\n\n\t11.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-11) : ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        clrscr();
        write_student();
        break;
    case 2:
        display_alls();
        break;
    case 3:
        char num[6];
        clrscr();
        cout << "\n\n\tPlease Enter The Admission No. : ";
        cin >> num;
        display_sps(num);
        break;
    case 4:
        modify_student();
        break;
    case 5:
        delete_student();
        break;
    case 6:
        clrscr();
        write_book();
        break;
    case 7:
        display_allb();
        break;
    case 8:
    {
        char num[6];
        clrscr();
        cout << "\n\n\tPlease Enter The book No. : ";
        cin >> num;
        display_spb(num);
        break;
    }
    case 9:
        modify_book();
        break;
    case 10:
        delete_book();
        break;
    case 11:
        return clrscr();
    default:
        cout << "\a";
    }
    admin_menu();
}

//***************************************************************
//        THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
    char ch;
    intro();
    do
    {
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. BOOK ISSUE";
        cout << "\n\n\t02. BOOK DEPOSIT";
        cout << "\n\n\t03. ADMINISTRATOR MENU";
        cout << "\n\n\t04. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-4) : ";
        cin >> ch;
        switch (ch)
        {
        case '1':
        {
            clrscr();
            book_issue();
            clrscr();
            break;
        }
        case '2':
        {
            book_deposit();
            clrscr();
            break;
        }
        case '3':
        {
            admin_menu();
            break;
        }
        case '4':
            exit(0);
        default:
            cout << "\a";
        }
    } while (ch != '4');
    return 0;
}

//***************************************************************
//                END OF PROJECT
//***************************************************************
