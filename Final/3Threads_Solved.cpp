#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <tuple>

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

void around(tuple<int, int> cell, queue<tuple<int, int>>* sector) {
    int x = get<0>(cell), y = get<1>(cell);
    int value = m[x][y];

    if (x >= 10 || x < 0 || y >= 10 || y < 0 || value >= 9)
        return;

    if ((m[x + 1][y] == 0 || m[x + 1][y] > value + 1) && x + 1 < 10) {
        mtx[x + 1][y].lock();
        m[x + 1][y] = value + 1;
        mtx[x + 1][y].unlock();
        sector->push(make_tuple(x + 1, y));
    }
        
    if ((m[x - 1][y] == 0 || m[x - 1][y] > value + 1) && x - 1 >= 0) {
        mtx[x - 1][y].lock();
        m[x - 1][y] = value + 1;
        mtx[x - 1][y].unlock();
        sector->push(make_tuple(x - 1, y));
    }
        
    if ((m[x][y + 1] == 0 || m[x][y + 1] > value + 1) && y + 1 < 10) {
        mtx[x][y + 1].lock();
        m[x][y + 1] = value + 1;
        mtx[x][y + 1].unlock();
        sector->push(make_tuple(x, y + 1));
    }
        
    if ((m[x][y - 1] == 0 || m[x][y + 1] > value + 1) && y - 1 >= 0) {
        mtx[x][y - 1].lock();
        m[x][y - 1] = value + 1;
        mtx[x][y - 1].unlock();
        sector->push(make_tuple(x, y - 1));
    }
        
}

void start(int x, int y) {
    
    queue<tuple<int, int>> *sector;
    sector = new queue<tuple<int, int>>;

    sector->push(make_tuple(x, y));
    
    for (int value = m[x][y]; !sector->empty();) {
        
        around(sector->front(), sector);
        sector->pop();
    }   
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