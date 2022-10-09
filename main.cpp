#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//Check if password and login are correct
bool check_data()
{
    //Initiate and open file
    std::ifstream file;
    file.open("F:\\pass.txt");

    if(file.good()){

        cout << endl;
        cout << "Enter login: ";
        string tmp_login;
        cin >> tmp_login;
        cout << endl;
        //system("cls");

        cout << "Enter password: ";
        string tmp_password;
        cin >> tmp_password;
        cout << endl;
        //system("cls");

        //File open
        string tmp_string;
        //To check if both variable are found
        int both_good = 0;

        while(std::getline(file, tmp_string))
        {
            both_good = 0;

            //Check for login
            size_t foundPosition = tmp_string.find(tmp_login);

            if(foundPosition != string::npos){
                    both_good += 1;
            }

            //Check for password
            foundPosition = tmp_string.find(tmp_password);

            if(foundPosition != string::npos){
                both_good += 1;
            }

            if(both_good == 2){
                break;
            }
        }

        if(both_good == 2){
            cout << "Correct! Welcome!" << endl;
            file.close();
            return true;
        }
        else{
            cout << "Login or password do not exists!" << endl;
            file.close();
            return false;
        }

    }else{
        //File doesn't open
        cout << "Error : File not found" << endl;
        return false;
    }
}

bool register_acc(){

    ofstream file("F:\\pass.txt", ofstream::app);

    if(file.good()){
        cout << endl;
        string tmp_login;
        cout << "Login: ";
        cin >> tmp_login;
        cout << endl;
        //system("cls");

        string tmp_password;
        cout << "Password: ";
        cin >> tmp_password;
        cout << endl;
        //system("cls");

        file << tmp_login + tmp_password  << endl;

        cout << "Account created!" << endl;
        file.close();
        return true;
    }
    else{
        cout << endl;
        cout << "Can't find a file!";
        return false;
    }
}
int main()
{
    int tmp_input;
    bool is_logged = false;

    while(!is_logged){
        cout << "What you want to do?" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;

        cin >> tmp_input;

        switch(tmp_input){
        case 1:
            //system("cls");
            is_logged = register_acc();
            break;

        case 2:
            //system("cls");
            is_logged = check_data();
            break;

        default:
            break;
        }
    }
    return 0;
}
