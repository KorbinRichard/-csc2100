#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include "Stack.h"
#include "Queue.h"
#include <sstream>
using namespace std;
int main() {

    string filename;
    int capacity;
    Stack<string> garage;
    Queue<string> waiting;

    cout << "Enter event file : ";
    cin >> filename;

    cout << "Enter garage capacity : ";
    cin >> capacity;

    ifstream input("files/" + filename);

    string line;

    while (getline(input, line))
    {
        if (line.empty())
        {
            continue;
        }

        string event;
        string car;

        stringstream ss(line);
        ss >> event >> car;
        if (event == "ARRIVE")
        {
            if (garage.size() < capacity)
            {
                garage.push(car);
            }
            else
            {
                waiting.enqueue(car);
            }
            cout << "ARRIVE " << car << endl;
        }
        if (event == "LEAVE")
        {
            Stack<string> temp;
            bool found = false;

            while (garage.isEmpty()==false)
            {
                string current = garage.pop();

                if (current == car)
                {
                    found = true;
                    break;
                }

                temp.push(current);
            }

            while (temp.isEmpty()==false)
            {
                garage.push(temp.pop());
            }
            if (found==false)
            {
                cout << "LEAVE " << car << " (not found)" << endl;
            }
            else
            {
                cout << "LEAVE " << car << endl;

                if (waiting.isEmpty()==false)
                {
                    garage.push(waiting.dequeue());
                }


            }

        }
        cout << "LANE:";
        Stack<string> temp;

        while (garage.isEmpty() == false)
        {
        	temp.push(garage.pop());
        }


        while (temp.isEmpty() == false)
        {
        	string current = temp.pop();
        	cout << " " << current;
    		garage.push(current);
        }
    cout << endl;
    cout << "WAIT:";


    Queue<string> tempq;

    while (waiting.isEmpty() == false)
    {
        string current = waiting.dequeue();

        cout << " " << current;

        tempq.enqueue(current);
    }

    while (tempq.isEmpty() == false)
    {
        waiting.enqueue(tempq.dequeue());
    }

    cout << endl;
    }





    return 0;
}
