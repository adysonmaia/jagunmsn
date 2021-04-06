#ifndef JAGUNPACKAGEINFORMATION_H
#define JAGUNPACKAGEINFORMATION_H

#include <QString>

/**
 * Classe responsavel por informar os tipos de pacotes de uma comunicacao
 */
class JagunPackageInformation
{
public:
    static QString getLiteralTypePackage(int etp);
    enum ETypePackage
    {
        ETPNewConnection         = 0, // tipo pedido de conexao
        ETPConnectionEstablished = 1, // tipo conexao estabelecida
        ETPData                  = 2, // tipo dado
        ETPConnectionClosed      = 3, // tipo conexao fechada
        ETPNewData               = 4, // tipo novo dado
        ETPEndData               = 5, // tipo fim de dado
        ETPConfirmationData      = 6  // tipo confirmacao de dado
    };
};

#endif // JAGUNPACKAGEINFORMATION_H
