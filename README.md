# Avaliação Comparativa de Algoritmos de Ordenação
## Especificações
### Metricas de Avaliação dos Algoritimos
- Comparações
- Movimentações
- Chamadas de função

### Estratégia
- Avaliação baseada em contadores
- Instrumentação explícita
    - Avaliação não considera tempo
- Plano de experimentos
    - Algoritmo
    - Tamanho do vetor a ser ordenado
    - Semente aleatória
### Algoritimos
- Seleção
    - Iterativo
    - Recursivo
- Inserção
- QuickSort
    - Padrão
    - Mediana de 3
    - Inserção para partições pequenas (p.ex., 50)
    - Mediana de 3 e Inserção
- Shellsort
    - Utilizando sequência n/2i


## Testes Locais
testar localmente, os casos de teste utilizados nesta PA são:

./pa1.out -z 9 -s 27 -a s

./pa1.out -z 9 -s 27 -a i

./pa1.out -z 9 -s 27 -a q

./pa1.out -z 9 -s 27 -a q3

./pa1.out -z 9 -s 27 -a qi

./pa1.out -z 9 -s 27 -a q3i

./pa1.out -z 9 -s 27 -a h

./pa1.out -z 9 -s 27 -a rs

./pa1.out -z 81 -s 17 -a s

./pa1.out -z 81 -s 17 -a i

./pa1.out -z 81 -s 17 -a q

./pa1.out -z 81 -s 17 -a q3

./pa1.out -z 81 -s 17 -a qi

./pa1.out -z 81 -s 17 -a q3i

./pa1.out -z 81 -s 17 -a h

./pa1.out -z 81 -s 17 -a rs

./pa1.out -z 448 -s 15 -a s

./pa1.out -z 448 -s 15 -a i

./pa1.out -z 448 -s 15 -a q

./pa1.out -z 448 -s 15 -a q3

./pa1.out -z 448 -s 15 -a qi

./pa1.out -z 448 -s 15 -a q3i

./pa1.out -z 448 -s 15 -a h

./pa1.out -z 448 -s 15 -a rs

./pa1.out -z 4803 -s 34 -a s

./pa1.out -z 4803 -s 34 -a i

./pa1.out -z 4803 -s 34 -a q

./pa1.out -z 4803 -s 34 -a q3

./pa1.out -z 4803 -s 34 -a qi

./pa1.out -z 4803 -s 34 -a q3i

./pa1.out -z 4803 -s 34 -a h

./pa1.out -z 4803 -s 34 -a rs

./pa1.out -z 19097 -s 25 -a s

./pa1.out -z 19097 -s 25 -a i

./pa1.out -z 19097 -s 25 -a q

./pa1.out -z 19097 -s 25 -a q3

./pa1.out -z 19097 -s 25 -a qi

./pa1.out -z 19097 -s 25 -a q3i

./pa1.out -z 19097 -s 25 -a h

./pa1.out -z 19097 -s 25 -a rs