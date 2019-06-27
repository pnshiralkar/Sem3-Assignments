/*
Book shop maintains inventory of books that are being sold at shop. List inculedes details such as title, author, publisher, price & available stock.
Write a program in C++ which will have class 'Books' wih suitable data & memberfuncs - 1.add 2.update 3.search 4.purchase book(update stock and display cost).
Record No. of successful & unseccessful transactions(use static data-members to keep track of transactions)
Use new operator in constructor to allocate reqd mem
Last date - 13/7/2019
*/

#include <bits/stdc++.h>

using namespace std;

class Book{
    string title, auth, pub;
    float  price;
    int stock;
    
    public:
    Book(string ctitle, string cauth, string cpub, float cprice, int cstock)
    {
        title = ctitle;
        auth = cauth;
        pub = cpub;
        price = cprice;
        stock = cstock;
    }
};

int main()
{
    cout << "Hello Coders!!!";
    return 0;
}

