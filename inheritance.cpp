#include <iostream>
#include <string>

using namespace std;

// Base class
class Publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: $";
        cin >> price;
        cin.ignore(); // to clear the newline character from the input buffer
    }

    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

// Derived class for books
class Book : public Publication {
private:
    int page_count;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
        cin.ignore();
    }

    void putdata() const {
        Publication::putdata();//calling the base class function
        cout << "Page count: " << page_count << endl;
    }
};

// Derived class for tapes
class Tape : public Publication {
private:
    float playing_time;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter playing time (minutes): ";
        cin >> playing_time;
        cin.ignore();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Playing time: " << playing_time << " minutes" << endl;
    }
};

// Main program
int main() {
    Book book;
    Tape tape;

    cout << "\nEnter data for book:" << endl;
    book.getdata();

    cout << "\nEnter data for tape:" << endl;
    tape.getdata();

    cout << "\nBook Information:" << endl;
    book.putdata();

    cout << "\nTape Information:" << endl;
    tape.putdata();

    return 0;
}
