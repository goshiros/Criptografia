/* ************************************************************************** */
/* Nome: Giovana Oshiro da Silva                                              */
/* Numero USP: 8022103                                                        */
/* Exercício-programa 2                                                       */
/* ************************************************************************** */

/* O meu programa utiliza entrada de arquivo apenas em LETRAS MAIÚSCULAS */

#include <stdio.h>
#define MAX 5000

/* A função int chavespossiveis calcula o mdc entre n (tamanho da mensagem a ser
criptografada) e as possíveis chaves (números inteiros positivos menores ou iguais
a 300 tal que mdc (n, k) = 1). Se o mdc entre esses números for 1, a chave é colocada
em um vetor. A função retorna a quantidade de elementos do vetor, isto é, o número
de chaves possíveis. Como o vetor é um apontador por si só, todas as mudanças
feitas nele são levadas a main. */

int chavespossiveis (int n, int key [300]){
  int i = 1, k, c = 0, nlinha = 0, klinha = 0;

  /* A primeira casa do vetor com as chaves possíveis é sempre 1, pois o mdc
  entre 1 e qualquer número é 1. */

  key[0] = 1;

  /* 'k' representa os números que podem ser chaves; inicia no 2 pois 1 é sempre
  chave e já está alocada na primeira casa do vetor key [300] */

  for (k = 2; k <= 300; k++){
    nlinha = n;
    klinha = k;

    /* Para calcular o mdc entre dois números, utilizei o algoritmo gcd (greatest
    common divisor) já existente. Nele, dois números 'a' e 'b' quaisquer são
    parâmetros. Enquanto um deles, suponha 'a', for diferente de 0, uma variável
    'c' recebe o valor de 'a', 'a' recebe o resto da divisão de 'b' por 'a' e 'b'
    recebe o valor da variável 'c'. Ao sair do laço, isto é, quando 'a' = 0, 'b',
    que recebe 'c', é o máximo divisor comum. */

    while (klinha != 0){ /*algoritmo gcd*/
      c = klinha;
      klinha = nlinha % klinha;
      nlinha = c;
    }

    /* Ao sair do laço, nlinha é o mdc. Se nlinha = mdc (n, k) = 1, o k em questão
    entra no vetor key[300] */

    if (nlinha == 1){
      key [i] = k;
      i++;
      /* a variável 'i' foi inicializada por 1 porque se sabe, independetemente
      do tamanho da mensagem, o valor da primeira casa do vetor (key[0] = 1) */
    }

  } /* for (k = 2; k <= 300; k++) */

  /* key [i] é o vetor com o número de chaves possíveis; i é a quantidade de
  elementos do vetor */

  return i;

} /* int chavespossiveis (int n, int key [300]) */

/* A função comparadic compara uma palavra com o dicionário. Ela retorna se a
palavra está ou não no dicionário. Se estiver, ela retorna 1; caso contrário,
retorna 0.
A função será chamada na main para comparar as palavras do vetor plaintext (o
correto ou não; isto é, todas as possíveis chaves geram plaintexts, com as
palavras certas ou com as palavras desordenadas) com o dicionário. Caso todas as
palavras do plaintext (com uma das possíveis chaves) estejam no dicionário, essa
é a chave correta. */

int comparadic (char palavra [30], int tamanhodapalavra){

  /* A função recebe como parâmetro o vetor com a palavra a ser comparada com o
  dicionário e o tamanho dessa palavra */

  FILE * dicionario; /*declarar arquivo*/
  int leituradic, achei, i, tampaldic, j, ok;
  char caractere, palavradic [30];

  dicionario = fopen ("dicionario.txt", "r"); /* abrir arquivo */
  leituradic = 0;
  achei = 0;

  /* Enquanto a leitura do arquivo dicionário não tiver chegado ao fim e enquanto
  a palavra não constar no dicionário, a próxima palavra do dicionário é lida e
  comparada com palavra [30]. Ou seja, esse laço é desfeito se o arquivo chega
  ao fim ou se palavra [30] for encontrada no dicionário. */

  while (leituradic != EOF && !achei){

    leituradic = fscanf (dicionario, "%c", &caractere);

    for (i = 0; caractere != '\n' && leituradic != EOF; i++){
      palavradic [i] = caractere;
      leituradic = fscanf (dicionario, "%c", &caractere);
    }

    /* palavradic é o vetor que contém uma única palavra do dicionário */

    tampaldic = i; /* tampaldic = tamanho da palavra do dicionário */

    /* Se a palavra a ser comparada com o dicionário tiver o mesmo tamanho da
    palavra do dicionário, os seus caracteres serão comparados. No caso de todos
    os caracteres serem iguais, as palavras são iguais. Portanto, a palavra está
    no dicionário. */

    if (tamanhodapalavra == tampaldic){

      ok = 1;

      for (j = 0; j < i && ok; j++){
        if (palavra [j] != palavradic [j]) ok = 0;
      }
      /* Se o caractere for diferente conforme comparamos as palavras, não é
      necessário continuar a comparação com a mesma palavra do dicionário; por isso
      a flag 'ok'. Nesse caso, devemos comparar essa mesma palavra com a próxima
      palavra do dicionário, de forma que retornamos ao começo do while. */

      if (ok) achei = 1;
      /* Se a comparação passou pelo 'for' sem mudança de flag, significa que todos
      os caracteres das duas palavras comparadas são iguais. Logo, a palavra está
      no dicionário. Assim, a flag 'achei', que mantém o laço de leitura e comparação
      com o dicionário, muda de valor. */
    } /* if (tamanhodapalavra == tampaldic) */

  } /* while (leituradic != EOF && !achei) */

  fclose (dicionario); /* fechar o dicionário */
  /* como o arquivo é aberto e fechado toda vez que a função é chamada, não é
  necessário utilizar o comando rewind para retornar ao começo dele no caso de a
  função ser chamada novamente */

  return achei;
} /* int comparadic (char palavra[30], int tamanhodapalavra) */


int main (){

  /* declarar arquivo de entrada e de saída */
  FILE * entrada;
  FILE * saida;

  int i, j, n, leituraentrada, ciphercode [MAX], plaincode [MAX], k = 0, w = 0;

  int key [300], numchaves = 0, prox, tampal = 0, achei, chave;

  char alfabeto [28], caractere, ciphertext [MAX], plaintext [MAX], palavraplaintext [30];

  /* abrir arquivo de entrada e saída */
  entrada = fopen ("DECRYPT.IN", "r");

  saida = fopen ("DECRYPT.OUT", "w");

  /* criar vetor alfabeto */
  /* Como '_' e '.' não constam na tabela ASCII, eles são adicionados separadamente
  na primeira e última casa do vetor respectivamente, conforme enunciado do EP */

  alfabeto [0] = '_';
  alfabeto [27] = '.';

  for (i = 0; i < 26; i++){
    alfabeto [i+1] = 'A'+i;
  }

  /* ler a entrada e colocar no vetor de caractere ciphertext */

  leituraentrada = fscanf (entrada, "%c", &caractere);

  for (n = 0; caractere != '\n' && leituraentrada != EOF; n++){
    ciphertext [n] = caractere;
    leituraentrada = fscanf (entrada, "%c", &caractere);
  }
  ciphertext[n] = '\0';

  /* transformar vetor ciphertext em ciphercode (transformar as letras em números) */
  for (i = 0; i < n; i++){
    for (j = 0; j < 28; j++){
      if (ciphertext [i] == alfabeto [j])
        ciphercode [i] = j;
    }
  }

  /* A função chavespossiveis (n, key), que retorna o número de chaves e altera
  o vetor key [300] será chamada para que comecemos a testar as chaves. */

  numchaves = chavespossiveis (n, key);
  /* key[300] contém, agora, a quantidade "numchaves" de chaves e, nas casas do
  vetor, estão alocadas apenas as possíveis chaves */

  chave = 1;
  /* a flag "chave" recebe 1; ela só altera de valor quando a chave correta for
  encontrada */

  for (j = 0; j < numchaves && chave; j++){

    k = key [j];

    /* a variável k recebe a primeira chave possível */

    /* Agora, com a possível chave, iremos transformar o ciphercode em plaincode */

    for (i = 0; i < n; i++){

      /* A fórmula ciphercode[i]=(plaincode[(k*i)mod	n]-i)	mod	28, dada no enunciado
      do EP encripta um texto. Em discussões com colegas e pesquisas na internet,
      chegamos à seguinte fórmula inversa: plaincode [(k*i) % n] = (ciphercode [i] + i) % 28 */

      w = (k*i) % n;

      plaincode [w] = (ciphercode [i] + i) % 28;

      /* Obtém-se o plaincode através da fórmula acima. O plaincode é, então,
      convertido em plaintext */

      if (plaincode [w] == 0) plaintext [w] = '_';
      else if (plaincode [w] == 1) plaintext [w] = 'A';
      else if (plaincode [w] == 2) plaintext [w] = 'B';
      else if (plaincode [w] == 3) plaintext [w] = 'C';
      else if (plaincode [w] == 4) plaintext [w] = 'D';
      else if (plaincode [w] == 5) plaintext [w] = 'E';
      else if (plaincode [w] == 6) plaintext [w] = 'F';
      else if (plaincode [w] == 7) plaintext [w] = 'G';
      else if (plaincode [w] == 8) plaintext [w] = 'H';
      else if (plaincode [w] == 9) plaintext [w] = 'I';
      else if (plaincode [w] == 10) plaintext [w] = 'J';
      else if (plaincode [w] == 11) plaintext [w] = 'K';
      else if (plaincode [w] == 12) plaintext [w] = 'L';
      else if (plaincode [w] == 13) plaintext [w] = 'M';
      else if (plaincode [w] == 14) plaintext [w] = 'N';
      else if (plaincode [w] == 15) plaintext [w] = 'O';
      else if (plaincode [w] == 16) plaintext [w] = 'P';
      else if (plaincode [w] == 17) plaintext [w] = 'Q';
      else if (plaincode [w] == 18) plaintext [w] = 'R';
      else if (plaincode [w] == 19) plaintext [w] = 'S';
      else if (plaincode [w] == 20) plaintext [w] = 'T';
      else if (plaincode [w] == 21) plaintext [w] = 'U';
      else if (plaincode [w] == 22) plaintext [w] = 'V';
      else if (plaincode [w] == 23) plaintext [w] = 'W';
      else if (plaincode [w] == 24) plaintext [w] = 'X';
      else if (plaincode [w] == 25) plaintext [w] = 'Y';
      else if (plaincode [w] == 26) plaintext [w] = 'Z';
      else if (plaincode [w] == 27) plaintext [w] = '.';

    } /* for (i = 0; i < n; i++) */

    /* Agora o plaintext gerado através da chave k (key[j]) será analisado e cada
    palavra do vetor vai ser comparada com o dicionário. Se todas constarem no
    dicionário, a chave é a correta. */

    /* Como não é possível saber se a frase a ser decriptada termina com um ponto
    final, já que não há informações sobre isso no enunciado, e como não sabemos
    o que existe nas casas não utilizadas do vetor, inseri um '\0' ao final do
    vetor plaintext para saber que de fato chegou-se ao final da mensagem. */

    plaintext [n] = '\0';

    prox = 0;

    /* "prox" é uma variável criada para "apontar"/guardar a casa do vetor em que
    a próxima palavra do plaintext começa */

    achei = 1;

    /* "achei" é uma flag criada para saber se a palavra consta ou não no dicionário.
    Ela recebe a função comparadic, que retorna 1 caso a palavra esteja no dicionário
    e 0 caso não conste. */

    while (prox < n && achei){

      /* Esse laço mantém o plaintext gerado com a chave k sendo lido até que
      todas as "palavras" dele sejam comparadas com o dicionário. Se uma palavra
      do plaintext não constar no dicionário, não é necessário comparar as outras;
      a chave utilizada não é a correta. Por isso essas duas condições são colocadas:
      a comparação é feita até que o plaintext chegue ao final ou até alguma palavra
      do plaintext não estar no dicionário. */

      for (i = 0; plaintext [i + prox] != '_' && plaintext [i + prox] != '.' && plaintext [i + prox] != '\0'; i++){

        /* Enquanto a casa de plaintext for diferente de '_', '.' ou '\0', que
        representam ou o final de uma palavra ou o final da string, o vetor plaintext
        vai ser lido e colocado em um novo vetor; cada casa desse novo vetor
        receberá o valor correspondente de plaintext. Esse vetor é o
        palavraplaintext [30], que guarda uma única palavra de plaintext. */

        /* "i+prox" na primeira interação é igual à i, pois prox é inicializada
        com 0. Nas próximas interações, no entanto, uma ou mais palavras já terão
        sido lidas. Portanto, a posição não pode ser mais i apenas, pois devemos
        contar as casas que já foram lidas, isto é, as casas das palavras anteriores.
        Como prox guarda a casa do vetor em que a próxima palavra do plaintext
        começa, ela guarda também o número de casas que já foram lidas. */

        palavraplaintext [i] = plaintext [i + prox];

      } /* for (i = 0; plaintext [i + prox] != '_' && plaintext [i + prox] != '.' && plaintext [i + prox] != '\0'; i++) */

      prox = (i + 1) + prox;
      /* prox é atualizada */

      tampal = i;
      /* tampal é o tamanho da palavra */

      achei = comparadic (palavraplaintext, tampal);
      /* Aqui, a função comparadic é chamada. Ela vai comparar a palavra de
      plaintext sozinha com todas as palavras do dicionário */

      /* Se a função retornar 1, achei=1: a palavra está no dicionário e é preciso
      agora comparar as próximas palavras. Por isso, nesse caso, nada é feito e
      retorna-se ao while até que a próxima palavra não esteja no dicionário ou
      até que todo o plaintext seja lido */

      /* Se a função retornar 0, achei=0: a palavra não está no dicionário. Nesse
      caso, o programa sai do laço que leria a próxima palavra de plaintext.
      O contador "j" aumenta em uma unidade e a próxima chave é testada */

    } /* while (prox < n && achei) */

    /* Se o programa sai do while, duas coisas podem ter acontecido: ou o vetor
    plaintext terminou de ser lido ou a palavra não constou no dicionário.
    A flag "achei" é, então, conferida: se valer 1, significa que todas as palavras
    de plaintext constam no dicionário (é a chave certa!). Caso contrário, a próxima
    chave é testada. */

    if (achei){
      chave = 0;
    }

    /* Com a chave correta, o programa sai, então, do laço que testa as próximas
    chaves, de modo que a flag "chave" muda de valor. */

  } /* for (j = 0; j < numchaves && chave; j++) */

  /* Achada a chave correta, imprime-se no arquivo de saída o plaintext correto,
  com ciphertext decifrado */

  for (i = 0; i < n; i++){
    fprintf (saida, "%c", plaintext [i]);
  }
  fprintf (saida, "\n");

  /* Fechar arquivo de entrada e saída */
  fclose (entrada);
  fclose (saida);

  return 0;

} /* int main */
