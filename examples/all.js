const utils = require("../");

// get local hostname
console.log(utils.hostname);

// get ipaddress
console.log(utils.ipaddr());

// calc probablity
console.log(utils.probability(0.5, 0.25, 0.5));

// add two numbers
console.log(utils.add(1, 2));

// subtract two numbers
console.log(utils.minus(.3, .2));

// find a string in string
console.log(utils.find("a boy", "l"))

// perform sdbm hash algorithm to string
console.log(utils.sdbmHash("this is a sdbm hash"))

// perform djb2 hash algorithm to string
console.log(utils.djb2Hash("this is a djb2 hash"))

// perform xor8 hash algorithm to string
console.log(utils.xor8Hash("this is a xor8 hash"))

// perform adler_32 hash algorithm to string
console.log(utils.adler32Hash("this is a xor8 hash"))

// perform crc32 hash hash algorithm to string
console.log(utils.crc32Hash("this is a crc32 hash"))

// write contents to a file
console.log(utils.write("hello.txt", "yessss!"));

// read contents of a file
console.log(utils.read("hello.txt"));

// simulate key type
utils.type("wtf");

// simulate mouse move
utils.mouse(100, 400);

// simulate smooth mouse move
utils.smoothMouse(400, 600);

// get screen size
console.log(utils.screen());

// simulate mouse move

/** Clipboard is not yet implemented
console.log(utils.getClipboardText())
**/
