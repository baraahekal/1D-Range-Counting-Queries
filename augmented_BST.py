class Node:
    def __init__(self, key):
        self.key = key
        self.left = self.right = None
        self.size = 1  # Augmentation


# Function time-complexity: O(log(n))
def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    elif key > root.key:
        root.right = insert(root.right, key)
    root.size = 1 + size(root.left) + size(root.right)  # Update size
    return root


# Function time-complexity: O(1)
def size(node):
    return node.size if node else 0


# Function time-complexity: O(log(n))
def rank(x, node):
    if not node:
        return 0
    elif x <= node.key:
        return rank(x, node.left)
    else:
        return rank(x, node.right) + size(node.left) + 1


# Function time-complexity: O(log(n))
def contains(x, node):
    if not node:
        return False
    elif x == node.key:
        return True
    elif x < node.key:
        return contains(x, node.left)
    else:
        return contains(x, node.right)


def main():
    values = [1, 2, 3, 4, 5, 6]
    root = None
    for value in values:
        root = insert(root, value)

    low = 2
    hi = 7

    result = rank(hi, root) - rank(low, root) + 1 if contains(hi, root) else rank(hi, root) - rank(low, root)
    print(result)


if __name__ == '__main__':
    main()
