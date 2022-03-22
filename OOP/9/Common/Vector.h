#pragma once

#include <algorithm>
#include <iostream>

namespace nikminer4sv {

    template<typename T>
    class Vector {
        public:
            Vector() {}

            Vector(size_t size){
                this->size = size;
                this->arr = new T[size];
            }

            Vector(const Vector<T>& vector){
                this->size = vector.size;
                this->arr = new T[size];
                std::memcpy(this->arr, vector.arr, sizeof(T)*this->size);
            }

            Vector<T>& operator = (const Vector<T>& vector){
                if(this->arr){
                    delete[] this->arr;
                }

                this->size = vector.size;
                this->arr = new T[size];
                std::memcpy(this->arr, vector.arr, sizeof(T)*this->size);


                return *this;
            }

            ~Vector(){
                delete[] this->arr;
            }

            void SetSize(size_t size) {
                T* new_arr = new T[size]{};

                if(this->arr){
                    std::memcpy(new_arr, this->arr, sizeof(T)*std::min(size,this->size));            
                    delete[] this->arr;
                }
                
                this->arr = new_arr;
                this->size = size;
            }

            int GetSize() const{
                return this->size;
            }

            void Append(int element){
                SetSize(this->size+1);
                (*this)[this->size-1] = element;
            }

            int& operator[](int index){
                if(index < 0 || index >= size){
                    throw std::invalid_argument("index is out of bounds");
                }

                return this->arr[index];
            }

            int operator[](int index) const {
                if(index < 0 || index >= size){
                    throw std::invalid_argument("index is out of bounds");
                }

                return this->arr[index];
            }


        private:
            size_t size = 0;
            T* arr = nullptr;
    };

    template<typename T>
    std::ostream& operator << (std::ostream &os, const Vector<T>& vector)
    {
        for(size_t i = 0; i<vector.GetSize();i++){
            os<< vector[i] << " ";
        }
    
        return os;
    }
    
}
