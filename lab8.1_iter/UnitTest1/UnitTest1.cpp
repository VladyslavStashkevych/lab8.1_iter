#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "../lab8.1_iter/lab8.1_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
public:
	TEST_METHOD(TestMethod1) {
		char s[100] = "aaabbbccc";
		char g[100] = "******";
		int* arr = new int[34];
		char* c = new char[101];
		int t = Count(s, "abc", arr);
		c = Change(s, arr);
		Assert::AreEqual(3, t);
		Assert::AreEqual(g, c);
	}
	};
}
