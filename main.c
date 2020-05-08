#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

char RespostaChar[20], NamePlayer[20], Password[20];
int KeyPress,b,L,opcao,i,TimeText = 1;


void coordxy(int x,int y)
{
    COORD Mouse;
    Mouse.X = x;
    Mouse.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Mouse);
}

void SetaUpDown(La, coordx, BLimite, LOper)
{
    L=La;b=1;
    do{
        coordxy(coordx,L);
        printf("->");
        coordxy(0,20);
        if(kbhit){KeyPress=getch();}
        if(KeyPress == 80 && b < BLimite){coordxy(coordx,L);printf("  ");L+=LOper;b++;}
        if(KeyPress == 72 && b > 1){coordxy(coordx,L);printf("  ");L-=LOper;b--;}
        if (KeyPress == 27) {Quit();}
        if(KeyPress == 13){opcao=b;}
    }while(opcao == 0);
}

void SetaLeftRight(La, coordy, BLimite, LOper)
{
    L=La;b=1;
    do{
        coordxy(L,coordy);
        printf(">");
        coordxy(0,20);
        if(kbhit){KeyPress=getch();}
        if (KeyPress == 77 && b < BLimite) {coordxy(L,coordy);printf(" ");L+=LOper;b++;}
        if (KeyPress == 75 && b > 1) {coordxy(L,coordy);printf(" ");L-=LOper;b--;}
        if (KeyPress == 27) {Quit();}
        if(KeyPress == 13){opcao=b;}
    }while(opcao == 0);
}

char SlowText(char* Text)
{
    for (i = 0; Text[i] != '\0'; i++)
    {
        printf("%c",Text[i]);
        Sleep(TimeText);
    }
}

void main()
{
    PlaySound(TEXT("Menu.wav"),NULL,SND_ASYNC|SND_LOOP);
    setlocale(LC_ALL,"Portuguese");
    system("cls");
    printf("     \"Menu de op��es\"\n\n      Novo Jogo \n      Escolher Fase\n      GitHub\n      Sair\n");
    SetaUpDown(2, 3, 4, 1);

    switch (opcao){
        case 1:
            system("cls");
            Player();
        case 2:
            system("cls");
            printf("  Este � o menu do desenvolvedor, por favor digite sua senha: ");
            gets(Password);
            if ((strcmp (Password, "1234")== 0)){
                printf("  Verificando...\n");
                Sleep(1000);
                printf("  Voc� ser� direcionado para o menu de escolha de fase, por favor aguarde.");
                Sleep(2000);
                system("cls");
                SelectFase();
            } else {
                printf("  Verificando...\n");
                Sleep(1000);
                printf("  Senha incorreta.");
                Sleep(700);
                system("cls");
                main();
            }
        case 3:
            system("cls");
            printf("  Voc� est� sendo direcionado ao nosso projeto no GitHub...");
            Sleep(2000);
            system("start https://github.com/Gaspor/Archeology");
            Sleep(2000);
            main();
        case 4:
            Quit();
        default:
            printf("  Essa op��o n�o existe, por favor tente uma nova.\n");
            Sleep(1500);
    }
}

void SelectFase()
{
    system("cls");
    char EscolherFase[] = "     \"Menu de Fases\"\n\n      Ir para a Fase 1\n      Ir para a Fase 2\n      Ir para a Fase 3\n      Ir para o Boss\n\n      Voltar ao Menu principal\n";
    SetaUpDown(2, 3, 6, 1);

    switch (opcao){
        case 1:
            system("cls");
            printf("   Voc� escolheu ir para a Fase 1.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 1...\n");
            Sleep(1500);
            system("cls");
            Fase1();
        case 2:
            system("cls");
            printf("   Voc� escolheu ir para a Fase 2.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 2...\n");
            Sleep(1500);
            system("cls");
            PlaySound(TEXT("null"),NULL,SND_ASYNC);
            Fase2();
        case 3:
            system("cls");
            printf("   Voc� escolheu ir para a Fase 3.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 3...\n");
            Sleep(1500);
            system("cls");
            PlaySound(TEXT("null"),NULL,SND_ASYNC);
            Fase3();
        case 4:
            system("cls");
            printf("   Voc� escolheu ir para a Fase do Boss.\n");
            Sleep(1000);
            printf("   Iniciando o Boss...\n");
            Sleep(1500);
            system("cls");
            Boss();
        case 6:
            main();
        default:
            printf("  Op��o inv�lida, tente outra");
            Sleep(1000);
    }
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
    char GameOver[] = "   Game Over";
    SlowText(GameOver);
    Sleep(2000);
    system("cls");
    main();
}

void Player()
{
    system("cls");
    printf("  Por favor, n�o aperte nada enquanto o texto � digitado em sua tela.\n");
    printf("  Por favor, n�o use caractere especial\n\n");
    printf("  Digite o nome do Arque�logo: ");
    gets(NamePlayer);
    KbLore:
        coordxy(0,5);
        printf("\n\n Voc� deseja pular a Hist�ria? \n   Aperte S para Sim.\n   Aperte N para N�o.\n");
        if (kbhit) {KeyPress=getch();}
        if (KeyPress == 110) {Lore();}
        if (KeyPress == 115) {Fase1();}
        else {goto KbLore;}
}

void Lore()
{
    system("cls");
    char Texto1[2000] = "   H� muitas eras, no ano 51 A.C, em algum lugar do Egito antigo acontecia uma grande batalha, uma guerra \n\n civil que parecia n�o ter fim. Em meio a todo aquele caos algo brilhava nos c�us, e seu brilho ficava cada vez \n\n mais intenso e mais pr�ximo, at� que esse misterioso brilho se depara com o ch�o, causando um grande alvoro�o em \n\n meio aquelas terras. Todos se esquecem por um minuto daquela guerra e decidem ir ver o que era aquilo. \n\n Depois de um tempo alguns dos soldados descobrem que aquilo era um amuleto ainda intacto, mesmo depois daquela \n\n enorme queda, e sem saber dos seus efeitos acidentalmente um dos soldados aciona esse amuleto, fazendo com que ele \n\n revelasse um poder desconhecido que era capaz de mudar toda a natureza humana. O medo assolava a todos que ali \n\n estavam presentes, muitos fugiram e os que ficaram decidiram que aquele amuleto era perigoso demais para a posse de \n\n qualquer pessoa, e em um ato de desespero constru�ram uma enorme pir�mide em volta do amuleto com diversas armadilhas. \n\n   Depois de s�culos, lendas foram criadas e todos chamavam aquele amuleto desconhecido de O olho de Os�ris. \n\n   Ningu�m se atrevia a entrar naquela pir�mide, pois al�m das armadilhas, muitos diziam que os antigos designaram \n\n um guardi�o para a prote��o do amuleto, mas a ganancia humana � grande demais, e em algum dia algu�m tentara \n\n tomar posse desse poderoso artefato. Essa � a lenda que � contada at� os dias de hoje.\n";
    char Texto2[] ="  Voc� � um arque�logo conhecido como";
    char Texto3[] ="ao estudar est� lenda voc� decide ir em busca deste artefato antigo...\n\n  Essa ser� um jornada tortuosa, e para enfim alcan�ar o antigo artefato, voc� ter� que passar pelos mais dif�ceis \n\n desafios... \n\n";
    char TextFase1[] = "  Voc� entra na piramide e logo se depara com o primeiro desafio, uma porta com um tipo de tabela com pe�as faltando, \n\n sem saber o que fazer voc� come�a a andar pela sala.\n\n Andando pela sala voc� encontra uma sacola com 6 letras F's e duas letras V's, depois de encontrar est� sacola voc� \n\n decide voltar para a porta, ao voltar voc� logo percebe o que ter� que fazer, voc� ter� que colocar essas letras da \n\n sacola na porta para passar \n\n";

    SlowText(Texto1);
    LoreEnter1:
        printf("\n Pressione Enter para continuar...");
        if (kbhit) {KeyPress=getch();}
        if (KeyPress == 13) {
            system("cls");
            SlowText(Texto2);
            printf(" ");
            SlowText(NamePlayer);
            printf(", ");
            SlowText(Texto3);
            SlowText(TextFase1);
            LoreEnter2:
                printf("\n Pressione Enter para continuar...");
                if (kbhit) {KeyPress=getch();}
                if (KeyPress == 13) {Fase1();}
                else {goto LoreEnter2;}
        } else {goto LoreEnter1;}
}

void Fase1()
{
    system("cls");
    PlaySound(TEXT("null"),NULL,SND_ASYNC);
    int Acertos = 0, Vs = 2,Fs = 6;
    Tabelas:
    system("cls");
    printf(" Voc� ent�o come�a a completar a tabela...\n");
    coordxy(0,6);
    printf("\t\t\t\t  ========================================\n");
    printf("\t\t\t\t  |   A   B (A^B) B' (B'^A) (A^B)^(B'^A) |\n");
    printf("\t\t\t\t  |       F       V              F       |\n");
    printf("\t\t\t\t  |   F   V   F   F     F                |\n");
    printf("\t\t\t\t  |       F   F   V     V                |\n");
    printf("\t\t\t\t  |   V       V         F        F       |\n");
    printf("\t\t\t\t  ========================================\n\n O que voc� deseja colocar nesta parte da tabela?");
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
    printf("\n\n Invent�rio\n  Total de F: %d\n  Total de V: %d",Fs, Vs);
    SetaUpDown(15, 3, 2, 1);

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
                coordxy(2,22);
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
                char NextFase[] = " A porta se abre e voc� consegue ir pra pr�xima sala.";
                SlowText(NextFase);
                Sleep(1000);
                system("cls");
                Acertos++;
                Fase2();
            } else {
                coordxy(2,22);
                printf("Voc� errou!");
                Sleep(2000);
                main();
            }
    }
}

void ErrorFase2()
{
    char ErroPiso[] ="   Voc� pisou em um lugar que n�o era seguro, o ch�o desmoronou, e voc� morreu com a queda.\n";
    SlowText(ErroPiso);
    Sleep(2000);
    GameOver();
}

void Fase2()
{
    int Acertos = 0;
    char Text1[] = "   Voc� se depara com uma entrada, anda at� ela e quando est� chegando, o ch�o come�a a tremer. De repente\nvoc� percebe que alguns pisos n�o tremem e eles ser�o o seu caminho at� a entrada.\n";
    char Text2[] = "\n   Para chegar � entrada voc� deve no primeiro piso ir ao m�ximo para a esquerda, no pr�ximo piso voc� deve quadruplicar\na sua posi��o atual, no pr�ximo voc� deve dividir por dois a sua posi��o atual e no �ltimo piso voc� deve somar um a\nsua posi��o atual.\n";
    SlowText(Text1);
    SlowText(Text2);
    Acerto:
        coordxy(2,0);
        if (Acertos == 0){coordxy(49,7);printf("== Primeiro Piso == \n");}
        if (Acertos == 1){coordxy(49,7);printf("== Segundo Piso == \n");}
        if (Acertos == 2){coordxy(49,7);printf("== Terceiro Piso == \n");}
        if (Acertos == 3){coordxy(49,7);printf(" == Quarto Piso ==  \n");}
        coordxy(19,7);
        printf("\n\t\t\t\t\t\====================================\n\t\t\t\t\t|  1         2         3         4 |\n\t\t\t\t\t|        Posi��o do jogador        |\n\t\t\t\t\t====================================\n");
        SetaLeftRight(41, 9, 4, 10);

        switch (opcao){
            case 1:
                if (Acertos == 0)
                {
                    char Acerto1[] ="   Voc� acertou e passou para o pr�ximo piso           \n";
                    Acertos++;
                    SlowText(Acerto1);
                    goto Acerto;
                } else {
                    ErrorFase2();
                }
            case 2:
                if (Acertos == 2)
                {
                    char Acerto3[] = "   Voc� acertou, por pouco!                            \n";
                    Acertos++;
                    SlowText(Acerto3);
                    goto Acerto;
                } else {
                    ErrorFase2();
                }
            case 3:
                if (Acertos == 3)
                {
                    char Acerto4[] = "   Voc� finalmente passou sem cair em nenhuma armadilha\n";
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
                    char Acerto2[] = "   Voc� acertou, tome cuidado com os pisos falsos      \n";
                    Acertos++;
                    SlowText(Acerto2);
                    goto Acerto;
                } else {
                    ErrorFase2();
                }
        }
}

void Fase3()
{
    char Text1Fase3[] = "   Voc� passa pela entrada da segunda fase e observa que h� outra entrada, voc� anda at� ela e de repente a entrada se \n\n fecha e voc� ouve uma voz.\n\n";
    char Text2Fase3[] = "   \"Eu sou o Deus daquilo que traz a tristeza e o medo, mas sempre chego na hora certa, as vezes venho depois de \n\n uma doen�a, e outras, depois de um ato de viol�ncia e tamb�m sou guardi�o daquilo que voc� procura, me diga do que \n\n eu sou Deus e sua passagem ser� liberada.\"\n\n";
    char Text3Fase3[] = "   Me diga, eu sou Deus da: ";
    SlowText(Text1Fase3);
    SlowText(Text2Fase3);
    SlowText(Text3Fase3);
    gets(RespostaChar);
    if ((strcmp (RespostaChar, "MORTE")== 0)||(strcmp (RespostaChar, "morte")== 0)||(strcmp (RespostaChar, "Morte")== 0)) {
        char Text4Fase3[] = "\n   Voc� descobriu do que eu sou Deus, agora me enfrente e ver� o meu poder!\n";
        SlowText(Text4Fase3);
        Sleep(4000);
        system("cls");
        Boss();
    }else {
        char Text5Fase3[] = "\n   Se voc� n�o sabe que tipo de Deus eu sou voc� n�o � digno de me enfrentar, saia da minha pir�mide!\n";
        SlowText(Text5Fase3);
        Sleep(6000);
        system("cls");
        main();
    }
}

void Boss()
{
    PlaySound(TEXT("Boss.wav"),NULL,SND_ASYNC|SND_LOOP);
    char Texto1[] = "   An�bis: Voc� chegou at� aqui, mas daqui voc� n�o passa!\n   An�bis: Tente me vencer, voc� precisar� de sorte, muita sorte!\n\n";
    char Texto2[] = "   An�bis � um inimigo extremamete poderoso, e para derrot�-lo voc� deve encontrar uma arma poderosa.\n\n";
    SlowText(Texto1);
    SlowText(Texto2);
    Sleep(3000);
    char Texto3[] = "   Voc� vai em busca de sua arma para derrotar An�bis, mas derrepente voc� escuta sua voz.\n\n";
    char Texto4[] = "   An�bis: Voc� nunca saber� o que � (A->B)<->(B'->A').\n\n";
    SlowText(Texto3);
    SlowText(Texto4);
    AnubisEnter1:
    printf("\n   Aperte enter se j� tiver memorizado a espress�o dita por An�bis.");
    if (kbhit) {KeyPress=getch();}
    if (KeyPress == 27) {Quit();}
    if (KeyPress == 13) {
        BossDoor:
        system("cls");
        char Texto5[] = "   Encontre pela sala o que � a express�o dita por An�bis.\n\n";
        char Texto6[] = "   Voc� v� duas pe�as, uma em sua direita e outra em sua esquerda.\n\n   O que voc� deseja fazer ?\n\n";
        SlowText(Texto5);
        SlowText(Texto6);
        printf("\t\t\===================================================================================\n\t\t|   Virar para a esquerda       Seguir em frente            Virar para a direita  |\n\t\t===================================================================================\n");
        SetaLeftRight(18, 7, 3, 28);

        switch(opcao){
            case 1:
                    coordxy(2,0);
                    system("cls");
                    char Contradicao[] = "   Voc� encontrou uma pe�a escrita Contradi��o, o que voc� deseja fazer ?\n";
                    SlowText(Contradicao);
                    printf("\n\t\t\=================================================================\n\t\t|   Pegar a pe�a e usar         Essa n�o � a pe�a para a arma   |\n\t\t=================================================================\n");
                    SetaLeftRight(18, 3, 2, 28);

                    switch(opcao){
                        case 1:
                            system("cls");
                            char Contradicao3[] = "   Voc� tentou usar a arma Contradi��o para derrotar An�bis...\n\n   A arma n�o funcionou e An�bis conseguiu chegar at� voc� e te matou...\n\n";
                            SlowText(Contradicao3);
                            Sleep(5000);
                            GameOver();
                        case 2:
                            coordxy(0,10);
                            char Contradicao4[] = "   Voc� descartou a pe�a Contradi��o e voltou para o inicio.";
                            SlowText(Contradicao4);
                            Sleep(5000);
                            system("cls");
                            goto BossDoor;
                    }
            case 2:
                system("cls");
                char MidRoad[] = "   Esse n�o era o caminho correto! \n\n   Voc� n�o conseguiu reunir as pe�as necess�rias para derrotar An�bis.\n\n   Ele arrancou a sua cabe�a!!\n\n";
                SlowText(MidRoad);
                Sleep(2000);
                GameOver();
            case 3:
                    system("cls");
                    coordxy(2,0);
                    system("cls");
                    char Tautologia[] = "   Voc� encontrou uma pe�a escrita Tautologia, o que voc� deseja fazer ?\n";
                    SlowText(Tautologia);
                    printf("\n\t\t\    =============================================================\n\t\t    |   Pegar a pe�a e usar                           Descartar |\n\t\t    =============================================================\n");
                    SetaLeftRight(22, 3, 2, 46);

                    switch(opcao){
                        case 1:
                            system("cls");
                            char Text8[] = "   Voc� conseguiu a pe�a correta para a arma.\n\n   Voc� termina de montar a arma definitiva para derrotar An�bis e usa contra ele.\n\n";
                            SlowText(Text8);
                            Sleep(2000);
                            printf("   Parab�ns %s, voc� venceu!!\n\n", NamePlayer);
                            printf("   Obrigado por jogar o Beta.");
                            Sleep(7000);
                            system("cls");
                            main();
                        case 2:
                            system("cls");
                            char Text2[] = "   Voc� acaba de jogar a arma para derrotar An�bis fora.\n\n   Voc� come�a a correr pela sala de An�bis, mas infelizmente ele consegue te pegar...\n\n";
                            SlowText(Text2);
                            Sleep(3500);
                            GameOver();
                    }
        }
    } else {goto AnubisEnter1;}
}
