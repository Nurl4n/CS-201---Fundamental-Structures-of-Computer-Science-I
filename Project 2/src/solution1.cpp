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
