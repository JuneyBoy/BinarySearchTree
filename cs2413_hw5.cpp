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
};

class BinarySearchTree{
    private:
        Key* root;
    public:
        BinarySearchTree(Key* root){
            this->root = root;
        }

        bool search(int keyVal){
            bool keyExists = false;

            Key* currNode = this->root;

            while(currNode != nullptr){
                if(currNode->get_key_val() == keyVal){
                    keyExists = true;
                    break;
                }
                else if(currNode->get_key_val() > keyVal){
                    currNode = currNode->get_left_child();
                }
                else{
                    currNode = currNode->get_right_child();
                }
            }
            return keyExists;
        }

        bool add_node(Key* node){
            bool nodeExists = false;

            Key* currNode = this->root;

            while(currNode != nullptr){
                if(currNode->get_key_val() == node->get_key_val()){
                    nodeExists = true;
                    return nodeExists;
                }

                else if (currNode->get_key_val() > node->get_key_val()){
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

            return nodeExists;

        }
};

int main(){

}