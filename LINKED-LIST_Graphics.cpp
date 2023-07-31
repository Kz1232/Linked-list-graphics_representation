#include <iostream>
#include <conio.h>
#include<stdlib.h>
#include<cstdio>
#include<windows.h>
#include <graphics.h>
using namespace std;
struct node{
    int info;
    struct node *next;
};
struct node *pfirst=NULL;
void insertatend( int va)
{
	struct node* pthis;
	//count++;
    struct node* pnew=(struct node*)malloc(sizeof(struct node));
    pnew->info=va;
    if(pfirst==NULL)
    {
        std::cout<<"\nThe list is empty so first node is created succesfully";
        pnew->next=NULL;
        pfirst=pnew;
   }
    else
    {
        pthis=pfirst;
        while(pthis->next!=NULL)
        {
            pthis=pthis->next;
        }
        pthis->next=pnew;
        pnew->next=NULL;
        cout<<"\nNew node addition successfull";
    }
}
// drawing part here
void displayInputInRectangle(int i,int userInput) {

// Rectangle coordinates
    int left =i;
    int top = 100;
    int right = i+90;
    int bottom = 150;
//Box line
int c=(left+right)/2;
line(c,100,c,150);

// conncting line creator
    line(i+90,125,i+90+20,125);
// Draw the rectangle
    rectangle(left, top, right, bottom);

   
    int x=left+20;
    int y = top + (bottom - top ) / 2;

    // Display the user input inside the rectangle
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(x, y, const_cast<char*>(std::to_string(userInput).c_str()));

    // delays your graph windows for 700ms
    delay(700);

}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
     int data;
     char g;
int x=110,i=0;

do{
    std::cout << "\nEnter text to display inside the rectangle: ";
    cin>>data;
    cout<<"111";
    insertatend(data);
    cout<<"\nrrr";
    displayInputInRectangle(x,data);
    x=x+110;
    cout<<"\nEnter y to insert the data in the linked list again:";
    g=getch();
}while(g=='y'||g=='Y');
    closegraph();
    delay(300);
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

Next co-ordinate x must be=prev last x+30;8 */
