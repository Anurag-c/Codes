
template<typename T>
class vector
{
    private :
        T *arr;
        int size;
        int capacity;
    
    public :
        vector()
        {
            arr = new T[1];
            capacity = 1;
            size = 0;
        }
        vector(T n)
        {
            arr = new T[n];
            capacity = n;
            size = 0;
        }
        int get_size()
        {
            return size;
        }
        int get_capacity()
        {
            return capacity;
        }
        void push_back(T data)
        {
            if(size == capacity)
            {
                capacity = 2 * capacity;
                T *temp = new T[capacity];
                for(int i = 0 ; i<size ; i++) temp[i] = arr[i];
                delete [] arr;
                arr = temp;
            }
            arr[size] = data;
            size++;
        }
        void pop_back()
        {
            delete arr[size-1];
            size--;
        }
        operator [](T i)
        {
            return arr[i];
        }
};