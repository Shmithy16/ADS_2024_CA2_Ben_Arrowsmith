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
		
		TEST_METHOD(TestPutAndAdd)
		{
			TreeMap<int, int> tree;
			tree.put(1, 2);
			Assert::AreEqual(tree.get(1), 2);
		}
	};

	TEST_CLASS(TreeMapNodeTest)
	{
	public:

		TEST_METHOD(TestGreaterThanFalse)
		{
			TreeMapNode<int, int> node1(1, 2);
			TreeMapNode<int, int> node2(3, 4);

			Assert::IsFalse(node1 > node2);
		}
	};
}
