
template <typename Vector>

class VectorIterator{

    public:
    using ValueType = typename Vector::ValueType;
    using PointerType =  ValueType*;
    using ReferenceType = ValueType&;

    PointerType pointer;

    public:
    VectorIterator(PointerType ptr) { pointer = ptr;}

    VectorIterator& operator++() { 

        pointer++;
        return *this;
    }

    VectorIterator operator++(int) {

        VectorIterator temp = *this;
        ++(*this);
        return temp;
    }

    VectorIterator& operator--() {

        pointer--;
        return *this;
    }

      VectorIterator operator--(int) {

        VectorIterator temp = *this;
        --(*this);
        return temp;
    }

    ReferenceType operator[](size_t position){

        return *(pointer + position);
    }

    PointerType operator->() {

        return pointer;
    }

    ReferenceType operator*() {

        return *pointer;
    }

    bool operator==(const VectorIterator& right) const{

        return pointer == right.pointer;
    }


    bool operator!=(const VectorIterator& right) const{

        return !(*this == right);
    }
};

template<typename T>

class Vector{

    T* vector = nullptr;
    unsigned _capacity;
    unsigned _size;
    void expand(size_t);

    public:
    using ValueType = T;
    using Iterator = VectorIterator<Vector<T>>;

    public:
    /*
    The rule of five
    Destructor
    Copy Constructor
    Copy Assignment Operator
    !!!Move Constructor
    !!!Move Assignment Operator*/

    Vector();
    Vector(Vector&);
    ~Vector(){delete[] vector; vector = nullptr;}
    T& operator[](size_t);
    const T& operator[](size_t) const;
    Vector& operator=(const Vector&);
    unsigned size() const;
    void push_back(const T& );
    void pop_back();
    void resize(size_t, T);
    bool empty() const;
    T& back();
    const T& back() const;
    void clear();
    Iterator begin();
    Iterator end();
};

