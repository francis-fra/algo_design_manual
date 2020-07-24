package com.fra.jalgo.ch03;

// import org.junit.Test;
import org.junit.*;
import static org.junit.Assert.*;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;


// private final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
// private final ByteArrayOutputStream errContent = new ByteArrayOutputStream();

public class LinkedListTest {

    @Before
    public void setUpStreams() {
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        ByteArrayOutputStream errContent = new ByteArrayOutputStream();

        PrintStream originalOut = System.out;
        PrintStream originalErr = System.err;

        System.setOut(new PrintStream(outContent));
        System.setErr(new PrintStream(errContent));

    };

    @Test
    public void testDeletion() {
        LinkedList<Integer> linked_list = new LinkedList<Integer>();
        linked_list.insert(8);
        int value = linked_list.delete();
        assertEquals(8, value);
    };

    @Test
    public void testInsertion() {
        LinkedList<Integer> linked_list = new LinkedList<Integer>();
        linked_list.insert(5);
        linked_list.insert(8);
        // PrintNode<Integer> P = new PrintNode<Integer>();
        // linked_list.

        // ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        // System.setOut(new PrintStream(outContent));
        // linked_list.traverse(P);
        // FIMXE: error
        // assertEquals("5 8", outContent.toString());
    }

    @Test
    public void out() {
        // FIXME: put these to @Before
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        ByteArrayOutputStream errContent = new ByteArrayOutputStream();

        PrintStream originalOut = System.out;
        PrintStream originalErr = System.err;

        System.setOut(new PrintStream(outContent));
        System.setErr(new PrintStream(errContent));
        System.out.print("hello");
        assertEquals("hello", outContent.toString());
    };
};
