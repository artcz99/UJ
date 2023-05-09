#include <iostream>

using namespace std;

int main () {
    int x;
    cin >> x;
    int i = 1;
    if ( x <= 0 ) {
    } else {
        while ( i <= x ) {
            float max = 0;
            float min = 0;
            float avg = 0;
            float a, b, c, d, e;
            cin >> a >> b >> c >> d >> e;
            avg = (a+b+c+d+e)/5;
            max = a;
            if ( max < b )
                max = b;
            if ( max < c )
                max = c;
            if ( max < d )
                max = d;
            if ( max < e )
                max = e;
            min = a;
            if ( min > b )
                min = b;
            if ( min > c )
                min = c;
            if ( min > d )
                min = d;
            if ( min > e )
                min = e;
            cout << min << " " << max << " " << avg << endl;
            i++;
        }

    }
}