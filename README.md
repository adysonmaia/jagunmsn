# JagunMsn

JagunMsn é um cliente de mensagens instantâneas desenvolvido como trabalho para a cadeira de Redes de Computadores (CK061) ministrada pelo prof Miguel

Jagun Msn usa  o paradigma Cliente/Servidor, ele pode ser divido em 3 partes:
-	JagunMSNClient
-	JagunMSNServer
-	JagunKet

O Cliente e o Servidor se comunicam atraves do JagunKet, que é baseado em Sockets UDP, só que ao contraio do UDP o JagunKet garante a confiablidade.
