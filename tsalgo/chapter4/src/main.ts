import * as fs from "fs"
import {sprintf} from "sprintf-js"
import { PriorityQueue, make_heap } from "./priorityQueue";
// import { heap_sort, merge_sort, merge, msort } from "./sort";
import { heap_sort, merge_sort, quick_sort } from "./sort";

function readTest() : number[] {
    let rawdata = fs.readFileSync("../data/numbers.txt", "utf8")
    let data : number[] = rawdata.split(' ').map(function (x) { 
                                                    return parseInt(x, 10)} )
    return data
}

let data = readTest()

let show_data = function(data: number) {
    console.log(sprintf("%d", data))
}

function PQTest() {

    let pq = make_heap<Number>(data)
    // print data
    console.log(pq.toString())

    // get min item 
    // console.log("removed top")
    // pq.extract_top()
    // console.log(pq.toString())
    // pq.traverse(show_data)

    // console.log("removed top")
    // pq.extract_top()
    // console.log(pq.toString())
    // pq.traverse(show_data)
    // sort

}
// PQTest()

function sortTest() {

    console.log("Sorted array:")
    // heap_sort(data)

    // let data = [8, 4]
    // let data = [4]
    // merge_sort(data) 
    quick_sort(data) 
    // msort(data, 0, 1)
    // msort(data, 1, 1)
    // merge(data, 0, 0, 1)
    // console.log(result)
    console.log(data)
}
sortTest()