#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> number_pool;
vector < vector<int> > tree;
vector<int> merge;

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
        cout<<"pushed: "<<x.at(0)<<endl;
        tree.push_back(x);
    }else if(x.size()==2){
        vector<int> get_swapped=change_func(x);
        cout<<"pushed: "<<get_swapped.at(0)<<" "<<get_swapped.at(1)<<endl;
        tree.push_back(get_swapped);
    };
};

// gets the center of the passed in length number minus 1 to get the index
int p_func(int x){
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

void ruler(vector<int> number_pool, int size) {
    int pivot=p_func(size);

  vector<int> l;
  vector<int> r;

  if (size <= 2) {
        push(number_pool);
  } else if (size > 2) {
    int i = pivot;
    while (i >= 0) {
        l.push_back(number_pool.at(i));
      i--;
    };

    int l_length = l.size();
    ruler(l, l_length);

    int s_start=pivot+1;
    int si = s_start;
    int last = number_pool.size() - 1;
    while (si <= last) {
      r.push_back(number_pool.at(si));
      si++;
    };

    int r_length = r.size();
    ruler(r, r_length);
  };
};

int main(){
//test.......
    for(int i=100;i>=0;i--){
        number_pool.push_back(i);
    };
    int* size=new int;
    *size=number_pool.size();
    ruler(number_pool,*size);



    delete size;
    return 0;
};
