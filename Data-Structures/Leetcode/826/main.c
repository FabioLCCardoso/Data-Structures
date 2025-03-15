#include <stdlib.h>

//compare function for qsort (to compare workers)
int compareWorkers(const void *a, const void *b){
    return*(int *)a - *(int *)b ;  
}
//compare function for qsort (to compare jobs)
int compareJobs(const void *a, const void *b){
    return((int *)a)[0] - ((int* )b)[0];
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    //array to store the jobs "profile where jobs[i][0] is the difficulty and jobs[i][1] is the profit "
    int jobs[difficultySize][2];
    for(int i = 0; i < difficultySize; i++){
        //jobs[i][0] = job difficulty
        jobs[i][0] = difficulty[i];
        // jobs[i][1] = job profit
        jobs[i][1] = profit[i];
    }
    //quicksort to sort jobs by difficulty
    qsort(jobs, difficultySize, sizeof(jobs[0]), compareJobs);
    //quicksort to sort workers by their skill
    qsort(worker, workerSize, sizeof(int), compareWorkers);

    
    int maxProfit = 0, jobIndex = 0, maxjobProfit=0;

    //loop through all the workers
    for(int i = 0; i < workerSize; i++){
    //assigning jobs to workers by the diffilculty and the workers skill
        while(jobIndex < difficultySize && jobs[jobIndex][0] <= worker[i]){
            //update max profit for the highest profit
            maxjobProfit = (maxjobProfit > jobs[jobIndex][1] ? maxjobProfit : jobs[jobIndex][1] );
            jobIndex++;
        }
        //add max profit from each worker to the total
        maxProfit += maxjobProfit;
    }
    return maxProfit;
}