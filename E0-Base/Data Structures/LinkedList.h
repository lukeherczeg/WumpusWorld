
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
		private:
			// A node that the iterator currently points to.
			Node* currentNode; 

		public:			
			// Constructor for the Iterator.
			Iterator(Node* start) {
				currentNode = start;
			}

			// Return the element at the iterator's current position in the queue.
			T operator*() const {
				return currentNode->data;
			};
			// Pre-increment overload; advance the operator one position in the list. Return this iterator. 
			Iterator& operator++() {
				if (currentNode->next != nullptr)
					currentNode = currentNode->next;
				else
					currentNode = nullptr;

				return *this;
			};
			// Returns true it both iterators point to the same node in the list, and false otherwise.
			bool operator==(Iterator const& rhs) {
				return (currentNode == rhs.currentNode);
			};
			// Returns false it both iterators point to the same node in the list, and true otherwise.
			bool operator!=(Iterator const& rhs) {
				return (currentNode != rhs.currentNode);
			};
			// Gets the node that the iterator currently points to.
			Node* getNode() {
				return currentNode;
			}
		};

	private:
		// A sentinel front and back node, as well as count of elements in the list
		Node* front;
		Node* back;
		int count = 0;

	public:
		// This is the constructor for LinkedList.
		LinkedList<T>() {
			front = back = nullptr;
		};

		// Returns an Iterator pointing to the beginning of the list.
		Iterator begin() const {
			return Iterator(front);
		};

		// Returns an Iterator pointing past the end of the list (an invalid, unique state)
		Iterator end() const {
			if (back == nullptr)
				return Iterator(back);

			return Iterator(back->next);
		};

		// Returns true if there are no elements, false otherwise.
		bool isEmpty() const {
			return (count == 0);
		};

		// Returns the first element in the list
		T getFront() const {
			return front->data;
		};

		// Returns the last element in the list.
		T getBack() const {
			return back->data;
		};

		// Inserts the specified element to the list.
		void enqueue(T element) {
			Node* temp = new Node;
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

		// Removes the first element from the list.
		void dequeue() {
			if (front == nullptr)
				return;

			count--;
			Node* temp = front;
			front = front->next;

			if (front == nullptr) 
				back = nullptr;
			else
				front->prev = nullptr;

			delete temp;
		};

		// Removes the last element from the list.
		void pop() {
			if (back == nullptr) {
				return;
			}

			count--;
			Node* temp = back;
			back = back->prev;

			delete temp;

			if (back == nullptr) {
				front = nullptr;
				return;
			}

			back->next = nullptr;
		};

		// Removes and deletes all elements from the list.
		void clear() {
			Iterator it = begin();
			Iterator itEnd = end();

			while (it != itEnd){
				++it;
				dequeue();
			}
		};

		// Returns true if you find a node whose data equals the specified element, false otherwise
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

		// Removes the first node you find whose data equals the specified element.
		void remove(T element) {
			Iterator it = begin();
			while (it != end()) {
				if (*it == element) {
					if (front == nullptr)
						return;
					Node* temp = it.getNode();
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

		// Destructor for LinkedList
		~LinkedList<T>() {
			clear();
		};
	};
} }  // namespace ufl_cap4053::fundamentals
