#include <iostream>
#include <random>

#include "../hashtable/hashtable.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"

#define DimensioneContainer 10

using namespace std;

default_random_engine gen(random_device{}());
uniform_int_distribution<int> RandomNumber(0, 100);

#include "test.hpp"

bool TestClseAdr()
{
  cout << "\n\nBegin of HTCloseAdr Test: " << endl;

  bool testCloseAdr = true;
  int lines = 1;

  lasd::Vector<int> vec1(8);
  vec1[0] = 5;
  vec1[1] = 1792;
  vec1[2] = -123;
  vec1[3] = -1;
  vec1[4] = -2;
  vec1[5] = -4;
  vec1[6] = -5;
  vec1[7] = -6;

  lasd::HashTableClsAdr<int> htCls1(1, vec1);
  if (!htCls1.Exists(16))
  {
    std::cout << lines++ << " 16 does NOT Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " 16 does Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(1792))
  {
    std::cout << lines++ << " 1792 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " 1792 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(5))
  {
    std::cout << lines++ << " 5 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " 5 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(-123))
  {
    std::cout << lines++ << " -123 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " -123 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(-1))
  {
    std::cout << lines++ << " -1 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " -1 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (!htCls1.Exists(1))
  {
    std::cout << lines++ << " 1 does NOT Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " 1 does Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(-2))
  {
    std::cout << lines++ << " -2 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " -2 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(-4))
  {
    std::cout << lines++ << " -4 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " -4 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(-5))
  {
    std::cout << lines++ << " -5 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " -5 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(-6))
  {
    std::cout << lines++ << " -6 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " -6 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Exists(5))
  {
    std::cout << lines++ << " 5 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " 5 does NOT Exists: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls1.Remove(5))
  {
    cout << lines++ << " 5 element has been correctly removed: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " 5 element has not been removed: Error!" << endl;
    testCloseAdr = false;
  }
  if (!htCls1.Exists(5))
  {
    std::cout << lines++ << " 5 does NOT Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " 5 does Exists: Error!" << endl;
    testCloseAdr = false;
  }
  htCls1.Clear();
  bool flagClear = true;
  for (ulong i = 0; i < vec1.Size(); i++)
  {
    if (htCls1.Exists(vec1[i]))
    {
      flagClear &= false;
      testCloseAdr = false;
      cout << lines++ << " " << vec1[i] << " does Exists: Error!" << endl;
    }
    else
    {
      cout << lines++ << " " << vec1[i] << " does NOT Exists: Correct!" << endl;
    }
  }
  if (flagClear)
  {
    cout << lines++ << " htOpn has been correctly Cleared: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htOpn has NOT been correctly Cleared: Error!" << endl;
  }

  lasd::List<double> lst1;
  for (int i = 0; i < RandomNumber(gen); i++)
  {
    lst1.Insert(RandomNumber(gen));
  }

  lasd::List<double> lst2(lst1);
  lasd::Vector<double> vec2(lst2);

  lasd::HashTableClsAdr<double> htCls2(std::move(lst1));
  lasd::HashTableClsAdr<double> htCls3(std::move(lst2));
  if (htCls2 == htCls3)
  {
    cout << lines++ << " htCls2 and htCls3 are equals: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htCls2 and htCls3 are NOT equals: Error!" << endl;
    testCloseAdr = false;
  }
  htCls2.Clear();
  if (htCls2.Empty())
  {
    cout << lines++ << " htCls2 has been Cleared: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htCls2 has NOT been Cleared: Error!" << endl;
    testCloseAdr = false;
  }
  htCls2 = std::move(htCls3);
  if (htCls3.Empty())
  {
    cout << lines++ << " htCls3 has been Swapped: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htCls3 has NOT been Swapped: Error!" << endl;
    testCloseAdr = false;
  }
  if (!htCls2.Empty())
  {
    cout << lines++ << " htCls2 is NOT empty now: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htCls2 is empty now: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls2.RemoveSome(vec2) && htCls2.Empty())
  {
    cout << lines++ << " all htCls2 Elements have been removed: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " all htCls2 Elements have NOT been removed: Error!" << endl;
    testCloseAdr = false;
  }

  lasd::HashTableClsAdr<int> htCls4(0);
  htCls4.Clear();
  if (htCls4.Empty())
  {
    cout << lines++ << " htOpn4 is empty now: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htOpn4 is NOT empty now: Error!" << endl;
    testCloseAdr = false;
  }
  for (int i = 0; i < RandomNumber(gen) * RandomNumber(gen) + 1; i++)
  {
    int RandomValue = RandomNumber(gen);
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
    cout << lines++ << " htCls4 is already empty: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htCls4 is NO more empty: Error!" << endl;
    testCloseAdr = false;
  }

  lasd::List<int> lst3;
  for (int i = 0; i < RandomNumber(gen) + 1; i++)
  {
    lst3.Insert(RandomNumber(gen));
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
    cout << lines++ << " (removeSome vec3) every htCls5 element has been correctly removed: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " (removeSome vec3) every htCls5 element has been correctly removed: Error!" << endl;
    testCloseAdr = false;
  }
  htCls5.Clear();
  htCls5.Resize(0);
  htCls5.Clear();
  htCls5.Clear();
  lasd::Vector<int> vec4;
  if (!htCls5.RemoveSome(vec4))
  {
    cout << lines++ << " NO elements have been removed: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " some elements have been removed: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls4 == htCls5)
  {
    cout << lines++ << " the two empty htCls are equal: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " the two empty htCls are NOT equal: error!" << endl;
    testCloseAdr = false;
  }
  if (!htCls5.Remove(5))
  {
    cout << lines++ << " an empty htCls doesn't remove elements: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " an empty htCls remove elements: Error!" << endl;
    testCloseAdr = false;
  }

  lasd::HashTableClsAdr<int> htCls6;
  ulong dimension = RandomNumber(gen) * RandomNumber(gen) + 1;
  for (ulong i = 0; i < dimension; i++)
  {
    htCls6.Insert(RandomNumber(gen) * RandomNumber(gen) * RandomNumber(gen));
  }
  int sizeBefore = htCls6.Size();
  cout << " size before Resizing: " << sizeBefore << endl;
  htCls6.Resize(dimension / 5);
  int sizeAfter = htCls6.Size();
  cout << " size after Resizing: " << sizeAfter << endl;
  if (sizeBefore == sizeAfter)
  {
    cout << lines++ << " size before and after resizing/5 are equals: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " size before and after resizing/5 are NOT equals: Error!" << endl;
    testCloseAdr = false;
  }
  lasd::List<int> lst4;
  int InsertedElement;
  cout << "Creating a List without repetitions: " << endl;
  for (int i = 0; i < RandomNumber(gen) * RandomNumber(gen) + 1; i++)
  {
    InsertedElement = RandomNumber(gen) * RandomNumber(gen);
    if (!lst4.Exists(InsertedElement))
    {
      lst4.Insert(InsertedElement); // inserisco senza duplicati nella lista
    }
  }
  htCls6.Clear();
  if (htCls6.InsertAll(lst4))
  {
    cout << lines++ << " every element from a List has been inserted: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " some elements from a List have NOT been inserted: Error!" << endl;
    testCloseAdr = false;
  }
  lasd::HashTableClsAdr<int> htCls7;
  htCls7 = htCls6;
  if (!htCls7.InsertSome(lst4))
  {
    cout << lines++ << " NO elements have been inserted: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " some elements have been inserted: Error!" << endl;
    testCloseAdr = false;
  }
  htCls7 = std::move(htCls6);
  if (htCls6 == htCls7)
  {
    cout << lines++ << " htOpn and its(equal) move assignament are equals: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htOpn and its(equal) move assignament are different: Error!" << endl;
    testCloseAdr = false;
  }
  htCls7.Clear();
  htCls7 = std::move(htCls6);
  if (htCls6 != htCls7)
  {
    cout << lines++ << " htCls and its(equal) move assignament are different: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htCls and its(equal) move assignament are equals: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls6.Empty())
  {
    cout << lines++ << " moved htCls is empty: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " moved htCls is not empty: Error!" << endl;
    testCloseAdr = false;
  }

  lasd::HashTableClsAdr<int> htCls8(16);
  cout << " Testing specific COLLISIONS on tableSize = 16 (^2 hashing): " << endl;
  if (htCls8.Insert(3))
  {
    cout << lines++ << " Inserted '3': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '3': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(5))
  {
    cout << lines++ << " Inserted '5' collide -> '3': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '5': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(11))
  {
    cout << lines++ << " Inserted '11': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '11': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(13))
  {
    cout << lines++ << " Inserted '13': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '13': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(19))
  {
    cout << lines++ << " Inserted '19': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '19': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(21))
  {
    cout << lines++ << " Inserted '21': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '21': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(27))
  {
    cout << lines++ << " Inserted '27': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '27': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(29))
  {
    cout << lines++ << " Inserted '29': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '29': Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Insert(37))
  {
    cout << lines++ << " Inserted '37': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '37': Error!" << endl;
    testCloseAdr = false;
  }

  if (htCls8.Exists(3))
  {
    cout << lines++ << " Value '3' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '3' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(5))
  {
    cout << lines++ << " Value '5' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '5' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(11))
  {
    cout << lines++ << " Value '11' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '11' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(13))
  {
    cout << lines++ << " Value '13' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '13' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(19))
  {
    cout << lines++ << " Value '19' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '19' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(21))
  {
    cout << lines++ << " Value '21' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '21' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(27))
  {
    cout << lines++ << " Value '27' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '27' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(29))
  {
    cout << lines++ << " Value '29' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '29' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }
  if (htCls8.Exists(37))
  {
    cout << lines++ << " Value '37' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '37' doesn't exist: Error!" << endl;
    testCloseAdr = false;
  }

  cout << " Testing string: " << endl;
  lasd::HashTableClsAdr<std::string> htCls9(12);
  std::string accStr = "a";
  int dimensionStr = (RandomNumber(gen) % 4) + 1;
  for (int i = 0; i < dimensionStr; i++)
  {
    if (htCls9.Insert(accStr))
    {
      cout << lines++ << " Value '" << accStr << "' inserted: Correct!" << endl;
    }
    else
    {
      cout << lines++ << " Value '" << accStr << "' NOT inserted: Error!" << endl;
      testCloseAdr = false;
    }
    accStr += "a";
  }

  accStr = "a";
  for (int i = 0; i < dimensionStr; i++)
  {
    if (htCls9.Exists(accStr))
    {
      cout << lines++ << " Value '" << accStr << "' exists: Correct!" << endl;
    }
    else
    {
      cout << lines++ << " Value '" << accStr << "' doesn't exist: Error!" << endl;
      testCloseAdr = false;
    }
    accStr += "a";
  }

  return testCloseAdr;
}

bool TestOpnAdr()
{
  cout << "\n\nBegin of HTOpenAdr Test: " << endl;

  bool testOpenAdr = true;
  int lines = 1;

  lasd::Vector<int> vec1(8);
  vec1[0] = 5;
  vec1[1] = 1792;
  vec1[2] = -123;
  vec1[3] = -1;
  vec1[4] = -2;
  vec1[5] = -4;
  vec1[6] = -5;
  vec1[7] = -6;

  lasd::HashTableOpnAdr<int> htOpn1(1, vec1);
  if (!htOpn1.Exists(16))
  {
    std::cout << lines++ << " 16 does NOT Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " 16 does Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(1792))
  {
    std::cout << lines++ << " 1792 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " 1792 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(5))
  {
    std::cout << lines++ << " 5 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " 5 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(-123))
  {
    std::cout << lines++ << " -123 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " -123 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(-1))
  {
    std::cout << lines++ << " -1 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " -1 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (!htOpn1.Exists(1))
  {
    std::cout << lines++ << " 1 does NOT Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " 1 does Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(-2))
  {
    std::cout << lines++ << " -2 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " -2 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(-4))
  {
    std::cout << lines++ << " -4 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " -4 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(-5))
  {
    std::cout << lines++ << " -5 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " -5 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(-6))
  {
    std::cout << lines++ << " -6 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " -6 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Exists(5))
  {
    std::cout << lines++ << " 5 does Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " 5 does NOT Exists: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn1.Remove(5))
  {
    cout << lines++ << " 5 element has been correctly removed: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " 5 element has not been removed: Error!" << endl;
    testOpenAdr = false;
  }
  if (!htOpn1.Exists(5))
  {
    std::cout << lines++ << " 5 does NOT Exists: Correct!" << endl;
  }
  else
  {
    std::cout << lines++ << " 5 does Exists: Error!" << endl;
    testOpenAdr = false;
  }
  htOpn1.Clear();
  bool flagClear = true;
  for (ulong i = 0; i < vec1.Size(); i++)
  {
    if (htOpn1.Exists(vec1[i]))
    {
      flagClear &= false;
      testOpenAdr = false;
      cout << lines++ << " " << vec1[i] << " does Exists: Error!" << endl;
    }
    else
    {
      cout << lines++ << " " << vec1[i] << " does NOT Exists: Correct!" << endl;
    }
  }
  if (flagClear)
  {
    cout << lines++ << " htOpn has been correctly Cleared: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htOpn has NOT been correctly Cleared: Error!" << endl;
  }

  lasd::List<double> lst1;
  for (int i = 0; i < RandomNumber(gen); i++)
  {
    lst1.Insert(RandomNumber(gen));
  }

  lasd::List<double> lst2(lst1);
  lasd::Vector<double> vec2(lst2);

  lasd::HashTableOpnAdr<double> htOpn2(std::move(lst1));
  lasd::HashTableOpnAdr<double> htOpn3(std::move(lst2));
  if (htOpn2 == htOpn3)
  {
    cout << lines++ << " htOpn2 and htOpn3 are equals: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htOpn2 and htOpn3 are NOT equals: Error!" << endl;
    testOpenAdr = false;
  }
  htOpn2.Clear();
  if (htOpn2.Empty())
  {
    cout << lines++ << " htOpn2 has been Cleared: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htOpn2 has NOT been Cleared: Error!" << endl;
    testOpenAdr = false;
  }
  htOpn2 = std::move(htOpn3);
  if (htOpn3.Empty())
  {
    cout << lines++ << " htOpn3 has been Swapped: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htOpn3 has NOT been Swapped: Error!" << endl;
    testOpenAdr = false;
  }
  if (!htOpn2.Empty())
  {
    cout << lines++ << " htOpn2 is NOT empty now: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htOpn2 is empty now: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn2.RemoveSome(vec2) && htOpn2.Empty())
  {
    cout << lines++ << " all htOpn2 Elements have been removed: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " all htOpn2 Elements have NOT been removed: Error!" << endl;
    testOpenAdr = false;
  }

  lasd::HashTableOpnAdr<int> htOpn4(0);
  htOpn4.Clear();
  if (htOpn4.Empty())
  {
    cout << lines++ << " htOpn4 is empty now: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htOpn4 is NOT empty now: Error!" << endl;
    testOpenAdr = false;
  }
  for (int i = 0; i < RandomNumber(gen) * RandomNumber(gen) + 1; i++)
  {
    int RandomValue = RandomNumber(gen);
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
    cout << lines++ << " htOpn4 is already empty: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htOpn4 is NO more empty: Error!" << endl;
    testOpenAdr = false;
  }

  lasd::List<int> lst3;
  for (int i = 0; i < RandomNumber(gen) + 1; i++)
  {
    lst3.Insert(RandomNumber(gen));
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
    cout << lines++ << " (removeSome vec3) every htOpn5 element has been correctly removed: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " (removeSome vec3) every htOpn5 element has been correctly removed: Error!" << endl;
    testOpenAdr = false;
  }
  htOpn5.Clear();
  htOpn5.Resize(0);
  htOpn5.Clear();
  htOpn5.Clear();
  lasd::Vector<int> vec4;
  if (!htOpn5.RemoveSome(vec4))
  {
    cout << lines++ << " NO elements have been removed: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " some elements have been removed: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn4 == htOpn5)
  {
    cout << lines++ << " the two empty htOpn are equal: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " the two empty htOpn are NOT equal: error!" << endl;
    testOpenAdr = false;
  }
  if (!htOpn5.Remove(5))
  {
    cout << lines++ << " an empty htOpn doesn't remove elements: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " an empty htOpn remove elements: Error!" << endl;
    testOpenAdr = false;
  }

  lasd::HashTableOpnAdr<int> htOpn6;
  ulong dimension = RandomNumber(gen) * RandomNumber(gen) + 1;
  for (ulong i = 0; i < dimension; i++)
  {
    htOpn6.Insert(RandomNumber(gen) * RandomNumber(gen) * RandomNumber(gen));
  }
  int sizeBefore = htOpn6.Size();
  cout << " size before Resizing: " << sizeBefore << endl;
  htOpn6.Resize(dimension / 5);
  int sizeAfter = htOpn6.Size();
  cout << " size after Resizing: " << sizeAfter << endl;
  if (sizeBefore == sizeAfter)
  {
    cout << lines++ << " size before and after resizing/5 are equals: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " size before and after resizing/5 are NOT equals: Error!" << endl;
    testOpenAdr = false;
  }
  lasd::List<int> lst4;
  int InsertedElement;
  cout << "Creating a List without repetitions: " << endl;
  for (int i = 0; i < RandomNumber(gen) * RandomNumber(gen) + 1; i++)
  {
    InsertedElement = RandomNumber(gen) * RandomNumber(gen);
    if (!lst4.Exists(InsertedElement))
    {
      lst4.Insert(InsertedElement); // inserisco senza duplicati nella lista
    }
  }
  htOpn6.Clear();
  if (htOpn6.InsertAll(lst4))
  {
    cout << lines++ << " every element from a List has been inserted: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " some elements from a List have NOT been inserted: Error!" << endl;
    testOpenAdr = false;
  }
  lasd::HashTableOpnAdr<int> htOpn7;
  htOpn7 = htOpn6;
  if (!htOpn7.InsertSome(lst4))
  {
    cout << lines++ << " NO elements have been inserted: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " some elements have been inserted: Error!" << endl;
    testOpenAdr = false;
  }
  htOpn7 = std::move(htOpn6);
  if (htOpn6 == htOpn7)
  {
    cout << lines++ << " htOpn and its(equal) move assignament are equals: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htOpn and its(equal) move assignament are different: Error!" << endl;
    testOpenAdr = false;
  }
  htOpn7.Clear();
  htOpn7 = std::move(htOpn6);
  if (htOpn6 != htOpn7)
  {
    cout << lines++ << " htOpn and its(equal) move assignament are different: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " htOpn and its(equal) move assignament are equals: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn6.Empty())
  {
    cout << lines++ << " moved htOpn is empty: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " moved htOpn is not empty: Error!" << endl;
    testOpenAdr = false;
  }

  lasd::HashTableOpnAdr<int> htOpn8(16);
  cout << " Testing specific COLLISIONS on tableSize = 16 (^2 hashing): " << endl;
  if (htOpn8.Insert(3))
  {
    cout << lines++ << " Inserted '3': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '3': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(5))
  {
    cout << lines++ << " Inserted '5' collide -> '3': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '5': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(11))
  {
    cout << lines++ << " Inserted '11': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '11': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(13))
  {
    cout << lines++ << " Inserted '13': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '13': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(19))
  {
    cout << lines++ << " Inserted '19': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '19': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(21))
  {
    cout << lines++ << " Inserted '21': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '21': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(27))
  {
    cout << lines++ << " Inserted '27': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '27': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(29))
  {
    cout << lines++ << " Inserted '29': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '29': Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Insert(37))
  {
    cout << lines++ << " Inserted '37': Correct!" << endl;
  }
  else
  {
    cout << lines++ << " NOT inserted '37': Error!" << endl;
    testOpenAdr = false;
  }

  if (htOpn8.Exists(3))
  {
    cout << lines++ << " Value '3' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '3' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(5))
  {
    cout << lines++ << " Value '5' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '5' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(11))
  {
    cout << lines++ << " Value '11' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '11' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(13))
  {
    cout << lines++ << " Value '13' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '13' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(19))
  {
    cout << lines++ << " Value '19' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '19' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(21))
  {
    cout << lines++ << " Value '21' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '21' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(27))
  {
    cout << lines++ << " Value '27' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '27' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(29))
  {
    cout << lines++ << " Value '29' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '29' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }
  if (htOpn8.Exists(37))
  {
    cout << lines++ << " Value '37' exists: Correct!" << endl;
  }
  else
  {
    cout << lines++ << " Value '37' doesn't exist: Error!" << endl;
    testOpenAdr = false;
  }

  cout << " Testing string: " << endl;
  lasd::HashTableOpnAdr<std::string> htOpn9(15);
  std::string accStr = "a";
  int dimensionStr = RandomNumber(gen) + 1;
  for (int i = 0; i < dimensionStr; i++)
  {
    if (htOpn9.Insert(accStr))
    {
      cout << lines++ << " Value '" << accStr << "' inserted: Correct!" << endl;
    }
    else
    {
      cout << lines++ << " Value '" << accStr << "' NOT inserted: Error!" << endl;
      testOpenAdr = false;
    }
    accStr += "a";
  }

  accStr = "a";
  for (int i = 0; i < dimensionStr; i++)
  {
    if (htOpn9.Exists(accStr))
    {
      cout << lines++ << " Value '" << accStr << "' exists: Correct!" << endl;
    }
    else
    {
      cout << lines++ << " Value '" << accStr << "' doesn't exist: Error!" << endl;
      testOpenAdr = false;
    }
    accStr += "a";
  }

  return testOpenAdr;
}

void mytest()
{
  bool testOpenAdr = TestOpnAdr();
  cout << "OpenAdr Test: ", testOpenAdr ? cout << "Passed!\n" : cout << "NOT passed!\n";

  bool testCloseAdr = TestClseAdr();
  cout << "\nClosedAdr Test: ", testCloseAdr ? cout << "Passed!\n" : cout << "NOT passed!\n";

  if (testOpenAdr && testCloseAdr)
  {
    cout << "\nMyTest : Passato!";
  }
  else
  {
    cout << "\nMyTest : NON Passato!";
  }
}