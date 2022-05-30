//https://www.codingame.com/training/medium/death-first-search-episode-1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

struct Candidate {
    bool operator >( const Candidate & c ) const {
        return this->weight > c.weight;
    }

    int weight;
    int from;
    int to;
};

auto cmp = [](const Candidate & lhs, const Candidate & rhs) { return lhs.weight > rhs.weight; };

void findVirus( 
    std::unordered_map<int, std::vector<int>> &nodes, 
    std::set<int> &visited, 
    priority_queue<Candidate, std::vector<Candidate>, greater<Candidate>> &candidates, 
    int depth,
    int curr_node, 
    int virus_loc ) 
{
    if( visited.find( curr_node ) != visited.end() ) {
        return;
    }

    visited.emplace( curr_node );
    auto & neighbours = nodes.at( curr_node );

    for( auto it = neighbours.begin(); it != neighbours.end(); ++it ) {
        if( *it == virus_loc ) {
            candidates.push( Candidate { depth, curr_node, *it } );
            return;

        } else {
            findVirus( nodes, visited, candidates, depth + 1, *it, virus_loc );
        }
    }
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    auto nodes    = std::unordered_map<int, std::vector<int>>();
    auto gateways = std::vector<int>();

    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();
    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore();

        if( nodes.find( n1 ) != nodes.end() ) {
            nodes.at( n1 ).emplace_back( n2 );
        } else {
            nodes.emplace( n1, std::vector<int>( { n2 } ) );
        }

        if( nodes.find( n2 ) != nodes.end() ) {
            nodes.at( n2 ).emplace_back( n1 );
        } else {
            nodes.emplace( n2, std::vector<int>( { n1 } ) );
        }
    }
    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        gateways.emplace_back( ei );
    }

    // game loop
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        auto candidates = priority_queue<Candidate, std::vector<Candidate>, greater<Candidate>>();
        
        for( auto gateway : gateways ) {
            auto visisted = std::set<int>();
            findVirus( nodes, visisted, candidates, 1, gateway, si );
        }

        if( !candidates.empty() ) {
            auto & candidate = candidates.top();
            auto & node1_links = nodes.at( candidate.from );
            auto & node2_links = nodes.at( candidate.to );
            
            auto it1 = std::find( node1_links.begin(), node1_links.end(), candidate.to );
            auto it2 = std::find( node2_links.begin(), node2_links.end(), candidate.from );
            
            node1_links.erase( it1 );
            node2_links.erase( it2 );

            cout << candidate.from << " " << candidate.to << endl;
        }
    }
} 
