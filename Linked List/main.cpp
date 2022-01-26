#include <iostream>

class LinkedList
{
public:
    LinkedList()
    {
        root = nullptr;
    }
    
    LinkedList(int key)
    {
        root = new Node(key);
    }
    
    void AddLast(int key)
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return;
        }
        
        Node* temp = root;
        
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        
        temp->next = new Node(key);
    }
    
    void AddFirst(int key)
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return;
        }
        
        Node* temp = new Node(key);
        temp->next = root;
        root = temp;
    }
    
    void RemoveFirst()
    {
        if (root == nullptr) return;
        
        Node* temp = root->next;
        root = temp;
    }
    
    void RemoveLast()
    {
        if (root == nullptr) return;
        
        Node* temp = root;
        
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        
        delete (temp->next);
        temp->next = nullptr;
    }
    
    int IndexOf(int key)
    {
        if (root == nullptr) return -1;
        
        Node* temp = root;
        int count = 0;
        
        while(temp != nullptr)
        {
            if (temp->key == key)
            {
                return count;
            }
            temp = temp->next;
            count++;
        }
        
        return -1;
    }
    
    bool Contains(int key)
    {
        if (root == nullptr) return false;
        
        Node* temp = root;
        
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return true;
            }
            
            temp = temp->next;
        }
        return false;
    }
    
    void RemoveDuplicates()
    {
        if (root == nullptr) return;
        
        Node* temp = root;
        
        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->key == temp->next->key)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    
    void PrintNodes()
    {
        if (root == nullptr) return;
        
        Node* temp = root;
        int count = 0;
        
        while (temp != nullptr)
        {
            printf("[%d] %d\n", count, temp->key);
            temp = temp->next;
            count++;
        }
    }
    
    int FirstElement()
    {
        if (root == nullptr) return -1;
        return root->key;
    }
    
    int LastElement()
    {
        if (root == nullptr) return -1;
        
        Node* temp = root;
        
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        
        return temp->key;
    }
    
private:
    struct Node
    {
        Node(int key) : key(key) {};
        Node *next;
        int key;
    };
    
    Node* root = nullptr;
};


int main(int argc, const char * argv[]) {
    // Declaring our ListNode.
    LinkedList* ListNode = new LinkedList;
    
    // Adding nodes to end.
    ListNode->AddLast(10);
    ListNode->AddLast(20);
    ListNode->AddLast(30);
    ListNode->AddLast(40);
    ListNode->AddLast(50);
    ListNode->AddLast(50);
    ListNode->AddLast(50);
    
    // Removes the duplicates.
    ListNode->RemoveDuplicates();
    
    // Adding nodes to start.
    ListNode->AddFirst(1);
    
    // Printing out functions.
    printf("FirstElement(): %d\n", ListNode->FirstElement());
    printf("LastElement(): %d\n", ListNode->LastElement());
    printf("IndexOf(30): %d\n", ListNode->IndexOf(30));
    printf("Contains(20): %s\n", ListNode->Contains(20) ? "True" : "False");
    
    // Printing all nodes.
    ListNode->PrintNodes();
    
    // Return 0.
    return 0;
}
