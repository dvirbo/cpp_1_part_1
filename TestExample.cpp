/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <dvir borochov>
 *
 * Date: 2021-02
 */

#define CHECK_THROWS DOCTEST_CHECK_THROWS CHECK
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

using namespace ariel;
using namespace std;

#include "doctest.h"
#include "mat.hpp"
#include <algorithm>
#include <string>
#include <iostream>

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good input")
{
			CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n
													 @-------@\n
													 @-@@@@@-@\n
													 @-@---@-@\n
													 @-@@@@@-@\n
													 @-------@\n
													 @@@@@@@@@"));

			CHECK(nospaces(mat(3, 5, '@', '-')) == nospaces("@@@\n
															@-@\n
															@-@\n
															@-@\n
															@@@"));

			CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n
															  @-----------@\n
															  @-@@@@@@@@@-@\n
															  @-----------@\n
															  @@@@@@@@@@@@@"));


												
}

TEST_CASE("Bad input")
{
	CHECK_THROWS(mat(10, 5, '$', '%')); // "char isn't valid"
	CHECK_THROWS(mat(3, 5, '@', '%'));	// "char isn't valid"
	CHECK_THROWS(mat(-3, 5, '@', '-')); // "column num is negetive-must be positive"
}

TEST_CASE("Bad input-ckeck the err")
{

	CHECK(nospaces(mat(-1, 7, '@', '-')) == "column num is negetive-must be positive");
	CHECK(nospaces(mat(3, -7, '@', '-')) == "row num is negetive-must be positive");
	CHECK(nospaces(mat(3, 7, '@', '-')) == "char isn't valid");
}

