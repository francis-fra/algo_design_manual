import { make_heap} from "./src/priorityQueue";

function heap_sort<T>(data: T[]) {
    let pq = make_heap<T>(data)
    for (var k=0; k<data.length; k++)
        console.log(pq.extract_top())
}

function quick_sort<T>(data: T[]) {
    let pivot_idx = partition(data, 0, data.length - 1)
    // console.log("pivot idx = " + pivot_idx)
    qsort(data, 0, pivot_idx - 1)
    qsort(data, pivot_idx, data.length - 1)
}

function partition<T>(data: T[], low: number, hi: number) : number {
    // choose the last one (TODO: optimize it)
    let pivot = data[hi]
    let pivot_idx = low
    for (var k=low; k<hi; k++) {
        if (data[k] < pivot) {
            swap(data, pivot_idx, k)
            pivot_idx++
        }
    }
    swap(data, pivot_idx, hi)
    return pivot_idx
}

function swap<T>(data: T[], n: number, m: number) {
    let tmp = data[n]
    data[n] = data[m]
    data[m] = tmp
}

function qsort<T>(data: T[], low: number, hi: number) {
    if (low < hi) {
        let pivot_idx = partition(data, low, hi)
        qsort(data, low, pivot_idx - 1)
        qsort(data, pivot_idx, hi)
    }

}

function merge_sort<T>(data: T[]) {
    msort(data, 0, data.length - 1)
}

// array passed by reference
function msort<T>(data: T[], low: number, hi: number) {
    if (low < hi) {
        let middle = Math.floor((hi - low) / 2) + low
        msort(data, low, middle)
        msort(data, middle+1, hi)
        // in-place array merge
        merge(data, low, middle, hi)
    }
    // return data
}

function merge<T>(data: T[], low: number, middle: number, hi: number) {
    // merge two sorted arrays
    let left_idx = low 
    let right_idx = middle + 1
    // let current_idx = 0
    let left_count = middle - low + 1
    let right_count = hi - middle

    let total = left_count + right_count
    // TODO: pre-allocate space
    let sorted_array : Array<T> = new Array<T>()

    while (total > 0) {
        let left_item = data[left_idx]
        let right_item = data[right_idx]
        if (left_idx > middle) {
            sorted_array.push(right_item)
            right_idx++
        } else if (right_idx > hi) {
            sorted_array.push(left_item)
            left_idx++
        } else if (left_item < right_item) {
            sorted_array.push(left_item)
            left_idx++
        } else {
            sorted_array.push(right_item)
            right_idx++
        } 
        total--
    }

    // copy back to array
    for (var idx=low, current=0; idx <= hi; idx++, current++) {
        data[idx] = sorted_array[current]
    }

    // return data

}


export { heap_sort, merge_sort, quick_sort }