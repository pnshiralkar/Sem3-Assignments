/*
Book shop maintains inventory of books that are being sold at shop. List inculedes details such as title, author, publisher,ISBN No., price & available stock.
Write a program in C++ which will have class 'Books' wih suitable data & memberfuncs - 1.add 2.update 3.search 4.purchase book(update stock and display cost).
Record No. of successful & unseccessful transactions(use static data-members to keep track of transactions)
Use new operator in constructor to allocate reqd mem
Search based on 1.ISBN, 2.Author, 3.Name
Last date - 13/7/2019
*/

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class Book{
    char *title, *author, *pub, *isbn;
    float  *price;
    int *stock;
    
    public:
    static int s,us;
    Book()
    {
        title = new char[50];
        author = new char[50];
        pub = new char[50];
        isbn = new char[15];
        price = new float;
        stock = new int;
    }
    static void trans()
    {
    	cout << "Seccessful transactions : " << s << "\nUnsuccessful transactions : " << us << endl;
    }
    int checktitle(char t[50])
    {
    	if(!strcmp(title, t))
    		return 1;
    	return 0;
    }
    int checkauthor(char t[50])
    {
    	if(!strcmp(author, t))
    		return 1;
    	return 0;
    }
    int checkisbn(char t[50])
    {
    	if(!strcmp(isbn, t))
    		return 1;
    	return 0;
    }
    void add()
    {
    	cout << "Enter details of book you want to add:\n\tTitle : ";
    	cin >> title;
    	cout << "\tAuthor : ";
    	cin >> author;
    	cout << "\tPublisher : ";
    	cin >> pub;
    	cout << "\tISBN No. : ";
    	cin >> isbn;
    	cout << "\tPrice : ";
    	cin >> *price;
    	cout << "\tAvailable stock : ";
    	cin >> *stock;
    }
    
    void update()
    {
    	cout << "Enter new details of the book : \n\tTitle : ";
    	cin >> title;
    	cout << "\tAuthor : ";
    	cin >> author;
    	cout << "\tPublisher : ";
    	cin >> pub;
    	cout << "\tISBN No. : ";
    	cin >> isbn;
    	cout << "\tPrice : ";
    	cin >> *price;
    	cout << "\tAvailable stock : ";
    	cin >> *stock;
    }
    
    void purchase(int n)
    {
    	if(n <= *stock){
			*stock-=n;
			s++;
			cout << "Transacion successful!";
		}else{
			cout << "Insufficient stock available for given qty!\nTransaction unsuccessful";
			us++;
		}
    }
    
    void disp()
    {
    	cout << "\n\tTitle : " << title << "\n\tAuthor : " << author << "\n\tPublisher : " << pub << "\n\tISBN No. : " << isbn << "\n\tPrice : " << *price << "\n\tAvailable Sock : "<< *stock << endl;
    }
};

int Book::s;
int Book::us;

void update(Book *b, int n)
{	int i;
	char title[50];
    cout << "Enter title of book you want to update : ";
    cin >> title;
    for(i=0;i<n;i++)
    	if(b[i].checktitle(title))
    	{
    		b[i].update();
    		b[i].disp();
    		break;
    	}
    if(i==n)
    	cout << "No book with the given title!\n";
}

void search(Book *b, int n)
{
	int r,f=0;
	char inp[50];
	cout << "Search a book by?\n  1.ISBN No.\n  2.Author\n  3.Title\nEnter a choice : ";
	cin >> r;
	switch(r)
	{
		case 1:
			cout << "Enter ISBN No. of book to search : ";
			cin >> inp;
			for(int i=0;i<n;i++)
				if(b[i].checkisbn(inp)){
					f=1;
					cout << "Book found : \n";
					b[i].disp();
				}
			if(!f)
				cout << "No book found with the given ISBN No.!\n";
			break;
		case 2:
			cout << "Enter Author of book to search : ";
			cin >> inp;
			for(int i=0;i<n;i++)
				if(b[i].checkauthor(inp)){
					f=1;
					cout << "Book found : \n";
					b[i].disp();
				}
			if(!f)
				cout << "No book found with the given Author!\n";
			break;
		case 3:
			cout << "Enter Title of book to search : ";
			cin >> inp;
			for(int i=0;i<n;i++)
				if(b[i].checktitle(inp)){
					f=1;
					cout << "Book found : \n";
					b[i].disp();
				}
			if(!f)
				cout << "No book found with the given Title!\n";
			break;
		default:
			cout << "Please Enter a valid choice!";
			search(b, n);
	}
}

int search(int n, Book *b)
{
	int f=0;
	char inp[50];
	cout << "Enter ISBN No. of book to purchase : ";
	cin >> inp;
	for(int i=0;i<n;i++)
		if(b[i].checkisbn(inp)){
			f=1;
			cout << "Book found : \n";
			b[i].disp();
			return i;
		}
	cout << "No book found with the given ISBN No.!\n";
	return -1;
}

int menu()
{
	int i;
	cout << "\n\n******Bookstore Inventory******\n\n\t1.Add new book\n\t2.Update existing book\n\t3.Search a book in inventory\n\t4.Purchase Book\n\t5.Transaction history\n\t6.Exit\nEnter your choice : ";
	cin >> i;
	cout << endl << endl;
	return i; 
}

int main()
{
	int n=0,f=1,i,p;
    Book book[50];
    while(f)
    {
		switch(menu())
		{
			case 1:
				book[n++].add();
				break;
			case 2:
				i = search(n, book);
				if(i>=0)
					book[i].update();
				break;
			case 3:
				search(book,n);
				break;
			case 4:
				i = search(n, book);
				if(i>=0){
					cout << "Enter No. of copies to purchase : ";
					cin >> p;
					book[i].purchase(p);
				}
				break;
			case 5:
				Book::trans();
				break;
			default:
				f=0;
		}
    }
    return 0;
}
