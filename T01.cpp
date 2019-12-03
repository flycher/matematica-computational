#include <iostream>
#include <math.h>

using namespace std;

typedef long double ld;

ld solve(int questao, ld x){
    ld res;

    switch(questao){
        case 1:
            res = pow(x,5) - 3*pow(x,4) - 3*pow(x,2) + 2;
            return res;

        case 2:
            res = pow(x,0.5) - pow(5,-x);
            return res;

        case 3:
            res = pow(x,5) - pow(x,4) - 4*x + 1;
            return res;

        case 4:
            res = 0.05*pow(x,3) - 0.4*pow(x,2) + 2*x*sin(x);
            return res;

        default:
            return -1;
    }
}

ld error(int questao){
    switch(questao){
        case 1:
            return 0.03125;

        case 2:
            return 0.001;

        case 3:
            return 0.01;

        case 4:
            return 0.005;

        default:
            return -1;
    }
}

pair<ld, int> bissecao(ld a, ld b, int iter, int questao)
{
    ld erro = error(questao);
    ld resp;
    ld Fb = solve(questao, b);

    int i;
    for(i = 1; i < iter; i++)
    {
        resp = (a + b) / 2;
        ld Fresp = solve(questao, resp);

        if(abs(Fresp) <= erro && (b + a) / 2 <= erro)
            return make_pair(resp, i);

        if(Fresp * Fb < 0)
        {
            a = resp;
        }
        else
        {
            b = resp;
            Fb = Fresp;
        }
    }
    return make_pair(resp, i);
}

ld zero_reta(ld a, ld b, int questao){
	ld Fa = solve(questao, a);
	ld Fb = solve(questao, b);

	return (a * Fb - b * Fa)/(Fb - Fa);
}

pair<ld, int> falsa_posicao(ld a, ld b, int iter, int questao)
{
    ld erro = error(questao);
    ld Fa = solve(questao, a);
    ld ax;

    int i;
    for(i = 1; i < iter; i++)
    {
        ax = zero_reta(a, b, questao);
        ld ay = solve(questao, ax);

        if(abs(ay) <= erro)
            return make_pair(ax, i);

        if(Fa * ay < 0)
        {
            b = ax;
        }
        else
        {
            a = ax;
            Fa = ay;
        }
    }

    return make_pair(ax, i);
}

pair<ld, int> pegaso(ld a, ld b, int iter, int questao)
{
    ld erro = error(questao);
    ld Fa = solve(questao, a);
    ld Fb = solve(questao, b);
    ld resp = b;
    ld Fresp = Fb;
    ld Delta;

    int i;
    for(i = 1; i < iter; i++)
    {
        Delta = -Fresp/(Fb - Fa) * (b - a);
        resp += Delta;
        Fresp = solve(questao, resp);

        if(abs(Fresp) <= erro)
            return make_pair(resp, i);

        if(Fresp * Fb < 0)
        {
            a = b;
            Fa = Fb;
        }
        else
        {
            Fa = Fa * Fb/(Fb + Fresp);
        }
        b = resp;
        Fb = Fresp;
    }

    return make_pair(resp, i);

}

int main (){

    int questao;

    cout << "Qual questão a ser resolvida? ";
    cout << "[1] -> f(x) = x^5 − 3x^4 − 3x^2 + 2 , com e = 2^−5." << endl;
    cout << "[2] -> f(x) = sqrt(x) −5^−x , com e = 10^−3." << endl;
    cout << "[3] -> f(x) = x^5 − x^4 − 4x + 1 , com e = 0.01." << endl;
    cout << "[4] -> f(x) = 0.05x^3 − 0.4x^2 + 3xsenx, com e = 0.005." << endl;
    cout << "-> " << endl;
    cin >> questao;

    ld a,b;
    cout << "Determine o intervalo [a,b]: ";
    cin >> a >> b;

    int metodo;
    cout << "Por qual método deseja resolver a questão?" << endl;
    cout <<"[1] -> Bissecao\n [2] -> Falsa Posição\n [3] -> Pégaso" << endl;
    cout << "-> " << endl;
    cin >> metodo;

    int iter;
    cout << "Defina o limite de iterações: ";
    cin >> iter;

    pair<ld, int> resp;
    cout << "A raiz da equação é o número de iterações são:\n\t";
    switch (metodo)
    {
        case 1:
            resp = bissecao(a, b, iter, questao);
            cout << "Raiz: " << resp.first << " , ";
            cout << "Iterações: " << resp.second << endl;
            break;

        case 2:
            resp = falsa_posicao(a, b, iter, questao);
            cout << "Raiz: " << resp.first << " , ";
            cout << "Iterações: " << resp.second << endl;
            break;

        case 3:
            resp = pegaso(a, b, iter, questao);
            cout << "Raiz: " << resp.first << " , ";
            cout << "Iterações: " << resp.second << endl;
            break;

        default:
            cout << "Método selecionado inválido!" << endl;
            break;
    }

    return 0;
}
