#include <iostream>
#include <fstream>

using namespace std;

struct comma
{
    string name;
    int argument = 0;
};

void task1(const string &path)
{
    fstream stream;
    stream.open(path);

    int horizontalPos(0), depthPos(0);

    comma temp;
    while(!stream.eof())
    {
        stream >> temp.name >> temp.argument;

        if(temp.name == "forward")
            horizontalPos += temp.argument;
        else if(temp.name == "down")
            depthPos += temp.argument;
        else if(temp.name == "up")
            depthPos -= temp.argument;

        temp.name = ""; temp.argument = 0;
    }

    int result = horizontalPos * depthPos;
    cout << result << '\n';
}

void task2(const string &path)
{
    fstream stream;
    stream.open(path);

    int horizontalPos(0), depthPos(0), aim(0);

    comma temp;
    while(!stream.eof())
    {
        stream >> temp.name >> temp.argument;

        if(temp.name == "forward")
        {
            horizontalPos += temp.argument;
            depthPos += aim * temp.argument;
        }
        else if(temp.name == "down")
        {
            aim += temp.argument;
        }
        else if(temp.name == "up")
        {
            aim -= temp.argument;
        }

        temp.name = ""; temp.argument = 0;
    }

    int result = horizontalPos * depthPos;
    cout << result << '\n';
}

int main() {
    string path;
    fstream fileStream;
    char confirmChar('m');

    cout << "AoC, day 2.\n";
    do {
        cout << "Type path to input file with puzzles:\n";
        cin >> path;

        fileStream.open(path);
        if(fileStream.is_open())
        {
            fileStream.close();
            cout << "File successfully opened!\n";
            cout << "First task result - ";
            task1(path);

            cout << "Second task result - ";
            task2(path);

            break;
        }
        else
        {
            fileStream.close();
            cout << "Wrong path to file. Not opened. Try again? y/n - ";
            cin >> confirmChar;
            if(confirmChar == 'y' || confirmChar == 'Y') confirmChar = 'm';
        }
    }while(confirmChar == 'm');
}
