const addon = require("../");

console.log(addon.hostname);

addon.ipaddr();

console.log(addon.probability(0.5, 0.25, 0.5));

console.log(addon.add(1, 2));

console.log(addon.minus(.3, .2));

console.log(addon.find("a boy", "l"))

console.log(addon.sdbmHash("hello"))
/** Clipboard is not yet implemented
console.log(addon.getClipboardText())
**/
