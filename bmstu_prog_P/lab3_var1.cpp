#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct Book {
    string title;
    string author;
    short year;
};


void AddtoFile(const string& s) {
    ofstream OutFile("output.txt", ios::app);

    if (OutFile.is_open()) {
        OutFile << s << "\n";
    }

    OutFile.close();
}


short Opr() {
    short n = 0;

    cout << "Choose option: \n";

    cout << "1. Add books\n";
    cout << "2. Search by title\n";
    cout << "3. Sort books\n";
    cout << "4. Add book to the end\n";
    cout << "5. Search by year\n";
    cout << "6. Exit\n";

    cout << "7. Show all books\n";
    cout << "8. Show output\n";

    cout << "Choose your variant: ";
    cin >> n;
    cin.ignore();

    return n;
}


void ShowAllBooks() {
    ifstream inFile("books.txt");

    if (inFile.fail()) {
        cout << "Error\n";
        return;
    }

    string line;
    short count = 0;
    string output = "\n All books \n";

    while (getline(inFile, line)) {
        count++;
        cout << count << ": " << line << endl;
        output += to_string(count) + ": " + line + "\n";
    }

    if (count == 0) {
        cout << "No books found\n";
        output += "No books found\n";
    }

    AddtoFile(output);
    inFile.close();
}


void ShowOutput() {
    ifstream inFile("output.txt");

    if (inFile.fail()) {
        cout << "Error";
        return;
    }

    string line;

    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}


void add() {
    ofstream outFile("books.txt", ios::app);

    if (outFile.fail()) {
        cout << "Error with open\n";
        return;
    }

    string output = "\n Adding books \n";
    cout << output;

    AddtoFile(output);

    while (true) {
        string title, author;
        short year = 0;

        cout << "Enter title of book (empty to exit): ";
        getline(cin, title);

        if (title.empty()) {
            break;
        }

        cout << "Enter author of book: ";
        getline(cin, author);

        cout << "Enter year of release: ";
        cin >> year;

        cin.ignore();

        outFile << title << ":" << author << ", " << year << "\n";

        string added = "Added: " + title + ":" + author + ", " + to_string(year);
        cout << added << endl;

        AddtoFile(added);
    }

    outFile.close();
}


void SearchByTitle() {
    ifstream inFile("books.txt");

    if (inFile.fail()) {
        cout << "Error with open\n";
        return;
    }

    string name, line;
    cout << "Enter title to search: ";
    getline(cin, name);

    bool found = false;
    string output = "\n    Search results for '" + name + "'    \n";

    while (getline(inFile, line)) {
        size_t pos = line.find(':');

        if (pos != string::npos) {
            string title = line.substr(0, pos);
            if (title == name) {
                output += "Found: " + line + "\n";
                cout << "Result: " << line << "\n";
                found = true;
            }
        }
    } cout << "\n";

    if (!found) {
        output += "Book not found\n";
        cout << "Book not found\n";
    }

    AddtoFile(output);

    inFile.close();
}


void SortByPar() {
    ifstream inFile("books.txt");

    if (inFile.fail()) {
        cout << "Error with open\n";
        return;
    }

    vector<Book> books;
    string line;

    while (getline(inFile, line)) {

        size_t Pos = line.find(':');
        size_t commaPos = line.find(',', Pos + 1);

        if (Pos != string::npos && commaPos != string::npos) {
            Book book;
            book.title = line.substr(0, Pos);
            book.author = line.substr(Pos + 1, commaPos - Pos - 1);
            book.year = stoi(line.substr(commaPos + 1));

            books.push_back(book);
        }
    }

    inFile.close();

    if (books.empty()) {
        cout << "No books to sort\n";
        return;
    }

    short type = 0;

    cout << "\nChoose type of sort:\n";
    cout << "Search by author(1)\n";
    cout << "Search by year of release(2)\n";
    cout << "Choose your variant: ";
    cin >> type;
    cin.ignore();

    switch (type) {
    case 1:
        sort(books.begin(), books.end(), [](Book& x, Book& y) {
            return x.author < y.author;
            });
        break;
    case 2:
        sort(books.begin(), books.end(), [](Book& x, Book& y) {
            return x.year < y.year;
            });
        break;
    default:
        cout << "Invalid choice\n";
        return;
    }

    ofstream outFile("books.txt");

    if (outFile.fail()) {
        cout << "Error with open\n";
        return;
    }

    string sorted = "\n Sorted books \n";

    for (auto& book : books) {
        string bookEntry = book.title + ":" + book.author + ", " + to_string(book.year);
        outFile << bookEntry << "\n";
        sorted += bookEntry + "\n";
    }

    cout << sorted;

    AddtoFile(sorted);
    outFile.close();
}


void addtheend() {
    ofstream outFile("books.txt", ios::app);

    if (outFile.fail()) {
        cout << "Error with open\n";
        return;
    }

    string title, author;
    short year = 0;

    cout << "\nEnter information about book:\n";

    cout << "Enter title: ";
    getline(cin, title);

    cout << "Enter author: ";
    getline(cin, author);

    cout << "Enter year of release: ";
    cin >> year;
    cin.ignore();

    outFile << title << ":" << author << ", " << year << "\n";

    string s = "Added to end: " + title + ":" + author + ", " + to_string(year);
    cout << s << endl;
    AddtoFile(s);

    outFile.close();
}


void SearchByYear() {
    ifstream inFile("books.txt");

    if (inFile.fail()) {
        cout << "Error with open\n";
        return;
    }

    short year = 0;

    cout << "\nEnter maximum year: ";
    cin >> year;
    cin.ignore();

    string line;
    bool found = false;
    string output = "\n Books released before " + to_string(year) + " \n";

    while (getline(inFile, line)) {
        size_t pos = line.find_last_of(',');

        if (pos != string::npos) {
            short year_of_book = stoi(line.substr(pos + 1));
            if (year_of_book <= year) {
                output += line + "\n";
                found = true;
            }
        }
    }

    if (!found) {
        output += "No books found\n";
    }

    cout << output;

    AddtoFile(output);
    inFile.close();
}


int main() {
    short n = 0;

    ofstream clearFile("output.txt");
    clearFile.close();

    do {
        n = Opr();

        switch (n) {
        case 1:
            add();
            break;
        case 2:
            SearchByTitle();
            break;
        case 3:
            SortByPar();
            break;
        case 4:
            addtheend();
            break;
        case 5:
            SearchByYear();
            break;
        case 6:
            cout << "The end!\n";
            AddtoFile("The end!");
            return 0;
        case 7:
            ShowAllBooks();
            break;
        case 8:
            ShowOutput();
            break;
        default:
            cout << "Invalid Value\n";
            break;
        }
    } while (n != 6);

    return 0;
}
