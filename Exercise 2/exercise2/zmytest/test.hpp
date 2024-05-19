
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/traversable.hpp"
#include "../container/dictionary.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../queue/queue.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../stack/stack.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../iterator/iterator.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"

/* ************************************************************************** */

void mytest();

void TestEsercizio1();
void ListTests();
void VectorTests();
void SortableVectorTests();
void StackLstTests();
void StackVecTests();
void QueueLstTests();
void QueueVecTests();

void TestEsercizio2();
bool IteratorTest();
bool BTVectorTest();
bool BTListTest();
bool BSTTest();

/* ************************************************************************** */

#endif