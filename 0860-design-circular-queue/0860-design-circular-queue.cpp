class MyCircularQueue {
public:
    int size;
    int *arr;
    int front;
    int rear;
    int count;
    MyCircularQueue(int k) {
        arr = new int[k];
        this->size = k;
        front = -1;
        rear = -1;
        count = 0;
    }
    
    bool enQueue(int value) {
        if(count == size){
            return false;
        }
        if(front == -1){
            front++;
        }
        rear=(rear+1)%size;
        arr[rear]=value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(front == -1){
            return false;
        }else{
            if(front == rear){
                front = -1;
                rear = -1;
            }else{
                front = (front+1)%size;
            }
            count--;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */