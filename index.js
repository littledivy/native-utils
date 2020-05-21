var addon = require('bindings')('spin');

module.exports = {
  hostname: addon.host(),
  ipaddr: addon.ip,
  add: addon.add,
  minus: addon.minus,
  find: addon.find,
  ...addon
};
