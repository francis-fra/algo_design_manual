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
# gradle execute_sorting

# chapter 4
gradle execute_ch04

#--------------------
# run gradle test
#--------------------
# gradle test -PmainClass=com.jalgo.ch03.AppTest
# gradle test -PmainClass=com.jalgo.ch03.LinkedListTest

# report:
# file:///home/fra/Project/MyCode/algo/javaalgo/build/reports/tests/test/index.html