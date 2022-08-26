cat fig5.9.txt | ./main_graph 
./main_graph  fig5.9.txt
./main_graph  fig5.9.txt -s dfs
./main_graph  fig5.9.txt -s bfs

./main_graph  fig5.9m.txt
# two color
./main_graph  cycle.txt

# spanning tree
./main_graph  fig6.3.txt -w

# union test
./main_graph  union_data.txt -w