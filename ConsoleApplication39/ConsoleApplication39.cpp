#include <iostream>
#include <cstring>
using namespace std;

const int maxBookCount = 100;
class Book
{
private:
	char* bookname;
	char* author;
public:
	Book(const char* bookname_, const char* author_) : bookname{ new char[strlen(bookname_) + 1] }, author{ new char[strlen(author_) + 1] } {
	for (int i = 0; i < strlen(bookname_) + 1; i++)
		{
		this->bookname[i] = bookname_[i];
		}
	for (int i = 0; i < strlen(author_)+1; i++)
	{
		this->author[i] = author_[i];
	}
	}
	Book(const char* bookname_) : Book(bookname_, "") {

	}
	Book(): Book(""){}
	char* getBookName() const {
		return bookname;
}
	char* getAuthor() const {
		return author;
	}
	void setBookname(char* bookname_) {
		for (int i = 0; i < strlen(bookname_) + 1; i++)
		{
			this->bookname[i] = bookname_[i];
		}
	}
	void setAuthor(char* author_) {
		for (int i = 0; i < strlen(author_) + 1; i++)
		{
			this->author[i] = author_[i];
		}
	}
	~Book(){
		if (author!=nullptr)
		{
			delete[]author;
		}
		if (bookname!=nullptr)
		{
			delete[]bookname;
		}
	}
	void displayBooks()
	{
		cout << "Title: " << bookname<<"\n";
		cout << "Author: " << author<<"\n";
	}
};

class Library {
public:
	static Book books[maxBookCount];
	static int bookCount;
	static int newBookcount;
	static void addBook(Book& book_);
	void deleteBook(char* bookname)
	{
		int removedCount = 0;
		for (int i = 0; i < newBookcount; ++i)
		{
			if (strcmp(books[i].getBookName(), bookname) == 0)
			{
				for (int j = i; j < newBookcount - 1; ++j)
				{
					books[j] = books[j + 1];
				}
				--newBookcount;
				++removedCount;
				--i;
				cout << "Contact deleted." << endl;
				break;
			}
		}

		if (removedCount == 0)
		{
			cout << "Contact n found." << endl;
		}
	}
	static void displayBook(const Book& book_);
};
void Library::addBook(Book& book_) 
{
	if (bookCount < maxBookCount) {
		cout << " Enter new book author: \n";
		char author[100];
		cin >> author;
		books[newBookcount].setAuthor(author);
		cout << "Enter new book name: \n";
		char bookname[100];
		cin >> bookname;
		books[newBookcount].setBookname(bookname);
		cout << "Book added \n";
		bookCount++; 
		newBookcount++;
	}
	else {
		cout << "Library is full\n";
	}
}


void Library::displayBook(const Book& book_)
{
	for (int i = 0; i < newBookcount; i++) 
	{
		books[i].displayBooks();
	}
}

int Library::newBookcount = 0;
int Library::bookCount = 10;
Book Library::books[maxBookCount];
int main() {
	Book books;
	Library library;
	while (true)
	{
		cout << "_______________________" << endl;
		cout << "Welcome to Library!" << endl;
		cout << "Press 1 to add Book" << endl;
		cout << "Press 2 to delete Book" << endl;
		cout << "Press 3 to display all books" << endl;
		cout << "Press 4 to exit from library" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: 
			library.addBook(books);
			break;
		case 2: 
			char Bookname[100];
			cout << "Enter Book title to delete " << endl;
			cin >> Bookname;
			library.deleteBook(Bookname);
			break;
		case 3:
			library.displayBook(books);
			break;

		case 4:
			cout << "Exiting from library. Be safe!\n";
			return 0;
		}
	}
}

