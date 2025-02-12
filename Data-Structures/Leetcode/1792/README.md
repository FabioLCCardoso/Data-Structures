# LeetCode 1792
-**Problem's name:** Maximum Average Pass Ratio

## Personal Info
- **Nome:** Fabio Cardoso
- **Degree:** Ciência da Computação
- **Registration:** 23200360

## Problem Description
There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

**Solution**
To solve this problem I've used a maxheap that prioritizes adding students to the class that gains the most improvement in pass ratio. The gain was calculated with the function
calculateGain: 
![calculateGain](https://github.com/user-attachments/assets/b27f6fe6-fad7-4896-81f1-9b553d7ab808)

It basically adds a hypotethical student to the class, gets the pass ratio by dividing the passing students to the total and then subtracts the new pass ration with the current one.

First it initializes the heap. each class is stored as a structure with pass, total and gain values.
then, i've used a heapify function to build the maxheap, the heap is arranged so that the class with the highest gain stays at the top.
The heapify function ensures the maxheap is maintained after the updates.

Heapify Function: 

![heapify](https://github.com/user-attachments/assets/20c39cca-34c6-4e85-900a-9099e3b76d3d)

Then, it assigns the extra students at the top class, update its pass ratio and recalculate its gain. Then restore the heap order. Repeating this until all the students are assigned.
After that it returns the sum of the pass ratio of all classes divided by the number of classes.
![maxavereageratio](https://github.com/user-attachments/assets/d0c86abe-3101-4899-8dff-f4c85682cf6b)

**Complexity Analysis**

Building the Heap: O(n) (where n is the number of classes)

Heap Operations:

Extract Max (O(log n)) for each extra student (m times)

Update and Heapify (O(log n)) for each insertion

Final Calculation: O(n)

Total Complexity: O(m log n + n)

**Test Cases:**


![image](https://github.com/user-attachments/assets/63b8e5e5-cbfc-4399-9144-835dff390f3b)


![image](https://github.com/user-attachments/assets/3887002a-a7c7-4e2d-b278-e482eba6623f)


