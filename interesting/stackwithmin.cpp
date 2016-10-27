/*
定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。要求函数min、push以及pop的时间复杂度都是O(1)
*/

#include <deque>
#include <assert.h>
#include <iostream>

using namespace std;

template <typename T> 
class CStackWithMin {
    public:
        CStackWithMin(void){}
	virtual ~CStackWithMin(void){}

	T& top(void);
	void push(const T& value);
	void pop(void);
	const T& min(void) const;
        
    private:
        deque<T> m_data;
	deque<size_t> m_minIndex;

};

template <typename T> 
T&  CStackWithMin<T>::top()
{  
    return m_data.back();
}

template <typename T> 
void CStackWithMin<T>::push( const T& value )
{
    // append the data into the end of m_data
    m_data.push_back( value );
    if( m_minIndex.size() == 0 )
        m_minIndex.push_back(0);
    else {
        if( value < m_data[m_minIndex.back()] )
	    m_minIndex.push_back(m_data.size() - 1 );
	else
	    m_minIndex.push_back(m_minIndex.back());
    }
}

template <typename T> 
void CStackWithMin<T>::pop()
{
    // erease the element at the end of stack
    m_data.pop_back();
    m_minIndex.pop_back();
}

template <typename T> 
const T& CStackWithMin<T>::min() const
{
    assert(m_data.size() > 0);
    assert(m_minIndex.size() > 0);


    return m_data[m_minIndex.back()];
}

int main(){
    CStackWithMin<int> minStack;
    minStack.push(3);
    cout<<"min value is "<<minStack.min()<<endl;
    minStack.push(4);
    cout<<"min value is "<<minStack.min()<<endl;
    minStack.push(2);
    cout<<"min value is "<<minStack.min()<<endl;
    minStack.push(1);
    cout<<"min value is "<<minStack.min()<<endl;
    minStack.pop();
    cout<<"min value is "<<minStack.min()<<endl;
    minStack.pop();
    cout<<"min value is "<<minStack.min()<<endl;
    minStack.push(0);
    cout<<"min value is "<<minStack.min()<<endl;
    return 0;
}
