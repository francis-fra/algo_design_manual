# run gradle task
# gradle execute_ch03
# gradle execute
# gradle helloWorld

# task :run with specified main class by passing the mainClass parameter
# gradle -PmainClass=com.fra.jalgo.ch03.LinkedList execute

# task :run & task :execute_ch03
# gradle run -PmainClass=com.fra.jalgo.ch03.LinkedList execute_ch03

# FIXME: run main class only??
# gradle run -PmainClass=com.fra.jalgo.ch03.LinkedList 
# gradle -q run

# sorting
gradle execute_sorting

# chapter 4
gradle execute_ch04

# chapter 5
# mkdir -p src/main/java/com/fra/jalgo/ch05
# gradle execute_ch05
# cat data/graph01.txt | gradle execute_ch05
# bfs / dfs
cat data/wgraph01.txt | gradle execute_ch05
cat data/dgraph01.txt | gradle execute_ch05
# ucc (for undirected graph only)
cat data/ugraph01.txt | gradle execute_ch05
# shortest path
cat data/ugraph02.txt | gradle execute_ch05
# topology ordering
cat data/topograph01.txt | gradle execute_ch05
cat data/topograph02.txt | gradle execute_ch05

#--------------------
# run gradle test
#--------------------
# gradle test -PmainClass=com.jalgo.ch03.AppTest
# gradle test -PmainClass=com.jalgo.ch03.LinkedListTest

# report:
# file:///home/fra/Project/MyCode/algo/javaalgo/build/reports/tests/test/index.html

