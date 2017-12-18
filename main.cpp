#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#define POPULATION_SIZE 20

#define POW(x) x*x

using namespace std;

typedef vector<int> CHROMOSSOME;
typedef vector<CHROMOSSOME> POPULATION;
int NUMBER_OF_VERTEXES;
int NUMBER_OF_MEDIANS;

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

VERTEX* get_vertex(vector<VERTEX> v, int id){
    for(int i=0; i<v.size(); i++){
        if(v[i].id == id) return &v[i];
    }
    return NULL;
}

bool contains(vector<int> v, int x){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == x) return true;
    }
    return false;
}

POPULATION build_initial_solution(vector<VERTEX> v){

    int aux;
    vector<int> medians;
    CHROMOSSOME aux_chromossome;
    POPULATION initial_population;

    for(int i = 0; i < POPULATION_SIZE; i++){

        // choose the medians
        for(int j = 0; j < NUMBER_OF_MEDIANS; j++){
            do{
                aux = rand()%NUMBER_OF_VERTEXES;
            }while(contains(medians,aux));
            medians[j] = aux;
        }

        // choose a median for each vertex
        for(int j = 0; j < NUMBER_OF_VERTEXES; j++){
            if(contains(medians, j)) aux_chromossome[j] = j;
            else aux_chromossome[j] = medians[rand()%NUMBER_OF_MEDIANS];
        }

        // add this solution to the population
        initial_population[i] = aux_chromossome;

        cout << "\n [";
        for(int j = 0; j < medians.size(); j++) cout << " " << medians[j];
        cout << " ]";

        aux_chromossome.clear();
        medians.clear();
    }

    return initial_population;
}

int p_median(vector<VERTEX> v) {

    POPULATION population = build_initial_solution(v);



    return 0;
}

int main() {
    srand((unsigned)time(0));


    int trash;
    VERTEX aux;
    vector<VERTEX> v;

    cin >> NUMBER_OF_VERTEXES;
    cin >> NUMBER_OF_MEDIANS;
    cin >> trash;
    cin >> trash;

    for (int i = 0; i < NUMBER_OF_VERTEXES; i++) {
        cin >> aux;
        aux.id = i;
        v.push_back(aux);
    }

    /*for (int i = 0; i < NUMBER_OF_VERTEXES; i++) {
        cout << "id: " << v[i].id << "\n";
        cout << "x: " << v[i].x << "\n";
        cout << "y: " << v[i].y << "\n";
        cout << "capacity: " << v[i].capacity << "\n";
        cout << "demand: " << v[i].demand << "\n";
        cout << "\n";
    }*/

    p_median(v);

    cin >> trash;
    return 0;
}