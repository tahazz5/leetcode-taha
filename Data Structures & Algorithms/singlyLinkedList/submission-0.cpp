struct Node {
    Node* next = nullptr;
    int val;

    explicit Node(int value = 0) : val(value) {}
};

class LinkedList {
    Node* list;

public:
    LinkedList() : list(new Node()) {}

    ~LinkedList() {
        while (list != nullptr) {
            Node* next = list->next;
            delete list;
            list = next;
        }
    }

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    int get(int index) const {
        if (index < 0) {
            return -1;
        }

        const Node* curr = list->next;
        for (int i = 0; i < index && curr != nullptr; ++i) {
            curr = curr->next;
        }

        return curr == nullptr ? -1 : curr->val;
    }

    void insertHead(int val) {
        Node* node = new Node(val);
        node->next = list->next;
        list->next = node;
    }

    void insertTail(int val) {
        Node* curr = list;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new Node(val);
    }

    bool remove(int index) {
        if (index < 0) {
            return false;
        }

        Node* prev = list;
        for (int i = 0; i < index && prev->next != nullptr; ++i) {
            prev = prev->next;
        }

        Node* target = prev->next;
        if (target == nullptr) {
            return false;
        }

        prev->next = target->next;
        delete target;
        return true;
    }

    std::vector<int> getValues() const {
        std::vector<int> values;
        for (const Node* curr = list->next; curr != nullptr; curr = curr->next) {
            values.push_back(curr->val);
        }
        return values;
    }
};
