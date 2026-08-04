#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    void getPublication() {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter Price: ";
        cin >> price;
        if (price < 0) {
            throw price;
        }
    }

    void displayPublication() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

    void resetPublication() {
        title = "0";
        price = 0;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    void getData() {
        try {
            getPublication();
            cout << "Enter Page Count: ";
            cin >> pageCount;
            if (pageCount < 0) {
                throw pageCount;
            }
        }
        catch (...) {
            cout << "invalid \n";
            resetPublication();
            pageCount = 0;
        }
    }

    void displayData() {
        cout << "\nBook detail\n";
        displayPublication();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playTime;

public:
    void getData() {
        try {
            getPublication();
            cout << "Enter playing time: ";
            cin >> playTime;
            if (playTime < 0) {
                throw playTime;
            }
        }
        catch (...) {
            cout << "\ninvalid\n";
            resetPublication();
            playTime = 0;
        }
    }

    void displayData() {
        cout << "\nTape detail" << endl;
        displayPublication();
        cout << "Playing Time: " << playTime << " minutes" << endl;
    }
};
int main() {
    Book b;
    Tape t;

    cout << "Enter Book Detail\n";
    b.getData();

    cout << "Enter Tape Detail \n";
    t.getData();

    cout << "\nPublication information:\n";
    b.displayData();
    t.displayData();

    return 0;
}
