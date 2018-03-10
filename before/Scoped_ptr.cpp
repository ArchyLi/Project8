emplate<typename T>
class ScopedPtr //防拷贝，防赋值，使得scopedptr看起来更像一个指针类型，但实际上scopedptr是一个类模板  
{
public:
    explicit ScopedPtr(T* ptr);
    T& operator*();
    T* operator->();
    ~ScopedPtr();
    T* Get() const;
    void Reset(T *p = 0);
    void Swap(ScopedPtr<T>& sp);
protected:
    ScopedPtr(const ScopedPtr<T>& sp);   //将拷贝和赋值运算符声明为保护，防赋值、防拷贝  
    ScopedPtr<T>& operator=(const ScopedPtr<T>& ap);
private:
    T* _ptr;
};
template<typename T>
T* ScopedPtr<T>::Get() const
{
    return _ptr;
}
template<typename T>
void ScopedPtr<T>::Reset(T *p = 0)
{
    delete _ptr;
    _ptr = p;
    p = NULL;
}
template<typename T>
void ScopedPtr<T>::Swap(ScopedPtr<T>& sp)
{
    swap(_ptr, sp._ptr);
}
template<typename T>
ScopedPtr<T>::ScopedPtr(T* ptr)
    :_ptr(ptr)
{}
template<typename T>
T& ScopedPtr<T>::operator*()
{
    return *_ptr;
}
template<typename T>
T* ScopedPtr<T>::operator->() 
{
    return _ptr;
}
template<typename T>
ScopedPtr<T>::~ScopedPtr()
{
    if (NULL != _ptr)
    {
        delete _ptr;
        _ptr = NULL;
    }
}
