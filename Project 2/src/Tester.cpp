#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>


using namespace std;

static void swap( int& n1, int& n2 ) {

    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void solution1( int input[], const int n, const int k, int output[] ) {

    int maxIndex, maxValue;
    for ( int i = 0; i < k; i++ ) {
        maxIndex = i;
        maxValue = input[i];
        for ( int j = i+1; j < n; j++ ) {
            if ( input[j] >= maxValue ) {
                maxIndex = j;
                maxValue = input[ j ];
            }
        }
        swap( input[i], input[maxIndex] );
        output[i] = input[i];
    }
}


static void swap2( int& n1, int& n2 ) {

    int temp = n1;
    n1 = n2;
    n2 = temp;
}

static int partition2( int input[], int p, int r ) {

    int x = input[ r ], i = p - 1;
    for ( int j = p; j < r; j++ ) {
        if ( input[ j ] >= x ) {
            i = i + 1;
            swap2( input[i], input[j] );
        }
    }
    swap2( input[i+1], input[r] );
    return i + 1;
}

static void quickSort2( int input[], int p, int r ) {

    int q;
    if ( p < r ) {
        q = partition2( input, p, r );
        quickSort2( input, p, q - 1 );
        quickSort2( input, q + 1, r );
    }
}

void solution2( int input[], const int n, const int k, int output[] ) {
    quickSort2( input, 0, n - 1 );
    for ( int i = 0; i < k; i++ ) {
        output[i] = input[i];
    }
}


static void swap3( int& n1, int& n2 ) {

    int temp = n1;
    n1 = n2;
    n2 = temp;
}

static int partition3( int input[], int a, int p, int r ) {

    int x = a, i = p - 1;
    for ( int j = p; j < r; j++ ) {
        if ( input[ j ] == x ) {
            swap3( input[ j ], input[ r ] );
        }
        if ( input[ j ] >= x ) {
            i = i + 1;
            swap3( input[i], input[j] );
        }
    }
    swap3( input[ i + 1 ], input[ r ] );
    return i + 1;
}

static void quickSort3( int input[], int p, int r ) {

    int q;
    if ( p < r ) {
        q = partition3( input, input[ r ], p, r );
        quickSort3( input, p, q - 1 );
        quickSort3( input, q + 1, r );
    }
}

static int findMin3( int n1, int n2 ) {

    if ( n1 <= n2 )
        return n1;
    else
        return n2;
}

static int select3( int input[], int n, int k, int start, int end, int flag ) {

    if ( n <= 5 ) {
        quickSort3( input, start, end );
        return input[ start + k - 1 ];
    }
    int i = start, numGroups = (int) ceil( ( double ) n / 5 ), numElements, j = 0;
    int *medians = new int[numGroups];
    while ( i <= end ) {
        numElements = findMin3( 5, end - i + 1 );
        medians[( i - start ) / 5] = select3( input, numElements, (int) ceil( ( double ) numElements / 2 ), i, i + numElements - 1, 1 );
        i = i + 5;
    }
    int M = select3( medians, numGroups, (int) ceil( ( double ) numGroups / 2 ), 0, numGroups - 1, 1 );
    delete[] medians;
    if ( flag == 1 )
        return M;
    int q = partition3( input, M, start, end );
    int m = q - start + 1;
    if ( k == m )
        return M;
    else if ( k < m )
        return select3( input, m - 1, k, start, q - 1, 0 );
    else
        return select3( input, end - q, k - m, q + 1, end, 0 );
}

void solution3( int input[], const int n, const int k, int output[] ) {

    select3( input, n, k, 0, n - 1, 0 );
    for( int i = 0; i < k; i++ )
        output[i] = input[i];
}


int main()
{
    char stop;
    do
    {
        int* inputArr1;
        int* inputArr2;
        int* inputArr3;
        int* outputArr;

        cout<< "Enter size for array (bigger than 0): ";
        int arrSize;
        cin >> arrSize;
        srand((unsigned)time(0));

        inputArr1 = new int[arrSize];
        for(int i = 0; i < arrSize; i++)
            inputArr1[i] = (rand()%1000000)+1;

        int k;
        do
        {
            cout<< "Enter a number between 0 and " << arrSize << " (for k): ";
            cin >> k;
            if( k > arrSize || k < 0)
                cout << "This number is not within bounds, please enter a number again." << endl;
            else
                outputArr = new int[k];
        }
        while( k > arrSize || k < 0);

        inputArr2 = new int[arrSize];
        for(int i = 0; i < arrSize; i++)
            inputArr2[i] = inputArr1[i];
        /**/ /* calculate time for solution 1 */
        //Store the starting time
        double duration1;
        clock_t startTime1 = clock();
        //Code block
        solution1(inputArr1, arrSize, k, outputArr);
        //Compute the number of seconds that passed since the starting time
        duration1 = 1000 * double( clock() - startTime1 ) / CLOCKS_PER_SEC;
        cout << "(Solution 1) Execution took " << duration1 << " milliseconds." << endl;
        delete[] inputArr1;
        delete[] outputArr;


        inputArr3 = new int[arrSize];
        for(int i = 0; i < arrSize; i++)
            inputArr3[i] = inputArr2[i];
        outputArr = new int[k];
        /**/ /* calculate time for solution 2 */
        //Store the starting time
        double duration2;
        clock_t startTime2 = clock();
        //Code block
        solution2(inputArr2, arrSize, k, outputArr);
        //Compute the number of seconds that passed since the starting time
        duration2 = 1000 * double( clock() - startTime2 ) / CLOCKS_PER_SEC;
        cout << "(Solution 2) Execution took " << duration2 << " milliseconds." << endl;
        delete [] inputArr2;
        delete [] outputArr;


        outputArr = new int[k];
        /**/ /* calculate time for solution 3 */
        //Store the starting time
        double duration3;
        clock_t startTime3 = clock();
        //Code block
        solution3(inputArr3, arrSize, k, outputArr);
        //Compute the number of seconds that passed since the starting time
        duration3 = 1000 * double( clock() - startTime3 ) / CLOCKS_PER_SEC;
        cout << "(Solution 3) Execution took " << duration3 << " milliseconds." << endl;
        delete [] inputArr3;
        delete [] outputArr;

        cout << "Do you want to continue? (Y or N): ";
        cin >> stop;
        cout << endl;
    }
    while( stop == 'Y' || stop == 'y');

    return 0;
}
