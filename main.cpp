#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stdlib.h>

using namespace std;

vector < vector<int> > tree;

vector<int> change_func(vector<int> x_holder){
    int one=x_holder.at(0);
    int two=x_holder.at(1);

    if(one>two || two<one){
        int temp=x_holder.at(0);
        x_holder.at(0)=x_holder.at(1);
        x_holder.at(1)=temp;
    };
    return x_holder;
};

// pushes the recieved vector into the tree vector
void push(vector<int> x){
    if(x.size()==1){
        tree.push_back(x);
    }else if(x.size()==2){
        vector<int> get_swapped=change_func(x);
        tree.push_back(get_swapped);
    };
};

// gets the center of the passed in length number minus 1 to get the index
int pivotal(int x){
    int p;
    if(x%2==1){
        p=(0.5*(x))+0.5;
    } else if(x==1){
        p=1;
    } else{
        p=0.5*(x);
    };
    return p-1;
};

// ruling function
void ruler(vector<int> number_pool, int size) {
    int pivot=pivotal(size);

  vector<int> left;
  vector<int> right;

  if (size <= 2) {
        push(number_pool);
  } else if (size > 2) {
    int i = pivot;
    while (i >= 0) {
        left.push_back(number_pool.at(i));
      i--;
    };

    int left_length = left.size();
    ruler(left, left_length);

    int s_start=pivot+1;
    int si = s_start;
    int last = number_pool.size() - 1;
    while (si <= last) {
      right.push_back(number_pool.at(si));
      si++;
    };

    int right_length = right.size();
    ruler(right, right_length);
  };
};

int main(){
    vector<int> number_pool;
    int arr[tree.size()];


//test.......
    for(int i=10;i>=0;i--){
        number_pool.push_back(i);
    };
    int size=number_pool.size();

    ruler(number_pool,size);

// unit reading......
    int get_tree_length=tree.size();
    for(int i=0;i<get_tree_length;i++){
        int get_inner_length=tree.at(i).size();
        for(int si=0;si<get_inner_length;si++){
            cout<<tree.at(i).at(si)<<endl;
        }
    };
    return 0;
}
