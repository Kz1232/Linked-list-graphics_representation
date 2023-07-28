#include <iostream>
#include <conio.h>
#include <graphics.h>

void displayInputInRectangle(int i,const std::string userInput) {

    // Rectangle coordinates
    int left =i;
    int top = 100;
    int right = i+90;
    int bottom = 150;
// line creator
    line(i+90,125,i+90+20,125);
//    int left =x;
//    int top = 100;
//    int right = x+d;
//    int bottom = 150;

        // Draw the rectangle
    rectangle(left, top, right, bottom);

    // Get user input
//    std::string userInput;
//    std::cout << "Enter text to display inside the rectangle: ";
//    std::getline(std::cin, userInput);

    // Calculate text position to center it inside the rectangle
//    int textWidth = textwidth(userInput.c_str());
//    int textHeight = textheight(userInput.c_str());
    int x = left + (right - left ) / 2;
    int y = top + (bottom - top ) / 2;

    // Display the user input inside the rectangle
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(x, y, const_cast<char*>(userInput.c_str()));

    // Wait for a key press before closing the graphics window
    getch();

}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
     std::string userInput;

//    displayInputInRectangle(1,1);
//    displayInputInRectangle(2,2);
int x=110,i=0;
// yaha loop ma 3 value rakhnu ko khas meaning kehi testo xaina hae
while(i<3)
{
    std::cout << "Enter text to display inside the rectangle: ";
    std::getline(std::cin, userInput);
    displayInputInRectangle(x,userInput);
    x=x+110;
    i++;
}
    closegraph();
    return 0;
}
/*
Certainly! Let's break down the `const_cast<char*>(userInput.c_str())` part step by step:

In C++, the `const_cast` is a type of C++ casting operator used to remove the `const` qualifier from a variable.
It is generally used when you need to work with legacy code or interfaces that expect non-const pointers or references
but provide only const-qualified pointers or references.

In this context, `userInput.c_str()` returns a `const char*`. The `c_str()` function of the `std::string` class returns
a pointer to a null-terminated array of characters representing the contents of the string. Since this function returns
 a pointer to const, it indicates that you should not modify the contents of the string using this pointer.

However, the `outtextxy()` function from the `graphics.h` library expects a `char*` as its third argument, not a `const char*`.
So, to pass the string to `outtextxy()` properly, we need to cast away the `const` qualifier from the `userInput.c_str()`.

Here's the breakdown of the expression:

1.`userInput.c_str()`: This returns a `const char*` pointer to the underlying C-style string representation of
 the `userInput` string.

2. `const_cast<char*>()`: This is a C++ casting operator that removes
the `const` qualifier from the provided type. In this case, it's casting the `const char*` to a `char*`.

By using `const_cast`, we inform the compiler that we acknowledge the potential risks
 involved (such as modifying a const object), and in this specific context, it allows us to use the `userInput.c_str()`
pointer as the third argument of the `outtextxy()` function, which expects a `char*`.

Again, be cautious when using `const_cast` as it can lead to undefined behavior
if you attempt to modify a value that was originally declared as `const`.
In this case, you must ensure that the `outtextxy()` function doesn't modify
the contents of the string, as the original `userInput` is still considered `const`.

Next co-ordinate x must be=prev last x+30;8*/
