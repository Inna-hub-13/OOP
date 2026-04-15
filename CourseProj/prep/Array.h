

template <typename T>
class Array{

    T* arr;
    int size;

    public:
    Array();
    Array(int);
    ~Array() {
        
        delete[] arr;
        arr = nullptr;
    }
    void fill(T);
    T& at(int);
    void print();
};