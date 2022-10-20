
#include <bits/stdc++.h>
#include <chrono> 

namespace cstm{

/// @brief 
/// @tparam T 
/// @param __Obj 
template<typename T>
    void print(T __Obj){
        std::cout<<__Obj<<std::endl;
    }
   
class Timer{

    private:
    std::chrono::time_point<std::chrono::steady_clock> _StartingPoint,_EndingPoint;
    std::chrono::duration<float> duration;
     float _MILLISECOND;

    public:
    Timer():_MILLISECOND(0000.0f){
        start_Timer();
    }

    ~Timer(){};

    public:
    void start_Timer(){
        _StartingPoint = std::chrono::steady_clock::now();
    }
    void end_Timer(){
        _EndingPoint = std::chrono::steady_clock::now();
        duration = _EndingPoint-_StartingPoint;
        _MILLISECOND = duration.count() * 1000.0f;
    }
    float show_Time() const{
        std::cout<<_MILLISECOND<<std::endl;
        return _MILLISECOND;
    }
};

/// @brief 
/// @tparam T 
/// @param _Iterble_Obj 
template<typename T>
void for_each(T _Iterble_Obj){
    for(int i = 0 ; i < sizeof(_Iterble_Obj) ; i++){
        std::cout<<_Iterble_Obj[i]<<std::endl;
    }
}

class SmartThread{
    public:

    /// @brief 
    /// @param __Timing 
    void wait_for(int __Timing){
        std::this_thread::sleep_for(std::chrono::seconds(__Timing));
}   
    public:
template<typename T>
    void Thread_Excuter(T _Func1,T __Func2){
        std::thread __Thread1(_Func1);
        std::thread __Thread2(__Func2);
        __Thread1.join();
        __Thread2.join();
}
    public:
template<typename T>
    void Thread_Excuter(T _FirstFunc1,T __SecondFunc2,int _Time){
        std::thread __First_Thread1(_FirstFunc1);
        std::this_thread::sleep_for(std::chrono::seconds(_Time));
        std::thread __Second_Thread2(__SecondFunc2);
        __First_Thread1.join();
        __Second_Thread2.join();
}
};

 /// @brief
 /// @param size
 /// @return description of the return value
}
namespace Algorithm{

     template<typename T>
    int linearSearch(T arr[],size_t n,T target) {
        for(int i = 0 ; i < n ; i++){
            if(arr[i] == target)return i;
        }
    return -1;
    }

    int binarySearch(int arr[], int target , int l , int r){
        while(r >= l){
            int mid  = l + (r-l)/2;
            if(arr[mid] == target)
                return mid;
            if(arr[mid] > target)
                r = mid-1;
            if(arr[mid] < target)
                l = mid+1;
        }
        return -1;
    }
    void insertionSort(int arr[], int n){
	int i, key, j;
	for (i = 1; i < n; i++)
	{
	  key = arr[i];
	  j = i - 1;

	while (j >= 0 && arr[j] > key){
		arr[j + 1] = arr[j];
		j = j - 1;
	}
	arr[j + 1] = key;
	}
    }
}
namespace DS{

    class Node{
    public:
        int data;
        Node* next;

        Node(int value){
            data = value;
            next = NULL;
        }
};
class linkedList{

    Node* head;
    public:
        linkedList(){
            head = NULL;
        }
    void insertNode(int);
    void del(int);
    void print();
    void insertAfter(int,int);
    void insertTail(int);
    

};
void linkedList::insertNode(int value){

    Node* new_node = new Node(value);
    if(head == NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}
void linkedList::del(int key){
    Node* temp = head;
    Node* prev = NULL;
    if(temp != NULL && temp->data == key){
        head = temp->next;
        delete temp;
    }
    while(!temp){
        if(temp->data == key){
            prev->next = temp->next;
            delete temp;
        }
        prev = temp;
        temp = temp->next;
    }    
}
void linkedList::print(){
    using namespace std;

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void linkedList::insertAfter(int key, int value){
    Node* new_node = new Node(value);

    if(head->data == key){
        new_node->next = head->next;
        head->next =new_node;
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    new_node->next = temp;
    prev->next = new_node;
}
void linkedList::insertTail(int value){
    Node* new_node  = new Node(value);
    if(head->next == NULL){
        head->next = new_node;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}
class DPNode{
    public:
        int data;
        DPNode* next;
        DPNode* prev;
        DPNode(int value){
            data = value;
            next = NULL;
            prev = NULL;
        }
};
class doubleLinkedList{
        DPNode* head;
    public:

        doubleLinkedList(){head = NULL;}
        void insertDPNode(int);
        void insertHead(int);
        void del(int);
        void print();
        void insertAfter(int,int);
        void insertTail(int);
};
void doubleLinkedList::insertHead(int value){
    DPNode* new_DPnode = new DPNode(value);
    if(head == NULL){
        head = new_DPnode;
        new_DPnode->prev = NULL;
        return;
    }
	new_DPnode->next = head;

	if (head != NULL)
		head->prev = new_DPnode;
	
	head = new_DPnode;
}
void doubleLinkedList::insertDPNode(int value){

    if(head == NULL){
       insertHead(value);
       return;
    }
    DPNode* new_DPnode = new DPNode(value);
    DPNode* temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    new_DPnode->prev = temp;
    temp->next = new_DPnode;
    
}
void doubleLinkedList::print(){
    using namespace std;
    
	DPNode* temp = head;
    cout<<"NULL <-- ";
	while (temp != NULL){
        if(temp->next == NULL){
            cout<<temp->data <<" --> ";
            break;
        }
		cout << temp->data << " <--> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}
void doubleLinkedList::del(int key){
    DPNode* temp = head;
    if(temp->data == key){
        head = head->next;
        delete temp;
    }
    DPNode* prev = NULL;
    DPNode* tempNextPrev = NULL;
    while (temp->data != key){
        prev = temp; // temp prev 
        temp = temp->next;// temp
        tempNextPrev = temp; // temp next
    }
    prev->next = temp->next; // prev next = temp next
    tempNextPrev->prev = prev; // temp next = prev

}
void doubleLinkedList::insertAfter(int key , int value){
    DPNode* new_DPnode = new DPNode(value);
    if(head == NULL){
        insertHead(value);
        return;
    }
    DPNode* temp = head;
    DPNode* prev = NULL;
    while(temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    new_DPnode->next = temp;
    new_DPnode->prev = temp->prev;
    prev->next = new_DPnode;
    temp->prev = new_DPnode;
}
void doubleLinkedList::insertTail(int value){
    DPNode* new_DPnode = new DPNode(value);
    if(head == NULL){
        insertHead(value);
        return;
    }
    DPNode* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    new_DPnode->prev = temp;
    temp->next = new_DPnode;
    new_DPnode->next = NULL;
}

class BST{
    public:
        int data;
        BST* right;
        BST* left;
    
    BST(int val):data(val),right(NULL),left(NULL){}
    BST();
    BST* search(BST*,int);
    BST* insert(BST*,int);
    void inorder(BST*);

};
BST ::BST(): data(0), left(NULL), right(NULL){}

BST* BST::insert(BST* root, int key){
    if(root == NULL)
        return new BST(key);

    if(root->data < key)
        root->right = insert(root->right,key);

    if(root->data > key)
        root->left = insert(root->left,key);
    
    return root;
}

BST* BST::search(BST* root,int key){
    if(root == NULL || root->data == key)
        return root;
    if(root->data < key)
        return search(root->right,key);
    
    return search(root->left,key);
}

void BST::inorder(BST* root){

    if(!root)
        return;
    
    inorder(root->left);
    std::cout<<root->data<<std::endl;
    inorder(root->right);
}
	
}
