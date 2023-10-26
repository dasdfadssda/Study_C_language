#include <stdio.h>

int main()
{

    // open a file
    FILE *fp = NULL;                // 포인터를 통해 파일에 대해 다이렉트로 값을 선정한다.
    fp = fopen("my_file.txt", "w"); // r은 읽겠다. w는 쓴기, a는 수정

    // write data into file
    for (int i = 0; i <= 10; i++)
        fprintf(fp,"%d", i); // 파일에 입력.
    fprintf(fp,"\n");

    // close the file
    fclose(fp); // 중요하다. 
    return 0;
}
