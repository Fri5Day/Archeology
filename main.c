#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

char RespostaChar[20];
char NamePlayer[20];
char Password[20];
int KeyPress,b,L,L2,opcao,i,TimeText = 70;

char SlowText(char* Text)
{
    for (i = 0; Text[i] != '\0'; i++)
    {
        printf("%c",Text[i]);
        Sleep(TimeText);
    }
}

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
    do{
        opcao=0;
        L=2;L2=2;b=2;
        system("cls");
        printf("     \"Menu de op��es\"\n\n      Novo Jogo \n      Escolher Fase\n      GitHub\n      Sair\n");
        do
        {
            coordxy(3,L);
            printf("->");
            coordxy(0,6);
            if(kbhit){KeyPress=getch();}
            if(KeyPress == 80 && b < 5){L2=L;L++;b++;}
            if(KeyPress == 72 && b > 2){L2=L;L--;b--;}
            if(L!=L2){coordxy(2,L2);printf("    \n     ");L2=L;}
            if (KeyPress == 27) {Quit();}
            if(KeyPress == 13){opcao=b-1;}
        }while(opcao == 0);
    switch (opcao){
        case 1:
            system("cls");
            Player();
        case 2:
            system("cls");
            printf("Este � o menu do desenvolvedor, por favor digite sua senha: ");
            gets(Password);
            if ((strcmp (Password, "1234")== 0)){
                printf("Verificando...\n");
                Sleep(1000);
                printf("Voc� ser� direcionado para o menu de escolha de fase, por favor aguarde.");
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
        case 3:
            system("cls");
            printf("Voc� est� sendo direcionado ao nosso projeto no GitHub...");
            Sleep(2000);
            system("start iexplore.exe https://github.com/Gaspor/Archeology");
            Sleep(2000);
            main();
        case 4:
            Quit();
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
        printf("     \"Menu de Fases\"\n\n     Ir para a Fase 1\n     Ir para a Fase 2\n     Ir para a Fase 3\n     Ir para o Boss\n\n     Voltar ao Menu principal\n");
        do
        {
            coordxy(3,L);
            printf("->");
            coordxy(0,8);
            if(kbhit){KeyPress=getch();}
            if(KeyPress == 80 && b < 7){L2=L;L++;b++;}
            if(KeyPress == 72 && b > 2){L2=L;L--;b--;}
            if(L!=L2){coordxy(1,L2);printf("    ");L2=L;}
            if (KeyPress == 27) {Quit();}
            if(KeyPress == 13){Fase=b-1;}
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
            printf("Voc� escolheu ir para a Fase do Boss.\n");
            Sleep(1000);
            printf("Iniciando o Boss...\n");
            Sleep(1500);
            system("cls");
            Boss();
        case 6:
            main();
        default:
            printf("Op��o inv�lida, tente outra");
            Sleep(1000);
        }
    }while(Fase!=2);
}

void Quit()
{
    system("cls");
    printf("\aSaindo...\n");
    Sleep(800);
    exit(0);
}

void GameOver()
{
    char GameOver[] = "Game Over";
    SlowText(GameOver);
    Sleep(2000);
    system("cls");
    main();
}

void Player()
{
    system("cls");
    printf("Por favor n�o aperte nada enquanto o texto � digitado em sua tela.\n");
    printf("Por favor, n�o use caractere especial\n");
    printf("Digite o nome do Arque�logo: ");
    gets(NamePlayer);
    printf("\n\nVoc� deseja pular a Hist�ria? \n Aperte S para Sim.\n Aperte N para N�o.\n");
    if (kbhit) {KeyPress=getch();}
    if (KeyPress == 110) {Lore();}
    if (KeyPress == 115) {Fase1();}
}

void Lore()
{
    system("cls");
    char Texto1[2000] = "   H� muitas eras, no ano 51 A.C, em algum lugar do Egito antigo acontecia uma grande batalha, uma guerra \n\n civil que parecia n�o ter fim. Em meio a todo aquele caos algo brilhava nos c�us, e seu brilho ficava cada vez \n\n mais intenso e mais pr�ximo, at� que esse misterioso brilho se depara com o ch�o, causando um grande alvoro�o em \n\n meio aquelas terras. Todos se esquecem por um minuto daquela guerra e decidem ir ver o que era aquilo. \n\n Depois de um tempo alguns dos soldados descobrem que aquilo era um amuleto ainda intacto, mesmo depois daquela \n\n enorme queda, e sem saber dos seus efeitos acidentalmente um dos soldados aciona esse amuleto, fazendo com que ele \n\n revelasse um poder desconhecido que era capaz de mudar toda a natureza humana. O medo assolava a todos que ali \n\n estavam presentes, muitos fugiram e os que ficaram decidiram que aquele amuleto era perigoso demais para a posse de \n\n qualquer pessoa, e em um ato de desespero constru�ram uma enorme pir�mide em volta do amuleto com diversas armadilhas. \n\n Depois de s�culos, lendas foram criadas e todos chamavam aquele amuleto desconhecido de O olho de Os�ris. \n\nNingu�m se atrevia a entrar naquela pir�mide, pois al�m das armadilhas, muitos diziam que os antigos designaram \n\num guardi�o para a prote��o do amuleto, mas a ganancia humana � grande demais, e em algum dia algu�m tentara \n\ntomar posse desse poderoso artefato. Essa � a lenda que � contada at� os dias de hoje.\n";
    char Texto2[] ="  Voc� � um arque�logo conhecido como";
    char Texto3[] ="ao estudar est� lenda voc� decide ir em busca deste artefato antigo...\n\n  Essa ser� um jornada tortuosa, e para enfim alcan�ar o antigo artefato, voc� ter� que passar pelos mais dif�ceis \ndesafios... \n\n";
    char TextFase1[] = "  Voc� entra na piramide e logo se depara com o primeiro desafio, uma porta com um tipo de tabela com pe�as faltando, \nsem saber o que fazer voc� come�a a andar pela sala.\n\n Andando pela sala voc� encontra uma sacola com 6 letras F's e duas letras V's, depois de encontrar est� sacola voc� \ndecide voltar para a porta, ao voltar voc� logo percebe o que ter� que fazer, voc� ter� que colocar essas letras da \nsacola na porta para passar \n\n";

    SlowText(Texto1);
    printf("\nPressione Enter para continuar...");
    if (kbhit) {KeyPress=getch();}
    if (KeyPress == 13) {
        system("cls");
        SlowText(Texto2);
        printf(" ");
        SlowText(NamePlayer);
        printf(", ");
        SlowText(Texto3);
        SlowText(TextFase1);
        printf("\n\nPressione Enter para continuar...");
        if (kbhit) {KeyPress=getch();}
        if (KeyPress == 13)
            Fase1();
    }
}

void Fase1()
{
    system("cls");
    int Acertos = 0, Vs = 2,Fs = 6;
    do{
        Tabelas:
        opcao=0;
        L=15;L2=15;b=2;
        system("cls");
        printf("Voc� ent�o come�a a completar a tabela...\n");
        coordxy(0,6);
        printf("\t\t\t\t  ========================================\n");
        printf("\t\t\t\t  |   A   B (A^B) B' (B'^A) (A^B)^(B'^A) |\n");
        printf("\t\t\t\t  |       F       V              F       |\n");
        printf("\t\t\t\t  |   F   V   F   F     F                |\n");
        printf("\t\t\t\t  |       F   F   V     V                |\n");
        printf("\t\t\t\t  |   V       V         F        F       |\n");
        printf("\t\t\t\t  ========================================\n\nO que voc� deseja colocar nesta parte da tabela?");
        if (Acertos == 0) {
            coordxy(36,8);
            printf(">");
        }if (Acertos == 1) {
            coordxy(38,8);
            printf("F");
            coordxy(44,8);
            printf(">");
        } if (Acertos == 2) {
            coordxy(38,8);
            printf("F   F   F");
            coordxy(54,8);
            printf(">");
        }if (Acertos == 3) {
            coordxy(38,8);
            printf("F   F   F   V     F");
            coordxy(63,9);
            printf(">");
        } if (Acertos == 4) {
            coordxy(38,8);
            printf("F   F   F   V     F");
            coordxy(38,9);
            printf("F   V   F   F     F        F");
            coordxy(36,10);
            printf(">");
        }if (Acertos == 5) {
            coordxy(38,8);
            printf("F   F   F   V     F");
            coordxy(38,9);
            printf("F   V   F   F     F        F");
            coordxy(38,10);
            printf("V");
            coordxy(63,10);
            printf(">");
        }if (Acertos == 6) {
            coordxy(38,8);
            printf("F   F   F   V     F");
            coordxy(38,9);
            printf("F   V   F   F     F        F");
            coordxy(38,10);
            printf("V   F   F   V     V        F");
            coordxy(40,11);
            printf(">");
        }if (Acertos == 7) {
            coordxy(38,8);
            printf("F   F   F   V     F");
            coordxy(38,9);
            printf("F   V   F   F     F        F");
            coordxy(38,10);
            printf("V   F   F   V     V        F");
            coordxy(38,11);
            printf("V   V   V");
            coordxy(48,11);
            printf(">");
        }
        coordxy(6,15);
        printf("V\n      F");
        printf("\n\nInvent�rio\n Total de F: %d\n Total de V: %d",Fs, Vs);
        do{
            coordxy(3,L);
            printf("->");
            coordxy(10,18);
            if(kbhit){KeyPress=getch();}
            if (KeyPress == 27) {Quit();}
            if(KeyPress == 80 && b < 3){L2=L;L++;b++;}
            if(KeyPress == 72 && b > 2){L2=L;L--;b--;}
            if(L!=L2){coordxy(3,L2);printf("  ");L2=L;}
            if(KeyPress == 13){opcao=b-1;}
        }while(opcao == 0);
    switch (opcao){
        case 1:
            if (Acertos == 4) {
                Vs--;
                system("cls");
                Acertos++;
                goto Tabelas;
            }if (Acertos == 6) {
                Vs--;
                system("cls");
                Acertos++;
                goto Tabelas;
            } else {
                coordxy(1,22);
                printf("Voc� errou!");
                Sleep(2000);
                main();
            }
        case 2:
            if (Acertos == 0) {
                Fs--;
                system("cls");
                Acertos++;
                goto Tabelas;
            }if (Acertos == 1) {
                Fs--;
                system("cls");
                Acertos++;
                goto Tabelas;
            }if (Acertos == 2) {
                Fs--;
                system("cls");
                Acertos++;
                goto Tabelas;
            }if (Acertos == 3) {
                Fs--;
                system("cls");
                Acertos++;
                goto Tabelas;
            }if (Acertos == 5) {
                Fs--;
                system("cls");
                Acertos++;
                goto Tabelas;
            }if (Acertos == 7) {
                Fs--;
                coordxy(50,11);
                printf("F");
                coordxy(1,22);
                char NextFase[] = "A porta se abre e voc� consegue ir pra pr�xima sala.";
                SlowText(NextFase);
                Sleep(1000);
                system("cls");
                Acertos++;
                Fase2();
            } else {
                coordxy(2,19);
                printf("Voc� errou!");
                Sleep(2000);
                main();
            }
        }
    }while(opcao!=2);
}

void ErrorFase2()
{
    char ErroPiso[] ="Voc� pisou em um lugar que n�o era seguro, o ch�o desmoronou, e voc� morreu com a queda.\n";
    SlowText(ErroPiso);
    Sleep(2000);
    GameOver();
}

void Fase2()
{
    int Acertos = 0;
    char Text1[] = " Voc� se depara com uma entrada, anda at� ela e quando est� chegando, o ch�o come�a a tremer. De repente\nvoc� percebe que alguns pisos n�o tremem e eles ser�o o seu caminho at� a entrada.\n";
    char Text2[] = "\n  Para chegar � entrada voc� deve no primeiro piso ir ao m�ximo para a esquerda, no pr�ximo piso voc� deve quadruplicar\na sua posi��o atual, no pr�ximo voc� deve dividir por dois a sua posi��o atual e no �ltimo piso voc� deve somar um a\nsua posi��o atual.\n";
    SlowText(Text1);
    SlowText(Text2);
    Acerto:
    do{
        opcao=0;
        L=41;b=2;
        coordxy(2,0);
        if (Acertos == 0){coordxy(49,7);printf("== Primeiro Piso == \n");}
        if (Acertos == 1){coordxy(49,7);printf("== Segundo Piso == \n");}
        if (Acertos == 2){coordxy(49,7);printf("== Terceiro Piso == \n");}
        if (Acertos == 3){coordxy(49,7);printf(" == Quarto Piso ==  \n");}
        coordxy(19,7);
        printf("\n\t\t\t\t\t\====================================\n\t\t\t\t\t|  1         2         3         4 |\n\t\t\t\t\t|        Posi��o do jogador        |\n\t\t\t\t\t====================================\n");
        do{
            coordxy(L,9);
            printf(">");
            coordxy(0,20);
            if(kbhit){KeyPress=getch();}
            if (KeyPress == 77 && b < 5) {coordxy(L,9);printf(" ");L=L+10;b++;}
            if (KeyPress == 75 && b > 2) {coordxy(L,9);printf(" ");L=L-10;b--;}
            if (KeyPress == 27) {Quit();}
            if(KeyPress == 13){opcao=b-1;}
        }while(opcao == 0);
    switch (opcao){
        case 1:
            if (Acertos == 0)
            {
                char Acerto1[] ="Voc� acertou e passou para o pr�ximo piso           \n";
                Acertos++;
                SlowText(Acerto1);
                goto Acerto;
            } else {
                ErrorFase2();
            }
        case 2:
            if (Acertos == 2)
            {
                char Acerto3[] = "Voc� acertou, por pouco!                            \n";
                Acertos++;
                SlowText(Acerto3);
                goto Acerto;
            } else {
                ErrorFase2();
            }
        case 3:
            if (Acertos == 3)
            {
                char Acerto4[] = "Voc� finalmente passou sem cair em nenhuma armadilha\n";
                SlowText(Acerto4);
                Sleep(3000);
                system("cls");
                Fase3();
            } else {
                ErrorFase2();
            }
        case 4:
            if (Acertos == 1)
            {
                char Acerto2[] = "Voc� acertou, tome cuidado com os pisos falsos      \n";
                Acertos++;
                SlowText(Acerto2);
                goto Acerto;
            } else {
                ErrorFase2();
            }
        }
    }while(opcao!=2);
}

void Fase3()
{
    char Text1Fase3[] = "Voc� passa pela entrada da segunda fase e observa que h� outra entrada, voc� anda at� ela e de repente a entrada se \nfecha e voc� ouve uma voz.\n";
    char Text2Fase3[] = "Eu sou o Deus daquilo que traz a tristeza e o medo, mas sempre chego na hora certa, as vezes venho depois de uma doen�a,\ne outras, depois de um ato de viol�ncia e tamb�m sou guardi�o daquilo que voc� procura, me diga do que eu sou Deus e \nsua passagem ser� liberada.\n";
    char Text3Fase3[] = "Me diga, eu sou Deus da: ";
    SlowText(Text1Fase3);
    SlowText(Text2Fase3);
    SlowText(Text3Fase3);
    gets(RespostaChar);
    if ((strcmp (RespostaChar, "MORTE")== 0)||(strcmp (RespostaChar, "morte")== 0)||(strcmp (RespostaChar, "Morte")== 0)) {
        char Text4Fase3[] = "\nVoc� descobriu do que eu sou Deus, agora me enfrente e ver� o meu poder!\n";
        SlowText(Text4Fase3);
        Sleep(4000);
        system("cls");
        Boss();
    }else {
        char Text5Fase3[] = "\nSe voc� n�o sabe que tipo de Deus eu sou voc� n�o � digno de me enfrentar, saia da minha pir�mide!\n";
        SlowText(Text5Fase3);
        Sleep(6000);
        system("cls");
        main();
    }
}

void Boss()
{
    do{
        char Texto1[] = "An�bis: Voc� chegou at� aqui, mas daqui voc� n�o passa!\nAn�bis: Tente me vencer, voc� precisar� de sorte, muita sorte!\n\n";
        char Texto2[] = "An�bis � um inimigo extremamete poderoso, e para derrot�-lo voc� deve encontrar uma arma poderosa.\n\n";
        SlowText(Texto1);
        SlowText(Texto2);
        Sleep(3000);
        char Texto3[] = "Voc� vai em busca de sua arma para derrotar An�bis, mas derrepente voc� escuta sua voz.\n\n";
        char Texto4[] = "An�bis: Voc� nunca saber� o que � (A->B)<->(B'->A').";
        SlowText(Texto3);
        SlowText(Texto4);
        Sleep(8000);
        BossDoor:
        L=18;b=2;
        system("cls");
        char Texto5[] = "Encontre pela sala o que � a express�o dita por An�bis.\n\n";
        char Texto6[] = "Voc� v� duas pe�as, uma em sua direita e outra em sua esquerda.\nO que voc� deseja fazer ?\n\n";
        SlowText(Texto5);
        SlowText(Texto6);
        printf("\n\t\t\===================================================================================\n\t\t|   Virar para a esquerda       Seguir em frente            Virar para a direita  |\n\t\t===================================================================================\n");
        do{
            opcao=0;
            coordxy(L,7);
            printf(">");
            coordxy(0,20);
            if(kbhit){KeyPress=getch();}
            if (KeyPress == 77 && b < 4) {coordxy(L,7);printf(" ");L=L+28;b++;}
            if (KeyPress == 75 && b > 2) {coordxy(L,7);printf(" ");L=L-28;b--;}
            if (KeyPress == 27) {Quit();}
            if(KeyPress == 13){opcao=b-1;}
        }while(opcao == 0);
    switch(opcao){
        case 1:
            do {
                opcao=0;
                L=18;b=2;
                coordxy(2,0);
                system("cls");
                char Contradicao[] = "Voc� encontrou uma pe�a escrita Contradi��o, o que voc� deseja fazer ?\n";
                SlowText(Contradicao);
                printf("\n\t\t\=================================================================\n\t\t|   Pegar a pe�a e usar         Essa n�o � a pe�a para a arma   |\n\t\t=================================================================\n");
                do{
                    coordxy(L,3);
                    printf(">");
                    coordxy(0,20);
                    if(kbhit){KeyPress=getch();}
                    if (KeyPress == 77 && b < 3) {coordxy(L,3);printf(" ");L=L+28;b++;}
                    if (KeyPress == 75 && b > 2) {coordxy(L,3);printf(" ");L=L-28;b--;}
                    if (KeyPress == 27) {Quit();}
                    if(KeyPress == 13){opcao=b-1;}
                }while(opcao == 0);
            switch(opcao){
                case 1:
                    system("cls");
                    char Contradicao3[] = "Voc� tentou usar a arma Contradi��o para derrotar An�bis...\n\nA arma n�o funcionou e An�bis conseguiu chegar at� voc� e te matou...\n\n";
                    SlowText(Contradicao3);
                    Sleep(5000);
                    GameOver();
                case 2:
                    system("cls");
                    char Contradicao4[] = "Voc� descartou a pe�a Contradi��o e voltou para o inicio.";
                    SlowText(Contradicao4);
                    Sleep(5000);
                    system("cls");
                    goto BossDoor;
                }
            }while(opcao!=2);
        case 2:
            system("cls");
            char MidRoad[] = "Esse n�o era o caminho correto! \n\nVoc� n�o conseguiu reunir as pe�as necess�rias para derrotar An�bis.\n\nEle arrancou a sua cabe�a!!\n\n";
            SlowText(MidRoad);
            Sleep(2000);
            GameOver();
        case 3:
            do{
                system("cls");
                opcao=0;
                L=22;b=2;
                coordxy(2,0);
                system("cls");
                char Tautologia[] = "Voc� encontrou uma pe�a escrita Tautologia, o que voc� deseja fazer ?\n";
                SlowText(Tautologia);
                printf("\n\t\t\    =============================================================\n\t\t    |   Pegar a pe�a e usar                           Descartar |\n\t\t    =============================================================\n");
                do{
                    coordxy(L,3);
                    printf(">");
                    coordxy(0,20);
                    if(kbhit){KeyPress=getch();}
                    if (KeyPress == 77 && b < 3) {coordxy(L,3);printf(" ");L=L+46;b++;}
                    if (KeyPress == 75 && b > 2) {coordxy(L,3);printf(" ");L=L-46;b--;}
                    if (KeyPress == 27) {Quit();}
                    if(KeyPress == 13){opcao=b-1;}
                }while(opcao == 0);
            switch(opcao){
                case 1:
                    system("cls");
                    char Text8[] = "Voc� conseguiu a pe�a correta para a arma.\n\nVoc� termina de montar a arma definitiva para derrotar An�bis e usa contra ele.\n\n";
                    SlowText(Text8);
                    Sleep(2000);
                    printf("Parab�ns %s, voc� venceu!!\n\n", NamePlayer);
                    printf("Obrigado por jogar o Beta.");
                    Sleep(7000);
                    system("cls");
                    main();
                case 2:
                    system("cls");
                    char Text2[] = "Voc� acaba de jogar a arma para derrotar An�bis fora.\n\nVoc� come�a a correr pela sala de An�bis, mas infelizmente ele consegue de pegar...\n\n";
                    SlowText(Text2);
                    Sleep(3500);
                    GameOver();
                }
            }while(opcao!=2);
        }
    }while(opcao!=2);
}
