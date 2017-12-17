#include <iostream>
#include <vector>

using namespace std;

struct dot {
    int id;
    int x;
    int y;
    int capacity;
    int demand;
}typedef DOT;

istream& operator>>(std::istream& is, DOT& mydot)
{
    cin >> mydot.x;
    cin >> mydot.y;
    cin >> mydot.capacity;
    cin >> mydot.demand;

    return is;
}

bool operator==(const DOT& a, const DOT& b) {

    if (a.x == b.x && a.y == b.y) {
        return true;
    }
    return false;
}

int pmedian(vector<DOT> v, int nmedians) {

    return 0;
}

int main() {

    int ndots;
    int nmedians;
    int trash;
    DOT aux;
    vector<DOT> v;

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