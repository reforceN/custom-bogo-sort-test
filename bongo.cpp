//sorry i thought the name was bongo sort not bogo LMFAO

#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

int k = 0;


void display(vector<int> arr){
    cout<<"{";
    for(int n:arr){
       cout<<n<<",";
    }
    cout<<"}";
}

bool searchFor(int temp, vector<int>& arr){
       for(int n:arr){
         if(n == temp) return true;
       }
       return false;
}

vector<int> makeArray(int size){
     vector<int> arr = {};
     int temp = 0;
     for(int i=0; i<size; ++i){
        temp = (rand() % size) + 1;
        if(!searchFor(temp,arr)){
            arr.push_back(temp);
        }
        else{
            i--;
        }
    }
    return arr;
}

vector<int> makeArrayRandom(int size){
     vector<int> arr = {};
     int temp = 0;
     for(int i=0; i<size; ++i){
        arr.push_back((rand() % size)+1);
    }
    return arr;
}

bool isRight(vector<int>& arr){
    for(int i=0; i<arr.size()-1; ++i){
        if(arr[i] > arr[i+1]){
             return false;
        }
    }
    return true;
}

vector<int> shuffle(vector<int>&arr){
    int size = arr.size();
    int times = 0;
    int n = 0;
    int j = 0;
    int temp = 0;
    int temp2 = 0;


    if(size == 1 || size < 1){
        return arr;
    }
    else{
        times = (size*size) + 100;
    }

    for(int i=0; i<times; ++i){
       temp = rand() % size;
       temp2 = rand() % size;

       while(temp == temp2){
          temp2 = rand() % size;
       }

       n = temp2;
       j = arr[temp];
       arr[temp] = arr[temp2];
       arr[n] = j;
    }

    return arr;
}

vector<int> newShuffle(vector<int>&arr){
   vector<int> order = makeArray(arr.size());
   vector<int> newArr = {};
   
   for(int i=0; i<arr.size(); ++i){
      newArr.push_back(arr[(order[i] -1)]);
   }

    arr = newArr;
    return arr;
}

void bongoSort(vector<int>& array){
    while(!isRight(array)){
        shuffle(array);
        k++;
    }
}

void bongoSortWithNewShuffle(vector<int>& array){
    while(!isRight(array)){
        newShuffle(array);
        k++;
    }
}

int main(){
    srand(time(__null));
    int size = 7;
    size_t t = time(0);
    vector<int> arr = makeArray(size);
    //vector<int> arr = makeArrayRandom(size);

    cout<<"array generated with size "<<size<<": ";
    display(arr);
    cout<<"\n";

    bongoSortWithNewShuffle(arr);

    cout<<"array after sort:";
    display(arr);
    cout<<"\n"<<"attempts:"<<k<<"\n"<<"time:"<<time(0)-t<<" seconds";
    

    return 0x0;
}
