#ifndef __GRAPHS_DLL_HPP__
#define __GRAPHS_DLL_HPP__

#include <list>
#include <vector>
#include <iostream>

class Edge;

class Graph
{
public:
    virtual void add_edge(int p, int q, double weight=1.0) = 0;
    virtual void remove_edge(int p, int q) = 0;
    virtual void change_edge_weight(int p, int q, double weight) = 0;
    virtual std::list<int> get_connections(int p) = 0;
    virtual int get_size() = 0;
};

class Dense_graph : public Graph
{
private:
    double **adjacency_matrix;
    const int graph_size;
public:
    Dense_graph(int num_of_vertices);
    Dense_graph(Dense_graph &graph);
    Dense_graph(Dense_graph &&graph);
    ~Dense_graph();
public:
    void add_edge(int p, int q, double weight=1.0);
    void remove_edge(int p, int q);
    void change_edge_weight(int p, int q, double weight);
    std::list<int> get_connections(int vertix);
    inline int get_size() { return graph_size; }
public:
    Dense_graph & operator=(Dense_graph &graph);
    Dense_graph & operator=(Dense_graph &&graph);
public:
    friend std::istream & operator>>(std::istream &we, Dense_graph &graph);
    friend std::ostream & operator<<(std::ostream &wy, const Dense_graph &graph);
public:

    class Dense_vertix_iterator
    {
        friend Dense_graph;
    private:
        int index;
        const int max_index;
        Dense_vertix_iterator(int max_index, int start);
    public:
        Dense_vertix_iterator operator++(int);
        Dense_vertix_iterator operator++();
        inline int operator*() { return index; }
        bool operator==(const Dense_vertix_iterator& dvi);
        bool operator!=(const Dense_vertix_iterator& dvi);
    };

    class Dense_edge_iterator
    {
        friend Dense_graph;
    private:
        int p, q;
        const int max_index;
        double **matrix;
        Dense_edge_iterator(double **ptr, int max_index, int p, int q);
    public:
        ~Dense_edge_iterator();
        Dense_edge_iterator operator++(int);
        Dense_edge_iterator operator++();
        Edge operator*();
        bool operator==(const Dense_edge_iterator& dei);
        bool operator!=(const Dense_edge_iterator& dei);
    };

public:
    Dense_vertix_iterator vertices_begin();
    Dense_vertix_iterator vertices_end();
    Dense_edge_iterator edges_begin();
    Dense_edge_iterator edges_end();
};

class Thin_graph : public Graph
{
private:
    std::vector< std::vector< std::pair<int,double> > > *adjacency_list;
    const int graph_size;
private:
    bool check_edge(int p, int q);
public:
    Thin_graph(int num_of_vertices);
    Thin_graph(Thin_graph &graph);
    Thin_graph(Thin_graph &&graph);
    ~Thin_graph();
public:
    void add_edge(int p, int q, double weight=1.0);
    void remove_edge(int p, int q);
    void change_edge_weight(int p, int q, double weight);
    std::list<int> get_connections(int vertix);
    inline int get_size() { return graph_size; }
public:
    Thin_graph & operator=(Thin_graph &graph);
    Thin_graph & operator=(Thin_graph &&graph);
public:
    friend std::istream & operator>>(std::istream &in, Thin_graph &graph);
    friend std::ostream & operator<<(std::ostream &out, const Thin_graph &graph);
public:

    class Thin_vertix_iterator
    {
        friend Thin_graph;
    private:
        int index;
        const int max_index;
        Thin_vertix_iterator(int max_index, int start);
    public:
        Thin_vertix_iterator operator++(int);
        Thin_vertix_iterator operator++();
        inline int operator*() { return index; }
        bool operator==(const Thin_vertix_iterator& tvi);
        bool operator!=(const Thin_vertix_iterator& tvi);
    };

    class Thin_edge_iterator
    {
        friend Thin_graph;
    private:
        int p, q;
        const int max_index;
        std::vector< std::vector< std::pair<int,double> > > *it_list;
        Thin_edge_iterator(std::vector< std::vector< std::pair<int,double> > > *ptr, int max_index, int p, int q);
    public:
        ~Thin_edge_iterator();
        Thin_edge_iterator operator++(int);
        Thin_edge_iterator operator++();
        Edge operator*();
        bool operator==(const Thin_edge_iterator& tei);
        bool operator!=(const Thin_edge_iterator& tei);
    };

public:
    Thin_vertix_iterator vertices_begin();
    Thin_vertix_iterator vertices_end();
    Thin_edge_iterator edges_begin();
    Thin_edge_iterator edges_end();
};

class Edge
{
    friend Dense_graph;
    friend Thin_graph;
private:
    Edge(int p, int q, int weight) : p(p), q(q), weight(weight) {}
public:
    int p;
    int q;
    int weight;
};

#endif // __GRAPHS_DLL_HPP__
