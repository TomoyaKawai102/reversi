#include <stdio.h>
#define SIZE 8

typedef struct
{
    int c_stone;
}
player;

player players[2];
int board[SIZE][SIZE];
int MAX_TURN = 100;


//プロトタイプ宣言セクション
void reset_board(void);
int reversi(int x, int y, int my_num, int opponent_num);
int turn_end();
int check_XY(int x, int y);

int main(void)
{
    //盤面初期化
    reset_board();

    int my_num;
    int opponent_num;
    int i = 1;
    int x;
    int y;

    while (i <= MAX_TURN)
    {
        if( i % 2 == 0 )
        {
            my_num = 2;
            opponent_num = 1;

        }
        else
        {
            my_num = 1;
            opponent_num = 2;
        }

            do
            {
                printf("プレイヤー%iさん、石を配置するx座標を入力してください\n", my_num);
                scanf("%i", &x);
                printf("プレイヤー%iさん、石を配置するy座標を入力してください\n", my_num);
                scanf("%i", &y);
            } while (check_XY(x, y) == 1 || reversi(x, y, my_num, opponent_num) == 1);
            reversi(x, y, my_num, opponent_num);
            i++;

            int j;
            int k;
            for (j = 1; j <= 6; j++)
            {
                for (k = 1; k <= 6; k++)
                {
                    printf("%2i", board[j][k]);
                }
                printf("\n");
            }

            if (turn_end() == 0)
            {
                break;
            }
    }
}

    //printf("%i, %i\n", x, y);


void reset_board(void)
{
    int j = 0;
    int i = 0;
    for (i = 0; i <= 7; i++)
    {
        board[0][i] = 0;
        board[7][i] = 0;
        board[i][0] = 0;
        board[i][7] = 0;
        //printf("%i", board[i][i]);
    }

    for (j = 1; j <= 6; j++)
    {
        for (i = 1; i <= 6; i++)
        {
            board[j][i] = 0;
            //printf("%2i", board[j][i]);
        }
        //printf("\n");
    }

    board[3][3] = 1;
    board[4][4] = 1;
    board[3][4] = 2;
    board[4][3] = 2;

    // for (j = 1; j <= 6; j++)
    // {
    //     for (i = 1; i <= 6; i++)
    //     {
    //         printf("%2i", board[j][i]);
    //     }
    //     printf("\n");
    // }
}

int reversi(x, y, my_num, opponent_num)
{
    //横軸プラス方向探索
    int i = 1;
    if (board[y][x + i] == opponent_num)
    {
        while (board[y][x + i] == opponent_num)
        {
            board[y][x + i] = my_num;
            i++;
        }

        if (board[y][x + i] == 0)
        {
            while (i != 0)
            {
                i--;
                board[y][x + i] = opponent_num;
            }
        }
        else
        {
            board[y][x] = my_num;
            return (0);
        }

    }

    //横軸マイナス方向探索
    i = -1;
    if (board[y][x + i] == opponent_num)
    {
        while (board[y][x + i] == opponent_num)
        {
            board[y][x + i] = my_num;
            i--;
        }

        if (board[y][x + i] == 0)
        {
            while (i != 0)
            {
                i++;
                board[y][x + i] = opponent_num;
            }
        }
        else
        {
            board[y][x] = my_num;
            return (0);
        }

    }
    //縦軸プラス方向探索
    i = 1;
    if (board[y + i][x] == opponent_num)
    {
        while (board[y + i][x] == opponent_num)
        {
            board[y + i][x] = my_num;
            i++;
        }

        if (board[y + i][x] == 0)
        {
            while (i != 0)
            {
                i--;
                board[y + i][x] = opponent_num;
            }
        }
        else
        {
            board[y][x] = my_num;
            return (0);
        }

    }

    //縦軸マイナス方向探索
    i = -1;
    if (board[y + i][x] == opponent_num)
    {
        while (board[y + i][x] == opponent_num)
        {
            board[y + i][x] = my_num;
            i--;
        }

        if (board[y + i][x] == 0)
        {
            while (i != 0)
            {
                i++;
                board[y + i][x] = opponent_num;
            }
        }
        else
        {
            board[y][x] = my_num;
            return (0);
        }

    }
    else
    {
        return (1);
    }

    //右上斜め探索
    //右下斜め探索
    //左上斜め探索
    //左下斜め探索

    return (0);
}

int turn_end()
{
    return (1);
}

int check_XY(int x, int y)
{
    if (board[y][x] == 0)
    {
        return (0);
    }

    return (1);
}