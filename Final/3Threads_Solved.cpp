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

void around(int x , int y, int value, queue<tuple<int*, int, int>>* sector) {
    if (x >= 10 || x < 0 || y >= 10 || y < 0) // || m[x][y] != 0
        return;

    if (m[x + 1][y] == 0 && x + 1 < 10) {
        m[x + 1][y] = value + 1;
        sector->push(make_tuple(&m[x + 1][y], x + 1, y));
    }
        
    if (m[x - 1][y] == 0 && x - 1 >= 0) {
        m[x - 1][y] = value + 1;
        sector->push(make_tuple(&m[x - 1][y], x - 1, y));
    }
        
    if (m[x][y + 1] == 0 && y + 1 < 10) {
        m[x][y + 1] = value + 1;
        sector->push(make_tuple(&m[x][y + 1], x, y + 1));
    }
        
    if (m[x][y - 1] == 0 && y - 1 >= 0) {
        m[x][y - 1] = value + 1;
        sector->push(make_tuple(&m[x][y - 1], x, y - 1));
    }
        
}

void start(int x, int y) {
    
    queue<tuple<int*, int, int>> *sector;
    sector = new queue<tuple<int*, int, int>>;

    sector->push(make_tuple(&m[x][y], x, y));
    


    for (int value = *get<0>(sector->front()); !sector->empty();) {
        around(x, y, value, sector);
        sector->pop();
    }
    
    
    /*
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

*/   
}

/*
void start(int x, int y) {
    int value = m[x][y];

    expand(x + 1, y, value + 1);
    expand(x - 1, y, value + 1);
    expand(x, y + 1, value + 1);
    expand(x, y - 1, value + 1);;
}
*/

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