//PEDRO GOULART RODRIGUES
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

	int totalVotosPresidente=0;
	int totalVotosDeputado=0;
	struct dados_presidente presidente;
	struct dados_deputado deputado;
	int votoPresidente = 0;
	int votoDeputado = 0;

struct dados_presidente {
    int  numCandidato;
    char nomeCandidado[21];
    char partidoCandidato[4];
    char cargoCandidato[2];
    int votos;
    float porcentagem;   
    };
       
struct dados_deputado {
    int  numCandidato;
    char nomeCandidado[21];
    char partidoCandidato[4];
    char cargoCandidato[2];
    int votos;
    float porcentagem;
    };
    
struct dados_presidente presidentes[3];
struct dados_deputado deputados[8];
	
int main(){
	setlocale(LC_ALL, "portuguese");
	int menu = 0;
	int cargo = 0;
	int confirmacao = 0;
	
	
	//DECLARAÇÃO DE PRESIDENTES

	//candidato 1
	presidentes[0].numCandidato = 10;
	strcpy(presidentes[0].nomeCandidado, "Jorge");
	strcpy(presidentes[0].partidoCandidato, "ABC");
	strcpy(presidentes[0].cargoCandidato, "P");
	presidentes[0].votos = 0;
	//candidato 2
	presidentes[1].numCandidato = 20;
	strcpy(presidentes[1].nomeCandidado, "Marta");
	strcpy(presidentes[1].partidoCandidato, "XYZ");
	strcpy(presidentes[1].cargoCandidato, "P");
	presidentes[1].votos = 0;
	//candidato 3
	presidentes[2].numCandidato = 30;
	strcpy(presidentes[2].nomeCandidado, "Sergio");
	strcpy(presidentes[2].partidoCandidato, "DEF");
	strcpy(presidentes[2].cargoCandidato, "P");
	presidentes[2].votos = 0;
	//DECLARAÇÃO DE DEPUTADOS
	//candidato 4
	deputados[3].numCandidato = 1001;
	strcpy(deputados[3].nomeCandidado, "Sergio");
	strcpy(deputados[3].partidoCandidato, "ABC");
	strcpy(deputados[3].cargoCandidato, "D");
	deputados[3].votos = 0;
	//candidato 5
	deputados[4].numCandidato = 1002;
	strcpy(deputados[4].nomeCandidado, "Bruna");
	strcpy(deputados[4].partidoCandidato, "ABC");
	strcpy(deputados[4].cargoCandidato, "D");
	deputados[4].votos = 0;
	//candidato 6
	deputados[5].numCandidato = 2001;
	strcpy(deputados[5].nomeCandidado, "Breno");
	strcpy(deputados[5].partidoCandidato, "XYZ");
	strcpy(deputados[5].cargoCandidato, "D");
	deputados[5].votos = 0;
	//candidato 7
	deputados[6].numCandidato = 2002;
	strcpy(deputados[6].nomeCandidado, "Bruno");
	strcpy(deputados[6].partidoCandidato, "XYZ");
	strcpy(deputados[6].cargoCandidato, "D");
	deputados[6].votos = 0;
	//candidato 8
	deputados[7].numCandidato = 2003;
	strcpy(deputados[7].nomeCandidado, "Nani");
	strcpy(deputados[7].partidoCandidato, "XYZ");
	strcpy(deputados[7].cargoCandidato, "D");
	deputados[7].votos = 0;
	//candidato 9
	deputados[8].numCandidato = 3001;
	strcpy(deputados[8].nomeCandidado, "Joao");
	strcpy(deputados[8].partidoCandidato, "DEF");
	strcpy(deputados[8].cargoCandidato, "D");
	deputados[8].votos = 0;
	//candidato 10
	deputados[9].numCandidato = 3002;
	strcpy(deputados[9].nomeCandidado, "Joana");
	strcpy(deputados[9].partidoCandidato, "DEF");
	strcpy(deputados[9].cargoCandidato, "D");
	deputados[9].votos = 0;
	//candidato 11
	deputados[10].numCandidato = 3003;
	strcpy(deputados[10].nomeCandidado, "Josmar");
	strcpy(deputados[10].partidoCandidato, "DEF");
	strcpy(deputados[10].cargoCandidato, "D");
	deputados[10].votos = 0;

	do{
		printf("\n\t ======== MENU ELEIÇÕES ========");
		printf("\n\t 1 - VOTAR.");
		printf("\n\t 2 - Listar candidatos.");
		printf("\n\t 3 - Total de votos.");
		printf("\n\t 4 - Apuração %% de Votos.");
		printf("\n\t 5 - Qntde de eleitos por partido.");
		printf("\n\t 6 - SAIR.");
		printf("\n\n\t Selecione uma opção => ");
		scanf("%d", &menu);
	
		switch(menu){
	
			case 1:
				system("cls");
				iniciarVotacao();
				break;
			case 2:
				exibirCandidatos();
				system("cls");
				break;
			case 3:
				system("cls");
				ordenaPresidente();
				ordenaDeputado();
				totalDeVotos();
				break;
			case 4:
				system("cls");
				percenteVotos();
				break;
			case 5:
				system("cls");
				eleitosPartido();
				break;
			case 6:
				system("cls");
				printf("\n\tVOCÊ SAIU DA VOTAÇÃO\n");
				break;
			default:
				system("cls");
				printf(" ======== OPÇÃO INVÁLIDA ========\n         DIGITE NOVAMENTE! \n");
				break;
		}
		
	}while(menu!= 6);
	
}

int iniciarVotacao(){
	

	int i = 0;
	int confirmacao = 0;
	presidente.nomeCandidado[0] = '\0';
	deputado.numCandidato = 0;
	
	while(confirmacao == 0){
	printf("\t ========= VOTAÇÃO =========\n");
	printf("\t ======== PRESIDENTE ========\n");
	printf("Número do candidato para a Presidência => ");
	scanf("%d", &votoPresidente);
	printf("\n\t ======== DEPUTADO =========");
	printf("\nNúmero do candidato para Deputado => ");
	scanf("%d", &votoDeputado);
	
	for(i = 0 ; i < 11 ; i++)
	{
			if(presidentes[i].numCandidato == votoPresidente && presidentes[i].numCandidato < 50)
			{
				presidente = presidentes[i];
			}
			if(deputados[i].numCandidato == votoDeputado && deputados[i].numCandidato > 1000)
			{
				deputado = deputados[i];
			}
	} 	

		if(presidente.numCandidato != 0)
		{
			printf("\n\t=====PRESIDENTE(A)=====\n");
  	 	    printf("\tNOME => %s \n", presidente.nomeCandidado);
 	  	    printf("\tPARTIDO => %s \n", presidente.partidoCandidato);
   		    printf("\tCARGO => %s \n", presidente.cargoCandidato);
		
		}else
		{
			printf("\n\t DIGITE UM NÚMERO VÁLIDO PARA PRECIDENCIA!!!\n");
		}
		
		if(deputado.numCandidato != 0)
		{
			printf("\n\t=====DEPUTADO(A)=====\n");
        	printf("\tNOME => %s \n", deputado.nomeCandidado);
        	printf("\tPARTIDO => %s \n", deputado.partidoCandidato);
        	printf("\tCARGO => %s \n", deputado.cargoCandidato);
        		
        	printf("\t PARA CONFIRMAR");
        	printf("\n\t 1 - CONFIRMA | 0 - CANCELAR \n\t =>");
        	scanf("%d", &confirmacao);
        		
        	if(confirmacao == 1)
			{
             	for(i = 0; i < 11; i++)
				{
                	if(deputados[i].numCandidato == votoDeputado)
					{
                    	deputados[i].votos += 1;
               		}
               		 if(presidentes[i].numCandidato == votoPresidente)
					{                   	
                   		presidentes[i].votos += 1;
                	}
                }
            }
		}else
		{
				printf("\n\t DIGITE UM NÚMERO VÁLIDO PARA DEPUTADO!!!\n");
		}
	}
	return 0;
}

int ordenaPresidente() {
	int i;
	int j;
	struct dados_presidente k;

	for (i = 0; i < 2; i++)
	 {
		for (j = 0; j < 2; j++) 
		{
			if (presidentes[j].votos < presidentes[j + 1].votos)
			 {
				k = presidentes[j];
				presidentes[j] = presidentes[j + 1];
				presidentes[j + 1] = k;
			}
		}
	}
	return 0;
}

int ordenaDeputado(){
	int i;
	int j;
	struct dados_deputado b;

	for (i = 3; i < 11; i++) {
		for (j = 3; j < 11; j++) {
			if (deputados[j].votos < deputados[j + 1].votos) {
				b = deputados[j];
				deputados[j] = deputados[j + 1];
				deputados[j + 1] = b;				
			}
		}
	}
	return 0;
}

void exibirCandidatos(){
	int i = 0;
	int cargo = 0;
	system("cls");
    printf("\t   ========= Canditados =========\n");
    printf("\t 1 - PRESIDENTES\n");
    printf("\t 2 - DEPUTADOS\n");
    printf("\t Digite opção desejada = >");
    scanf("%d", &cargo);
    
    if(cargo == 1)
	{
		system("cls");
		for(i = 0; i <3; i++)
		{
    		printf("\n");
			printf("\tN°Cand. \tNome Cand. \tPartido Candidato \tCargo Candidato\n");
			printf("\t %d      \t   %s \t     %s      \t\t    %s\n", presidentes[i].numCandidato, presidentes[i].nomeCandidado, presidentes[i].partidoCandidato, presidentes[i].cargoCandidato);	
		}
		system("\nPAUSE");
	}else{
		system("cls");
		for(i = 0; i < 11; i++)
		{
			if(deputados[i].numCandidato > 50)
			{
    		printf("\n");
			printf("\tN°Cand. \t Nome Cand.\tPartido Candid. \tCargo Cand.\n");
			printf("\t %d      \t   %s \t     %s      \t\t    %s\n", deputados[i].numCandidato, deputados[i].nomeCandidado, deputados[i].partidoCandidato, deputados[i].cargoCandidato);
			}
		}
		system("PAUSE");	
	}
}

void totalDeVotos(){
	int cargo = 0;
	int i = 0, j = 0, k = 0;
	int aux1 = 0, aux2 = 0;
	printf("TOTAL DE VOTOS PARA QUAL CARGO?\n1-Presidente\n2-Deputado\n");
    scanf("%d",&cargo);

 	if(cargo == 1)
	{
		system("cls");
		for(i = 0; i <3; i++)
		{
    		printf("\n");
			printf("\tN°Cand. \t Nome Cand.\tPartido Candid. \tCargo Cand. \tTotal Votos\n");
			printf("\t %d      \t   %s \t     %s      \t\t    %s \t             %d\n", presidentes[i].numCandidato, presidentes[i].nomeCandidado, presidentes[i].partidoCandidato, presidentes[i].cargoCandidato, presidentes[i].votos);	
		}
		system("\nPAUSE");
		eleitoPresidente();
	}else{
		system("cls");
		for(i = 0; i < 11; i++)
		{
			if(deputados[i].numCandidato > 50)
			{
    		printf("\n");
			printf("\tN°Cand. \t Nome Cand.\tPartido Candid. \tCargo Cand. \tTotal Votos\n");
			printf("\t %d      \t   %s \t     %s      \t\t    %s \t            %d\n", deputados[i].numCandidato, deputados[i].nomeCandidado, deputados[i].partidoCandidato, deputados[i].cargoCandidato, deputados[i].votos);
			}
		}
		system("PAUSE");
		eleitoDeputado();	
	}	
             
}

int percenteVotos(){ //percet apuração

    int i;
    float porcentagem;
    int totalPresidentes = 0, totalDeputados = 0;
	system("cls");
	
	//Total de votos
 	for (i = 0; i < 3; i++) 
	{
		totalPresidentes += presidentes[i].votos;
	}
	for (i = 0; i < 8; i++)
	{
		totalDeputados += deputados[i].votos;
	}
	//Fazer porcentagem
	for (i = 0; i < 3; i++) 
	{		
		if (totalPresidentes == 0) 
		{	
			printf("\n\t==========================");
			printf("\n\tNenhum voto para apuração %%");
			printf("\n\t==========================\n\n");
			main(); //para não entrar em loop
		}
		else
		{
			presidentes[i].porcentagem = (presidentes[i].votos * 100) / totalPresidentes;
		}
	}
	
	for (i = 3; i < 11; i++)
	{
		if (totalDeputados == 0) 
		{
			printf("\n\t==========================");
			printf("\n\tNenhum voto para apuração %%");
			printf("\n\t==========================\n\n");
			main(); //para não entrar em loop
		}
		else 
		{
			deputados[i].porcentagem = (deputados[i].votos * 100) / totalDeputados;
		}
	}
	
	printf("\n\t\t=====================ELEIÇÕES=====================\n\t\t\t\tAPURAÇÃO DE VOTOS %%");
	printf("\n\t\t==================PRESIDENTES(A)==================");
	printf("\n\t Num. Cand.     Nome Cand.        Cargo Cand.        %% de Votos\n\n");
	ordenaPresidente();
	for (i = 0; i < 3; i++)
	{
		printf("\t %d    \t%s    \t\t%s   \t\t %.2f\t\n",presidentes[i].numCandidato, presidentes[i].nomeCandidado, presidentes[i].cargoCandidato, presidentes[i].porcentagem);
	}
	printf("\n\n\t\t==================DEPUTADOS(A)==================");
	printf("\n\t Num. Cand.     Nome Cand.        Cargo Cand.        %% de Votos\n\n");
	ordenaDeputado();
	for (i = 0; i < 11; i++)
	{
		if(deputados[i].numCandidato > 50)
		{
			printf("\t %d    \t%s    \t\t%s   \t\t %.2f\t\n",deputados[i].numCandidato, deputados[i].nomeCandidado, deputados[i].cargoCandidato, deputados[i].porcentagem);
		}
		
	}
}
void eleitoPresidente(){
	int i = 0;
	ordenaPresidente();
	for (i = 0 ; i < 1 ; i++)
	{
		printf("\t ========== PRESIDENTE(A) ELEITO ==========\n");
		printf("\tN°Cand. \t Nome Cand.\tPartido Candid. \tCargo Cand. \tTotal Votos\n");
	 	printf("\t %d      \t   %s \t     %s      \t\t    %s \t            %d ***\n", presidentes[i].numCandidato, presidentes[i].nomeCandidado, presidentes[i].partidoCandidato, presidentes[i].cargoCandidato, presidentes[i].votos);	
	}
			
}

void eleitoDeputado(){
	int i = 0;
	for (i = 0 ; i <= 1 ; i++)
	{
		printf("\t ========== DEPUTADO(A) ELEITO ==========\n");
		printf("\tN°Cand. \t Nome Cand.\tPartido Candid. \tCargo Cand. \tTotal Votos\n");
	 	printf("\t %d      \t   %s \t     %s      \t\t    %s \t            %d ***\n", deputados[i].numCandidato, deputados[i].nomeCandidado, deputados[i].partidoCandidato, deputados[i].cargoCandidato, deputados[i].votos);	
	}
}

int eleitosPartido(){
	int a = 0, b = 0, c = 0;
	int i = 0, x = 0, y = 0, z = 0;
	struct dados_deputado eleitoDeputado[2];
	ordenaDeputado();
	struct dados_presidente eleitoPresidente[1];
	ordenaPresidente();
	
	eleitoPresidente[0] = presidentes[0];
	
	eleitoDeputado[0] = deputados[3];
	eleitoDeputado[1] = deputados[4];
	
	if(deputados[4].votos > 0)
	{		
			if (strcmp(eleitoPresidente[0].partidoCandidato, "ABC") == 0)
			{
				a++;
			}
			else if (strcmp(eleitoPresidente[0].partidoCandidato, "XYZ") == 0)
			{
				b++;
			}
			else if (strcmp(eleitoPresidente[0].partidoCandidato, "DEF") == 0)
			{
				c++;
			}
		////////////////////////////////////////////////////
			for (i = 0; i <= 2; i++) 
			{
				if (strcmp(eleitoDeputado[i].partidoCandidato, "ABC") == 0)
				{
					x++;
				}
				else if (strcmp(eleitoDeputado[i].partidoCandidato, "XYZ") == 0)
				{
					y++;;
				}
				else if (strcmp(eleitoDeputado[i].partidoCandidato, "DEF") == 0)
				{
					z++;
				}
			}
	}
	printf(" PARTIDOS e VOTOS PRESIDENTE \n\n");
	printf(" ABC	    %d \n XYZ        %d \n DEF        %d \n",a,b,c);
	printf("\n PARTIDOS e VOTOS DEPUTADOS \n\n");
	printf(" ABC	    %d \n XYZ        %d \n DEF        %d \n",x,y,z);
	

	
		
	return 0;
}


