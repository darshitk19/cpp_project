#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book
{
private:
    string title;
    string author;
    int id;
public:
    Book(string title, string author, int id) : title(title), author(author), id(id) {}

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    int getId() const
    {
        return id;
    }
};

class Library
{
private:
    vector<Book> books;
public:
    void addBook(const Book& book)
    {
        books.push_back(book);
    }

    void removeBook(int id)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
        {
            if (it->getId() == id)
            {
                books.erase(it);
                cout<<"Removed your book successfully"<<endl;
                cout<<endl;
                return;
            }
        } cout<<endl;
        cout << "Book with ID " << id << " not found in library." << endl;
    }

    void displayBooks() const
    {
        {
            cout<<endl;
            cout << "------Books in the library------ " << endl;
        }

        for (const Book& book : books)
        {

            cout << "Title:- "<< book.getTitle()<<endl<< " Author:- "<< book.getAuthor()<<endl<< " ID:- "<< book.getId() << endl;
            cout<<endl;
        }
    }
};

int main()
{
    Library library;

    int choice;
    while (true)
    {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Display Books" << endl;
        cout << "4. Exit" << endl;
        cout<<endl;
        cout<<" ====================="<<endl;
        cout <<"* Enter your choice *"<<endl;
        cout<<" ====================="<<endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string title, author;
            int id;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ID: ";
            cin >> id;
            Book book(title, author, id);
            library.addBook(book);
            cout << "Book added successfully." << endl;
            cout<<endl;
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter ID of book to remove: ";
            cin >> id;
            library.removeBook(id);
            break;
        }
        case 3:
            library.displayBooks();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
