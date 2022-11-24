#include <iostream>
#include <list>
#include <vector>
using namespace std;


template <typename T>
class DoublyLinkedList {
public:
	struct Node {
		Node* prev;
		Node* next;
		T data;
		Node(Node* prev, Node* next, T data)
			: prev(prev), next(next), data(data) {}
		Node() : prev(nullptr),next(nullptr),data(false){}
	};
private:
	Node* head;
	Node* tail;
	unsigned long long int size;
public:
	DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
	
	~DoublyLinkedList() {
		if (size == 0) { return; }
		Node* temp;
		for (Node* node = head->next; node != nullptr;) {
			temp = node->next;
			delete node;
			node = temp;
		}
	}
	void push_back(T data) {
		if (head == nullptr) {
			head = new Node(nullptr, nullptr, data);
			tail = head;
		}
		else {
			tail->next = new Node(tail, nullptr, data);
			tail = tail->next;
		}
		size++;
	}
	T& front() {
		return head->data;
	}
	T& back() {
		return tail->data;
	}
	void push_front(T data) {
		Node* newHead = new Node(nullptr, head, data);
		if (size > 0) {
			head->prev = newHead;
		}
		head = newHead;
		if (tail == nullptr) {
			tail = head;
		}
		size++;
	}
	Node* begin() {
		return head;
	}
	void pop_back() {
		if (tail)
		{
			Node* nodeToDelete = tail;
			tail = tail->prev;

			if (tail)
			{
				tail->next = nullptr;
			}
			else
			{
				head = nullptr;
			}

			delete nodeToDelete;
			size--;
		}
	}
	
	void manipulate(Node* ptr) {
		if (ptr == head) {
			return;
		}
		else if (ptr == tail) {
			tail = ptr->prev;
			tail->next = nullptr;
			tail->prev = ptr->prev->prev;
		}
		else {
			ptr->prev->next = ptr->next;

			ptr->next->prev = ptr->prev;
		}

	}
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t maxSize, T;
    cin >> T >> maxSize;
    DoublyLinkedList<size_t> packages{};

    size_t currentSize = 0;
    size_t current = 0;
	DoublyLinkedList<size_t>::Node* ptrs[100001] {nullptr};
    for (unsigned long long int i = 0; i < T; i++)
    {
        cin >> current;
        
        
        auto address = ptrs[current];
        
        bool consists = address != nullptr;
        cout << boolalpha << consists << '\n';
        if (consists) {
			packages.manipulate(address);
			if (address != packages.begin()) {
				packages.push_front(current);
				ptrs[current] = packages.begin();
			}
            
        }
        else {
            if (currentSize < maxSize) {
                
                packages.push_front(current);
                currentSize++;
				ptrs[current] = packages.begin();

            }
            else {
                size_t temporary = packages.back();
                ptrs[temporary] = nullptr;
                packages.pop_back();
                
                packages.push_front(current);
				ptrs[current] = packages.begin();


            }
        }
        
    }
    
}




