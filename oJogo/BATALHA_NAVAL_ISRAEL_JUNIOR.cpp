#include<stdio.h>
#include<windows.h>
#include <conio.h>
#include<iostream>
// by Israel Junior de Oliveira Santos
// 2021, Fatec Ourinhos

void exibeCampopre (int campo[10][10],int a)
{
		int i,num,j; 
		printf("\n\n\t\tCAMPO EM PRENCHIMENTO DO JOGADODOR %d\n\n",a); 
		printf("      0     1     2     3     4     5     6     7     8     9\n\n");
		for(i=0;i<10;i++)
		{
			printf("%d   ",i);
			
			for(j=0; j<10; j++)
			{	
				printf("  %d   ",campo[i][j]);								
			}
			
			printf("\n\n");
			num++;			
		}
}


void zeromatriz (int mat[10][10])
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			mat[i][j]=0; 
}


void addnavio (int campo[10][10])
{
	int linha_navio[2],coluna_navio[2]; 
	int i=0; 
	printf("Insira dois NAVIOS representados pelo numero | 1 |: \n\n"); 
	
	do
    {
	printf("Insira a LINHA do navio [0 a 9]: ",i+1);
	scanf ("%d", &linha_navio[i]);
	
	printf("Insira a COLUNA do navio [0 a 9]: ",i+1); 
	scanf ("%d", &coluna_navio[i]);
	
	
	 if (       (linha_navio[i] > 9 || linha_navio[i] < 0)                      ||
                (  coluna_navio[i] > 9 || coluna_navio < 0 )                    ||
                (linha_navio[0] == linha_navio[1] && coluna_navio[0] == coluna_navio[1])
                
        )       {
                    printf ("Numero(s) invalido(s),TENTE NOVAMENTE\n");
                    Sleep(2000);
                    system("cls");
                }else{
                    i++;
                }        
    }while (i<2);
            
        for (i=0;i<2;i++)
            campo[linha_navio[i]][coluna_navio[i]] = 1;


}

void addsubmarino (int campo[10][10])
{
	
	int valida=0; 
	char sentido; 
	int i=0; 
	
	printf("Insira dois SUBMARINOS de 2 espacos, representados pelo numero | 2 |: \n\n"); 
	
	int l_sub,l1_sub,c_sub;    
    int l2_sub, c2_sub, l3_sub, c3_sub;
    
    printf ("Determine o sentido das navegacoes\n\n");
    printf ("Coloque 'V' para vertical\nColoque 'H' para horizontal\n");
    scanf ("%s", &sentido);
    i=0;
    
    
    if (sentido == 'v' || sentido == 'V'){
            printf ("\nInsira a COLUNA que deseja colocar o SUBMARINO  [0 a 9]: ");
            scanf ("%d", &c_sub);
            fflush(stdin);
            
        do
        {
            printf ("Insira a LINHA do submarino [0 a 9]: ");
            scanf ("%d", &l_sub);
            printf ("Insira a LINHA do submarino [0 a 9]: ");
            scanf ("%d", &l1_sub);
            fflush(stdin);
        
            if (
					(campo[l_sub][c_sub] != 0 || campo[l1_sub][c_sub] != 0)     ||
		            (l_sub == l1_sub)                                             ||
		            (l_sub > l1_sub+1||l_sub < l1_sub-1)                          ||
		            (l_sub < 0 || l_sub > 9)                                      ||
		            (l1_sub < 0 || l1_sub > 9)                                    //||
		            //(l_sub == 0 || l1_sub == 9 || l_sub == 9 || l1_sub == 0)    
            	)
			{
                printf ("Numero(s) invalido(s),TENTE NOVAMENTE!\n");
                Sleep(2000);
                system("cls");
            }else{
            valida++;
            campo[l_sub][c_sub] = 2;
            campo[l1_sub][c_sub] = 2;
            }
        
        }while (valida<1);
    
    
    }else if (sentido == 'h' || sentido == 'H'){
        printf ("Insira a LINHA que deseja colocar o SUBMARINO  [0 a 9]: ");
        scanf ("%d", &c_sub);
        fflush(stdin);
        do
        {
            printf ("Insira a COLUNA do submarino [0 a 9]: ");
            scanf ("%d", &l_sub);
            printf ("Insira a COLUNA do submarino [0 a 9]: ");
            scanf ("%d", &l1_sub);
            fflush(stdin);
        
            if (
					(campo[l_sub][c_sub] != 0 || campo[l1_sub][c_sub] != 0)       ||
		            (l_sub == l1_sub)                                             ||
		            (l_sub > l1_sub+1||l_sub < l1_sub-1)                          ||
		            (l_sub < 0 || l_sub > 9)                                      ||
		            (l1_sub < 0 || l1_sub > 9)                                        
	        	){
	                printf ("Numero(s) invalido(s),TENTE NOVAMENTE!\n");
	                Sleep(2000);
	                system("cls");
	             }else{
		            valida++;
	            campo[c_sub][l_sub] = 2;
	            campo[c_sub][l1_sub] = 2;
	            }
	        
        }while (valida<1);
    }

}

void addcontratorpedeiro (int campo[10][10])
{
	int i=0; 
	
	int valida=0; 
	
	char sentido; 
	
	int l_contra,l1_contra,l2_contra,c_contra; 
	
	
	printf("Insira 1 CONTRATORPEDEIRO de 3 casas representados pelo numero | 3 |: \n\n"); 
	
	printf ("Determine o sentido das navegacoes\n\n");
    printf ("Coloque 'V' para vertical\nColoque 'H' para horizontal\n");
    scanf ("%s", &sentido);
    i=0;
    
     if (sentido == 'v' || sentido == 'V'){
            printf ("Insira a COLUNA que deseja colocar o contratorpedeiro  [0 a 9]: ");
            scanf ("%d", &c_contra);
            fflush(stdin);
            
        do
        {
            printf ("Insira a LINHA do contratorpedeiro [0 a 9]: ");
            scanf ("%d", &l_contra);
            printf ("Insira a LINHA do contratorpedeiro [0 a 9]: ");
            scanf ("%d", &l1_contra);
            printf ("Insira a LINHA do contratorpedeiro [0 a 9]: ");
            scanf ("%d", &l2_contra);
          
            fflush(stdin);
        
            if (
					(campo[l_contra][c_contra] != 0 || campo[l1_contra][c_contra] != 0 ||campo[l2_contra][c_contra] != 0)       ||
		            ((l_contra == l1_contra)||(l_contra==l2_contra) ||(l1_contra==l2_contra))                                   ||
		            (l_contra > l1_contra+1||l_contra < l1_contra-1 ||l1_contra>l2_contra+1 ||l1_contra<l2_contra-1)            ||
		            (l_contra < 0 || l_contra > 9)                                                  							||
		            (l1_contra < 0 || l1_contra > 9)                                                							||
		            (l2_contra<0|| l2_contra>9)                                                                                 
            	)
			{
                printf ("Numero(s) invalido(s),TENTE NOVAMENTE!\n");
                Sleep(2000);
                system("cls");
            }else{
            valida++;
            campo[l_contra][c_contra] = 3;
            campo[l1_contra][c_contra] = 3;
            campo[l2_contra][c_contra] = 3;
            }
        
        }while (valida<1);
    
    
    }else if (sentido == 'h' || sentido == 'H'){
        printf ("Insira a LINHA que deseja colocar o contratorpedeiro [0 a 9]: ");
        scanf ("%d", &c_contra);
        fflush(stdin);
        do
        {
            printf ("Insira a COLUNA do contratorpedeiro [0 a 9]: ");
            scanf ("%d", &l_contra);
            printf ("Insira a COLUNA do contratorpedeiro [0 a 9]: ");
            scanf ("%d", &l1_contra);
            printf ("Insira a COLUNA do contratorpedeiro [0 a 9]: ");
            scanf ("%d", &l2_contra);
            
			fflush(stdin);
        
            if (
					(campo[l_contra][c_contra] != 0 || campo[l1_contra][c_contra] != 0 ||campo[l2_contra][c_contra] != 0 )       ||
		            ((l_contra == l1_contra)||(l_contra==l2_contra)||(l1_contra==l2_contra))                                     ||
		            (l_contra > l1_contra+1||l_contra < l1_contra-1 ||l1_contra>l2_contra+1 ||l1_contra<l2_contra-1)             ||
		            (l_contra < 0 || l_contra > 9)                                      ||
		            (l1_contra < 0 || l1_contra > 9)  ||
					(l2_contra<0|| l2_contra>9)                                  
	        	){
	                printf ("Numero(s) invalido(s),TENTE NOVAMENTE\n");
	                Sleep(2000);
	                system("cls");
	             }else{
		            valida++;
	            campo[c_contra][l_contra] = 3;
	            campo[c_contra][l1_contra] = 3;
	            campo[c_contra][l2_contra] = 3;
	            }
	        
        }while (valida<1);
    }

}

void addnaviotanque (int campo[10][10])
{
	
	int i=0; 
	
	int valida=0; 
	
	char sentido; 
	
	int l_tanque,l1_tanque,l2_tanque,l3_tanque,c_tanque;
	
	printf("Insira 1 NAVIO TANQUE de 4 casas representados pelo numero | 4 |: \n\n"); 
	
	printf ("Determine o sentido das navegacoes\n\n");
    printf ("Coloque 'V' para vertical\nColoque 'H' para horizontal\n");
    scanf ("%s", &sentido);
    i=0;
    
     if (sentido == 'v' || sentido == 'V'){
            printf ("Insira a COLUNA que deseja colocar o NAVIO TANQUE [0 a 9]: ");
            scanf ("%d", &c_tanque);
            fflush(stdin);
            
     do
        {
            printf ("Insira a LINHA do navio tanque [0 a 9]: ");
            scanf ("%d", &l_tanque);
            printf ("Insira a LINHA do navio tanque [0 a 9]: ");
            scanf ("%d", &l1_tanque);
            printf ("Insira a LINHA do navio tanque [0 a 9]: ");
            scanf ("%d", &l2_tanque);
            printf ("Insira a LINHA do navio tanque [0 a 9]: ");
            scanf ("%d", &l3_tanque);
          
            fflush(stdin);
        
            if (
					(campo[l_tanque][c_tanque] != 0 || campo[l1_tanque][c_tanque] != 0 ||campo[l2_tanque][c_tanque] != 0  ||campo[l3_tanque][c_tanque] != 0 )       ||
		            ((l_tanque == l1_tanque)||(l_tanque==l2_tanque)||(l1_tanque==l2_tanque) ||(l_tanque==l3_tanque)||(l1_tanque==l3_tanque) ||(l2_tanque==l3_tanque))                                    ||
		            (l_tanque > l1_tanque+1||l_tanque < l1_tanque-1 ||l1_tanque>l2_tanque+1 ||l1_tanque<l2_tanque-1||l2_tanque>l3_tanque+1||l2_tanque<l3_tanque-1)            ||
		            (l_tanque < 0  || l_tanque > 9)                                                  							||
		            (l1_tanque < 0 || l1_tanque > 9)                                                							||
		            (l2_tanque<0   || l2_tanque>9)   																			||
					(l3_tanque<0   || l3_tanque>9)                                                                                    
            	)
			{
                printf ("Numero(s) invalido(s),TENTE NOVAMENTE!\n");
                Sleep(2000);
                system("cls");
            }else{
            valida++;
            campo[l_tanque][c_tanque] = 4;
            campo[l1_tanque][c_tanque] = 4;
            campo[l2_tanque][c_tanque] = 4;
            campo[l3_tanque][c_tanque] = 4;
            }
        
        }while (valida<1);
    
    
    }else if (sentido == 'h' || sentido == 'H'){
        printf ("Insira a LINHA que deseja colocar o contratorpedeiro [0 a 9]: ");
        scanf ("%d", &c_tanque);
        fflush(stdin);
        do
        {
            printf ("Insira a COLUNA do contratorpedeiro [0 a 9]: ");
            scanf ("%d", &l_tanque);
            printf ("Insira a COLUNA do contratorpedeiro [0 a 9]: ");
            scanf ("%d", &l1_tanque);
            printf ("Insira a COLUNA do contratorpedeiro [0 a 9]: ");
            scanf ("%d", &l2_tanque);
            printf ("Insira a COLUNA do contratorpedeiro [0 a 9]: ");
            scanf ("%d", &l3_tanque);
            
			fflush(stdin);
        
            if (
					(campo[l_tanque][c_tanque] != 0 || campo[l1_tanque][c_tanque] != 0 ||campo[l2_tanque][c_tanque] != 0  || campo[l3_tanque][c_tanque] != 0 )                 ||
		            ((l_tanque == l1_tanque)||(l_tanque==l2_tanque)||(l1_tanque==l2_tanque) ||(l_tanque==l3_tanque)||(l1_tanque==l3_tanque) ||(l2_tanque==l3_tanque))          ||
		            (l_tanque > l1_tanque+1 ||l_tanque < l1_tanque-1 ||l1_tanque>l2_tanque+1||l1_tanque<l2_tanque-1||l2_tanque>l3_tanque+1  ||l2_tanque<l3_tanque-1)             ||
		            (l_tanque < 0  || l_tanque > 9)                                                  							||
		            (l1_tanque < 0 || l1_tanque > 9)                                                							||
		            (l2_tanque<0   || l2_tanque>9)   																			||
					(l3_tanque<0   || l3_tanque>9)                                                                                                           
	        	){
	                printf ("Numero(s) invalido(s),TENTE NOVAMENTE!\n");
	                Sleep(2000);
	                system("cls");
	             }else{
		            valida++;
	            campo[c_tanque][l_tanque] = 4;
	            campo[c_tanque][l1_tanque] = 4;
	            campo[c_tanque][l2_tanque] = 4;
	            campo[c_tanque][l3_tanque] = 4;
	            }
	        
        }while (valida<1);
    }
            

}

void addportaaviao (int campo[10][10])
{
	int i=0; 
	
	int valida=0; 
	
	char sentido; 
	
	int l_porta,l1_porta,l2_porta,l3_porta,l4_porta,c_porta;
	
	printf("Insira 1 PORTA AVIAO de 5 casas representados pelo numero | 5 |\n\n"); 
	
	printf ("Determine o sentido das navegacoes\n\n");
    printf ("Coloque 'V' para vertical\nColoque 'H' para horizontal\n");
    scanf ("%s", &sentido);
    i=0;
    
     if (sentido == 'v' || sentido == 'V'){
            printf ("Insira a COLUNA que deseja colocar o PORTA AVIAO  [0 a 9]: ");
            scanf ("%d", &c_porta);
            fflush(stdin);
            
     do
        {
            printf ("Insira a LINHA do porta aviao [0 a 9]: ");
            scanf ("%d", &l_porta);
            printf ("Insira a LINHA do navio aviao [0 a 9]: ");
            scanf ("%d", &l1_porta);
            printf ("Insira a LINHA do navio aviao [0 a 9]: ");
            scanf ("%d", &l2_porta);
            printf ("Insira a LINHA do navio aviao [0 a 9]: ");
            scanf ("%d", &l3_porta);
            printf ("Insira a LINHA do navio aviao [0 a 9]: ");
            scanf ("%d", &l4_porta);
          
          
            fflush(stdin);
        
            if (
					(campo[l_porta][c_porta] != 0 || campo[l1_porta][c_porta] != 0  ||campo[l2_porta][c_porta] != 0  ||campo[l3_porta][c_porta] != 0   ||campo[l3_porta][c_porta] != 0 )       ||
		            ((l_porta == l1_porta)||(l_porta==l2_porta) ||(l_porta==l3_porta)||l_porta==l4_porta  ||(l1_porta==l2_porta) ||(l1_porta==l3_porta)  ||(l1_porta==l4_porta) ||(l2_porta==l3_porta)||(l2_porta==l4_porta)||l3_porta==l4_porta)||
		            (l_porta > l1_porta+1 ||l_porta < l1_porta-1||l1_porta>l2_porta+1||l1_porta<l2_porta-1||l2_porta>l3_porta+1  ||l2_porta<l3_porta-1 ||l3_porta>l4_porta+1||l3_porta<l4_porta-1)            ||
		            (l_porta < 0  || l_porta > 9)                                                  							 ||
		            (l1_porta < 0 || l1_porta > 9)                                                						 	 ||
		            (l2_porta<0   || l2_porta>9)   																			 ||
					(l3_porta<0   || l3_porta>9)                                                                             ||
					(l4_porta<0   || l4_porta>9)       																		                
            	)
			{
                printf ("Numero(s) invalido(s),TENTE NOVAMENTE:\n");
                Sleep(2000);
                system("cls");
            }else{
            valida++;
            campo[l_porta][c_porta] = 5;
            campo[l1_porta][c_porta] = 5;
            campo[l2_porta][c_porta] = 5;
            campo[l3_porta][c_porta] = 5;
            campo[l4_porta][c_porta] = 5;
            }
        
        }while (valida<1);
    
    
    }else if (sentido == 'h' || sentido == 'H'){
        printf ("Insira a LINHA que deseja colocar o PORTA AVIAO [0 a 9]: ");
        scanf ("%d", &c_porta);
        fflush(stdin);
        do
        {
            printf ("Insira a COLUNA do PORTA AVIAO [0 a 9]: ");
            scanf ("%d", &l_porta);
            printf ("Insira a COLUNA do PORTA AVIAO [0 a 9]: ");
            scanf ("%d", &l1_porta);
            printf ("Insira a COLUNA do PORTA AVIAO [0 a 9]: ");
            scanf ("%d", &l2_porta);
            printf ("Insira a COLUNA do PORTA AVIAO [0 a 9]: ");
            scanf ("%d", &l3_porta);
            printf ("Insira a COLUNA do PORTA AVIAO [0 a 9]: ");
            scanf ("%d", &l4_porta);
            
			fflush(stdin);
        
            if (
					(campo[l_porta][c_porta] != 0 || campo[l1_porta][c_porta] != 0  ||campo[l2_porta][c_porta] != 0  ||campo[l3_porta][c_porta] != 0   ||campo[l3_porta][c_porta] != 0 )       ||
		            ((l_porta == l1_porta)||(l_porta==l2_porta) ||(l_porta==l3_porta)||l_porta==l4_porta  ||(l1_porta==l2_porta) ||(l1_porta==l3_porta)  ||(l1_porta==l4_porta) ||(l2_porta==l3_porta)||(l2_porta==l4_porta)||l3_porta==l4_porta)||
		            (l_porta > l1_porta+1 ||l_porta < l1_porta-1||l1_porta>l2_porta+1||l1_porta<l2_porta-1||l2_porta>l3_porta+1  ||l2_porta<l3_porta-1 ||l3_porta>l4_porta+1||l3_porta<l4_porta-1)            ||
		            (l_porta < 0  || l_porta > 9)                                                  							 ||
		            (l1_porta < 0 || l1_porta > 9)                                                						 	 ||
		            (l2_porta<0   || l2_porta>9)   																			 ||
					(l3_porta<0   || l3_porta>9)                                                                             ||
					(l4_porta<0   || l4_porta>9)       																		        
	        	){
	                printf ("Numero(s) invalido(s),TENTE NOVAMENTE!\n");
	                Sleep(2000);
	                system("cls");
	             }else{
		            valida++;
	            campo[c_porta][l_porta] = 5;
	            campo[c_porta][l1_porta] = 5;
	            campo[c_porta][l2_porta] = 5;
	            campo[c_porta][l3_porta] = 5;
	            campo[c_porta][l4_porta] = 5;
	            }
	        
        }while (valida<1);
    }


}


int verifica_18 (int campo[10][10])
{
	int cont=0,confere,inconfere; 
	
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(campo[i][j]!=0)
				cont++; 
	
	if(cont!=18){
		printf("\t\tREPREENCHA A TABELA!!!!\n");
		Sleep(1000);
		printf("\t\tVerifique se VOCE NAO SOBREPOS ALGUMA EMBARCACAO\n"); 
		Sleep(1000);
		printf("\t\tOU NAO DEU ENTRADA DE DADOS CORRETAMENTE\n"); 
		Sleep(1000);
		printf("\t\tVERIFIQUE A TABELA ACIMA E TENTE NOVAMENTE\n");  
		Sleep(9000); 
		confere=0;
		
	}else{
		printf("\tMuito bem tabela preenchida corretamente!!!\n\n"); 
		confere=1; 
	}
	
	return confere; 

}

void comeca_jogo(int campo[10][10] ,int campo1[10][10],int campojogo[10][10],int campojogo1[10][10])
{
	int cont1,cont2,i,j,num,x,y,repetir1=0,repetir2=0,contatiro1=0,contaacerto1=0,contaacerto2=0,contatiro2=0,jogadorvez=1,jogadorcontra=2; 
	int paratudo1=1,paratudo2=1; 
		
	while(paratudo1==1 && paratudo2==1)
	{
			do{
			Sleep(1000); 	
			system("CLS");
			printf("Jogador 1, voce ATACARA o campo do jogador 2!!!\n");
			
		 
				printf("\n\t\t\t     CAMPO EM BATALHA \n\n"); 
				printf("       0      1      2      3      4      5      6      7      8      9\n\n");
				for(i=0;i<10;i++)
				{
					printf("%d   ",i);
					
					for(j=0; j<10; j++)
					{
							printf("  _%d_  ",campojogo1[i][j]);							
					}
					
					printf("\n\n");
					num++;			
				}
			
			do{
				
			printf("\njogador 1, digite uma CORDENADA DA MALHA ACIMA !!!\n"); 
			printf("Cordenada X: "); 
			scanf("%d",&y); 
			printf("Cordenada Y: "); 
			scanf("%d",&x);
			Sleep(2000);
			system("CLS"); 
				
				if(campo1[x][y]!=0)
				{
					printf("VOCE ACERTOU PARTE DE UMA EMBARCACAO!!!\n\n");
					
					repetir1=1; 
					
					contaacerto1++;
					
					campojogo1[x][y]=campo1[x][y];  
					
					Sleep(3000);
				
				}
					else 
					{
					
					printf("TIRO NA AGUA !!!");
					repetir1=0;
					Sleep(3000);  
					campojogo1[x][y]=8; 
					}
				
				printf("\n\t\t\t     CAMPO EM BATALHA \n\n"); 
				printf("       0      1      2      3      4      5      6      7      8      9\n\n");
				
				for(i=0;i<10;i++)
				{
					printf("%d   ",i);
					
					for(j=0; j<10; j++)
					{
						
						printf("  _%d_  ",campojogo1[i][j]);
									
					}
													
					printf("\n\n");
					num++;		
				}
					
								
				Sleep(4000);
			
				contatiro1++; 
			
			if(contaacerto1==18)
			
			{
				repetir1=0;  
				paratudo1=0;
				paratudo2=0;
				printf("Jogador 1, voce ganhou !!!\n");
				printf("PARABENS VOCE VENCEU A BATALHA\n"); 		
				 
			}
			}while(repetir1==1); 
			
			
		// jogador 2
			
		while(paratudo1==1){
		Sleep(1000);
		system("CLS"); 
		
		printf("Jogador 2 voce ATACARA o campo do jogador 1!!!\n");
				 
		printf("\n\t\t\t     CAMPO EM BATALHA \n\n"); 
				printf("       0      1      2      3      4      5      6      7      8      9\n\n");
				for(i=0;i<10;i++)
				{
					printf("%d   ",i);
					
					for(j=0; j<10; j++)
					{		
							printf("  _%d_  ",campojogo[i][j]);								
					}
					
					printf("\n\n");
					num++;			
				}
			
			do{
				
			printf("\nJOGADOR 2 ,digite uma CORDENADA DA MALHA ACIMA !!!\n"); 
			printf("Cordenada X: "); 
			scanf("%d",&y); 
			printf("Cordenada Y: "); 
			scanf("%d",&x);
			Sleep(1000);
			system("CLS"); 
				
				if(campo[x][y]!=0)
				{
					printf("VOCE ACERTOU PARTE DE UMA EMBARCACAO!!!\n\n");
					repetir2=1; 
					contaacerto2++;
					campojogo[x][y]=campo[x][y];  
					Sleep(3000);
				}
				else 
				{
					printf("TIRO NA AGUA !!!");
					repetir2=0;
					Sleep(3000);  
					campojogo[x][y]=8; 
					paratudo1=0; 
				}
				
				printf("\n\t\t\t     CAMPO EM BATALHA \n\n"); 
				printf("       0      1      2      3      4      5      6      7      8      9\n\n");
				
				for(i=0;i<10;i++)
				{
					printf("%d   ",i);
					
					for(j=0; j<10; j++)
					{
						printf("  _%d_  ",campojogo[i][j]);				
					}
													
					printf("\n\n");
					num++;		
				}
								
					Sleep(4000);
				
				contatiro2++; 
			if(contaacerto2==18)
			{
				paratudo1=0; 
				paratudo2=0; 
				repetir2=0; 
				printf("Jogador 2 voce ganhou !!!\n");
				printf("PARABENS VOCE VENCEU A BATALHA\n");  
				break;   
			}
			}while(repetir2==1); 
	}
}while(repetir2==1||paratudo1==1||paratudo2==1); 

}
	
		Sleep(3000); 
	printf("\n\nRELATORIO: \n"); 
	printf("Numeros de acertos do jogador 1: %d\n",contaacerto1); 
	printf("Numeros de tiros do jogador 1: %d\n",contatiro1); 
	printf("\nNumeros de acertos do jogador 2: %d\n",contaacerto2); 
	printf("Numeros de tiros do jogador 2: %d\n",contatiro2); 
	
	printf("\n\nFim do programa!!!"); 

}
    

main(){
	
	int campopre1[10][10],campopre2[10][10],campojogo1[10][10],campojogo2[10][10],a,jogador1=1,jogador2=2; 
	
	
	
	
	printf("\n\n\t\t\t\t\t\t   BATALHA NAVAL\n\n\n\n");
printf("\t                               o o                                      \n");
printf("\t                                 o ooo\n");
printf("\t                                  o oo         ___      \n");
printf("\t                                      o o      | | #)\n");
printf("\t                                       oo     _|_|_#_\n");
printf("\t                                         o   | U505  |\n");
printf("\t    __                    ___________________|       |____________________  \n");
printf("\t   |   -_______-----------                                                )\n");
printf("\t  >|    _____                                                   Brasil   )\n");
printf("\t   |__ -     ---------_________________________________________________ )\n");


Sleep(2000);


// adicionar navios jogador 1
do
{

	zeromatriz(campopre1);
	 
	printf ("\n                                Digite alguma tecla para COMECAR O JOGO: "); 
	
	getch() ;
	
	
	system("CLS");	
	
	printf("\t\t     Campo jogador 1  virgem:"); 	
		
	exibeCampopre(campopre1,jogador1); 
		
	printf("Digite qualquer tecla para comecar a preencher a tabuleiro 1: "); 
	
	getch(); 
	
	system("CLS"); 
	
	addnavio(campopre1); 
	
	exibeCampopre(campopre1,jogador1); 
	Sleep(4000);
	system("CLS");
	
	addsubmarino(campopre1); 
	
	exibeCampopre(campopre1,jogador1); 
	
	Sleep(4000);
	system("CLS");
	
	addsubmarino(campopre1); 
	
	exibeCampopre(campopre1,jogador1); 
	
	Sleep(4000);
	system("CLS");
	
	addcontratorpedeiro(campopre1); 
	
	exibeCampopre(campopre1,jogador1); 
	
	Sleep(4000);
	system("CLS");
	
	addnaviotanque(campopre1); 
	exibeCampopre(campopre1,jogador1); 
	
	Sleep(4000);
	system("CLS");
	
	addportaaviao(campopre1); 
	exibeCampopre(campopre1,jogador1); 


}while(verifica_18(campopre1) == 0 ); 


Sleep(4000);
system("CLS") ; 
printf("Muito bem, agora o jogador 1 dara espaco para o jogador 2 preencher o tabuleiro !!!\n"); 
Sleep(3000); 
printf("Pronto !?\n"); 
Sleep(3000); 
printf("Vamos comecar!!!\n");
Sleep(3000);

//adicionar navios jogador 2

do
{

	zeromatriz(campopre2); 
		
	system("CLS");	
	
	printf("\t\t     Campo jogador 2 virgem:"); 	
		
		exibeCampopre(campopre2,jogador2); 
		
	printf("Digite qualquer tecla para comecar a preencher a tabuleiro 2: "); 
	
	getch(); 
		
	system("CLS"); 
	
	addnavio(campopre2); 
	
	exibeCampopre(campopre2,jogador2); 
	Sleep(6000);
	system("CLS");
	
	addsubmarino(campopre2); 
	
	exibeCampopre(campopre2,jogador2); 
	
	Sleep(6000);
	system("CLS");
	
	addsubmarino(campopre2); 
	
	exibeCampopre(campopre2,jogador2); 
	
	Sleep(6000);
	system("CLS");
	
	addcontratorpedeiro(campopre2); 
	
	exibeCampopre(campopre2,jogador2); 
	
	Sleep(6000);
	system("CLS");
	
	addnaviotanque(campopre2); 
	exibeCampopre(campopre2,jogador2); 
	
	Sleep(6000);
	system("CLS");
	
	addportaaviao(campopre2); 
	exibeCampopre(campopre2,jogador2); 


}while(verifica_18(campopre2) == 0 ); 

	Sleep(5000); 
	system("CLS"); 
	
    printf("\t\t    ~~~~~~~MUITO BEM JOGADORES VOCES ACABARAM DE PREENCHER OS TABULEIROS!!!~~~~~~~~~\n\n"); 
	Sleep(1000); 
	printf("\t\t                 ~~~~~~~AGORA A GUERRA VAI COMECAR!!!~~~~~~~~\n\n"); 
	Sleep(1000); 
	printf("\t\t                                     INSTRUCOES:                         \n\n"); 
	printf("\t\t                |NAVIO|          REPRESENTADO POR 1 CASA  DE NUMERO  | 1 |    \n"); 
	printf("\t\t              |SUBMARINO|        REPRESENTADO POR 2 CASAS DE NUMERO  | 2 |    \n"); 
	printf("\t\t           |CONTRATORPEDEIRO|    REPRESENTADO POR 3 CASAS DE NUMERO  | 3 |    \n"); 
	printf("\t\t             |NAVIO TANQUE|      REPRESENTADO POR 4 CASAS DE NUMERO  | 4 |    \n"); 
	printf("\t\t              |PORTA AVIAO|      REPRESENTADO POR 5 CASAS DE NUMERO  | 5 |    \n"); 
	printf("\t\t              |LOCAL TIRO|       REPRESENTADO POR 1 CASA  DE NUMERO  | 0 |    \n"); 
	printf("\t\t             |TIRO NA AGUA|      REPRESENTADO POR 1 CASA  DE NUMERO  | 8 |    \n\n"); 
	Sleep(3000);
	printf("\t\t        ~~~~~~~Jogador 1 clique ENTER PARA DAR SEU PRIMEIRO TIRO!!!~~~~~~~~\n\n");
	Sleep(1000); 
	printf("\t\t                    ~~~~~~E QUE A BATALHA COMECE~~~~~~");
	
	getch(); 
	
	zeromatriz( campojogo1); 
	zeromatriz(campojogo2); 
			
	comeca_jogo(campopre1,campopre2, campojogo1,campojogo2); 

	
}




 


