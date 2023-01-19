import sqlite3

banco = sqlite3.connect('myserve.db')
c = banco.cursor()

def create_table():
    c.execute('CREATE TABLE IF NOT EXISTS cadastro (cpf TEXT primary key, rg integer(7), nome varchar(150), altura integer(3), peso integer(3))')

def Excluir_registro(cpf):
    c.execute('DELETE from cadastro WHERE cpf ='+cpf)
    banco.commit()
    print("\nREGISTRO EXCLUIDO COM SUCESSO!!")

def select_dados(cpf):
    c.execute('SELECT * FROM cadastro WHERE cpf ='+cpf)
    for linha in c.fetchall():
        print("\nCPF:",linha[0],"\nRG:",linha[1],"\nNOME:",linha[2],"\nALTURA:",linha[3],"cm","\nPESO:",linha[4],"kg")

def alterar_dados(peso,cpf):
    c.execute( """UPDATE cadastro SET peso =""" + peso + """ WHERE cpf = """ + cpf)
    banco.commit()

add = 'INSERT INTO cadastro VALUES (?,?,?,?,?)'

create_table()