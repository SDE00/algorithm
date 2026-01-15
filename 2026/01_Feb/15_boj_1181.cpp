#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Dot{
    int x;
    int y;
};

bool compare(const Dot& a, const Dot& b){
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

int main()
{
    int n;
    cin >> n;

    Dot dot[n];
    
    //입력
    for(int i=0; i<n; i++){
        cin >> dot[i].x >> dot[i].y;
    }

    //정렬 - sort compare
    sort(dot,dot+n,compare);

    //출력
    for(int i=0; i<n; i++){
        cout << dot[i].x << " " << dot[i].y << "\n";
    }

    return 0;
}
