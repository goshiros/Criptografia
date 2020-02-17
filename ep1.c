/* ************************************************************************** */
/* Nome: Giovana Oshiro da Silva */
/* Numero USP: 8022103 */
/* Exercício-programa 1 */
/* ************************************************************************** */

#include <stdio.h>

/* função número aleatório */
int numAleatorio (int xn, long int m){
	long int a = 22695477;
	int b = 1;
	xn = (a * xn + b) % m;
	return xn;
}

/*função que normaliza o número aleatório, colocando-o entre 0 e 1*/
float zeroum (int xn, long int m){
	float num;
	num = ((float)xn)/m;
	return num;
}

/* função para descobrir qual número, dentre 3, é o maior, a ser usada no nível 2 */
int maiorNum (int x, int y, int z){
	int maior;
	if (x > y) maior = x;
	else maior = y;
	if (maior < z) maior = z;
	return maior;
}

/*função para imprimir o resultado final*/
void printResultado (int vitoria, int derrota, int empate){
  printf ("Você venceu %d vezes. A porcentagem de vitórias foi %f%%.\n", vitoria, ((float)vitoria/(vitoria+derrota+empate))*100);
  printf ("Você perdeu %d vezes. A porcentagem de derrotas foi %f%%.\n", derrota, ((float)derrota/(vitoria+derrota+empate))*100);
  printf ("Você empatou %d vezes. A porcentagem de empates foi %f%%.\n", empate, ((float)empate/(vitoria+derrota+empate))*100);
  if (vitoria > derrota) printf ("Você foi o vencedor. Parabéns!\n");
  else if (vitoria == derrota) printf ("Você empatou!\n");
  else if (vitoria < derrota) printf ("Você perdeu! Tente novamente.\n");
}

int main (){

	int nivel, jogada, fimdenivel = 0, vitoria = 0, empate = 0, derrota = 0, xn = 0, fimdejogo = 0, option = 0;
	int i, jogAnterior = 0, Pe_Pe = 0, Pe_Te = 0, Pe_Pa = 0, Te_Pe = 0, Te_Te = 0;
	int Te_Pa = 0, Pa_Pe = 0, Pa_Te = 0, Pa_Pa = 0, jogcpu = 0, maior = 0, jogcpuAnt = 0;
	int cpuPe_pesPe = 0, cpuTe_pesPe = 0, cpuPa_pesPe = 0, cpuPe_pesTe = 0, cpuTe_pesTe = 0, cpuPa_pesTe = 0, cpuPe_pesPa = 0, cpuTe_pesPa = 0, cpuPa_pesPa = 0;
	long int m = 1073741824;
	float jogcpuA;

	/* A variável fimdejogo muda para 1 quando a pessoa termina o nível e não deseja mais joagr novamente */
  while (fimdejogo == 0){
    fimdenivel = 0, vitoria = 0, empate = 0, derrota = 0; /* As variáveis fimdenivel, vitoria, empate e derrota recebem 0 toda vez que saem de um nível */
  	printf ("Escolha o nível de dificuldade do jogo. Digite 1 para fácil, 2 para médio, 3 para difícil1 ou 4 para difícil2. Caso queira parar o jogo, digite 0.\n");
  	scanf ("%d", &nivel);
  	printf ("\n"); /*pular linha*/

  	if (nivel == 1){
  		printf ("MODO FÁCIL\n\n");
  		printf ("Entre com uma semente:\n");
  		scanf ("%d", &xn);

  		while (fimdenivel == 0){
  			xn = numAleatorio(xn,m); /* xn recebe a função que gera o número aleatório */
  			jogcpuA = zeroum(xn,m); /* jogcpuA, a jogada do computador de acordo com o número aleatório gerado, recebe a função zeroum, que transforma xn em um número entre 0 e 1 */
  			printf ("\nDigite 1 para pedra, 2 para tesoura ou 3 para papel:\n");
  			scanf ("%d", &jogada);

				/* o comando 0 indica que o ser humano quer parar o nível */
  			if (jogada==0) fimdenivel=1;

  			else{
  				if (jogcpuA >= 0.0 && jogcpuA < 1.0/3){ /* conforme enunciado do EP */
  					printf ("Jogada do computador: pedra\n"); /* jogcpu = 1 */
  					if (jogada ==3 ){ /* papel=3 vence de pedra */
  						printf ("Você venceu!\n\n");
  						vitoria++; /* a variável vitória recebe mais um a cada vitória */
  					}
  					else if (jogada == 1){ /* pedra=1 empata com pedra=1 */
  						printf ("Empate\n\n");
  						empate++; /* a variável empate recebe mais um a cada empate */
  					}
  					else{  /* if (jogada==2) */
  						printf ("Você perdeu!\n\n"); /* tesoura=2 perde de pedra=1 */
  						derrota++;
  					}
  				}

  				if (jogcpuA >= 1.0/3 && jogcpuA < 2.0/3){
  					printf ("Jogada do computador: tesoura\n");
  					if (jogada == 1){
  						printf ("Você venceu!\n\n");
  						vitoria++;
  					}
  					else if (jogada == 3){
  						printf ("Você perdeu!\n\n");
  						derrota++;
  					}
  					else{ /*if (jogada==2)*/
  						printf ("Empate\n\n");
  						empate++;
  					}
  				}

  				if (jogcpuA >= 2.0/3 && jogcpuA < 1.0){
  					printf ("Jogada do computador: papel\n");
  					if (jogada == 2){
  						printf ("Você venceu!\n\n");
  						vitoria++;
  					}
  					else if (jogada == 1){
  						printf ("Você perdeu!\n\n");
  						derrota++;
  					}
  					else{ /* if (jogada==3) */
  						printf ("Empate\n\n");
  						empate++;
  					}
  				}
  			} /* else */
  		} /* while (fim==0) */
      printf ("\n");
			printResultado(vitoria, derrota, empate); /* imprimir resultado do nível */
			printf ("\n");
			printf ("Deseja jogar novamente? Digite 1 para sim ou 2 para não.\n");
			scanf ("%d", &option);
				if (option == 2) fimdejogo = 1; /* fimdejogo=1 sai do while que engloba o programa todo */
			printf ("\n");
  	} /* if (nivel==1) */

  	if (nivel == 2){
  		printf ("MODO MÉDIO\n\n");
  		printf ("Entre com uma semente:\n");
  		scanf ("%d", &xn);
  		printf ("\nDigite 1 para pedra, 2 para tesoura ou 3 para papel:\n");
  		scanf ("%d", &jogada);

			/* A primeira jogada vai ser guardada separadamente em uma variável jogada anterior, para que possa servir de comparação nas próximas rodadas */
			for (i = 0; i < 1 && fimdenivel == 0; i++){
				if (jogada == 0) fimdenivel = 1;
				else{
					/*A primeira jogada do computador não vai ser aleatória. Escolhi papel
					porque, a partir de pesquisas, constatei que as pessoas jogam mais vezes
					o comando pedra, por parecer ser mais forte e por ser mais fácil de ser
					jogado com as mãos.*/
					printf ("Jogada do computador: papel\n");
					if (jogada == 1){ /*jogada é a jogada atual do ser humano*/
						printf ("Você perdeu!\n\n");
						derrota++;
					}
					if (jogada == 2){
						printf ("Você venceu!\n\n");
						vitoria++;
					}
					if (jogada == 3){
						printf ("Empate!\n\n");
						empate++;
					}
				} /* else */
				jogAnterior = jogada; /* jogada anterior recebe jogada atual */
			} /* for (i = 0; i < 1 && fimdenivel == 0, i++) */

			/* As próximas 4 jogadas serão aleatórias para analisar o padrão do ser humano nas primeiras rodadas */
  		for (i = 1; i < 5 && fimdenivel == 0; i++){
  			printf ("\nDigite 1 para pedra, 2 para tesoura ou 3 para papel:\n");
  			scanf ("%d", &jogada);
  			xn = numAleatorio(xn, m); /* função que gera o número aleatório */
  			jogcpuA = zeroum(xn, m); /* função normaliza o número aleatório */

  			if (jogada == 0) fimdenivel = 1; /* comando 0 para o jogo */

  			else{ /* if (jogada!=0) */
  				if (jogcpuA >= 0.0 && jogcpuA < 1.0/3){
  					printf ("Jogada do computador: pedra\n");
  					if (jogada == 3){
  						printf ("Você venceu!\n\n");
  						vitoria++;
  					}
  					else if (jogada == 1){
  						printf ("Empate\n\n");
  						empate++;
  					}
  					else if (jogada == 2){
  						printf ("Você perdeu!\n\n");
  						derrota++;
  					}
  				}

  				if (jogcpuA >= 1.0/3 && jogcpuA < 2.0/3){
  					printf ("Jogada do computador: tesoura\n");
  					if (jogada == 1){
  						printf ("Você venceu!\n\n");
  						vitoria++;
  					}
  					else if (jogada == 3){
  						printf ("Você perdeu!\n\n");
  						derrota++;
  					}
  					else if (jogada == 2){
  						printf ("Empate\n\n");
  						empate++;
  					}
  				}

  				if (jogcpuA >= 2.0/3 && jogcpuA < 1.0){
  					printf ("Jogada do computador: papel\n");
  					if (jogada == 2){
  						printf ("Você venceu!\n\n");
  						vitoria++;
  					}
  					else if (jogada == 1){
  						printf ("Você perdeu!\n\n");
  						derrota++;
  					}
  					else if (jogada == 3){
  						printf ("Empate\n\n");
  						empate++;
  					}
  				}
  			} /* else */

  			/* Agora, a jogada do ser humano será armazenada em uma variável e comparada com a jogada anterior */
  			if (jogada == 1){ /* Se a jogada atual for pedra, analisar a jogada anterior e ver o que o ser humano jogou */
  				if (jogAnterior == 1) Pe_Pe++; /* Se a jogada anterior do ser humano também for pedra, guardar na variável Pe_Pe, que indica que, antes do comando pedra, o ser humano jogou pedra */
  				else if (jogAnterior == 2) Te_Pe++; /* Se a jogada anterior for tesoura, guardar na variável Te_Pe, que indica que, antes do comando pedra, o ser humano jogou tesoura */
  				else Pa_Pe++; /* if(jogAnterior == 3) */ /* Se a jogada anterior for papel, guardar na variável Pa_Pe, que indica que, antes do comando pedra, o ser humano jogou papel */
  			}
  			else if (jogada == 2){ /* Esse comando de guardar a jogada em relação à jogada anterior é repetido nos casos jogada=2 (tesoura) e jogada=3 (pedra) */
  				if (jogAnterior == 1) Pe_Te++;
  				else if (jogAnterior == 2) Te_Te++;
  				else Pa_Te++;
  			}
  			else if (jogada == 3){
  				if (jogAnterior == 1) Pe_Pa++;
  				else if (jogAnterior == 2) Te_Pa++;
  				else Pa_Pa++;
  			} /* Essas variáveis que indicam o que o ser humano jogou antes da jogada atual são atualizadas a cada rodada, de forma que é possível obter um padrão */
  			jogAnterior=jogada; /* A variável jogada anterior recebe o valor da jogada atual a cada rodada */
  		} /* for (i = 0; i < 4 && fim == 0; i++) */

  		/* Agora vamos analisar as próximas jogadas, isto é, quando i>=5 */
  		while (fimdenivel == 0){ /* Tudo o que está abaixo será repetido até que o usuário deseje terminar o jogo */
				printf ("\nDigite 1 para pedra, 2 para tesoura ou 3 para papel:\n");
				scanf ("%d", &jogada);

				if (jogada == 0){
					fimdenivel = 1;
				}

  			else{ /* if jogada!=0 */
					/* O próximo passo é analisar qual das variáveis que guardam o valor da jogada em relação à anterior é a mais frequente.
					A partir disso, prever qual será a próxima jogada do ser humano e fazer a jogada do computador para ganhar */
					if (jogAnterior == 1){ /*Se a jogada anterior for pedra, analisar qual dos comandos o usuário mais jogou depois de pedra*/
	  				maior = maiorNum(Pe_Pe, Pe_Pa, Pe_Te); /*função que determina o maior número dentre 3*/
	  				if (maior == Pe_Pe) jogcpu = 3; /* Exemplo: se a variável Pe_Pe é a maior, isso significa que,
																						depois do comando pedra, o ser humano jogou outra pedra na maioria das vezes.
																						Portanto, assume-se que o ser humano jogará pedra novamente. O computador,
																						portanto, joga papel, que ganha de pedra */
	  				else if (maior == Pe_Pa) jogcpu = 2;
	  				else if (maior == Pe_Te) jogcpu = 1;
	  			}
	  			else if (jogAnterior == 2){
	  				maior = maiorNum(Te_Pe, Te_Pa, Te_Te);
	  				if (maior == Te_Pe) jogcpu = 3;
	  				else if (maior == Te_Pa) jogcpu = 2;
	  				else if (maior == Te_Te) jogcpu = 1;
	  			}
	  			else{ /* (jogAnterior == 3) */
	  				maior = maiorNum(Pa_Pe,Pa_Pa, Pa_Te);
	  				if (maior == Pa_Pe) jogcpu = 3;
	  				else if (maior == Pa_Pa) jogcpu = 2;
	  				else if (maior == Pa_Te) jogcpu = 1;
	  			}

	  			/* Escolhida a jogada do computador, vamos agora armazenar a jogada atual (sempre em relação à jogada anterior) do ser humano */
	  			if (jogada == 1){ /* Conforme fizemos nas 5 primeiras jogadas */
	  				if (jogAnterior == 1) Pe_Pe++;
	  				else if (jogAnterior == 2) Te_Pe++;
	  				else Pa_Pe++; /* if(jogAnterior==3) */
	  			}
	  			else if (jogada == 2){
	  				if (jogAnterior == 1) Pe_Te++;
	  				else if (jogAnterior == 2) Te_Te++;
	  				else Pa_Te++;
	  			}
	  			else{ /* (jogada==3) */
	  				if (jogAnterior == 1) Pe_Pa++;
	  				else if (jogAnterior == 2) Te_Pa++;
	  				else Pa_Pa++;
	  			}

	  			jogAnterior = jogada; /* jogada anterior recebe a jogada atual */

	   			/* Vamos agora comparar a jogada do computador e a jogada do ser humano e analisar quem foi o vencedor */
	  			if (jogcpu == 1){ /* jogcpu é a jogada do computador */
	  				printf ("Jogada do computador: pedra\n");
	  				if (jogada == 3){ /*jogada é a jogada do ser humano*/
	  					printf ("Você venceu!\n\n");
	  					vitoria++;
	  				}
	  				else if (jogada == 1){
	  					printf ("Empate\n\n");
	  					empate++;
	  				}
	  				else if (jogada == 2){
	  					printf ("Você perdeu!\n\n");
	  					derrota++;
	  				}
	  			}

	  			if (jogcpu == 2){
	  				printf ("Jogada do computador: tesoura\n");
	  				if (jogada == 1){
	  					printf ("Você venceu!\n\n");
	  					vitoria++;
	  				}
	  				else if (jogada == 3){
	  					printf ("Você perdeu!\n\n");
	  					derrota++;
	  				}
	  				else if (jogada == 2){
	  					printf ("Empate\n\n");
	  					empate++;
	  				}
	  			}

	  			if (jogcpu == 3){
	  				printf ("Jogada do computador: papel\n");
	  				if (jogada == 2){
	  					printf ("Você venceu!\n\n");
	  					vitoria++;
	  				}
	  				else if (jogada == 1){
	  					printf ("Você perdeu!\n\n");
	  					derrota++;
	  				}
	  				else if (jogada == 3){
	  					printf ("Empate\n\n");
	  					empate++;
	  				}
	  			}
				} /* else, isto é, if (jogada!=0) */
  		} /* while (fimdenivel==0) */

      printf ("\n");
			printResultado(vitoria, derrota, empate); /* imprimir resultado do nível */
			printf ("\n");
			printf ("Deseja jogar novamente? Digite 1 para sim ou 2 para não.\n");
			scanf ("%d", &option);
				if (option == 2) fimdejogo = 1;
			printf ("\n");
  	} /* if (nivel==2) */
		/* Justificativa da escolha do k do nível médio, conforme enunciado do EP:
		A minha escolha foi armazenar e analisar todas as jogadas anteriores para obter um padrão do ser humano mais preciso. */

    if (nivel == 3){
  		printf ("MODO DIFÍCIL1\n\n");
  		printf ("Entre com uma semente:\n");
  		scanf ("%d", &xn);
  		printf ("\nDigite 1 para pedra, 2 para tesoura ou 3 para papel:\n");
  		scanf ("%d", &jogada);

  		/* A primeira jogada vai ser guardada separadamente em uma variável jogada anterior, para que possa servir de comparação nas próximas rodadas */
			for (i = 0; i < 1 && fimdenivel == 0; i++){
				if (jogada == 0) fimdenivel = 1;
				else { /* if jogada!=0 */
					jogcpu = 3;
		  		printf ("Jogada do computador: papel\n");
		  			if (jogada == 1){
		  				printf ("Você perdeu!\n");
		  				derrota++;
		  			}
		  			if (jogada == 2){
		  				printf ("Você venceu!\n");
		  				vitoria++;
		  			}
		  			if (jogada == 3){
		  				printf ("Empate!\n");
		  				empate++;
		  			}
		  		jogAnterior = jogada; /* jogada anterior do ser humano recebe a jogada atual */
		  		jogcpuAnt = jogcpu; /* jogada anterior do computador recebe jogada atual do computador */
				} /* else */
			} /* for (i = 0; i < 1 && fimdenivel == 0; i++) */

  		while (fimdenivel == 0){ /* Depois da primeira jogada, todos os comando abaixo são repetidos até que o usuário deseje parar */
  			xn = numAleatorio(xn, m); /* xn recebe a função que gera o número aleatório */
  			jogcpuA = zeroum(xn, m); /* jogcpu normaliza o valor de xn */
  			printf ("\nDigite 1 para pedra, 2 para tesoura ou 3 para papel:\n");
  			scanf ("%d", &jogada);

  			if (jogada == 0) fimdenivel = 1;

				/* Agora vamos definir a jogada do computador */
				else{ /*if (jogada!=0)*/
	  			if ((jogcpuAnt == 3 && jogAnterior == 2) || (jogcpuAnt == 2 && jogAnterior == 1) || (jogcpuAnt == 1 && jogAnterior == 3)){ /* isto é, se o ser humano venceu */
	  				if (jogcpuA >= 0.0 && jogcpuA < 2.0/3){ /* Se o ser humano venceu, parte-se da ideia de que ele utilizará o mesmo comando,
																										para ganhar novamente. Portanto, o computador joga o comanda que vence da jogada anterior do ser humano */
	  					if (jogcpuAnt == 3) jogcpu = 1; /* O intervalo de probabilidade do número aleatório é maior para esse caso porque é mais
																							provável que ele jogue o mesmo comando do que as outras opções */
	  					else if (jogcpuAnt == 2) jogcpu = 3;
	  					else jogcpu = 2; /* else if (jogcpuAnt==1) */
	  				}
	  				else if (jogcpuA >= 2/3 && jogcpuA < 5/6){ /* As outras duas opções de próxima jogada do ser humano, as que são menos prováveis, recebem um valor de
																												 probabilidade igual e menor, por serem menos prováveis*/
	  					if (jogcpuAnt == 3) jogcpu = 2;
	  					else if (jogcpuAnt == 2) jogcpu = 2;
	  					else jogcpu = 1; /* else if (jogcpuAnt==1) */
	  				}
	  				else if (jogcpuA >= 5/6 && jogcpuA < 3/3){
	  					if (jogcpuAnt == 3) jogcpu = 3;
	  					else if (jogcpuAnt == 2) jogcpu = 1;
	  					else jogcpu = 3; /* else if (jogcpuAnt==1) */
	  				}
	  		 } /* if ((jogcpuAnt==3 && jogAnterior==2) || (jogcpuAnt==2 && jogAnterior==1) || (jogcpuAnt==1 && jogAnterior==3)) */

	  		 else if ((jogcpuAnt == 3 && jogAnterior == 1) || (jogcpuAnt == 2 && jogAnterior == 3) || (jogcpuAnt == 1 && jogAnterior == 2)){ /* isto é, se o ser humano perdeu */
	  			 if (jogcpuA >= 0.0 && jogcpuA < 2.0/3){ /* Se o ser humano perdeu, parte-se da ideia de que, na próxima jogada, ele utilizará o comando
						 																				que vence da jogada anterior do computador.*/
	  				 if (jogcpuAnt == 3) jogcpu = 1;
	  				 else if (jogcpuAnt == 2) jogcpu = 3;
	  				 else jogcpu = 2; /* else if (jogcpuAnt==1) */
	  			 }
	  			 else if (jogcpuA >= 2/3 && jogcpuA < 5/6){ /* Utilizei as 3 possibilidades de jogadas para dar um grau de aleatoriedade ao programa e
						 																					para que seja mais difícil de o ser humano descobrir a estratégia do computador */
	  				 if (jogcpuAnt == 3) jogcpu = 2;
	  				 else if (jogcpuAnt == 2) jogcpu = 1;
	  				 else jogcpu = 3; /* else if (jogcpuAnt == 1) */
	  			 }
	  			 else if (jogcpuA >= 5/6 && jogcpuA < 3/3){
	  				 if (jogcpuAnt == 3) jogcpu = 3;
	  				 else if (jogcpuAnt == 2) jogcpu = 2;
	  				 else jogcpu = 1; /* else if (jogcpuAnt==1) */
	  			 }
	  		 } /* else if ((jogcpuAnt==3 && jogAnterior==1) || (jogcpuAnt==2 && jogAnterior==3) || (jogcpuAnt==1 && jogAnterior==2)) */

				 /* No caso de o ser humano empatar na rodada anterior, a jogada é aleatória */
	  		 else if ((jogcpuAnt == 3 && jogAnterior == 3) || (jogcpuAnt == 2 && jogAnterior == 2) || (jogcpuAnt == 3 && jogAnterior == 3)){
	  			 if (jogcpuA >= 0.0 && jogcpuA < 1.0/3){
	  				 if (jogcpuAnt == 3) jogcpu = 3;
	  				 else if (jogcpuAnt == 2) jogcpu = 2;
	  				 else jogcpu = 1; /* else if (jogcpuAnt==1) */
	  			 }
	  			 if (jogcpuA >= 1/3 && jogcpuA < 2/3){
	  				 if (jogcpuAnt == 3) jogcpu = 2;
	  				 else if (jogcpuAnt == 2) jogcpu = 1;
	  				 else jogcpu = 2; /* else if (jogcpuAnt==1) */
	  			 }
	  			 if (jogcpuA >= 2/3 && jogcpuA < 3/3){
	  				 if (jogcpuAnt == 3) jogcpu = 1;
	  				 else if (jogcpuAnt == 2) jogcpu = 3;
	  				 else jogcpu = 3; /* else if (jogcpuAnt==1) */
	  			 }
	  		 } /* else if ((jogcpuAnt==3 && jogAnterior==3) || (jogcpuAnt==2 && jogAnterior==2) || (jogcpuAnt==3 && jogAnterior==3)) */

				 /* Definida a jogada do computador, vamos comparar com a jogada atual do ser humano para obter o resultado */
				 if (jogcpu == 1){
	  				printf ("Jogada do computador: pedra\n");
	  				if (jogada == 3){
	  					printf ("Você venceu!\n\n");
	  					vitoria++;
	  				}
	  				else if (jogada == 1){
	  					printf ("Empate\n\n");
	  					empate++;
	  				}
	  				else if (jogada == 2){
	  					printf ("Você perdeu!\n\n");
	  					derrota++;
	  				}
	  			} /* if (jogcpu==1) */

					else if (jogcpu == 2){
	  				printf ("Jogada do computador: tesoura\n");
	  				if (jogada == 1){
	  					printf ("Você venceu!\n\n");
	  					vitoria++;
	  				}
	  				else if (jogada == 3){
	  					printf ("Você perdeu!\n\n");
	  					derrota++;
	  				}
	  				else if (jogada == 2){
	  					printf ("Empate\n\n");
	  					empate++;
	  				}
	  			} /* else if (jogcpu==2) */

					else if (jogcpu == 3){
	  				printf ("Jogada do computador: papel\n");
	  				if (jogada == 2){
	  					printf ("Você venceu!\n\n");
	  					vitoria++;
	  				}
	  				else if (jogada == 1){
	  					printf ("Você perdeu!\n\n");
	  					derrota++;
	  				}
	  				else if (jogada == 3){
	  					printf ("Empate\n\n");
	  					empate++;
	  				}
	  			} /* else if (jogcpu==3) */

	  		jogAnterior = jogada; /* jogada anterior recebe a jogada atual */
	  		jogcpuAnt = jogcpu; /* jogada anterior do computador recebe a jogada atual do computador */

				} /* else, isto é fimdejogo!=0 */
  		} /* while (fimdenivel==0) */

      printf ("\n");
			printResultado(vitoria, derrota, empate); /* imprimir resultado do nível */
			printf ("\n");
			printf ("Deseja jogar novamente? Digite 1 para sim ou 2 para não.\n");
			scanf ("%d", &option);
				if (option == 2) fimdejogo = 1;
			printf ("\n");

  	} /* if (nivel==3) */

		if (nivel == 4){
			printf ("MODO DIFÍCIL2\n\n");
			printf ("Entre com uma semente:\n");
			scanf ("%d", &xn);
			printf ("\nDigite 1 para pedra, 2 para tesoura ou 3 para papel:\n");
			scanf ("%d", &jogada);

			/* A primeira jogada do computador (jogcpu) vai ser armazenada separadamente em uma variável jogcpuAnt,
			para que possa servir de comparação nas próximas rodadas */
			for (i = 0; i < 1 && fimdenivel == 0; i++){
				if (jogada == 0) fimdenivel = 1;
				else{
					jogcpu = 3; /* A primeira jogada do computador não vai ser aleatória. Escolhi papel porque, a partir de pesquisas,
											constatei que as pessoas jogam mais vezes o comando pedra, por parecer ser mais forte e por ser mais
											fácil de ser jogado com as mãos.*/
					printf ("Jogada do computador: papel\n");
						if (jogada == 1){
							printf ("Você perdeu!\n");
							derrota++;
						}
						if (jogada == 2){
							printf ("Você venceu!\n");
							vitoria++;
						}
						if (jogada == 3){
							printf ("Empate!\n");
							empate++;
						}
				jogcpuAnt = jogcpu; /* jogada anterior do computador recebe jogada atual */
				} /* else, isto é, if (jogada!=0) */
			} /* for (i=0; i<1 && fimdenivel==0; i++) */

			for (i = 1; i < 5 && fimdenivel == 0; i++){ /* As próximas 4 jogadas serão aleatórias para analisar o padrão do ser humano nas primeiras rodadas */
				printf ("\nDigite 1 para pedra, 2 para tesoura ou 3 para papel:\n");
				scanf ("%d", &jogada);
				xn = numAleatorio(xn, m); /* função que gera o número aleatório */
				jogcpuA = zeroum(xn, m); /* função normaliza o número aleatório */

				if (jogada == 0) fimdenivel = 1; /* comando 0 termina o jogo */

				else{ /* if (jogada!=0) */
					if (jogcpuA >= 0.0 && jogcpuA < 1.0/3){
						jogcpu = 1;
						printf ("Jogada do computador: pedra\n");
						if (jogada == 3){
							printf ("Você venceu!\n\n");
							vitoria++;
						}
						else if (jogada == 1){
							printf ("Empate\n\n");
							empate++;
						}
						else if (jogada == 2){
							printf ("Você perdeu!\n\n");
							derrota++;
						}
					}

					else if (jogcpuA >= 1.0/3 && jogcpuA < 2.0/3){
						jogcpu = 2;
						printf ("Jogada do computador: tesoura\n");
						if (jogada == 1){
							printf ("Você venceu!\n\n");
							vitoria++;
						}
						else if (jogada == 3){
							printf ("Você perdeu!\n\n");
							derrota++;
						}
						else if (jogada == 2){
							printf ("Empate\n\n");
							empate++;
						}
					}

					else if (jogcpuA >= 2.0/3 && jogcpuA < 1.0){
						jogcpu = 3;
						printf ("Jogada do computador: papel\n");
						if (jogada == 2){
							printf ("Você venceu!\n\n");
							vitoria++;
						}
						else if (jogada == 1){
							printf ("Você perdeu!\n\n");
							derrota++;
						}
						else if (jogada == 3){
							printf ("Empate\n\n");
							empate++;
						}
					}
					/*Agora, a jogada do ser humano será armazenada em uma variável, a qual
					vai analisar a escolha do ser humano em relação à jogada anterior do computador*/
					if (jogada == 1){ /*Se a jogada atual for pedra, analisaremos qual foi a escolha do ser humano, nas*/
						if (jogcpuAnt == 1) cpuPe_pesPe++; /*Se a jogada anterior do computator tiver sido pedra, guardar na variável cpuPe_pesPe,
																								que indica que, depois da jogada pedra do computador, a pessoa jogou pedra*/
						else if (jogcpuAnt == 2) cpuTe_pesPe++; /*Se a jogada anterior do computador tiver sido tesoura, guardar na variável cpuTe_pesPe,
																										que indica que, depois do comando pedra do computador, a pessoa jogou tesoura*/
						else cpuPa_pesPe++; /* if(jogcpuAnt==3) */ /* Se a jogada anterior do computador tiver sido papel, guardar na variável cpuPa_pesPe,
																												que indica que, depois do comando pedra do computador, a pessoa jogou papel */
					} /* Esse comando de guardar a jogada da pessoa em relação à última jogada do computador é repetido em cada caso */
					else if (jogada == 2){
						if (jogcpuAnt == 1) cpuPe_pesTe++;
						else if (jogcpuAnt == 2) cpuTe_pesTe++;
						else cpuPa_pesTe++;
					}
					else if (jogada == 3){
						if (jogcpuAnt == 1) cpuPe_pesPa++;
						else if (jogcpuAnt == 2) cpuTe_pesPa++;
						else cpuPa_pesPa++;
					}
				/* As variáveis que indicam o que o ser humano jogou depois da jogada do computador são atualizadas a cada rodada, de forma que é possível analisar o padrão */
				jogcpuAnt = jogcpu;
				} /* else */
			} /* for (i=0; i<4 && fim==0; i++) */

			/* Agora vamos analisar as próximas jogadas, isto é, quando i>5 */
			while (fimdenivel == 0){
				/* O próximo passo é analisar qual das variáveis que guardam o valor da jogada da pessoa em relação à última jogada do
				computador é a mais frequente. A partir disso, prever qual será a próxima jogada do ser humano e fazer a jogada do computador para ganhar */
				if (jogcpuAnt == 1){
					maior = maiorNum(cpuPe_pesPe, cpuPe_pesPa, cpuPe_pesTe);
					if (maior == cpuPe_pesPe) jogcpu = 3; /* Se a maior variável dentre essas que guardam o valor da jogada da pessoa em relação à jogada anterior
					 																			do computador for cpuPe_pesPe, significa que, depois da jogada pedra do computador, o ser humano jogou pedra
																								mais vezes. Portanto, supõe-se que ele jogará pedra novamente, então o computador joga papel, que ganha de pedra. */
					else if (maior == cpuPe_pesPa) jogcpu = 2;
					else if (maior == cpuPe_pesTe) jogcpu = 1;
				}

				else if (jogcpuAnt == 2){
					maior = maiorNum(cpuTe_pesPe, cpuTe_pesPa, cpuTe_pesTe);
					if (maior == cpuTe_pesPe) jogcpu = 3;
					else if (maior == cpuTe_pesPa) jogcpu = 2;
					else if (maior == cpuTe_pesTe) jogcpu = 1;
				}

				else{ /* (jogcpuAnt==3) */
					maior = maiorNum(cpuPa_pesPe, cpuPa_pesPa, cpuPa_pesTe);
					if (maior == cpuPa_pesPe) jogcpu = 3;
					else if (maior == cpuPa_pesPa) jogcpu = 2;
					else if (maior == cpuPa_pesTe) jogcpu = 1;
				}

				/* Escolhida a jogada do computador, vamos agora guardar a jogada atual (sempre em relação à jogada anterior do computador) do ser humano */
				printf ("\nDigite 1 para pedra, 2 para tesoura ou 3 para papel:\n");
				scanf ("%d", &jogada);

				if (jogada == 0) fimdenivel = 1; /* comando 0 encerra o jogo */

				else{
					if (jogada == 1){
						if (jogcpuAnt == 1) cpuPe_pesPe++;
						else if (jogcpuAnt == 2) cpuTe_pesPe++;
						else cpuPa_pesPe++;
					}
					else if (jogada == 2){
						if (jogcpuAnt == 1) cpuPe_pesTe++;
						else if (jogcpuAnt == 2) cpuTe_pesTe++;
						else cpuPa_pesTe++;
					}
					else if (jogada == 3){
						if (jogcpuAnt == 1) cpuPe_pesPa++;
						else if (jogcpuAnt == 2) cpuTe_pesPa++;
						else cpuPa_pesPa++;
					}

		 			/*Vamos agora comparar a jogada do computador e a jogada do ser humano*/
					if (jogcpu == 1){
						printf ("Jogada do computador: pedra\n");
						if (jogada == 3){
							printf ("Você venceu!\n\n");
							vitoria++;
						}
						else if (jogada == 1){
							printf ("Empate\n\n");
							empate++;
						}
						else if (jogada == 2){
							printf ("Você perdeu!\n\n");
							derrota++;
						}
					}

					if (jogcpu == 2){
						printf ("Jogada do computador: tesoura\n");
						if (jogada == 1){
							printf ("Você venceu!\n\n");
							vitoria++;
						}
						else if (jogada == 3){
							printf ("Você perdeu!\n\n");
							derrota++;
						}
						else if (jogada == 2){
							printf ("Empate\n\n");
							empate++;
						}
					}

					if (jogcpu == 3){
						printf ("Jogada do computador: papel\n");
						if (jogada == 2){
							printf ("Você venceu!\n\n");
							vitoria++;
						}
						else if (jogada == 1){
							printf ("Você perdeu!\n\n");
							derrota++;
						}
						else if (jogada == 3){
							printf ("Empate\n\n");
							empate++;
						}
					}
				jogcpuAnt = jogcpu; /* jogada anterior do computator recebe a jogada atual */
				} /* else, isto é, if jogada!=0 */
			} /* while (fim == 0) */

			printf ("\n");
			printResultado(vitoria, derrota, empate); /* imprimir resultado do nível */
			printf ("\n");
			printf ("Deseja jogar novamente? Digite 1 para sim ou 2 para não.\n");
			scanf ("%d", &option);
				if (option == 2) fimdejogo = 1;
			printf ("\n");
		} /* if (nivel==4) */

	} /* while (fimdejogo= = 0) */

	return 0;

} /*int main*/
