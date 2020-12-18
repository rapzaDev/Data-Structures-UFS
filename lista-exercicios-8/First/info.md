### Objetivos:

- Criar o nó raiz da arvore e setar seus valores em NULL;
- Pegar os valores de entrada e somente sair do loop de scanf se o char == '\n'
- Se os valores forem '(' ou  ')' eles serao somados aos contadores cl ou cr. Se o valor for um numero eu adiciono este a minha arvore criada.
- Antes de adicionar, vou criar uma função para adicionar os elementos na arvore para ela se tornar uma arvore de busca binaria
- Se ao ler '\n' e cl != cr o programa tem que imprimir FALSO\n e encerrar a execução.
- Para verificar se é uma arvore binaria eu faço a validação na hora de cada inserção, ou seja, se ao inserir um novo valor e ele nao seguir as condições necessarias eu interrompo a execução, faço o print FALSO\n e encerro a execução do programa.  Se seguir toda a validação ate a ultima inserção, entao sera VERDADEIRO\n.