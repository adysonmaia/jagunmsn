#ifndef JAGUNPARSERMESSAGEINFORMATION_H
#define JAGUNPARSERMESSAGEINFORMATION_H

class JagunParserMessageInformation
{
public:
    JagunParserMessageInformation();
    enum ETypeMessage
    {
        ETPNewUser                = 0,  // mensagem para criar novo usuario
        ETPUserCreated            = 1,  // mensagem de usuario cadastrado
        ETPError                  = 2,  // mensagem de erro
        ETPLoginUser              = 3,  // mensagem logar usuario
        ETPLogOn                  = 4,  // mensagem usuario logado
        ETPAddContact             = 5,  // mensagem de adicionar contato
        ETPRequestAddContact      = 6,  // mensagem de pedido para adicionar contato
        ETPAddContactConfirmation = 7,  // mensagem de resposta ao pedido de adicionar contato
        ETPRequestContactList     = 8,  // mensagem de requisicao da lista de contatos
        ETPApprovedAddContact     = 9,  // mensagem de adicionar contato aceito
        ETPContactList            = 10,  // mensagem lista de contatos
        ETPRemoveContact          = 11, // mensagem remover contato
        ETPBlockOrUnblock         = 12, // mensagem bloquear ou desbloquear contato
        ETPChangeStatus           = 13, // mensagem mudanca de status do usuario
        ETPGetStatusContact       = 14, // mensagem requisitar status de um contato
        ETPChangeStatusContact    = 15, // mensagem mudança no status do cantato
        ETPKeepAlive              = 16, // mensagem keep alive
        ETPSendMessage            = 17, // mensagem enviar mensagem
        ETPReceiveMessage         = 18, // mensagem receber mensagem
    };

    enum EErrorCode
    {
        EECNewUser         = 0, // erro no cadastro do usuario
        EECLoginUser       = 1, // erro ao logar usuario
        EECAddContact      = 2  // erro ao adicionar contato
    };
};

#endif // JAGUNPARSERMESSAGEINFORMATION_H
