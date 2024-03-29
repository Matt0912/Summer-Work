/* Calculate a grade from a mark. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

// Integer constants representing grades.
enum { G1, G21, G22, G3, Fail, Invalid };

// Convert a mark string into an integer.  Return -1 if it is not valid.
// The argument n is the length of the string (normally 1 or 2 or 3).

char digit(char c) {
  if (c > 47 && c < 58) return 1;
  else return 0;
}

int convert(int n, const char mark[]) {
  if (n==1) {
    // If digit between 0 and 9, convert to integer
    if (digit(mark[0])) return strtol(mark, NULL, 10);
  }
  if (n==2) {
    if (digit(mark[0]) && digit(mark[1])) return strtol(mark, NULL, 10);
  }
  if (n==3) {
    if (strtol(mark, NULL, 10) == 100) return strtol(mark, NULL, 10);
    else return -1;
  }

  return -1;
}

// Convert a mark string into a grade.
int grade(int m) {
  if (m >= 0) {
    if (m < 40) return Fail;
    else if (m < 50) return G3;
    else if (m < 60) return G22;
    else if (m < 70) return G21;
    else if (m <= 100) return G1;
    else return Invalid;
  }
  else return Invalid;
}

// -----------------------------------------------------------------------------
// User interface and testing.

// Print out a grade.
void print(int grade) {
    if (grade == G1) printf("First class\n");
    else if (grade == G21) printf("Upper second class\n");
    else if (grade == G22) printf("Lower second class\n");
    else if (grade == G3) printf("Third class\n");
    else if (grade == Fail) printf("Fail\n");
    else if (grade == Invalid) printf("Invalid mark\n");
}

// Check that you haven't changed the grade constants.  (If you do, it spoils
// automatic marking, when your program is linked with a test program.)
void checkConstants() {
    assert(G1==0 && G21==1 && G22==2 && G3==3 && Fail==4 && Invalid==5);
}

// Test grade, at all the boundary points (tests 1 to 12)
void testGrade() {
    assert(grade(0) == Fail);
    assert(grade(39) == Fail);
    assert(grade(40) == G3);
    assert(grade(49) == G3);
    assert(grade(50) == G22);
    assert(grade(59) == G22);
    assert(grade(60) == G21);
    assert(grade(69) == G21);
    assert(grade(70) == G1);
    assert(grade(100) == G1);
    assert(grade(-1) == Invalid);
    assert(grade(101) == Invalid);
}

// Test convert on mark strings from "0" to "100" (tests 13 to 17).
void testConvert() {
    assert(convert(1, "0") == 0);
    assert(convert(1, "9") == 9);
    assert(convert(2, "10") == 10);
    assert(convert(2, "99") == 99);
    assert(convert(3, "100") == 100);
}

// Test that convert rejects non-digits, numbers outside the range 0..100, and
// unnecessary leading zeros which might cause ambiguity because they sometimes
// indicate octal (tests 18 to 25)
void testValidity() {
    assert(convert(4, "40.5") == -1);
    assert(convert(1, "x") == -1);
    assert(convert(2, "-1") == -1);
    assert(convert(4, "40x5") == -1);
    assert(convert(3, " 40") == -1);
    assert(convert(3, "101") == -1);
    assert(convert(3, "547") == -1);
    assert(convert(3, "040") == -1);
}

// Run the tests.
void test() {
    checkConstants();
    testGrade();
    testConvert();
    testValidity();
    printf("All tests pass\n");
}

// Deal with input and output. If there are no arguments call test. If there is
// one argument, calculate and print the grade.
int main(int n, char *args[n]) {
    setbuf(stdout, NULL);
    if (n == 1) test();
    else if (n == 2) print(grade(convert(strlen(args[1]), args[1])));
    else {
        fprintf(stderr, "Use:   ./grade   or   ./grade m\n");
        fprintf(stderr, "where m is an integer mark from 0 to 100\n");
        return 1;
    }
    return 0;
}
