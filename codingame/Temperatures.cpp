//https://www.codingame.com/ide/puzzle/temperatures

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    auto temps = std::vector<int>();
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        temps.emplace_back( t );
    }

    if( !temps.empty() ) {
        int lowest = temps.front();

        for( auto it = std::next( temps.begin(), 1 ); it != temps.end(); ++it ) {
            if( abs( *it ) == abs( lowest ) ) {
                lowest = ( lowest > 0 ? lowest : *it );
            } else if( abs( *it ) < abs( lowest ) ) {
                lowest = *it;
            }
        }

        cout << lowest << endl;

    } else {
        cout << 0 << endl;
    }
} 
