#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectCA2/TreeMapNode.h"
#include "../ProjectCA2/TreeMap.h"
#include "../ProjectCA2/BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeMapTest
{
	TEST_CLASS(TreeMapTest)
	{
	public:
		
		TEST_METHOD(TestPutAndGet)
		{
			TreeMap<int, int> tree;
			tree.put(1, 2);
			Assert::AreEqual(tree.get(1), 2);
		}

		TEST_METHOD(TestSizeOnEmpty)
		{
			TreeMap<int,int> tree;
			Assert::AreEqual(0, tree.size());
		}

		TEST_METHOD(TestSizeOnFullTree)
		{
			TreeMap<int,int> tree;
			tree.put(1,2);
			tree.put(2,6);
			tree.put(3,7);
			tree.put(4,1);
			tree.put(5,9);
			tree.put(6,11);
			tree.put(7,5);

			Assert::AreEqual(7, tree.size());
		}
		TEST_METHOD(TestContainsKey)
		{
			TreeMap<int, int> tree;
			tree.put(1, 2);
			tree.put(2, 6);
			tree.put(3, 7);
			tree.put(4, 1);
			tree.put(5, 9);
			tree.put(6, 11);
			tree.put(7, 5);

			Assert::IsTrue(tree.containsKey(5));
		}

		TEST_METHOD(TestClear)
		{
			TreeMap<int, int> tree;
			tree.put(1, 2);
			tree.put(2, 6);
			tree.put(3, 7);
			tree.put(4, 1);
			tree.put(5, 9);
			tree.put(6, 11);
			tree.put(7, 5);
			Assert::AreEqual(7, tree.size());
			tree.clear();
			Assert::AreEqual(0, tree.size());
		}

		TEST_METHOD(TestSquareBrackets)
		{
			TreeMap<int, int> tree;
			tree.put(1, 2);
			Assert::AreEqual(tree[1], 2);
		}

		TEST_METHOD(TestRemoveKey)
		{
			TreeMap<int, int> tree;
			tree.put(1, 2);
			tree.put(2, 6);
			tree.put(3, 7);
			tree.put(4, 1);
			tree.put(5, 9);
			Assert::AreEqual(5, tree.size());
			tree.removeKey(5);
			Assert::AreEqual(4, tree.size());
		}
		TEST_METHOD(TestKeySet)
		{
			TreeMap<int, int> tree;
			BinaryTree<int> bTree;
			int val = 2;
			bTree.add(val);
			val = 3;
			bTree.add(val);
			val = 4;
			bTree.add(val);
			tree.put(2, 6);
			tree.put(3, 7);
			tree.put(4, 1);
			Assert::AreEqual(tree.keySet(), bTree);
		}
	};

	TEST_CLASS(TreeMapNodeTest)
	{
	public:

		TEST_METHOD(TestGreaterThanKey)
		{
			TreeMapNode<int, int> node1(1, 2);
			TreeMapNode<int, int> node2(3, 4);

			Assert::IsTrue(node2 > node1);
		}
		TEST_METHOD(TestGreaterThanValue)
		{
			TreeMapNode<int, int> node1(2, 2);
			TreeMapNode<int, int> node2(1, 4);

			Assert::IsFalse(node2 > node1);
		}

		TEST_METHOD(TestLessThanKey)
		{
			TreeMapNode<int, int> node1(1, 2);
			TreeMapNode<int, int> node2(3, 4);

			Assert::IsTrue(node1 < node2);
		}

		TEST_METHOD(TestLessThanValue)
		{
			TreeMapNode<int, int> node1(1, 5);
			TreeMapNode<int, int> node2(2, 4);

			Assert::IsFalse(node2 < node1);
		}

		TEST_METHOD(TestEqualToKey)
		{
			TreeMapNode<int, int> node1(1, 2);
			TreeMapNode<int, int> node2(1, 4);

			Assert::IsTrue(node1 == node2);
		}

		TEST_METHOD(TestEqualToValue)
		{
			TreeMapNode<int, int> node1(1, 2);
			TreeMapNode<int, int> node2(2, 2);

			Assert::IsFalse(node1 == node2);
		}
	};
}
