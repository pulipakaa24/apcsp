#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h> // IMPORTS

struct book {
    string author;
    string title;
    int numCopies;
}; // data structure to store book author, title, and number of copies of that book.

int arrSize = 0; // initialize size counter used during runtime
struct book * library; // declare library array

void addBook(void) // function to add books to the library array.
{
    bool duplicate = 0; // bool to keep track of whether the book is already in the library or has ever been added.
    struct book addedBook;
    addedBook.author = get_string("Author (All Caps): "); // get author and title
    addedBook.title = get_string("Title (All Caps): ");
    for (int i = 0; i < arrSize; i++)
    {
        if (!strcmp(addedBook.author, library[i].author) && !strcmp(addedBook.title, library[i].title))
        {
            library[i].numCopies++; // if a copy has ever been added before, increment the number of copies and set duplicate to 1 to prevent adding to library.
            duplicate = 1;
        }
    }

    if (!duplicate)
    {
        arrSize++;
        addedBook.numCopies = 1;
        library = realloc(library, arrSize * sizeof(struct book)); // if never added, add to library.
        library[arrSize - 1] = addedBook;
    }
}

int loanBook(void)
{
    struct book bookLoaned;
    bookLoaned.author = get_string("Author (All Caps): ");
    bookLoaned.title = get_string("Title (All Caps): ");// get author and title for book requested
    for (int i = 0; i < arrSize; i++)
    {
        if (!strcmp(bookLoaned.author, library[i].author) && !strcmp(bookLoaned.title, library[i].title) && library[i].numCopies > 0)
        {
            library[i].numCopies--; // loan book, remove one copy from library.
            return i; // return index of book loaned
        }
    }

    printf("Unavailable\n"); // if nothing was found, the book isn't in the library.
    return -1;
}

void search(void)
{
    bool smthFound = 0;
    string author = get_string("Author (All Caps): "); // get search term
    for (int i = 0; i < arrSize; i++)
    {
        if (!strcmp(author, library[i].author))
        {
            printf("%s, copies: %i\n", library[i].title, library[i].numCopies); // find each book title and number of available copies of that book.
            smthFound = 1;
        }
    }

    if (!smthFound)
    {
        printf("No Search Results\n"); // if nothing was found, print that nothing was found.
    }
}

void listBooks(void)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s, by %s, # of copies: %i\n", library[i].title, library[i].author, library[i].numCopies); // List all the books in the library.
    }
}

int main(void)
{
    library = malloc(sizeof(struct book));
    while (1)
    {
        int option;
        do
        {
            option = get_int("\n1: Add a Book\n2: Loan a Book\n3: Search by Author\n4: List Books\n5: QUIT\n"); // print option menu.
        } while (option < 1 || option > 5);

        if (option == 1)
        {
            addBook();
            printf("%s added! Now %i copies.\n", library[arrSize - 1].title, library[arrSize - 1].numCopies); // run add books, then print a confirmation message
        }

        else if (option == 2)
        {
            int index = loanBook();
            if (index >= 0)
            {
                printf("%s loaned, %i copies remaining.\n", library[index].title, library[index].numCopies); // if a valid index is returned, print the book loaned and the number of remaining copies.
            }
        }

        else if (option == 3)
        {
            search(); // run search
        }

        else if (option == 4)
        {
            listBooks(); // run list books.
        }

        else if (option == 5)
        {
            printf("Goodbye! Library will be deleted.\n"); // print goodbye message then break loop to quit.
            break;
        }
    }
}