#include <iostream>
#include "graphs_dll.hpp"

int main()
{
    Dense_graph dgraph(5);
    dgraph.add_edge(0,2,7);
    dgraph.add_edge(1,2,6);
    dgraph.remove_edge(0,2);
    dgraph.add_edge(3,2,5);
    dgraph.change_edge_weight(3,2,4);

    Dense_graph dgraph2(5);
    dgraph2 = dgraph;
    std::cout<<dgraph2<<'\n';

    int sum=0;
    for(auto it=dgraph.edges_begin(); it!=dgraph.edges_end(); it++)
    {
        sum+=(*it).weight;
    }
    std::cout<<sum<<"\n\n\n";

    Thin_graph tgraph(5);
    tgraph.add_edge(0,2,7);
    tgraph.add_edge(1,2,6);
    tgraph.remove_edge(0,2);
    tgraph.add_edge(3,2,5);
    tgraph.change_edge_weight(3,2,4);


    Thin_graph tgraph2(5);

    tgraph2 = tgraph;
    std::cout<<tgraph<<'\n';

    sum=0;
    for(auto it=tgraph.edges_begin(); it!=tgraph.edges_end(); it++)
    {
        sum+=(*it).weight;
    }
    std::cout<<sum<<'\n';
    return 0;
}
