#include "usuarios.h"

usuarios::usuarios(string _cc, string _clave, float _saldo)
{
    cc= _cc;
    clave= _clave;
    saldo= _saldo;
}

string usuarios::getCC()
{
    return cc;
}
string usuarios::getClave()
{
    return clave;
}

float usuarios::getSaldo()
{
    return saldo;
}

usuarios::~usuarios()
{
}
