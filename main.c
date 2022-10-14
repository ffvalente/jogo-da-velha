#include<stdio.h>
#include<stdlib.h>


void tela();
void jogada();
void validarJogada();
void validarJogo();
void limpaTela();

char map[3][3] = {{' ',' ',' '},
                  {' ',' ',' '},
                  {' ',' ',' '},};


int posL, posC;  // Linha e Coluna
int jogador = 0; // 0 = Jogador O e 1 = Jogador X
int loop = 1;    // loop = 0 fim do while

int main(int argc, char const *argv[])
{
    tela();
    while (loop == 1)
    {

        jogada();
        tela();
        validarJogo();
        printf("\n");

    }

    return 0;
}

void tela(){

    limpaTela(); // para função funcionar, vai depender do sistema operacional utilizado, melhor explicação na linha 59

    printf("  0 1 2\n");

    for(int i = 0; i < 3; i++){

        printf("%d",i);
        for(int j = 0; j < 3; j++){

            printf("|");
            printf("%c", map[i][j]);

        }
        printf("|");
        printf("\n");
    }
    printf("\n");

}

void limpaTela(){
    system("cls"); // Modificar para system("clear") caso for usar em linux;
}

void jogada(){

    posL = 10;
    posC = 10;

    if(jogador == 0) printf("Vez do 'O'\n\n");
    else printf("Vez do 'X'\n\n");

    printf("Digite a linha: ");
    scanf("%d",&posL);
    setbuf(stdin, NULL);
    printf("Digite a coluna: ");
    scanf("%d",&posC);
    setbuf(stdin, NULL);

        if(!isdigit(posL + '0') && !isdigit(posC + '0')){
            printf("\Apenas numeros de 0 a 2 sao validos, Digite novamente!\n");
            jogada();
        }

        if(posL >=0 && posL <= 2 && posC >= 0 && posC <= 2){ //validando se o número é de 0 a 2
            validarJogada();
        }else{
            printf("\Apenas numeros de 0 a 2 sao validos, Digite novamente!\n");
            jogada();
        }

}

void validarJogada(){        //validando posição para mudar de jogador

    if(map[posL][posC] == ' '){
        if(jogador == 0){
            map[posL][posC] = 'O';
            jogador = 1;
        }else{
            map[posL][posC] = 'X';
            jogador = 0;
        }

    }else{
        printf("Jogada Invalida!\n");
        jogada();
    }

}

void validarJogo(){ //validar vencedor, continuade ou fim do jogo


    if(map[0][0] == 'X' && map[0][1] == 'X' && map[0][2] == 'X'){
        loop = 0;
        printf("Jogador X venceu!");
        return;
    }
    if(map[1][0] == 'X' && map[1][1] == 'X' && map[1][2] == 'X'){
        loop = 0;
        printf("Jogador X venceu!");
        return;
    }
    if(map[2][0] == 'X' && map[2][1] == 'X' && map[2][2] == 'X'){
        loop = 0;
        printf("Jogador 'X venceu!");
        return;
    }
    if(map[0][0] == 'X' && map[1][0] == 'X' && map[2][0] == 'X'){
        loop = 0;
        printf("Jogador X venceu!");
        return;
    }
    if(map[0][1] == 'X' && map[1][1] == 'X' && map[2][1] == 'X'){
        loop = 0;
        printf("Jogador X venceu!");
        return;
    }
    if(map[0][2] == 'X' && map[1][2] == 'X' && map[2][2] == 'X'){
        loop = 0;
        printf("Jogador X venceu!");
        return;
    }
    if(map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X'){
        loop = 0;
        printf("Jogador X venceu!");
        return;
    }
    if(map[0][2] == 'X' && map[1][1] == 'X' && map[2][0] == 'X'){
        loop = 0;
        printf("Jogador X venceu!");
        return;
    }



     if(map[0][0] == 'O' && map[0][1] == 'O' && map[0][2] == '0'){
        loop = 0;
        printf("Jogador O venceu!");
        return;
    }
    if(map[1][0] == 'O' && map[1][1] == 'O' && map[1][2] == 'O'){
        loop = 0;
        printf("Jogador O venceu!");
        return;
    }
    if(map[2][0] == 'O' && map[2][1] == 'O' && map[2][2] == 'O'){
        loop = 0;
        printf("Jogador O venceu!");
        return;
    }
    if(map[0][0] == 'O' && map[1][0] == 'O' && map[2][0] == 'O'){
        loop = 0;
        printf("Jogador O venceu!");
        return;
    }
    if(map[0][1] == 'O' && map[1][1] == 'O' && map[2][1] == 'O'){
        loop = 0;
        printf("Jogador O venceu!");
        return;
    }
    if(map[0][2] == 'O' && map[1][2] == 'O' && map[2][2] == 'O'){
        loop = 0;
        printf("Jogador O venceu!");
        return;
    }
    if(map[0][0] == 'O' && map[1][1] == 'O' && map[2][2] == 'O'){
        loop = 0;
        printf("Jogador O venceu!");
        return;
    }
    if(map[0][2] == 'O' && map[1][1] == 'O' && map[2][0] == 'O'){
        loop = 0;
        printf("Jogador O venceu!");
        return;
    }

    printf("\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(map[i][j] == ' ') return;
        }
    }

    loop = 0;
    printf("Deu velha!");
    printf("\n");

    return 0;
}
