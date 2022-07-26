#include<iostream>
#include<stdlib.h>
#include <Windows.h>
#include<iomanip>
#include<fstream>
#include<string>
#include<string.h>
#define SIZE 15
#include<cwchar>
#include <bits/stdc++.h>
  //used for hashing
#define ALPHABET_SIZE (50)  //hashing array
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
//#include<graphics.h>
using namespace std;
long long int num1,num2;
string rel;
struct Node {       //Tree NODE
  string key;
  struct Node *left, *right;
};
struct Node *root = NULL;
Node *temporary=NULL;
struct node    ////link list contacts note
{
    string name;
    long long int phNumber, phNumber2;
    string relationship;
    int favourite, blocked;
    node *next;
    node *prev;
};
struct Node *newNode(string item) {   ////Get new node of a tree
  struct Node *temporary = new Node;
  temporary->key = item;
  temporary->left = temporary->right = NULL;
  return temporary;
}

// Insert a node
struct Node *insert(struct Node *Node, string key) {
  // Return a new node if the tree is empty
  if (Node == NULL) return newNode(key);

  // Traverse to the right or left place and insert the node
  if (key < Node->key)
    Node->left = insert(Node->left, key);
  else
    Node->right = insert(Node->right, key);

  return Node;
}

struct TrieNode {   //hashing begins
	struct TrieNode* children[ALPHABET_SIZE];

	// isWordEnd is true if the node represents
	// end of a word
	bool isWordEnd;
};
struct TrieNode* getNode(void)
{
	struct TrieNode* pNode = new TrieNode;
	pNode->isWordEnd = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie. If the
// key is prefix of trie node, just marks leaf node
void insert1(struct TrieNode* root, const string key)
{
	struct TrieNode* pCrawl = root;

	for (int level = 0; level < key.length(); level++) {
		int index = CHAR_TO_INDEX(key[level]);
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isWordEnd = true;
}

// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool isLastNode(struct TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return 0;
	return 1;
}

// Recursive function to print auto-suggestions for given
// node.
void suggestionsRec(struct TrieNode* root,
					string currPrefix)
{
	// found a string in Trie with the given prefix
	if (root->isWordEnd)
		cout << currPrefix << endl;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i]) {
			// child node character value
			char child = 'a' + i;
			suggestionsRec(root->children[i],
						currPrefix + child);
		}
}

// print suggestions for given query prefix.
int printAutoSuggestions(TrieNode* root, const string query)
{
	struct TrieNode* pCrawl = root;
	for (char c : query) {
		int ind = CHAR_TO_INDEX(c);

		// no string in the Trie has this prefix
		if (!pCrawl->children[ind])
			return 0;

		pCrawl = pCrawl->children[ind];
	}
	// If prefix is present as a word, but
	// there is no subtree below the last
	// matching node.
	if (isLastNode(pCrawl)) {
		cout << query << endl;
		return -1;
	}
	suggestionsRec(pCrawl, query);
	return 1;
}

node *head = NULL, *l, *temp, *n1, *n2, *temp1, *contact;
int counter = 0;
void coordinates(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void cyan()
{
    cout<<"\033[0;36m";
}

void red()
{
    cout<<"\033[1;31m";
}

void starting()
{
    system("cls");
    int i, j;
    coordinates(30, 5);
    red();
    cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb CONTACTS MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
    coordinates(30, 10);
    cyan();
    cout<<"LOADING...";
    coordinates(35, 12);
      for (i = 1; i <= 62; i++)
    {
        for (j = 1; j <= 20000000; j++)
            ;
        cout<<char(177);
    }
    coordinates(32, 15);
    red();
    cout<<endl;
    cout<<"\t\t\t\t Project Prepared by"<<endl<<endl;
    cyan();
    cout<<"\t\t\t\tAtif Malik"<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}
void ending()
{
    int i,j;
    system("cls");
    coordinates(25, 5);
    red();
    cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb TERMINATING PROGRAM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
    coordinates(25, 10);
    cyan();
    cout<<"EXITING...";
    coordinates(25, 12);
       for (i = 1; i <=42; i++)
    {
        for (j = 1; j <= 20000000; j++)
            ;
        cout<<char(177);
    }
    cout<<endl<<endl;
}

int repl(string s){
    l=head;
    while(l!=NULL){
        if(l->name==s)
            return 1;
        else
            return 0;
        l=l->next;

    }
}
void insertContact()
{
    system("CLS");
    string tempName;
    label:
    cout<<"\t\t\t\tEnter name of contact \n\t\t\t\t";
   	//getline(cin,tempName);
   	getline(cin,tempName);
   	if(repl(tempName)){
        cout<<"\t\t\t\tName already exit!\n";
        goto label;
   	}
    cout<<"\t\t\t\tEnter Contact Number of '"<<""<<tempName<<"' \n\t\t\t\t";
    cin>>num1;
    while(!cin.good())
      {
          cin.clear();
          cin.ignore(256, '\n');
          cout<<"Enter correct Number: "<<endl;
          cin>>num1;
      }
      cin.clear();
      cin.ignore(256, '\n');
    while((num1<1000000000)||(num1>100000000000)){
        if(num1<0){
            cout<<"\t\t\t\tNumber can't be negative!\nKindly enter correct input\n";
        }
        cout<<"\t\t\t\tNumber must be 11 digits: ";
        cin>>num1;
        while(!cin.good())
      {
          cin.clear();
          cin.ignore(256, '\n');
          cout<<"Enter correct Number: "<<endl;
          cin>>num1;
      }
      cin.clear();
      cin.ignore(256, '\n');
    }
    cout<<"\t\t\t\tEnter the number for the same user or 0 to exit (you can add maximum 2 numbers) \n\t\t\t\t";
	cin>>num2;
    while(!cin.good())
      {
          cin.clear();
          cin.ignore(256, '\n');
          cout<<"Enter correct Number or 0 to exit: "<<endl;
          cin>>num2;
      }
      cin.clear();
      cin.ignore(256, '\n');
    while((num2<1000000000)||(num2>100000000000)){
        if(num2==0){
            break;
        }
        if(num2<0){
            cout<<"\t\t\t\tNumber can't be negative!\nKindly enter correct input\n";
        }
        cout<<"\t\t\t\tNumber must be 11 digits: ";
        cin>>num2;
        while(!cin.good())
      {
          cin.clear();
          cin.ignore(256, '\n');
          cout<<"Enter correct Number: "<<endl;
          cin>>num2;
      }
      cin.clear();
      cin.ignore(256, '\n');
    }
	cout<<"\t\t\t\tEnter the relationship with the contact\n\t\t\t\t";
	getline(cin,rel);

	char c;
	do{
        cout<<"\t\t\t\tIs the person your fav (y/n)\n\t\t\t\t";
        cin>>c;
	}while((c!='y')&&(c!='n'));

    l = head;

    if(head==NULL)
    {
        head = new node;
        int i=0;
        head->name= tempName;
        head->phNumber=num1;
        head->phNumber2=num2;
        head->relationship=rel;
        if (c == 'y')
	    {
	        head->favourite = 1;
	    }

	    else
	    {
	        head->favourite = 0;
	    }
	    head->blocked=0;
        head->prev = NULL;
        head->next = NULL;
        l = head;

}
    else
    {
        while(l->next!=NULL)
        {
            l = l->next;
        }
        temp = new node;
        temp->name =tempName;
        temp->phNumber=num1;
        temp->phNumber2=num2;
        temp->relationship=rel;
        if (c == 'y')
	    {
	        temp->favourite = 1;
	    }

	    else
	    {
	        temp->favourite = 0;
	    }
	    temp->blocked=0;
        temp->prev = l;
        temp->next = NULL;
        l->next = temp;
        l = temp;

    }
    counter++;
    cout<<"Contact saved to the list successfully!\n";

    root=insert(root,l->name);

    system("pause");
    system("CLS");
}

void print()
{
    int c=1;
    system("CLS");
    if(c==1)
    {
        l =  head;
        while(l!=NULL)
        {
        	cout<<"========================================================================================================\n";
            cout<<"\t\t\t\tName of contact is : "<< l->name<<endl<<endl;
            cout<<"\t\t\t\t1st Number of contact is : +92"<<l->phNumber<<endl<<endl;
            if(l->phNumber2==0){
	        	cout<<"\t\t\t\tYour Relationship with the person is: "<<l->relationship<<endl<<endl;
	        	if (l->favourite)
				    {
				        cout<<"\t\t\t\tThis person is in your FAVORITES\n"<<endl;
				    }
				if (l->blocked)
				    {
				        cout<<"\t\t\t\tYou have BLOCKED this person\n"<<endl;
				    }
	        	l = l->next;

			}
			else{
				cout<<"\t\t\t\t2nd Number of contact is : +92"<<l->phNumber2<<endl<<endl;
				cout<<"\t\t\t\tYour Relationship with the person is: "<<l->relationship<<endl<<endl;
				if (l->favourite)
				    {
				        cout<<"\t\t\t\tThis person is in your FAVORITES\n"<<endl;
				    }
				if (l->blocked)
				    {
				        cout<<"\t\t\t\tYou have BLOCKED this person\n"<<endl;
				    }
				l = l->next;

			}

        }

    }
}
void display_list_contacts(){
    int c=1;
    system("CLS");
    if(c==1)
    {
        l =  head;
        while(l!=NULL)
        {
        	cout<<"========================================================================================================\n";
            cout<<"\t\t\t\tName of contact is : "<< l->name<<endl;
            cout<<"\t\t\t\t1st Number of contact is : +92"<<l->phNumber<<endl;
            if(l->phNumber2==0){
	        	l = l->next;

			}
			else{
				cout<<"\t\t\t\t2nd Number of contact is : +92"<<l->phNumber2<<endl;
				l = l->next;

			}

        }

    }
}
node *tree=NULL;
void preorder(struct Node *root) {
  l=head;
  if (root != NULL) {

    // Traverse root
    while(l!=NULL){
        if(l->name==root->key){

            cout<<"========================================================================================================\n";
        cout<<"\t\t\t\tName of contact is : "<< l->name<<endl<<endl;
        cout<<"\t\t\t\t1st Number of contact is : +92"<<l->phNumber<<endl<<endl;
        if(l->phNumber2==0){
            cout<<"\t\t\t\tYour Relationship with the person is: "<<l->relationship<<endl<<endl;
            if (l->favourite)
            {
                cout<<"\t\t\t\tThis person is in your FAVORITES\n"<<endl;
            }
            if (l->blocked)
            {
                cout<<"\t\t\t\tYou have BLOCKED this person\n"<<endl;
            }
        }
        else{
            cout<<"\t\t\t\t2nd Number of contact is : +92"<<l->phNumber2<<endl<<endl;
            cout<<"\t\t\t\tYour Relationship with the person is: "<<l->relationship<<endl<<endl;
            if (l->favourite)
            {
                cout<<"\t\t\t\tThis person is in your FAVORITES\n"<<endl;
            }
            if (l->blocked)
            {
                cout<<"\t\t\t\tYou have BLOCKED this person\n"<<endl;
            }

        }
        break;
        }
        else{

            l=l->next;
        }
    }


    // Traverse left
    preorder(root->left);

    // Traverse right
    preorder(root->right);
  }
  else {
    return;
  }
}
// Post-order Tarversal
void postorder(struct Node *root) {
  l=head;
  if (root != NULL) {

    // Traverse left
    postorder(root->left);

     // Traverse right
    postorder(root->right);


    while(l!=NULL){
        if(l->name==root->key){

            cout<<"========================================================================================================\n";
        cout<<"\t\t\t\tName of contact is : "<< l->name<<endl<<endl;
        cout<<"\t\t\t\t1st Number of contact is : +92"<<l->phNumber<<endl<<endl;
        if(l->phNumber2==0){
            cout<<"\t\t\t\tYour Relationship with the person is: "<<l->relationship<<endl<<endl;
            if (l->favourite)
            {
                cout<<"\t\t\t\tThis person is in your FAVORITES\n"<<endl;
            }
            if (l->blocked)
            {
                cout<<"\t\t\t\tYou have BLOCKED this person\n"<<endl;
            }
        }
        else{
            cout<<"\t\t\t\t2nd Number of contact is : +92"<<l->phNumber2<<endl<<endl;
            cout<<"\t\t\t\tYour Relationship with the person is: "<<l->relationship<<endl<<endl;
            if (l->favourite)
            {
                cout<<"\t\t\t\tThis person is in your FAVORITES\n"<<endl;
            }
            if (l->blocked)
            {
                cout<<"\t\t\t\tYou have BLOCKED this person\n"<<endl;
            }

        }
        break;
        }
        else{

            l=l->next;
        }
    }


  }
  else {
    return;
  }
}

// In-order Taraversal
void inorder(struct Node *root) {
  l=head;
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    while(l!=NULL){
        if(l->name==root->key){

            cout<<"========================================================================================================\n";
        cout<<"\t\t\t\tName of contact is : "<< l->name<<endl<<endl;
        cout<<"\t\t\t\t1st Number of contact is : +92"<<l->phNumber<<endl<<endl;
        if(l->phNumber2==0){
            cout<<"\t\t\t\tYour Relationship with the person is: "<<l->relationship<<endl<<endl;
            if (l->favourite)
            {
                cout<<"\t\t\t\tThis person is in your FAVORITES\n"<<endl;
            }
            if (l->blocked)
            {
                cout<<"\t\t\t\tYou have BLOCKED this person\n"<<endl;
            }
        }
        else{
            cout<<"\t\t\t\t2nd Number of contact is : +92"<<l->phNumber2<<endl<<endl;
            cout<<"\t\t\t\tYour Relationship with the person is: "<<l->relationship<<endl<<endl;
            if (l->favourite)
            {
                cout<<"\t\t\t\tThis person is in your FAVORITES\n"<<endl;
            }
            if (l->blocked)
            {
                cout<<"\t\t\t\tYou have BLOCKED this person\n"<<endl;
            }

        }
        break;
        }
        else{

            l=l->next;
        }
    }

    // Traverse right
    inorder(root->right);
  }
  else {
    return;
  }
}

void deletee()
{
    node *nl,*n2;
    display_list_contacts();
    string s;
    cout<<"Enter name of contact to delete: ";
    getline(cin,s);
    l = head;

    while(l->name!=s)
    {
        n1 = l;
        l = l->next;
    }

    int del_counter=0;
    if(l->phNumber2!=0){
        del_counter++;
        int choice;
        label_choice2:
            cout<<"Which number you want to delete: ";
            cin>>choice;
            while(!cin.good())
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout<<"Kindly Enter correct choice: "<<endl;
                cin>>choice;
            }
            cin.clear();
            cin.ignore(256, '\n');
        switch(choice){
        case 1:
            l->phNumber=0;
            l->phNumber=l->phNumber2;
            l->phNumber2=0;

            break;
        case 2:
            l->phNumber2=0;
            break;
        default:
            goto label_choice2;
            break;
        }
        cout<<"Phone Number deleted successfully.\n";
    }
    if((l==head)&&(l->next==NULL)){
        head=NULL;
        head->next=NULL;
        head->prev=NULL;
        cout<<"Contact List is Empty!\n";
    }
    else if((l==head)&&(del_counter==0))
    {
        head = head->next;
        head->prev = NULL;
    }
    else if(del_counter==0)
    {
        if(l->next!=NULL)
        {
            n1->next = l->next;
            n2 = l->next;
            n2->prev = n1;
        }
        else
        {
            n2 = l->prev;
            n2->next = NULL;
            temp = n2;
        }
        free(l);
        cout<<s<<" deleted successfully!\n";

    }

}
int comp=0;
void search_suggestion(){
	system("pause");
	system("CLS");
	l=head;
	if(head==NULL){
        cout<<"Empty link list! \n";
	}
	struct TrieNode* root = getNode();
	while(l->next!=NULL){
        insert1(root, l->name);
        l=l->next;
	}
	insert1(root, l->name);

	cout<<"Enter input for suggestions: ";
	string s;
	getline(cin,s);
	comp = printAutoSuggestions(root, s);
	if (comp == -1)
		cout << "No other strings found with this prefix\n";

	else if (comp == 0)
		cout << "No string found with this prefix\n";

}
bool flag=true;
string s;
void search(){
    label_suggestion:
        search_suggestion();
    if(comp==0){
        goto label_suggestion;
    }
    label_search:
        l=head;
        cout<<"Enter name: ";
        getline(cin,s);
    while(l!=NULL){
        if(l->name==s){
            flag=true;
            cout<<"========================================================================================================\n";
        cout<<"\t\t\t\tName of contact is : "<< l->name<<endl<<endl;
        cout<<"\t\t\t\t1st Number of contact is : +92"<<l->phNumber<<endl<<endl;
        if(l->phNumber2==0){
            cout<<"\t\t\t\tYour Relationship with the person is: "<<l->relationship<<endl<<endl;
            if (l->favourite)
            {
                cout<<"\t\t\t\tThis person is in your FAVORITES\n"<<endl;
            }
            if (l->blocked)
            {
                cout<<"\t\t\t\tYou have BLOCKED this person\n"<<endl;
            }
        }
        else{
            cout<<"\t\t\t\t2nd Number of contact is : +92"<<l->phNumber2<<endl<<endl;
            cout<<"\t\t\t\tYour Relationship with the person is: "<<l->relationship<<endl<<endl;
            if (l->favourite)
            {
                cout<<"\t\t\t\tThis person is in your FAVORITES\n"<<endl;
            }
            if (l->blocked)
            {
                cout<<"\t\t\t\tYou have BLOCKED this person\n"<<endl;
            }

        }
        break;
        }
        else{
            flag=false;
            l=l->next;
        }
    }
    if(flag){

    }
    else{
        cout<<"Kindly enter name of the contact correctly!\n";
        goto label_search;
    }
}
void update_contact(){
    search();
    while(l!=NULL){
        if(l->name==s){
            cout<<"1) Update Name\n";
            cout<<"2) Update Phone number\n";
            cout<<"3) Update Relationship\n";
            cout<<"4) Update Favorite Status\n";
            cout<<"5) Update Blocked Status\n";
            int choice;
            label_1:
                cout<<"Enter choice: ";
                cin>>choice;
                while(!cin.good())
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout<<"Kindly Enter correct choice: "<<endl;
                    cin>>choice;
                }
            cin.clear();
            cin.ignore(256, '\n');
            if(choice==1){
                string s;
                cout<<"Enter Updated Name: ";
                getline(cin,s);
                l->name=s;
                cout<<"Name Updated Successfully!\n";
                break;
            }
            else if(choice==2){
                long long int ph;
                if((l->phNumber>0)&&(l->phNumber2==0)){
                    cout<<"1) Update First Number\n2) Add second Number\n";
                    int ch;
                    cin>>ch;
                    while(!cin.good())
                    {
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout<<"Enter correct Number: "<<endl;
                        cin>>ch;
                    }
                    cin.clear();
                    cin.ignore(256, '\n');
                    if(ch==1){
                            cout<<"Enter Updated Number: ";
                            cin>>ph;
                            while(!cin.good())
                            {
                                cin.clear();
                                cin.ignore(256, '\n');
                                cout<<"Enter correct Number: "<<endl;
                                cin>>ph;
                            }
                            cin.clear();
                            cin.ignore(256, '\n');
                            while((ph<1000000000)||(ph>100000000000)){
                            if(ph<0){
                                cout<<"Number can't be negative!\nKindly enter correct input\n";
                            }
                            cout<<"Number must be 11 digits: ";
                            cin>>ph;
                            while(!cin.good())
                            {
                                cin.clear();
                                cin.ignore(256, '\n');
                                cout<<"Enter correct Number: "<<endl;
                                cin>>ph;
                            }
                            cin.clear();
                            cin.ignore(256, '\n');
                            }
                    l->phNumber=ph;
                    }
                    else if(ch==2){
                            cout<<"Enter Second Number: ";
                            cin>>ph;
                            while(!cin.good())
                            {
                                cin.clear();
                                cin.ignore(256, '\n');
                                cout<<"Enter correct Number: "<<endl;
                                cin>>ph;
                            }
                            cin.clear();
                            cin.ignore(256, '\n');
                            while((ph<1000000000)||(ph>100000000000)){
                            if(ph<0){
                                cout<<"Number can't be negative!\nKindly enter correct input\n";
                            }
                            cout<<"Number must be 11 digits: ";
                            cin>>ph;
                            while(!cin.good())
                            {
                                cin.clear();
                                cin.ignore(256, '\n');
                                cout<<"Enter correct Number: "<<endl;
                                cin>>ph;
                            }
                            cin.clear();
                            cin.ignore(256, '\n');
                            }
                    l->phNumber2=ph;
                    }
                }
                else{
                    cout<<"1) Update First Number\n2) Update Second Number\n";
                    label:
                        int ch;
                        cin>>ch;
                    while(!cin.good())
                    {
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout<<"Enter correct Number: "<<endl;
                        cin>>ch;
                    }
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout<<"Enter Number: ";
                    cin>>ph;
                    while(!cin.good())
                    {
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout<<"Enter correct Number: "<<endl;
                        cin>>ph;
                    }
                    cin.clear();
                    cin.ignore(256, '\n');
                    while((ph<1000000000)||(ph>100000000000)){
                    if(ph<0){
                        cout<<"Number can't be negative!\nKindly enter correct input\n";
                    }
                    cout<<"Number must be 11 digits: ";
                    cin>>ph;
                    while(!cin.good())
                    {
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout<<"Enter correct Number: "<<endl;
                        cin>>ph;
                    }
                    cin.clear();
                    cin.ignore(256, '\n');

                }
                if(ch==1)
                    l->phNumber=ph;
                else if(ch==2)
                    l->phNumber2=ph;
                else
                    goto label;
                }
                cout<<"Phone Number Updated Successfully!\n";
            }
            else if(choice==3){
                string s;
                cout<<"Enter Updated Relationship: ";
                getline(cin,s);
                l->relationship=s;
                cout<<"Relationship Updated Successfully!\n";
            }
            else if(choice==4){
                char c;
                int x;
                do{
                    cout<<"Is the person your favorite anymore? (y/n)\n";
                    cin>>c;
                }while((c!='y')&&(c!='n'));
                if(c=='y'){
                    x=1;
                }
                else
                    x=0;
                l->favourite=x;
                cout<<"Favorite status updated successfully\n";
            }
            else if(choice==5){
                int blk;
                if(l->blocked==0){
                    cout<<"To block this contact enter other than 0 \n";
                    cin>>blk;
                    while(!cin.good())
                    {
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout<<"Enter correct Number: "<<endl;
                        cin>>blk;
                    }
                    cin.clear();
                    cin.ignore(256, '\n');
                    if(blk>0){
                            cout<<"Blocked Successfully\n";
                    }

                }
                else{
                    cout<<"To unblock this contact enter 0\n";
                    cin>>blk;
                    while(!cin.good())
                    {
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout<<"Enter correct Number: "<<endl;
                        cin>>blk;
                    }
                    cin.clear();
                    cin.ignore(256, '\n');
                    if(blk==0){
                            cout<<"Unblocked Successfully\n";
                    }

                }
                l->blocked=blk;
            }
            break;
        }
        else{
            l=l->next;
        }
    }
}
void block_contact(){
    system("CLS");
    l=head;
    if(l==NULL){
        cout<<"Contact list is empty!\nCan't display favorites!\n";
    }
    else{
    while(l->next!=NULL){
        if(l->blocked){
            cout<<"========================================================================================================\n";
            cout<<"Name: "<<l->name<<endl<<"Ph# :+92"<<l->phNumber<<endl;
            if(l->phNumber2!=0){
                cout<<"Second Ph#: +92"<<l->phNumber2<<endl;
            }
            cout<<"Relationship: "<<l->relationship<<endl<<endl<<"This person is in your favorite list!"<<endl;
            cout<<"========================================================================================================\n";
        }
        l=l->next;
    }
    if(l->next==NULL){
        if(l->blocked){
            cout<<"========================================================================================================\n";
            cout<<"Name: "<<l->name<<endl<<"Ph# : +92"<<l->phNumber<<endl;
            if(l->phNumber2!=0){
                cout<<"Second Ph#: +92"<<l->phNumber2<<endl;
            }
            cout<<"Relationship: "<<l->relationship<<endl<<endl<<"This person is in your blocked list!\n"<<endl;
            cout<<"========================================================================================================\n";
        }
    }
    Sleep(3000);
    }
}
void save_to_file(){
    ifstream file("Contacts.txt");
    ofstream file_2("Contacts_backup.txt");
    string s;
    while(getline(file,s)){
        file_2<<s<<endl;
    }
    l=head;
    while(l->next!=NULL){
        file_2<<l->name<<endl<<l->phNumber<<endl;
        if(l->phNumber2!=0){
        	file_2<<l->phNumber2<<endl;
        	l=l->next;
		}else{
        //file<<l->full_name<<endl<<l->phNo<<endl;
        l=l->next;
		}
    }
    file_2<<l->name<<endl<<l->phNumber<<endl;

    if(l->phNumber2!=0){
        	file_2<<l->phNumber2<<endl;
        	l=l->next;
		}else{
        //file<<l->full_name<<endl<<l->phNo<<endl;
        l=l->next;
		}
    //file<<l->full_name<<endl<<l->phNo<<endl;
    cout<<"\nContacts saved to file successfully! \n";
    file_2.close();
    file.close();
    ifstream myFile("Contacts_backup.txt");
    ofstream myFile_2("Contacts.txt");
    string str;
    while(getline(myFile,str)){
        myFile_2<<str<<endl;
    }
    myFile.close();
    myFile_2.close();
}
void print_relationships(){
    node *relation_node=NULL;
    l=head;
    if(head==NULL){
        cout<<"List is Empty!\n";
    }
    else{
        cout<<"Following Relationships Exit in your directory!\n\n";
        while(l->next!=NULL){
            cout<<l->relationship<<endl<<endl;
            l=l->next;
        }
        cout<<l->relationship<<endl<<endl;
    }
    cout<<"Which relationship you want to view: ";
    string s;
    cin>>s;
    l=head;
    while(l->next!=NULL){
        if(l->relationship==s){
            cout<<"========================================================================================================\n";
            cout<<"Name: "<<l->name<<endl<<"Ph# :"<<l->phNumber<<endl;
            if(l->phNumber2!=0){
                cout<<"Second Ph#: "<<l->phNumber2<<endl;
            }
            cout<<"Relationship: "<<l->relationship<<endl;
            cout<<"========================================================================================================\n";
        }
        l=l->next;
    }
    if(l->next==NULL){
        if(l->relationship==s){
            cout<<"========================================================================================================\n";
            cout<<"Name: "<<l->name<<endl<<"Ph# :"<<l->phNumber<<endl;
            if(l->phNumber2!=0){
                cout<<"Second Ph#: "<<l->phNumber2<<endl;
            }
            cout<<"Relationship: "<<l->relationship<<endl;
            cout<<"========================================================================================================\n";
        }
    }
    Sleep(3000);
}
void print_favorite(){
    system("CLS");
    l=head;
    if(l==NULL){
        cout<<"Contact list is empty!\nCan't display favorites!\n";
    }
    else{
    while(l->next!=NULL){
        if(l->favourite){
            cout<<"========================================================================================================\n";
            cout<<"Name: "<<l->name<<endl<<"Ph# :"<<l->phNumber<<endl;
            if(l->phNumber2!=0){
                cout<<"Second Ph#: "<<l->phNumber2<<endl;
            }
            cout<<"Relationship: "<<l->relationship<<endl<<endl<<"This person is in your Favorite list!"<<endl;
            cout<<"========================================================================================================\n";
        }
        l=l->next;
    }
    if(l->next==NULL){
        if(l->favourite){
            cout<<"========================================================================================================\n";
            cout<<"Name: "<<l->name<<endl<<"Ph# :"<<l->phNumber<<endl;
            if(l->phNumber2!=0){
                cout<<"Second Ph#: "<<l->phNumber2<<endl;
            }
            cout<<"Relationship: "<<l->relationship<<endl<<endl<<"This person is in your Favorite list!\n"<<endl;
            cout<<"========================================================================================================\n";
        }
    }
    Sleep(3000);
    }
}

int main(){

    starting();
    while(true)
    {

        system("color 0A");
        Sleep(1000);
        system("CLS");
    	int choice;
    	cout<<"1)  Insert\n"<<"2)  List all Contacts\n"<<"3)  Search Suggestions\n4)  Update Contact\n5)  Block/Unblock Contact\n"<<"6)  Save to file\n7)  Delete Contact\n8)  Print Relationships\n";
        cout<<"9)  Print Favorites\n"<<"10) Print using In order\n"<<"11) Print using Pre order\n";
        cout<<"12) Print using Post order\n"<<"0)  Exit\n";
        int counter_main=0;
        int counter_switch=0;
        label:
            cout<<"Enter choice: ";
            cin>>choice;
            while(!cin.good())
            {
                if(counter_main>3){
                    cout<<"too many incorrect choices";
                    ending();
                    return 0;
                }
                cin.clear();
                cin.ignore(256, '\n');
                counter_main++;
                cout<<"Enter correct choice: "<<endl;
                cin>>choice;


            }

            cin.clear();
            cin.ignore(256, '\n');

        switch(choice){
        	case 1:
        		insertContact();
        		break;
        	case 2:
        		print();
        		system("pause");
        		system("CLS");
        		break;
        	case 3:
        		search();
        		break;
        	case 4:
                update_contact();
                break;
            case 5:
                block_contact();
                break;
        	case 6:
            system("CLS");
            if(head==NULL){
                cout<<"Link List is empty\nCould not save data!\n";
            }
            else{
                save_to_file();
            }
            break;
            case 7:
                deletee();
                break;
            case 8:
                print_relationships();
                Sleep(3000);
        		system("CLS");
                break;
            case 9:
                print_favorite();
                Sleep(3000);
        		system("CLS");
                break;
            case 10:
        		inorder(root);
        		Sleep(3000);
        		system("CLS");
        		break;
            case 11:
        		preorder(root);
        		Sleep(3000);
        		system("CLS");
        		break;
            case 12:
        		postorder(root);
        		Sleep(3000);
        		system("CLS");
        		break;
            case 0:
                if(head==NULL){
                    cout<<"Empty link list!\n";
                    ending();
                    return 0;
                }
                else{
                    ending();
                    return 0;
                }
                break;
            default:
                counter_switch++;
                if(counter_switch>3){
                    cout<<"too many incorrect choices";
                    ending();
                    return 0;
                }

                goto label;
		}

    }
}
