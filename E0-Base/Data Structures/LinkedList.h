

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
		Node* head;
		Node* tail;

	public:
		LinkedList<T>() {
			head = new Node;
			tail = new Node;
			head->next = tail;
			tail->prev = header;
		};

		Iterator begin() const {
			return Iterator(head->next);
		};

		Iterator end() const {
			return Iterator(tail);
		};

		bool isEmpty() const {
			return (head == nullptr);
		};

		T getFront() const {
			return head->data;
		};

		T getBack() const {
			return tail->data;
		};

		void enqueue(T element) {
			if (head == NULL) {
				head = new Node();
				head->data = element;
				tail = head;
				return;
			}
			tail->next = new Node();
			tail->next->data = element;
			tail = tail->next;
		};

		void dequeue() {
			
		};

		void pop() {
			tail = tail->previous;
			delete tail->next;
		};

		void clear() {
			Iterator it = this->begin();
			for (it; it != this->end(); it++) {
				delete it->currentNode;
			}
		};

		bool contains(T element) const {
			Iterator it = this->begin();
			while (!(this->end()) && (it->currentNode->data == element)) {
				it++;
			}
			
			return (it->currentNode->data == element);
		};

		void remove(T element) {
			Iterator it = this->begin();
			while (!(this->end()) && (it->currentNode->data == element)) {
				it++;
			}

			if (it->currentNode->data == element) {
				delete it->currentNode;
			}
		};
	};
} }  // namespace ufl_cap4053::fundamentals
