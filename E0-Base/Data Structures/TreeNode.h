#include <vector>
#include <queue>
using std::vector;
using std::queue;

namespace ufl_cap4053 { namespace fundamentals {
	template <class T>
	class TreeNode {

	private:
		// A vector to store children nodes
		vector<TreeNode*> children;

		// A value to store data
		T data;

		// Private kickoff preOrder traversal function that takes in a TreeNode and the datafunction
		void preOrder(const TreeNode* currentNode, void (*dataFunction)(const T)) const {

			dataFunction(currentNode->getData());

			for (const TreeNode* child : currentNode->children)
				preOrder(child, dataFunction);
		}

		// Private kickoff postOrder traversal function that takes in a TreeNode and the datafunction
		void postOrder(const TreeNode* currentNode, void (*dataFunction)(const T)) const {

			for (const TreeNode* child : currentNode->children)
				postOrder(child, dataFunction);

			dataFunction(currentNode->getData());
		}

	public:
		// Constructor for TreeNode. Should store a default - constructed data value and start with no children.
		TreeNode<T>() {
			this->data = 0;
		}

		// Constructor for TreeNode. Should store element as its data value and start with no children.
		TreeNode<T>(T element) {
			this->data = element;
		}

		// Returns a reference to the stored data.
		const T& getData() const {
			return this->data;
		}

		// Returns the number of children of this node.
		size_t getChildCount() const {
			size_t count = 0;
			for (TreeNode* child : this->children)
				count++;

			return count;
		}

		// Returns the child node specified by index.
		TreeNode<T>* getChild(size_t index) {
			if (children[index] != nullptr)
				return this->children[index];
			else
				return nullptr;
		}

		// Returns the child node specified by index. Note: this is the const version of this method.
		TreeNode<T>* getChild(size_t index) const {
			if (children[index] != nullptr)
				return this->children[index];
			else
				return nullptr;
		}

		// Add child to the children of this node.
		void addChild(TreeNode<T>* child) {
			this->children.push_back(child);
		}

		// Remove the child node at specified by index.
		void removeChild(size_t index) {
			TreeNode* child = this->children[index];
			size_t numChildren = child->getChildCount();

			if (numChildren != 0) {
				for (TreeNode* childOfChild : child->children) {
					delete childOfChild;
				}
			}
			delete child;
		}

		// Breadth - first traversal starting at this node. Calls dataFunction on the element to process it.
		void breadthFirstTraverse(void (*dataFunction)(const T)) const {
			queue<const TreeNode*> q;
			q.push(this); // 'this' is the root node to begin the traversal.

			while (!q.empty()) {
				const TreeNode* current = q.front();
				q.pop();

				dataFunction(current->getData());

				for (const TreeNode* child : current->children)
					q.push(child);
			}
		}

		// These two functions below call private kickoff functions to perform the traversals with 
		// the recursion suggested in the manual provided to us.

		// Pre - order traversal starting at this node. Calls dataFunction on the element to process it.
		void preOrderTraverse(void (*dataFunction)(const T)) const {
			preOrder(this, dataFunction);
		}

		// Post - order traversal starting at this node. Calls dataFunction on the element to process it.
		void postOrderTraverse(void (*dataFunction)(const T)) const {
			postOrder(this, dataFunction);
		}
	};
}}  // namespace ufl_cap4053::fundamentals
