#include <cinttypes>
#include <cstdlib>

template<class T>
struct fixed_size_ptr{
    uint64_t data;

	fixed_size_ptr<T>(const T* pos = nullptr) :
        data((uint64_t)pos)
    {}

	T& operator[](const size_t k){
		return ((T*)data)[k];
	}
	
	T* operator->(){
		return (T*)data;
	}

    T& operator*(){
		return *(T*)data;
	}
	
	bool operator==(const T* other){
		return (T*)data == other;
	}

    fixed_size_ptr<T>& operator+=(const size_t k){
        data += k * sizeof(T);
		return *this;
	}

    fixed_size_ptr<T>& operator-=(const size_t k){
		data -= k * sizeof(T);
        return *this;
	}

    fixed_size_ptr<T>& operator++(){
		data += sizeof(T);
        return *this;
	}

    fixed_size_ptr<T> operator++(int){
        fixed_size_ptr<T> aux = (T*)data;
        data += sizeof(T);
		return aux;
	}

    fixed_size_ptr<T>& operator--(){
        data -= sizeof(T);
		return *this;
	}
    fixed_size_ptr<T> operator--(int){
        fixed_size_ptr<T> aux = (T*)data;
        data -= sizeof(T);
		return (T*)aux;
	}

    fixed_size_ptr<T> operator+(const size_t k){
        return (T*)(data + k * sizeof(T));
	}

    fixed_size_ptr<T> operator-(const size_t k){
        return (T*)(data - k * sizeof(T));
	}
};
