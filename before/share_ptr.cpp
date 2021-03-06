template<typename T>
//采用引用计数，实现一个可以有多个指针指向同一块内存的类模板
////SharedPtr是类模板，不是智能指针类型 
class SharedPtr  
{

public:
    SharedPtr(T* ptr);
    SharedPtr(const SharedPtr<T>& sp);
    SharedPtr<T>& operator=(SharedPtr<T> sp);
    T& operator*();
    T* operator->();
    ~SharedPtr();
    int Count()
    {

        return *_pCount;
    }
private:
    void Release()
    {

        if (--(*_pCount) == 0)
        {

            delete _ptr;
            delete _pCount;
            _ptr = NULL;
            _pCount = NULL;
        }
    }
private:
    T* _ptr;
    int* _pCount; //指向引用计数的空间  
};
template<typename T>
SharedPtr<T>::SharedPtr(T* ptr)
    :_ptr(ptr)
    , _pCount(new int(1)) {
}
template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& sp)
{

    _ptr = sp._ptr;
    _pCount = sp._pCount;
    ++(*_pCount);
}
template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T> sp)
{

    std::swap(sp._ptr, _ptr);
    std::swap(sp._pCount, _pCount);
    return *this;
}
template<typename T>
T& SharedPtr<T>::operator*()
{

    return *_ptr;
}
template<typename T>
T* SharedPtr<T>::operator->()
{

    return _ptr;
}
template<typename T>
SharedPtr<T>::~SharedPtr()
{

    Release();
}
}
}
}
}
}
}
}
}
}
}
