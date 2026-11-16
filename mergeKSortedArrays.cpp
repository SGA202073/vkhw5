struct HeapNode 
{
    int value;
    int arrayIdx;
    int elemIdx;
};
class MinHeap 
{
    public:
        HeapNode data[1000];
        int size = 0;
        void push(HeapNode node) 
        {
            data[size] = node;
            int i = size++;
            while (i > 0 && data[i].value < data[(i - 1) / 2].value) 
            {
                HeapNode temp = data[i];
                data[i] = data[(i - 1) / 2];
                data[(i - 1) / 2] = temp;
                i = (i - 1) / 2;
            }
        }
        HeapNode pop() 
        {
            HeapNode minNode = data[0];
            data[0] = data[--size];
            int i = 0; 
            while (true) 
            {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int smallest = i;
                if (left < size && data[left].value < data[smallest].value)
                    smallest = left; 
                if (right < size && data[right].value < data[smallest].value)
                    smallest = right;
                if (smallest == i)
                    break; 
                HeapNode temp = data[i];
                data[i] = data[smallest];
                data[smallest] = temp;
                i = smallest;
            }
            return minNode;
        }
        bool isEmpty() 
        {
            return size == 0;
        }
};
void MergeKSortedArrays(int** sortedArrays, int* sizes, int K, int* mergedArray, int* mergedSize) 
{
    MinHeap minHeap;
    for (int i = 0; i < K; i++) 
    {
        if (sizes[i] > 0)
        {
            HeapNode node;
            node.value = sortedArrays[i][0];
            node.arrayIdx = i;
            node.elemIdx = 0;
            minHeap.push(node);
        }
    }
    *mergedSize = 0;
    while (!minHeap.isEmpty()) 
    {
        HeapNode node = minHeap.pop();
        mergedArray[(*mergedSize)++] = node.value;
        if (node.elemIdx + 1 < sizes[node.arrayIdx]) 
        {
            HeapNode nextNode;
            nextNode.value = sortedArrays[node.arrayIdx][node.elemIdx + 1];
            nextNode.arrayIdx = node.arrayIdx;
            nextNode.elemIdx = node.elemIdx + 1;
            minHeap.push(nextNode);
        }
    }
}
/* используем минимальную кучу. сначала кидаем в нее первые элементы каждого из k массивов, потом в цикле достаем из кучи минимум,
пишем его в итоговый массив, и если в том же массиве, откуда он пришел, есть следующий элемент, кидаем его в кучу. сложность O(NlogK), где N -- это все элементы,
а K это число массивов, потому что в куче всегда не больше K элементов. память O(K) под кучу и O(N) под ответ */