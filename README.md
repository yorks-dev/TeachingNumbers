# TeachingNumbers

Your 4 year old niece is struggling to memorize single digit numbers. You have decided to help her out by building a game so that she can learn the numeric digits. The function implementing the game, expects an array of strings. Each of the 10 digits from '0' to '9' appears exactly once in the array of strings supplied. The remaining characters are periods ('.'). The numbers specified in the input, forms a maze obeying the following rules:
1. The first element contains the letter '0'
2. The second number '1' should be vertically, horizontally or diagonally adjacent to '0'
3. The third number '2' should be adjacent to '1' and so on and so forth. 

Your function should analyze the input supplied and return the count of the numbers until the conditions mentioned above holds true. Make sure you add unit tests to cover each of the cases mentioned below. Feel free to add your own.

<hr>

# NOTE :
  1. The teacNumber.cpp also includes the test cases I used to validate the program.
  2. I used the catch2 for testing. It is locally installed on my PC.
  3. To add another test case, simply add another REQUIRE(); under TESE_CASE().
  
# TestCases

INPUT :

{
 "0...567.",
 "12.4...8",
 "3......9"
}

 OUTPUT : 4 /okk

INPUT :

{
 "0...576.",
 "21.4...8",
 "3......9"
}

 OUTPUT : 4 /okk

 INPUT :
 {
 ".012",
 "..3.",
 ".4..",
 "5...",
 ".6..",
 "..7.",
 "..98"
 }

OUTPUT : 10  /okk


INPUT :
 {
 ".013",
 "..24",
 "....",
 "5...",
 ".6..",
 "..7.",
 "..98"
 }

OUTPUT : 5  /okk

INPUT :
 {
 "....",
 "..78",
 ".6.1",
 ".502",
 "..43"
 }

OUTPUT : 9 /okk

INPUT :
 {
 "1024356789"
 }

OUTPUT : 2  /okk

INPUT : 
"9786543210"

OUTPUT : 7 /okk

<hr>




