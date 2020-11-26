#include <iostream>
#include <vector>

using namespace std;

class Key{
    private:
        int keyVal;
        Key* parent;
        Key* leftChild;
        Key* rightChild;
    
    public:
        
        Key(int keyVal){
            this->keyVal = keyVal;
            this->parent = nullptr;
            this->leftChild = nullptr;
            this->rightChild = nullptr;
        }

        int get_key_val(){
            return this->keyVal;
        }

        Key* get_parent(){
            return this->parent;
        }

        Key* get_left_child(){
            return this->leftChild;
        }

        Key* get_right_child(){
            return this->rightChild;
        }

        void set_key_val(int keyVal){
            this->keyVal = keyVal;
        }

        void set_parent(Key* parent){
            this->parent = parent;
        }

        void set_left_child(Key* child){
            this->leftChild = child;
        }

        void set_right_child(Key* child){
            this->rightChild = child;
        }

        void print_val(){
            cout << this->get_key_val() << " ";
        }
};

class Stack{
    private:
        vector<int> list;
    public:
        void push(int val){
            list.push_back(val);
        }
        void pop(){
            int val = list.back();
            list.pop_back();
            cout << val << " ";
        }
};

class BinarySearchTree{
    private:
        Key* root;
        Stack* bstStack = new Stack();
    public:
        BinarySearchTree(Key* root){
            this->root = root;
        }

        Key* get_root(){
            return this->root;
        }

        Key* search(int keyVal){
            bool keyExists = false;

            Key* currNode = this->root;

            while(currNode != nullptr){
                if(currNode->get_key_val() == keyVal){
                    return currNode;
                }
                else if(currNode->get_key_val() > keyVal){
                    currNode = currNode->get_left_child();
                }
                else{
                    currNode = currNode->get_right_child();
                }
            }
            return nullptr;
        }

        bool add_node(Key* node){

            if(this->search(node->get_key_val()) != nullptr){
                return false;
            }

            Key* currNode = this->root;

            while(currNode != nullptr){

                if (currNode->get_key_val() > node->get_key_val()){
                    if(currNode->get_left_child() == nullptr){
                        currNode->set_left_child(node);
                        break;
                    }
                    currNode = currNode->get_left_child();
                }

                else {
                    if(currNode->get_right_child() == nullptr){
                        currNode->set_right_child(node);
                        break;
                    }
                    currNode = currNode->get_right_child();
                }
            }

            return true;

        }

        bool remove_node(int keyVal){
            Key* nodeToRemove = this->search(keyVal);

            if(nodeToRemove == nullptr){
                return false;
            }

            Key* parent = nodeToRemove->get_parent();

            if(nodeToRemove->get_left_child() == nullptr && nodeToRemove->get_right_child() == nullptr){
                if(nodeToRemove == this->root){
                    this->root = nullptr;
                }
                else if(nodeToRemove == parent->get_left_child()){
                    parent->set_left_child(nullptr);
                }
                else{
                    parent->set_right_child(nullptr);
                }
            }

            else if(nodeToRemove->get_right_child() == nullptr){
                if(nodeToRemove == this->root){
                    this->root = nodeToRemove->get_left_child();
                }
                else if(nodeToRemove == parent->get_left_child()){
                    parent->set_left_child(nodeToRemove->get_left_child());
                }
                else{
                    parent->set_right_child(nodeToRemove->get_left_child());
                }
            }

            else if(nodeToRemove->get_left_child() == nullptr){
                if(nodeToRemove == this->root){
                    this->root = nodeToRemove->get_right_child();
                }
                else if(nodeToRemove == parent->get_left_child()){
                    parent->set_left_child(nodeToRemove->get_right_child());
                }
                else{
                    parent->set_right_child(nodeToRemove->get_right_child());
                }
            }

            else{
                Key* successor = nodeToRemove->get_right_child();
                while(successor->get_left_child() != nullptr){
                    successor = successor->get_left_child();
                }
                int successorVal = successor->get_key_val();
                this->remove_node(successor->get_key_val());
                nodeToRemove->set_key_val(successorVal);
            }
            return true;
        }

        void enumerate(Key* node){
            if(node == nullptr){
                return;
            }

            this->bstStack->push(node->get_key_val());

            enumerate(node->get_left_child());
            enumerate(node->get_right_child());

            this->bstStack->pop();

        }
};

int main(){
    Key* key = new Key(5);
    Key* key2 = new Key(0);
    Key* key3 = new Key(7);

    BinarySearchTree* BST = new BinarySearchTree(key);

    BST->add_node(key2);
    BST->add_node(key3);

    BST->enumerate(BST->get_root());

    /**
    Stack* stack = new Stack();

    stack->push(5);
    stack->push(0);
    stack->pop();
    stack->push(7);
    stack->pop();
    stack->pop();
    **/

    

}