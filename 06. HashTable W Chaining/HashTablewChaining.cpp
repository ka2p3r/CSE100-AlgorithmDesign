#include <bits/stdc++.h>
using namespace std;

int sz; //size of hash table
list<int> *hash_table; 

//used to return the key
int hash_function(int k) { 
	return k % sz;
}

//function used to insert the key in hashtable
void hash_insert_chained(int num) {
	hash_table[hash_function(num)].push_front(num); 
}

//function used to delete the key in hashtable
void hash_delete_chained(int num) {

	for (auto i = hash_table[hash_function(num)].begin(); i != hash_table[hash_function(num)].end(); i++) { 
		if (*i == num) {
			i = hash_table[hash_function(num)].erase(i);
			cout << num << ":DELETED;\n";
			return;
		}
	}
	cout << num << ":DELETE_FAILED;\n";
}


//function used to search the key in hashtable
void hash_search_chained(int num) {
	int cnt = 0;

	for (auto i = hash_table[hash_function(num)].begin(); i != hash_table[hash_function(num)].end(); i++) { 
		if (*i == num)   {
			cout << num << ":FOUND_AT" << hash_function(num) << "," << cnt << ";\n";
			return;
		}
		cnt++;
	}
	cout << num << ":NOT_FOUND;\n";
}


//function used to print the hashtable
void print_hashtable() {
	for (int j = 0; j < sz; j++) {
		cout << j << ":";
		for (auto y : hash_table[j]) {
			cout << y << "->";
		}
		cout << ";" << endl;
	}
}

int main() { 
	cin >> sz;
  	hash_table = new list<int>[sz];
  	char type;

  	while (type != 'e') {
    	int num;
    	cin >> type;

    	switch (type) {
            case 'i':
                cin >> num;
                hash_insert_chained(num);
                break;

            case 'd':
                cin >> num;
                hash_delete_chained(num);
                break;

            case 's':
                cin >> num;
                hash_search_chained(num);
                break;

            case 'o':
                print_hashtable();
                break;
	}
  }
}