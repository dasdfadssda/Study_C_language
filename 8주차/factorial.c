factorial(1) = 1
factorial(5) = 5 * 4 * 3 * 2 * 1
factorial(4) = 4 * 3 * 2 * 1

factorial(x) = x * factorial(x-1)

int factorial(int x)
{
    int result = 1;

    for(i = 1; i <= x; i++)
        result *= i;
    
    return result;
}



factorial(5) = 5 * 4 * 3 * 2 * 1
factorial(4) = 4 * 3 * 2 * 1

factorial(1) = 1
factorial(x) = x * factorial(x-1)

int factorial(int x)
{
    if(x == 1)
        return 1;
    else
        return x * factorial(x - 1);
}