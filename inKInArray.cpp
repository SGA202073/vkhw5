class MaxHeap 
{
public:
    int data[10000];
    int size = 0;
    void heappush(int value) 
    {
        data[size] = value;
        int i = size++;
        while (i > 0 && data[i] > data[(i - 1) / 2]) 
        {
            int temp = data[i];
            data[i] = data[(i - 1) / 2];
            data[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }
    int heappop() 
    {
        int maxVal = data[0];
        data[0] = data[--size];
        int i = 0;
        while (true) 
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && data[left] > data[largest])
                largest = left;
            if (right < size && data[right] > data[largest])
                largest = right;

            if (largest == i)
                break;

            int temp = data[i];
            data[i] = data[largest];
            data[largest] = temp;
            i = largest;
        }
        return maxVal;
    }
    int top()
    {
        return data[0];
    }
};
int findKthSmallest(int* arr, int n, int k) 
{
    MaxHeap maxHeap;
    for (int i = 0; i < n; i++) 
    {
        if (maxHeap.size < k)
            maxHeap.heappush(arr[i]);
        else if (arr[i] < maxHeap.top()) 
        {
            maxHeap.heappop();
            maxHeap.heappush(arr[i]);
        }
    }
    return maxHeap.top();
}
/* берем максимальную кучу (maxheap) размера k. идем по массиву. если куча еще не заполнена, то добавляем элементы. 
если новый элемент меньше корня кучи, то выкидываем корень и добавляем новый элемент. в итоге в куче останутся только k самых маленьких элементов,
а на вершине будет k-ый наименьший. время O(NlogK), память O(K) */