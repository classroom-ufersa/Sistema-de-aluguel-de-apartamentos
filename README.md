# Sistema de Aluguel de Apartamentos

Este projeto consiste em um sistema de aluguel de apartamentos desenvolvido em linguagem C. O objetivo do sistema é facilitar a gestão de informações sobre apartamentos e inquilinos, oferecendo funcionalidades como adicionar inquilinos, excluir inquilinos, listar inquilinos, buscar inquilinos, editar informações de inquilinos, consultar apartamentos disponíveis, consultar o quantitativo de inquilinos e sair do sistema.

# Conceitos Utilizados:

O sistema foi implementado utilizando diversos conceitos da linguagem C, como ponteiros, alocação dinâmica de memória e structs. Além disso, foi adotada a estrutura de dados de listas encadeadas simples para armazenar as informações dos inquilinos.

# Estrutura de Dados:

## A estrutura "Apartamento" possui os seguintes campos:

Número do apartamento,
Disponibilidade do apartamento (indicando se está alugado ou vago),
Valor do aluguel,
Localização,
Inquilino associado ao apartamento (caso esteja alugado).

## A estrutura "Inquilino" é composta pelos seguintes campos:

Nome,
RG,
CPF,
Data de entrada ou início do contrato,
Data de saída ou fim do contrato,
Número do apartamento alugado.

# Funcionalidades do Sistema:

## O sistema oferece as seguintes funcionalidades:

Adicionar Inquilino: Permite cadastrar as informações de um novo inquilino e associá-lo a um apartamento disponível.

Excluir Inquilino: Remove um inquilino do sistema, liberando o apartamento associado.

Listar Inquilinos: Apresenta ao usuário a lista de todos os inquilinos cadastrados, exibindo suas informações.

Buscar Inquilinos: Permite buscar um inquilino pelo nome, exibindo suas informações caso seja encontrado.

Editar Inquilinos: Permite editar as informações de um inquilino específico, como nome, RG, CPF, datas de entrada/saída e número do apartamento.

Consultar Apartamentos Disponíveis: Mostra ao usuário a lista de apartamentos que estão atualmente desocupados e disponíveis para aluguel.

Consultar Quantitativo de Inquilinos: Exibe o número total de inquilinos cadastrados no sistema.

Sair: Encerra a execução do programa.

# Tecnologias Utilizadas:

O projeto foi desenvolvido em linguagem C, utilizando os seguintes conceitos e recursos:

Ponteiros: Foram utilizados ponteiros para manipulação de variáveis e acesso aos elementos das listas encadeadas.

Alocação Dinâmica: A alocação dinâmica de memória foi empregada para criar e gerenciar as estruturas de dados, permitindo a flexibilidade no armazenamento das informações dos inquilinos.

Structs: As structs foram utilizadas para criar os tipos de dados personalizados, como "Apartamento" e "Inquilino", para armazenar as informações relacionadas a cada entidade.

Arquivos: Os dados dos inquilinos e apartamentos são armazenados em arquivos, permitindo a persistência das informações mesmo após a execução do programa.

Listas Encadeadas Simples: As listas encadeadas foram empregadas para gerenciar os inquilinos e permitir a manipulação eficiente dos dados, como adicionar, excluir e buscar inquilinos.

# Uso de Listas Encadeadas Simples:

No sistema de aluguel de apartamentos, optou-se por utilizar listas encadeadas simples para armazenar os dados dos inquilinos. Essa escolha se deu pelas seguintes razões:

Inserção e Remoção Eficientes: As listas encadeadas simples permitem a inserção e remoção eficientes de elementos, mesmo no meio da lista, sem a necessidade de realocação de memória. Isso é particularmente útil quando lidamos com um grande número de inquilinos e suas respectivas informações, garantindo um desempenho adequado no sistema.

Flexibilidade: Com as listas encadeadas simples, é possível adicionar ou remover inquilinos de forma dinâmica, adaptando-se às mudanças no sistema de aluguel de apartamentos sem restrições rígidas de tamanho fixo.

Busca por Nome: A estrutura de listas encadeadas permite a busca eficiente de inquilinos pelo nome, percorrendo os elementos sequencialmente até encontrar o nome desejado.

# Por que não utilizar Pilhas e Filas?

Embora pilhas e filas sejam estruturas de dados úteis em muitos cenários, para este sistema de aluguel de apartamentos, as listas encadeadas simples foram escolhidas devido à necessidade de realizar operações de busca eficiente por nome e manipulação flexível dos inquilinos. Pilhas e filas não seriam tão adequadas nesse contexto, pois não oferecem a mesma facilidade de acesso aleatório aos elementos.

# Como Contribuir:

Se você deseja contribuir para o projeto, siga as etapas abaixo:

1 - Clone o repositório em sua máquina local.

2 - Implemente as melhorias ou correções desejadas no código.

3 - Teste as alterações para garantir seu correto funcionamento.

4 - Envie um pull request para que suas contribuições sejam analisadas e incorporadas ao projeto.

5 - Sua contribuição é muito bem-vinda!

### Observação: Este sistema de aluguel de apartamentos foi desenvolvido com finalidades educacionais e não representa um sistema de produção completo.
