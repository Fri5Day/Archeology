#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

char RespostaChar[20];
char NomeJogador[20];
int a,b,L,L2,Password;

void coordxy(int x,int y)
{
    COORD Mouse;
    Mouse.X = x;
    Mouse.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Mouse);
}

void main()
{
    setlocale(LC_ALL,"Portuguese");
    int opcao;
    do{
        opcao=0;
        L=2;L2=2;b=2;
        system("cls");
        printf("     \"Menu de op��es\"\n\n      Novo Jogo \n      Escolher Fase\n\n      Sair\a\n");
        do
        {
            coordxy(3,L);
            printf("->");
            coordxy(0,6);
            if(kbhit){
                a=getch();
            }if(a == 80 && b < 5){
                L2=L;L++;b++;
            }if(a == 72 && b > 2){
                L2=L;L--;b--;
            }if(L!=L2){
                coordxy(2,L2);printf("    \n     ");L2=L;
            }if(a == 13){
                opcao=b-1;
            }
        }while(opcao == 0);
    switch (opcao){
        case 1:
            system("cls");
            Fase1();
        case 2:
            system("cls");
            printf("Este � o menu do desenvolvedor, por favor digite sua senha: ");
            scanf("%d", &Password);
            if (Password == 1234) {
                printf("Verificando...\n");
                Sleep(1000);
                printf("Voc� ser� direcionado para o menu de escolha de fase, por favor aguarde.\a");
                Sleep(2000);
                system("cls");
                SelectFase();
            } else {
                printf("Verificando...\n");
                Sleep(1000);
                printf("Senha incorreta.");
                Sleep(700);
                system("cls");
                main();
            }
        case 4:
            system("cls");
            printf("\aVoc� escolheu sair\n");
            printf("\aSaindo...\n");
            Sleep(800);
            exit(0);
        default:
            printf("Essa op��o n�o existe, por favor tente uma nova.\n");
            Sleep(1500);
        }
    }while(opcao!=2);
}

void SelectFase()
{
    int Fase;
    do{
        Fase=0;
        L=2;L2=2;b=2;
        system("cls");
        printf("     \"Menu de Fases\"\n\n     Ir para a Fase 1\n     Ir para a Fase 2\n     Ir para a Fase 3\n     Ir para o Boss\n\n     Voltar ao Menu principal\a\n");
        do
        {
            coordxy(3,L);
            printf("->");
            coordxy(0,8);
            if(kbhit){a=getch();}
            if(a == 80 && b < 7){L2=L;L++;b++;}
            if(a == 72 && b > 2){L2=L;L--;b--;}
            if(L!=L2){coordxy(1,L2);printf("    ");L2=L;}
            if(a == 13){Fase=b-1;}
        }while(Fase == 0);
    switch (Fase){
        case 1:
            system("cls");
            printf("Voc� escolheu ir para a Fase 1.\n");
            Sleep(1000);
            printf("Iniciando a Fase 1...\n");
            Sleep(1500);
            system("cls");
            Fase1();
        case 2:
            system("cls");
            printf("Voc� escolheu ir para a Fase 2.\n");
            Sleep(1000);
            printf("Iniciando a Fase 2...\n");
            Sleep(1500);
            system("cls");
            Fase2();
        case 3:
            system("cls");
            printf("Voc� escolheu ir para a Fase 3.\n");
            Sleep(1000);
            printf("Iniciando a Fase 3...\n");
            Sleep(1500);
            system("cls");
            Fase3();
        case 4:
            system("cls");
            printf("Voc� escoleu ir para a Fase do Boss.\n");
            Sleep(1000);
            printf("Iniciando o Boss...\n");
            Sleep(1500);
            system("cls");
            Boss();
        case 6:
            main();
        }
    }while(Fase!=2);
}

void Fase1()
{
    system("cls");
    printf("Por favor, n�o use espa�o nem caractere especial\n");
    printf("Digite o nome do Arque�logo: \a");
    scanf("%s", NomeJogador);
    system("cls");
    printf("\a   H� muitas eras atr�s no ano 51 A.C, em algum lugar do Egito antigo acontecia uma grande batalha, uma guerra \n civil que parecia n�o ter fim. Em meio a todo aquele caos algo brilhava nos c�us, e seu brilho ficava cada vez \n mais intenso e mais pr�ximo, at� que esse misterioso brilho se depara com o ch�o, causando um grande alvoro�o em \n meio aquelas terras. Todos se esquecem por um minuto daquela guerra e decidem ir ver o que era aquilo. \n Depois de um tempo alguns dos soldados descobrem que aquilo era um amuleto ainda intacto, mesmo depois daquela \n enorme queda, e sem saber dos seus efeitos acidentalmente um dos soldados aciona esse amuleto, fazendo com que ele \n revelasse um poder desconhecido que era capaz de mudar toda a natureza humana. O medo assolava a todos que ali \n estavam presentes, muitos fugiram e os que ficaram decidiram que aquele amuleto era perigoso demais para a posse de \n qualquer pessoa, e em um ato de desespero constru�ram uma enorme pir�mide em volta do amuleto com diversas armadilhas. \n Depois de s�culos, lendas foram criadas e todos chamavam aquele amuleto desconhecido de O olho de Os�ris e ningu�m se \n atrevia a entrar naquela pir�mide, pois al�m das armadilhas, muitos diziam que os antigos designaram um guardi�o para \n a prote��o do amuleto, mas a ganancia humana � grande demais, e em algum dia algu�m tentara tomar posse desse poderoso \n artefato. Essa lenda � contada at� os dias de hoje.\n");
    system("pause");
    system("cls");
    printf("\aVoc� � um arque�logo conhecido como %s, voc� est� em busca de um artefato antigo, mais conhecido como\n 'O olho de Os�ris'..", NomeJogador);
    printf("\n \n");
    printf("Essa jornada ser� tortuosa, e para enfim alcan�ar o antigo artefato, voc� ter� que passar pelos mais dif�ceis desafios.. ");
    printf("\n \n");
    system("pause");
    system("cls");
    printf("Voc� entra na piramide e se depara com o primeiro puzzle.\n\n");
    printf("Voc� encontra tr�s portas, na qual apenas uma � a correta.\n\n");
    printf("\aDescubra o padr�o para avan�ar para a pr�xima fase...\n\n");
    system("pause");
    system("cls");
    printf("No pilar central est� entalhado o seguinte s�mbolo: (A^B) ^ (B'^A)\n\n");
    printf("      Porta da esquerda (A):       |          Porta da meio (B):         |          Porta da direita (C):\n");
    printf(" A B (A^B) B' (B'^A) (A^B)^(B'^A)      A B (AvB) B' (B'vA) (AvB)^(B'vA)      A B (A^B) B' (B'^A) (A^B)^(B'^A)\n\n");
    printf(" F F   V   V    V         V            F F   F   V     V        F            F F   F   V     F        F\n");
    printf(" F V   F   V    F         V            F V   V   F     F        F            F V   F   F     F        F\n");
    printf(" V F   V   F    F         V            V F   V   V     V        V            V F   F   V     V        F\n");
    printf(" V V   F   V    V         V            V V   V   F     V        V            V V   V   F     F        F\n\n");
    printf("Apenas uma das portas � a correta, caso escolha a porta errada voc� cair� em uma armadilha mortal.\n\a");
    system("pause");
    printf("Qual � a porta? ");
    scanf("%s", &RespostaChar);
    if ((strcmp (RespostaChar, "C")== 0) || (strcmp (RespostaChar, "c")== 0)) {
        printf("\aVoc� passou de fase!\n");
        system("pause");
        system("cls");
        Fase2();
    } if ((strcmp (RespostaChar, "A")== 0) || (strcmp (RespostaChar, "a")== 0)) {
        printf("Voc� acaba de entrar em um labirinto, e percebe que n�o consegue encontrar a saida...\n\a");
        system("pause");
        printf("Voc� ficou perdido para todo o sempre\n");
        system("pause");
        printf("\aGame over\n");
        system("pause");
        system("cls");
        main();
    } if ((strcmp (RespostaChar, "B")== 0) || (strcmp (RespostaChar, "b")== 0)) {
        printf("\aVoc� caiu em um po�o que n�o possui fundo!\n");
        system("pause");
        printf("\aVoc� caiu por toda a eternidade...\n");
        system("pause");
        printf("\aGame over\n");
        system("pause");
        system("cls");
        main();
    } else {
        printf("A porta que voc� tentou usar n�o existe.\n");
        system("pause");
        system("cls");
        main();
    }
}

void Fase2()
{
    printf("Voc� se depara com uma entrada, anda at� ela e quando est� chegando, o ch�o come�a a tremer. De repente\nvoc� percebe que alguns pisos n�o tremem e eles ser�o o seu caminho at� a entrada.\n");
    printf("\n\t===============================\n");
    printf("\t| Entrada para a pr�xima fase |\n");
    printf("\t|   1       2       3       4 |\n");
    printf("\t|A  1A      2A      3A      4A|\n");
    printf("\t|B  1B      2B      3B      4B|\n");
    printf("\t|C  1C      2C      3C      4C|\n");
    printf("\t|D  1D      2D      3D      4D|\n");
    printf("\t|      Posi��o do jogador     |\n");
    printf("\t===============================\n");
    printf("Para chegar � entrada voc� deve no primeiro piso ir ao m�ximo para a esquerda, no pr�ximo piso voc� deve quadruplicar\na sua posi��o atual, no pr�ximo voc� deve dividir por dois a sua posi��o atual e no �ltimo piso voc� deve somar um a\nsua posi��o atual\n");
    printf("Qual o caminho correto? ");
    scanf("%s", &RespostaChar);
    if ((strcmp (RespostaChar, "1D4C2B3A")== 0) || (strcmp (RespostaChar, "1d4c2b3a")== 0)) {
        printf("Vo�� passou de fase\n");
        system("pause");
        system("cls");
        Fase3();
    } else {
        printf("Voc� pisou em um lugar que n�o era seguro, o ch�o desmoronou e voc� morreu com a queda.\n");
        Sleep(1000);
        printf("Gameover\a\n");
        Sleep(1000);
        main();
    }
}

void Fase3()
{
    printf("Voc� passa pela entrada da segunda fase e observa que h� outra entrada, voc� anda at� ela e de repente a entrada se \nfecha e voc� ouve uma voz.\n");
    printf("Eu sou o Deus daquilo que traz a tristeza e o medo, mas sempre chego na hora certa, as vezes venho depois de uma doen�a,\ne outras, depois de um ato de viol�ncia e tamb�m sou guardi�o daquilo que voc� procura, me diga do que eu sou Deus e \nsua passagem ser� liberada.\n");
    printf("Me diga, eu sou Deus da: ");
    scanf("%s", &RespostaChar);
    if ((strcmp (RespostaChar, "MORTE")== 0)||(strcmp (RespostaChar, "morte")== 0)||(strcmp (RespostaChar, "Morte")== 0)) {
        printf("\n");
        printf("Voc� descobriu do que eu sou Deus, agora me enfrente e ver� o meu poder!\n");
        system("pause\n");
        system("cls\n");
        Boss();
    }else {
        printf("\n");
        printf("Se voc� n�o sabe que tipo de Deus eu sou voc� n�o � digno de me enfrentar, saia da minha pir�mide!\n");
        system("pause\n");
        system("cls\n");
        main();
    }
}

void Boss()
{
    printf("A fase do Boss est� em constru��o, volte um outro dia!\n");
    system("pause");
    system("cls");
    main();
}
