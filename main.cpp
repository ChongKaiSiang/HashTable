#include <iostream>
#include <chrono>
#include <ctime>
#include "HashTable.cpp"
#include <fstream>

using namespace std;

void searchData(HashTable<string>ht,string target,int n,int method) {
    if (ht.retrieve(target,n,method))
        cout << "Target found" << endl;
    else
        cout << "Target not found" << endl;
}

int main()
{
    int method = 0;
    int data;
    cout << "Choose a Set of data to be used."<< endl ;
    cout << "1 : Set A - 100 items"<<endl;
    cout << "2 : Set B - 100000 items"<<endl;
    cout << "3 : Set C - 500000 items"<<endl;
    cout << "Data set:" ;
    cin>> data;

    cout << endl;
    cout << "Hash table method to be used." << endl;
    cout <<"1 : Chaining"<< endl;
    cout <<"2 : Linear Probing" << endl;
    cout <<"Method:";
    cin >> method;

    if(data==1){

        if (method == 1){
            const int n = 100 ;
            static string A[n];

            ifstream MyReadFile("setA.txt");
            string data1;

            auto start = chrono::system_clock::now();

            for(int i=0;i<n;i++){
                getline(MyReadFile,data1);
                A[i] = data1;
            }
            HashTable<string> ht(n*0.9);
            cout << "Array : ";
            for (int i = 0; i < n; i++) {

                // 3. Insert A[i] into ht.
                ht.insert(A[i],n,method);
            }
            cout << endl;

            // Display ht.
            cout << ht << endl;
            auto end = chrono::system_clock::now();
            chrono::duration<double> duration = end - start;

            cout << "Duration for insert: " << duration.count() << "s\n";

            string target;

            for (int i = 0 ;i < 20; i++){
                cout << endl;
                cout << "Target to search: ";
                cin >> target;

                start = chrono::system_clock::now();
                // 4. Retrieve the target from ht.
                searchData(ht,target,n,method);


                end = chrono::system_clock::now();
                duration = end - start;
                cout << "Duration for search: " << duration.count() << "s\n";
            }
            MyReadFile.close();
        }
        else if(method == 2){
            const int n = 100 ;
            static string A[n];

            ifstream MyReadFile("setA");
            string data1;

            auto start = chrono::system_clock::now();

            for(int i=0;i<n;i++){
                getline(MyReadFile,data1);
                A[i] = data1;
            }
            HashTable<string> ht(n*1.5);
            cout << "Array : ";
            for (int i = 0; i < n; i++) {

                // 3. Insert A[i] into ht.
                ht.insert(A[i],n,method);
            }
            cout << endl;

            // Display ht.
            cout << ht << endl;
            auto end = chrono::system_clock::now();
            chrono::duration<double> duration = end - start;

            cout << "Duration for insert: " << duration.count() << "s\n";

            string target;
            for (int i = 0 ;i < 20; i++){
                cout << endl;
                cout << "Target to search: ";
                cin >> target;

                start = chrono::system_clock::now();
                // 4. Retrieve the target from ht.
                searchData(ht,target,n,method);


                end = chrono::system_clock::now();
                duration = end - start;
                cout << "Duration for search: " << duration.count() << "s\n";
            }
            MyReadFile.close();
        }

    }
    else if(data==2){

        if (method == 1){
            const int n = 100000 ;
            static string A[n];

            ifstream MyReadFile("setB.txt");
            string data1;

            auto start = chrono::system_clock::now();

            for(int i=0;i<n;i++){
                getline(MyReadFile,data1);
                A[i] = data1;
            }
            HashTable<string> ht(n*0.9);
            cout << "Array : ";
            for (int i = 0; i < n; i++) {

                // 3. Insert A[i] into ht.
                ht.insert(A[i],n,method);
            }
            cout << endl;

            // Display ht.
            //cout << ht << endl;
            auto end = chrono::system_clock::now();
            chrono::duration<double> duration = end - start;

            cout << "Duration for insert: " << duration.count() << "s\n";

            string target;
            for (int i = 0 ;i < 20; i++){
                cout << endl;
                cout << "Target to search: ";
                cin >> target;

                start = chrono::system_clock::now();
                // 4. Retrieve the target from ht.
                searchData(ht,target,n,method);


                end = chrono::system_clock::now();
                duration = end - start;
                cout << "Duration for search: " << duration.count() << "s\n";
            }
            MyReadFile.close();
        }
        else if(method == 2){
            const int n = 100000 ;
            static string A[n];

            ifstream MyReadFile("setB.txt");
            string data1;

            auto start = chrono::system_clock::now();

            for(int i=0;i<n;i++){
                getline(MyReadFile,data1);
                A[i] = data1;
            }
            HashTable<string> ht(n*1.5);
            cout << "Array : ";
            for (int i = 0; i < n; i++) {

                // 3. Insert A[i] into ht.
                ht.insert(A[i],n,method);
            }
            cout << endl;

            // Display ht.
            //cout << ht << endl;
            auto end = chrono::system_clock::now();
            chrono::duration<double> duration = end - start;

            cout << "Duration for insert: " << duration.count() << "s\n";

            string target;
            for (int i = 0 ;i < 20; i++){
                cout << endl;
                cout << "Target to search: ";
                cin >> target;

                start = chrono::system_clock::now();
                // 4. Retrieve the target from ht.
                searchData(ht,target,n,method);


                end = chrono::system_clock::now();
                duration = end - start;
                cout << "Duration for search: " << duration.count() << "s\n";
            }
            MyReadFile.close();
        }
    }
    else if(data==3){


        if (method == 1){
            const int n = 500000 ;
            static string A[n];

            ifstream MyReadFile("setC.txt");
            string data1;
            auto start = chrono::system_clock::now();

            for(int i=0;i<n;i++){
                getline(MyReadFile,data1);
                A[i] = data1;
            }
            HashTable<string> ht(n*0.9);
            cout << "Array : ";
            for (int i = 0; i < n; i++) {

                // 3. Insert A[i] into ht.
                ht.insert(A[i],n,method);
            }
            cout << endl;

            // Display ht.
            //cout << ht << endl;
            auto end = chrono::system_clock::now();
            chrono::duration<double> duration = end - start;

            cout << "Duration for insert: " << duration.count() << "s\n";

            string target;
            for (int i = 0 ;i < 20; i++){
                cout << endl;
                cout << "Target to search: ";
                cin >> target;

                start = chrono::system_clock::now();
                // 4. Retrieve the target from ht.
                searchData(ht,target,n,method);


                end = chrono::system_clock::now();
                duration = end - start;
                cout << "Duration for search: " << duration.count() << "s\n";
            }
            MyReadFile.close();
        }
        else if(method == 2){
            const int n = 500000 ;
            static string A[n];

            ifstream MyReadFile("setC.txt");
            string data1;
            auto start = chrono::system_clock::now();

            for(int i=0;i<n;i++){
                getline(MyReadFile,data1);
                A[i] = data1;
            }
            HashTable<string> ht(n*1.5);
            cout << "Array : ";
            for (int i = 0; i < n; i++) {

                // 3. Insert A[i] into ht.
                ht.insert(A[i],n,method);
            }
            cout << endl;

            // Display ht.
            //cout << ht << endl;
            auto end = chrono::system_clock::now();
            chrono::duration<double> duration = end - start;

            cout << "Duration for insert: " << duration.count() << "s\n";

            string target;
            for (int i = 0 ;i < 20; i++){
                cout << endl;
                cout << "Target to search: ";
                cin >> target;

                start = chrono::system_clock::now();
                // 4. Retrieve the target from ht.
                searchData(ht,target,n,method);


                end = chrono::system_clock::now();
                duration = end - start;
                cout << "Duration for search: " << duration.count() << "s\n";
            }
            MyReadFile.close();
        }
    }



}
