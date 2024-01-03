//
// Created by Rick Lattin on 3/4/21.
//
#include "DSString.h"
#include "catch.hpp"
#include "DSVector.h"

//TEST_CASE("Testing Copy Constructor","[Copy Constructor]"){     //incomplete
//    DSVector<int> first;
//    first.insert(5);
//    first.setSize(20);
//    first.setNextOpen(2);
//
//    DSVector<int> arr(first);
//
//
//
//    REQUIRE(arr.getSize() == 20);
//    REQUIRE(arr.getNextOpen() == 2);
//    REQUIRE(arr[1] == 5);
//
//};

TEST_CASE("Testing Default DSVector Constructor","[default constructor]"){
    DSVector<int> vec;

    REQUIRE(vec.getNextOpen() == 0);
    REQUIRE(vec.getSize() == 10);
};


TEST_CASE("Testing Insert and Brackets Functions","[insert and brackets functions]"){
    DSVector<int> vec;
    vec.insert(5);

    DSVector<DSString> vec2;
    DSString str = "holder";
    DSString strO = "test";
    vec2.insert(str);
    vec2.insert(strO);

    REQUIRE(vec[0] == 5);
    REQUIRE((vec2[1] == "test")== true);
};

TEST_CASE("Testing Remove Operator","[Remove Operator ]"){
    DSVector<int> vec;
    vec.insert(5);
    vec.insert(8);

    vec.remove(0);

    REQUIRE(vec[0] == 8);
};

TEST_CASE("Testing Remove Function","[Remove Function ]"){
    DSVector<int> vec;
    vec.insert(5);
    vec.insert(8);

    int out = vec.remove(0);

    REQUIRE(vec[0] == 8);
    REQUIRE(out == 5);
};

TEST_CASE("Testing Find Function","[Find Function ]"){
    DSVector<int> vec;
    vec.insert(5);
    vec.insert(8);
    vec.insert(4);
    vec.insert(8);

    int loc = vec.find(4);
    int loc2 = vec.find(8);

    REQUIRE(loc == 2);
    REQUIRE(loc2 == 1);
};

TEST_CASE("Testing is founds Function","[isFound Function]"){
DSVector<int> vec;
vec.insert(5);
vec.insert(8);
vec.insert(4);
vec.insert(7);

bool loc = vec.isFound(4);
bool loc2 = vec.isFound(9);

REQUIRE(loc == true);
REQUIRE(loc2 == false);
};

TEST_CASE("Testing Grow Function","[Grow Function ]"){     //incomplete
    DSVector<int> vec;
    vec.insert(1);
    vec.insert(2);
    vec.insert(3);
    vec.insert(4);
    vec.insert(5);
    vec.insert(6);
    vec.insert(7);
    vec.insert(8);

    DSVector<int> vec2;
    vec2.insert(0);
    vec2.insert(1);
    vec2.insert(2);
    vec2.insert(3);
    vec2.insert(4);
    vec2.insert(5);
    vec2.insert(6);
    vec2.insert(7);
    vec2.insert(8);
    vec2.insert(9);
    vec2.insert(10);
    vec2.insert(11);

    REQUIRE(vec.getSize() == 10);
    REQUIRE(vec2.getSize() == 20);
};

TEST_CASE("Testing Get/Set Functions","[Get/Set Functions ]"){
    DSVector<int> vec;
    vec.insert(5);

    REQUIRE(vec.getSize() == 10);
    REQUIRE(vec.getNextOpen() == 1);

    vec.setNextOpen(4);
    vec.setSize(5);

    REQUIRE(vec.getSize() == 5);
    REQUIRE(vec.getNextOpen() == 4);
};
