#include <gtest/gtest.h>
#include "../src/unordered_set.h"


//unordered_set Test Suite


TEST(HashSetTestSuite, HashSetAddTest) {
	unordered_set<double> set;
	double element1 = 1;
	double element2 = 2;
	set.add(element1);
	ASSERT_TRUE(set.contains(element1));
	ASSERT_FALSE(set.contains(element2));
}

TEST(HashSetTestSuite, HashSetRemoveTest) {
	unordered_set<int> set;
	int element1 = 1;
	int element2 = 2;
	set.add(element1);
	set.add(element2);
	set.remove(element1);
	ASSERT_TRUE(set.contains(element2));
	ASSERT_FALSE(set.contains(element1));
}

TEST(HashSetTestSuite, HashSetClearTest) {
	unordered_set<int> set;
	for (int i = 0; i < 10000; i++) {
		set.add(i);
	}
	ASSERT_FALSE(set.isEmpty());
	set.clear();
	ASSERT_TRUE(set.isEmpty());
}

TEST(HashSetTestSuite, HashSetSizeTest) {
	unordered_set<size_t> set;
	int expectedSize=20;
	for (size_t i = 0; i < expectedSize; i++) {
		set.add(i);
	}
	ASSERT_EQ(expectedSize,set.getSize());
}

TEST(HashSetTestSuite, HashSetIteratorTest) {
	unordered_set<double> set;
	int counter = 0;
	int itercounter = 0;
	for (double i = 0; i < 10; i+=0.5) {
        set.add(i);
        counter++;
    }
	for (auto i :set) {
        itercounter++;
    }
	ASSERT_EQ(itercounter,counter);
}
