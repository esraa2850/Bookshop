#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Data.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::shared_ptr;



// Global vector to hold objects


// Book
struct Book {
    string title;
    string type;
    double price;
    string author;
    string code;
};

//User system
struct User {

	string username;
	string fullName;
	string email;
	string haspassword;
} ;

using std::ios;
using std::stringstream;

vector<Book> books;
vector<User> user;
vector<User> admin;


/*
data-->>book
data-->>user
data-->>admin
add books to my list
view my list
favourit
install
review -->book
*/

// Method prototypes  ->>>Book
void add_book();
void view_books( vector<Book> &mybooks);
void view_books_for_users( vector<Book> &mybooks);
void search_book(vector<Book> &search_book);
void delete_book(vector<Book>&del_book);
void updata_book(vector<Book>&updata_book);

// Methods for all users
int getIndex(int role, string username);
void admin_logup(int role);
void admin_login(int role);
string getPassword();
void smallmain(int role);
void loginMenu(int role, string username);
int welcom_menu();

//methods of admin
void log_out_admin();
bool verifyAdminrData(string username, string password);
void admin_Menu(int id);

//Methods for user
void log_out_user(int id);
void user_Menu(int id);
bool verifyUserData(string username, string password);

//Main
int main() {
    cout<<"\n---->>Welcome in Book Shop Project<----\n";
    welcom_menu();
    return 0;
}


//Start Methods -->>Book
//Add book
void add_book() {
    Book newBook; // Create a new Book object
    cout << "\nPlease enter the following information:\n";

    cout << "Title: ";
    getline(cin >> std::ws, newBook.title);

    cout << "Type: ";
    getline(cin >> std::ws, newBook.type);

    cout << "Author: ";
    getline(cin >> std::ws, newBook.author);

    cout << "Code: ";
    getline(cin >> std::ws, newBook.code);

    cout << "Price: ";
    cin >> newBook.price; // Read price directly into newBook.price

    books.push_back(newBook); // Add newBook to the global vector
    cout << "Book added successfully\n";
}

//view book
void view_books( vector<Book> &mybooks) {
    if(mybooks.empty())
    {
        cout<<"There isn't books\n";
    }
    else{
    cout<<"=================================================================================\n";
     cout<<"Number\tTitle\tCode\tAuthor\tType\tPrice\n";
      int i=1;
    for (const auto &book : mybooks) {
        cout<<i<<"\t"<< book.title
             << "\t" << book.code
             << "\t" << book.author
             << "\t" << book.type
             << "\t" << book.price<<'\n';
         i++;
    }
    cout<<"=================================================================================\n";
    }
}

//for users
void view_books_for_users( vector<Book> &mybooks)
{
     cout<<"=================================================================================\n";
     cout<<"Number\tTitle\tCode\tAuthor\tType\tPrice\n";
      int i=1;
    for (const auto &book : mybooks) {
        cout<<i<<"\t"<< book.title
             << "\t" << book.code
             << "\t" << book.author
             << "\t" << book.type
             << "\t" << book.price
             << '\n';
         i++;
    }
    cout<<"=================================================================================\n";
}

//delete
void delete_book( vector<Book>&del_book)
{
    string decode;
    cout<<"Enter code of Book to delete:";
    cin>>decode;
    //search book
    bool found_book=1;
    for (auto it = del_book.begin(); it != del_book.end(); ++it)
    {
        if(it->code == decode)
        {    found_book=0;
             cout << "Title: " << it->title
             << ", Type: " << it->type
             << ", Author: " << it->author
             << ", Code: " << it->code
             << ", Price: " << it->price<< '\n';
             int t;
             cout<<"are you sure 1:Yes 2:No  :";
             cin>>t;
             if(1==t)
             {
                 del_book.erase(it);
                 cout<<"Book deleted  successfully\n";
                 break;
             }
             else
                break;
        }
    }
    if(found_book)
    cout << "Book not found.\n";

}

//updata
void updata_book(vector<Book>&updata_book)
{
    string decode;
    cout<<"Enter code of Book to updata:";
    cin>>decode;
    //search book
    bool found_book=1;
    for (auto it = (updata_book.begin()); it != updata_book.end(); ++it)
    {
        if(it->code == decode)
        {
             found_book=0;
             cout << "Title: " << it->title
             << ", Type: " << it->type
             << ", Author: " << it->author
             << ", Code: " << it->code
             << ", Price: " << it->price
             << '\n';
             cout<<"Enter the new data\n";
             Book data;
              cout << "Title: ";
              getline(cin >> std::ws, it->title);

              cout << "Type: ";
              getline(cin >> std::ws, it->type);

              cout << "Author: ";
              getline(cin >> std::ws, it->author);

              cout << "Code: ";
              getline(cin >> std::ws, it->code);

              cout << "Price: ";
              cin >> it->price; // Read price directly into newBook.price

             cout<<"updata  successfully\n";
             view_books(updata_book);
             break;
        }
    }
        if(found_book)
           cout << "Book not found.\n";
}

//search
void search_book(vector<Book> &search_book)
{
    again:
    cout<<"Search by\n";
    cout<<"1. Title\n";
    cout<<"2. Author\n";
    cout<<"\nEnter your choice:";
    int value;
    cin>>value;
    if(value==1)
    {
        bool found_book=1;
        cout<<"Enter Title:";
        string title;
        cin>>title;
        for (auto it = search_book.begin(); it != search_book.end(); ++it)
         {
             if(it->title == title)
             {    found_book=0;
                  cout << "Title: " << it->title
                  << ", Type: " << it->type
                  << ", Author: " << it->author
                  << ", Code: " << it->code
                  << ", Price: " << it->price
                  << '\n';
             }
         }
         if(found_book)
         {
             cout<<"there isn't book whit this Title\n";
         }

    }

    else if(value==2)
    {
        string au;
        bool found_book=1;
        cout<<"Enter author:";
        cin>>au;
         for (auto it = search_book.begin(); it != search_book.end(); ++it)
         {
            if(it->author == au)
            {    found_book=0;
                 cout << "Title: " << it->title
                 << ", Type: " << it->type
                 << ", Author: " << it->author
                 << ", Code: " << it->code
                 << ", Price: " << it->price
                 << '\n';
            }
         }
         if(found_book)
         {
             cout<<"there isn't book whit this author\n";

         }
    }
    else{
        cout<<"Please Enter 1 or 2 \t";
        goto again;
    }

}
// end Methods books

//start Methods of users
//logup-->admin
void admin_logup(int role)
{
    User info;
    string password;
	cout << "\nPlease enter the following information:\n";

	cout << "Full Name: ";
	getline(cin >> std::ws, info.fullName);

	cout << "E-mail: ";
	cin >> info.email;

	cout << "Username: ";
	cin >> info.username;

	cout << "Password: ";
	password = getPassword();


    // Check if this user already exist
    if (role ==1 && !verifyAdminrData(info.username, password)) {
        admin.push_back(info);
        admin_Menu(getIndex(role, info.username));
    }
     else if (role == 2 && !verifyUserData(info.username, password)) {
        user.push_back(info);
        user_Menu(getIndex(role, info.username));
    }
     else {
        cout << "This user already exist\n";
        return;
    }
}

//// Check if this admin already exist
bool verifyAdminrData(string username, string password)
{
    for (auto admi: admin) {
        if (username == admi.username && password == admi.haspassword) {
            return true;
        }
    }
    return false;
}
string getPassword()
{
    again:
    string pass;
    cin>>pass;
    if(pass.size()!=8)
    {
        cout<<"password must be 8 characters\nTry again:";
        goto again;
    }
    else
        return pass;
}

bool verifyUserData(string username, string password)
{
    for(auto userr:user){
        if(username ==userr.username && password == userr.haspassword)
            return true;
    }
    return false;
}
void smallmain(int role)
{
    cout<<"1.Sign UP\n2.Sing In \n";
    int t;
    again:
    cout<<"Enter Your choice:";
    cin>>t;
    if(t==1){
        admin_logup(role);
    }
    else if(t==2)
        admin_login(role);
    else{
        cout<<"ERROR: Out of range, Try again\n";
        goto again;
    }
}
void admin_login(int role)
{
    string username, password;
	cout << "\nPlease enter the following information:\n";

	cout << "Username: ";
	cin >> username;

	cout << "Password: ";
	password = getPassword();

    // Verify username and password
    if (role == 1 && verifyAdminrData(username, password)) {
        loginMenu(role, username);
    }
    else if (role == 2 && verifyUserData(username, password)) {
        loginMenu(role, username);
    } else {
        cout << "Username or Password Incorect\n";
    }
}



int getIndex(int role, string username) {
    if (role == 1) {
        for (int i = 0; i < admin.size(); i++) {
            if (admin[i].username == username)
                return i;
        }
    } else if (role == 2) {
        for (int i = 0; i < user.size(); i++) {
            if (user[i].username == username)
                return i;
        }
    }

	return -1;
}
//main menu for admin
void admin_Menu(int id)
{
    int operation = -1;
    while (operation) {
            vector <string> menu = {"Add Book", "View Books", "Up Data Book", "Delete Book", "log out"};
            for(int i=1;i<=menu.size();i++)
            {
                 cout<<i<<". "<<menu[i-1]<<"\n";
            }
            cout<<"Enter your choice:";
            cin>>operation;

            switch (operation) {
            case 1:
                add_book();
                break;
            case 2:
                view_books(books);
                break;
            case 3:
                updata_book(books);
                break;
            case 4:
                delete_book(books);
                break;
            case 5:
                operation=0;
                log_out_admin();
                break;
        }
    }
}
//main menu

void user_Menu(int id)
{
    int operation = -1;
    while (operation) {
            vector <string> menu = {"Search", "View My List books", "View Books", "Log out"};
            for(int i=1;i<=menu.size();i++)
            {
                 cout<<i<<". "<<menu[i-1]<<"\n";
            }
            cout<<"Enter your choice:";
            cin>>operation;

            switch (operation) {
            case 1:
                search_book(books);
                break;
            case 2:
                //view_mylistbooks();
                break;
            case 3:
                view_books(books);
                break;
            case 4:
                operation=0;
                log_out_user(id);
                break;
        }
    }
}

void loginMenu(int role, string username) {
    cout << "\n\nWelcome " << username << " you are logged in\n";
	if (role == 1)
		admin_Menu(getIndex(role, username));
	else if (role == 2)
		user_Menu(getIndex(role, username));
}
int welcom_menu()
{
    again:
    int operation=-1;
    cout<<"1. admin\n";
    cout<<"2. user\n";
    cout<<"3. Exit\n";
    cout<<"Enter Your choice:";
    cin>>operation;
    if(operation==1)
        smallmain(1);
    else if(operation==2)
        smallmain(2);
    else if(operation==3)
        return 0;
    else
    {
        cout<<"ERROR: Out of range, Try again\n";
        goto again;
    }
}
void log_out_admin()
{
   cout<<"Are You need save data: 1->Yes  2->No :";
   int value;
   cin>>value;
   if(value==1)
   {
       value++;
       welcom_menu();
   }
   else
   {
       welcom_menu();
   }
}

void log_out_user(int id)
{
    cout<<"Are You need save data: 1->Yes  2->No :";
   int value;
   cin>>value;
   if(value==1)
   {
       value++;
       welcom_menu();
   }
   else
   {
       welcom_menu();
   }
}
