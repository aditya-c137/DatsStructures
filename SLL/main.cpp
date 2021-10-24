#include <iostream>

using namespace std;

template<class T>
class Node {
    private:
        T content;
        Node<T>* next;
    public:
        Node<T>* getNext(){
            return this->next;
        }
        T getContent(){
            return this->content;
        }
        void setNext(Node<T>* next){
            this->next = next;
        }
        void setContent(T content){
            this->content = content;
        }
};

template<class T>
class LinkedList {
    private:
        Node<T>* head;
    public:
        LinkedList(){
            this->head = NULL;
        }
        void setHead(Node<T>* head){
            this->head = head;
        }
        Node<T>* getHead(){
            return this->head;
        }
        T get(int index){
            Node<T>* temp = this->getHead();
            for(int i = 0; i < index; i++){
                temp = (*temp).getNext();
            }
            return (*temp).getContent();
        }
        void add(T content){
            Node<T>* temp;
            if(this->head){
                temp =  this->getHead();
                while((*temp).getNext()){
                    temp = (*temp).getNext();
                }
                temp->setNext(new Node<T>());
                temp = (*temp).getNext();
            }
            else{
                this->setHead(new Node<T>());
                temp = this->getHead();
            }
            (*temp).setContent(content);
        }
};


int main() {
    LinkedList<int> sll;
    int i;
    cin>>i;
    sll.add(i++);
    sll.add(i);
    cout<<"sll: "<<sll.get(0)<<endl;
    cout<<"sll: "<<sll.get(1)<<endl;
    return 0;
}