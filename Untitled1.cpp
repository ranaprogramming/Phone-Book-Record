// Importing input output operations file
#include <iostream>
// Importing file class for open a file for writing
#include <fstream>
// Importing standard library file

using namespace std;

// Variables declared outside any function
string fname, lname, phone_num, email, address;


// Main driver method
void addContact();
void searchContact();
void self_exit();
bool check_digits(string);
bool check_numbers(string);


void self_exit()
{
	system("cls");
	cout << "\n\n\n\t\tThank You for using Contact-Saver!";
	exit(1);
}


//Add 
void addContact()
{              // file name in which we store data
	ofstream phone("number.txt", ios::app);
	system("cls");
	
	//Menu
	cout << "\n\n\tEnter First Name : ";
	cin >> fname;
	cout << "\n\tEnter Last Name : ";
	cin >> lname;
	cout << "\n\tEnter Email Address :";
	cin >> email;
	cout << "\n\tEnter Address :";
	cin >> address;
	cout << "\n\tEnter Phone Number : ";
	cin >> phone_num;

    
    //Conditions
	if (check_digits(phone_num) == true) 
	{
		if (check_numbers(phone_num) == true)
		 {
			if (phone.is_open())
			 {
				phone << fname << " " << lname << " "<< email<< " " <<address << " " << phone_num << endl;
				cout << "\n\tContact saved successfully !";
			}
			else {
				cout << "\n\tError in opening record!";
			}
		}
		
		else {
			cout << "\n\tOnly numbers are allowed!";
		}
	}
	else {
		cout << "\n\tPhone number should be of 11 digits "
				"only.";
	}
	cout << endl << endl;
	system("pause");
	system("cls");
	phone.close();
}

// Search
void searchContact()
{
	bool found = false;
	ifstream myfile("number.txt");
	string keyword;
	cout << "\n\tEnter Name to search : ";
	cin >> keyword;
	while (myfile >> fname >> lname >> email >> address>> phone_num ) {
		if (keyword == fname || keyword == lname) {
			system("cls");
			cout << "\n\n\n\t\tCONTACT DETAILS\n";
			cout << "\n\nFirst Name : " << fname;
			cout << "\nLast Name : " << lname;
			cout << "\nEmail : " << email;
			cout << "\nAddress : " << address;
			cout << "\nPhone Number : " << phone_num;
	

			found = true;
			break;
		}
	}
	if (found == false)
		cout << "\nNo such contact is found!";

	cout << endl << endl;
	system("pause");
	system("cls");
}

//Phone number length
bool check_digits(string x)
{
	if (x.length() == 11)
		return true;
	else
		return false;
}

bool check_numbers(string x)
{
	bool check = true;

	for (int i = 0; i < x.length(); i++) {
		if (!(int(x[i]) >= 48 && int(x[i]) <= 57)) {
			check = false;
			break;
		}
	}

	if (check == true)
		return true;

	if (check == false)
		return false;

	cout << endl << endl;
	system("pause");
	system("cls");
}


// Main driver method
int main()
{
	int choice;
	system("cls");
	
	// screen color
	system("color 0C");
	while (1) {
		cout << "\n\n\n\t\t\tCONTACT SAVER";
		cout << "\n\n\t1. Add Contact\n\t2. Search "
				"Contact\n\t3. Exit\n\t> ";
		cin >> choice;

		// Switch case
		switch (choice) {
		case 1:
			addContact();
			break;
		case 2:
			searchContact();
			break;
	
	    case 3:
			self_exit();
			break;

		default:
			cout << "\n\n\tInvalid Input!";
		}
	}
	    return 0;
	}
