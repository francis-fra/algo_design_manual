package com.fra.jalgo.ch05;
import java.util.Queue;
import java.util.Stack;

import org.junit.rules.DisableOnDebug;

import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Collections;

public class GraphSearch {

    // for undirected graph 
    static public void shortest_path(Graph g, int start_id, int destiantion_id,
        ArrayList<Integer> parents) {
        // node to be visiting
        LinkedList<Integer> discoverd = new LinkedList<>();
        ArrayList<Boolean> visited = new ArrayList<>(
                Collections.nCopies(g.get_nvertices(), false)
                );
        for (int k=0; k<parents.size(); k++) {
            parents.set(k, -1);
        }
        int current = start_id;
        do {
            visited.set(current, true);
            // explore edges
            var neighbours = g.get_edges(current);
            for (var node: neighbours) {
                // check if it is done
                if (visited.get(node.next) == false) {
                    discoverd.add(node.next);
                    // set parents only if not previously found
                    if (parents.get(node.next) == -1)
                        parents.set(node.next, node.id);
                }
            }
            System.out.printf("Processing node %d\n", current);

            // parent_id = current;
            while (discoverd.size() > 0) {
                current = discoverd.remove();
                if (visited.get(current) == false) break;
            }
            if (visited.get(current) == true) break;
        } while (true);
    }

    static public void DFS_processing(Graph g, int start_id, ArrayList<Integer> outcome) {
        // node to be visiting
        Stack<Integer> discoverd = new Stack<>();
        ArrayList<Boolean> visited = new ArrayList<>(
                Collections.nCopies(g.get_nvertices(), false)
                );
        int current = start_id;
        do {
            visited.set(current, true);
            // explore edges
            var neighbours = g.get_edges(current);
            for (var node: neighbours) {
                // check if it is done
                if (visited.get(node.next) == false)
                    discoverd.push(node.next);
            }
            // node processing - just print
            System.out.printf("Processing node %d\n", current);
            outcome.set(current, 1);
            while (discoverd.size() > 0) {
                current = discoverd.pop();
                if (visited.get(current) == false) break;
            }
            if (visited.get(current) == true) break;
        } while (true);
        // return outcome;
    }

    static public void DFS(Graph g, int start_id) {
        // node to be visiting
        Stack<Integer> discoverd = new Stack<>();
        ArrayList<Boolean> visited = new ArrayList<>(
                Collections.nCopies(g.get_nvertices(), false)
                );
        int current = start_id;
        do {
            visited.set(current, true);
            // explore edges
            var neighbours = g.get_edges(current);
            for (var node: neighbours) {
                // check if it is done
                if (visited.get(node.next) == false)
                    discoverd.push(node.next);
            }
            // node processing - just print
            System.out.printf("Processing node %d\n", current);
            while (discoverd.size() > 0) {
                current = discoverd.pop();
                if (visited.get(current) == false) break;
            }
            if (visited.get(current) == true) break;
        } while (true);

    }

    static public void BFS(Graph g, int start_id) {
        // node to be visiting
        Queue<Integer> discoverd = new LinkedList<>();
        ArrayList<Boolean> visited = new ArrayList<>(
                Collections.nCopies(g.get_nvertices(), false)
                );
        int current = start_id;
        do {
            visited.set(current, true);
            // explore edges
            var neighbours = g.get_edges(current);
            for (var node: neighbours) {
                // check if it is done
                if (visited.get(node.next) == false)
                    discoverd.add(node.next);
            }
            // node processing - just print
            System.out.printf("Processing node %d\n", current);
            while (discoverd.size() > 0) {
                current = discoverd.remove();
                if (visited.get(current) == false) break;
            }
            if (visited.get(current) == true) break;
        } while (true);

    }

    // find connected compoents for undirected graphs only
    static public void UCC(Graph g) {
        int nvertices = g.get_nvertices();
        ArrayList<Integer> components = new ArrayList<>(
                    Collections.nCopies(g.get_nvertices(), 0)
                );
        int n = 1;
        for (int k=0; k<nvertices; k++) {
            if (components.get(k) == 0) {
                System.out.printf("Component %d\n", n++);
                DFS_processing(g, k, components);
            }
        }
    }

    // static public void toposort(Graph g) {
    //     ArrayList<Boolean> visited = new ArrayList<>(
    //             Collections.nCopies(g.get_nvertices(), false)
    //             );
    //     ArrayList<Boolean> discovered = new ArrayList<>(
    //             Collections.nCopies(g.get_nvertices(), false)
    //             );
    //     for (int v=0; v<g.get_nvertices(); v++) {
    //         if (discovered.get(v) == false) {
    //             DFS_Topo(g, v, discovered, visited);
    //         }
    //     }
    // }

    // static public void DFS_Topo(Graph g, int start_id, 
    //                         ArrayList<Boolean> discovered,
    //                         ArrayList<Boolean> visited) {
    //     int current = start_id;
    //     do {
    //         visited.set(current, true);
    //         // explore edges
    //         var neighbours = g.get_edges(current);
    //         for (var node: neighbours) {
    //             // check if it is done
    //             if (visited.get(node.next) == false)
    //                 discovered.set(node.next, true);
    //         }
    //         // node processing - just print
    //         System.out.printf("Processing node %d\n", current);
    //         while (discovered.size() > 0) {
    //             current = discovered.pop();
    //             if (visited.get(current) == false) break;
    //         }
    //         if (visited.get(current) == true) break;
    //     } while (true);

    }
    
}
