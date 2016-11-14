#include "graphs_dll.hpp"
#include <string>


// =======  DENSE GRAPH =======
Dense_graph::Dense_graph(int num_of_vertices) : graph_size(num_of_vertices)
{
    if(num_of_vertices <= 0)
        throw std::string("Wrong graph size.");

    adjacency_matrix = new double*[graph_size];
    for(int z=0; z<graph_size; z++)
    {
        adjacency_matrix[z] = new double[graph_size];
        for(int x=0; x<graph_size; x++)
            adjacency_matrix[z][x] = 0;
    }
}

Dense_graph::Dense_graph(Dense_graph &graph) : graph_size(graph.graph_size)
{
    adjacency_matrix = new double*[graph_size];
    for(int z=0; z<graph_size; z++)
    {
        adjacency_matrix[z] = new double[graph_size];
        for(int x=0; x<graph_size; x++)
            adjacency_matrix[z][x] = graph.adjacency_matrix[z][x];
    }
}

Dense_graph::Dense_graph(Dense_graph &&graph) : graph_size(graph.graph_size)
{
    adjacency_matrix = graph.adjacency_matrix;
    graph.adjacency_matrix = nullptr;
}

Dense_graph::~Dense_graph()
{
    for(int z=0; z<graph_size; z++)
        delete[] adjacency_matrix[z];
    delete[] adjacency_matrix;
}

void Dense_graph::add_edge(int p, int q, double weight)
{
    if(weight <= 0)
        throw std::string("Forbidden edge weight.");
    if(p<0 || p>graph_size-1 || q<0 || q>graph_size-1)
        throw std::string("Wrong number of vertix.");

    adjacency_matrix[p][q] = weight;
    adjacency_matrix[q][p] = weight;
}

void Dense_graph::remove_edge(int p, int q)
{
    if(p<0 || p>graph_size-1 || q<0 || q>graph_size-1)
        throw std::string("Wrong number of vertix.");

    adjacency_matrix[p][q] = 0;
    adjacency_matrix[q][p] = 0;
}

void Dense_graph::change_edge_weight(int p, int q, double weight)
{
    if(weight <= 0)
        throw std::string("Forbidden edge weight.");
    if(p<0 || p>graph_size-1 || q<0 || q>graph_size-1)
        throw std::string("Wrong number of vertix.");
    if(adjacency_matrix[p][q] == 0)
        throw std::string("Edge does not exist.");

    adjacency_matrix[p][q] = weight;
    adjacency_matrix[q][p] = weight;
}

std::list<int> Dense_graph::get_connections(int vertix)
{
    if(vertix<0 || vertix>graph_size-1)
        throw std::string("Vertix does not exist.");

    std::list<int> *connections = new std::list<int>();

    for(int z=0; z<graph_size; z++)
        if(adjacency_matrix[z][vertix] != 0)
            connections->push_back(z);

    return *connections;
}

Dense_graph & Dense_graph::operator=(Dense_graph &graph)
{
    if(graph.graph_size != graph_size)
        throw std::string("Graphs have different size.");

    this->~Dense_graph();

    adjacency_matrix = new double*[graph_size];
    for(int z=0; z<graph_size; z++)
    {
        adjacency_matrix[z] = new double[graph_size];
        for(int x=0; x<graph_size; x++)
            adjacency_matrix[z][x] = graph.adjacency_matrix[z][x];
    }

    return *this;
}

Dense_graph & Dense_graph::operator=(Dense_graph &&graph)
{
    if(graph.graph_size != graph_size)
        throw std::string("Graphs have different size.");

    this->~Dense_graph();

    adjacency_matrix = graph.adjacency_matrix;
    graph.adjacency_matrix = nullptr;

    return *this;
}

std::istream & operator>>(std::istream &in, Dense_graph &graph)
{
    int num, p, q, weight;
    in>>num;
    for(int z=0; z<num; z++)
    {
        in>>p>>q>>weight;
        try
        {
            graph.add_edge(p,q,weight);
        }
        catch(std::string ex)
        {
            throw ex;
        }
    }

    return in;
}

std::ostream & operator<<(std::ostream &out, const Dense_graph &graph)
{
    for(int z=0; z<graph.graph_size; z++)
    {
        for(int x=0; x<graph.graph_size; x++)
        {
            out<<graph.adjacency_matrix[z][x];
            if(x<graph.graph_size-1)
                out<<' ';
        }
        out<<'\n';
    }

    return out;
}

// ===== dense iterators =====

Dense_graph::Dense_vertix_iterator::Dense_vertix_iterator(int max_index, int start) : max_index(max_index)
{
    index = start;
}

Dense_graph::Dense_vertix_iterator Dense_graph::Dense_vertix_iterator::operator++(int)
{
    Dense_vertix_iterator it(max_index, index);
    index++;
    return it;
}

Dense_graph::Dense_vertix_iterator Dense_graph::Dense_vertix_iterator::operator++()
{
    index++;
    return *this;
}

bool Dense_graph::Dense_vertix_iterator::operator==(const Dense_vertix_iterator& dvi)
{
    return index == dvi.index;
}

bool Dense_graph::Dense_vertix_iterator::operator!=(const Dense_vertix_iterator& dvi)
{
    return index != dvi.index;
}

Dense_graph::Dense_edge_iterator::Dense_edge_iterator(double **ptr, int max_index, int p, int q) : max_index(max_index)
{
    this->p=p;
    this->q=q;
    matrix = ptr;
}

Dense_graph::Dense_edge_iterator::~Dense_edge_iterator()
{
    matrix = nullptr;
}

Dense_graph::Dense_edge_iterator Dense_graph::Dense_edge_iterator::operator++(int)
{
    Dense_edge_iterator it(matrix, max_index, p, q);
    if(q < max_index-1)
        q++;
    else
    {
        p++;
        q=p;
    }
    while(p<max_index && matrix[p][q] == 0)
    {
        if(q < max_index-1)
            q++;
        else
        {
            p++;
            q=p;
        }
    }
    return it;
}

Dense_graph::Dense_edge_iterator Dense_graph::Dense_edge_iterator::operator++()
{
    if(q < max_index-1)
        q++;
    else
    {
        p++;
        q=p;
    }
    while(p<max_index && matrix[p][q] == 0)
    {
        if(q < max_index-1)
            q++;
        else
        {
            p++;
            q=p;
        }
    }
    return *this;
}

Edge Dense_graph::Dense_edge_iterator::operator*()
{
    Edge edg(p,q,matrix[p][q]);
    return edg;
}

bool Dense_graph::Dense_edge_iterator::operator==(const Dense_edge_iterator& dei)
{
    return p==dei.p && q==dei.q;
}

bool Dense_graph::Dense_edge_iterator::operator!=(const Dense_edge_iterator& dei)
{
    return p!=dei.p || q!=dei.q;
}

Dense_graph::Dense_vertix_iterator Dense_graph::vertices_begin()
{
    Dense_graph::Dense_vertix_iterator it(graph_size, 0);
    return it;
}
Dense_graph::Dense_vertix_iterator Dense_graph::vertices_end()
{
    Dense_graph::Dense_vertix_iterator it(graph_size, graph_size);
    return it;
}
Dense_graph::Dense_edge_iterator Dense_graph::edges_begin()
{
    int p=0, q=0;
    while(p<graph_size && adjacency_matrix[p][q] == 0)
    {
        if(q < graph_size-1)
            q++;
        else
        {
            p++;
            q=p;
        }
    }
    Dense_graph::Dense_edge_iterator it(adjacency_matrix, graph_size, p, q);
    return it;
}
Dense_graph::Dense_edge_iterator Dense_graph::edges_end()
{
    Dense_graph::Dense_edge_iterator it(adjacency_matrix, graph_size, graph_size, graph_size);
    return it;
}

// ======= THIN GRAPH =======

Thin_graph::Thin_graph(int num_of_vertices) : graph_size(num_of_vertices)
{
    if(num_of_vertices <= 0)
        throw std::string("Wrong graph size.");

    adjacency_list = new std::vector<std::vector<std::pair<int,double>>>;
    std::vector<std::pair<int,double>> temp;
    for(int z=0; z<graph_size; z++)
        adjacency_list->push_back(temp);
}

Thin_graph::Thin_graph(Thin_graph &graph) : graph_size(graph.graph_size)
{
    adjacency_list = new std::vector<std::vector<std::pair<int,double>>>;
    std::vector<std::pair<int,double>> temp;
    for(int z=0; z<graph_size; z++)
    {
        adjacency_list->push_back(temp);
        for(auto it=(*graph.adjacency_list)[z].begin(); it!=(*graph.adjacency_list)[z].end(); it++)
            (*adjacency_list)[z].push_back(*it);
    }
}

Thin_graph::Thin_graph(Thin_graph &&graph) : graph_size(graph.graph_size)
{
    adjacency_list = graph.adjacency_list;
    graph.adjacency_list = nullptr;
}

Thin_graph::~Thin_graph()
{
    delete adjacency_list;
}

bool Thin_graph::check_edge(int p, int q)
{
    int n = (*adjacency_list)[p].size();
    for(int z=0; z<n; z++)
        if((*adjacency_list)[p][z].first == q)
            return true;
    return false;
}

void Thin_graph::add_edge(int p, int q, double weight)
{
    if(weight <= 0)
        throw std::string("Forbidden edge weight.");
    if(p<0 || p>graph_size-1 || q<0 || q>graph_size-1)
        throw std::string("Wrong number of vertix.");

    if(!this->check_edge(p,q))
    {
        std::pair<int,double> pair1(q,weight);
        (*adjacency_list)[p].push_back(pair1);
        pair1.first=p;
        (*adjacency_list)[q].push_back(pair1);
    }
    else
    {
        int i=0;
        while((*adjacency_list)[p][i].first != q)
            i++;
        (*adjacency_list)[p][i].second = weight;

        i=0;
        while((*adjacency_list)[q][i].first != p)
            i++;
        (*adjacency_list)[q][i].second = weight;
    }
}

void Thin_graph::remove_edge(int p, int q)
{
    if(p<0 || p>graph_size-1 || q<0 || q>graph_size-1)
        throw std::string("Wrong number of vertix.");

    if(this->check_edge(p,q))
    {
        int i=0;
        while((*adjacency_list)[p][i].first != q)
            i++;
        (*adjacency_list)[p].erase((*adjacency_list)[p].begin() + i);

        i=0;
        while((*adjacency_list)[q][i].first != p)
            i++;
        (*adjacency_list)[q].erase((*adjacency_list)[q].begin() + i);
    }
}

void Thin_graph::change_edge_weight(int p, int q, double weight)
{
    if(weight <= 0)
        throw std::string("Forbidden edge weight.");
    if(p<0 || p>graph_size-1 || q<0 || q>graph_size-1)
        throw std::string("Wrong number of vertix.");
    if(!this->check_edge(p,q))
        throw std::string("Edge does not exist.");

    int i=0;
    while((*adjacency_list)[p][i].first != q)
        i++;
    (*adjacency_list)[p][i].second = weight;

    i=0;
    while((*adjacency_list)[q][i].first != p)
        i++;
    (*adjacency_list)[q][i].second = weight;
}

std::list<int> Thin_graph::get_connections(int vertix)
{
    if(vertix<0 || vertix>graph_size-1)
        throw std::string("Vertix does not exist.");

    std::list<int> *connections = new std::list<int>();

    for(auto it=(*adjacency_list)[vertix].begin(); it!=(*adjacency_list)[vertix].end(); it++)
        connections->push_back((*it).first);

    return *connections;
}

Thin_graph & Thin_graph::operator=(Thin_graph &graph)
{
    if(graph.graph_size != graph_size)
        throw std::string("Graphs have different size.");

    this->~Thin_graph();

    adjacency_list = new std::vector<std::vector<std::pair<int,double>>>;
    std::vector<std::pair<int,double>> temp;
    for(int z=0; z<graph_size; z++)
    {
        adjacency_list->push_back(temp);
        for(auto it=(*graph.adjacency_list)[z].begin(); it!=(*graph.adjacency_list)[z].end(); it++)
            (*adjacency_list)[z].push_back(*it);
    }

    return *this;
}

Thin_graph & Thin_graph::operator=(Thin_graph &&graph)
{
    if(graph.graph_size != graph_size)
        throw std::string("Graphs have different size.");

    this->~Thin_graph();

    adjacency_list = graph.adjacency_list;
    graph.adjacency_list = nullptr;

    return *this;
}

std::istream & operator>>(std::istream &in, Thin_graph &graph)
{
    int num, p, q, weight;
    in>>num;
    for(int z=0; z<num; z++)
    {
        in>>p>>q>>weight;
        try
        {
            graph.add_edge(p,q,weight);
        }
        catch(std::string ex)
        {
            throw ex;
        }
    }

    return in;
}

std::ostream & operator<<(std::ostream &out, const Thin_graph &graph)
{
    for(int z=0; z<graph.graph_size; z++)
    {
        out<<z<<": ";
        for(auto it=(*graph.adjacency_list)[z].begin(); it!=(*graph.adjacency_list)[z].end(); it++)
        {
            out<<'('<<(*it).first<<';'<<(*it).second<<") ";
        }
        out<<'\n';
    }

    return out;
}

// ===== thin iterators =====

Thin_graph::Thin_vertix_iterator::Thin_vertix_iterator(int max_index, int start) : max_index(max_index)
{
    index = start;
}

Thin_graph::Thin_vertix_iterator Thin_graph::Thin_vertix_iterator::operator++(int)
{
    Thin_vertix_iterator it(max_index, index);
    index++;
    return it;
}

Thin_graph::Thin_vertix_iterator Thin_graph::Thin_vertix_iterator::operator++()
{
    index++;
    return *this;
}

bool Thin_graph::Thin_vertix_iterator::operator==(const Thin_vertix_iterator& tvi)
{
    return index == tvi.index;
}

bool Thin_graph::Thin_vertix_iterator::operator!=(const Thin_vertix_iterator& tvi)
{
    return index != tvi.index;
}

Thin_graph::Thin_edge_iterator::Thin_edge_iterator(std::vector< std::vector< std::pair<int,double> > > *ptr, int max_index, int p, int q) : max_index(max_index)
{
    this->p=p;
    this->q=q;
    it_list = ptr;
}

Thin_graph::Thin_edge_iterator::~Thin_edge_iterator()
{
    it_list = nullptr;
}

Thin_graph::Thin_edge_iterator Thin_graph::Thin_edge_iterator::operator++(int)
{
    Thin_edge_iterator it(it_list, max_index, p, q);
    if(p<max_index)
    {
        if(q < int((*it_list)[p].size()-1))
            q++;
        else
        {
            q=0;
            p++;
            while(p<max_index && (*it_list)[p].size() == 0)
                p++;
        }
        while(p<max_index && (*it_list)[p][q].first<p)
        {
            if(q < int((*it_list)[p].size()-1))
                q++;
            else
            {
                q=0;
                p++;
                while(p<max_index && (*it_list)[p].size() == 0)
                    p++;
            }
        }
    }
    return it;
}

Thin_graph::Thin_edge_iterator Thin_graph::Thin_edge_iterator::operator++()
{
    if(p<max_index)
    {
        if(q < int((*it_list)[p].size()-1))
            q++;
        else
        {
            q=0;
            p++;
            while(p<max_index && (*it_list)[p].size() == 0)
                p++;
        }
        while(p<max_index && (*it_list)[p][q].first<p)
        {
            if(q < int((*it_list)[p].size()-1))
                q++;
            else
            {
                q=0;
                p++;
                while(p<max_index && (*it_list)[p].size() == 0)
                    p++;
            }
        }
    }
    return *this;
}

Edge Thin_graph::Thin_edge_iterator::operator*()
{
    Edge edg(p,q,(*it_list)[p][q].second);
    return edg;
}

bool Thin_graph::Thin_edge_iterator::operator==(const Thin_edge_iterator& tei)
{
    return p==tei.p && q==tei.q;
}

bool Thin_graph::Thin_edge_iterator::operator!=(const Thin_edge_iterator& tei)
{
    return p!=tei.p || q!=tei.q;
}

Thin_graph::Thin_vertix_iterator Thin_graph::vertices_begin()
{
    Thin_graph::Thin_vertix_iterator it(graph_size, 0);
    return it;
}
Thin_graph::Thin_vertix_iterator Thin_graph::vertices_end()
{
    Thin_graph::Thin_vertix_iterator it(graph_size, graph_size);
    return it;
}
Thin_graph::Thin_edge_iterator Thin_graph::edges_begin()
{
    int p=0, q=0;
    while(p<graph_size && (*adjacency_list)[p].size() == 0)
        p++;

    Thin_graph::Thin_edge_iterator it(adjacency_list, graph_size, p, q);
    return it;
}
Thin_graph::Thin_edge_iterator Thin_graph::edges_end()
{
    Thin_graph::Thin_edge_iterator it(adjacency_list, graph_size, graph_size, 0);
    return it;
}
