#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Purse{
public:
    Purse(); // cria um porta moedas vazio sem dono especificado
    Purse(string owner); // cria um porta moedas vazio cujo dono é "owner"
    void addCoin(float coin); // acrescenta a moeda indicada como parâmetro
    void addCoins(vector<float> coins); // acrescenta as moedas indicadas como parâmetro
    bool removeCoin(float coin); //se existir uma moeda com o valor indicado como parâmetro
                                 // remove‐a e retorna true, se não retorna false
    bool removeAmount(float toRemove, vector<float>& coins); // VER DESCRIÇÃO NA ALÍNEA a)
    float tellAmount() const; // retorna o montante total
    vector<float> tellCoins() const; // retorna uma cópia do vetor das moedas
    void show() const; // mostra o dono, as moedas e o montante total
// ... outros métodos
    static vector<float> possibleCoins; // moedas possíveis: 2, 1, 0.5, 0.2 e 0.1 euro
private:
    string owner; // o dono do porta‐moedas
    vector<float> coins; // as moedas
    float amount; // o montante total (soma do valor das moedas)
};

vector<float> possibleCoins = {2.0f, 1.0f, 0.5f, 0.2f, 0.1f};

Purse::Purse(string owner){
    this->owner = owner;
    this->amount = 0.0f;
}

void Purse::addCoins(vector<float> coins){
    for(const float &n:coins){
        this->coins.push_back(n);
        this->amount += n;
    }
}

bool Purse::removeCoin(float coin){
    vector<float>::iterator it = find(coins.begin(), coins.end(), coin);
    if(it != coins.end()){
        amount -= *it;
        coins.erase(it);
        return true;
    }else{
        return false;
    }
}

bool operator==(const Purse &p1, const Purse &p2){
    if(p1.tellAmount() == p2.tellAmount()) return true;
    vector<float> v1 = p1.tellCoins(), v2 = p2.tellCoins();
    sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
    return (v1 == v2);
}

int main(){
    Purse p1("Ana");
    vector<float> v = {2.0f, 1.0f, 0.5f, 0.5f, 0.2f, 0.2f, 0.1f};
    p1.addCoins(v);
    p1.show();

    Purse p2;
    size_t N = p1.tellCoins().size();
    for(size_t i = 0; i < N; ++i){
        size_t j = rand()%Purse::possibleCoins.size();
        p2.addCoin(Purse::possibleCoins[j]);
    }
    if(p1 == p2) cout << "Purse content is the same" << endl;
    else         cout << "Purse content is different" << endl;

    return 0;
}
