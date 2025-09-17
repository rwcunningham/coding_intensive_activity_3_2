#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "catch.hpp"
#include "functions_to_implement.cpp"

#include <vector>
#include <string>

TEST_CASE("Split: basic and edge cases", "[Split]") {
    SECTION("basic comma separated") {
        std::vector<std::string> got = Split("a,b,c", ',');
        std::vector<std::string> expected{"a","b","c"};
        REQUIRE(got == expected);
    }
    SECTION("no separator present returns whole string as single element") {
        auto got = Split("abc", ',');
        REQUIRE(got.size() == 1);
        REQUIRE(got[0] == "abc");
    }
    SECTION("leading separator produces empty first token") {
        auto got = Split(",a,b", ',');
        std::vector<std::string> expected{"","a","b"};
        REQUIRE(got == expected);
    }
    SECTION("trailing separator produces empty last token") {
        auto got = Split("a,b,", ',');
        std::vector<std::string> expected{"a","b",""};
        REQUIRE(got == expected);
    }
    SECTION("consecutive separators yield empty fields between") {
        auto got = Split("a,,b,,,c", ',');
        std::vector<std::string> expected{"a","","b","","","c"};
        REQUIRE(got == expected);
    }
    SECTION("empty input yields single empty string") {
        auto got = Split("", ',');
        std::vector<std::string> expected{""};
        REQUIRE(got == expected);
    }
}

TEST_CASE("RemoveAllSubstrings: correctness and corner cases", "[RemoveAllSubstrings]") {
    SECTION("remove simple substring occurrences") {
        std::string s = "the cat in the cathedral";
        REQUIRE(RemoveAllSubstrings(s, "cat") == "the  in the hedral");
    }
    SECTION("s2 not present leaves s1 unchanged") {
        std::string s = "abcdef";
        REQUIRE(RemoveAllSubstrings(s, "xyz") == "abcdef");
    }
    SECTION("empty s2 returns s1 unchanged") {
        std::string s = "abcdef";
        REQUIRE(RemoveAllSubstrings(s, "") == "abcdef");
    }
    SECTION("overlapping occurrences handled correctly") {
        // Removing "aa" from "aaaa" should remove both pairs, leaving empty string.
        // Your implementation searches from current pos after each erase, which is correct here.
        std::string s = "aaaa";
        REQUIRE(RemoveAllSubstrings(s, "aa") == "");
    }
    SECTION("remove all characters when s2 is single char") {
        std::string s = "banana";
        REQUIRE(RemoveAllSubstrings(s, "a") == "bnn");
    }
}

TEST_CASE("Join: basic and edge cases", "[Join]") {
    SECTION("empty vector yields empty string") {
        std::vector<std::string> v;
        REQUIRE(Join(v, ",") == "");
    }
    SECTION("single element is returned unchanged") {
        std::vector<std::string> v{"hello"};
        REQUIRE(Join(v, ", ") == "hello");
    }
    SECTION("multiple elements joined with glue") {
        std::vector<std::string> v{"a","b","c"};
        REQUIRE(Join(v, "-") == "a-b-c");
    }
    SECTION("empty glue concatenates directly") {
        std::vector<std::string> v{"a","b","c"};
        REQUIRE(Join(v, "") == "abc");
    }
    SECTION("elements containing glue are not modified") {
        std::vector<std::string> v{"a-b","c"};
        REQUIRE(Join(v, "-") == "a-b-c");
    }
}

TEST_CASE("MatchVectors: removes elements from a that appear in b", "[MatchVectors]") {
    SECTION("basic removal") {
        std::vector<int> a{1,2,3,4,5};
        std::vector<int> b{2,4,6};
        auto got = MatchVectors(a, b);
        std::vector<int> expected{1,3,5};
        REQUIRE(got == expected);
    }
    SECTION("b empty => a unchanged") {
        std::vector<int> a{7,8,9};
        std::vector<int> b{};
        REQUIRE(MatchVectors(a, b) == a);
    }
    SECTION("a empty => result empty") {
        std::vector<int> a{};
        std::vector<int> b{1,2,3};
        REQUIRE(MatchVectors(a, b).empty());
    }
    SECTION("all elements removed") {
        std::vector<int> a{1,1,2,2};
        std::vector<int> b{1,2};
        std::vector<int> expected{};
        REQUIRE(MatchVectors(a, b) == expected);
    }
    SECTION("duplicates in a preserved when not in b, original order kept") {
        std::vector<int> a{3,3,2,3,1,3};
        std::vector<int> b{2};
        std::vector<int> expected{3,3,3,1,3};
        REQUIRE(MatchVectors(a, b) == expected);
    }
    SECTION("b with extras not in a has no effect") {
        std::vector<int> a{10,11};
        std::vector<int> b{0,1,2,10};
        std::vector<int> expected{11}; // 10 removed, others in b irrelevant
        REQUIRE(MatchVectors(a, b) == expected);
    }
}