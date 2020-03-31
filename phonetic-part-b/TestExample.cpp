/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;
#include <string>
using namespace std;

TEST_CASE("Test replacement of p and b")
{
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    text = "xxx habby yyy";
    CHECK(find(text, "happy") == string("habby"));
    CHECK(find(text, "habby") == string("habby"));
    CHECK(find(text, "hapby") == string("habby"));
    CHECK(find(text, "habpy") == string("habby"));
    text = "xxx habpy yyy";
    CHECK(find(text, "happy") == string("habpy"));
    CHECK(find(text, "habby") == string("habpy"));
    CHECK(find(text, "hapby") == string("habpy"));
    CHECK(find(text, "habpy") == string("habpy"));
    text = "xxx hapby yyy";
    CHECK(find(text, "happy") == string("hapby"));
    CHECK(find(text, "habby") == string("hapby"));
    CHECK(find(text, "hapby") == string("hapby"));
    CHECK(find(text, "habpy") == string("hapby"));
    text = "xxx be yyy";
    CHECK(find(text, "be") == string("be"));
    CHECK(find(text, "pe") == string("be"));
    text = "xxx pe yyy";
    CHECK(find(text, "be") == string("pe"));
    CHECK(find(text, "pe") == string("pe"));

    /* Add more checks here */
}

TEST_CASE("Test replacement of p and f")
{
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
    text = "xxx haffy yyy";
    CHECK(find(text, "happy") == string("haffy"));
    CHECK(find(text, "haffy") == string("haffy"));
    CHECK(find(text, "hapfy") == string("haffy"));
    CHECK(find(text, "hafpy") == string("haffy"));
    text = "xxx hafpy yyy";
    CHECK(find(text, "happy") == string("hafpy"));
    CHECK(find(text, "haffy") == string("hafpy"));
    CHECK(find(text, "hapfy") == string("hafpy"));
    CHECK(find(text, "hafpy") == string("hafpy"));
    text = "xxx hapfy yyy";
    CHECK(find(text, "happy") == string("hapfy"));
    CHECK(find(text, "haffy") == string("hapfy"));
    CHECK(find(text, "hapfy") == string("hapfy"));
    CHECK(find(text, "hafpy") == string("hapfy"));

    /* Add more checks here */
}
TEST_CASE("Test replacement of w <-> v and y<->i")
{
    string text = "xxx worry yyy";
    CHECK(find(text, "worry") == string("worry"));
    CHECK(find(text, "vorry") == string("worry"));
    CHECK(find(text, "worri") == string("worry"));
    CHECK(find(text, "vorri") == string("worry"));

    text = " xxx vorry yyy";
    CHECK(find(text, "vorry") == string("vorry"));
    CHECK(find(text, "worry") == string("vorry"));
    CHECK(find(text, "vorri") == string("vorry"));
    CHECK(find(text, "worri") == string("vorry"));

    text = "xxx worri yyy";
    CHECK(find(text, "worri") == string("worri"));
    CHECK(find(text, "worry") == string("worri"));
    CHECK(find(text, "vorri") == string("worri"));
    CHECK(find(text, "vorry") == string("worri"));

    text = "xxx vorri yyy";
    CHECK(find(text, "vorri") == string("vorri"));
    CHECK(find(text, "worri") == string("vorri"));
    CHECK(find(text, "vorry") == string("vorri"));
    CHECK(find(text, "worry") == string("vorri"));

    text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "happi") == string("happy"));

    text = "xxx happi yyy";
    CHECK(find(text, "happy") == string("happi"));
    CHECK(find(text, "happi") == string("happi"));
}

TEST_CASE("Test replacement of d<->t and o<->u")
{

    string text = "xxx dont yyy";
    CHECK(find(text, "dont") == string("dont"));
    CHECK(find(text, "dond") == string("dont"));
    CHECK(find(text, "dund") == string("dont"));
    CHECK(find(text, "dunt") == string("dont"));

    text = "xxx dond yyy";

    CHECK(find(text, "dont") == string("dond"));
    CHECK(find(text, "dond") == string("dond"));
    CHECK(find(text, "dund") == string("dond"));
    CHECK(find(text, "dunt") == string("dond"));

    text = "xxx dund yyy";
    CHECK(find(text, "dont") == string("dund"));
    CHECK(find(text, "dond") == string("dund"));
    CHECK(find(text, "dund") == string("dund"));
    CHECK(find(text, "dunt") == string("dund"));

    text = "xxx dunt yyy";
    CHECK(find(text, "dont") == string("dunt"));
    CHECK(find(text, "dond") == string("dunt"));
    CHECK(find(text, "dund") == string("dunt"));
    CHECK(find(text, "dunt") == string("dunt"));

    text = "xxx worry yyy";
    CHECK(find(text, "wurry") == string("worry"));
    text = "xxx wurry yyy";
    CHECK(find(text, "wurry") == string("wurry"));
    CHECK(find(text, "worry") == string("wurry"));
}

TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    text = "xxx happI yyy";
    CHECK(find(text, "happi") == string("happI"));
    CHECK(find(text, "Happi") == string("happI"));
    CHECK(find(text, "HAPPI") == string("happI"));
    CHECK(find(text, "HaPpI") == string("happI"));
    text = "xxx haBBi yyy";
    CHECK(find(text, "happi") == string("haBBi"));
    CHECK(find(text, "Happi") == string("haBBi"));
    CHECK(find(text, "HAPPI") == string("haBBi"));
    CHECK(find(text, "HaPpI") == string("haBBi"));
    text = "xxx Be yyy";
    CHECK(find(text, "Be") == string("Be"));
    CHECK(find(text, "be") == string("Be"));

    text = "xxx bE yyy";
    CHECK(find(text, "be") == string("bE"));
    CHECK(find(text, "Be") == string("bE"));
    CHECK(find(text, "bE") == string("bE"));

    text = "xxx WORRY yyy";
    CHECK(find(text, "worry") == string("WORRY"));
    CHECK(find(text, "vorry") == string("WORRY"));
    CHECK(find(text, "worri") == string("WORRY"));
    CHECK(find(text, "vorri") == string("WORRY"));

    text = "xxx VORRY yyy";
    CHECK(find(text, "worry") == string("VORRY"));
    CHECK(find(text, "vorry") == string("VORRY"));
    CHECK(find(text, "worri") == string("VORRY"));
    CHECK(find(text, "vorri") == string("VORRY"));

    text = "xxx VORRI yyy";
    CHECK(find(text, "worry") == string("VORRI"));
    CHECK(find(text, "vorry") == string("VORRI"));
    CHECK(find(text, "worri") == string("VORRI"));
    CHECK(find(text, "vorri") == string("VORRI"));

    text = "xxx DONT yyy";
    CHECK(find(text, "dont") == string("DONT"));
    CHECK(find(text, "dond") == string("DONT"));
    CHECK(find(text, "dunt") == string("DONT"));
    CHECK(find(text, "dund") == string("DONT"));

    text = "xxx DOND yyy";
    CHECK(find(text, "dont") == string("DOND"));
    CHECK(find(text, "dond") == string("DOND"));
    CHECK(find(text, "dunt") == string("DOND"));
    CHECK(find(text, "dund") == string("DOND"));
    /* Add more checks here */
}

/* Add more test cases here */
