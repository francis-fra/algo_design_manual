// import * as fs from "fs"
// import {sprintf} from "sprintf-js"
// import { PriorityQueue, make_heap } from "./priorityQueue";
import { heap_sort, merge_sort, quick_sort } from "../src/sort";

import * as mocha from 'mocha';
import * as chai from 'chai';

const expect = chai.expect;
describe('quick sort test', () => {

  it('should be able to add things correctly' , () => {
    let result = [4,5,6,1,2] 
    quick_sort(result)
    expect(result).to.deep.equal([1,2,4,5,6])
  });

});