/*
	<multi-thread-drawing>
	Copyright (C) <2016>  <NeverMine17>

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <thread>
#include <iostream>
#include "TXLib.h"
using namespace std;

void threadfunc1()
{
    cout << "First thread" << endl;
    int i;
    txSetColor(TX_BLUE);
    while(1)
    {
        for(i = 0; i < 500; i++)
        {
        txLine(0+i,0+i,random(500),random(500));
        txSleep(10);
        }
    }
}

void threadfunc2()
{
    cout << "Second thread" << endl;
    while(1)
    {
        txSetPixel(random(500),random(500),RGB(random(255), random(255), random(255)));
    }
}

void threadfunc3()
{
    cout << "Second thread" << endl;
    int i;
    while(1)
    {
        txSetPixel(random(500),random(500),TX_GREEN);
    }
}

int main()
{
    txCreateWindow(500,500);
    txSetFillColor(TX_BLACK);
    thread thread1(threadfunc1);
    thread thread2(threadfunc2);
    thread thread3(threadfunc3);
    thread1.join();
    thread2.join();
    thread3.join();
    return 0;
}
