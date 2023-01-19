import sq

l=[]
while True:
    print("\n>>> MENU DE OPCOES <<<\n\n> [1] Inserir Registro\n> [2] Deletar Registro\n> [3] Alterar Registro\n> [4] Exibir Registros\n> [5] Sair do programa")
    op=int(input("\nInsira o número da opcao desejada: "))
    if op==1:
        a = input("\nDigite seu CPF: ")
        b = int(input("Digite seu RG: "))
        c = input("Digite seu nome: ")
        d = int(input("Digite sua altura: "))
        e = int(input("Digite seu peso: "))
        l.extend([a,b,c,d,e])
        sq.c.execute(sq.add, l)
        sq.banco.commit()
        print("\nREGISTRO INSERIDO COM SUCESSO!!")
        break
    elif op==2:
        cpf=input("\nDigite o cpf do cliente que deseja excluir: ")
        sq.select_dados(cpf)
        op=input("\nDeseja realmente excluir esse registro? s = SIM, n = NAO\n ")
        if op=='s':
            sq.Excluir_registro(cpf)
            break
        else:
            print("\nFECHANDO O PROGRAMA!!")
            break
    elif op == 3:
        cpf = input("\nDigite o CPF do cliente que deseja alterar: ")
        sq.select_dados(cpf)

        peso = input("\nDigite o novo peso do cliente: ")
        sq.alterar_dados(peso, cpf)
        print("\nDado alterado com sucesso!!")
        break
    elif op==4:
        print("\nDigite o CPF do cliente que deseja exibir: ")
        cpf=input("\nCPF do cliente: ")
        sq.select_dados(cpf)
        break
    elif op==5:
        print("Saindo do programa!!")
        sq.banco.close()
        sq.c.close()
        break