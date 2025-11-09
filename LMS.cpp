#include<iostream>
#include<string>
using namespace std;
int main() {
	const int max_books = 100;
	int bookIDs[max_books], totalbooks = 0, quantity[max_books];
	string booknames[max_books], password, edition[max_books];
	int option,i;
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AHR LIBRARY MANAGMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
	do {
		cout << "Login As:\n1.Admin.\n2.Student\n0.Exit\n\n";
		cout << "Enter your Choice:";
		cin >> option;
		if (option == 0) {
			cout << "Exiting the system.\n\n";
			break;
		}
			switch (option) {
			case 1:
				cout << "Enter Password (i.e: admin):";
				cin >> password;
				if (password == "admin") {
					cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Correct Password! Welcome to AHR Library System.\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
					cout << "Logged in as Admin:\n\n";
					cout << "\xB2\xB2\xB2\xB2\xB2\xB2 1.ADD BOOK\n\n\xB2\xB2\xB2\xB2\xB2\xB2 2.DELETE BOOK\n\n";
					cout << "\xB2\xB2\xB2\xB2\xB2\xB2 3.VIEW BOOK LIST\n\n\xB2\xB2\xB2\xB2\xB2\xB2 4.SEARCH BOOK\n\n";
					cout << "\xB2\xB2\xB2\xB2\xB2\xB2 5.EDIT BOOK RECORD\n\n\xB2\xB2\xB2\xB2\xB2\xB2";
					cout << "Enter your choice:";
					cin >> option;
					switch (option) {
					/*case 1:              //Add Books
						if (totalbooks < max_books) {
							cout << "Book Name:";
							cin >> booknames[totalbooks];     //used as array
							cout << "Book ID:";
							cin >> bookIDs[totalbooks];
							cout << "Quantity:";
							cin >> quantity[totalbooks];
							cout << "Edition:";
							cin >> edition[totalbooks];
							totalbooks++;  //Books will not exceed more then 10.
							cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
							cout << "      Book added Successfully!\n\n";
						}
						else {
							cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
							cout << "      You cannot add more than 100 books!\n\n";   //when books exceeds no of 100 this msg displayed.
						}
						break;*/
					case 1: // Add Books
						if (totalbooks < max_books) {
							cin.ignore(); // Clear input buffer to prevent issues with getline()
							cout << "Book Name: ";
							getline(cin, booknames[totalbooks]); // Use getline to allow spaces in input
							cout << "Book ID: ";
							cin >> bookIDs[totalbooks];
							cout << "Quantity: ";
							cin >> quantity[totalbooks];
							cin.ignore(); // Clear input buffer again for the next getline
							cout << "Edition: ";
							getline(cin, edition[totalbooks]); // Use getline for Edition if it may contain spaces
							totalbooks++; // Increment total books
							cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
							cout << "      Book added Successfully!\n\n";
						}
						else {
							cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
							cout << "      You cannot add more than 100 books!\n\n"; // when books exceed the limit
						}
						break;

					case 2:   //Delete Book
						if (totalbooks > 0) {
							int id, found = -1;
							cout << "Enter book Id to delete Book:";  //book id required to delete a book
							cin >> id;
							for (int i = 0;i < totalbooks;i++) {         //loop to match book id 
								if (bookIDs[i] == id) {
									found = i;           //book id found then variable (found) will newly equal to value to i
									break;
								}
							}
							if (found != -1) {
								for (int i = found;i < totalbooks ;i++) {
									bookIDs[i] = bookIDs[i + 1];
									booknames[i] = booknames[i + 1];
									quantity[i] = quantity[i + 1];
									edition[i] = edition[i + 1];
								}
								totalbooks--;
								cout << "\xB2\xB2\xB2\xB2\xB2 Book Deleted Successfully!\n\n";
							}
							else {
								cout << "\xB2\xB2\xB2\xB2\xB2 Book not found!\n\n";
							}
						}
						else {
							cout << "\xB2\xB2\xB2\xB2\xB2 No Book to be deleted!\n\n";
						}
						break;
					case 3:       //View Books
						if (totalbooks == 0) {
							cout << "\xB2\xB2\xB2\xB2\xB2 No Book available right now!\n\n";
						}
						else {
							cout << "\xB2\xB2\xB2\xB2\xB2\xB2 Book List \xB2\xB2\xB2\xB2\xB2\xB2\n\n";
							for (int i = 0;i < totalbooks;i++) {
								cout << "\xB2\xB2\xB2 1.Book Name: " << booknames[i] << "\n\n\xB2\xB2\xB2 2.Book ID: " << bookIDs[i];
								cout << "\n\n\xB2\xB2\xB2 3.Quantity: " << quantity[i] << "\n\n\xB2\xB2\xB2 4.Edition: " << edition[i] << "\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
							}
						}
						break;
					case 4:    //search Book
						if (totalbooks > 0) {
							int id, found = -1;
							cout << "Enter book Id to search:";     //ID required to search for book
							cin >> id;
							for (int i = 0;i < totalbooks;i++) {         //Loop to match id to search book
								if (bookIDs[i] == id) {
									found = i;
									break;
								}
							}
							if (found != -1) {
								cout << "\xB2\xB2\xB2\xB2\xB2\xB2 Book Found! \xB2\xB2\xB2\xB2\xB2\xB2\n\n\xB2\xB2\xB2\xB2 1.Book Name: " << booknames[found] << "\n\n\xB2\xB2\xB2\xB2 2.Book ID: " << bookIDs[found];
								cout << "\n\n\xB2\xB2\xB2\xB2 3.Quantity: " << quantity[found] << "\n\n\xB2\xB2\xB2\xB2 4.Edition: " << edition[found] << "\n\n";
							}
							else {
								cout << "\xB2\xB2\xB2\xB2\xB2 Book not Found!";
							}
						}
						else {
							cout << "\xB2\xB2\xB2\xB2\xB2 No available book to search!";
						}
						break;
					case 5:     //Edit Book Record
						if (totalbooks > 0) {
							int id, found = -1;
							cout << "Enter book Id to search:";     //ID required to search for book
							cin >> id;
							for (int i = 0;i < totalbooks;i++) {         //Loop to match id to search book
								if (bookIDs[i] == id) {
									found = i;
									break;
								}
							}
							if (found != -1) {
								cout << "\xB2\xB2\xB2\xB2\xB2 New Details \xB2\xB2\xB2\xB2\xB2\n\n";
								cout << "\xB2\xB2\xB2\xB2\xB2 New Book name:";
								cin >> booknames[found];
								cout << "\xB2\xB2\xB2\xB2\xB2 New quantity:";
								cin >> quantity[found];
								cout << "\xB2\xB2\xB2\xB2\xB2 Edition:";
								cin >> edition[found];
								cout << "\xB2\xB2\xB2\xB2\xB2 Book record updated Successfully!\n\n";
							}
							else {
								cout << "\xB2\xB2\xB2\xB2\xB2 Book not found!\n\n";
							}
						}
						else {
							cout << "\xB2\xB2\xB2\xB2\xB2 No book Record available to Edit\n\n";
						}
						break;
					default:
						cout << "\xB2\xB2\xB2\xB2\xB2 Not a choice. Try Again\n\n";
						break;
					}
				}
				else {
					cout << "\xB2\xB2\xB2\xB2\xB2 Incorrect Password. Try Again!\n\n";
				}
				break;
				default:
					cout << "Invalid Choice. Try Again!\n\n";
					break;
			case 2:      //student portal.
				cout << "Enter your Password(i.e: student):";
				cin >> password;
				if (password == "student") {
					cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Correct Password! Welcome to AHR Library System.\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
					cout << "\xB2\xB2\xB2\xB2\xB2 Logged in as Student:\n\n";
					cout << "\xB2\xB2\xB2\xB2\xB2\xB2 1.VIEW BOOK LIST\n\n\xB2\xB2\xB2\xB2\xB2\xB2 2.SEARCH BOOK\n\n";
					cout << "\xB2\xB2\xB2\xB2\xB2\xB2 3.BORROW BOOK\n\n";
					cout << "Enter your choice:";
					cin >> option;
					switch (option) {
					case 1:       //View Book
						if (totalbooks == 0) {
							cout << "\xB2\xB2\xB2\xB2\xB2 No Book available right now!\n\n";
						}
						else {
							cout << "\xB2\xB2\xB2\xB2\xB2\xB2 Book List \xB2\xB2\xB2\xB2\xB2\xB2\n\n";
							for (int i = 0;i < totalbooks;i++) {
								cout << "\xB2\xB2\xB2 1.Book Name: " << booknames[i] << "\n\n\xB2\xB2\xB2 2.Book ID: " << bookIDs[i];
								cout << "\n\n\xB2\xB2\xB2 3.Quantity: " << quantity[i] << "\n\n\xB2\xB2\xB2 4.Edition: " << edition[i] << "\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
							}
						}
						break;
					case 2:    //search Book
						if (totalbooks > 0) {
							int id, found = -1;
							cout << "Enter book Id to search:";     //ID required to search for book
							cin >> id;
							for (int i = 0;i < totalbooks;i++) {         //Loop to match id to search book
								if (bookIDs[i] == id) {
									found = i;
									break;
								}
							}
							if (found != -1) {
								cout << "\xB2\xB2\xB2\xB2\xB2 Book Found!\xB2\xB2\xB2\xB2\xB2\n\n\xB2\xB2\xB2\xB2\xB2 1.Book Name: " << booknames[found] << "\n\n\xB2\xB2\xB2\xB2\xB2 2.Book ID: " << bookIDs[found];
								cout << "\n\n\xB2\xB2\xB2\xB2\xB2 3.Quantity: " << quantity[found] << "\n\n\xB2\xB2\xB2\xB2\xB2 4.Edition: " << edition[found] << "\n\n";
							}
							else {
								cout << "\xB2\xB2\xB2\xB2\xB2 Book not Found!";
							}
						}
						else {
							cout << "\xB2\xB2\xB2\xB2\xB2 No available book to search!\n\n";
						}
						break;
					case 3:      //BORROW BOOK
						int id, found = -1;
						string rollno, section,department;
						if (totalbooks > 0) {
							cout << "Enter your Roll No:";
							cin >> rollno;
							cout << "Enter your department:";
							cin >> department;
							cout << "Enter your Section:";
							cin >> section;
							cout << "Enter Book ID:";
							cin >> id;
							for (int i = 0;i < totalbooks;i++) {
								if (bookIDs[i] == id) {
									found = i;
									break;
								}
							}
							if (found != -1) {
								cout << "\xB2\xB2\xB2\xB2\xB2 Book Found! \xB2\xB2\xB2\xB2\xB2\n\n";
								cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Book Issue Slip \xB2\xB2\xB2\xB2\xB2\xB2\n\n\xB2\xB2\xB2\xB2\xB2 1.Student Roll NO:" << rollno << "\n\n\xB2\xB2\xB2\xB2\xB2 2.Student Departent:"<<department<<"\n\n\xB2\xB2\xB2\xB2\xB2 3.Student Section:"<<section;
								cout<<"\n\n\xB2\xB2\xB2\xB2\xB2 4.Book Name: " << booknames[found] << "\n\n\xB2\xB2\xB2\xB2\xB2 5.Book ID: " << bookIDs[found];
								cout << "\n\n\xB2\xB2\xB2\xB2\xB2 6.Edition: " << edition[found] << "\n\n";
								cout << "Book Granted for 7 Days.\n\n";
								cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
								cout << "Important Note: If book is not returned within 7 days then Fine of (RS 200 Per Day) will be charged\n\n";
								quantity[found] -= 1;
							}
							else {
								cout << "\xB2\xB2\xB2\xB2\xB2 Book Not found!\n\n";
							}
						}
						else {
							cout << "\xB2\xB2\xB2\xB2\xB2 No, Book available!\n\n";
						}
						break;
					}
				}
				else {
					cout << "\xB2\xB2\xB2\xB2\xB2 Incorrect Password. Try Again!\n\n";
				}
				break;
			}
	} while (option != 0);
}