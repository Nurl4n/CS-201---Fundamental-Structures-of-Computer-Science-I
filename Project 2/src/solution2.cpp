static void swap( int& n1, int& n2 ) {

    int temp = n1;
    n1 = n2;
    n2 = temp;
}

static int partition( int input[], int p, int r ) {

    int x = input[ r ], i = p - 1;
    for ( int j = p; j < r; j++ ) {
        if ( input[ j ] >= x ) {
            i = i + 1;
            swap( input[i], input[j] );
        }
    }
    swap( input[i+1], input[r] );
    return i + 1;
}

static void quickSort( int input[], int p, int r ) {

    int q;
    if ( p < r ) {
        q = partition( input, p, r );
        quickSort( input, p, q - 1 );
        quickSort( input, q + 1, r );
    }
}

void solution2( int input[], const int n, const int k, int output[] ) {

    quickSort( input, 0, n - 1 );
    for ( int i = 0; i < k; i++ ) {
        output[i] = input[i];
    }
}
