#include <vector>
#include "LinkedList.cpp" // available at MMLS.

template <typename T>
class HashTable {
  vector< LinkedList<T> > table;
  int hashfunction (string hashitem,int n,int method) { // hash function
    int toInt_1 = hashitem.at(2) + hashitem.at(6) * hashitem.at(14)*(n/100);
    return toInt_1 % table.size();
  }
 public:
  HashTable (int size) {
    table.resize (size); // resize vector to support size elements.
  }
  ~HashTable() {
    for (int i = 0; i < table.size(); i++)
      table[i].makeEmpty();
  }
  int size() {
    return table.size();
  }
  void insert (T newItem,int n, int method) {
    if (method == 1){
        int index = hashfunction(newItem,n,method);
        table[index].insertFront(newItem);
    }
    else if (method == 2){
        int index = hashfunction(newItem,n,method);
        if(!table[index].isEmpty()) {
            while(!table[index%size()].isEmpty()) {
                index++;
            }
            table[index%size()].insertFront(newItem);
        }
        else
            table[index].insertFront(newItem);
    }

  }
  bool retrieve (T & target,int n,int method) {

    if (method == 1){
        int index = hashfunction(target,n,method);
        if(table[index].find(target) == true)
            return true;
        else
            return false;
    }
    else if (method == 2){
        int index = hashfunction(target,n,method);
        if(table[index].find(target) == true){
            return true;
        }

        else if (!table[index].find(target) == true) {
            index++;
            int limit = size();
            int itemSearched = 0;
            while((!table[index%size()].isEmpty()) && (itemSearched <= limit)) {
                if(table[index%size()].find(target) == true) {
                    //cout << "Array index :"<<index<<endl;
                    return true;
                }
                else
                    index++;
            }
            if(itemSearched == size()){
               return false;
            }

        }
    }

  }
  friend ostream& operator<< (ostream& os, HashTable<T>& ht) {
    for (int i = 0; i < ht.size(); i++)
      os << i << " = " << ht.table[i] << endl;
    return os;
  }
};
