
//641. 设计循环双端队列

//解法一：list
class MyCircularDeque {
private:
    int mSize;
    list<int> mImpl;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        mSize = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(!isFull()){
            mImpl.push_front(value);
            return true;
        }
        return false;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(!isFull()){
            mImpl.push_back(value);
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(!isEmpty()){
            mImpl.pop_front();
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(!isEmpty()){
            mImpl.pop_back();
            return true;
        }
        return false; 
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : mImpl.front();
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : mImpl.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return 0==mImpl.size();
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return mSize==mImpl.size();
    }
};

