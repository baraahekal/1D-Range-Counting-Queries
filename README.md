# 1D Range Counting Queries Problem

## 🎥 [Youtube Video](https://youtu.be/tJUoeyNMZEM?si=AiKe3q6EgG3saD3X)

## 🗓️ Problem Description

The 1D range counting problem involves counting the number of elements within a specified range in a one-dimensional dataset. This is a fundamental problem in computational geometry and databases, often addressed through range queries.

## 📚 Which Data Structure to Use?

### Naive Solution: I will not use extra space (DS), i will just [Binary Search](1D_range_query_binarySearch.cpp) on it

Initially, Binary Search seems efficient for 1D Range Counting Queries on a sorted dataset. However, it falls short with dynamic operations like insertions and deletions, disrupting the sorted order.

### ⚡️ Better Option: [Binary Search Tree](augmented_BST.py) (BST)

For handling dynamic datasets, a Binary Search Tree (BST) is more suitable. BSTs allow for efficient insertions and deletions while maintaining an ordered structure, making them an optimal choice for 1D Range Counting Queries with changing data.

## Comparison

| Data Structure        | Insertion          | Removal           | Range Counting     | Space Complexity   |
| --------------------- | ------------------ | ------------------ | ------------------ | ------------------ |
| Unordered Array       | Amortized O(1)     | O(n)              | O(n)              | O(1)               |
| Ordered Array         | O(n)              | O(n)              | O(log(n))      | O(1)               |
| Binary Search Tree    | O(log(n))      | O(log(n))      | O(log(n))      | O(n)               |

### Insertion node (17) in BST Demonestration
![BST insertion_gif](assets/BSTInsert.gif)
