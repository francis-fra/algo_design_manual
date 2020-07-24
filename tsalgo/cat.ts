// read file
import fs = require('fs');

//  synchronous IO
let data = fs.readFileSync('data/tobe.txt', 'utf8')
console.log(data)
fs.writeFileSync("data/copy.txt",  data); 

// asynchronous IO
// fs.readFile('data/tobe.txt', 'utf8', function(error, contents) {
//     if (error) {
//         console.log('Error: ' + error)
//         throw error;
//     }
//     console.log(contents);
// });


fs.writeFile('data/copycopy.txt', data, function(error) {
    if (error) {
        console.log('Error:- ' + error);
        throw error;
    }
    console.log("done!!");
});