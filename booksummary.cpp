#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <ShellApi.h>
using namespace std;

int main() {
	//Variables 
	string book_title;
	string author;
	int num_chapters;
	char option;		//Whether they chose new/existing template
	string trash;		//Clean up whitespace
	char close;			
	string path = "C:\\Users\\Varun\\Desktop\\Book Summaries\\";	//Path then append the book title here
		//(path + book_title + ".txt").c_str()


	//Ask if they want to open an already made summary file	
	cout << "Welcome to the Book Refresher" << endl;
	cout << "Would you like to create a new template or open an existing template?" << endl;
	cout << "'N': New template \n'E': Existing template" << endl;
	cin >> option;
	getline(cin, trash);	//Eat up the whitespace

	//Get book title 
	if (option == 'N') {
		cout << "Enter the book title:" << endl;
		getline(cin, book_title);

		//Get book author
		cout << "Enter the author:" << endl;
		getline(cin, author);

		//Get the number of chapters
		cout << "Enter the number of chapters:" << endl;
		cin >> num_chapters;

		//Now import this information into a text file
		std::ofstream file(book_title + ".txt");	//Creates a txt file that is named the book's title
		//Add information into the file
		file << book_title << std::endl;					//Firest line is Book name
		file << author << "\n"<< std::endl;					//Second line is Author
		file << "Summary of chapters:" << std::endl;		//General prompt

		//Create a list of ascending chapter numbers
		for (int i = 1; i <= num_chapters; i++) {
			string chap = std::to_string(i);
			file << "Chapter " << chap << ": \n"<< std::endl;
		}

		cout << "File has been created in your project directory" << endl;

	} else if(option == 'E') {
		//Search the folder for the booksummary file.
		cout << "What book are you looking for?" << endl;
		getline(cin, book_title);

		//Trying to open the file up
		ShellExecute(NULL, "open", (path + book_title + ".txt").c_str(), NULL, NULL, SW_SHOWNORMAL);	
	}

	return 0;
}