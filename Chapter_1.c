/**
 * ====================================================================================
 * C Programming Examples for Students
 * ====================================================================================
 *
 * Description:
 * This file contains a series of basic examples demonstrating the usage of the
 * printf(), scanf(), and various operators in C. Each example is self-contained and
 * includes comments explaining the key concepts.
 *
 * How to Use:
 * 1. Save this file as "c_examples.c".
 * 2. Open a terminal or command prompt.
 * 3. Compile the file using a C compiler like GCC:
 * gcc c_examples.c -o output
 * 4. Run the compiled program:
 * ./output
 *
 * ====================================================================================
 */

#include <stdio.h> // This includes the Standard Input/Output library for functions like printf and scanf.

int main() {

    // --------------------------------------------------------------------------------
    // --- Example 1: Print a Variable ---
    // --------------------------------------------------------------------------------
    printf("--- Example 1: Print a Variable ---\n");
    int a = 99;
    int b = 1;

    // Printing variables and the value of an expression.
    // The %d is a format specifier for integers. The values of a, b, and (a + b)
    // are substituted in order.
    printf("Sum of %d and %d is %d\n\n", a, b, a + b);


    // --------------------------------------------------------------------------------
    // --- Example 2: Print a Literal ---
    // --------------------------------------------------------------------------------
    printf("--- Example 2: Print a Literal ---\n");

    // Instead of using variables, we can use the actual values (literals) directly.
    // The format specifier %d substitutes 99, 1, and the result of 99 + 1 into the string.
    printf("Sum of %d and %d is %d\n\n", 99, 1, 99 + 1);


    // --------------------------------------------------------------------------------
    // --- Example 3: Right Align the Output ---
    // --------------------------------------------------------------------------------
    printf("--- Example 3: Right Align the Output ---\n");
    // We can right-align output by specifying a width with a positive number.
    char s[] = "Welcome to AVIT!";

    // The format specifier %40s prints the string `s` in a total field width
    // of 40 characters. Since the string is shorter than 40 characters, it is
    // padded with spaces on the left, making it appear right-aligned.
    printf("The following string is right-aligned within a 40-character width:\n");
    printf("%40s\n\n", s);


    // --------------------------------------------------------------------------------
    // --- Example 4: Left Align the Output ---
    // --------------------------------------------------------------------------------
    printf("--- Example 4: Left Align the Output with Specified Width ---\n");
    // Using a negative number for the width specifier left-aligns the output.

    // The format specifier %-50s prints the string `s` left-aligned within a
    // minimum width of 50 characters. The remaining space is padded with blanks
    // on the right. "Students" is printed immediately after.
    printf("The following string is left-aligned within a 50-character width:\n");
    printf("%-50sStudents\n\n", s);


    // --------------------------------------------------------------------------------
    // --- Example 5: Add Leading Zeroes to an Integer ---
    // --------------------------------------------------------------------------------
    printf("--- Example 5: Add Leading Zeroes to an Integer ---\n");
    int n = 2451;

    // For integers, using a precision specifier (the dot '.') with a number
    // specifies the MINIMUM number of digits to be printed.
    // The format specifier %.10d ensures the integer `n` is printed with a
    // minimum of 10 digits. If `n` has fewer digits, it is padded with leading zeros.
    printf("The number %d with leading zeros to make 10 digits: %.10d\n\n", n, n);


    // --------------------------------------------------------------------------------
    // --- Example 6: Limit Digits After Decimal Point in a Float ---
    // --------------------------------------------------------------------------------
    printf("--- Example 6: Limit Digits After Decimal Point in a Float ---\n");
    // For floating-point values, the precision specifier limits the number of
    // digits printed AFTER the decimal point.
    float f = 2.451;

    // The format specifier %.2f ensures the floating-point number `f` is
    // printed with exactly 2 digits after the decimal point. It rounds the value if necessary.
    printf("The float %.3f printed to 2 decimal places is: %.2f\n\n", f, f);


    // --------------------------------------------------------------------------------
    // --- Example 7: Getting Integer Input from User ---
    // --------------------------------------------------------------------------------
    printf("--- Example 7: Getting Integer Input from User ---\n");
    int user_num;
    printf("Enter an integer and press Enter: ");

    // scanf("%d", &user_num) reads an integer from the user's input.
    // The '&' is the "address-of" operator. It gives scanf the memory location
    // of `user_num` so it can store the value there.
    scanf("%d", &user_num);

    printf("You entered the number: %d\n\n", user_num);


    // --------------------------------------------------------------------------------
    // --- Example 8: Getting String Input with scanf ---
    // --------------------------------------------------------------------------------
    printf("--- Example 8: Getting String Input with scanf ---\n");
    char name[50]; // Declares a character array (a string) that can hold up to 49 characters + a null terminator.

    printf("Enter your first name and press Enter: ");
    // IMPORTANT: scanf("%s", ...) stops reading when it encounters any whitespace (like a space, tab, or newline).
    // Therefore, it's only good for single words without spaces.
    // Note: We do NOT use the '&' for a character array with %s because the array name itself points to the starting address.
    scanf("%s", name);

    printf("Your name is: %s\n\n", name);


    // --------------------------------------------------------------------------------
    // --- Example 9: Getting a Full Line of Text with fgets ---
    // --------------------------------------------------------------------------------
    printf("--- Example 9: Getting a Full Line of Text with fgets ---\n");
    char greet[50];

    // **IMPORTANT NOTE on input buffer**
    // The previous `scanf` read a name, but it left the 'Enter' key press (a newline character, '\n')
    // in the input buffer. If we call fgets now, it will immediately read that newline and stop.
    // To fix this, we must clear the buffer first. The simplest way is to read and discard that character.
    getchar(); // This consumes the leftover newline character.

    printf("Enter a full greeting (e.g., Hello World): ");
    // fgets is a safer way to read strings, especially those with spaces.
    // It reads until it reaches the specified size, or until it finds a newline.
    // fgets(variable, size, source);
    fgets(greet, sizeof(greet), stdin); // `stdin` is the standard input (the keyboard).

    printf("You entered: %s\n", greet);


    // --------------------------------------------------------------------------------
    // --- Example 10: Common Mistake - Mismatched Format Specifiers ---
    // --------------------------------------------------------------------------------
    printf("--- Example 10: Common Mistake - Mismatched Format Specifiers ---\n");
    // The following line of code is commented out because it causes an error.
    // printf("%s", 10 < 5);

    // EXPLANATION:
    // The format specifier %s tells printf to expect a string (a `char*` pointer).
    // However, the expression '10 < 5' evaluates to a boolean (true/false) value,
    // which in C is represented by an integer: 0 for false, and 1 for true.
    //
    // Trying to print an integer (0) using a specifier for a string (%s) is a
    // type mismatch. This leads to **Undefined Behavior**. The program might crash,
    // print "(null)", or print garbage data. It is incorrect and should be avoided.

    printf("The code `printf(\"%%s\", 10 < 5);` is incorrect and will not work as expected.\n");
    printf("Here is the CORRECT way to print the result of a comparison:\n");

    // To print the result of a comparison, use the integer format specifier %d.
    printf("The result of the expression (10 < 5) is: %d (0 means false)\n", 10 < 5);
    printf("The result of the expression (10 > 5) is: %d (1 means true)\n\n", 10 > 5);


    // --------------------------------------------------------------------------------
    // --- NEW Example 11: Arithmetic Operators ---
    // --------------------------------------------------------------------------------
    printf("--- Example 11: Arithmetic Operators ---\n");
    int x = 10;
    int y = 3;
    printf("Given x = %d and y = %d\n", x, y);
    printf("Addition (x + y): %d\n", x + y);      // Result: 13
    printf("Subtraction (x - y): %d\n", x - y);    // Result: 7
    printf("Multiplication (x * y): %d\n", x * y);  // Result: 30
    // NOTE: When dividing integers, the result is also an integer (the decimal part is truncated).
    printf("Division (x / y): %d\n", x / y);        // Result: 3 (not 3.33)
    // The Modulus operator (%) gives the remainder of a division.
    printf("Modulus (x %% y): %d\n\n", x % y);        // Result: 1 (because 10 / 3 is 3 with a remainder of 1)


    // --------------------------------------------------------------------------------
    // --- NEW Example 12: Increment and Decrement Operators ---
    // --------------------------------------------------------------------------------
    printf("--- Example 12: Increment (++) and Decrement (--) Operators ---\n");
    int count = 5;
    printf("Initial count: %d\n", count);
    // Postfix Increment (count++): The value is USED first, THEN incremented.
    printf("Value during postfix increment (count++): %d\n", count++);
    printf("Value after postfix increment: %d\n", count);
    // Prefix Increment (++count): The value is INCREMENTED first, THEN used.
    count = 5; // Resetting for the next example
    printf("Initial count reset to: %d\n", count);
    printf("Value during prefix increment (++count): %d\n", ++count);
    printf("Value after prefix increment: %d\n\n", count);


    // --------------------------------------------------------------------------------
    // --- NEW Example 13: Assignment Operators ---
    // --------------------------------------------------------------------------------
    printf("--- Example 13: Assignment Operators ---\n");
    int score = 100;
    printf("Initial score: %d\n", score);
    // These operators provide a shorthand for modifying a variable.
    score += 20; // Same as: score = score + 20;
    printf("After score += 20, score is: %d\n", score);
    score -= 50; // Same as: score = score - 50;
    printf("After score -= 50, score is: %d\n", score);
    score *= 2;  // Same as: score = score * 2;
    printf("After score *= 2, score is: %d\n\n", score);


    // --------------------------------------------------------------------------------
    // --- NEW Example 14: Relational and Logical Operators ---
    // --------------------------------------------------------------------------------
    printf("--- Example 14: Relational and Logical Operators ---\n");
    int age = 25;
    int has_id_card = 1; // Using 1 for true

    printf("Given age = %d, has_id_card = %d (1 means true)\n", age, has_id_card);
    // Logical AND (&&): Both conditions must be true for the result to be true (1).
    printf("Is age > 18 AND has_id_card? Result: %d\n", (age > 18) && (has_id_card == 1));
    // Logical OR (||): Only one condition needs to be true for the result to be true (1).
    int is_weekend = 0; // Using 0 for false
    printf("Is age < 18 OR is it the weekend (%d)? Result: %d\n", is_weekend, (age < 18) || (is_weekend == 1));
    // Logical NOT (!): Inverts the boolean value. !true is false, !false is true.
    printf("Is the person NOT 25 years old? !(age == 25) Result: %d\n\n", !(age == 25));


    printf("--- All examples are complete. ---\n");
    return 0; // Indicates that the program executed successfully.
}