

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
			front = new Node;
			back = new Node;
			front->next = nullptr;
			back->prev = nullptr;
		};

		Iterator begin() const {
			return Iterator(front->next);
		};

		Iterator end() const {
			return Iterator(back);
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

			temp->next = front;
			temp->prev = nullptr;

			if (front != nullptr) {
				front->prev = temp;
			}

			front = temp;
			count++;
		};

		void dequeue() {
			
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
			while (!((it.currentNode == end().currentNode) && (it.currentNode->data == element))) {
				++it;
			}
			
			return (it.currentNode->data == element);
		};

		void remove(T element) {
			Iterator it = begin();
			while (!(it.currentNode == end().currentNode)) {
				++it;
			}

			if (it.currentNode->data == element) {
				delete it.currentNode;
				count--;
			}
		};
	};
} }  // namespace ufl_cap4053::fundamentals
