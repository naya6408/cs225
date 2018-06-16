
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    /// @todo Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the left child.
    return 2*currentIdx;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the right child.
    return currentIdx*2+1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    /// @todo Update to return the index of the parent.
    return (currentIdx/2);
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    /// @todo Update to return whether the given node has a child
    return leftChild(currentIdx)<=_elems.size()-1;
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
    size_t rightChildIndex = 0;
    size_t leftChildIndex = 0;
    leftChildIndex = leftChild(currentIdx);
    rightChildIndex = rightChild(currentIdx);

    if(rightChild(currentIdx)>_elems.size() || rightChild(currentIdx) == _elems.size())
       return leftChildIndex;
    if(higherPriority(_elems[leftChildIndex],_elems[rightChildIndex]))
      return leftChildIndex;
    else
      return rightChildIndex;
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    /// @todo Implement the heapifyDown algorithm.

    size_t priorityChild = maxPriorityChild(currentIdx);
    if(hasAChild(currentIdx) == false){
      return; // base case, which means that we don't have children to compare to
    }
    else{
    if(higherPriority(_elems[priorityChild], _elems[currentIdx]) == true){ // if priority child is less than the currentIdx value, we swap
      std::swap(_elems[priorityChild], _elems[currentIdx]);
      heapifyDown(priorityChild);
    }
  }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{

    _elems.push_back(0);
    /// @todo Depending on your implementation, this function may or may
    ///   not need modifying
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
  _elems.push_back(0);
	for(size_t i=0;i<elems.size();i++){
		_elems.push_back(elems[i]);
  }
	for(size_t j=parent(elems.size());j>0;j--){
		heapifyDown(j);
  }

}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    /// @todo Remove, and return, the element with highest priority
    T backValue = _elems[1]; // storing the value of the element at the end
    std::swap(_elems[1], _elems[_elems.size()-1]); // switches the value at index 1 and index end
    _elems.pop_back();
    heapifyDown(1);
    return backValue;
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    /// @todo Return, but do not remove, the element with highest priority
    return _elems[1];
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
  _elems.push_back(elem);
  heapifyUp(_elems.size()-1); // why do i need -1 here
    /// @todo Add elem to the heap
}

template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    /// @todo Determine if the heap is empty
    if(_elems.size() == 0){
      return true;
    }
    else{
      return false;
    }

}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}
