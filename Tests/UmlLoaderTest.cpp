/**
 * @file UmlLoaderTest.cpp
 * @author ybw0014
 *
 * Test UmlLoader
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <UmlLoader.h>

TEST(UmlLoaderTest, Constructer) {
    UmlLoader loader;
}

TEST(UmlLoaderTest, Loader){
    UmlLoader loader;
    loader.Load();
}