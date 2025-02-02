// #include "..."

/* ************************************************************************** */

#include <random>
using namespace std;

default_random_engine gen(random_device{}());
uniform_int_distribution<int> randNumb(0, 100);

#include "test.hpp"
/* ************************************************************************** */

void mytest()
{
  TestEsercizio1();
  TestEsercizio2();
  TestEsercizio3();
}

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

void TestEsercizio1()
{
  ListTests();
  VectorTests();
  SortableVectorTests();
  StackLstTests();
  StackVecTests();
  QueueLstTests();
  QueueVecTests();
}

string evaluateResult(bool &hook, bool result, string correctPrint, string incorrectPrint)
{
  hook &= result;
  if (result)
    return correctPrint;
  return incorrectPrint;
}

bool IteratorTest()
{
  bool test = true;
  int testNumber = 0;
  cout << "\n\nBegin of Iterator Test for BST: " << endl;

  lasd::BinaryTreeLnk<int> btlnk;
  lasd::BTInOrderIterator<int> inOrderBSTlnk(btlnk);
  cout << "Test: " << ++testNumber << ")" << " BTInOrderIterator should be terminated: " << evaluateResult(test, inOrderBSTlnk.Terminated(), "Terminated (Correct)", "Not Terminated (Incorrect)") << endl;

  lasd::BTInOrderIterator<int> inOrderBSTmovelnk(std::move(btlnk));
  cout << "Test: " << ++testNumber << ")" << " BTInOrderIterator should be terminated: " << evaluateResult(test, inOrderBSTmovelnk.Terminated(), "Terminated (Correct)", "Not Terminated (Incorrect)") << endl;

  lasd::BinaryTreeVec<int> btvec;
  lasd::BTInOrderIterator<int> inOrderBSTvec(btvec);
  cout << "Test: " << ++testNumber << ")" << " BTInOrderIterator should be terminated: " << evaluateResult(test, inOrderBSTvec.Terminated(), "Terminated (Correct)", "Not Terminated (Incorrect)") << endl;

  lasd::BTInOrderIterator<int> inOrderBSTmovevec(std::move(btvec));
  cout << "Test: " << ++testNumber << ")" << " BTInOrderIterator should be terminated: " << evaluateResult(test, inOrderBSTmovevec.Terminated(), "Terminated (Correct)", "Not Terminated (Incorrect)") << endl;

  lasd::List<int> lst;
  for (int i = 10; i < 16; i++)
  {
    lst.InsertAtBack(i);
  }

  lasd::BinaryTreeLnk<int> btLnk(lst);
  string expectedString = "101113141215";
  string resultString = "";
  btLnk.Traverse(
      [&resultString](const int &dat)
      {
        resultString += to_string(dat);
      });
  cout << "Test: " << ++testNumber << ")" << " Traverse: Executed " << evaluateResult(test, expectedString == resultString, "Correctly", "Wrongly") << endl;

  resultString = "";
  btLnk.PreOrderTraverse(
      [&resultString](const int &dat)
      {
        resultString += to_string(dat);
      });
  cout << "Test: " << ++testNumber << ")" << " PreOrderTraverse: Executed " << evaluateResult(test, expectedString == resultString, "Correctly", "Wrongly") << endl;

  lasd::BTPreOrderIterator<int> itrPre(btLnk);
  cout << "\nPreOrderIterator Execution: ";
  while (!(itrPre.Terminated()))
  {
    cout << *itrPre << "-";
    ++itrPre;
  }
  cout << endl;

  expectedString = "131411151210";
  resultString = "";
  btLnk.PostOrderTraverse(
      [&resultString](const int &dat)
      {
        resultString += to_string(dat);
      });
  cout << "Test: " << ++testNumber << ")" << " PostOrderTraverse: Executed " << evaluateResult(test, expectedString == resultString, "Correctly", "Wrongly") << endl;

  lasd::BTPostOrderIterator<int> itrPost(btLnk);
  cout << "\nPostOrderIterator Execution: ";
  while (!(itrPost.Terminated()))
  {
    cout << *itrPost << "-";
    ++itrPost;
  }
  cout << endl;

  expectedString = "131114101512";
  resultString = "";
  btLnk.InOrderTraverse(
      [&resultString](const int &dat)
      {
        resultString += to_string(dat);
      });
  cout << "Test: " << ++testNumber << ")" << " InOrderTraverse: Executed " << evaluateResult(test, expectedString == resultString, "Correctly", "Wrongly") << endl;

  lasd::BTInOrderIterator<int> itrIn(btLnk);
  cout << "\nInOrderIterator Execution: ";
  while (!(itrIn.Terminated()))
  {
    cout << *itrIn << "-";
    ++itrIn;
  }
  cout << endl;

  expectedString = "101112131415";
  resultString = "";
  btLnk.BreadthTraverse(
      [&resultString](const int &dat)
      {
        resultString += to_string(dat);
      });
  cout << "Test: " << ++testNumber << ")" << " BreadthTraverse: Executed " << evaluateResult(test, expectedString == resultString, "Correctly", "Wrongly") << endl;

  lasd::BTBreadthIterator<int> itrBreadth(btLnk);
  cout << "\nBreadthOrderIterator Execution: ";
  while (!(itrBreadth.Terminated()))
  {
    cout << *itrBreadth << "-";
    ++itrBreadth;
  }
  cout << endl;

  lasd::SortableVector<int> vec(randNumb(gen) + 1);
  for (unsigned long i = 0; i < vec.Size(); i++)
  {
    vec[i] = randNumb(gen);
  }
  vec.Sort();
  lasd::BinaryTreeVec<int> btvec1(vec);
  lasd::BTBreadthIterator<int> breadthIterVec(btvec1);
  int next = 0;
  while (!breadthIterVec.Terminated())
  {
    int previous = *breadthIterVec;
    if (!(++breadthIterVec).Terminated())
    {
      next = *breadthIterVec;
    }
    if (previous <= next)
    {
      test &= true;
    }
    else
    {
      test &= false;
      cout << "Test: " << ++testNumber << ")" << " BTBredthIterator wrongly built on top of BTVec" << endl;
      break;
    }
  }
  if (test == true)
  {
    cout << "Test: " << ++testNumber << ")" << " BTBredthIterator correctly built on top of BTVec" << endl;
  }

  breadthIterVec.Reset();
  cout << "Test: " << ++testNumber << ")" << " Iterator Reset: Resetted " << evaluateResult(test, *breadthIterVec == vec[0], "Correctly", "Wrongly") << endl;

  lasd::BinaryTreeLnk<int> btlnk1;
  lasd::BTInOrderIterator<int> postOrderBSTlnk(btlnk1);
  cout << "Test: " << ++testNumber << ")" << " BTInOrderIterator should be terminated: " << evaluateResult(test, postOrderBSTlnk.Terminated(), "Terminated (Correct)", "Not Terminated (Incorrect)") << endl;

  lasd::BTInOrderIterator<int> postOrderBSTmovelnk(std::move(btlnk));
  cout << "Test: " << ++testNumber << ")" << " BTInOrderIterator should be terminated: " << evaluateResult(test, postOrderBSTlnk.Terminated(), "Terminated (Correct)", "Not Terminated (Incorrect)") << endl;

  return test;
}

bool BTVectorTest()
{
  bool testBTVec = true;
  int testNumber = 0;
  cout << "\n\nBegin of BTVec Test: " << endl;
  lasd::List<int> lst;
  for (int i = 0; i < randNumb(gen) + 1; i++)
  {
    lst.Insert(randNumb(gen));
  }
  lasd::BinaryTreeVec<int> btvec1(lst);
  lasd::BinaryTreeVec<int> btvec2(std::move(lst));
  cout << "Test: " << ++testNumber << ")" << " BTVecs are " << evaluateResult(testBTVec, btvec1 == btvec2, "Equals (Correct)", "Not Equals (Incorrect)") << endl;

  btvec2.Clear();
  btvec1 = btvec2;
  cout << "Test: " << ++testNumber << ")" << " BTVec is " << evaluateResult(testBTVec, btvec1.Empty(), "Empty (Correct)", "Not Empty (Incorrect)") << endl;
  cout << "Test: " << ++testNumber << ")" << " BTVecs are " << evaluateResult(testBTVec, btvec1 == btvec2, "Equals (Correct)", "Not Equals (Incorrect)") << endl;

  lasd::List<double> vec;
  lasd::BinaryTreeVec<double> btvec3;
  btvec3 = std::move(vec);
  try
  {
    btvec3.Root();
  }
  catch (std::length_error const &)
  {
    cout << "Test: " << ++testNumber << ")" << " leng_error called BTVec is Empty, doesn't have root: Correct!" << endl;
  }
  catch (std::exception const &)
  {
    cout << "Test: " << ++testNumber << ")" << " Wrong exception called: Error!" << endl;
    testBTVec &= false;
  }
  lasd::Vector<double> vec1(randNumb(gen) + 1);
  for (unsigned long i = 0; i < vec1.Size() - 1; i++)
  {
    vec1[i] = randNumb(gen);
  }

  vec1[0]++;
  vec1[vec1.Size() - 1] = vec1[0];
  lasd::BinaryTreeLnk<double> btlnk1(vec1);
  lasd::BinaryTreeVec<double> btvec4(btlnk1);
  double accumulator1 = 0;
  btlnk1.Traverse(
      [&accumulator1](const double &dat)
      {
        accumulator1 += dat;
      });

  double accumulator2 = 0;
  btvec4.Traverse(
      [&accumulator2](const double &dat)
      {
        accumulator2 += dat;
      });
  cout << "Test: " << ++testNumber << ")" << " BTVec and BTLnk are " << evaluateResult(testBTVec, accumulator1 == accumulator2, "Equals (Correct)", "Not Equals (Incorrect)") << endl;

  lasd::BST<double> BST1(btvec4);
  double accumulator3 = 0;
  BST1.Traverse(
      [&accumulator3](double dat)
      {
        accumulator3 += dat;
      });
  cout << "Test: " << ++testNumber << ")" << " BTVec and (BTLnk and BTVec) are " << evaluateResult(testBTVec, accumulator2 != accumulator3, "Not Equals (Correct)", "Equals (Incorrect)") << endl;

  lasd::Vector<int> vec3(randNumb(gen) + 1);
  for (unsigned long i = 0; i < vec3.Size(); i++)
  {
    vec3[i] = randNumb(gen);
  }
  lasd::Vector<int> vec4(vec3);
  lasd::BinaryTreeLnk<int> btlnk5(std::move(vec3));
  lasd::BinaryTreeVec<int> btvec5(std::move(vec4));
  bool placeholder = true;
  cout << "Test: " << ++testNumber << ")" << " BTVec and BTLnk are " << evaluateResult(placeholder, btlnk5.lasd::BinaryTree<int>::operator==(btvec5), "Equals (Correct)", "Not Equals (Incorrect)") << endl;

  lasd::BinaryTreeLnk<int> btlnk6(std::move(btlnk5));
  lasd::BinaryTreeVec<int> btvec6(std::move(btvec5));
  cout << "Test: " << ++testNumber << ")" << " BTVec and BTLnk are " << evaluateResult(placeholder, btlnk6.lasd::BinaryTree<int>::operator==(btvec6), "Equals (Correct)", "Not Equals (Incorrect)") << endl;

  lasd::List<int> lista;
  lista.Insert(randNumb(gen));
  lista.Insert(randNumb(gen));

  lasd::BinaryTreeVec<int> btvec7(std::move(lista));
  lasd::List<int> list(btvec7);
  for (unsigned long i = 0; i < list.Size(); i++)
  {
    cout << "Test: " << ++testNumber << ")" << " Value From List in BTLnk " << list[i] << endl;
  }

  lasd::List<int> list1;
  for (int i = 0; i < (randNumb(gen) % 10) + 5; i++)
  {
    list1.Insert(randNumb(gen));
  }
  cout << "Test: " << ++testNumber << ")" << " Map LIST:";
  list1.Map(
      [](int dat)
      {
        cout << "-" << dat;
      });
  lasd::BinaryTreeVec<int> bintvec(list1);
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " Map:";
  bintvec.Map(
      [](int dat)
      {
        cout << "-" << dat;
      });
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " PreOrder Map:";
  bintvec.PreOrderMap(
      [](int dat)
      {
        cout << "-" << dat;
      });
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " PostOrder Map:";
  bintvec.PostOrderMap(
      [](int dat)
      {
        cout << "-" << dat;
      });
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " InOrder Map:";
  bintvec.InOrderMap(
      [](int dat)
      {
        cout << "-" << dat;
      });
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " Breadth Map:";
  bintvec.BreadthMap(
      [](int dat)
      {
        cout << "-" << dat;
      });

  return testBTVec;
}

bool BTListTest()
{
  bool testBTLnk = true;
  int testNumber = 0;
  cout << "\n\nBegin of BTLnk Test: " << endl;
  lasd::List<int> lst;
  for (int i = 0; i < randNumb(gen) + 1; i++)
  {
    lst.Insert(randNumb(gen));
  }
  lasd::BinaryTreeLnk<int> btlnk1(lst);
  lasd::BinaryTreeLnk<int> btlnk2(std::move(lst));
  cout << "Test: " << ++testNumber << ")" << " BTLnks are " << evaluateResult(testBTLnk, btlnk1 == btlnk2, "Equals (Correct)", "Not Equals (Incorrect)") << endl;

  btlnk2.Clear();
  btlnk1 = btlnk2;
  cout << "Test: " << ++testNumber << ")" << " BTLnks is " << evaluateResult(testBTLnk, btlnk1.Empty(), "Empty (Correct)", "Not Empty (Incorrect)") << endl;
  cout << "Test: " << ++testNumber << ")" << " BTLnks are " << evaluateResult(testBTLnk, btlnk1 == btlnk2, "Equals (Correct)", "Not Equals (Incorrect)") << endl;

  lasd::List<double> vec;
  lasd::BinaryTreeLnk<double> btlnk3;
  btlnk3 = vec;
  try
  {
    btlnk3.Root();
  }
  catch (std::length_error const &)
  {
    cout << "Test: " << ++testNumber << ")" << " leng_error called BTLnk is Empty, doesn't have root: Correct!" << endl;
  }
  catch (std::exception const &)
  {
    cout << "Test: " << ++testNumber << ")" << " Wrong exception called: Error!" << endl;
    testBTLnk &= false;
  }

  lasd::Vector<double> vec1(randNumb(gen) + 1);
  for (unsigned long i = 0; i < vec1.Size() - 1; i++)
  {
    vec1[i] = randNumb(gen);
  }

  vec1[0]++;
  vec1[vec1.Size() - 1] = vec1[0];
  lasd::BinaryTreeLnk<double> btlnk4(std::move(vec1));
  lasd::BinaryTreeVec<double> btvec1(btlnk4);
  double accumulator1 = 0;
  btlnk4.Map(
      [&accumulator1](double dat)
      {
        accumulator1 += dat;
      });

  double accumulator2 = 0;
  btvec1.Map(
      [&accumulator2](double dat)
      {
        accumulator2 += dat;
      });

  cout << "Test: " << ++testNumber << ")" << " BTVec and BTLnk are " << evaluateResult(testBTLnk, accumulator1 == accumulator2, "Equals (Correct)", "Not Equals (Incorrect)") << endl;

  lasd::BST<double> BST1(std::move(btlnk4));
  double accumulator3 = 0;
  BST1.Traverse(
      [&accumulator3](const double &dat)
      {
        accumulator3 += dat;
      });
  cout << "Test: " << ++testNumber << ")" << " BST and (BTLnk and BTVec) are " << evaluateResult(testBTLnk, accumulator2 != accumulator3, "Not Equals (Correct)", "Equals (Incorrect)") << endl;

  lasd::Vector<int> vec3(randNumb(gen) + 1);
  for (unsigned long i = 0; i < vec3.Size(); i++)
  {
    vec3[i] = randNumb(gen);
  }
  lasd::BinaryTreeLnk<int> btlnk5(vec3);
  lasd::BinaryTreeVec<int> btvec2(vec3);
  lasd::BinaryTreeLnk<int> btlnk6(btlnk5);
  lasd::BinaryTreeVec<int> btvec3(btvec2);
  bool placeholder = true;
  cout << "Test: " << ++testNumber << ")" << " BST and (BTLnk and BTVec) are " << evaluateResult(placeholder, btlnk5.lasd::BinaryTree<int>::operator==(btvec2), "Equals (Correct)", "Not Equals (Incorrect)") << endl;
  cout << "Test: " << ++testNumber << ")" << " BST and (BTLnk and BTVec) are " << evaluateResult(placeholder, btlnk6.lasd::BinaryTree<int>::operator==(btvec3), "Equals (Correct)", "Not Equals (Incorrect)") << endl;

  lasd::Vector<int> vector(2);
  vector[0] = randNumb(gen);
  vector[1] = randNumb(gen);
  lasd::BinaryTreeLnk<int> btlnk7(std::move(vector));
  lasd::List<int> lista(btlnk7);
  for (unsigned long i = 0; i < lista.Size(); i++)
  {
    cout << "Test: " << ++testNumber << ")" << " Value From List in BTLnk: " << lista[i] << endl;
  }
  lasd::Vector<int> vettore(std::move(btlnk7));
  for (unsigned long i = 0; i < vettore.Size(); i++)
  {
    cout << "Test: " << ++testNumber << ")" << " Value From Vector in BTLnk: " << vettore[i] << endl;
  }

  lasd::Vector<int> vettore1((randNumb(gen) % 10) + 5);
  for (unsigned long i = 0; i < vettore1.Size(); i++)
  {
    vettore1[i] = randNumb(gen);
  }
  cout << "Test: " << ++testNumber << ")" << " Map VEC:";
  vettore1.Traverse(
      [](int dat)
      {
        cout << "-" << dat;
      });
  lasd::BinaryTreeLnk<int> bintrelnk(std::move(vettore1));
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " Trav:";
  bintrelnk.Traverse(
      [](int dat)
      {
        cout << "-" << dat;
      });
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " PreOrder Trav:";
  bintrelnk.PreOrderTraverse(
      [](int dat)
      {
        cout << "-" << dat;
      });
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " PostOrder Trav:";
  bintrelnk.PostOrderTraverse(
      [](int dat)
      {
        cout << "-" << dat;
      });
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " InOrder Trav:";
  bintrelnk.InOrderTraverse(
      [](int dat)
      {
        cout << "-" << dat;
      });
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " Breadth Trav:";
  bintrelnk.BreadthTraverse(
      [](int dat)
      {
        cout << "-" << dat;
      });

  return testBTLnk;
}

bool BSTTest()
{
  bool testBST = true;
  int testNumber = 0;
  cout << "\n\nBegin of BST Test: " << endl;

  lasd::Vector<int> vec1;
  lasd::BST<int> bst1(vec1);
  bst1.Insert(1);
  cout << "Test: " << ++testNumber << ")" << " Max is " << evaluateResult(testBST, bst1.Max() == 1, "Correct", "Incorrect") << endl;

  lasd::Vector<int> vec2(randNumb(gen) + 1);
  for (unsigned long i = 0; i < vec2.Size(); i++)
  {
    vec2[i] = randNumb(gen);
  }
  bst1.Clear();
  bst1.InsertAll(vec2);
  int ExstactedValue = bst1.MaxNRemove();
  while (!bst1.Empty())
  {
    if (bst1.Max() > ExstactedValue)
    {
      break;
      cout << "Test: " << ++testNumber << ")" << " Previous ExtractedMax '" << ExstactedValue << "' > Actual ExtractedMax '" << bst1.Max() << "': Error!" << endl;
      testBST &= false;
    }
    else
    {
      cout << "Test: " << ++testNumber << ")" << " Previous ExtractedMax '" << ExstactedValue << "' < Actual ExtractedMax '" << bst1.Max() << "': Correct!" << endl;
    }
    ExstactedValue = bst1.MaxNRemove();
  }

  lasd::BST<int> bst2;
  cout << "Test: " << ++testNumber << ")" << " BST are " << evaluateResult(testBST, bst1 == bst2, "Equals (Correct)", "Not Equals (Incorrect)") << endl;

  lasd::BST<int> bst3(vec2);
  bst1 = bst3;
  cout << "Test: " << ++testNumber << ")" << " BST (Copy Assigned) are " << evaluateResult(testBST, bst1 == bst3, "Equals (Correct)", "Not Equals (Incorrect)") << endl;

  bst2 = std::move(bst3);
  cout << "Test: " << ++testNumber << ")" << " BST (Move Assigned) are " << evaluateResult(testBST, bst2 != bst3, "Not Equals (Correct)", "Equals (Incorrect)") << endl;
  cout << "Test: " << ++testNumber << ")" << " BST (Move Assigned) is " << evaluateResult(testBST, bst3.Empty(), "Empty (Correct)", "Not Empty (Incorrect)") << endl;
  cout << "Test: " << ++testNumber << ")" << " BST are " << evaluateResult(testBST, bst1 == bst2, "Equals (Correct)", "Not Equals (Incorrect)") << endl;

  lasd::List<std::string> lst1;
  lst1.Insert("a");
  for (int i = 0; i < 3; i++)
  {
    lst1.InsertAtFront("a" + lst1.Front());
  }
  lasd::BST<std::string> bst4(std::move(lst1));
  cout << "Test: " << ++testNumber << ")" << " Lenghts for BSTs " << evaluateResult(testBST, bst4.Min().length() < bst4.Max().length(), "Correct Set", "Incorrect Set") << endl;
  cout << "Test: " << ++testNumber << ")" << " Predecessor is " << evaluateResult(testBST, bst4.Predecessor("aa") == "a", "Correct", "Incorrect") << endl;
  cout << "Test: " << ++testNumber << ")" << " Successor is " << evaluateResult(testBST, bst4.Successor("aaa") == "aaaa", "Correct", "Incorrect") << endl;
  bool placeholder = true;
  cout << "Test: " << ++testNumber << ")" << " Successor is " << evaluateResult(placeholder, !bst4.Exists("aaaa"), "Deleted (Correct)", "Not Deleted (Incorrect)") << endl;

  bst4.Clear();
  cout << "Test: " << ++testNumber << ")" << " BST is " << evaluateResult(placeholder, bst4.Empty(), "Clear (Correct)", "Not Clear (Incorrect)") << endl;

  lasd::SortableVector<int> vec3(randNumb(gen) + 3);
  for (unsigned long i = 0; i < vec3.Size(); i++)
  {
    vec3[i] = randNumb(gen);
  }
  lasd::BST<int> bst5(vec3);
  cout << "Test: " << ++testNumber << ")" << " BST Root is " << evaluateResult(testBST, bst5.Root().Element() == vec3[0], "Correct", "Incorrect") << endl;

  vec3.Sort();
  cout << "Test: " << ++testNumber << ")" << " BST Min is " << evaluateResult(testBST, vec3[0] == bst5.Min(), "Correct", "Incorrect") << endl;
  cout << "Test: " << ++testNumber << ")" << " BST predecessor of Successor's Min is " << evaluateResult(testBST, bst5.Min() == bst5.Predecessor(bst5.Successor(bst5.Min())), "Correct", "Incorrect") << endl;
  cout << "Test: " << ++testNumber << ")" << " BST Max is " << evaluateResult(testBST, vec3[vec3.Size() - 1] == bst5.Max(), "Correct", "Incorrect") << endl;
  cout << "Test: " << ++testNumber << ")" << " BST successor of Predecessor's Min is " << evaluateResult(testBST, bst5.Max() == bst5.Successor(bst5.Predecessor(bst5.Max())), "Correct", "Incorrect") << endl;

  bst5.Clear();
  try
  {
    bst5.Root();
  }
  catch (std::length_error const &)
  {
    cout << "Test: " << ++testNumber << ")" << " leng_error called BST is Empty, doesn't have root: Correct!" << endl;
  }
  catch (std::exception const &)
  {
    cout << "Test: " << ++testNumber << ")" << " Wrong exception called: Error!" << endl;
    testBST &= false;
  }

  cout << "Test: " << ++testNumber << ")" << " BST Insert has been " << evaluateResult(testBST, bst5.Insert(5), "Executed (Correct)", "Not Executed (Incorrect)") << endl;
  cout << "Test: " << ++testNumber << ")" << " BST Insert has been " << evaluateResult(testBST, bst5.Insert(7), "Executed (Correct)", "Not Executed (Incorrect)") << endl;

  try
  {
    bst5.Successor(8);
  }
  catch (std::length_error const &)
  {
    cout << "Test: " << ++testNumber << ")" << " leng_error, value '8' doesnt' exists in BST: Correct!" << endl;
  }
  catch (std::exception const &)
  {
    cout << "Test: " << ++testNumber << ")" << " exception, value '8' doesnt' exists in BST: Error!" << endl;
    testBST &= false;
  }

  cout << "Test: " << ++testNumber << ")" << " BST Successor Test is " << evaluateResult(testBST, bst5.Successor(6) == 7, "Correct", "Incorrect") << endl;

  lasd::Vector<int> vettore(bst5);
  for (unsigned long i = 0; i < vettore.Size(); i++)
  {
    cout << "Test: " << ++testNumber << ")" << " extracted value from Vector(BST): " << vettore[i] << endl;
  }
  lasd::List<int> lista(bst5);
  for (unsigned long i = 0; i < lista.Size(); i++)
  {
    cout << "Test: " << ++testNumber << ")" << " extracted value from List(BST): " << lista[i] << endl;
  }

  lasd::Vector<int> vettore1((randNumb(gen) % 10) + 5);
  for (unsigned long i = 0; i < vettore1.Size(); i++)
  {
    vettore1[i] = randNumb(gen);
  }
  cout << "Test: " << ++testNumber << ")" << " Trav VEC:";
  vettore1.Traverse(
      [](int dat)
      {
        cout << "-" << dat;
      });
  lasd::BST<int> binserTree(std::move(vettore1));
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " Trav:";
  binserTree.Traverse(
      [](int dat)
      {
        cout << "-" << dat;
      });
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " PreOrder Trav:";
  binserTree.PreOrderTraverse(
      [](int dat)
      {
        cout << "-" << dat;
      });
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " PostOrder Trav:";
  binserTree.PostOrderTraverse(
      [](int dat)
      {
        cout << "-" << dat;
      });
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " InOrder Trav:";
  binserTree.InOrderTraverse(
      [](int dat)
      {
        cout << "-" << dat;
      });
  cout << "\n"
       << "Test: " << ++testNumber << ")" << " Breadth Trav:";
  binserTree.BreadthTraverse(
      [](int dat)
      {
        cout << "-" << dat;
      });

  return testBST;
}

void TestEsercizio2()
{
  bool test = IteratorTest();
  cout << "Iterator Test: ", test ? cout << "Passed!\n" : cout << "NOT passed!\n";
  bool testBTVec = BTVectorTest();
  cout << "\nBTVec Test: ", testBTVec ? cout << "Passed!\n" : cout << "NOT passed!\n";
  bool testBTLnk = BTListTest();
  cout << "\nBTLnk Test: ", testBTLnk ? cout << "Passed!\n" : cout << "NOT passed!\n";
  bool testBST = BSTTest();
  cout << "\nBST Test: ", testBST ? cout << "Passed!\n" : cout << "NOT passed!\n";
}

bool TestClseAdr()
{
  cout << "\n\nBegin of HTCloseAdr Test: " << endl;

  bool testCloseAdr = true;
  int testNumber = 0;

  lasd::Vector<int> vec1(8);
  vec1[0] = 5;
  vec1[1] = 184;
  vec1[2] = -83;
  vec1[3] = -72;
  vec1[4] = -11;
  vec1[5] = -44;
  vec1[6] = -55;
  vec1[7] = -66;

  lasd::HashTableClsAdr<int> htCls1(1, vec1);
  if (!htCls1.Exists(16))
  {
    cout << "Test: " << ++testNumber << ")" << " 16 does NOT Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 16 does Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(184))
  {
    cout << "Test: " << ++testNumber << ")" << " 184 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 184 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(5))
  {
    cout << "Test: " << ++testNumber << ")" << " 5 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 5 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(-83))
  {
    cout << "Test: " << ++testNumber << ")" << " -83 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " -83 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(-72))
  {
    cout << "Test: " << ++testNumber << ")" << " -72 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " -72 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (!htCls1.Exists(1))
  {
    cout << "Test: " << ++testNumber << ")" << " 1 does NOT Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 1 does Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(-11))
  {
    cout << "Test: " << ++testNumber << ")" << " -11 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " -11 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(-44))
  {
    cout << "Test: " << ++testNumber << ")" << " -44 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " -44 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(-55))
  {
    cout << "Test: " << ++testNumber << ")" << " -55 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " -55 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(-66))
  {
    cout << "Test: " << ++testNumber << ")" << " -66 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " -66 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(5))
  {
    cout << "Test: " << ++testNumber << ")" << " 5 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 5 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Remove(5))
  {
    cout << "Test: " << ++testNumber << ")" << " 5 element has been correctly removed: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 5 element has not been removed: Error!" << endl;
    testCloseAdr = false;
  }
  if (!htCls1.Exists(5))
  {
    cout << "Test: " << ++testNumber << ")" << " 5 does NOT Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 5 does Exists: Error!" << endl;
    testCloseAdr = false;
  }
  htCls1.Clear();
  bool flagClear = true;
  for (unsigned long i = 0; i < vec1.Size(); i++)
  {
    if (htCls1.Exists(vec1[i]))
    {
      flagClear &= false;
      testCloseAdr = false;
      cout << "Test: " << ++testNumber << ")" << vec1[i] << " does Exists: Error!" << endl;
    }
    else
    {
      cout << "Test: " << ++testNumber << ")" << vec1[i] << " does NOT Exists: Correct!" << endl;
    }
  }
  if (flagClear)
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn has been correctly Cleared: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn has NOT been correctly Cleared: Error!" << endl;
  }

  lasd::List<double> lst1;
  for (int i = 0; i < randNumb(gen); i++)
  {
    lst1.Insert(randNumb(gen));
  }

  lasd::List<double> lst2(lst1);
  lasd::Vector<double> vec2(lst2);

  lasd::HashTableClsAdr<double> htCls2(std::move(lst1));
  lasd::HashTableClsAdr<double> htCls3(std::move(lst2));
  if (htCls2 == htCls3)
  {
    cout << "Test: " << ++testNumber << ")" << " htCls2 and htCls3 are equals: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htCls2 and htCls3 are NOT equals: Error!" << endl;
    testCloseAdr = false;
  }
  htCls2.Clear();
  if (htCls2.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " htCls2 has been Cleared: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htCls2 has NOT been Cleared: Error!" << endl;
    testCloseAdr = false;
  }
  htCls2 = std::move(htCls3);
  if (htCls3.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " htCls3 has been Swapped: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htCls3 has NOT been Swapped: Error!" << endl;
    testCloseAdr = false;
  }
  if (!htCls2.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " htCls2 is NOT empty now: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htCls2 is empty now: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls2.RemoveSome(vec2) && htCls2.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " all htCls2 Elements have been removed: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " all htCls2 Elements have NOT been removed: Error!" << endl;
    testCloseAdr = false;
  }

  lasd::HashTableClsAdr<int> htCls4(0);
  htCls4.Clear();
  if (htCls4.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn4 is empty now: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn4 is NOT empty now: Error!" << endl;
    testCloseAdr = false;
  }
  for (int i = 0; i < randNumb(gen) * randNumb(gen) + 1; i++)
  {
    int RandomValue = randNumb(gen);
    if (htCls4.Insert(RandomValue))
    {
      cout << " Inserted value: " << RandomValue << endl;
    }
    if (htCls4.Remove(RandomValue))
    {
      cout << " Removed value: " << RandomValue << endl;
    }
  }
  if (htCls4.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " htCls4 is already empty: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htCls4 is NO more empty: Error!" << endl;
    testCloseAdr = false;
  }

  lasd::List<int> lst3;
  for (int i = 0; i < randNumb(gen) + 1; i++)
  {
    lst3.Insert(randNumb(gen));
  }
  lasd::HashTableClsAdr<int> htCls5(31, std::move(lst3));
  lasd::Vector<int> vec3(101);
  for (int i = 0; i <= 100; i++)
  {
    vec3[i] = i;
  };
  htCls5.RemoveSome(vec3);
  if (htCls5.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " (removeSome vec3) every htCls5 element has been correctly removed: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " (removeSome vec3) every htCls5 element has been correctly removed: Error!" << endl;
    testCloseAdr = false;
  }
  htCls5.Clear();
  htCls5.Resize(0);
  htCls5.Clear();
  htCls5.Clear();
  lasd::Vector<int> vec4;
  if (!htCls5.RemoveSome(vec4))
  {
    cout << "Test: " << ++testNumber << ")" << " NO elements have been removed: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " some elements have been removed: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls4 == htCls5)
  {
    cout << "Test: " << ++testNumber << ")" << " the two empty htCls are equal: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " the two empty htCls are NOT equal: error!" << endl;
    testCloseAdr = false;
  }
  if (!htCls5.Remove(5))
  {
    cout << "Test: " << ++testNumber << ")" << " an empty htCls doesn't remove elements: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " an empty htCls remove elements: Error!" << endl;
    testCloseAdr = false;
  }

  lasd::HashTableClsAdr<int> htCls6;
  unsigned long dimension = randNumb(gen) * randNumb(gen) + 1;
  for (unsigned long i = 0; i < dimension; i++)
  {
    htCls6.Insert(randNumb(gen) * randNumb(gen) * randNumb(gen));
  }
  int sizeBefore = htCls6.Size();
  cout << " size before Resizing: " << sizeBefore << endl;
  htCls6.Resize(dimension / 5);
  int sizeAfter = htCls6.Size();
  cout << " size after Resizing: " << sizeAfter << endl;
  if (sizeBefore == sizeAfter)
  {
    cout << "Test: " << ++testNumber << ")" << " size before and after resizing/5 are equals: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " size before and after resizing/5 are NOT equals: Error!" << endl;
    testCloseAdr = false;
  }
  lasd::List<int> lst4;
  int InsertedElement;
  cout << "Creating a List without repetitions: " << endl;
  for (int i = 0; i < randNumb(gen) * randNumb(gen) + 1; i++)
  {
    InsertedElement = randNumb(gen) * randNumb(gen);
    if (!lst4.Exists(InsertedElement))
    {
      lst4.Insert(InsertedElement);
    }
  }
  htCls6.Clear();
  if (htCls6.InsertAll(lst4))
  {
    cout << "Test: " << ++testNumber << ")" << " every element from a List has been inserted: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " some elements from a List have NOT been inserted: Error!" << endl;
    testCloseAdr = false;
  }
  lasd::HashTableClsAdr<int> htCls7;
  htCls7 = htCls6;
  if (!htCls7.InsertSome(lst4))
  {
    cout << "Test: " << ++testNumber << ")" << " NO elements have been inserted: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " some elements have been inserted: Error!" << endl;
    testCloseAdr = false;
  }
  htCls7 = std::move(htCls6);
  if (htCls6 == htCls7)
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn and its(equal) move assignament are equals: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn and its(equal) move assignament are different: Error!" << endl;
    testCloseAdr = false;
  }
  htCls7.Clear();
  htCls7 = std::move(htCls6);
  if (htCls6 != htCls7)
  {
    cout << "Test: " << ++testNumber << ")" << " htCls and its(equal) move assignament are different: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htCls and its(equal) move assignament are equals: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls6.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " moved htCls is empty: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " moved htCls is not empty: Error!" << endl;
    testCloseAdr = false;
  }

  lasd::HashTableClsAdr<int> htCls8(16);
  cout << " Testing specific COLLISIONS on tableSize = 16 (^2 hashing): " << endl;
  if (htCls8.Insert(3))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '3': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '3': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(5))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '5' collide -> '3': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '5': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(11))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '11': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '11': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(13))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '13': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '13': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(19))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '19': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '19': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(21))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '21': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '21': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(27))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '27': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '27': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(29))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '29': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '29': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(37))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '37': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '37': Error!" << endl;
    testCloseAdr = false;
  }

  if (htCls8.Exists(3))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '3' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '3' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(5))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '5' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '5' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(11))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '11' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '11' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(13))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '13' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '13' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(19))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '19' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '19' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(21))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '21' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '21' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(27))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '27' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '27' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(29))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '29' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '29' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(37))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '37' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '37' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }

  cout << " Testing string: " << endl;
  lasd::HashTableClsAdr<std::string> htCls9(12);
  std::string accStr = "X";
  int dimensionStr = (randNumb(gen) % 4) + 1;
  for (int i = 0; i < dimensionStr; i++)
  {
    if (htCls9.Insert(accStr))
    {
      cout << "Test: " << ++testNumber << ")" << " Value '" << accStr << "' inserted: Correct!" << endl;
    }
    else
    {
      cout << "Test: " << ++testNumber << ")" << " Value '" << accStr << "' NOT inserted: Error!" << endl;
      testCloseAdr = false;
    }
    accStr += "X";
  }

  accStr = "X";
  for (int i = 0; i < dimensionStr; i++)
  {
    if (htCls9.Exists(accStr))
    {
      cout << "Test: " << ++testNumber << ")" << " Value '" << accStr << "' exists: Correct!" << endl;
    }
    else
    {
      cout << "Test: " << ++testNumber << ")" << " Value '" << accStr << "' doesn't exist: Error!" << endl;
      testCloseAdr = false;
    }
    accStr += "X";
  }

  return testCloseAdr;
}

bool TestOpnAdr()
{
  cout << "\n\nBegin of HTOpenAdr Test: " << endl;

  bool testOpenAdr = true;
  int testNumber = 1;

  lasd::Vector<int> vec1(8);
  vec1[0] = 5;
  vec1[1] = 184;
  vec1[2] = -83;
  vec1[3] = -72;
  vec1[4] = -11;
  vec1[5] = -44;
  vec1[6] = -55;
  vec1[7] = -66;

  lasd::HashTableOpnAdr<int> htOpn1(1, vec1);
  if (!htOpn1.Exists(16))
  {
    cout << "Test: " << ++testNumber << ")" << " 16 does NOT Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 16 does Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(184))
  {
    cout << "Test: " << ++testNumber << ")" << " 184 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 184 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(5))
  {
    cout << "Test: " << ++testNumber << ")" << " 5 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 5 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(-83))
  {
    cout << "Test: " << ++testNumber << ")" << " -83 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " -83 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(-72))
  {
    cout << "Test: " << ++testNumber << ")" << " -72 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " -72 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (!htOpn1.Exists(1))
  {
    cout << "Test: " << ++testNumber << ")" << " 1 does NOT Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 1 does Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(-11))
  {
    cout << "Test: " << ++testNumber << ")" << " -11 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " -11 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(-44))
  {
    cout << "Test: " << ++testNumber << ")" << " -44 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " -44 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(-55))
  {
    cout << "Test: " << ++testNumber << ")" << " -55 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " -55 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(-66))
  {
    cout << "Test: " << ++testNumber << ")" << " -66 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " -66 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(5))
  {
    cout << "Test: " << ++testNumber << ")" << " 5 does Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 5 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Remove(5))
  {
    cout << "Test: " << ++testNumber << ")" << " 5 element has been correctly removed: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 5 element has not been removed: Error!" << endl;
    testOpenAdr = false;
  }
  if (!htOpn1.Exists(5))
  {
    cout << "Test: " << ++testNumber << ")" << " 5 does NOT Exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " 5 does Exists: Error!" << endl;
    testOpenAdr = false;
  }
  htOpn1.Clear();
  bool flagClear = true;
  for (unsigned long i = 0; i < vec1.Size(); i++)
  {
    if (htOpn1.Exists(vec1[i]))
    {
      flagClear &= false;
      testOpenAdr = false;
      cout << "Test: " << ++testNumber << ")" << vec1[i] << " does Exists: Error!" << endl;
    }
    else
    {
      cout << "Test: " << ++testNumber << ")" << vec1[i] << " does NOT Exists: Correct!" << endl;
    }
  }
  if (flagClear)
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn has been correctly Cleared: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn has NOT been correctly Cleared: Error!" << endl;
  }

  lasd::List<double> lst1;
  for (int i = 0; i < randNumb(gen); i++)
  {
    lst1.Insert(randNumb(gen));
  }

  lasd::List<double> lst2(lst1);
  lasd::Vector<double> vec2(lst2);

  lasd::HashTableOpnAdr<double> htOpn2(std::move(lst1));
  lasd::HashTableOpnAdr<double> htOpn3(std::move(lst2));
  if (htOpn2 == htOpn3)
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn2 and htOpn3 are equals: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn2 and htOpn3 are NOT equals: Error!" << endl;
    testOpenAdr = false;
  }
  htOpn2.Clear();
  if (htOpn2.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn2 has been Cleared: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn2 has NOT been Cleared: Error!" << endl;
    testOpenAdr = false;
  }
  htOpn2 = std::move(htOpn3);
  if (htOpn3.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn3 has been Swapped: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn3 has NOT been Swapped: Error!" << endl;
    testOpenAdr = false;
  }
  if (!htOpn2.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn2 is NOT empty now: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn2 is empty now: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn2.RemoveSome(vec2) && htOpn2.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " all htOpn2 Elements have been removed: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " all htOpn2 Elements have NOT been removed: Error!" << endl;
    testOpenAdr = false;
  }

  lasd::HashTableOpnAdr<int> htOpn4(0);
  htOpn4.Clear();
  if (htOpn4.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn4 is empty now: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn4 is NOT empty now: Error!" << endl;
    testOpenAdr = false;
  }
  for (int i = 0; i < randNumb(gen) * randNumb(gen) + 1; i++)
  {
    int RandomValue = randNumb(gen);
    if (htOpn4.Insert(RandomValue))
    {
      cout << " Inserted value: " << RandomValue << endl;
    }
    if (htOpn4.Remove(RandomValue))
    {
      cout << " Removed value: " << RandomValue << endl;
    }
  }
  if (htOpn4.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn4 is already empty: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn4 is NO more empty: Error!" << endl;
    testOpenAdr = false;
  }

  lasd::List<int> lst3;
  for (int i = 0; i < randNumb(gen) + 1; i++)
  {
    lst3.Insert(randNumb(gen));
  }
  lasd::HashTableOpnAdr<int> htOpn5(31, std::move(lst3));
  lasd::Vector<int> vec3(101);
  for (int i = 0; i <= 100; i++)
  {
    vec3[i] = i;
  };
  htOpn5.RemoveSome(vec3);
  if (htOpn5.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " (removeSome vec3) every htOpn5 element has been correctly removed: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " (removeSome vec3) every htOpn5 element has been correctly removed: Error!" << endl;
    testOpenAdr = false;
  }
  htOpn5.Clear();
  htOpn5.Resize(0);
  htOpn5.Clear();
  htOpn5.Clear();
  lasd::Vector<int> vec4;
  if (!htOpn5.RemoveSome(vec4))
  {
    cout << "Test: " << ++testNumber << ")" << " NO elements have been removed: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " some elements have been removed: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn4 == htOpn5)
  {
    cout << "Test: " << ++testNumber << ")" << " the two empty htOpn are equal: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " the two empty htOpn are NOT equal: error!" << endl;
    testOpenAdr = false;
  }
  if (!htOpn5.Remove(5))
  {
    cout << "Test: " << ++testNumber << ")" << " an empty htOpn doesn't remove elements: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " an empty htOpn remove elements: Error!" << endl;
    testOpenAdr = false;
  }

  lasd::HashTableOpnAdr<int> htOpn6;
  unsigned long dimension = randNumb(gen) * randNumb(gen) + 1;
  for (unsigned long i = 0; i < dimension; i++)
  {
    htOpn6.Insert(randNumb(gen) * randNumb(gen) * randNumb(gen));
  }
  int sizeBefore = htOpn6.Size();
  cout << " size before Resizing: " << sizeBefore << endl;
  htOpn6.Resize(dimension / 5);
  int sizeAfter = htOpn6.Size();
  cout << " size after Resizing: " << sizeAfter << endl;
  if (sizeBefore == sizeAfter)
  {
    cout << "Test: " << ++testNumber << ")" << " size before and after resizing/5 are equals: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " size before and after resizing/5 are NOT equals: Error!" << endl;
    testOpenAdr = false;
  }
  lasd::List<int> lst4;
  int InsertedElement;
  cout << "Creating a List without repetitions: " << endl;
  for (int i = 0; i < randNumb(gen) * randNumb(gen) + 1; i++)
  {
    InsertedElement = randNumb(gen) * randNumb(gen);
    if (!lst4.Exists(InsertedElement))
    {
      lst4.Insert(InsertedElement);
    }
  }
  htOpn6.Clear();
  if (htOpn6.InsertAll(lst4))
  {
    cout << "Test: " << ++testNumber << ")" << " every element from a List has been inserted: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " some elements from a List have NOT been inserted: Error!" << endl;
    testOpenAdr = false;
  }
  lasd::HashTableOpnAdr<int> htOpn7;
  htOpn7 = htOpn6;
  if (!htOpn7.InsertSome(lst4))
  {
    cout << "Test: " << ++testNumber << ")" << " NO elements have been inserted: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " some elements have been inserted: Error!" << endl;
    testOpenAdr = false;
  }
  htOpn7 = std::move(htOpn6);
  if (htOpn6 == htOpn7)
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn and its(equal) move assignament are equals: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn and its(equal) move assignament are different: Error!" << endl;
    testOpenAdr = false;
  }
  htOpn7.Clear();
  htOpn7 = std::move(htOpn6);
  if (htOpn6 != htOpn7)
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn and its(equal) move assignament are different: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " htOpn and its(equal) move assignament are equals: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn6.Empty())
  {
    cout << "Test: " << ++testNumber << ")" << " moved htOpn is empty: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " moved htOpn is not empty: Error!" << endl;
    testOpenAdr = false;
  }

  lasd::HashTableOpnAdr<int> htOpn8(16);
  cout << " Testing specific COLLISIONS on tableSize = 16 (^2 hashing): " << endl;
  if (htOpn8.Insert(3))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '3': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '3': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(5))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '5' collide -> '3': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '5': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(11))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '11': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '11': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(13))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '13': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '13': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(19))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '19': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '19': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(21))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '21': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '21': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(27))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '27': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '27': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(29))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '29': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '29': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(37))
  {
    cout << "Test: " << ++testNumber << ")" << " Inserted '37': Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " NOT inserted '37': Error!" << endl;
    testOpenAdr = false;
  }

  if (htOpn8.Exists(3))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '3' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '3' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(5))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '5' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '5' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(11))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '11' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '11' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(13))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '13' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '13' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(19))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '19' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '19' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(21))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '21' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '21' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(27))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '27' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '27' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(29))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '29' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '29' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(37))
  {
    cout << "Test: " << ++testNumber << ")" << " Value '37' exists: Correct!" << endl;
  }
  else
  {
    cout << "Test: " << ++testNumber << ")" << " Value '37' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }

  cout << " Testing string: " << endl;
  lasd::HashTableOpnAdr<std::string> htOpn9(15);
  std::string accStr = "X";
  int dimensionStr = randNumb(gen) + 1;
  for (int i = 0; i < dimensionStr; i++)
  {
    if (htOpn9.Insert(accStr))
    {
      cout << "Test: " << ++testNumber << ")" << " Value '" << accStr << "' inserted: Correct!" << endl;
    }
    else
    {
      cout << "Test: " << ++testNumber << ")" << " Value '" << accStr << "' NOT inserted: Error!" << endl;
      testOpenAdr = false;
    }
    accStr += "X";
  }

  accStr = "X";
  for (int i = 0; i < dimensionStr; i++)
  {
    if (htOpn9.Exists(accStr))
    {
      cout << "Test: " << ++testNumber << ")" << " Value '" << accStr << "' exists: Correct!" << endl;
    }
    else
    {
      cout << "Test: " << ++testNumber << ")" << " Value '" << accStr << "' doesn't exist: Error!" << endl;
      testOpenAdr = false;
    }
    accStr += "X";
  }

  return testOpenAdr;
}

void TestEsercizio3()
{
  bool testCloseAdr = TestClseAdr();
  cout << "HTCloseAdr Test: ", testCloseAdr ? cout << "Passed!\n" : cout << "NOT passed!\n";
  bool testOpenAdr = TestOpnAdr();
  cout << "HTOpenAdr Test: ", testOpenAdr ? cout << "Passed!\n" : cout << "NOT passed!\n";
}