class MyLinkedList {
    private:
        struct Node {
            int val;
            Node* next;
            Node(int x) : val(x), next(nullptr) {}
        };
    
        Node* head;
        int size;
    
    public:
        MyLinkedList() {
            head = nullptr;
            size = 0;
        }
    
        int get(int index) {
            if (index < 0 || index >= size) return -1;
            Node* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            return current->val;
        }
    
        void addAtHead(int val) {
            Node* node = new Node(val);
            node->next = head;
            head = node;
            size++;
        }
    
        void addAtTail(int val) {
            Node* node = new Node(val);
            if (!head) {
                head = node;
            } else {
                Node* current = head;
                while (current->next) {
                    current = current->next;
                }
                current->next = node;
            }
            size++;
        }
    
        void addAtIndex(int index, int val) {
            if (index > size) return;
            if (index <= 0) {
                addAtHead(val);
            } else if (index == size) {
                addAtTail(val);
            } else {
                Node* node = new Node(val);
                Node* current = head;
                for (int i = 0; i < index - 1; i++) {
                    current = current->next;
                }
                node->next = current->next;
                current->next = node;
                size++;
            }
        }
    
        void deleteAtIndex(int index) {
            if (index < 0 || index >= size) return;
    
            if (index == 0) {
                Node* toDelete = head;
                head = head->next;
                delete toDelete;
            } else {
                Node* current = head;
                for (int i = 0; i < index - 1; i++) {
                    current = current->next;
                }
                Node* toDelete = current->next;
                current->next = current->next->next;
                delete toDelete;
            }
            size--;
        }
    };
    