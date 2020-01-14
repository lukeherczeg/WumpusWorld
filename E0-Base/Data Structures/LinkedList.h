

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
			Node* temp = new Node;
			temp->data = element;
			temp->next = nullptr;
			count++;

			if (back == nullptr) {
				front = back = temp;
				return;
			}

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
			delete(temp);
		};

		void pop() {
			back = back->prev;
			delete back->next;
			count--;
		};

		void clear() {
			Iterator it = begin();
			for (it; it != end(); ++it) {
				delete it.currentNode;
				count--;
			}
		};

		bool contains(T element) const {
			Iterator it = begin();
			while (!((it == end()) && (*it == element))) {
				++it;
			}
			
			return (*it == element);
		};

		void remove(T element) {
			Iterator it = begin();
			while (it != end()) {
				if (*it == element) {
					Node* temp = it.currentNode;
					temp = temp->next;
					temp->prev = temp;
					delete temp;

					count--;
					return;
				}
				++it;
			}
		};
	};
} }  // namespace ufl_cap4053::fundamentals
