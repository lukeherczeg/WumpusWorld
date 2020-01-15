#include <stdlib.h>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

// LinkedList class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {
	template <class T>
	class LinkedList {

		class Node {
		public:
			T data;
			Node* next;
			Node* prev;
		};

		class Iterator {
		public:
			Node* currentNode;
			
			Iterator(Node* start) {
				currentNode = start;
			}

			T operator*() const {
				return currentNode->data;
			};

			Iterator& operator++() {
				if (currentNode->next != nullptr)
					currentNode = currentNode->next;
				else
					currentNode = nullptr;

				return *this;
			};

			bool operator==(Iterator const& rhs) {
				return (currentNode == rhs.currentNode);
			};

			bool operator!=(Iterator const& rhs) {
				return (currentNode != rhs.currentNode);
			};
		};

	private:
		Node* front;
		Node* back;
		int count = 0;

	public:
		LinkedList<T>() {
			front = back = nullptr;
		};

		Iterator begin() const {
			return Iterator(front);
		};

		Iterator end() const {
			if (back == nullptr)
				return Iterator(back);

			return Iterator(back->next);
		};

		bool isEmpty() const {
			return (count == 0);
		};

		T getFront() const {
			return front->data;
		};

		T getBack() const {
			return back->data;
		};

		void enqueue(T element) {
			Node* temp = DBG_NEW Node;
			temp->data = element;
			temp->next = nullptr;
			count++;

			if (back == nullptr) {
				front = back = temp;
				front->prev = nullptr;
				return;
			}

			temp->prev = back;
			back->next = temp;
			back = temp;
		};

		void dequeue() {
			if (front == nullptr) {
				return;
			}

			count--;
			Node* temp = front;
			front = front->next;

			if (front == nullptr) {
				back = nullptr;
			}
			else {
				front->prev = nullptr;
			}

			delete temp;
		};

		void pop() {
			if (back == nullptr) {
				return;
			}

			count--;
			Node* temp = back;
			back = back->prev;

			if (back == nullptr) {
				delete temp->next;
				return;
			}

			delete temp->next;
			back->next = nullptr;
		};

		void clear() {
			Iterator it = begin();
			Iterator itEnd = end();

			while (it != itEnd){
				++it;
				dequeue();
			}
		};

		bool contains(T element) const {
			Iterator it = begin();
			while (it != end()) {
				if (*it == element) {
					return true;
				}
				++it;
			}
			return false;
		};

		void remove(T element) {
			Iterator it = begin();
			while (it != end()) {
				if (*it == element) {
					if (front == nullptr)
						return;
					Node* temp = it.currentNode;
					count--;

					if (front == temp)
						front = temp->next;

					if (back == temp)
						back = temp->prev;

					if (temp->next != nullptr)
						temp->next->prev = temp->prev;

					if (temp->prev != nullptr)
						temp->prev->next = temp->next;
					
					delete temp;
					return;
				}
				++it;
			}
		};
	};
} }  // namespace ufl_cap4053::fundamentals
