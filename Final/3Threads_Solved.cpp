#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

int m[10][10] =
{
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,1,0,0,0,0,},
    {0,2,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,1,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,2,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
};

mutex mtx[10][10];
mutex muse;

void printm()
{
    for (int j = 0; j < 10;j++)
    {
        for (int i = 0; i < 10;i++)
        {
            if (m[j][i] == 0)
                std::cout << "  ";
            else
                std::cout << m[j][i];
            cout << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "---------------------------\n";
}

void expand(int x, int y, int value) {
    if (x >= 10 || x < 0 || y >= 10 || y < 0 || m[x][y] != 0 || value >= 10) //
        return;

    if (m[x][y] == 0) {
        mtx[x][y].lock();
        m[x][y] = value;
        mtx[x][y].unlock();
    }
    
    else 
        return;

    expand(x + 1, y, value + 1);
    expand(x - 1, y, value + 1);
    expand(x, y + 1, value + 1);
    expand(x, y - 1, value + 1);
}

void start(int x, int y) {
    int value = m[x][y];

    expand(x + 1, y, value + 1);
    expand(x - 1, y, value + 1);
    expand(x, y + 1, value + 1);
    expand(x, y - 1, value + 1);;
}

void levels()
{
    vector<thread> T(4);
    T[0] = thread(start, 2, 1);
    T[1] = thread(start, 7, 4);
    T[2] = thread(start, 1, 5);
    T[3] = thread(start, 3, 7);

    for (int i = 0; i < 4; i++) {
        T[i].join();
    }

}



int main()
{
    printm();
    levels();
    printm();
}