// min-heap: parent is less than all of its children

class PriorityQueue<T> {
    private _data: T[];

    constructor(private _capacity: number = 10, 
                private _next :number = 1) {
        // _capacity: max capacity of pq
        // _next: next index to insert
        this._data = [null]     // data start at index=1
    }

    get_parent(n: number) : number {
        if (n == 1) {
            return -1
        } else {
            return Math.floor(n/2)
        }
    }

    get_young_child(n: number) : number {
        return (2 * n)
    }

    get_old_child(n: number) : number {
        return (2 * n + 1)
    }

    any_young_child?(n: number): boolean {
        return (2*n <= this.get_right_most_item_index())
    }

    any_old_child(n: number): boolean {
        return (2*n+1 <= this.get_right_most_item_index())
    }

    get size(): number {
        return this._next - 1;
    }

    // FIXME: not all data, just up to current
    traverse(processor: (data: T) => void) {
        for (var n in this._data) {
            if (+n > this.get_right_most_item_index())
                break
            processor(this.get_item(+n))
        }
    }

    insert(data: T) {
        if (this.size >= this._capacity) {
            return
        } else {
            this._data.push(data)
            this._next++
            this.bubble_up(this._next-1)
        }
    }

    toString() {
       return this._data.slice(1, this.size+1) 
    }

    private bubble_up(n: number) {
        let parent = this.get_parent(n)
        if (parent == -1) {
            return
        } else {
            if (this._data[n] < this._data[parent]) {
                this.swap(n, parent)
                this.bubble_up(parent)
            }
        }
    }

    // return item from index
    private get_item(n: number): T {
        return this._data[n]
    }

    private get_right_most_item(): T {
        let last_idx = this.get_right_most_item_index()
        return this._data[last_idx]
    }

    private get_right_most_item_index(): number {
        return this._next - 1
    }

    private bubble_down(n: number) {

        let has_young_child = this.any_young_child(n)
        let has_old_child = this.any_old_child(n)

        if (!has_young_child && !has_old_child) {
            // nothing to do
        } else if (!has_old_child) {
            // only one child
            let child_idx = this.get_young_child(n)
            let child = this.get_item(child_idx)
            let current = this.get_item(n)
            if (current > child) {
                this.swap(n, child_idx)
                this.bubble_down(child_idx)
            }
        } else {
            let left_child_idx = this.get_young_child(n)
            let left_child = this.get_item(left_child_idx)
            let right_child_idx = this.get_old_child(n)
            let right_child = this.get_item(right_child_idx)
            // find the smallet child
            let smallest_child_idx = left_child < right_child ? left_child_idx : right_child_idx
            let smallest_child = this.get_item(smallest_child_idx)
            let current = this.get_item(n)
            if (current > smallest_child) {
                this.swap(n, smallest_child_idx)
                this.bubble_down(smallest_child_idx)
            }
        }

    }

    // remove current item and 
    // move the right most child to 'n' position
    private promote_right_most_item(n: number) {

        let right_most_item = this.get_right_most_item()
        this._data[n] = right_most_item
        // this.swap(n, right_most_item) 
        this._next--
    }

    public extract_top(): T {
        if (this.size > 0) {
            let top = this._data[1]
            this.promote_right_most_item(1)
            this.bubble_down(1)

            return top
        }
    }

    // swap the two index
    private swap(n: number, m: number) {
        let tmp = this._data[n]
        this._data[n] = this._data[m]
        this._data[m] = tmp
        // debug
        // console.log("swap " + this._data[n] + " with " + this._data[m])
    }
}

function make_heap<T>(data: T[]) {

    let pq = new PriorityQueue()
    for (var n of data)
        pq.insert(n)

    return pq
    
}

function heap_sort<T>(data: T[]) {
    let pq = make_heap<T>(data)
    for (var k=0; k<data.length; k++)
        console.log(pq.extract_top())
}

export {PriorityQueue, make_heap}