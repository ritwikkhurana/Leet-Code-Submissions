class Node {
    public int key;
    public int value;
    public Node left;
    public Node right;

    public Node(int key, int value) {
        this.key = key;
        this.value = value;
        left = null;
        right = null;
    }
}

class LRUCache {
    public int cap;
    public Map<Integer, Node> cache = new HashMap<>();
    public Node head;
    public Node tail;

    public LRUCache(int capacity) {
        this.cap = capacity;
        cache.clear();
        head = null;
        tail = null;
    }

    public void updatePos(Node node) {
        if (node != head) {
            node.left.right = node.right;
            if (node == tail) {
                tail = node.left;
            } else {
                node.right.left = node.left;
            }
            node.left = null;
            add(node);
        }
    }

    public void add(Node node) {
        if (head == null) {
            head = node;
            tail = node;
        } else {
            node.right = head;
            head.left = node;
            head = node;
        }
    }

    public void remove() {
        if (head == tail) {
            head = null;
            tail = null;
        } else {
            tail.left.right = null;
            tail = tail.left;
        }
    }
    
    public int get(int key) {
        if (!cache.containsKey(key)) return -1;
        Node node = cache.get(key);
        updatePos(node);
        return node.value;
    }
    
    public void put(int key, int value) {
        if (cache.containsKey(key)) {
            Node node = cache.get(key);
            node.value = value;
            updatePos(node);
        } else {
            if (cache.size() == cap) {
                cache.remove(tail.key);
                remove();
            }
            Node newNode = new Node(key, value);
            cache.put(key, newNode);
            add(newNode);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */