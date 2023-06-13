#include <iostream>
using namespace std;
#include "LinkedList.h"

int main(){
    LinkedList p = nil();
    //cout<<isEmpty(p) <<endl;
    Snoc(40, p);
    Snoc(50, p);
    Snoc(70, p);
    cout<<isEmpty(p) <<endl;
    Tail(p);
    cout<<length(p) <<endl;
    cout <<head(p) <<endl;
    
}