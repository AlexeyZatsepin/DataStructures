#include <gtest/gtest.h>
#include "../src/vector.h"
#include "../src/unordered_set.h"

// array Test Suite
TEST(VectorTestSuite, VectorAddTest)
{
	vector<int> vector;
	int element1 = 1;
	int element2 = 2;
	vector.add(element1);
	ASSERT_TRUE(vector.contains(element1));
	ASSERT_FALSE(vector.contains(element2));
}

TEST(VectorTestSuite, VectorRemoveTest) {
	vector<int> vector;
	int element1 = 1;
	vector.add(element1);
	ASSERT_EQ(element1,vector.remove());
	ASSERT_FALSE(vector.contains(element1));
}

TEST(VectorTestSuite, VectorInsertTest) {
	vector<int> vector;
	int testElement = 100;
	int testPosition = 0;
	for (size_t i = 0; i < 10; i++) {
		vector.add(i);
	}
	vector.insert(testPosition,testElement);
	ASSERT_TRUE(vector.contains(testElement));
	ASSERT_EQ(vector.indexOf(testElement), testPosition);
	ASSERT_EQ(vector[testPosition], testElement);

}

TEST(VectorTestSuite, VectorSizeTest) {
	vector<int> vector;
	size_t expectedSize=10000;
	for (size_t i = 0; i < expectedSize; i++) {
		vector.add(i);
	}
	ASSERT_EQ(expectedSize, vector.getSize());
}

TEST(VectorTestSuite, VectorGetTest) {
	vector<char> vector;
	for (auto i = 'a'; i < 'z'; i++) {
		vector.add(i);
	}
	int testPosition = 0;
	for (size_t pos = 0; pos < vector.getSize(); pos++) {
		ASSERT_EQ(vector[pos], vector.get(pos));
	}
}
TEST(VectorTestSuite, VectorClearTest) {
	vector<char> vector;
	for (auto i = 'a'; i < 'z'; i++) {
		vector.add(i);
	}
	ASSERT_FALSE(vector.isEmpty());
	vector.clear();
	ASSERT_TRUE(vector.isEmpty());
}

TEST(VectorTestSuite, VectorIndexOfTest) {
	vector< int > vector;
	for (auto i = 0; i < 100; i++) {
		vector.add(i);
	}
	int testElement1 = 1000;
	int testPosition1 = 0;
	int testElement2 = 2000;
	int testPosition2 = 50;
	vector.insert(testPosition1,testElement1);
	vector.insert(testPosition2, testElement2);
	ASSERT_EQ(vector.indexOf(testElement1),testPosition1);
	ASSERT_EQ(vector.indexOf(testElement2), testPosition2);
}


TEST(VectorTestSuite, VectorIteratorTest) {
	vector<int> vector;
	int counter = 0;
	int iterCounter = 0;
	for (auto i = 0; i < 1000000; i++) {
		vector.add(i);
		counter++;
	}
	for (auto i : vector) {
		iterCounter++;
	}
	ASSERT_EQ(iterCounter,counter);
}
