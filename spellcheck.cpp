#include<stdio.h>
#include<vector>
#include <iostream>
#include<string>
#include <bits/stdc++.h> 
#include <functional> //for std::hash
using namespace std; 

enum EntryType {Legitimate, Empty, Deleted};

struct HashNode{
	int element;
	enum EntryType status;
};

struct HashTable{
	int size;
	HashNode *table;
};

bool isPrime (int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n == 1 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

int nextPrime(int n)
{
    if (n <= 0)
        n = 3;
    if (n % 2 == 0)
        n++;
    for (; !isPrime( n ); n += 2);
    return n;
}

int HashFunc(int key, int size)
{
    return key % size;
}

HashTable *initializeTable(int size){
	HashTable *htable;

	htable = new HashTable;

	htable->size = nextPrime(size);

	htable->table = new HashNode[htable->size];

	for(int i = 0; i<htable->size; i++){
		htable->table[i].status = Empty;
		htable->table[i].element = NULL;
	}

	return htable;

}
int total_collitions = 0;

int Find(int key, HashTable *htable)
{
    int pos = HashFunc(key, htable->size);
    int collisions = 0;
    while (htable->table[pos].status != Empty &&
           htable->table[pos].element != key)
    {
        //------------ QUADRATIC PROBING --------------
        pos = pos + 2 * ++collisions -1;
        //------------ LINEAR PROBING --------------
        //pos = pos + 1;
        if (pos >= htable->size)
            pos = pos - htable->size;
    }
    total_collitions+=collisions;
    //cout<<"Total Collisions = "<<total_collitions<<endl;
    return pos;
}

void Insert(int key, HashTable *htable)
{
    int pos = Find(key, htable);
    if (htable->table[pos].status != Legitimate)
    {
        htable->table[pos].status = Legitimate;
        htable->table[pos].element = key;
    }
}

HashTable *Rehash(HashTable *htable)
{
    int size = htable->size;
    HashNode *table = htable->table;
    htable = initializeTable(2 * size);
    for (int i = 0; i < size; i++)
    {
        if (table[i].status == Legitimate)
            Insert(table[i].element, htable);
    }
    free(table);
    return htable;
}

void Retrieve(HashTable *htable)
{
    for (int i = 0; i < htable->size; i++)
    {
        int value = htable->table[i].element;
        if (!value)
            cout<<"Position: "<<i<<" Element: Null"<<endl;
        else
            cout<<"Position: "<<i<<" Element: "<<value<<endl;
    }

}

int convertToASCII(string s)
{
	int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
    	sum+=(int)s[i];
        //cout << (int)s[i]<< endl;
    }
    return sum;
}


int main(){

	int value, size, pos, i = 1;
	string word;
    int choice;
    HashTable *htable;

    cout<<"Initializing size of the table to 53"<<endl;
    //cout<<"Enter size of the Hash Table: ";
    //cin>>size;
    size = 53;
    htable = initializeTable(size);
    cout<<"Size of Hash Table: "<<nextPrime(size)<<endl;

    std::string str;
    ifstream in("words.txt");
	while (std::getline(in, str)) {
    	// output the line
		cout<<"Inserting word: "<< str <<endl;
		i++;
		if((i*2)>htable->size){
			cout<<"------------\n"<<"Rehashing table to size "<<(2*nextPrime(htable->size))<<"\n"<<"------------"<<endl;
            htable = Rehash(htable);
            total_collitions = 0;
		}

		value = convertToASCII(str);
        Insert(value, htable);

    	//std::cout << str << std::endl;

    	// now we loop and get the next line in 'str'
	}
    cout<<"Total Collisions = "<<total_collitions<<endl;

    while(1)
    {
        cout<<"----------------------\n";
        cout<<"Choose an option below:\n";
        cout<<"----------------------\n";
        // cout<<"1.Initialize size of the table"<<endl;
        cout<<"1.Find element the table\n";
        cout<<"2.Display Hash Table\n";
        //cout<<"4.Rehash The Table"<<endl;
        cout<<"3.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        

        switch(choice)
        {
        
        case 1:
        	cout<<"Enter word to be spell checked: ";
        	cin>>word;
        	cout<<"\n";
        	value = convertToASCII(word);
        	int in_value;

        	for (int i = 0; i < htable->size; i++){
	        	in_value = htable->table[i].element;
	        	if(value == in_value){
	        		cout<<"Correct Spelling! :)"<<endl;
	        		break;
	        	}
	    	}
	    	if(value != in_value){
	    		cout<<"Wrong Spelling! :("<<endl;
	    	}

            break;
        case 2:
            Retrieve(htable);
            break;
        case 3:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;


}