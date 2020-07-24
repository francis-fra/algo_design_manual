package com.fra.jalgo.ch03;
/*
abstract public class NodeMethod<T> {
    abstract public void execute(LinkedNode<T> node);
}

class PrintNode<T> extends NodeMethod<T> {
    @Override
    public void execute(LinkedNode<T> node) {
        System.out.println(node.get());
    }
}
*/

public interface NodeMethod<T> {
    void execute(LinkedNode<T> node);
}

class PrintNode<T> implements NodeMethod<T> {
    @Override
    public void execute(LinkedNode<T> node) {
        System.out.print(node.get());
        System.out.print(" ");
    }
}