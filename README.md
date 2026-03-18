# OpenMP_Parallel_CM

Programa em C++ que calcula uma aproximação de PI usando a regra do ponto médio (integração numérica) paralelizada com OpenMP.

Descrição
- Exemplo simples e didático que demonstra como paralelizar um laço (for) com OpenMP.
- O programa integra a função f(x) = 4 / (1 + x^2) no intervalo [0,1] usando n intervalos e retorna uma aproximação de PI.
- Projeto escrito 100% em C++.

Estrutura do repositório
- src/main.cpp — código-fonte principal (implementação OpenMP).
- bin/ — pasta para binários (não comitada).
- build/ — pasta para arquivos de build (não comitada).
- resources/ — recursos (se aplicável).
- Makefile.win — arquivo de build/compilação destinado ao Windows.
- DeltaX.dev — arquivo de configuração/auxiliar (presente no repositório).

Pré-requisitos
- Compilador C++ com suporte a OpenMP:
  - Linux / macOS: g++ (com suporte -fopenmp) ou clang++ (no macOS configure libomp).
  - Windows: MinGW-w64 (g++) ou MSVC (cl, com /openmp).
- Make (opcional) ou outro sistema de build.
- Variável de ambiente recomendada para controlar threads: OMP_NUM_THREADS (ex.: export OMP_NUM_THREADS=4).

Compilação (exemplos)

1) Compilar:
   g++ -fopenmp src/main.cpp -O2 -o bin/pi

Windows (MinGW-w64)
1) Criar diretório para binários (opcional):
   mkdir bin

2) Compilar:
   g++ -fopenmp src/main.cpp -O2 -o bin\pi.exe

Windows (MSVC)
- Compile com:
  cl /openmp /O2 src\main.cpp

Observação sobre Makefile.win
- Existe um arquivo Makefile.win no repositório. Se preferir usar esse arquivo, confira seu conteúdo e use a ferramenta de build apropriada (mingw32-make, nmake, etc.), conforme sua plataforma.

Uso
1) Execute o programa gerado:
   ./bin/pi    (Linux/macOS)
   bin\pi.exe  (Windows)

2) O programa pedirá:
   Digite o numero de intervalos:

3) Informe um valor inteiro grande (ex.: 100000000) para obter uma aproximação mais precisa de PI. Exemplo:
   Digite o numero de intervalos: 10000000
   O valor de PI é 3.14159...

Observações sobre precisão e performance
- A precisão aumenta com o número de intervalos (n), mas o tempo de execução também.
- Defina OMP_NUM_THREADS para controlar o número de threads:
  export OMP_NUM_THREADS=4
- O código atual usa uma variável local por thread (soma_local) e uma região crítica para acumular o total global. Isso funciona, mas a diretiva OpenMP reduction é mais eficiente e evita a seção crítica.

Sugestões de melhoria
- Substituir a seção crítica por uma diretiva de redução:
  #pragma omp parallel for reduction(+:soma)
- Medir tempos de execução (ex.: omp_get_wtime()) para comparar escalabilidade com diferentes números de threads.
- Tratar entradas inválidas (n <= 0).
- Adicionar testes automatizados e integração contínua (CI) para builds em Linux/Windows.
- Tornar a saída mais completa (tempo, número de threads, erro relativo em relação a M_PI).
- Fornecer um Makefile/CMakelists para builds multiplataforma.

Explicação rápida do algoritmo
- Método: Regra do ponto médio.
- Para cada subintervalo i = 0..n-1, calcula-se x = (i + 0.5) * deltax e soma-se f(x).
- Soma total multiplicada por deltax aproxima a integral de f(x) em [0,1], equivalente a PI.

Exemplo de saída esperada
- Entrada: 10000000
- Saída:
  Digite o numero de intervalos: 10000000
  O valor de PI é 3.14159...

Contribuições
- Sinta-se à vontade para abrir issues ou pull requests com melhorias (ex.: troca para reduction, adição de CMake, benchmarks, testes).

Autor
- ClaudioMatheusDev
