/*
    Write a program that reads a text and display its noisy version 10 times.                                                                                                                    in python
    (텍스트를 입력받아 noise가 추가된 텍스트를 10번 출력하는 프로그램을 작성하시오.)
        - DO NOT delete or modify the algorithms

    Example) Input a text: God loves you and has a wonderful plan for your life!
        God loves you and has a wonderful plan for your life!
        G.d.l.v...you .nd h.s.a .....rfu...... .o..y.ur .if.!
        ... ...e..y...an. has . wo.d.rful pl.n f.. .our li.e.
        ..d....e..y.u ... ha. a w....rfu...l.n.fo. y.u..li.e.
        ..d...ve..yo. .nd..as.a..o....... p.a. ..r .our lif.!
        ..d lov....ou..nd has a wo...rfu..pla..f.r.y.u...i..!
        ....l..e..y.u..nd .a. a......r..l.pl.n for .....l.fe.
        ....loves.y.u.a.d ..s.a .onde.f.l p.a..... y.u. lif.!
        .....ov.s..ou a.....s . wond....l .l.n..or .o.r....e.
        God .ov...y....n..has ..w...e.fu...l.n f.r.y... l.fe!
        God.l......ou.and has a w..de.f.. p.a. .o..y.ur.li..!

    Example) Input a text: I love you! God loves you!
        I love you! God loves you!
        . love.y.u!.G...love..you.
        . lov. you. .o. .o.es..o..
        . lo.e ..u...o. ..ves .ou.
        I ..ve .ou......l.ves ..u.
        I..... yo.. Go. l.v.s .o.!
        I..ov. yo.!.Go..l...s ..u.
        I ..v....u!.G.. ..v.s yo..
        I.l.....o.. G.d ..ve. y.u!
        I.love y..! ... l..e..you.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() // convert this into python without explanation
{
    // TO DO: initialize the random seed using the current time
    srand(time(NULL));
    char text[128] = "";
    char ft[128];

    // read a text line
    printf("Input a text: ");
    fgets(text, 127, stdin);
    text[strlen(text) - 1] = 0; // trim '\n'
    printf("%s\n", text);       // display the input text

    int len = strlen(text); // get the length of the input text

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < len; j++)
        {
            int random_number = rand() % 2;

            if (random_number == 0)
            {
                printf(".");
            }
            else
            {
                printf("%c", text[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
