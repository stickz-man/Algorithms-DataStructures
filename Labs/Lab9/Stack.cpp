// Goddard Stack.cpp 2015
// note that this is #included from Stack.h
// and not compile separately

  template< class E >
  Stack<E>::Stack() 
    : arr( new E[capacity] ), count(0)
  {
  }

  template< class E >
  Stack<E>::~Stack() 
  {
    delete [] arr;
  }

  template< class E >
  E Stack<E>::pop() 
  {
    count--;
    return arr[count];
  }
  
  template< class E >
  E Stack<E>::peek()
  {
    return arr[count - 1];
  }

  template< class E >
  void Stack<E>::push(E item) 
  {
    arr[count] = item;
    count++;
  }