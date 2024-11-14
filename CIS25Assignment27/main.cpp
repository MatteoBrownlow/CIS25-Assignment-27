#include <iostream>
using namespace std;

struct authorFullName{
    string firstName;
    string lastName;
};
struct book{
    authorFullName author;
    string title;
    int price;
    int howManyInStock;
    int yearPublished;
};

ostream& operator << (ostream& stream, book currentBook){
    cout << currentBook.title << " (" << currentBook.yearPublished << "), by " << currentBook.author.firstName << " " << currentBook.author.lastName << ". There are " << currentBook.howManyInStock << " copies in store, for $" << currentBook.price << ".";
    return stream;
}

int main(){
    int choice = 0;
    int books = 0;
    string authorFirstAndLast = "\0";
    int space = 0;
    int fullNameLength = 0;
    string firstName = "\0";
    string lastName = "\0";
    string title = "\0";
    int price = 0;
    int numberOfCopies = 0;
    int yearPublished = 0;
    int inventoryUpdate = 0;
    book* bookArray = new book[books];
    while(true){
        while(true){
            cout << "Add a book(1), find a book(2), or update inventory(3): " << endl;
            cin >> choice;
            if (cin.fail() || (choice != 1 && choice != 2 && choice != 3)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
        if(choice == 1){
            books++;
            cout << "What is the title?" << endl;
            getline(cin >> ws, title);
            
            cout << "Enter the author's first and last name:" << endl;
            getline(cin >> ws, authorFirstAndLast);
            while(true){
                if(authorFirstAndLast[space] == ' '){
                    break;
                }
                space++;
            }
            while(true){
                if(authorFirstAndLast[fullNameLength] == '\0'){
                    break;
                }
                fullNameLength++;
            }
            firstName = authorFirstAndLast.substr(0, space);
            lastName = authorFirstAndLast.substr(space, fullNameLength - 1);
            
            cout << "Enter the price:" << endl;
            cin >> price;
            cout << "How many copies are in stock?" << endl;
            cin >> numberOfCopies;
            cout << "What is the year of publication?" << endl;
            cin >> yearPublished;
            bookArray[books - 1] = {firstName, lastName, title, price, numberOfCopies, yearPublished};
            
            choice = 0;
            authorFirstAndLast = "\0";
            space = 0;
            fullNameLength = 0;
            firstName = "\0";
            lastName = "\0";
            title = "\0";
            price = 0;
            numberOfCopies = 0;
            int yearPublished = 0;
        }
        if(choice == 2){
            cout << "What is the title?" << endl;
            getline(cin >> ws, title);
            for(int i = 0; i < books; i++){
                if(bookArray[i].title == title){
                    cout << bookArray[i] << endl;
                }
            }
            title = "\0";
            choice = 0;
        }
        if(choice == 3){
            choice = 0;
            cout << "Enter the title:" << endl;
            getline(cin >> ws, title);
            for(int j = 0; j < books; j++){
                if(bookArray[j].title == title){
                    cout << bookArray[j] << endl;
                    cout << "Is the quantity going up(1) or down(2)?" << endl;
                    cin >> choice;
                    if(choice == 1){
                        choice = 0;
                        cout << "How many more copies?" << endl;
                        cin >> inventoryUpdate;
                        bookArray[j].howManyInStock += inventoryUpdate;
                        cout << "Updated. Threre are now " << bookArray[j].howManyInStock << " copies in stock." << endl;
                        inventoryUpdate = 0;
                    }
                    if(choice == 2){
                        choice = 0;
                        do{
                            if(inventoryUpdate > bookArray[j].howManyInStock){
                                cout << "There are only " << bookArray[j].howManyInStock << " copies in the store" << endl;
                            }
                            cout << "How many less copies?" << endl;
                            cin >> inventoryUpdate;
                        }while(inventoryUpdate > bookArray[j].howManyInStock);
                        
                        for(int k = 0; k < inventoryUpdate; k++){
                            bookArray[j].howManyInStock--;
                            if(k == inventoryUpdate - 1){
                                cout << "Updated. There are now " << bookArray[j].howManyInStock << " copies in stock." << endl;
                            }
                        }
                        
                        inventoryUpdate = 0;
                    }
                }
            }
        }
    }
    delete[] bookArray;
    bookArray = NULL;
    return 0;
}
