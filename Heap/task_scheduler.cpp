// 621. Task Scheduler

class Solution {

// this is a non intuitive approach.
// we mainatin a max heap and pop the max freq task, then
// see if it can be used at current time, once we use it,
// we don't push it back to heap, but to a waiting queue.
// and each time, check if some task of waiting queue can be
// completed now, then push it into heap.
public:
    int leastInterval(vector<char>& tasks, int n) {

        int curr_time = 0;

        // the first part is frequency and the second
        // it the bounded time untill which this task
        // has to wait(as the same task was used earlier)
        priority_queue<pair<int, int>> heap;
        queue<pair<int, int> > waiting;

        vector<int> task_frequency(27,0);
        for(auto task: tasks){
            task_frequency[task - 'A']++;
        }

        for(int i= 0; i<27; i++){

            if(task_frequency[i])
                heap.push({task_frequency[i], 0});
        }

        while(!heap.empty() || !waiting.empty()){

            curr_time++;
            if(!heap.empty()){

                auto curr_task = heap.top();
                heap.pop();
                if(--curr_task.first){

                    // the top task has been performed, still if
                    // has more frequency, then push this into waiting
                    // with time bound of n + curr_time;
                    waiting.push({curr_task.first, n + curr_time});
                }
            }

            // when bound time is eqaul to curr time, we push element
            // into the heap as it can be used in the next cycle.
            while(!waiting.empty() && waiting.front().second == curr_time){

                auto task = waiting.front();
                waiting.pop();
                heap.push({task.first, 0});
            }
        }

        return curr_time;
    }
};
