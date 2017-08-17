//Inclui as bibliotecas
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

//Funções dadas
#define f(x) (pow(x,2.0))
#define g(x) (pow(x,3.0)-(2*(pow(x,2.0)))+2)
#define h(yd,xd) (pow(1-xd,2.0)+(pow(1-yd,2.0)))
#define q(yd,xd) (pow(1-yd,2.0)+100*pow(xd-pow(yd,2),2))

//Derivadas das funções dadas
#define df(x) (2*x)
#define dg(x) (3*pow(x,2.0)-4*x)
#define dyh(yd,xd) (2*yd-2)
#define dxh(yd,xd) (2*xd-2)
#define dyq(yd,xd) (2*((-200)*xd*yd+200*(pow(yd,3.0)+yd-1)))
#define dxq(yd,xd) (200*(xd-pow(yd,2.0)))

//Preciso do pi para converter o valor do ângulo de radinos para graus
#define pi 3.14159

//Variaveis usadas
int funcao;
double x = 2;
double yd;
double xd;
double gradiente;
double angulo;
double beta = 0.1;
int iteracoes = 1e6;
int aux;

//Método de Newton-Raphson
void NewtonRaphsonf(double x, double precisao)
{
    int aux = 0;
    while((f(x) * f(x)) > (precisao*precisao) && (aux < iteracoes)) //Loop para criar a função iterativa
    {
        x = x - beta * (f(x) / df(x)); //Equação dada pelo método de Newton-Raphson
        aux++;
    }
    //imprime os resultados a cada iteração calculada
    cout << "Para taxa de aprendizado beta = " << beta << endl;
    cout << "A raiz aproximada é x = " << x << endl;
    cout << "E temos que f(" << x << ") = " << f(x) << endl;
    cout << "Número de iterações = " << aux << "\n" << endl;
}

void NewtonRaphsong(double x, double precisao)
{
    int aux = 0;
    while((g(x) * g(x)) > (precisao*precisao) && (aux < iteracoes))//Loop para criar a função iterativa
    {
        x = x - beta * (g(x) / dg(x));//Equação dada pelo método de Newton-Raphson
        aux++;

    }
    //imprime os resultados a cada iteração calculada
    cout << "Para taxa de aprendizado beta = " << beta << endl;
    cout << "A raiz aproximada é x = " << x <<  endl;
    cout << "E temos que g(" << x << ") = " << g(x) << endl;
    cout << "Número de iterações = " << aux << "\n" << endl;
}

//Descida de Gradiente
void DescidaGradientef(double x, double precisao)
{
    int aux = 0;
    while( (f(x) * f(x) > (precisao*precisao)) && (aux < iteracoes))//Loop para criara função iterativa
    {
        x = x - beta * (df(x));//Equação dada pelo método de Descida de Gradiente
        aux++;

    }
    //imprime os resultados a cada iteração calculada
    cout << "Para taxa de aprendizado beta = " << beta << endl;
    cout << "O ponto de minimo aproximado é x = " << x << endl;
    cout << "E temos que g(" << x << ") = " << f(x) << endl;
    cout << "Número de iterações = " << aux << "\n" << endl;
}

void DescidaGradienteg(double x, double precisao)
{
    int aux = 0;
    while((g(x) * g(x)) > (precisao*precisao) && (aux < iteracoes))//Loop para criar a função iterativa
    {
        x = x - beta * (dg(x));//Equação dada pelo método de Descida de Gradiente
        aux++;

    }
    //imprime os resultados a cada iteração calculada
    cout << "Para taxa de aprendizado beta = " << beta << endl;
    cout << "O ponto de minimo aproximado é x = " << x << endl;
    cout << "E temos que g(" << x << ") = " << g(x) << endl;
    cout << "Número de iterações = " << aux << "\n" << endl;
}

void DescidaGradienteh(double x, double precisao)
{
    int aux = 0;
    while((h(yd,xd) * h(yd,xd)) > (precisao*precisao) && (aux < iteracoes))//Loop para criar a função iterativa
    {
        xd = xd - beta * (dxh(yd,xd));//Equação dada pelo método de Descida de Gradiente
        yd = yd - beta * (dyh(yd,xd));//Equação dada pelo método de Descida de Gradiente
        gradiente = sqrt(pow(xd,2.0)+pow(yd,2.0)); //modulo
        angulo = atan(yd/xd) * 180 / pi; //fase
        aux++;

    }
    //imprime os resultados a cada iteração calculada
    cout << "Para taxa de aprendizado beta = " << beta << endl;
    cout << "O módulo é dado por = " << gradiente << endl;
    cout << "E temos que a fase é = " << angulo << endl;
    cout << "Número de iterações = " << aux << "\n" << endl;
}

void DescidaGradienteq(double x, double precisao)
{
    int aux = 0;
    while((q(yd,xd) * q(yd,xd)) > (precisao * precisao) && (aux < iteracoes))//Loop para criar a função iterativa
    {
        xd = xd - beta * (dxq(yd,xd));//Equação dada pelo método de Descida de Gradiente
        yd = yd - beta * (dyq(yd,xd));//Equação dada pelo método de Descida de Gradiente
        gradiente = sqrt(pow(xd,2.0)+pow(yd,2.0)); //modulo
        angulo = atan(yd/xd) * 180 / pi; //fase
        aux++;

    }
    //imprime os resultados a cada iteração calculada
    cout << "Para taxa de aprendizado beta = " << beta << endl;
    cout << "O módulo é dado por = " << gradiente << endl;
    cout << "E temos que a fase é = " << angulo << endl;
    cout << "Número de iterações = " << aux << "\n" << endl;
}

int main(int argc, char** argv)
{
    //Menu para escolha do que quer que seja calculado
    cout << "Exercício 1" << endl;
    cout << "Utilizando o Método de Newton-Raphson para encontrar as raizes das sequintes funções:" << endl;
    cout << "1) f(x) = x², com x inicial igual a 2" << endl;
    cout << "2) g(x) = x³-2x²+2, com x inicial igual a 2" << endl;
    cout << endl;
    cout << "Exercício 2" << endl;
    cout << "Utilizando o Método de Descida de Gradiente para encontrar o mínimo das sequintes funções:" << endl;
    cout << "3) f(x) = x², com x inicial igual a 2" << endl;
    cout << "4) g(x) = x³-2x²+2, com x inicial igual a 2" << endl;
    cout << "5) h(y,x) = (1-x)²+(1-y)²" << endl;
    cout << "6) q(y,x) = (1-y)²+100(x-y²)²" << endl;
    cout << endl;
    cout << "0) Para encerrar!" << endl;
    cout << endl;
    cout << "Digite sua opção: " << endl;
    cin >> funcao;
    cout << endl;


    switch (funcao)//criação das opçõs do menu
    {

    case 0:
        cout << "Tchau!" << endl;
        break;

    case 1:
        //Chama a função que quer calcular neste case
        while(beta <= 1)
        {
            NewtonRaphsonf(beta,1e-6);
            beta = beta + 0.1;
        }
        break;

    case 2:
        //Chama a função que quer calcular neste case
        while(beta <= 1)
        {
            NewtonRaphsong(beta,1e-6);
            beta = beta + 0.1;
        }
        break;

    case 3:
        //Chama a função que quer calcular neste case
        while(beta <= 1)
        {
            DescidaGradientef(beta,1e-6);
            beta = beta + 0.1;
        }
        break;

    case 4:
        //Chama a função que quer calcular neste case
        while(beta <= 1)
        {
            DescidaGradienteg(beta,1e-6);
            beta = beta + 0.1;
        }
        break;

    case 5:
        //Pede para inserir o valor para as variveis xd e yd usadas neste case
        cout << "Digite o valor do ponto inicial:" << endl;
        cout << "x = ";
        cin >> xd;
        cout << "y = ";
        cin >> yd;
        cout << endl;
        //Chama a função que quer calcular neste case
        while(beta <= 1)
        {
            DescidaGradienteh(beta,1e-6);
            beta = beta + 0.1;
        }
        break;

    case 6:
        //Pede para inserir o valor para as variveis xd e yd usadas neste case
        cout << "Digite o valor do ponto inicial:" << endl;
        cout << "x = ";
        cin >> xd;
        cout << "y = ";
        cin >> yd;
        cout << endl;
        //Chama a função que quer calcular neste case
        while(beta <= 1)
        {
            DescidaGradienteq(beta,1e-6);
            beta = beta + 0.1;
        }
        break;

    default: //Caso nenhuma dos cases seja escolhido
        cout << "Opção inválida!" << endl;
        break;
    }

    return 0;//encerra o programa
}
