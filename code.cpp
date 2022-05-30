#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;

void login();
void registration();
void forgot();

void welcome()
{
    cout << "Welcome to our Website !" << endl;
    int n;
    cout << "\nLogin(1) \nRegister(2) \nForgot Password(any key)" << endl;
    cin >> n;
    if (n == 1)
        login();
    else if (n == 2)
        registration();
    else
        forgot();
}

void sleep()
{
    int n = INT_MAX;
    while (n--)
    {
        // do nothing - Verification is going on...
    }
}

int main()
{
    welcome();
    return 0;
}

void login()
{
    string u_name, u_pass, f_name, f_pass;
    cout << "\nEnter Username: " << endl;
    cin >> u_name;
    cout << "Enter password: " << endl;
    cin >> u_pass;
    ifstream f("records.txt"); // ifstream is used to read text in a file
    bool flag = false;
    while (f >> f_name >> f_pass) // >> is used for reading operation. In each line first string is name and second is password.
    {
        if (f_name == u_name && f_pass == u_pass) // if name and password matches login successfull
        {
            flag = true;
        }
    }
    f.close();
    if (flag)
    {
        cout << "Login Successful" << endl;
        return;
    }
    else
    {
        char c;
        cout << "Login failed - Try again\n | Forgot Password (y/n)? |";
        cin >> c;
        if (c == 'y')
        {

            forgot();
        }
        else
        {

            login();
        }
    }
}

void registration()
{
    string u_name, u_pass, f_name;
    cout << "\nEnter Username: \n";
    cin >> u_name;
    ifstream f("records.txt");
    while (f >> f_name)
    {
        if (f_name == u_name)
        {
            int n;
            cout << "\nAccount already exists ! \nLogin(1) \nForgot Password(2)\nExit(3)\n";
            cin >> n;
            if (n == 1)
            {
                login();
            }
            else if (n == 2)
            {
                forgot();
            }
            else
                return;
        }
    }
    f.close();
    cout << "\nEnter Password: \n";
    cin >> u_pass;
    ofstream f1("records.txt", ios::app); // ofstream is used to write in the file. app means to append at the end of the file
    f1 << u_name << " " << u_pass << endl;
    cout << "Registration Successful\n";
    f1.close();
    welcome();
}

void forgot()
{
    int n;
    cout << "\nChoose a method to log in: \nMobile Verification(1) \nE-mail verification(2) \nExit(3)\n";
    cin >> n;
    string u_name;
    cout << "Enter user name: \n";
    cin >> u_name;
    if (n == 1)
    {
        cout << "\nA message has been sent to your mobile.Please Verify\n";
    }
    else if (n == 2)
    {
        cout << "A mail has been sent to your account.Please Verify\n";
    }
    else
    {
        return;
    }
    sleep();
    cout << "Verification Done !" << endl;
    cout << "Reset your password\n";
    string u_pass;
    cout << "\nEnter Password: \n";
    cin >> u_pass;
    ofstream f1("records.txt", ios::app); // ofstream is used to write in the file. app means to append at the end of the file
    f1 << u_name << " " << u_pass << endl;
    cout << "Password changed Successfully\n";
    f1.close();
    welcome();
}