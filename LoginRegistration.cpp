#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

bool isLoggedin() {
	string username, password, usr, pass;
	char ch;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	ch = _getch();
	while (ch != 13) {
		password.push_back(ch);
		cout << '*';
		ch = _getch();
	}


	ifstream read("C:\\Users\\User\\Documents\\2021 Projects\\C++\\LoginRegistration\\" + username +".txt");
	getline(read, usr);
	getline(read, pass);

	if (username == usr && password == pass) {
		return true;
	}
	else
	{
		return false;
	}
}

int main() {
	int choice;
	cout << "\n1. Register\n2. Login\nYou decide: " ;
	cin >> choice;
	if (choice == 1) {
		string username, password;
		char ch;
		cout << "Create a Username: ";
		cin >> username;
		cout << "Create a password: ";
		ch = _getch();
		while (ch != 13) {
			password.push_back(ch);
			cout << '*';
			ch = _getch();
		}

		ofstream cfile;
		cfile.open("C:\\Users\\User\\Documents\\2021 Projects\\C++\\LoginRegistration\\" + username + ".txt");
		cfile << username << endl << password;
		cfile.close();

		main();
	}
	else if (choice == 2) {
		bool status = isLoggedin();

		if (status == false) {
			cout << "\nFalse detais" << endl;
			system("PAUSE");
			system("CLS");
			main();
			return 0;
		}
		else {
			cout << "\nSuccessfully logged in" << endl;
			system("PAUSE");
			return 1;
		}

	}

}