package com.fra.jalgo.ch05;
import java.util.ArrayList;
import java.util.List;
// import java.util.LinkedList;
import java.util.HashMap;
import java.util.Scanner;
// import java.io.File;
// import java.io.FileNotFoundException;

class EdgeNode<T> {
    public T id;
    public int weight;
    public T next;
}

// index of vertices is zero based
public class Graph {

    private HashMap<Integer, Integer> Degrees;
    private List<List<EdgeNode<Integer>>> AdjList;
    private int nvertices;
    private int nedges;
    private Boolean isdirected;

    private void init_degree(int from, int to, Boolean isdirected) {
        var deg = this.Degrees.get(from);
        deg = (deg == null)? 0 : deg;
        this.Degrees.put(from, deg+1);

        if (!isdirected) {
            var deg2 = this.Degrees.get(to);
            deg2 = (deg2 == null)? 0 : deg2;
            this.Degrees.put(to, deg2+1);
        }
    }

    public List<EdgeNode<Integer>> get_edges(int id) {
        return this.AdjList.get(id);
    }

    private void add_adj_list(EdgeNode<Integer> node, Boolean isdirected) {
        var list = this.AdjList.get(node.id);
        list.add(node);
        if (!isdirected) {
            list = this.AdjList.get(node.next);
            var rev_node = new EdgeNode<Integer>();
            rev_node.id = node.next;
            rev_node.next = node.id;
            rev_node.weight = node.weight;
            list.add(rev_node);
        }
    }

    public int get_nvertices() { return this.nvertices; };

    public void show_adj_list() {
        for (int k=0; k<this.nvertices; k++) {
            var lst = this.AdjList.get(k);
            System.out.printf("Node %d\n", k);
            for (var node: lst) {
                System.out.printf("to:%d, weight:%d\n", node.next, node.weight);
            }
        }

    }

    // Triple: (from_id, to_id, weight)
    private Graph(int nvertics, int nedges, Boolean isdirected, List<Triple<Integer>> links) {
        this.nvertices = nvertics;
        this.nedges = nedges;
        this.isdirected = isdirected;
        this.Degrees = new HashMap<>();
        this.AdjList = new ArrayList<>();

        // init adjacency list
        for (int k=0; k<nvertices; k++) {
            this.AdjList.add(new ArrayList<>());
        }

        // read from list of edge tuples
        for (var p : links) {
            var node = new EdgeNode<Integer>();
            node.id = p.fst();
            node.next = p.snd();
            node.weight = p.thr();
            init_degree(node.id, node.next, isdirected);
            add_adj_list(node, isdirected);
            // System.out.printf("%d: %d\n", node.id, this.Degrees.get(node.id));
        }

    };

    static Graph read_weighted_graph(Boolean directed) {

        var links = new ArrayList<Triple<Integer>>();
        Scanner sc = new Scanner(System.in);
        int a, b, c;
        // read header first
        int nvertices = 0, nedges = 0;
        while (sc.hasNextLine()) {
            if (sc.hasNext("#")) {
                sc.nextLine();
                continue;
            }
            nvertices = sc.nextInt();
            nedges = sc.nextInt();
            break;
        }

        while (sc.hasNextLine()) {
            if (sc.hasNext("#")) {
                sc.nextLine();
                continue;
            }
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();
            links.add(new Triple<Integer>(a, b, c));
        }
        sc.close();
        Graph g = new Graph(nvertices, nedges, directed, links);
        return g;
    }

    static Graph read_unweighted_graph(Boolean directed) {

        var links = new ArrayList<Triple<Integer>>();
        Scanner sc = new Scanner(System.in);
        int a, b;
        int nvertices = 0, nedges = 0;
        while (sc.hasNextLine()) {
            if (sc.hasNext("#")) {
                sc.nextLine();
                continue;
            }
            nvertices = sc.nextInt();
            nedges = sc.nextInt();
            break;
        }
        while (sc.hasNextLine()) {
            if (sc.hasNext("#")) {
                sc.nextLine();
                continue;
            }
            a = sc.nextInt();
            b = sc.nextInt();
            links.add(new Triple<Integer>(a, b, 1));
            // System.out.printf("%d %d\n", a, b);
        }
        sc.close();
        Graph g = new Graph(nvertices, nedges, directed, links);
        return g;
    }

    static public Graph read_graph(Boolean directed, Boolean weighted) {

        if (weighted) {
            return read_weighted_graph(directed);
        } else {
            return read_unweighted_graph(directed);
        }
    }
    private Boolean is_edge_exist(int from, int to) {
        var lst = this.AdjList.get(from);
        if (lst == null) {
            return false;
        }
        for (var node: lst) {
            if (node.next == to) {
                return true;
            }
        }
        return false;
    }

    public void insert_edge(int from, int to, int weight, Boolean isdirected) {
        // index must be continuous
        if (from > this.nvertices) {
            System.out.printf("Index is %d not in sequence\n", from);
            return;
        }
        if (to > this.nvertices) {
            System.out.printf("Index is %d not in sequence\n", to);
            return;
        }
        // check if edge exists or not
        if (is_edge_exist(from, to) == true) {
            System.out.printf("Edge %d->%d exists already\n", from, to);
            return;
        }

        var deg = this.Degrees.get(from);
        // this is a new vertex
        if (deg == null) {
            this.nvertices++;
            this.AdjList.add(new ArrayList<>());
        }
        init_degree(from, to, isdirected);
        var node = new EdgeNode<Integer>();
        node.id = from;
        node.next = to;
        node.weight = weight;
        add_adj_list(node, isdirected);
    }


    public static void main(String[] argv) {

        // GraphTest.DFS_Test01();
        // GraphTest.read_graph_Test01();
        // GraphTest.read_wgraph_Test02();
        // GraphTest.BFS_Test01();
        // GraphTest.DFS_Test01();
        // GraphTest.DFS_directed_Test01();
        // GraphTest.DFS_undirected_ucc();
        // GraphTest.BFS_undirected_shortest_path();
        GraphTest.DFS_topograph();

    }

    
}
