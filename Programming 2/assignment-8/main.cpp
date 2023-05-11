template<class KEY_TYPE, class DATA_TYPE>
class BST {
public:
    struct Node {
        KEY_TYPE key;
        DATA_TYPE data;

        Node *left;
        Node *right;

        Node() {}

        Node(KEY_TYPE key, DATA_TYPE data) {
            this->key = key;
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

    class Queue {
    public:
        Node **nodeArr;
        int front;
        int rear;

        Queue(int size) {
            nodeArr = new Node *[size];
            front = 0;
            rear = 0;
        }

        ~Queue() {
            delete[] nodeArr;
        }

        void Pop() {
            for (int i = 0; i < rear - 1; i++) {
                nodeArr[i] = nodeArr[i + 1];
            }
            rear--;
        }

        void Push(Node *node) {
            nodeArr[rear] = node;
            rear++;
        }

        Node *Front() {
            return *(nodeArr + front);
        }

        bool Empty() {
            return front == rear;
        }
    };

    Node *root;

    BST() {
        root = NULL;
    }

    ~BST() {
        if (root == NULL) return;
        recursiveDestructor(root);
        root = NULL;
    }

    void recursiveDestructor(Node *node) {
        if (node == NULL) return;
        recursiveDestructor(node->left);
        recursiveDestructor(node->right);
        delete node;
        node = NULL;
    }

    bool Insert(KEY_TYPE key, DATA_TYPE data) {
        if (root == NULL) {
            root = new Node(key, data);
            return true;
        } else {
            Node *tempNode = root;
            while (tempNode != NULL) {
                if (!(key < tempNode->key || tempNode->key < key)) {
                    return false;
                } else if (key < tempNode->key && tempNode->left == NULL) {
                    tempNode->left = new Node(key, data);
                    return true;
                } else if (key < tempNode->key) {
                    tempNode = tempNode->left;
                } else if (tempNode->key < key && tempNode->right == NULL) {
                    tempNode->right = new Node(key, data);
                    return true;
                } else {
                    tempNode = tempNode->right;
                }
            }
        }
    }

    DATA_TYPE *Search(KEY_TYPE key) {
        if (root == NULL) {
            return NULL;
        } else {
            Node *tempNode = root;
            while (tempNode != NULL) {
                if (!(key < tempNode->key || tempNode->key < key)) {
                    return &tempNode->data;
                } else if (key < tempNode->key && tempNode->left == NULL) {
                    return NULL;
                } else if (key < tempNode->key) {
                    tempNode = tempNode->left;
                } else if (tempNode->key < key && tempNode->right == NULL) {
                    return NULL;
                } else {
                    tempNode = tempNode->right;
                }
            }
        }
    }

    bool Delete(KEY_TYPE key) {
        if (root == NULL) return false;
        if (Search(key) == NULL) return false;
        root = recursiveDelete(root, key);
        return true;
    }

    Node *minNode(Node *node) {
        Node *temp = node;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }

    Node *recursiveDelete(Node *node, KEY_TYPE key) {
        if (node == NULL)  {
            return NULL;
        } else if (key < node->key) {
            node->left = recursiveDelete(node->left, key);
            return node;
        } else if (node->key < key) {
            node->right = recursiveDelete(node->right, key);
            return node;
        }
        if (node->left == NULL) {
            Node *temp = node->right;
            delete node;
            return temp;
        } else if (node->right == NULL) {
            Node *temp = node->left;
            delete node;
            return temp;
        } else {
            Node *tempsParent = node;

            Node *temp = node->right;

            while(temp->left != NULL) {
                tempsParent = temp;
                temp = temp->left;
            }

            if (tempsParent != node) {
                tempsParent->left = temp->right;
            } else {
                tempsParent->right = temp->right;
            }

            node->key = temp->key;
            node->data = temp->data;

            delete temp;
            return node;
        }
    }

    void PreOrder() {
        recursivePreOrder(root);
    }

    void recursivePreOrder(Node *node) {
        if (node == NULL) return;
        //cout << node->key << " " << node->data << ",";
        cout << node->key << node->data;
        recursivePreOrder(node->left);
        recursivePreOrder(node->right);
    }

    void InOrder() {
        recursiveInOrder(root);
    }

    void recursiveInOrder(Node *node) {
        if (node == NULL) return;
        recursiveInOrder(node->left);
        cout << node->key << node->data;
        recursiveInOrder(node->right);
    }

    void PostOrder() {
        recursivePostOrder(root);
    }

    void recursivePostOrder(Node *node) {
        if (node == NULL) return;
        recursivePostOrder(node->left);
        recursivePostOrder(node->right);
        cout << node->key << node->data;
    }

    void LevelOrder() {
        if (root == NULL) return;

        int i = 4;
        for (int j = 2; j < Height(); j++) {
            i *= j;
        }

        Queue *queue = new Queue(i);

        queue->Push(root);

        while (!queue->Empty()) {
            Node *node = queue->Front();
            cout << node->key << node->data;
            queue->Pop();

            if (node->left != NULL) {
                queue->Push(node->left);
            }

            if (node->right != NULL) {
                queue->Push(node->right);
            }
        }

        delete queue;
    }

    int Height() {
        if (this->root == NULL) return -1;

        return recursiveHeight(root);
    }

    int recursiveHeight(Node *node) {
        if (node == NULL) return -1;

        int leftHeight = this->recursiveHeight(node->left);
        int rightHeight = this->recursiveHeight(node->right);

        if (rightHeight < leftHeight) return leftHeight + 1;
        else return rightHeight + 1;
    }
};