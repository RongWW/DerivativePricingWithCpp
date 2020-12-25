//
//  Wrapper.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-24.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef Wrapper_hpp
#define Wrapper_hpp

template<class T>
class Wrapper
{
public:
    Wrapper()
    {DataPtr = 0;}
    
    Wrapper(const T& inner)
    {
        DataPtr  = inner.clone();
    }
    
    Wrapper(const Wrapper<T>& original)
    {
        if (original.DataPtr != 0)
            DataPtr = original.DataPtr->clone();
        else
            DataPtr = 0;
    }
    
    ~Wrapper()
    {
        if (DataPtr != 0)
            delete DataPtr;
    }
    
    Wrapper& operator=(const Wrapper<T>& original)
    {
        if (this != original)
        {
            if (DataPtr!=0)
                delete DataPtr;
            
            DataPtr = (original.DataPtr!=0) ? original.DataPtr->clone() : 0;
        }
        return *this;
    }
    
    T& operator*()
    {
        return *DataPtr;
    }
    
    const T& operator*() const
    {
        return *DataPtr;
    }
    
    const T* const operator->() const
    {
        return DataPtr;
    }
    
    T* operator->()
    {
        return DataPtr;
    }
    
private:
    T* DataPtr;
};

#endif /* Wrapper_hpp */
