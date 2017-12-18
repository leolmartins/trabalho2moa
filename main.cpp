#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <unordered_map>
#include <algorithm>

#define POPULATION_SIZE 20
#define NUMBER_OF_ITERATIONS 100

using namespace std;

typedef vector<int> CHROMOSSOME;
typedef vector<CHROMOSSOME> POPULATION;

typedef struct vertex {
    int id;
    int x;
    int y;
    int capacity;
    int demand;
}VERTEX;

int NUMBER_OF_VERTEXES;
int NUMBER_OF_MEDIANS;
unordered_map<int, VERTEX> LIST_OF_VERTEXES;

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

inline int square(int x) { return x*x; }

float distance(VERTEX a, VERTEX b){
    return sqrt((float) (square(a.x-b.x) + square(a.y-b.y)));
}

VERTEX get_vertex(int id){ return LIST_OF_VERTEXES.find(id)->second; }

float vector_min(vector<float> vet){
    float return_value = vet[0];

    for(int i = 0; i<POPULATION_SIZE; i++){
        if( vet[i] < return_value ) return_value = vet[i];
    }

    return return_value;
}

bool vector_contains(vector<int> v, int x){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == x) return true;
    }
    return false;
}

bool sort_comparator(int x, int y){ return (get_vertex(x).demand > get_vertex(y).demand); }

float evaluate_solution(CHROMOSSOME solution){
    float obj = 0;

    for(int i = 0; i<NUMBER_OF_VERTEXES; i++) obj += distance(get_vertex(solution[i]), get_vertex(i));

    return obj;
}

POPULATION build_initial_population(){

    int aux;
    vector<int> sorted;
    vector<int> medians;
    vector<int> medians_capacity;
    CHROMOSSOME aux_chromossome;
    POPULATION initial_population;

    for(int i = 0; i < POPULATION_SIZE; i++){

        aux_chromossome.resize(NUMBER_OF_VERTEXES);
        medians.resize(NUMBER_OF_MEDIANS);
        medians_capacity.resize(NUMBER_OF_MEDIANS);

        // choose the medians
        for(int j = 0; j < NUMBER_OF_MEDIANS; j++){
            do{
                aux = rand()%NUMBER_OF_VERTEXES;
            }while(vector_contains(medians,aux));
            medians[j] = aux;
            medians_capacity[j] = get_vertex(aux).capacity-get_vertex(aux).demand;
        }

        // sort vertexes by demand
        for(int j = 0; j< NUMBER_OF_VERTEXES; j++) sorted.push_back(j);
        sort(sorted.begin(), sorted.end(), sort_comparator);

        // choose a median for each vertex
        for(int j = 0; j < NUMBER_OF_VERTEXES; j++){
            if(vector_contains(medians, sorted[j])) aux_chromossome[sorted[j]] = sorted[j];
            else{
                aux = rand()%NUMBER_OF_MEDIANS;

                // the chosen median need to be able to support the vertex
                while( medians_capacity[aux]-get_vertex(sorted[j]).demand < 0 ){
                    aux = (aux + 1)%NUMBER_OF_MEDIANS;
                }

                aux_chromossome[sorted[j]] = medians[aux];
                medians_capacity[aux] -= get_vertex(sorted[j]).demand;

            }
        }

        // add this solution to the population
        initial_population.push_back(aux_chromossome);

        cout << "\n [";
        for(int j = 0; j < medians.size(); j++) cout << " " << medians[j];
        cout << " ]";
        cout << "\n [";
        for(int j = 0; j < aux_chromossome.size(); j++) cout << " " << aux_chromossome[j];
        cout << " ]\n";

        aux_chromossome.clear();
        medians.clear();
        medians_capacity.clear();
        sorted.clear();

    }

    return initial_population;
}

float p_median() {

    int return_value;
    int iteration = 1;
    vector<float> sol_score;
    sol_score.resize(POPULATION_SIZE);

    // build an initial population
    POPULATION population = build_initial_population();

    // evaluates each solution in the population
    for(int i = 0; i<POPULATION_SIZE; i++) sol_score[i] = evaluate_solution(population[i]);

    // evolution proccess
    while(NUMBER_OF_ITERATIONS >= iteration){

        // selects chromossomes for reproduction
        //

        // reproducts the selected chromossomes
        //

        // mutates the chromossomes
        //

        // local search
        //

        // evaluates each chromossome in the population
        for(int i = 0; i<POPULATION_SIZE; i++) sol_score[i] = evaluate_solution(population[i]);

        iteration++;
    }

    // return the best score
    return vector_min(sol_score);
}

int main() {
    srand((unsigned)time(0));

    int trash;
    VERTEX aux;
    //vector<VERTEX> v;

    cin >> NUMBER_OF_VERTEXES;
    cin >> NUMBER_OF_MEDIANS;

    for (int i = 0; i < NUMBER_OF_VERTEXES; i++) {
        cin >> aux;
        aux.id = i;
        LIST_OF_VERTEXES.insert({i, aux});
    }

    for (int i = 0; i < NUMBER_OF_VERTEXES; i++) {
        cout << "id: " << LIST_OF_VERTEXES.find(i)->second.id << "\n";
        cout << "x: " << LIST_OF_VERTEXES.find(i)->second.x << "\n";
        cout << "y: " << LIST_OF_VERTEXES.find(i)->second.y << "\n";
        cout << "capacity: " << LIST_OF_VERTEXES.find(i)->second.capacity << "\n";
        cout << "demand: " << LIST_OF_VERTEXES.find(i)->second.demand << "\n";
        cout << "\n";
    }

    p_median();

    cin >> trash;
    return 0;
}