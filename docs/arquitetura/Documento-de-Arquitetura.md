| **Data** | **Versão** | **Descrição** | **Autor(es)** |
| --- | --- | --- | --- |
| 22/03 | 0.1.0 | Criação do Documento | Mateus Augusto |
| 22/03 | 0.1.1 | Representação da Arquitetura | Mateus Augusto |
| 22/03 | 0.1.2 | Metas e Restrições da Arquitetura | Mateus Augusto |


## Sumário

1. [Introdução](https://github.com/fga-gpp-mds/2018.1-Cardinals/wiki/Documento-de-Arquitetura#1-introdu%C3%A7%C3%A3o)       
  1.1 [Finalidade]()            
  1.2 [Escopo]()
  1.3 [Visão Geral]()

2. [Representação da Arquitetura](https://github.com/fga-gpp-mds/2018.1-Cardinals/wiki/Documento-de-Arquitetura#2-representa%C3%A7%C3%A3o-da-arquitetura)

3. [Metas e Restrições de Arquitetura](https://github.com/fga-gpp-mds/2018.1-Cardinals/wiki/Documento-de-Arquitetura#3-metas-e-restri%C3%A7%C3%B5es-da-arquitetura)        
  3.1 [Ambiente e Ferramentas de Desenvolvimento](https://github.com/fga-gpp-mds/2018.1-Cardinals/wiki/Documento-de-Arquitetura#31-ambiente-e-ferramentas-de-desenvolvimento)
  3.2 [Segurança](https://github.com/fga-gpp-mds/2018.1-Cardinals/wiki/Documento-de-Arquitetura#32-seguran%C3%A7a)
  3.3 [Integração de Software Pronto](https://github.com/fga-gpp-mds/2018.1-Cardinals/wiki/Documento-de-Arquitetura#33-integra%C3%A7%C3%A3o-de-software-pronto)

4. [Visão Lógica](https://github.com/fga-gpp-mds/2018.1-Cardinals/wiki/Documento-de-Arquitetura#4-vis%C3%A3o-l%C3%B3gica)              
  4.1 [Visão Geral](https://github.com/fga-gpp-mds/2018.1-Cardinals/wiki/Documento-de-Arquitetura#41-vis%C3%A3o-geral)                 
  4.2 [Pacotes de Design Significativos do Ponto de Vista da Arquitetura](https://github.com/fga-gpp-mds/2018.1-Cardinals/wiki/Documento-de-Arquitetura#42-pacotes-de-design-significativos-do-ponto-de-vista-da-arquitetura)

5. [Visão de Processos](https://github.com/fga-gpp-mds/2018.1-Cardinals/wiki/Documento-de-Arquitetura#5-vis%C3%A3o-de-processos)

6. [Visão de Implantação](https://github.com/fga-gpp-mds/2018.1-Cardinals/wiki/Documento-de-Arquitetura#6-vis%C3%A3o-de-implanta%C3%A7%C3%A3o)

7. [Visão de Implementação](https://github.com/fga-gpp-mds/2018.1-Cardinals/wiki/Documento-de-Arquitetura#7-vis%C3%A3o-da-implementa%C3%A7%C3%A3o)         
  7.1 [Visão Geral]()           
  7.2 [Camadas]()              
    7.2.1 [Model]()           
    7.2.2 [View]()             
    7.2.3 [Template]()             

8. [Tamanho e Desempenho]()                            

9. [Qualidade]()                    

10. [Referências]()                   


# 1. Introdução
## 1.1 Finalidade.  
<p align ="justify"></p>

## 1.2 Escopo     
<p align="justify"></p>


## 1.3 Visão Geral
<p align="justify"></p>

# 2. Representação da Arquitetura
<p align="justify">Nosso projeto utilizará a arquitetura MTV (model, template, view), que trata-se de um padrão de arquitetura de software baseada na MVC mas adaptada pela framework Django. Ela separa a aplicação em 3 camadas tal como a tradicional MVC. A camada Model que manipula dos dados, a Template, onde há a interação com o usuário e a View, onde ficam as ações e trata as requisições do usuário</p>
<img src="https://raw.githubusercontent.com/wiki/fga-gpp-mds/2018.1-Cardinals/imagens/esquema-mtv.jpeg" alt="MTV">
<p>Figura 1</p>
<p>Fonte: https://pt.slideshare.net/CursosDevcode/fundamentos-dj-45913014</p>



# 3. Metas e Restrições da Arquitetura
## 3.1 Ambiente e Ferramentas de Desenvolvimento
<p align="justify">O sistema será desenvolvido para funcionar em todos os navegadores web e terá comportamento responsivo, portanto adaptando-se adequadamente a navegadores desktop e mobile.
Utilizaremos o modelo MTV como padrão arquitetural de nosso sistema e
todos os recursos do sistema deverão estar disponíveis em Português(Brasil). 
A aplicação será acessada por conexão de internet de qualquer computador ou mobile com acesso a mesma.
As ferramentas de desenvolvimento serão:</p>

+ Linguagem Python em sua última versão oficial 3.6.2;
+ Framework Django em sua última versão oficial 1.11.4.

## 3.2 Segurança
<p align="justify"></p>

+ 
+ 

## 3.3 Integração de Software Pronto
<p align="justify"> </p>
<p align="justify"></p>

# 4. Visão Lógica
## 4.1 Visão Geral
<p align="justify"> Design Responsivo é uma técnica de estruturação HTML e CSS, em que o site se adapta ao browser do usuário sem precisar definir diversas folhas de estilos para cada resolução.
Na arquitetura MTV, os dados serão lidos, escritos e validados na camada Model. Tudo que diz respeito aos dados serão tratados aqui. Por exemplo a validação dos dados de login do usuário será feita na Model. A camada Template, é a camada responsável por “comunicar-se com o usuário”. É onde as funcionalidades são mostradas na tela, usualmente é feita em XML ou HTML. E o por fim, a View que é responsável por receber todas as requisições do usuário. Seus métodos chamados actions são responsáveis por uma página, controlando qual model usar e qual template será mostrado ao usuário.</p>

<img src="https://raw.githubusercontent.com/wiki/fga-gpp-mds/2018.1-Cardinals/imagens/django-mtv.jpeg" alt="Django framework">
<p>Figura 2 </p>
<p>Fonte: https://pt.slideshare.net/AnushaChickermane/saasy-maps </p>



## 4.2 Pacotes de Design Significativos do Ponto de Vista da Arquitetura
![diagrama de classes]()

# 5. Visão de Processos
<p align="justify"></p>

# 6. Visão de Implantação
<p align="justify"></p>

# 7. Visão da Implementação.         

## 7.1 Visão Geral.       
<p align="justify"></p>

## 7.2 Camadas

### 7.2.1 Model

<p align="justify"></p>

### 7.2.2 View

<p align="justify"></p>

### 7.2.3 Template

<p align="justify"></p>

# 8. Tamanho e Desempenho
<p align="justify"></p>
<p align="justify"></p>

# 9. Qualidade

<p align="justify"></p>

# 10. Referências


