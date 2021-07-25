#include <math.h>

static void swap( int& n1, int& n2 ) {

    int temp = n1;
    n1 = n2;
    n2 = temp;
}

static int partition( int input[], int a, int p, int r ) {

    int x = a, i = p - 1;
    for ( int j = p; j < r; j++ ) {
        if ( input[ j ] == x ) {
            swap( input[ j ], input[ r ] );
        }
        if ( input[ j ] >= x ) {
            i = i + 1;
            swap( input[i], input[j] );
        }
    }
    swap( input[ i + 1 ], input[ r ] );
    return i + 1;
}

static void quickSort( int input[], int p, int r ) {

    int q;
    if ( p < r ) {
        q = partition( input, input[ r ], p, r );
        quickSort( input, p, q - 1 );
        quickSort( input, q + 1, r );
    }
}

static int findMin( int n1, int n2 ) {

    if ( n1 <= n2 )
        return n1;
    else
        return n2;
}

static int select( int input[], int n, int k, int start, int end, int flag ) {

    if ( n <= 5 ) {
        quickSort( input, start, end );
        return input[ start + k - 1 ];
    }
    int i = start, numGroups = (int) ceil( ( double ) n / 5 ), numElements, j = 0;
    int *medians = new int[numGroups];
    while ( i <= end ) {
        numElements = findMin( 5, end - i + 1 );
        medians[( i - start ) / 5] = select( input, numElements, (int) ceil( ( double ) numElements / 2 ), i, i + numElements - 1, 1 );
        i = i + 5;
    }
    int M = select( medians, numGroups, (int) ceil( ( double ) numGroups / 2 ), 0, numGroups - 1, 1 );
    delete[] medians;
    if ( flag == 1 )
        return M;
    int q = partition( input, M, start, end );
    int m = q - start + 1;
    if ( k == m )
        return M;
    else if ( k < m )
        return select( input, m - 1, k, start, q - 1, 0 );
    else
        return select( input, end - q, k - m, q + 1, end, 0 );
}

void solution3( int input[], const int n, const int k, int output[] ) {

    select( input, n, k, 0, n - 1, 0 );
    for( int i = 0; i < k; i++ )
        output[i] = input[i];
}
