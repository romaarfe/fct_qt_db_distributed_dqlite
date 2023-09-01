<h3 align="center"> 
  🚧 TESTE DE BASE DE DADOS DISTRIBUÍDA (DQLITE) 🚧
</h3>

---
#### ⚙️ ETAPAS / FUNCIONALIDADES:

- [x] Criação de nova base de dados no QT utilizando o driver/plugin (QSQLCIPHER)
- [x] Promover encriptação através do SQLCipher (no driver)
- [x] Permitir que este driver, QSQLCipher, trabalhe tanto com SQLite quanto com SQLCipher
- [x] Implementação do código associado
- [x] Testes da funcionalidades através da apresentação de seu conteúdo
- [ ] Criação do server/cluster para iniciar a distribuição
- [ ] Criação do primeiro nó (leader) por linha de comando e associação por código
- [ ] Criar novos nós (inicialmente 3) e distribuir de fato a base de dados
- [x] Primeiro teste por terminal (alguns comandos não funcionam)
- [ ] Realizar novos testes por terminal

---
#### ⚠️ NOTAS IMPORTANTES:

- O **.setPasword()** do próprio QT (QSqlDatabase) ainda trabalha com SQLite, que por sua vez não concebe uso de senhas
- Para encriptação utilizar um **.exec()** e **"PRAGMA key = 'sua_senha_aqui';"**

---
#### 🔧 FERRAMENTAS / TECNOLOGIAS:

- C
- C++
- CMake
- QT Framework
- QT Creator
- SQLite (QSQLITE)
- SQLCipher (QSQLCIPHER)
- DQLite

---
##### 👨‍💻 Desenvolvido na SDILAB - Research & Software Development 
##### ⚖️ Balanças Marques - Grupo José Pimenta Marques
##### 📖 Projeto para Formação em Contexto de Trabalho - IEFP
