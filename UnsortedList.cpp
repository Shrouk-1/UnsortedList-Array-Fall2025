

template<class T>
UnsortedList<T>::UnsortedList() {
    length = 0;
    head = nullptr;
    currPos = nullptr;
}

template<class T>
void UnsortedList<T>::MakeEmpty() {
    while(head){
        Node *temp = head;
        head = temp->next;
        delete temp;
    }

}

template<class T>
bool UnsortedList<T>::IsFull() const {
    try {
        Node * testNode = new Node;
        delete testNode;
    }
    catch (std::bad_alloc &e){
        return true;
    }
    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {
    Node *currN = head;
    while(currN){
        if (currN->value == someItem){
            return true;
        }
        currN = currN->next;
        }
    return false;
}

template<class T>
void UnsortedList<T>::PutItem(T item) {
    Node* newNode = new Node;
    newNode->value = item;
    newNode->next = head;
    currPos = newNode;
    head= newNode;
    ++length;
}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    Node *prevN = nullptr;
    Node *currN = head;
    while(currN){
        if (currN->value == item){
            if(prevN != nullptr){
                prevN->next = currN->next;
            }else{
                head = currN->next;
                delete currN;
            }
            delete currN;
            --length;
            return;
        }
        prevN = currN;
        currN = currN->next;
    }
}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currPos = head;


}


template<class T>
T UnsortedList<T>::GetNextItem() {
    T currVal = currPos->value;
    currPos = currPos->next;
    return currVal;
}
