#include <iostream>

using namespace std;

template<class T>
class Node {
    private:
        T content;
        Node<T>* next;
        Node<T>* prev;
    public:
        Node<T>* getNext(){
            return this->next;
        }
        Node<T>* getPrev(){
            return this->prev;
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
            cout<<(*temp).getContent()<<endl;
            return (*temp).getContent();
        }
        void add(T content){
            // cout<<"setting head\n";
            Node<T>* temp = this->getHead();
            // cout<<"entering loop\n";
            int i = 0;
            while((*temp).getNext()){
                // cout<<"loop: "<<i++<<endl;
                temp = (*temp).getNext();
            }
            Node<T>* newtemp = new Node<T>();
            (*temp).setNext(newtemp);
            temp = (*temp).getNext();
            (*temp).setContent(content);
            cout<<(*temp).getContent()<<endl;
        }
        void deleteLL(){
            Node<T>* temp = this->getHead();
            if(!(*temp).getNext()){
                delete temp;
                return;
            }
            while((*temp).getNext()){
                temp = (*temp).getNext();
            }
            delete temp;
            deleteLL();
        }
};


int main() {
    LinkedList<int> dll;
    int i;
    cin>>i;
    cout<<"hello\n";
    dll.add(i);
    dll.add(++i);
    // cout<<"dll get(0): "<<dll.get(0)<<endl;
    dll.deleteLL();
    delete &dll;
    return 0;
}
