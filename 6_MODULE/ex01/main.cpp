#include "Data.hpp"

uintptr_t   serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data        *deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
}

int     main(){
    Data        *raw_data = new Data;
    uintptr_t   ptr;   

    raw_data->data = "I'm data, I want to be transfer";
    std::cout << "ptr of receive data " << raw_data << std::endl;
    std::cout << "recieve data: " << raw_data->data << std::endl;

    ptr = serialize(raw_data);
    std::cout << "ptr in uintptr_t: " << ptr << std::endl;

    Data        *receive_data;
    receive_data = deserialize(ptr);
    std::cout << "ptr of receive data " << receive_data << std::endl;
    std::cout << "recieve data: " << receive_data->data << std::endl;

    std::cout << std::endl << "Is data the same: " << std::boolalpha << (raw_data->data.compare(receive_data->data) == 0) << std::endl;

    delete raw_data;
}