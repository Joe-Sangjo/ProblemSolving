#include <stdio.h>


struct Node{
    int val;
    Node* next;
};

const int MAX_CNT = 5;
class Queue{
    Node* front;
    Node* rear;
    int cnt;

    void enqueue(int v) {
        if(cnt >= MAX_CNT) {
            printf("Queue Overflow");
            return;
        }

        Node *newnode = new Node(v, nullptr);
        if(front == nullptr) {
            front = newnode;
            rear = newnode;
            cnt++;
        } else {
            rear->next = newnode;
            rear = rear->next;
            cnt++;
        }
    }

    int pop() {
        if(cnt <= 0) {
            printf("No data");
            return -10;
        }
        auto temp = front;
        front = front->next;
        cnt--;
        delete temp;
    }

    void traverse() {
        for(auto& here = front; here!=nullptr ; here=here->next){
            printf("%d ", here->val);
        }
    }
};

int main(){

    int inp;
    cin>>inp;
    Queue q;
    q.cnt = 0;
    int num;
    while(inp!=4){
        switch(inp) {
            case 1:
                cin>>num;
                q.enqueue(num);         
                break;
            case 2:
                cin>>num;
                q.pop();
                break;
            case 3:
                q.traverse();
                break;
        }
    }

    return 0;
}