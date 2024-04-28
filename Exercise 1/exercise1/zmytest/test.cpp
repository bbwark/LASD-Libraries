#include <iostream>
#include <string.h>
#include <string>
#include <typeinfo>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include <cassert>

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

#include "../stack/stack.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"

#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

using namespace std;

/* ************************************************************************** */

void ListTests()
{
  cout << "=== LIST TESTS ===" << endl;

  // Test InsertAtFront
  lasd::List<int> list;
  list.InsertAtFront(5);
  list.InsertAtFront(10);
  assert(list.Front() == 10);
  assert(list.Back() == 5);
  cout << "List Insert Front Success" << endl;

  // Test InsertAtBack
  lasd::List<int> list2;
  list2.InsertAtBack(5);
  list2.InsertAtBack(10);
  assert(list2.Front() == 5);
  assert(list2.Back() == 10);
  cout << "List Insert Back Success" << endl;

  // Test RemoveFromFront
  list.RemoveFromFront();
  assert(list.Front() == 5);
  cout << "List Remove Front Success" << endl;

  // Test AccessElements
  assert(list[0] == 5);
  cout << "List Access Element Success" << endl;

  // Test CopyConstructor
  lasd::List<int> copy(list);
  assert(copy.Front() == 5);
  cout << "List Copy Constructor Success" << endl;

  // Test Traverse
  int sum = 0;
  list.Traverse([&sum](const int &element)
                { sum += element; });
  assert(sum == 5);
  cout << "List Traverse Success" << endl;

  // Test PreOrderTraverse
  sum = 0;
  list.PreOrderTraverse([&sum](const int &element)
                        { sum += element; });
  assert(sum == 5);
  cout << "List PreOrderTraverse Success" << endl;

  // Test PostOrderTraverse
  sum = 0;
  list.PostOrderTraverse([&sum](const int &element)
                         { sum += element; });
  assert(sum == 5);
  cout << "List PostOrderTraverse Success" << endl;

  // Test Map
  list.Map([](int &element)
           { element *= 2; });
  assert(list[0] == 10);
  cout << "List Map Success" << endl;

  // Test PreOrderMap
  list.PreOrderMap([](int &element)
                   { element *= 2; });
  assert(list[0] == 20);
  cout << "List PreOrderMap Success" << endl;

  // Test PostOrderMap
  list.PostOrderMap([](int &element)
                    { element *= 2; });
  assert(list[0] == 40);
  cout << "List PostOrderMap Success" << endl;
}

void VectorTests()
{
  cout << "\n\n=== VECTOR TESTS ===" << endl;

  // Test Constructor with initial dimension
  lasd::Vector<int> vec(5);
  assert(vec.Size() == 5);
  cout << "Vector Constructor Dimension Success" << endl;

  // Test Copy Constructor
  lasd::Vector<int> vecCopy(vec);
  assert(vecCopy.Size() == 5);
  cout << "Vector Copy Constructor Success" << endl;

  // Test Move Constructor
  lasd::Vector<int> vecMove(move(vecCopy));
  assert(vecMove.Size() == 5);
  cout << "Vector Move Constructor Success" << endl;

  // Test Copy Assignment
  lasd::Vector<int> vecAssign;
  vecAssign = vecMove;
  assert(vecAssign.Size() == 5);
  cout << "Vector Copy Assignement Success" << endl;

  // Test Move Assignment
  lasd::Vector<int> vecMoveAssign;
  vecMoveAssign = move(vecAssign);
  assert(vecMoveAssign.Size() == 5);
  cout << "Vector Move Assignement Success" << endl;

  // Test Resize
  vecMoveAssign.Resize(10);
  assert(vecMoveAssign.Size() == 10);
  cout << "Vector Resize Success" << endl;

  // Test Access Operators
  vecMoveAssign[0] = 5;
  assert(vecMoveAssign[0] == 5);
  cout << "Vector Access Success" << endl;

  // Test Front and Back
  assert(vecMoveAssign.Front() == 5);
  assert(vecMoveAssign.Back() == 0); // Assuming default initialization
  cout << "Vector Front and Back Success" << endl;

  // Test Clear
  vecMoveAssign.Clear();
  assert(vecMoveAssign.Empty());
  cout << "Vector Clear Success" << endl;
}

void SortableVectorTests()
{

  cout << "\n\n=== SORTABLE VECTOR TESTS ===" << endl;

  // Test Constructor with initial dimension
  lasd::SortableVector<int> sortableVec(5);
  assert(sortableVec.Size() == 5);
  cout << "SortableVector Constructor Dimension Success" << endl;

  // Test Copy Constructor
  lasd::SortableVector<int> sortableVecCopy(sortableVec);
  assert(sortableVecCopy.Size() == 5);
  cout << "SortableVector Copy Constructor Success" << endl;

  // Test Move Constructor
  lasd::SortableVector<int> sortableVecMove(move(sortableVecCopy));
  assert(sortableVecMove.Size() == 5);
  cout << "SortableVector Move Constructor Success" << endl;

  // Test Copy Assignment
  lasd::SortableVector<int> sortableVecAssign;
  sortableVecAssign = sortableVecMove;
  assert(sortableVecAssign.Size() == 5);
  cout << "SortableVector Copy Assignement Success" << endl;

  // Test Move Assignment
  lasd::SortableVector<int> sortableVecMoveAssign;
  sortableVecMoveAssign = move(sortableVecAssign);
  assert(sortableVecMoveAssign.Size() == 5);
  cout << "SortableVector Move Assignement Success" << endl;
}

void StackVecTests()
{
  cout << "\n\n=== STACK VECTOR TESTS ===" << endl;

  // Test Default Constructor
  lasd::StackVec<int> stackVec;
  assert(stackVec.Empty());
  cout << "Default Constructor Success" << endl;

  stackVec.Push(5);
  stackVec.Push(10);
  assert(stackVec.Top() == 10);

  // Test Copy Constructor
  lasd::StackVec<int> stackCopy(stackVec);
  assert(stackCopy.Top() == 10);
  cout << "Copy Constructor Success" << endl;

  // Test Move Constructor
  lasd::StackVec<int> stackMove(move(stackCopy));
  assert(stackMove.Top() == 10);
  cout << "Move Constructor Success" << endl;

  // Test Copy Assignment
  lasd::StackVec<int> stackAssign;
  stackAssign = stackMove;
  assert(stackAssign.Top() == 10);
  cout << "Copy Assignment Success" << endl;

  // Test Move Assignment
  lasd::StackVec<int> stackMoveAssign;
  stackMoveAssign = move(stackAssign);
  assert(stackMoveAssign.Top() == 10);
  cout << "Move Assignment Success" << endl;

  // Test Push and Top
  stackMoveAssign.Push(15);
  assert(stackMoveAssign.Top() == 15);
  cout << "Push and Top Success" << endl;

  // Test Pop and TopNPop
  stackMoveAssign.Pop();
  assert(stackMoveAssign.Top() == 10);
  cout << "Pop and TopNPop Success" << endl;

  // Test Clear
  stackMoveAssign.Clear();
  assert(stackMoveAssign.Empty());
  cout << "Clear Success" << endl;
}

void StackLstTests()
{
  cout << "\n\n=== STACK LIST TESTS ===" << endl;

  // Test Specific Constructor
  lasd::List<int> list;
  list.InsertAtBack(5);
  list.InsertAtBack(10);
  lasd::StackLst<int> stackFromList(list);
  assert(stackFromList.Top() == 5);
  cout << "Specific Constructor Success" << endl;

  // Test Copy Constructor
  lasd::StackLst<int> stackCopy(stackFromList);
  assert(stackCopy.Top() == 5);
  cout << "Copy Constructor Success" << endl;

  // Test Move Constructor
  lasd::StackLst<int> stackMove(move(stackCopy));
  assert(stackMove.Top() == 5);
  cout << "Move Constructor Success" << endl;

  // Test Copy Assignment
  lasd::StackLst<int> stackAssign;
  stackAssign = stackMove;
  assert(stackAssign.Top() == 5);
  cout << "Copy Assignment Success" << endl;

  // Test Move Assignment
  lasd::StackLst<int> stackMoveAssign;
  stackMoveAssign = move(stackAssign);
  assert(stackMoveAssign.Top() == 5);
  cout << "Move Assignment Success" << endl;

  // Test Push and Top
  stackMoveAssign.Push(15);
  assert(stackMoveAssign.Top() == 15);
  cout << "Push and Top Success" << endl;

  // Test Pop and TopNPop
  assert(stackMoveAssign.TopNPop() == 15);
  assert(stackMoveAssign.Top() == 5);
  cout << "Pop and TopNPop Success" << endl;

  // Test Clear
  stackMoveAssign.Clear();
  assert(stackMoveAssign.Empty());
  cout << "Clear Success" << endl;
}

void QueueVecTests()
{
  cout << "\n\n=== QUEUE VECTOR TESTS ===" << endl;

  // Test Default Constructor
  lasd::QueueVec<int> queueVec;
  assert(queueVec.Empty());
  cout << "Default Constructor Success" << endl;

  queueVec.Enqueue(5);
  queueVec.Enqueue(10);
  assert(queueVec.Head() == 5);

  // Test Copy Constructor
  lasd::QueueVec<int> queueCopy(queueVec);
  assert(queueCopy.Head() == 5);
  cout << "Copy Constructor Success" << endl;

  // Test Move Constructor
  lasd::QueueVec<int> queueMove(move(queueCopy));
  assert(queueMove.Head() == 5);
  cout << "Move Constructor Success" << endl;
}

void QueueLstTests()
{
  cout << "\n\n=== QUEUE LIST TESTS ===" << endl;

  // Test Default Constructor
  lasd::QueueLst<int> queueLst;
  assert(queueLst.Empty());
  cout << "Default Constructor Success" << endl;

  // Test Specific Constructor
  lasd::List<int> list;
  list.InsertAtBack(5);
  list.InsertAtBack(10);
  lasd::QueueLst<int> queueFromList(list);
  assert(queueFromList.Head() == 5);
  cout << "Specific Constructor Success" << endl;

  // Test Copy Constructor
  lasd::QueueLst<int> queueCopy(queueFromList);
  assert(queueCopy.Head() == 5);
  cout << "Copy Constructor Success" << endl;

  // Test Move Constructor
  lasd::QueueLst<int> queueMove(move(queueCopy));
  assert(queueMove.Head() == 5);
  cout << "Move Constructor Success" << endl;

  // Test Copy Assignment
  lasd::QueueLst<int> queueAssign;
  queueAssign = queueMove;
  assert(queueAssign.Head() == 5);
  cout << "Copy Assignment Success" << endl;

  // Test Move Assignment
  lasd::QueueLst<int> queueMoveAssign;
  queueMoveAssign = move(queueAssign);
  assert(queueMoveAssign.Head() == 5);
  cout << "Move Assignment Success" << endl;

  // Test Enqueue and Head
  queueMoveAssign.Enqueue(15);
  assert(queueMoveAssign.Head() == 5);
  cout << "Enqueue and Head Success" << endl;

  // Test Dequeue and HeadNDequeue
  queueMoveAssign.Dequeue();
  assert(queueMoveAssign.Head() == 10);
  cout << "Dequeue and HeadNDequeue Success" << endl;

  // Test Clear
  queueMoveAssign.Clear();
  assert(queueMoveAssign.Empty());
  cout << "Clear Success" << endl;
}

void mytest()
{
  ListTests();
  VectorTests();
  SortableVectorTests();
  StackLstTests();
  StackVecTests();
  QueueLstTests();
  QueueVecTests();
}