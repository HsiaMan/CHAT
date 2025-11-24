#ifndef SINGLETON_H
#define SINGLETON_H
#include "global.h"
template <typename T>
class Singleton{
protected:
    Singleton() = default;
    Singleton(const Singleton<T> &) = delete;
    Singleton & operator = (const Singleton<T> &st) = delete;
    static std::shared_ptr<T> _instance;
public:
    static std::shared_ptr<T>GetInstance(){
        static std::once_flag s_flag;
        std::call_once(s_flag,[&](){
            _instance = std::shared_ptr<T>(new T);
        });
        return _instance;

    }
    void PrintAddress(){
        std::cout << _instance.get() << std::endl;
    }
    ~Singleton(){
        std::cout << "this is singleton destruct" << std::endl;
    }
};
/*
    static定义在这
    如果static不是在一个模版类中，需要放在.cpp文件中
    如果static是在一个模版类中，则需在类外定义或者是使用inline static
 */
template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;
#endif // SINGLETON_H
