package com.fra.jalgo.ch05;
// import javafx.util.Pair;
// import java.util.List;
import java.util.ArrayList;
import java.util.Collections;


class Pair<T> {
    private T a;
    private T b;
    Pair(T aa, T bb) {a = aa; b = bb;};
    public T fst() { return a;}
    public T snd() { return b;}
}

class Triple<T> extends Pair<T> {
    // private T a;
    // private T b;
    private T c;
    Triple(T aa, T bb, T cc) 
    {
        super(aa, bb);
        c = cc;
    };

    public T thr() { return c;}
}

public class GraphTest {

    // static public <T> void print_parent_list(ArrayList<T> lst) {
    //     for (int idx=0; idx<lst.size(); idx++) {
    //         System.out.printf("node: %d, parent: %d\n", idx, lst.get(idx));
    //     }
    // }

    static public <T> void print_list(ArrayList<T> lst) {
        for (int idx=0; idx<lst.size(); idx++) {
            System.out.printf("node: %d, value: %d\n", idx, lst.get(idx));
        }
    }
    
    static public void read_graph_Test01() {
        var isdirected = false;
        var weighted = true;
        var G = Graph.read_graph(isdirected, weighted);
        G.insert_edge(0, 5, 1, true);
        G.show_adj_list();
    }

    static public void read_wgraph_Test02() {
        var isdirected = false;
        var weighted = true;
        var G = Graph.read_graph(isdirected, weighted);
        // add vertices
        G.insert_edge(0, 1, 1, isdirected);
        // G.show_adj_list();
        G.insert_edge(5, 3, 5, isdirected);
        G.show_adj_list();
    }

    static public void BFS_Test01() {
        var isdirected = false;
        var weighted = true;
        var G = Graph.read_graph(isdirected, weighted);
        int start_id = 0;
        GraphSearch.BFS(G, start_id);
    }

    static public void DFS_Test01() {
        var isdirected = false;
        var weighted = true;
        var G = Graph.read_graph(isdirected, weighted);
        int start_id = 0;
        GraphSearch.DFS(G, start_id);
    }

    static public void DFS_directed_Test01() {
        var isdirected = true;
        var weighted = false;
        var G = Graph.read_graph(isdirected, weighted);
        int start_id = 0;
        GraphSearch.DFS(G, start_id);
    }

    // static public void DFS_directed_ucc() {
    //     var isdirected = true;
    //     var weighted = false;
    //     var G = Graph.read_graph(isdirected, weighted);
    //     GraphSearch.UCC(G);
    // }

    static public void DFS_undirected_ucc() {
        var isdirected = false;
        var weighted = false;
        var G = Graph.read_graph(isdirected, weighted);
        GraphSearch.UCC(G);
    }

    static public void BFS_undirected_shortest_path() {
        var isdirected = false;
        var weighted = false;
        var G = Graph.read_graph(isdirected, weighted);
        int start_id = 0;
        int dst_id = 1;
        // create a list of parent nodes
        ArrayList<Integer> parents = new ArrayList<>(
                Collections.nCopies(G.get_nvertices(), -1)
                );
        // shortest path for unweighted graph
        GraphSearch.shortest_path(G, start_id, dst_id, parents);
        print_list(parents);
        // deermine path length
        for (int id=0; id<G.get_nvertices(); id++) {
            int len = 0;
            int next = parents.get(id);
            while (next != -1) {
                next = parents.get(next);
                len++;
            }
            System.out.printf("path length from %d = %d\n", id, len);
        }
    }

    // TODO: Kosaraju SCC directed graph 

    // TODO
    // static public void DFS_topograph() {
    //     var isdirected = true;
    //     var weighted = false;
    //     var G = Graph.read_graph(isdirected, weighted);
    //     int start_id = 0;
    //     ArrayList<Integer> fvalues = new ArrayList<>(
    //             Collections.nCopies(G.get_nvertices(), -1)
    //             );
    //     GraphSearch.toposort(G, fvalues, start_id);
    //     print_list(fvalues);

    // }
}
