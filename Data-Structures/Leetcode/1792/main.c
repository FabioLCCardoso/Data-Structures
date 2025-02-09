//Leetcode 1729

/*
There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.
*/



/* classes is a 2d array [[x,y], [w,z]]
    classes[i][0] = classes[i][pass]
    classes[i][1] = classes[i][total]

    pass ratio = pass / total

    average pass ratio = ( total ratio  / num of classes) */

// structure to store class data and its gain when new students are added
typedef struct {
    int pass;
    int total;
    double gain;
} Class;

// compare function for the max-heap (based on the gain in pass ratio)
int compare(const void *a, const void *b) {
    double diff = ((Class *)b)->gain - ((Class *)a)->gain;
    return (diff > 0) - (diff < 0);
}

//calculate the gain for a class if we add one more student
double calculateGain(int pass, int total) {
    double current_ratio = (double)pass / total;
    double new_ratio = (double)(pass + 1) / (total + 1);
    return new_ratio - current_ratio;
}
    //heapify function 
void heapify(Class *heap, int index, int heapSize){

    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    //compare with left child

    if(left < heapSize && heap[left].gain > heap[largest].gain ){
        largest = left;
    }
    
    //compare with right child

    if(right < heapSize && heap[right].gain > heap[largest].gain ){
        largest = right;
    }

    // if largest is not the current index, swap and continue heapifying
    if (largest != index) {
        Class temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;

        //recursisvely call the childs to maintain maxheap  
        heapify(heap, largest, heapSize);
    }

    }

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    
        //allocate memory for the heap

        Class *heap = (Class *)malloc(classesSize * sizeof(Class));
        //tests if memory was successfully allocated
        if(!heap){
            exit(EXIT_FAILURE);
        }
        
        //fill the heap with data and calculate the gain
        for (int i = 0; i < classesSize; i++){
        int pass = classes[i][0];
        int total = classes[i][1];
        heap[i].pass = pass;
        heap[i].total = total;
        heap[i].gain = calculateGain(pass, total);
        
        }

        //build the max heap

        for(int i = classesSize / 2 - 1 ; i >= 0; i--){
            heapify(heap, i, classesSize);
        }

        //assign extra students

        for(int i = 0; i < extraStudents; i++){

            //add an extra student to the class with the maximun gain
            heap[0].pass += 1;
            heap[0].total += 1; 

            //recalculate  gain for the updated classes
            heap[0].gain = calculateGain(heap[0].pass, heap[0].total);

            //heapify after modifying the root
            heapify(heap, 0, classesSize);
            
        }

        //calculate the avg pass ratio
        double totalRatio = 0;
        for( int i = 0; i < classesSize; i++){
            totalRatio += (double)heap[i].pass/heap[i].total;
        }

        free(heap);

        return totalRatio / classesSize;
    }



