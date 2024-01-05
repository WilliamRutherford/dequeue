#include <.\dequeue.cpp>
#include <iostream>

bool stack_operations_1(bool verbose = true) {
    //int arr[] = {};
    dequeue<int> dq({}, 8);
    int to_insert[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    for(int i = 0; i < 8; i++){
        dq.push(to_insert[i]);
        if(dq.peek() != to_insert[i]){
            std::cout << "Error inserting elem " << to_insert[i] << " with index " << i << std::endl;
            return false;
        }
        if(verbose){
            std::cout << "insert at step: " << i << ": " << dq.peek() << std::endl;
        }
    }
    // We have inserted all elements. Now we must pop them.
    int curr = 0;
    for(int i = 0; i < 8; i++){
        curr = dq.pop();
        if(curr != to_insert[7 - i]){
            std::cout << "Error when popping elem " << to_insert[7 - i] << " at i = " << i << " instead got: " << curr << std::endl;
            return false;
        }
        if(verbose){
            std::cout << "pop at step: " << i << ": " << curr << std::endl;
        }
    }
    return true;


}

int main(){
    stack_operations_1();
}