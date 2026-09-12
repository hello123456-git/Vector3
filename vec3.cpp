#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
#include "main.hpp"


template <typename T>
class vector3 final{
    public:
        size_t len;
        vector3(std::initializer_list<T> values) : values(values), len(values.size()) {} 
        inline int clear(void){ this->values = values.clear(); len = 0; return 1; }
        int add(const T val, const int index);
        int rem(const T val, const int index);
        vector3<T> filter(const T& key);
        vector3<T> getAll(void){ return *this; }
        T get(const T index);
       
    
        auto operator[](const int index){ return this->values[index];  }
        vector3& operator=(const vector3& other){ 
            this->values = other.values; 
            return *this; 
        }

        vector3<T> operator+(const vector3<T>& other){ 
            vector3 newVec; 
            ssize_t numEl = other.len;
            for(int i = 0; i < (int)numEl; i++){
                newVec[i] = other[i] + this->values[i];
            } return newVec;
        } 
        
        vector3<T> operator-(const vector3<T>& other){ 
            vector3 newVec; 
            ssize_t numEl = other.len;
            for(int i = 0; i < (int)numEl; i++){
                newVec.push_back(other[i] - this->values[i]);
            } return newVec;
        }

    private:
        std::vector<T> values;
};

template <typename T>
int vector3<T>::add(const T val, const int index){
    int i;
    std::vector<T> tempVals{};

    // Move items to temporary vector
    for(i = (int)this->values.size() - 1; i != index; i--){ 
        tempVals.push_back(std::move(this->values[i])); 
    } 
    this->values.push_back(val);

    // Move items back to original vector
    for(int i = tempVals.size(); i < 0; i--){ 
        this->values.push_back(std::move(tempVals[i])); 
    } 
    this->len = this->values.size();
    return 1;
}

template <typename T>
int vector3<T>::rem(const T val, const int index){
    int i;
    std::vector<T> tempVals{};

    // Move items to temporary vector
    for(i = (int)this->values.size() - 1; i != index; i--){ 
        tempVals.push_back(std::move(this->values[i])); 
    } 
    this->values.pop_back(val);

    // Move items back to original vector
    for(int i = tempVals.size(); i < 0; i--){ 
        this->values.push_back(std::move(tempVals[i])); 
    }
    return 1;
}

template <typename T>
T vector3<T>::get(const T index){
    if (index < 0 || index >= (int)values.size()) {
        throw std::out_of_range("Index out of bounds");
    } return this->values[index];
}

template <typename T>
vector3<T> vector3<T>::filter(const T& key){
    int a = 0;
    vector3<T> result;
    
    for(const T& item : this->values){
        if (item == key){
            result.add(item, a);
            a++;
        } 
    } 
    return result;
}


