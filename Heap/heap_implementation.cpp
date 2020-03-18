#include<bits/stdc++.h>
#define ll long long

using namespace std;

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	j = *a;
}

class minHeap
{
	int * heap;
	int capacity;
	int size;

	void minHeap(int cap)
	{
		int * heap = new int[cap + 1];
		capacity = cap;
		size = 0;
	}

	void insert(int i);

	void Heapify(int i);

	void getMini()
	{
		return heap[0];
	}

	int extractMin();

	int decreasekey(int i, int new_value);

	int delete(int i);


	int parent(int i)
	{
		return (i-1)/2;
	}

	int left(int i)
	{
		return (2*i + 1);
	}

	int right(int i)
	{
		return (2*i + 2);
	}

}


	void minHeap::insert(int i)
	{
		if(size==capacity)
			{
				cout << "Error! Can not add, size overflow";
				return;
			}
			
		size++;
        int j = size - 1;

        heap[j-1] = i;

        while(j>=0 && heap[j] < heap[parent(j)])
        {
        	swap(&heap[j],&heap[parent(j)]);
        	j = parent(j);
        }
				
	}


	// Considers already a heap
	// takes in the pointer to head
	void minHeap::Heapify(int i)
	{
      
      int l = left(i);
      int r = right(i);
      
      if(size==1)
      	return;

      int temp = i;

      if(l < size && heap[l] < heap[i])
      {      temp = l; }        

      if(r < size && heap[r] < heap[temp])
      	{     temp = r;    }

	  if(temp!=i)
	  {
	  	swap(&heap[temp], &heap[i]);
	  	Heapify(temp);
	  }    			 		

	}



	void minHeap::extractMin()
	{

		if(size <= 0)
			return INT_MAX;

		if(size == 1)
		{
			size--;
			return heap[0]
		}


		size--;
		int root = heap[0];
		heap[0] = INT_MIN;
		Heapify(0);

		return root;
	}


	void minHeap::decreasekey(int i, int new_value)
	{
		
		heap[i] = new_value;

		while(i!=0 && heap[parent(i)] > heap[i])
		{
			swap( &heap[parent(i)], &heap[i]);
			i = parent(i);
		}
	}

	void minHeap::delete(int i)
	{
		decreasekey(i, INT_MIN);
		extractMin();
	}



int main()
{
	MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
    return 0; 

}