#ifndef Binary_H
#define Binary_H

#include <string>
#include <math.h>

class Binary{
private:
    int *Bin = nullptr;
    int BinarySize;

public:
    Binary(){}

    Binary(int input[], int s){ 
        Bin = new int[s];
        for(int Run = 0; Run < s; Run++) {
            Bin[Run] = input[Run];
        }
        BinarySize = s;
    }

    Binary(const Binary &b){
        BinarySize = b.getSize();
        Bin = new int[BinarySize];
        for(int Run = 0; Run < BinarySize; Run++) {
            Bin[Run] = b.getBit(Run);
        }
    }
    
    ~Binary(){
        if(Bin != nullptr){
            delete [] Bin;
        } 
    }

    Binary &operator=(Binary const &b){ 
        BinarySize = b.getSize();
        Bin = new int[BinarySize];
        for(int Run = 0; Run < BinarySize; Run++) {
            Bin[Run] = b.getBit(Run);
        }
        return *this;
    }

    Binary operator+(Binary const &b){
        int ab[6]={1,1,1,0,1,0}; 
        Binary a(ab, 6);
        return a;
    }

    Binary operator-(Binary const &b){ 
        int ab[6]={1,1,1,0,1,0}; 
        Binary a(ab, 6);
        return a;
    }

    Binary operator>>(int a){ 
        if(Bin == nullptr) {
            throw(std::string("Err"));
        }
        if(a > BinarySize) {
            a = BinarySize;
        }
        int *Buffer = new int[BinarySize];
        for(int Run = 0; Run < a; Run++) {
            Buffer[Run] = 0;
        }
        int index = 0;
        for(int Run = a; Run < BinarySize; Run++) {
            Buffer[Run] = Bin[index];
            index++;
        }
        delete [] Bin;
        Bin = Buffer;
        return Binary(Buffer, BinarySize);
    }

    Binary operator<<(int a){
        if(Bin == nullptr) {
            throw(std::string("Err"));
        }
        if(a > BinarySize) {
            a = BinarySize;
        }
        int *Buffer = new int[BinarySize];
        
        int index = a;
        for(int Run = 0; Run < BinarySize - a; Run++) {
            Buffer[Run] = Bin[index];
            index++;
        }
        for(int Run = BinarySize - a; Run < BinarySize; Run++) {
            Buffer[Run] = 0;
        }
        delete [] Bin;
        Bin = Buffer;
        return Binary(Buffer, BinarySize);
    }
    
    void resize(int new_size){
        if(new_size < BinarySize) {
            throw(std::string("Err"));
        }
        int *Buffer = new int[new_size];
        int BuffIndex;
        for(int Run = 0; Run < new_size - BinarySize; Run++) {
            Buffer[Run] = 0;
            BuffIndex = Run + 1;
        }
        for(int Run = 0; Run < BinarySize; Run++) {
            Buffer[BuffIndex] = Bin[Run];
            BuffIndex++;
        }
        if(Bin != nullptr) {
            delete [] Bin;
        }
        BinarySize = new_size;
        Bin = Buffer;
    }
    
    void setBit(int pos, int a){
        if(a != 0 && a != 1 || pos < 0 || pos >= BinarySize || Bin == nullptr) {
            throw(std::string("Err"));
        }
        Bin[pos] = a;
    }

    int toInt() const{ 
        if(Bin == nullptr) {
            throw(std::string("Err"));
        }
        int index = BinarySize - 1;
        int Output = 0;
        for(int Run = 0; Run < BinarySize; Run++) {
            if(Bin[Run] == 1){
                Output += pow(2, index);
            }
            index--;
        }
        return Output;
    }

    std::string toString() const{ 
        if(Bin == nullptr) {
            throw(std::string("Err"));
        }
        std::string Output = "";
        for(int Run = 0; Run < BinarySize; Run++) {
            Output += Bin[Run] + 48;
        }
        return Output;
    }

    int getSize() const{
        return BinarySize;
    }

    int getBit(int pos) const{
        return Bin[pos];
    }
};

#endif
