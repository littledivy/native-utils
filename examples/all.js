const addon = require("../");

// get local hostname
console.log(addon.hostname);

// get ipaddress
console.log(addon.ipaddr());

// calc probablity
console.log(addon.probability(0.5, 0.25, 0.5));

// add two numbers
console.log(addon.add(1, 2));

// subtract two numbers
console.log(addon.minus(.3, .2));

// find a string in string
console.log(addon.find("a boy", "l"))

// perform sdbm hash algorithm to string

console.log(addon.sdbmHash("hello"))
/** Clipboard is not yet implemented
console.log(addon.getClipboardText())
**/
