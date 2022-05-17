/*A book consists of chapters, chapters consist of sections and sections consist of subsections. 
Construct a tree and print the nodes. Find the time and space requirements of your method.*/
#include <iostream>
#include <string>

using namespace std;

struct node
{
    string label;
    int ch_count;  

    struct node *child[20];
} * root;                  


class Book
{
public:
    void create_tree();
    void display(node *r1);

    Book()
    {
        root = NULL;
    }
};

void Book::create_tree()
{
    int tbooks, tchapters, i, j, k,tsections;

    root = new node(); // root node is created
    cout << "Enter name of book: ";   //Root node name
    cin >> root->label;

    cout << "Enter no. of chapters in book: " << endl;
    cin >> tchapters;
    root->ch_count = tchapters;

    for (i = 0; i < tchapters; i++) //chapters
    {
        root->child[i] = new node; //chapter is created

        cout << "Enter "<<i+1<< " Chapter name\n";
        cin >> root->child[i]->label;

        cout << "Enter no.of sections in this Chapter: "<<endl;
        cin >> root->child[i]->ch_count;

        for (j = 0; j < root->child[i]->ch_count; j++) //sections

        {
            root->child[i]->child[j] = new node;
            cout << "Enter section name: "<<endl;
            cin >> root->child[i]->child[j]->label;

            cout << "Enter no.of sub-sections in this Section: "<<endl;
            cin >> root->child[i]->child[j]->ch_count;

            for (k = 0; k < root->child[i]->child[j]->ch_count; k++) //sections
            {
            root->child[i]->child[j]->child[k] = new node;
            cout << "Enter sub-section name: "<<endl;
            cin >> root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

void Book::display(node *r1)
{
    int i, j, k, tchapters;
    if (r1 != NULL)
    {
        cout << "\n Book title : " << r1->label;
        tchapters = r1->ch_count; // how many chapters are there
        for (i = 0; i < tchapters; i++)
        {
            cout << "\n  Chapter " << i + 1;
            cout << " : " << r1->child[i]->label;
            cout << "\n Sections  ";
            for (j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout << "\n  " <<j+1<<")"<< r1->child[i]->child[j]->label;
                cout << "\n sub-sections: "<<endl;
                for (k = 0; k < root->child[i]->child[j]->ch_count; k++) //sections
                {
                    cout<<root->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }
}


int main()
{
    int choice;
    Book bst;
    while (1)
    {
        cout << "\n" << endl;
        cout << "***CHOICES***" << endl;
        cout << "1.Create" << endl;
        cout << "2.Display" << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            bst.create_tree();
        case 2:
            bst.display(root);
            break;
        case 3:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
}
