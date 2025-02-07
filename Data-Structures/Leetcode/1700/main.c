/*
1700 

The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

    If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
    Otherwise, they will leave it and go to the queue's end.

This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.
*/

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
       int count_0 = 0, count_1 = 0; // Counters for student preferences

    // Count number of students preferring each sandwich type
    for (int i = 0; i < studentsSize; i++) {
        if (students[i] == 0) 
            count_0++;
        else 
            count_1++;
    }

    // Process the sandwich stack
    for (int i = 0; i < sandwichesSize; i++) {
        if (sandwiches[i] == 0) {
            if (count_0 > 0) 
                // Serve a circular sandwich
                count_0--; 
            else 
            // Remaining students cannot eat
                return count_1; 
        } else {
            if (count_1 > 0) 
            // Serve a square sandwich
                count_1--; 
            else 
            // Remaining students cannot eat
                return count_0; 
        }
    }
    
    return 0; 
}
