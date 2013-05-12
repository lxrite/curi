// Copyright (c) 2013 Clodéric Mars

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma warning(push, 0)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#include <catch.hpp>
#pragma GCC diagnostic pop
#pragma warning(pop)

#include <curi.h>

#include <string>

#include <cstring>

// Reference taken from http://www.w3schools.com/tags/ref_urlencode.asp
static const size_t referenceCount = 95;
static const char* reference[referenceCount * 2] = {
    " ","%20", 
    "!","%21",
    "\"","%22",
    "#","%23", 
    "$","%24", 
    "%","%25", 
    "&","%26", 
    "'","%27", 
    "(","%28", 
    ")","%29", 
    "*","%2A", 
    "+","%2B", 
    ",","%2C", 
    "-","%2D", 
    ".","%2E", 
    "/","%2F", 
    "0","%30", 
    "1","%31", 
    "2","%32", 
    "3","%33", 
    "4","%34", 
    "5","%35", 
    "6","%36", 
    "7","%37", 
    "8","%38", 
    "9","%39", 
    ":","%3A", 
    ";","%3B", 
    "<","%3C", 
    "=","%3D", 
    ">","%3E", 
    "?","%3F", 
    "@","%40", 
    "A","%41", 
    "B","%42", 
    "C","%43", 
    "D","%44", 
    "E","%45", 
    "F","%46", 
    "G","%47", 
    "H","%48", 
    "I","%49", 
    "J","%4A", 
    "K","%4B", 
    "L","%4C", 
    "M","%4D", 
    "N","%4E", 
    "O","%4F", 
    "P","%50", 
    "Q","%51", 
    "R","%52", 
    "S","%53", 
    "T","%54", 
    "U","%55", 
    "V","%56", 
    "W","%57", 
    "X","%58", 
    "Y","%59", 
    "Z","%5A", 
    "[","%5B", 
    "\\","%5C",
    "]","%5D", 
    "^","%5E", 
    "_","%5F", 
    "`","%60", 
    "a","%61", 
    "b","%62", 
    "c","%63", 
    "d","%64", 
    "e","%65", 
    "f","%66", 
    "g","%67", 
    "h","%68", 
    "i","%69", 
    "j","%6A", 
    "k","%6B", 
    "l","%6C", 
    "m","%6D", 
    "n","%6E", 
    "o","%6F", 
    "p","%70", 
    "q","%71", 
    "r","%72", 
    "s","%73", 
    "t","%74", 
    "u","%75", 
    "v","%76", 
    "w","%77", 
    "x","%78", 
    "y","%79", 
    "z","%7A", 
    "{","%7B", 
    "|","%7C", 
    "}","%7D", 
    "~","%7E",
    /* 
    "′","%80", 
    "‚","%82", 
    "ƒ","%83", 
    "„","%84", 
    "…","%85", 
    "†","%86", 
    "‡","%87", 
    "ˆ","%88", 
    "‰","%89", 
    "Š","%8A", 
    "‹","%8B", 
    "Œ","%8C", 
    "Ž","%8E", 
    "‘","%91", 
    "’","%92", 
    "“","%93", 
    "”","%94", 
    "•","%95", 
    "–","%96", 
    "—","%97", 
    "˜","%98", 
    "™","%99", 
    "š","%9A", 
    "›","%9B", 
    "œ","%9C", 
    "ž","%9E", 
    "Ÿ","%9F", 
    " ","%A0", 
    "¡","%A1", 
    "¢","%A2", 
    "£","%A3", 
    "¤","%A4", 
    "¥","%A5", 
    "¦","%A6", 
    "§","%A7", 
    "¨","%A8", 
    "©","%A9", 
    "ª","%AA", 
    "«","%AB", 
    "¬","%AC", 
    "®","%AE", 
    "¯","%AF", 
    "°","%B0", 
    "±","%B1", 
    "²","%B2", 
    "³","%B3", 
    "´","%B4", 
    "µ","%B5", 
    "¶","%B6", 
    "·","%B7", 
    "¸","%B8", 
    "¹","%B9", 
    "º","%BA", 
    "»","%BB", 
    "¼","%BC", 
    "½","%BD", 
    "¾","%BE", 
    "¿","%BF", 
    "À","%C0", 
    "Á","%C1", 
    "Â","%C2", 
    "Ã","%C3", 
    "Ä","%C4", 
    "Å","%C5", 
    "Æ","%C6", 
    "Ç","%C7", 
    "È","%C8", 
    "É","%C9", 
    "Ê","%CA", 
    "Ë","%CB", 
    "Ì","%CC", 
    "Í","%CD", 
    "Î","%CE", 
    "Ï","%CF", 
    "Ð","%D0", 
    "Ñ","%D1", 
    "Ò","%D2", 
    "Ó","%D3", 
    "Ô","%D4", 
    "Õ","%D5", 
    "Ö","%D6", 
    "×","%D7", 
    "Ø","%D8", 
    "Ù","%D9", 
    "Ú","%DA", 
    "Û","%DB", 
    "Ü","%DC", 
    "Ý","%DD", 
    "Þ","%DE", 
    "ß","%DF", 
    "à","%E0", 
    "á","%E1", 
    "â","%E2", 
    "ã","%E3", 
    "ä","%E4", 
    "å","%E5", 
    "æ","%E6", 
    "ç","%E7", 
    "è","%E8", 
    "é","%E9", 
    "ê","%EA", 
    "ë","%EB", 
    "ì","%EC", 
    "í","%ED", 
    "î","%EE", 
    "ï","%EF", 
    "ð","%F0", 
    "ñ","%F1", 
    "ò","%F2", 
    "ó","%F3", 
    "ô","%F4", 
    "õ","%F5", 
    "ö","%F6", 
    "÷","%F7", 
    "ø","%F8", 
    "ù","%F9", 
    "ú","%FA", 
    "û","%FB", 
    "ü","%FC", 
    "ý","%FD", 
    "þ","%FE", 
    "ÿ","%FF"*/};

TEST_CASE("UrlDecode/Single", "Unit characters")
{
    char output[8];
    memset(output,0,8*sizeof(char));

    for (size_t i(0) ; i < referenceCount ; ++i)
    {
        std::string expectedOutput = reference[2*i];
        std::string input = reference[2*i+1];

        std::ostringstream oss;
        oss << i << ": " << input << "=" << expectedOutput; 
        SECTION(oss.str(), "")
        {   
            CAPTURE(expectedOutput);
            
            CAPTURE(input);

            CHECK(curi_url_decode(input.c_str(),input.length(),output,8,0) == curi_status_success);
            CAPTURE(output);
            CHECK(expectedOutput == output);
        }
    }
}

