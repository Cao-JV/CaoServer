/*
 * CaoS Server v0.1αß
 *
 * An old skool BBS in new skool ways.
 * 
 *  The MIT License
 *
 * Copyright 2022, CaoS.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include<iostream>
#include <string>
#include "ANSITerminal.hpp"

using std::cout;
using std::endl;
using std::string;

/*
 * 
 */


int main(int argc, char** argv) {
    std::locale::global(std::locale(""));    
    Simple::IO::ANSITerminal terminal(true, "");
    string title = "CaoS v0.01ab";
    int  X
        ,Y = 1;
    terminal.ClearScreen();
//    console.SetMaxXY(200, 80);
    terminal.GetMaxXY(X, Y);
    terminal.SetXY(1,1);
    terminal.SetForegroundColour(7);
    terminal.SetBackgroundColour(0);

    terminal.SetForegroundColour(9);
    terminal.SetBackgroundColour(0);
    for (int curX = 1; curX <= X; curX++) {
        terminal.SetXY(curX, 1);
        terminal.Print("%c", 196);
        terminal.SetXY(curX, 3);
        terminal.Print("%c", 196);
    }
    terminal.SetForegroundColour(6);
    terminal.SetXY((X - title.length()) / 2,2);
    terminal.Print(title);
    terminal.SetForegroundColour(15);
    for (int index = 0; index < 256; index++) {
        terminal.Print("%c",index);
    }


    return 0;
}