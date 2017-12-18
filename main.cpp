#include <iostream>
#include <vector>
#include <cmath>
#define POPULATION_SIZE

#define POW(x) x*x

using namespace std;

typedef vector<int> CHROMOSSOME;
typedef vector<CHROMOSSOME> POPULATION;

typedef struct vertex {
    int id;
    int x;
    int y;
    int capacity;
    int demand;
    int distance;
    struct vertex* center;
}VERTEX;

typedef struct graph{
    vector<VERTEX*> listofdots;
    VERTEX* center;
    float totaldist;
}GRAPH;

istream& operator>>(std::istream& is, VERTEX& mydot) {
    cin >> mydot.x;
    cin >> mydot.y;
    cin >> mydot.capacity;
    cin >> mydot.demand;

    return is;
}

bool operator==(const VERTEX& a, const VERTEX& b) {

    return a.x == b.x && a.y == b.y;
}

float distance(VERTEX a, VERTEX b){

    return sqrt(POW(a.x-b.x) + POW(a.y-b.y));

}

int pmedian(vector<VERTEX> v, int nmedians) {

    return 0;
}

int main() {

    int ndots;
    int nmedians;
    int trash;
    VERTEX aux;
    vector<VERTEX> v;

    cin >> ndots;
    cin >> nmedians;
    cin >> trash;
    cin >> trash;

    for (int i = 0; i < ndots; i++) {
        cin >> aux;
        aux.id = i;
        v.push_back(aux);
    }

    for (int i = 0; i < ndots; i++) {
        cout << "id: " << v[i].id << "\n";
        cout << "x: " << v[i].x << "\n";
        cout << "y: " << v[i].y << "\n";
        cout << "capacity: " << v[i].capacity << "\n";
        cout << "demand: " << v[i].demand << "\n";
        cout << "\n";
    }

    pmedian(v, nmedians);

    cin >> trash;
    return 0;
}