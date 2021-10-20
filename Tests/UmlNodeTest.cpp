/**
 * @file UmlNodeTest.cpp
 * @author ybw0014
 *
 * Test UmlNode
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <UmlNode.h>

TEST(UmlNodeTest, Constructer) {
    UmlNode goodNode1(L"name", L"Picture");
    UmlNode goodNode2(L"attribute", L"age: int");
    UmlNode goodNode3(L"operation", L"Save(filename: string)");

    UmlNode badNode1(L"attribute", L"cofefe", L"Missing type");
    UmlNode badNode2(L"name", L"", L"Missing class name");
}

TEST(UmlNodeTest, Getters){

    UmlNode goodNode1(L"name", L"Picture");
    UmlNode goodNode2(L"attribute", L"age: int");
    UmlNode goodNode3(L"operation", L"Save(filename: string)");

    ASSERT_EQ(goodNode1.GetType(), L"name");
    ASSERT_EQ(goodNode1.GetValue(), L"Picture");
    ASSERT_EQ(goodNode2.GetType(), L"attribute");
    ASSERT_EQ(goodNode2.GetValue(), L"age: int");
    ASSERT_EQ(goodNode3.GetType(), L"operation");
    ASSERT_EQ(goodNode3.GetValue(), L"Save(filename: string)");

    UmlNode badNode1(L"name", L"cofefe", L"Missing type");
    UmlNode badNode2(L"name", L"", L"Missing class name");

    ASSERT_EQ(badNode1.GetType(), L"name");
    ASSERT_EQ(badNode1.GetValue(), L"cofefe");
    ASSERT_EQ(badNode1.GetBadReason(), L"Missing type");
    ASSERT_EQ(badNode2.GetType(), L"name");
    ASSERT_EQ(badNode2.GetValue(), L"");
    ASSERT_EQ(badNode2.GetBadReason(), L"Missing class name");
}

