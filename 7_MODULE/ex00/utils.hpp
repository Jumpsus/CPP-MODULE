#ifndef UTILS_HPP
# define UTILS_HPP

template <typename T>
void  swap(T &A, T &B){
    T   temp;
    temp = A;
    A = B;
    B = temp;
    return ;
}

template <typename T> 
const T     &min(const T &A, const T &B){
    return ((B > A) ? A : B);
}

template <typename T> 
const T     &max(const T &A, const T &B){
    return ((A > B) ? A : B);
}

#endif